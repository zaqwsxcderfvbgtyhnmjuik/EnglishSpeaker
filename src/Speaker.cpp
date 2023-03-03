#include "Speaker.h"
TTS::TTS()
{
	m_pSpVoice = nullptr;
}


TTS::~TTS()
{
	StopVoice();
	::CoUninitialize();
}

bool TTS::InitVoice()
{
	HRESULT ret = ::CoInitialize(NULL);
	ret = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_INPROC_SERVER, IID_ISpVoice, (void**)&m_pSpVoice);
	if (0 == ret && m_pSpVoice)
	{
		m_pSpVoice->SetVolume(80);

		IEnumSpObjectTokens* pSpEnumTokens = NULL;
		if (SUCCEEDED(SpEnumTokens(SPCAT_VOICES, NULL, NULL, &pSpEnumTokens)))		//找到lili语音进行朗读, 否则就跳出
		{
			ISpObjectToken* pSpToken = NULL;
			while (SUCCEEDED(pSpEnumTokens->Next(1, &pSpToken, NULL)) && pSpToken != NULL)
			{
				LPWSTR pId = new WCHAR[32];
				pSpToken->GetId(&pId);

				int nLen = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)pId, -1, NULL, 0, NULL, NULL);

				char* s = new char[nLen + 1];
				WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)pId, -1, s, nLen, NULL, NULL);

				if (0 == strcmp(s, ("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\Voices\\Tokens\\MS-Lili-2052-20-DSK")))
				{
					m_pSpVoice->SetVoice(pSpToken);      // 设置lili语音
					pSpToken->Release();
					delete[] s;
					break;
				}
				delete[] s;
				pSpToken->Release();
			}
			pSpEnumTokens->Release();
		}
		return true;
	}
	else
	{

	}
	return false;
}

bool TTS::Speak(std::wstring word)
{
	StopVoice();
	if (InitVoice())
	{
		HRESULT ret = m_pSpVoice->Speak(word.c_str(), SPF_ASYNC, NULL);
		return ret;
	}
	else
	{
		return false;
	}

}

bool TTS::IsUseful()
{
	bool bRet = InitVoice();
	StopVoice();
	return bRet;
}

void TTS::StopVoice()
{
	if (m_pSpVoice != nullptr)
	{
		m_pSpVoice->Release();
	}
}

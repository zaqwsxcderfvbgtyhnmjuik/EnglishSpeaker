#pragma once
#include <Windows.h>
#include "sapi.h"
#include <list>
#include <string>
#include "sphelper.h"
#pragma comment(lib, "sapi.lib")


class TTS
{
public:
	TTS();
	~TTS();
	bool Speak(std::wstring);
	bool IsUseful();

private:
	ISpVoice* m_pSpVoice;

	bool InitVoice();
	void StopVoice();
};

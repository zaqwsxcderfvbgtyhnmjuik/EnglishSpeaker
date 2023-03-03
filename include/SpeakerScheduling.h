#pragma once
#include"Speaker.h"
#include"WordsReader.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define random(x) rand()%(x)

class SpeakerScheduling {
public:
	SpeakerScheduling(int Interval_minutes, std::string path) :_current_word_ordinal(0),_Interval_minutes(Interval_minutes), _words_reader(path){
		srand((int)time(0));  // �����������  ��0����NULLҲ��
		_words_reader.readWords();
	}

	void Schedule() {
		int rand_minutes = random(3);
		int rand_index = 0;
		while (true) {
			if (_words_reader.all()) {
				_words_reader.reset();
				std::cout << "[ info ]: All words have been pronounced randomly!\n" << std::endl;
				_current_word_ordinal = 0; ///< ������¿�ʼ
			}

			rand_index = random(_words_reader.size());
			bool btest = _words_reader.test(rand_index);
			
			if (btest == false) {
				_words_reader.setbit(rand_index);
				break;
			}

		}

		_tts.Speak(_words_reader.at(rand_index));
		std::cout << std::setfill('0') << std::setw(3) << ++_current_word_ordinal % (_words_reader.size() + 1);///< ���1�������ʽΪ001
		std::wcout.imbue(std::locale("chs"));///< �������
		std::wcout<< _T(" ") <<_words_reader.at(rand_index) << std::endl;
		if (_current_word_ordinal % 5 == 0) std::cout << std::endl;///< �������һ��
		Sleep(1000*60* (_Interval_minutes + rand_minutes) );
	}
private:
	int _current_word_ordinal;///< ��ǰ�����ڼ������ʣ������1��ʼ
	int _Interval_minutes;
	TTS _tts;
	WordsReader _words_reader;
};
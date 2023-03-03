#include <iostream>
#include < io.h>
#include "SpeakerScheduling.h"

bool IsNumber(const char* str){
	double aa;
	int nn = sscanf_s(str, "%lf", &aa);
	return nn != 0;
}
#define help_str "usage: EnglishSpeaker.exe 10 ./MathWords.txt\n参数1：指出间隔多少分钟朗读一个单词\n参数2：指出英语朗读文件的路径"
#define tip1_str "first argument should be a number, please do by usage! "
#define tip2_str "second argument should be a real path, please do by usage! "
#define tip3_str "too many arguments , please do by usage! "

int main(int argc, char** argv)
{
	std::cout << help_str << std::endl;

	int Interval_minutes = 1;
	std::string path = "MathWords.txt";

	if (argc == 1) {
		// 检查默认参数
		if (_access(path.c_str(), 0) == -1 || Interval_minutes < 0) {
			std::cout << tip2_str << std::endl;
			return 0;
		}
	}
	else if (argc == 2) {
		bool isnum = IsNumber(argv[1]);
		if (isnum)
			Interval_minutes = atoi(argv[1]);
		else {
			std::cout << tip1_str << std::endl;
			return 0;
		}
	}
	else if (argc == 3) {
		bool isnum = IsNumber(argv[1]);
		if (isnum)
			Interval_minutes = atoi(argv[1]);
		else {
			std::cout << tip1_str << std::endl;
			return 0;
		}

		if (_access(argv[2], 0) != -1)
			path = std::string(argv[2]);
		else {
			std::cout << tip2_str << std::endl;
			return 0;
		}
	}
	else
	{
		std::cout << tip3_str << std::endl;
		return 0;
	}

	SpeakerScheduling schedule (Interval_minutes, path);
	while (true) {
		schedule.Schedule();
	}
}
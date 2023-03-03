# EnglishSpeaker
a English words speaker program on windows platform to reviews some domain words like basic concepts of ML or DL and CET4/6 words

# Suggestions:
Please use the console to open the application. If you double-click to open it, the default parameters will be used. You cannot adjust the reading interval and the file to be read

# Words File Format:
The format of the read file is: one word on a line, and multiple words occupy multiple lines

# Fast to use this program, download executable file from bin, then to use command line startup:
usage: EnglishSpeaker.exe 10 ./MathWords.txt
Parameter 1: Indicates how many minutes to read a word
Parameter 2: Indicates the path to read the file in English

# if you want to compile this ptoject, to be aware of these pitfalls
1. in VS tool chains, code files like *.cpp or *.hpp should use GBK encode instead of utf-8 encode. because terminal in windows is default to use code page 936 which is GBK encode, if some tips by Chinese is going to output in terminal, garbled code will generate.
2. when you use cmake command "cmake .." to generate EnglishSpeaker.sln solution file, then to open it with VS, the first thing you need to do is going to set EnglishSpeaker project as a start up project, otherwise you can not to launch and debug it.

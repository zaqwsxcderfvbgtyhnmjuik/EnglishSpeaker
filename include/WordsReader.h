#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include <locale>
#include <codecvt>
#include<vector>
#include <utility>
#include<bitset>

class WordsReader {
public:
    WordsReader(std::string strPath) :_dataPath(strPath) {
        _fin.open(strPath.c_str(), std::ios::in);
        if (!_fin.is_open()) {
            std::cout << "文件打开时失败！" << std::endl;
        }
    }

    ~WordsReader() {
        if (!_fin.is_open()) {
            return;
        }
        _fin.close();
    }

    void readWords() {
        if (!_fin.is_open()) {
            return;
        }

        std::string buff;
        while (getline(_fin, buff)) {
            trim(buff);
            
            if (buff.empty())
                continue;

            std::wstring wstr = to_wide_string(buff);
            _wstr_vector.push_back(std::move(wstr));
        }

    }

    int size() {
        return _wstr_vector.size();
    }
    std::wstring& at(int index) {
        return _wstr_vector.at(index);
    }
    void setbit(std::size_t pos) {
        _bitset.set(pos);
    }
    bool all() {
        return _bitset.count() == _wstr_vector.size();
    }
    void reset() {
        _bitset.reset();
    }
    bool test(std::size_t pos) {
        return _bitset.test(pos);
    }
private:
    std::string& trim(std::string& s) {
        if (s.empty()) {
            return s;
        }

        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        return s;
    }

    // convert string to wstring
    std::wstring to_wide_string(const std::string& input) {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        return converter.from_bytes(input);
    }

    // convert wstring to string
    std::string to_byte_string(const std::wstring& input){
        // std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        return converter.to_bytes(input);
    }

private:
    std::vector<std::wstring> _wstr_vector;
    std::string _dataPath;
    std::ifstream _fin;
    std::bitset<30000> _bitset;
};
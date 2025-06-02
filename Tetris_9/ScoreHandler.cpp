#include "ScoreHandler.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

static const string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";


//인코딩해서 str로 저장
string ScoreHandler::base64_encode(const string& input, list<int>saved_score)
{
    saved_score.clear();
    string encoded;
    int val = 0, valb = -6;
    for (unsigned char c : input) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            encoded.push_back(base64_chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) encoded.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
    while (encoded.size() % 4) encoded.push_back('=');

    return encoded;
}

//디코딩해서 lsit로 저장
void ScoreHandler::base64_decode(string save, list<int>& saved_score)
{
    vector<int> T(256, -1);
    for (int i = 0; i < 64; i++) T[base64_chars[i]] = i;

    string decoded;
    int val = 0, valb = -8;
    for (unsigned char c : save) {
        if (T[c] == -1) break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            decoded.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    stringstream ss(decoded);
    string line;
    while (getline(ss, line)) {
        if (!line.empty()) {
            int value = stoi(line);
            saved_score.push_back(value);
        }
    }
    saved_score.sort(greater<>());
}

void ScoreHandler::load_score(list<int>& saved_score)
{
    ifstream file_in("save_score.txt");
    if (!file_in.is_open()) {
        //cout << "파일 읽기 오류!" << endl;
        //saved_score 에 저장하기
    }
    saved_score.clear();
    string str;
    string total_str;
    while (file_in >> str) {
        total_str += str;
    }
    ScoreHandler::base64_decode(total_str, saved_score);

}

void ScoreHandler::save_score(int score, list<int>& saved_score)
{
    ofstream file_out("save_score.txt");
    if (!file_out.is_open()) {
        //cout << "파일 출력 오류!" << endl;
        return;
    }
    saved_score.push_back(score);
    //saved_score.sort();

    // 파일에 상태 저장
    string list_to_string;
    for (auto& i : saved_score) {
        list_to_string += to_string(i);
        list_to_string += '\n';
    }


    string encoded = ScoreHandler::base64_encode(list_to_string, saved_score);
    file_out << encoded;
    saved_score.clear();
    //file_out << list_to_string;
}

#pragma once
#include <string>
#include <list>

using namespace std;

class ScoreHandler
{
private:
public:
	static string base64_encode(const std::string& input, list<int>saved_score);
	static void base64_decode(string save, list<int>& saved_score);
	static void load_score(list<int>& saved_score);
	static void save_score(int score, list<int>& saved_score);
};


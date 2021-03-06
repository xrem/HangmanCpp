#pragma once
#include <vector>
#include <string>

using namespace std;

class LevelHelper
{
private:
	static vector<string> level0;
	static vector<string> level1;
	static vector<string> level2;
	static vector<string> level3;
	static vector<string> level4;
	static vector<string> level5;
	static vector<string> level6;
public:
	static void initAsciiVectors();
	static void printLevel(int attempts_left);
};


#pragma once
#include <string>

using namespace std;

class Game
{
private:
	string selected_word;
	string display_word;
	int attempts_left;
public:
	explicit Game(string vocabulary_filename);
	bool start();
};


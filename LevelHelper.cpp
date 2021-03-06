#include "LevelHelper.h"
#include <iostream>

void LevelHelper::initAsciiVectors()
{
	if (level0.size() != 0) {
		return;
	}

	level0.push_back("  +---+");
	level0.push_back("  |   |");
	level0.push_back("      |");
	level0.push_back("      |");
	level0.push_back("      |");
	level0.push_back("      |");
	level0.push_back("=========");
	level1.push_back("  +---+");
	level1.push_back("  |   |");
	level1.push_back("  O   |");
	level1.push_back("      |");
	level1.push_back("      |");
	level1.push_back("      |");
	level1.push_back("=========");
	level2.push_back("  +---+");
	level2.push_back("  |   |");
	level2.push_back("  O   |");
	level2.push_back("  |   |");
	level2.push_back("      |");
	level2.push_back("      |");
	level2.push_back("=========");
	level3.push_back("  +---+");
	level3.push_back("  |   |");
	level3.push_back("  O   |");
	level3.push_back(" /|   |");
	level3.push_back("      |");
	level3.push_back("      |");
	level3.push_back("=========");
	level4.push_back("  +---+");
	level4.push_back("  |   |");
	level4.push_back("  O   |");
	level4.push_back(" /|\\\  |");
	level4.push_back("      |");
	level4.push_back("      |");
	level4.push_back("=========");
	level5.push_back("  +---+");
	level5.push_back("  |   |");
	level5.push_back("  O   |");
	level5.push_back(" /|\\\  |");
	level5.push_back(" /    |");
	level5.push_back("      |");
	level5.push_back("=========");
	level6.push_back("  +---+");
	level6.push_back("  |   |");
	level6.push_back("  O   |");
	level6.push_back(" /|\\\  |");
	level6.push_back(" / \\\  |");
	level6.push_back("      |");
	level6.push_back("=========");
}

void LevelHelper::printLevel(int attempts_left)
{
	LevelHelper::initAsciiVectors();
	int level = 6 - attempts_left;
	vector<string>* selected_level = nullptr;
	switch (level)
	{
	case 0:
		selected_level = &level0;
		break;
	case 1:
		selected_level = &level1;
		break;
	case 2:
		selected_level = &level2;
		break;
	case 3:
		selected_level = &level3;
		break;
	case 4:
		selected_level = &level4;
		break;
	case 5:
		selected_level = &level5;
		break;
	case 6:
		selected_level = &level6;
		break;
	}

	for (auto line : *selected_level)
	{
		std::cout << line << std::endl;
	}
}

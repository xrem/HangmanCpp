#include <algorithm>
#include <ctime>
#include <iostream>
#include <fstream>
#include <locale>
#include <string>
#include <vector>
#include "anscii_art.h"

using namespace std;

string vocabulary_filename = "C:\\путь\\до\\вашего\\файла\\словарь.txt";
vector<string> words = vector<string>();
int attempts_left = 6;

std::string str_toupper(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return toupper(c); }
	);
	return s;
}

int main()
{
	setlocale(LC_ALL, "Russian"); // Включает отображение на русском.
	system("chcp 1251"); // Исправление для ввода русского языка.
	srand(time(0));
	initAsciiVectors();
	
	ifstream vocabulary(vocabulary_filename);
	while(!vocabulary.eof())
	{
		string word;
		getline(vocabulary, word);
		words.push_back(str_toupper(word));
	}
	vocabulary.close();

	
	string selected_word = words[rand() % words.size()];
	string display_word = "";
	for (char letter : selected_word)
	{
		if (letter == ' ')
		{
			display_word.push_back(letter);
		} else {
			display_word.push_back('_');
		}
	} 
	
	// cout << "Загаданное слово: " << selected_word << endl;
	while (attempts_left > 0 && display_word != selected_word)
	{
		system("cls");
		printLevel(attempts_left);
		cout << endl << "Cлово: " << display_word << endl;
		cout << "Введите букву: ";
		string input;
		cin >> input;
		input = str_toupper(input);
		cout << endl;
		bool unmasked = false;
		for(int i = 0; i < selected_word.size(); i++)
		{
			if (selected_word[i] == input[0])
			{
				display_word[i] = input[0];
				unmasked = true;
			}
		}

		if (!unmasked)
		{
			attempts_left--;
		}
		
	}

	system("cls");
	printLevel(attempts_left);
	cout << "Загаданное слово: " << selected_word << endl;
	
	if (attempts_left == 0)
	{
		cout << "Вы проиграли" << endl;
	} else {
		cout << "Вы выйграли" << endl;
	}
	
	return 0;
}
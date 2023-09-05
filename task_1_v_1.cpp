#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input = "";
	string buff;
	ifstream in("input.txt");
	ofstream out("output.txt");

	while (getline(in, buff)) {
		if (buff.empty()) {
			break;
		}
		input = input + buff;
	}

	auto size = input.size() + 1;
	char* str = new char[input.size() + 1];
	strcpy_s(str, size, input.c_str());
	
	char* ptr = strtok(str, ".!?");
	int sentence = 0;

	while (ptr != NULL)
	{
		sentence++;

		ptr = strtok(NULL, ".!?");

	}

	out << "Number of sentences: " << sentence << endl;

	strcpy_s(str, size, input.c_str());
		
	char* ptr1 = strtok(str, " ,.!?;:()");
	int num_of_words = 0;
    int symb_word = 0;
	
	while (ptr1 != NULL)
	{
		num_of_words++;

		if (strlen(ptr1) > 5) {
			symb_word++;
		}

		ptr1 = strtok(NULL, " ,.!?;:()");
	}

	out << "Number of words: " << num_of_words << endl;

	out << "Number of words more than: " << symb_word << endl;
	return 0;
}
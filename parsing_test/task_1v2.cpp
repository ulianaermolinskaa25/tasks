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

	out << "Number of words longer than five characters: " << symb_word << endl;
	
	
	strcpy_s(str, size, input.c_str());

	
	strtok(str, ".!?");
	out << "Reverse first sentence: ";
	char* last_space_ptr = nullptr;
	
	do {

		 last_space_ptr = strrchr(str, ' ');
		
		if (last_space_ptr != NULL) {
			out << last_space_ptr + 1 << " ";
			*last_space_ptr = '\0';
		}
	} while (last_space_ptr != NULL);

	out << str;
	
	return 0;
}
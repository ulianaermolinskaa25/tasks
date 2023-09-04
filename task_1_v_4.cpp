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
	strcpy_s(str, size, input.c_str()); //copying the source file
	
	char* ptr = strtok(str, ".!?");
	int sentence = 0;

	while (ptr != NULL)
	{
		sentence++;

		ptr = strtok(NULL, ".!?");

	}

	out << "Number of sentences: " << sentence << endl; //output of the number of srntences

	strcpy_s(str, size, input.c_str()); //copying the source file
		
	char* ptr1 = strtok(str, " ,.!?;:()");
	int num_of_words = 0;
    int simb_words = 0;
	
	while (ptr1 != NULL)
	{
		num_of_words++;

		if (strlen(ptr1) > 5) {
			simb_words++;
		}

		ptr1 = strtok(NULL, " ,.!?;:()"); 

	}

	out << "Number of words: " << num_of_words << endl; //output of the number of words in a sentence
	out << "Number of words more than: " << simb_words << endl; //output of the number of words more than five characters
	return 0;
}
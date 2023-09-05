#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input = "";
	string buff;
	ifstream in("input1.txt");
	ofstream out("output1.txt");


	while (getline(in, buff)) {
		if (buff.empty()) {
			break;
		}
		input = input + buff;
	}
	auto size = input.size() + 1;
	char* str = new char[input.size() + 1];
	strcpy_s(str, size, input.c_str());

	char* strr = str;

	do {

		char* ptr = strrchr(str, ' ');
		strr = ptr;
		if (ptr != NULL) {
			out << ptr;
			*strr = '\0';
		}
	} while (strr != NULL);

	return 0;
}
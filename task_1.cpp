#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    char prevChar = '\0';
    char curChar;
    int sentence = 0;
    int word = 0;
    int letter = 0;
    int words = 0;
    string a;
    bool f = true;
    ifstream in("input.txt");
    ofstream out("output.txt");

    while (in.get(curChar)) {
        if (curChar == '.' || curChar == '!' || curChar == '?' || curChar == '/n') {
            if (prevChar != '.' && prevChar != '!' && prevChar != '?' && prevChar != '/n') {
                sentence++;
            }
        }
        if (curChar == '.' || curChar == '!' || curChar == '?' || curChar == ' ' || curChar == ',' || curChar == '/n') {
            if (prevChar != '.' && prevChar != '!' && prevChar != '?' && prevChar != ' ' && prevChar != ',' && prevChar != '/n') {
                word++;
            }
        }
        if (isalpha(prevChar)) {

            a = a + " " + prevChar;

            if (curChar != '.' && curChar != '!' && curChar != '?' && curChar != ' ' && curChar != ',' && curChar != '/n') {
                letter++;
            }

            else {
                letter = 0;
                f = true;
            }

            if (letter >= 5 && f) {
                words++;
                f = false;
            }

        }

        prevChar = curChar;
    }

    out << "Number of sentences: " << sentence << endl;
    out << "Number of words: " << word << endl;
    out << "Number of words longer than five characters: " << words << endl;

    return 0;
}
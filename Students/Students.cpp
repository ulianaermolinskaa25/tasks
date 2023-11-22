#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "StudentsGenerator.h"
#include "StudentsDatabase.h"

using namespace std;

int main()
{
    StudentsGenerator generator;
    vector<Student> students;

    generator.generate("Students_0.txt", students, 100);
 
    StudentsDatabase database;
    database.loadDatabase("Students_0.txt");
    database.minStudentFile(students, "Student_1.txt");
    database.findLetterStudent(students, 'B');

    return 0;
}
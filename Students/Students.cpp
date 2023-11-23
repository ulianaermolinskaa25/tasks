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
    database.findYoungestStudentForCourses("Students_1.txt");
    database.findStudentsForInitials("Students_2.txt", 'A');
    database.findOlderStudents("Students_3.txt", 21);
    database.findYoungerStudents("Students_4.txt", 21);
    database.findExcellentStudents("Students_5.txt", 1);
    database.findPoorStudents("Students_6.txt", 3);
    database.findAboveAvaragePraogessStudents("Students_7.txt");
    database.findAboveAvaragePraogessStudentsForCourses("Students_8.txt");

    return 0;
}
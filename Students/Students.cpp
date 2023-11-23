#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "StudentsGenerator.h"
#include "StudentsDatabase.h"

using namespace std;

typedef struct // Структура
{
    string surname;
    string name;
    string patronymic;
    int age;
    bool gender;
    short course;
    float progress;
} Student;

int main()
{
    StudentsGenerator generator;
    vector<Student> students;

    generator.generate("Students_0.txt", students, 100);                    //task_0
 
    StudentsDatabase database;
    database.loadDatabase("Students_0.txt");                                
    database.findYoungestStudentForCourses("Students_1.txt");               //task_1
    database.findStudentsForInitials("Students_2.txt", 'A');                //task_2
    database.findOlderStudents("Students_3.txt", 21);                       //task_3
    database.findExcellentStudents("Students_4.txt", 1);                    //task_4
    database.findPoorStudents("Students_5.txt", 3);                         //task_5
    database.findYoungerStudents("Students_6.txt", 21);                     //task_6
    database.findAboveAvaragePraogessStudents("Students_7.txt");            //task_7
    database.findAboveAvaragePraogessStudentsForCourses("Students_8.txt");  //task_8

    return 0;
}
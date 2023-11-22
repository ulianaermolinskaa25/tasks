#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

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

class StudentsGenerator
{
public:
    StudentsGenerator() // Конструктор без параметров, загрузка файлов
    {
        loadNames("Surname_boy.txt", manSurnames);
        loadNames("Surname_girl.txt", girlSurnames);
        loadNames("Name_boy.txt", manNames);
        loadNames("Name_girl.txt", girlNames);
        loadNames("Patronymic_boy.txt", manPatronymics);
        loadNames("Patronymic_girl.txt", girlPatronymics);
    }

    ofstream generate(const string& filename, const vector<Student>& students, const uint32_t N) // Генерация списка студентов, запись в файл, выыод файла со списком
    {
        //srand(time(0));

        ofstream fout(filename);
        if (!fout.is_open())
        {
            cout << "Error: Unable to open the file " << filename << endl;
            return fout;
        }

        for (size_t j = 0; j < N; j++)
        {
            Student student = generateStudent(students);
            fout << student.surname << ' ' << student.name << ' ' << student.patronymic << ' '
                << student.gender << ' ' << student.age << ' ' << student.course << ' ' << student.progress << endl;
        }

        return fout;
    }


protected:
    vector<string> manSurnames, girlSurnames, manNames, girlNames, manPatronymics, girlPatronymics, stud;

    void loadNames(const string& filename, vector<string>& names) // Сохранение данных исходных файлов в вектор
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Error: Unable to open the file " << filename << endl;
            return;
        }

        string data;
        while (file >> data)
        {
            names.push_back(data);
        }

        file.close();

    }

    string getRandomName(const vector<string>& names) // Генерация случаных ФИО
    {
        return names[rand() % names.size()];
    }

    Student generateStudent(const vector<Student>& students) // Генерация студента
    {
        Student student;
        student.surname = getRandomName(manSurnames);
        student.name = getRandomName(manNames);
        student.patronymic = getRandomName(manPatronymics);
        student.gender = false; // Мужской пол
        student.age = rand() % 10 + 18; // Генерация возраста от 18 до 27 лет
        student.course = rand() % 4 + 1; // Генерация курса от 1 до 4
        student.progress = static_cast<float>(rand() % 100) / 10.0; // Генерация успеваемости от 0 до 10

        // Вероятность выбора женского пола: 30%
        if (rand() % 100 < 30)
        {
            student.surname = getRandomName(girlSurnames);
            student.name = getRandomName(girlNames);
            student.patronymic = getRandomName(girlPatronymics);
            student.gender = true; // Женский пол
        }

        return student;
    }
};
class StudentsDatabase
{
public:

    StudentsDatabase()
    {}

    vector<Student> students;

    void loadDatabase(const string& filename)
    {
        ifstream fin(filename);
        if (!fin.is_open())
        {
            cout << "Error: Unable to open the file " << filename << endl;
            return;
        }
        while (!fin.eof())
        {
            Student student;
            fin >> student.surname >> student.name >> student.patronymic >> student.gender >> student.age >> student.course >> student.progress;

            students.push_back(student);
            //cout << student.surname << ' ' << student.name << ' ' << student.patronymic << ' ' << student.gender << ' ' << student.age << ' ' << student.progress << endl;
        }

        fin.close();
    }

    ofstream minStudentFile(const vector<Student> students, const string& filename)
    {
        ofstream fout(filename);

        if (!fout.is_open())
        {
            cout << "Error: Unable to open the file " << filename << endl;
            return fout;
        }

        Student student;
        vector<vector<Student>> courses = courseStudent();
        vector<Student> minStudents;

        for (int i = 0; i < 4; ++i)
        {
            student = findMinStudent(courses, i + 1);
            minStudents.push_back(student);
        }

        for (const auto& minStudent : minStudents)
        {
            fout << minStudent.surname << ' ' << minStudent.name << ' ' << minStudent.patronymic << endl;
        }

        return fout;
    }

//private:

    vector<vector<Student>> courseStudent()
    {
        vector<vector<Student>> courses(4);

        for (const auto& student : students)
        {
            int index = student.course - 1;
            courses[index].push_back(student);
        }

        return courses;
    }

    Student findMinStudent(const vector<vector<Student>>& courses, int Course)
    {
        if (Course < 1 || Course > courses.size())
        {
            cout << "Invalid course number." << endl;
            return Student();
        }

        const vector<Student>& students = courses[static_cast<std::vector<std::vector<Student, std::allocator<Student>>, std::allocator<std::vector<Student, std::allocator<Student>>>>::size_type>(Course) - 1];
        if (students.empty())
        {
            cout << "No students in the course." << endl;
            return Student();
        }
        else
        {
            int minAge = students[0].age;
            vector<Student> minStudents;

            for (const auto& student : students)
            {
                if (student.age < minAge)
                {
                    minAge = student.age;
                    minStudents.clear();
                    minStudents.push_back(student);
                }
                else if (student.age == minAge)
                {
                    minStudents.push_back(student);
                }
            }

           /* for (const auto& student : minStudents) {
                cout << "Minimum age in course " << Course << ": " << minAge << ' ' << student.surname << ' ' << student.name << ' ' << student.patronymic << endl;
            }*/
            return minStudents[0];
        }
    }

    bool findLetter(const string& surname, const char N) {
        return surname[0] == N;
    }

    Student findLetterStudent(const vector<Student> students, const char N)
    {
        vector<Student> letter;
        for (const auto& student : students)
        {
            if (findLetter(student.surname, N))
            {
                letter.push_back(student);
                cout << student.surname << ' ' << student.name << ' ' << student.patronymic << endl;
            }
            else
            {
                cout << "Surname not found." << endl;
            }
        }
        return letter[0];
    }
};

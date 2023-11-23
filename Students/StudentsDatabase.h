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

    void writeToFile(const vector<Student> students, const string& filename)
    {
        ofstream fout(filename);
        
        if (!fout.is_open())
        {
            fout << "Error: Unable to open the file " << filename << endl;
            return;
        }

        for (const auto& student : students)
        {
              fout << ":\t" << student.surname << ' ' << student.name << ' ' << student.patronymic << ' '
            << "\tGender: " << (student.gender ? "Girl" : "Boy") << ", \tAge: " << student.age << ", \tCourse: " << student.course << ", \tProgress: " << student.progress << endl;
        }

        fout.close();
    }

   //1. По исходному списку определить ФИО самого младшего студента на каждом курсе. 
   //Сформировать список из этих студентов, в отдельном файле students_1.txt.
   //Аналогично сохранение результатов для каждого следующего задания

    void findYoungestStudentForCourses(const string& filename)
    {
        Student student;
        vector<vector<Student>> courses = courseStudent();
        vector<Student> minStudents;

        for (int i = 0; i < 4; ++i)
        {
            student = getMinStudent(courses[i]);
            minStudents.push_back(student);
        }
       
        writeToFile(minStudents, filename);
    }

    //2. Определить всех студентов, ФИО которых начинается на заданную букву. 

    void findStudentsForInitials(const string& filename, const char initial)
    {
        vector<Student> initials;

        for (const auto& student : students)
        {
            if (!student.surname.empty() && student.surname[0] == initial)
            {
                initials.push_back(student);
                // cout << student.surname << ' ' << student.name << ' ' << student.patronymic << endl;
            }
        }
        if (initials.empty())
        {
            cout << "No students with the specified initial found." << endl;
        }

        writeToFile(initials, filename);
    }

    //3. Определить всех студентов, возраст которых превышает заданный

    void findOlderStudents(const string& filename, const int32_t age)
    {
        vector<Student> ages;

        for (const auto& student : students)
        {
            if (student.age > age)
            {
                ages.push_back(student);
                //cout << student.surname << ' ' << student.name << ' ' << student.patronymic << endl;
            }
        }
        if (ages.empty())
        {
            cout << "No students found." << endl;
        }

        writeToFile(ages, filename);
    }
    //4. Определить всех отличников n курса

    void findExcellentStudents( const string& filename, const int course) 
    {
        vector<Student> excellentStudent;
        float mark = 8.0;

        for (const auto& student : students)
        {
            if (student.course == course && student.progress > mark)
            {
                excellentStudent.push_back(student);
            }
        }

        if (excellentStudent.empty())
        {
            cout << "No students found." << endl;
        }

        writeToFile(excellentStudent, filename);
    }

    //5. Определить всех неуспевающих студентов n курса

    void findPoorStudents(const string& filename, const int course)
    {
        vector<Student> poorStudent;
        float mark = 8.0;

        for (const auto& student : students)
        {
            if (student.course == course && student.progress <= mark)
            {
                poorStudent.push_back(student);
                //cout << student.surname << ' ' << student.name << ' ' << student.patronymic << ' ' << student.progress << endl;
            }
        }

        if (poorStudent.empty())
        {
            cout << "No students found." << endl;
        }

        writeToFile(poorStudent, filename);
    }

    //6. Определить всех студентов, возраст которых не превышает заданный. 

    void findYoungerStudents(const string& filename, const int32_t age)
    {
        vector<Student> ages;

        for (const auto& student : students)
        {
            if (student.age < age)
            {
                ages.push_back(student);
                //cout << student.surname << ' ' << student.name << ' ' << student.patronymic << endl;
            }
        }
        if (ages.empty())
        {
            cout << "No students found." << endl;
        }

        writeToFile(ages, filename);
    }

    //7. Определить студентов, имеющих средний бал успеваемости выше общего среднего бала. 

    void findAboveAvaragePraogessStudents(const string& filename) 
    {
       
        vector<Student> avarageStudents = getAvarageProgress(students);
        writeToFile(avarageStudents, filename);

        if (avarageStudents.empty())
        {
            cout << "No students found." << endl;
        }

    }

    //8. Определить студентов, имеющих средний бал успеваемости выше среднего бала по его курсу. 

    void findAboveAvaragePraogessStudentsForCourses(const string& filename)
    {
        Student student;
        auto courses = courseStudent();

        for (int i = 0; i < courses.size(); i++)
        {
            vector<Student> avarageStudents = getAvarageProgress(courses[i]);
            writeToFile(avarageStudents, filename);
        }
    }

private:

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

    Student getMinStudent(const vector<Student> students)
    {
        if (students.empty())
        {
            cout << "No students in the course." << endl;
            return Student();
        }

        Student minStudent;
        minStudent.age = INT_MAX;

        for (const auto& student : students)
        {

            if (student.age < minStudent.age)
            {
                minStudent = student;
                //cout << student.surname << ' ' << student.name << ' ' << student.patronymic << endl;
            }
        }
        return minStudent;
    }

    vector<Student> getAvarageProgress(const vector<Student>& student)
    {
        vector<Student> aboveAverageStudents;
        double totalProgress = 0.0;

        for (const auto& student : students) {
            totalProgress += student.progress;
        }

        double averageProgress = totalProgress / students.size();

        for (const auto& student : students) {
            if (student.progress > averageProgress) {
                aboveAverageStudents.push_back(student);
                //cout << student.surname << ' ' << student.name << ' ' << student.patronymic << ' ' << student.progress << endl;
            }
        }
        return aboveAverageStudents;
    }
};

#include <iostream>
#include <vector>
using namespace std;
class Student {
public:
    std::string name;
    int grade;

    Student(const std::string& n, int g)
    {
        this->name = n;
        this->grade = g;
    }
};

class StudentList {
private:
    std::vector<Student> students;

public:
    
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    
    vector<Student> getStudentsWithGrade(int targetGrade) {
        vector<Student> result;

        for (int i = 0; i < students.size(); ++i) {
            const Student& student = students[i];
            if (student.grade == targetGrade) {
                result.push_back(student);
            }
        }

        return result;
    }
};

int main() {
    StudentList studentList;

    
    studentList.addStudent(Student("Ravan", 5));
    studentList.addStudent(Student("Misu", 4));
    studentList.addStudent(Student("Ion", 5));
    studentList.addStudent(Student("David", 3));

    
    int targetGrade = 5;
    vector<Student> studentsWithGrade = studentList.getStudentsWithGrade(targetGrade);

    
    if (studentsWithGrade.empty()) {
        std::cout << "No students found with grade " << targetGrade << "." << std::endl;
    }
    else {
        std::cout << "Students with grade " << targetGrade << ":" << std::endl;
        for (const auto& student : studentsWithGrade) {
            std::cout << "Name: " << student.name << ", Grade: " << student.grade << std::endl;
        }
    }

    return 0;
}

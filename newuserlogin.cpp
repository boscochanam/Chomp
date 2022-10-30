#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct UserData {
public:
    StudentRecord(
        string id,
        string firstName,
        string lastName,
        int age,
        string phoneNumber,
        double gpa
    ) {
        Id = id;
        FirstName = firstName;
        LastName = lastName;
        PhoneNumber = phoneNumber;
        Age = age;
        Gpa = gpa;
    }

    void display() {
        cout << "   Student ID: " << Id << endl;
        cout << "   First Name: " << FirstName << endl;
        cout << "    Last Name: " << LastName << endl;
        cout << " Phone Number: " << PhoneNumber << endl;
        cout << "          Age: " << Age << endl;
        cout << "          GPA: " << Gpa << endl;
        cout << endl;
    }

    string Id;
    string FirstName;
    string LastName;
    string PhoneNumber;
    int Age;
    double Gpa;

};

void displayStudents(vector<StudentRecord>& students) {

    for (auto student : students) {
        student.display();
    }
}

int main()
{
    ifstream inputFile;
    inputFile.open("C:\\temp\\student-records.csv");
    string line = "";

    vector<StudentRecord> students;
    while (getline(inputFile, line)) {

        stringstream inputString(line);

        //StudentId, Last Name, FirstName, Age, Phone Number, GPA
        string studentId;
        string lastName;
        string firstName;
        int age;
        string phone;
        double gpa;
        string tempString;

        getline(inputString, studentId, ',');
        getline(inputString, lastName, ',');
        getline(inputString, firstName, ',');
        getline(inputString, tempString, ',');
        age = atoi(tempString.c_str());
        getline(inputString, phone, ',');
        getline(inputString, tempString);
        gpa = atof(tempString.c_str());

        StudentRecord student(studentId, lastName,
            firstName, age, phone, gpa);
        students.push_back(student);
        line = "";
    }

    displayStudents(students);
}
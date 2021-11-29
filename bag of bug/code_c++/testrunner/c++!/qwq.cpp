//#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std;
int i;
class Student
{
private:
    string Name;
    char Sex;
    int Age;
    float English;
    float Math;
    float Program;

public:
    float Total;
    void SetName();
    void SetSex();
    void SetAge();
    void SetStudent();
    void GetTotal();
    void display();
};
void Student::SetName()
{
    string name;
    cout << "Name: ";
    cin >> name;
    Name = name;
}

void Student::SetSex()
{
    char sex;
    cout << "Sex: ";
    cin >> sex;
    Sex = sex;
}

void Student::SetAge()
{
    int age;
    cout << "Age: ";
    cin >> age;
    Age = age;
}

void Student::SetStudent()
{
    float english, math, program;
    cout << "English: ";
    cin >> english;
    English = english;
    cout << "Math: ";
    cin >> math;
    Math = math;
    cout << "Program: ";
    cin >> program;
    Program = program;
}
void Student::GetTotal()
{
    Total = English + Math + Program;
    //return English + Math + Program;
}

void Student::display()
{
    cout << setw(10) << setfill(' ') << "Name";
    cout << setw(10) << setfill(' ') << "Age";
    cout << setw(10) << setfill(' ') << "Sex";
    cout << setw(10) << setfill(' ') << "English";
    cout << setw(10) << setfill(' ') << "Math";
    cout << setw(10) << setfill(' ') << "Program";
    cout << setw(10) << setfill(' ') << "Total" << endl;

    cout << setw(10) << setfill(' ') << Name;
    cout << setw(10) << setfill(' ') << Age;
    cout << setw(10) << setfill(' ') << Sex;
    cout << setw(10) << setfill(' ') << English;
    cout << setw(10) << setfill(' ') << Math;
    cout << setw(10) << setfill(' ') << Program;
    cout << setw(10) << setfill(' ') << Total << endl;
}

int main(int argc, char *argv[])
{
    int x, n = 1;
    Student stu[5];
    for (i = 0; n != 0; i++)
    {
        stu[i].SetName();
        stu[i].SetAge();
        stu[i].SetSex();
        stu[i].SetStudent();
        stu[i].GetTotal();
        cout << "Do you want to enter the next student's message?" << endl;
        cout << "If you want,please enter 1." << endl;
        cout << "If not,please enter 0." << endl;
        getchar();
        cin >> n;
    }

    for (x = 0; x < i; x++)
    {
        stu[x].display();
    }

    return 0;
}

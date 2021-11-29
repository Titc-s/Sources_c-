//#include "stdafx.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int i;
class Student
{
private:
    char Name[20];
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
    //  void sort(Student[]);
};
void Student::SetName()
{
    char name[20];
    cout << "Name: ";
    cin >> name;
    strcpy(Name, name);
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
// void Student::sort(Student stu[])
// {
//     int x, y;
//     for (x = 1; x <= i; x++)
//         for (y = 0; y <= i - x - 1; y++)
//         {
//             if ((stu[y].GetTotal()) < (stu[y + 1].GetTotal()))
//             {
//                 stu[4] = stu[y];
//                 stu[y] = stu[y + 1];
//                 stu[y + 1] = stu[4];
//             }
//         }
// }
void sort(Student stu[])
{
    Student temp;
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4 - j; i++)
            if (stu[i].Total > stu[i + 1].Total)
            {
                temp = stu[i];
                stu[i] = stu[i + 1];
                stu[i + 1] = temp;
            }
    }
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
    sort(stu);
    for (x = 0; x < i; x++)
    {
        stu[x].display();
    }

    return 0;
}

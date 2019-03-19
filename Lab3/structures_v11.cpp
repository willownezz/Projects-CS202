//  structures_v11.cpp
//  Test program fpr structures

//  Version 1.0 ... basic version\
//  Versopm 1.1 ... adds input function and output function

#include <iostream>

using namespace std;

struct StudentGrade
{
    char fname[21];         // First name field (or data member)
    char lname[21];         // Last name field (or data member)
    unsigned int test[5];   //  Array of 5 tests
    double average;         // Average of 5 scores
    char letter_grade;      // Letter grade: A B C D F
};

//Function prototype go here

void get_student_info(StudentGrade *);
void show_student_info(StudentGrade *);

//          int argc;           // Number of parameters on the command line
//          char *argv[]        // An array pointers to C-String
//  "main()" function --- the program's entry point

int main(int argc, char *argv[])
{
    StudentGrade student;
    
    cout << "The size of object 'student' is: "
        << sizeof(student) << endl << endl;

get_student_info(& student);        // Data input
show_student_info(& student);       // Output statements

return 0;

}

// "get_student_info()" function
// demonstrates using pointers to access structure

void get_student_info(StudentGrade * s)
{    
    cout << "The size of pointers 's' is: " << sizeof(s) << endl << endl;
    cout << sizeof(s) << endl << endl;

    cout << "Enter first name: ";       //Data input
    cin >> (*s).fname;
    
    cout << "Enter last name: ";
    cin >> (*s).lname;

    for(int i = 0; i < 5; ++i)
    {
         cout << "Enter test score: ";
         cin >> (*s).test[i];
    }
}

// "Show_student_info()" function
// demonstrates using structure pointer operator
// (also know as the "arrow operator") to access structure

void show_student_info(StudentGrade *s)
{
    cout << endl;
    cout << "First name: " << s->fname << endl;
    cout << "Last name: " << s->lname << endl;

    for(int i = 0; i < 5; ++i)
    {
        cout << "Test score: " << s->test[i] << endl;
    }
}



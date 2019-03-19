//  structures_v14.cpp
//  Test program for structures

//  Version 1.0 ... basic version\
//  Version 1.1 ... adds input function and output function
//  Version 1.2 ... adds functions to calculate average and grade
//                  and GradeInfo nested structure
//  Version 1.3 ... create a header file with a preprocessor macro
//                  and dynamic memory for "student" in main()
//  Version 1.4 ... reads input file name from command line

#include <iostream>
#include "structures_v14.h"

using namespace std;

//          int argc;           // Number of parameters on the command line
//          char *argv[]        // An array pointers to C-String
//  "main()" function --- the program's entry point

int main(int argc, char *argv[])
{
    StudentGrade student;
    StudentGrade * student = new StudentGrade;

    //////////////////////////////////////////////////
    cout << "argc = " << argc << endl;
    
    if(argc > 1)
        read_file(argv[1], student);
    else
        get_student_info(cin, student, 1);      // Data input

    show_student_info(student);                 // Output statements

    delete student; 
    //////////////////////////////////////////////////
    cout << "The size of type 'GradeInfo' is: " << sizeof(GradeInfo) << endl;
    cout << "The size of type 'StudentGrade' is: " << sizeof(StudentGrade) << endl;

    get_student_info(& student);        // Data input
    show_student_info(& student);       // Output statements

    return 0;
}

// "get_student_info()" function
//  demonstrates using pointers to access structure

void get_student_info(StudentGrade * s)
{    
    cout << "The size of pointers 's' is: " << sizeof(s) << endl << endl;
//  cout << sizeof(s) << endl << endl;

    cout << "Enter first name: ";       //Data input
    cin >> (*s).fname;
    
    cout << "Enter last name: ";
    cin >> (*s).lname;

    for(size_t i = 0; i < ARRAY_SIZE(s->grades); ++i)
    {
         cout << "Enter test score: ";
         cin >> (*s).grades[i].test;
    }
}

// "Show_student_info()" function
// demonstrates using structure pointer operator
// (also know as the "arrow operator") to access structure

void show_student_info(StudentGrade *s)
{
    unsigned int max_score = 0;    

    cout << endl;                                           // Output statements
    cout << "First name: " << s->fname << endl;
    cout << "Last  name: " << s->lname << endl;
    cout << endl;

    for(size_t i = 0; i < ARRAY_SIZE(s->grades); ++i)
    {
        s->grades[i].letter_grade = get_grade(s->grades[i].test);
        max_score = MAX(max_score, s->grades[i].test);
        cout << " Test score: " << s->grades[i].test;
        cout << "     " << s->grades[i].letter_grade << endl;
    }   

    s->average = get_average(ARRAY_SIZE(s->grades), s->grades);
    s->final_grade.letter_grade = get_grade(s->average);

    cout << endl << endl;
    cout << "\n  Max score: " << max_score << endl;
    cout << "    Average: " << s->average << endl;
    cout << "      Grade: " << s->final_grade.letter_grade << endl;
    cout << endl;
}
double get_average(int num_tests, GradeInfo grades[])
{
    double sum = 0.0;

    for(size_t i = 0; i < num_tests; ++i)
        sum += grades[i].test;

    return(sum / num_tests);
}
char get_grade(double avg)
{
    char grade = 'F';

    if (avg >= 60) grade = 'D';
    if (avg >= 70) grade = 'C';
    if (avg >= 80) grade = 'B';
    if (avg >= 90) grade = 'A';

    return (grade);
}
void read_file(char* file, StudentGrade *student)
{
    ifstream infile(file);

    if(!infile)                                         // Test for errors
        cout << "\nError opening file: " << file << "\n\n";

    else
    {
        cout << "Input file: " << file << endl;
        get_student_info(infile, student, 0);           // Data input
        infile.close();
    }
}

// "get_student_info()" function
// NOTES:           mode: 0 = batch, 1 = interactive

void get_student_info(istream &in, StudentGrade *s, bool mode)
{
    if(mode) cout << "Enter first name: ";              // Data input
    in >> (*s).fname;

    if(mode) cout << "Enter last name: ";
    in >> (*s).lname;

    cout << "\nNum. tests: " << ARRAY_SIZE((*s).grades) << endl;

    for(size_t i = 0; i < ARRAY_SIZE((*s).grades); ++i)
    {
        if(mode) cout << "Enter test score: ";
        in >> (*s).grades[i].test;
    }
}


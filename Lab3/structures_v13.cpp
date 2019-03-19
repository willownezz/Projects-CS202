// structures_v13.cpp
// Test program for structures

// Version 1.0 ... basic version
// Version 1.1 ... adds input function and output fnction
// Version 1.2 ... adds functions to calculate average and grade
//                 and GradeInfo nested structure
// Version 1.3 ... create a header file with a preprocessor macro
//                 and dynamic memory for "student" in main()

#include "structures_v13.h"

//      int argc,       // Number of parameters on the command line
//      char *argv[]    // An array of pointers to C-strings
// "main()" function --- the program's entry point

int main(int argc, char *argv[])
{
    StudentGrade * student = new StudentGrade;

    cout << "The size of type 'student' is: " << sizeof(student) << endl;

    get_student_info (& student[0]);       // Data input
    show_student_info(student);       // Output statements

    delete student;

    return 0;
}

// "get_student_info()" function
// demonstrates using pointers to access structure

void get_student_info(StudentGrade * s)
{
    cout << "The size of pointer 's' is: " << sizeof(s) << endl << endl;

    cout << "Enter first name: ";       // Data input
    cin >> (*s).fname;

    cout << "Enter last  name: ";
    cin >> (*s).lname;

    for (size_t i = 0; i < ARRAY_SIZE(s->grades); ++i)
    {
        cout << "Enter test score: ";
        cin >> (*s).grades[i].test;
    }
}


// "show_student_info()" function
// demonstrates using structure pointer operator
// (also know as the "arrow operator") to access structure

void show_student_info(StudentGrade *s)
{
    unsigned int max_score = 0;

    cout << endl;                                   //Output statements
    cout << "First name: " << s->fname << endl;
    cout << "Last  name: " << s->lname << endl;

    for (size_t i = 0; i < ARRAY_SIZE(s->grades); ++i)
    {
        s->grades[i].letter_grade = get_grade(s->grades[i].test);
        max_score = MAX(max_score, s->grades[i].test);
        cout << "Test score: " << setw(3) << s->grades[i].test
             << "    " << s->grades[i].letter_grade << endl;
    }

    s->average = get_average(ARRAY_SIZE(s->grades), s->grades);
    s->final_grade.letter_grade = get_grade(s->average);

    cout << "\n Max score: " << max_score << endl;
    cout << "   Average: " << s->average << endl;
    cout << "     Grade: " << s->final_grade.letter_grade << endl;
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

    if (avg >- 60) grade = 'D';
    if (avg >- 70) grade = 'C';
    if (avg >- 80) grade = 'B';
    if (avg >- 90) grade = 'A';

    return (grade);
}

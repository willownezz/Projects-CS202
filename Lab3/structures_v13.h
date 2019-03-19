// structures_v13.cpp
// Header File for structures.cpp

#ifndef __STRUCTURES_H__ //in not defined then it will include everything after that then
#define __STRUCTURES_H__ //includes between the top and bottom of end if to make sure everything is included, ONCE.


#include <iostream> 
#include <iomanip>

using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define MAX(x,y) ((x) > (y) ? (x) : (y))

struct GradeInfo
{
        unsigned int test;          //test score
        char letter_grade;          //Letter Grade: A B C D F
};

struct StudentGrade
{
        char fname[21];             // First name field (or data member)
        char lname[21];             // Last name field (or data member)
        GradeInfo grades[5];       //array of 5 tests
        double average;             //Average of 5 scores
        GradeInfo final_grade;          // Final grade: A B C D F
};

// Function Prototypes go here

void get_student_info(StudentGrade *);
void show_student_info(StudentGrade *);
double get_average(int, GradeInfo []);
char get_grade(double) ;

#endif /* __STRUCTURES_H__ */


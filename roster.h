/* 
 * File:   roster.h
 * Author: Stephen Sorensen
 *
 * Created on March 18, 2019, 12:57 AM
 */

#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
using namespace std;

class Roster {
public:
    
    //default constructor
    Roster();
    //deconstructor
    ~Roster();
    void add(string studentID, string firstName, string lastName, string emailAddress,
             int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);
    void remove(string studentID);
    void printAll(); 
    void printAverageDaysInCourse(string StudentID);
    void printInvalidEmails();
    void printByDegreeProgram(int degreeProgram);
    
private:

    //Array of pointers
    Student *classRosterArray[5];

};


#endif /* ROSTER_H */

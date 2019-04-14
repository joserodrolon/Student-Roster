/* 
 * File:   student.h
 * Author: Stephen Sorensen
 *
 * Created on March 18, 2019, 12:53 AM
 */

#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
#include <iostream>
#include <array>
#include <vector>
using namespace std;

class Student {
public:
    //Constructor
    Student();
    //Overloaded constructor
    Student(string studentID, string fName, string lName, string emailAddr, int age,
            int numDays1, int numDays2, int numDays3, Degree degree);
    //Virtual print
    virtual void print();
    //Deconstructor 
    ~Student();
    //Accessors
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    vector<int> getnumDays();
    
    virtual Degree getDegreeProgram();

    //Mutators
    void setStudentID(string sID);
    void setFirstName(string fname);
    void setLastName(string lname);
    void setEmail(string email);
    void setAge(int age);
    void setNumDays(vector<int> days);
    void setDegree(Degree degree);

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    vector<int> numDays;
    Degree degree;

};







#endif /* STUDENT_H */

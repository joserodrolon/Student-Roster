/* 
 * File:   roster.cpp
 * Author: Stephen Sorensen
 * 
 * Created on March 18, 2019, 12:57 AM
 */

#include <array>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring> //email character checking function
#include <string>
#include "roster.h"
#include "degree.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
using namespace std;

//Default Constructor
Roster::Roster() {

}

const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Stephen,Sorensen,ssore16@wgu.edu,31, 30, 20, 15,SOFTWARE"
};

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {

    for (int i = 0; i < 5; i++) {
        int index = stoi(studentID.substr(1)) - 1; //Convert string to int
        if (degree == Degree::NETWORKING) {
            NetworkStudent *student = new NetworkStudent; //new Network student object
            vector<int> numDays;
            numDays.push_back(daysInCourse1);
            numDays.push_back(daysInCourse2);
            numDays.push_back(daysInCourse3);
            student->setStudentID(studentID);
            student->setFirstName(firstName);
            student->setLastName(lastName);
            student->setEmail(emailAddress);
            student->setAge(age);
            student->setNumDays(numDays);
            student->setDegree(degree);
            classRosterArray[index] = student;
        }
        if (degree == Degree::SECURITY) {
            SecurityStudent *student = new SecurityStudent; //new Security student object
            vector<int> numDays;
            numDays.push_back(daysInCourse1);
            numDays.push_back(daysInCourse2);
            numDays.push_back(daysInCourse3);
            student->setStudentID(studentID);
            student->setFirstName(firstName);
            student->setLastName(lastName);
            student->setEmail(emailAddress);
            student->setAge(age);
            student->setNumDays(numDays);
            student->setDegree(degree);
            classRosterArray[index] = student;
        }
        if (degree == Degree::SOFTWARE) {
            SoftwareStudent *student = new SoftwareStudent; //new Software student object
            vector<int> numDays;
            numDays.push_back(daysInCourse1);
            numDays.push_back(daysInCourse2);
            numDays.push_back(daysInCourse3);
            student->setStudentID(studentID);
            student->setFirstName(firstName);
            student->setLastName(lastName);
            student->setEmail(emailAddress);
            student->setAge(age);
            student->setNumDays(numDays);
            student->setDegree(degree);
            classRosterArray[index] = student;
        }
    }
}

//removes students from the roster by student ID. 
void Roster::remove(string studentID) {
    
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i]) {
            if (classRosterArray[i]->getStudentID() == studentID) {
 
                classRosterArray[i] = 0;
            }
        }
    }
}

//Print entire student roster
void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        classRosterArray[i]->print();
    }
    cout << endl;
}

/*
 FIXME ----- 3D
 Correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
 */
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < 5; i++) {
        if ((classRosterArray[i])->getStudentID() == studentID) {
            int average = 0;
            average = ((classRosterArray[i])->getnumDays()[0] + (classRosterArray[i])->getnumDays()[1] + (classRosterArray[i])->getnumDays()[2]) / 3;
            cout << "Average time take for: " << studentID << " to finish 3 courses: " << average << " days." << endl;
        }
    }
    cout << endl;
}


/* verifies student email addresses and displays all invalid email addresses to the user
 * A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
 */
// Checking emails and display invalid ones
void Roster::printInvalidEmails() {
    bool at = false;
    bool space = false;
    bool period = false;
    
    cout << "Invalid Emails:" << endl;
    for (int i = 0; i < 5; i++) {
        string email = (classRosterArray[i])->getEmail();
        for (char& c : email) { //copy each element of email and store in c
           if (c == '@') {
                at = true;
            }
           if (c == '.') {
                period = true;
            }
           if(isspace(c)){ //check for whitespace
                space = true;
            }
        }
        if (at == false || period == false || space == true) {
            cout << (classRosterArray[i])->getEmail() << endl;
        }
    }
}

void Roster::printByDegreeProgram(int degreeProgram) {
 
    if (degreeProgram == Degree::SECURITY) {
        
        cout << "Security Degree students: " << endl;
        classRosterArray[0]->print();
        classRosterArray[3]->print();
    }
    if (degreeProgram == Degree::NETWORKING) {
        
        cout << "Networking Degree students: " << endl;
        classRosterArray[1]->print();
    }
    if (degreeProgram == Degree::SOFTWARE) {
        
        cout << "Software Degree students: " << endl;
        classRosterArray[2]->print();
        classRosterArray[4]->print();
    }
    cout << endl;
}

Roster::~Roster() {
}

int main() {

    //Course title, language, StudentID, name
    cout << "C867 - Scripting and Programming - Applications " << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID# 000785924" << endl;
    cout << "Stephen Sorensen" << endl;
    cout << endl;

    Roster classRoster;
    Degree myDegree;

    //Add each student to class roster
    for (int i = 0; i < 5; i++) {
        stringstream student(studentData[i]);

        vector<string> index;

        while (student.good()) { //loop while the stream is good
            string substr;
            getline(student, substr, ',');
            index.push_back(substr);
        }
        if (index[8] == "SECURITY") {
            myDegree = Degree::SECURITY;
        }
        if (index[8] == "SOFTWARE") {
            myDegree = Degree::SOFTWARE;
        }
        if (index[8] == "NETWORK") {
            myDegree = Degree::NETWORKING;
        }
        classRoster.add(index[0], index[1], index[2], index[3], stoi(index[4]), stoi(index[5]),
                stoi(index[6]), stoi(index[7]), myDegree);
    }

    classRoster.printAll();

    classRoster.printInvalidEmails();

    classRoster.printAverageDaysInCourse("A1");

    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");

    classRoster.remove("A3");

    //Release Roster memory
    classRoster.~Roster();
    
return 0;
}


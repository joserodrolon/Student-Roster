/* 
 * File:   student.cpp
 * Author: Stephen Sorensen
 * 
 * Created on March 18, 2019, 12:53 AM
 */

#include "student.h"
using namespace std;

Student::Student() {

}

Student::Student(string studentID, string fName, string lName, string emailAddr, int age,
        int numDays1, int numDays2, int numDays3, Degree degree) {
    setStudentID(studentID);
    setFirstName(fName);
    setLastName(lName);
    setEmail(emailAddr);
    setAge(age);
    numDays.push_back(numDays1);
    numDays.push_back(numDays2);
    numDays.push_back(numDays3);
    setDegree(degree);
}

void Student::print() {
    string program;
    //Set program to degree type
    if (degree == SECURITY) {
        program = "Security";
    } else if (degree == NETWORKING) {
        program = "Networking";
    } else if (degree == SOFTWARE) {
        program = "Software";
    }
    cout << studentID << "\t";
    cout << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t" << "Age: " << age << "\t";
    cout << "daysInCourse: " << numDays.at(0) << ", " << numDays.at(1) << ", " << numDays.at(2) << "\t"; //display 3 days
    cout << "Degree Program: " << program << "\t" << endl; //display student program
}

Degree Student::getDegreeProgram() {
}

//Student ID Accessor & mutator

void Student::setStudentID(string sID) {
    studentID = sID;
}

string Student::getStudentID() {
    return studentID;
}

//First name Accessor & Mutator

void Student::setFirstName(string fName) {
    firstName = fName;
}

string Student::getFirstName() {
    return firstName;
}

//Last name Accessor & Mutator

void Student::setLastName(string lname) {
    lastName = lname;
}

string Student::getLastName() {
    return lastName;
}

//Email Accessor & Mutator

void Student::setEmail(string email) {
    emailAddress = email;
}

string Student::getEmail() {
    return emailAddress;
}

//Age Accessor & Mutator

void Student::setAge(int age) {
    this->age = age;
}

int Student::getAge() {
    return age;
}

//Course days Accessor & Mutator

void Student::setNumDays(vector<int> days){
    numDays = days;
}

vector<int> Student::getnumDays(){
    return numDays;
}

//degree Accessor & Mutator

void Student::setDegree(Degree degree) {
    this->degree = degree;
}


//Deconstructor

Student::~Student() {
}
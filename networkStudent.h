/* 
 * File:   networkStudent.h
 * Author: Stephen Sorensen
 *
 * Created on March 18, 2019, 12:54 AM
 */

#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include "student.h"

class NetworkStudent : public Student {
public:
    //default constructor
    NetworkStudent();
    //Deconstructor
    ~NetworkStudent();

    //Override getDegreeProgram() 
    Degree getDegreeProgram();


private:
    //Hold enumerated type for degree program
    Degree degree;
};





#endif /* NETWORKSTUDENT_H */

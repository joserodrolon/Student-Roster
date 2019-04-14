/* 
 * File:   softwareStudent.h
 * Author: Stephen Sorensen
 *
 * Created on March 18, 2019, 12:56 AM
 */

#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include "student.h"

class SoftwareStudent : public Student {
public:
    //default constructor
    SoftwareStudent();

    //Override getDegreeProgram() 
    Degree getDegreeProgram();
    //override print


private:
    //Hold enumerated type for degree program
    Degree degree;

};






#endif /* SOFTWARESTUDENT_H */

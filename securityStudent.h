/* 
 * File:   securityStudent.h
 * Author: Stephen Sorensen
 *
 * Created on March 18, 2019, 12:55 AM
 */

#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "student.h"

class SecurityStudent : public Student {
public:
    //default constructor
    SecurityStudent();
    
    //Override getDegreeProgram() 
    Degree getDegreeProgram();
    //override print


private:
    //Hold enumerated type for degree program
    Degree degree;
};




#endif /* SECURITYSTUDENT_H */

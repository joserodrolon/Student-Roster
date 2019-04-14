/* 
 * File:   networkStudent.cpp
 * Author: Stephen Sorensen
 * 
 * Created on March 18, 2019, 12:54 AM
 */

#include "networkStudent.h"
#include <string>
#include <iostream>
using namespace std;

NetworkStudent::NetworkStudent() {

}
NetworkStudent::~NetworkStudent(){}

Degree NetworkStudent::getDegreeProgram() {
    return degree;
}

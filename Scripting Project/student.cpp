#include "student.h"
#include <iostream>
using namespace std;

// parameterless constructor
Student::Student(){
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for(int i = 0; i < arrSize; i++){
        this->days[i] = 0;
        this->degree = DegreeProgram::SECURITY;
    }
}

//constructor
Student::Student(string studentID,string firstName,string lastName,string email,int age,int days[], DegreeProgram degree){
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for(int i = 0; i < arrSize; i++){
        this->days[i] = days[i];
        this->degree = degree;
    }
}
//destructor
Student::~Student(){

}

//getter functions
string Student::getID(){
    return this->studentID;
}
string Student::getFirstName(){
    return this->firstName;
}
string Student::getLastName(){
    return this->lastName;
}
string Student::getEmail(){
    return this->email;
}
int Student::getAge(){
    return this->age;
}
int* Student::getDays(){
    return this->days;
}
DegreeProgram Student::getDegree(){
    return this->degree;
}

//setter functions
void Student::setID(string studentID){
    this->studentID;
}
void Student::setFirstName(string firstName){
    this->firstName = firstName;
}
void Student::setLastName(string lastName){
    this-> lastName = lastName;
}
void Student::setEmail(string email){
    this->email = email;
}
void Student::setAge(int age){
    this->age = age;
}
void Student::setDays(int days[]){
    for(int i = 0; i < arrSize;i++){
        this->days[i] = days[i];
    }
}
void Student::setDegree(DegreeProgram degree){
    this->degree = degree;
}

//used to show the titles of each category of data
void Student::printTitles() {
    cout<< "ID  / First Name /Last Name /  Email   / Age /  Days  / Degree  \n";

}

void Student::print(){
//print all info about one student
    cout << this->getID()<<"\t";
    cout << this->getFirstName()<<"\t";
    cout << this->getLastName()<<"\t";
    cout << this->getEmail()<<"\t";
    cout << this->getDays()[0] <<","<<"\t";
    cout << this->getDays()[1] <<","<<"\t";
    cout << this->getDays()[2] <<","<<"\t";
    cout << degrees[this->getDegree()]<<"\n";
}

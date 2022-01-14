# include "roster.h"
#include<sstream>
#include<iostream>


using namespace std;
void Roster::parse(string arr[]){


    DegreeProgram dg = SECURITY; // just using security as default

    //storing each element of the array passed in main into their corresponding variables to be passed to add

    string studID = arr[0];

    string fname = arr[1];

    string lname = arr[2];

    string email = arr[3];

    stringstream q(arr[4]);
    int age = 0;
    q >> age;

    stringstream r(arr[5]);
    int day1 = 0;
    r >> day1;

    stringstream s(arr[6]);
    int day2 = 0;
    s >> day2;

    stringstream t(arr[7]);
    int day3 = 0;
    t >> day3;

    //checking the last letter of the degree program to know which one to use
    if(arr[8].back()=='K'){
        dg = NETWORK;
    }

    else if(arr[8].back()=='E'){
        dg = SOFTWARE;
    }
    add(studID,fname,lname,email,age,day1,day2,day3,dg);


}

void Roster::add(string id, string fname, string lname,
                 string email, int years, int day1, int day2,
                 int day3,DegreeProgram dg){

    int arr[3] = {day1,day2,day3};
    //make new student object and add to our array
    classRosterArray[index] = new Student(id,fname,lname,email,years,arr,dg);
    index++;
}

void Roster::printAll() {
    Student::printTitles();
    //printing all students
    for(int i = 0; i < index;i++){
        classRosterArray[i]->print();
        
        //turn into string with our degrees array
        cout<<degrees[classRosterArray[i]->getDegree()]<<endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram dg) {
    Student::printTitles();
    //searching for their program in the array found in degree.h
    for(int i = 0; i < index; i++){
         if(classRosterArray[i]->getDegree()==dg){
             classRosterArray[i]->print();
         }
    }
    cout<<std::endl;
}

void Roster::printInvalidEmails() {
    //emails cannot have spaces and must have @ and .
    bool invalid = false;
    for(int i = 0; i < index;i++){
        string mail = classRosterArray[i]->getEmail();
        //check for @ and . and spaces
        if(mail.find("@")==string::npos||mail.find(".")==string::npos||mail.find(" ")!=string::npos){
            invalid = true;
            cout<<mail<<endl;
        }


    }
    if(invalid == false){
        cout<< "No invalid emails!";
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    //loop through each student and calculate their average using getDays() method
    for(int i = 0; i < index; i++){
        if(classRosterArray[i]->getID()==studentID) {
            cout << classRosterArray[i]->getID() << ":";
            cout << (classRosterArray[i]->getDays()[0]
                     + classRosterArray[i]->getDays()[1]
                     + classRosterArray[i]->getDays()[2]) / 3.0 << endl;
        }
    }
    cout<<endl;
}

void Roster::remove(string studentID) {
     bool removed = false;
     //removing student based on their id, if not found print out a not found statement
     for(int i =0; i < index;i++){
         if(classRosterArray[i]->getID()==studentID){
             removed = true;
             if(i < numOfStudents-1){
                 //swap with last book
                 Student* temp = classRosterArray[i];
                 classRosterArray[i] = classRosterArray[numOfStudents-1];
                 classRosterArray[numOfStudents-1] = temp;
             }
             index--;
         }
     }
     if(removed){
         cout<<studentID<<" removed"<<endl<<endl;
         this->printAll();
         cout<<endl;
     }else{
         cout<<studentID<<" not found"<<endl<<endl;
     }
}

//destructor
Roster::~Roster() {
    for(int i = 0; i < numOfStudents; i++){
        cout << "Deleting student "<<i+1<<endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

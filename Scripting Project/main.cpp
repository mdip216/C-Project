#include<iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include<sstream>

using namespace std;


int main(){
    cout<<"Scripting and Programming - Applications – C867,"<<" C++, "<<"ID: 006371021, "<<"Matthew DiPerna"<<endl;
    cout<<endl;
    const static int numOfStudents = 5;
    const string studentData[] =

    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Matthew,DiPerna,mdipern@wgu.edu,27,7,14,21,SOFTWARE"};

    //instance of Roster class
    Roster classRoster;

    //looping through all students, separate their info into an array
    for(int i = 0; i < numOfStudents; i++){
            // array for items of each line
            string arr[8];
            stringstream my_stream(studentData[i]);

            //parsing
            int z = 0;
            while(my_stream.good()){
                string str;
                getline(my_stream,str,',');
                arr[z] = str;
                z++;
            }
        //passing the array to our parse function
        classRoster.parse(arr);
    }
    //printing all students
    classRoster.printAll();
    cout<<endl;

    //printing by degree
    for(int i = 0;i < 3; i++){
       cout<< "Printing by degree: "<< degrees[i] << std::endl;
        classRoster.printByDegreeProgram((DegreeProgram)i);

    }

    //printing invalid emails
    cout<< "Printing invalid emails"<<endl;
    classRoster.printInvalidEmails();
    cout<<endl;

    //printing average days in class
    for(int i = 0; i < numOfStudents;i++) {
        cout << "Printing average days: " << endl;
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
    }
    //removing student

    cout<<"Removing student with ID A3"<<endl;
    classRoster.remove("A3");

    cout<<"Removing student with ID A3"<<endl;
    classRoster.remove("A3");


    return 0;
}


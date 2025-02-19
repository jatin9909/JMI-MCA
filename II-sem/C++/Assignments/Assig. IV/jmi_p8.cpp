//
//
//
//
#include<iostream>
#include<stdio.h>
#include"myfunctions.h"//NOTE: we have to complie both the files as 'g++ jmi_p8.cpp myfunctions.cpp' from terminal
#define PASS_MARKS 25

using namespace std;

class student{
protected:
  string name;
  int rollno;
public:
  void get()
  {
    bool isvalid;
    char buffer[255];

    fgets(buffer, sizeof(buffer), stdin);
    
    do{
       cout << endl << "Enter name of the student : ";
       getline(cin, name);
       isvalid = isValidName(name);
       if(!isvalid) cout << "Invalid Name...! Try Again." << endl;
      }while(!isvalid);
    
    do{
       cout << "Enter roll number : ";
       cin >> rollno;
       if(rollno < 1)cout << endl << "Invaid Rollno ...! Try Again." << endl;
      }while(rollno < 1); 
  }
  void display()
  {
    cout << endl << name << "\t" << rollno;
  }
};

class marks:public student{
protected:
  float marks1,marks2;
public:
  void get()
  {
    do{
       cout << "Enter marks in English (0 <= Marks >= 50) : ";
       cin >> marks1;
       if(marks1 < 0 || marks1 > 50) cout << endl << "Invaid Marks ...! Try Again."<< endl;
      }while(marks1 < 0 || marks1 > 50);
    do{
       cout << "Enter marks in Maths (0 <= Marks >= 50) : ";
       cin >> marks2;
       if(marks2 < 0 || marks2 > 50) cout << endl << "Invaid Marks ...! Try Again." << endl;
      }while(marks2 < 0 || marks2 > 50);
  }
  void display()
  {
   cout << "\t" << marks1 << "\t" << marks2;
  }
};

class result:public marks{
  float total;
public:
  void get()
  {
    total = marks1 + marks2;

  }
  void display()
  {
   if(total >= PASS_MARKS)
   cout << "\t" << "Passed";
   else
   cout << "\t" << "Failed";
   }
};

int main()
{
  int n;
  do{
     cout << endl << "How many students : ";
     cin >> n;

     if(n < 1) cout << endl << "Invalid input...! Try again.";
   }while(n < 1);

  result s[n];

  for(int i = 0 ; i < n ; i++)
  {
   s[i].student::get();
   s[i].marks::get();
   s[i].get();
  }

  cout << endl << "Name\tRollno\tEnglish\tMaths\tResult"<< endl;
  for(int i = 0 ; i < 38 ; i++ , cout << "-");
  for(int i = 0 ; i < n ; i++)
  {
    cout << endl;
    s[i].student::display();
    s[i].marks::display();
    s[i].display();
  }
}

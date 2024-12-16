#include<iostream>
#include<string.h>
using namespace std;

class StudData;

class Student{
    string name;
    int roll_no;
    string cls;
    char* division;
    string dob;
    char* bloodgrp;
    static int count;

    public:
    Student(){
        name = "";
        roll_no = 0;
        cls = "";
        division = new char;
        dob = "dd/mm/yyyy";
        bloodgrp = new char[4];
    }

    ~Student(){
        delete division;
        delete[] bloodgrp;
    }

    static int getcount(){
        return count;
    }

    void getdata(StudData*);
    void dispData(StudData*);
};

class StudData{
string caddress;
long int* telno;
long int* dlno;
friend class Student;

public:
StudData(){
    caddress = "";
    telno = new long;
    dlno = new long;
}

~StudData(){
    delete telno;
    delete dlno;
}

void getStudData(){
    cout<<"Enter Contact address: ";
    cin.get();
    getline(cin,caddress);
    cout<<"Enter Telephone Number: ";
    cin>>*telno;
    cout<<"Enter Driving License No: ";
    cin>>*dlno;
    }

    void dispStudData(){
        cout<<"Contact Address: "<< caddress<<endl;
        cout<<"telephone number: "<<*telno<<endl;
        cout<<"Enter driving license no: "<<*dlno<<endl;
    }

};

inline void Student:: getdata(StudData* st){
    cout<<"Enter Student Name: ";
    getline(cin,name);
    cout<<"Enter Roll Number: ";
    cin>>roll_no;
    cout<<"Enter Class: ";
    cin.get();
    getline(cin,cls);
    cout<<"Enter Division: ";
    cin>>division;
    cout<<"Enter date of birth: ";
    cin.get();
    getline(cin,dob);
    cout<<"Enter blood group: ";
    cin>>bloodgrp;
    st->getStudData();
    count++;
}
inline void Student::dispData(StudData* st1){
    cout<<"Student Name: "<<name<<endl;
    cout<<"Roll number: "<<roll_no<<endl;
    cout<<"Class: "<<cls<<endl;
    cout<<"Division: "<<division<<endl;
    cout<<"Date of Birth: "<<dob<<endl;
    cout<<"Blood Group: "<<bloodgrp<<endl;
    st1->dispStudData();
}

int Student::count;

int main(){
    Student* stud1[100];
    StudData* stud2[100];
int n=0;
char ch;
    do{
        stud1[n] = new Student;
        stud2[n] = new StudData;
        stud1[n]->getdata(stud2[n]);
        n++;
        cout<<"add another(y/n): "<<endl;
        cin>>ch;
        cin.get();
    }while(ch=='y'||ch=='Y');

    
    for(int i=0; i<n; i++){
        cout<<"--------------------------------------------"<<endl;
        stud1[i]->dispData(stud2[i]);
    }

    cout<<endl;
    cout<<"Total Students: "<<Student::getcount();


    for(int i=0; i<n; i++){
        delete stud1[i];
        delete stud2[i];

    }

    return 0;



}


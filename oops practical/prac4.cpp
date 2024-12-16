#include<iostream>
#include<fstream>
using namespace std;

class Employee{
    string Name;
    int ID;
    double salary;

    public:
    void accept(){
        cout<<"Name: ";
        cin.ignore();
        getline(cin,Name);
        cout<<endl;
        cout<<"Id: ";
        cin>>ID;
        cout<<endl;
        cout<<"Salary: ";
        cin>>salary;
    }

    void display(){
        cout<<"Name: "<<Name<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Salary: "<<salary<<endl;

    }
};

int main(){
    Employee o[5];
    fstream f;
    int i,n;
    f.open("demo.txt", ios::out);
    cout<<"Enter the number of employees you want to store: ";
    cin>>n;
    cout<<endl;
    for(i=0; i<n; i++){
        cout<<"Enter the information of Employee "<<i+1<<" "<<endl;
        o[i].accept();
        f.write((char*) &o[i], sizeof o[i]);
    }
    f.close();

    f.open("demo.txt", ios::in);
    cout<<"Information of the employees: "<<endl;
    for(i = 0; i<n; i++){
        cout<<"Employee: "<<i+1<<" "<<endl;
        f.write((char*)&o[i], sizeof o[i]);
        o[i].display();
    }
    f.close();
    return 0;
    
}




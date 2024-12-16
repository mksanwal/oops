#include<bits/stdc++.h>
using namespace std;

class publication{
    string title;
    float price;
    public:
    void add(){
        cout<<"Enter the publication information: "<<endl;
        cout<<"Enter the Title of the Publication: ";
        cin.ignore();
        getline(cin,title);
        cout<<"Enter the price of the publication: ";
        cin>>price;
    }
    void display(){
        cout<<endl;
        cout<<"Title of Publication: "<<title<<endl;
        cout<<"Publication Price: "<<price<<endl;
        
    }
};

class book: public publication{
    private:
    int page_count;
    public:
    void add_book(){
        try{
            add();
                cout<<"Enter the Page count of Book: ";
                cin>>page_count;
                cout<<endl;
                if(page_count<=0){
                    throw page_count;
                
            }
        }
        catch(...){
            cout<<"Invalid page count";
            page_count=0;
        }
    }
    void display_book(){
        display();
        cout<<"Page count: "<<page_count<<endl;
    }
};

class tape: public publication{
    float play_time;
    public:
    void add_tape(){
        try{
            add();
            cout<<"Enter Play Duration of the Tape: ";
            cin>>play_time;
            cout<<endl;
            if(play_time<=0){
                throw play_time;
            }
        }
        catch(...){
            cout<<"Invalid play time";
            play_time=0;
        }
    }

    void display_tape(){
        display();
        cout<<"Play time is: "<<play_time<<" min"<<endl;
    }
};



int main(){
    book b1[10];
    tape t1[10];
    int ch, b_count=0, t_count=0;
    do{
         cout << "\n* * * * * PUBLICATION DATABASE SYSTEM * * * * *";
         cout << "\n--------------------MENU-----------------------";
         cout << "\n1. Add Information to Books";
         cout << "\n3. Display Books Information";
         cout << "\n2. Add Information to Tapes";
         cout << "\n4. Display Tapes Information";
         cout << "\n5. Exit";
         cout << "\n\nEnter your choice : ";
         cin>>ch;

         switch(ch){
            case 1:
            b1[b_count].add_book();
            b_count++;
            break;
            
            case 2:
            t1[t_count].add_tape();
            t_count++;
            break;

            case 3:
            cout<<endl;
            cout<<"Book Publication"<<endl;
            for(int i=0; i<b_count; i++){
                b1[i].display_book();
                }
                break;
         
            case 4:
            cout<<endl;
            cout<<"Tape Publication"<<endl;
            for(int j=0; j<t_count; j++){
                t1[j].display_tape();
                }
                break;

                case 5:
                exit(0);
         } 
    }while(ch!=5);
    return 0;
}

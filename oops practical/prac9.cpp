#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void countFileContent(const string& filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr<<"error opening the file"<<endl;
        return;
    }

    int LetterCount = 0, wordCount = 0, LineCount = 0;
    string line;

    while(getline(file, line)){
        LineCount++;

        bool inword = false;


        for(char ch:line){
            if(isalpha(ch)){
                LetterCount++;
            }
            if(isspace(ch)){
                if(inword){
                    wordCount++;
                    inword = false;
                }
              
            }
              else {
                    inword = true;
                }
        }
        if(inword){
            wordCount++;
        }
    }
    file.close();

    cout<<"Letters: "<<LetterCount<<endl;
    cout<<"Words: "<<wordCount<<endl;
    cout<<"Lines: "<<LineCount<<endl;
}

void calculatefileSize(const string& filename){
    ifstream file(filename, ios::binary|ios::ate);
    if(!file.is_open()){
        cerr<<"error openiing the file"<<endl;
        return;
    }

    streamsize size = file.tellg();
    file.close();

    cout<<"File size is: "<<size<<" "<<"bytes"<<endl;
}

int main(){
    string filename;
    cout<<"enter the filename: ";
    cin>>filename;
    cout<<endl;

    cout<<"Counting letters, words, and lines: "<<endl;
    countFileContent(filename);

    cout<<endl;

    cout<<"calculating the file size: "<<endl;
    calculatefileSize(filename);

    return 0;
}

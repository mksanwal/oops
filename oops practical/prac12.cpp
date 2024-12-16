#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void encryptfile(const string& inputfilename, const string& outputfilename){
    ifstream inputfile(inputfilename);
    ofstream outputfile(outputfilename);

    if(!inputfile.is_open() || !outputfile.is_open()){
        cerr<<"error opening file"<<endl;
        return;

    }

    char ch;
    while(inputfile.get(ch)){
        outputfile.put(ch+3);
    }

    cout<<"File encrypted successfully and saved to: "<<outputfilename<<endl;
    inputfile.close();
    outputfile.close();

}

void decryptfile(const string& inputfilename, const string& outputfilename){
    ifstream inputFile(inputfilename);
    ofstream outputFile(outputfilename);

    if(!inputFile.is_open() || !outputFile.is_open()){
        cerr<<"error opening file"<<endl;
        return;
    }

    char ch;
    while(inputFile.get(ch)){
        outputFile.put(ch-3);
    }

    cout<<"file decrypted successfully and saved to"<<outputfilename<<endl;
    inputFile.close();
    outputFile.close();
}


int main(){
    int choice;
    string inputFileName, outputFileName;

    do{
        cout << "\nFile Encryption/Decryption Program\n";
        cout << "1. Encrypt a file\n";
        cout << "2. Decrypt a file\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; 

        switch(choice){
            case 1:
                cout << "Enter the name of the file to encrypt: ";
                cin >> inputFileName;
                cout << "Enter the name of the output encrypted file: ";
                cin >> outputFileName;
                encryptfile(inputFileName, outputFileName);
                break;

            case 2:
                cout << "Enter the name of the file to decrypt: ";
                cin >> inputFileName;
                cout << "Enter the name of the output decrypted file: ";
                cin >> outputFileName;
                decryptfile(inputFileName, outputFileName);
                break;

            case 3:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
        }
    

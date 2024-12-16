#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void encryptFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        // Simple encryption: shift each character by 3
        outputFile.put(ch + 3);
    }

    cout << "File encrypted successfully and saved to " << outputFileName << endl;
    inputFile.close();
    outputFile.close();
}

void decryptFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        // Simple decryption: shift each character back by 3
        outputFile.put(ch - 3);
    }

    cout << "File decrypted successfully and saved to " << outputFileName << endl;
    inputFile.close();
    outputFile.close();
}

int main() {
    int choice;
    string inputFileName, outputFileName;

    do {
        cout << "\nFile Encryption/Decryption Program\n";
        cout << "1. Encrypt a file\n";
        cout << "2. Decrypt a file\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the name of the file to encrypt: ";
                cin >> inputFileName;
                cout << "Enter the name of the output encrypted file: ";
                cin >> outputFileName;
                encryptFile(inputFileName, outputFileName);
                break;

            case 2:
                cout << "Enter the name of the file to decrypt: ";
                cin >> inputFileName;
                cout << "Enter the name of the output decrypted file: ";
                cin >> outputFileName;
                decryptFile(inputFileName, outputFileName);
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

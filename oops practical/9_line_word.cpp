#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to count letters, words, and lines in a file
void countFileContent(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return;
    }

    int letterCount = 0, wordCount = 0, lineCount = 0;
    string line;

    while (getline(file, line)) {
        lineCount++;
        bool inWord = false;

        for (char ch : line) {
            if (isalpha(ch)) {
                letterCount++;
            }

            if (isspace(ch)) {
                if (inWord) {
                    wordCount++;
                    inWord = false;
                }
            } else {
                inWord = true;
            }
        }

        if (inWord) {
            wordCount++;
        }
    }

    file.close();

    cout << "Letters: " << letterCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Lines: " << lineCount << endl;
}

// Function to calculate file size
void calculateFileSize(const string& filename) {
    ifstream file(filename, ios::binary | ios::ate);
    if (!file.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return;
    }

    streamsize size = file.tellg();
    file.close();

    cout << "File size: " << size << " bytes" << endl;
}

int main() {
    string filename;

    cout << "Enter the filename: ";
    cin >> filename;

    cout << "\nCounting letters, words, and lines..." << endl;
    countFileContent(filename);

    cout << "\nCalculating file size..." << endl;
    calculateFileSize(filename);

    return 0;
}

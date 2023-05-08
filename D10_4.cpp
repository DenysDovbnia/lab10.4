#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readFilename(string& filename) {
    cout << "Enter filename: ";
    cin >> filename;
}

void readSearchString(string& searchString) {
    cout << "Enter search string: ";
    cin >> searchString;
}

int countLinesWithSearchString(ifstream& file, const string& searchString) {
    int count = 0;
    string line;
    while (getline(file, line)) {
        if (line.find(searchString) != string::npos) {
            count++;
        }
    }
    return count;
}

void copyMatchingLines(ifstream& inFile, ofstream& outFile, const string& searchString) {
    string line;
    while (getline(inFile, line)) {
        if (line.find(searchString) != string::npos) {
            outFile << line << endl;
        }
    }
}

int main() {
    string inFilename, outFilename, searchString;
    ifstream inFile;
    ofstream outFile;

    readFilename(inFilename);
    readSearchString(searchString);

    inFile.open(inFilename);
    if (!inFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    outFilename = "output.txt";
    outFile.open(outFilename);
    if (!outFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    copyMatchingLines(inFile, outFile, searchString);

    int count = countLinesWithSearchString(inFile, searchString);
    outFile << count << endl;

    inFile.close();
    outFile.close();

    return 0;
}

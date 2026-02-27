#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int SHIFT_KEY = 3;
const unsigned char XOR_KEY = 'K';


unsigned char shiftChar(unsigned char c, bool encrypt) {
    if (encrypt)
        return (unsigned char)(c + SHIFT_KEY);
    else
        return (unsigned char)(c - SHIFT_KEY);
}

unsigned char xorChar(unsigned char c) {
    return c ^ XOR_KEY;
}

void processFile(string inputFile, string outputFile, bool encryptMode) {
    ifstream fin;
    ofstream fout;
    unsigned char ch;

    
    fin.open(inputFile.c_str(), ios::binary);
    if (!fin) {
        cout << "\nCould not open source file: " << inputFile << endl;
        return;
    }

    fout.open(outputFile.c_str(), ios::binary);
    if (!fout) {
        cout << "\nCould not create output file: " << outputFile << endl;
        fin.close();
        return;
    }

    while (fin.read(reinterpret_cast<char*>(&ch), 1)) {
        unsigned char processedChar = ch;
        if (encryptMode) {
            processedChar = shiftChar(processedChar, true);
            processedChar = xorChar(processedChar);
        } else {
            processedChar = xorChar(processedChar);
            processedChar = shiftChar(processedChar, false);
        }
        fout.write(reinterpret_cast<char*>(&processedChar), 1);
    }

    fin.close();
    fout.close();
    cout << "\nOperation complete. Check " << outputFile << endl;
}

void showBanner() {
    cout << "CrypText: Multi-Layer Security Utility" << endl;
}


void waitForKey() {
    cout << "\nPress Enter to return...";
    cin.ignore();
    cin.get();
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    int choice;
    string fileIn, fileOut;

    do {
        clearScreen();
        showBanner();
        cout << "\n1. Encrypt a File";
        cout << "\n2. Decrypt a File";
        cout << "\n3. About CrypText";
        cout << "\n4. Exit";
        cout << "\n\nEnter Choice: ";

        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = -1;
        }

        switch (choice) {
        case 1:
            cout << "\n--- ENCRYPTION MODE ---";
            cout << "\nEnter filename to encrypt: ";
            cin >> fileIn;
            cout << "Enter name for encrypted file: ";
            cin >> fileOut;
            processFile(fileIn, fileOut, true);
            waitForKey();
            break;
        case 2:
            cout << "\n--- DECRYPTION MODE ---";
            cout << "\nEnter filename to decrypt: ";
            cin >> fileIn;
            cout << "Enter name for decrypted file: ";
            cin >> fileOut;
            processFile(fileIn, fileOut, false);
            waitForKey();
            break;
        case 3:
            cout << "\n--- ABOUT ---";
            cout << "\nCrypText uses a hybrid algorithm:";
            cout << "\nLayer 1: Caesar Substitution (ASCII Shift)";
            cout << "\nLayer 2: Bitwise XOR Operator";
            cout << "\nDeveloped by Ashfaq Ahmad, Anas Asif and Anas";
            waitForKey();
            break;
        case 4:
            cout << "\nExiting...";
            break;
        default:
            cout << "\nInvalid input.";
            waitForKey();
        }
    } while (choice != 4);

    return 0;
}
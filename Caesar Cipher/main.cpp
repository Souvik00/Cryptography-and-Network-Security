#include <bits/stdc++.h>
using namespace std;

string encryptCaesarCipher(string plaintext, int shift) {
    string cipherText = "";
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char start = isupper(ch) ? 'A' : 'a';
            char cipherChar = ((ch - start + shift) % 26) + start;
            cipherText += cipherChar;
        } else {
            cipherText += ch;
        }
    }
    return cipherText;
}

string decryptCaesarCipher(string cipherText, int shift) {
    return encryptCaesarCipher(cipherText, 26 - shift);
}

int main() {
    // Read message
    ifstream messageFile("message.txt");
    if (!messageFile.is_open()) {
        cerr << "Error: Could not open message file 'message.txt'!" << endl;
        return 1;
    }
    string plaintext;
    getline(messageFile, plaintext);
    messageFile.close();
    if (plaintext.empty()) {
        cerr << "Warning: message.txt is empty!" << endl;
    }

    int shift = 3;
    string ciphertext = encryptCaesarCipher(plaintext, shift);
    ofstream encryptedFile("encrypted.txt");
    if (!encryptedFile.is_open()) {
        cerr << "Error: Could not open output file 'encrypted.txt'!" << endl;
        return 1;
    }
    encryptedFile << ciphertext;
    encryptedFile.close();

    cout << "Plain Text: \"" << plaintext << "\"" << endl;
    cout << "Cipher Text created: \"" << ciphertext << "\"" << endl;

    string decryptedText = decryptCaesarCipher(ciphertext, shift);
    cout << "Decrypted back: \"" << decryptedText << "\"" << endl;

    return 0;
}
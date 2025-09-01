#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> encoder;
unordered_map<string, string> decoder;

void loadDictionary(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open dictionary file '" << filename << "'!" << endl;
        exit(1);
    }

    string key, value;
    int count = 0;
    while (file >> key >> value) {
        if (key.size() != 3 || value.size() != 3) {
            cerr << "Warning: Invalid key-value pair in dictionary: " << key << " -> " << value << endl;
            continue;
        }
        encoder[key] = value;
        decoder[value] = key;
        count++;
    }
    file.close();
    cout << "Dictionary loaded. Number of valid entries: " << count << endl;
}

string encryptPolygram(const string &plaintext, int blockSize = 3) {
    string cipherText = "";
    for (size_t i = 0; i < plaintext.size(); i += blockSize) {
        string block = plaintext.substr(i, blockSize);
        if (block.size() < blockSize) {
            while (block.size() < blockSize) block += 'x';
        }
        if (encoder.count(block)) {
            cipherText += encoder[block];
        } else {
            cipherText += block;
        }
    }
    return cipherText;
}

string decryptPolygram(const string &cipherText, int blockSize = 3) {
    string plainText = "";
    for (size_t i = 0; i < cipherText.size(); i += blockSize) {
        string block = cipherText.substr(i, blockSize);
        if (decoder.count(block)) {
            plainText += decoder[block];
        } else {
            plainText += block;
        }
    }
    return plainText;
}

int main() {

    loadDictionary("dictionary.txt");

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

    ofstream encryptedFile("encrypted.txt");
    if (!encryptedFile.is_open()) {
        cerr << "Error: Could not open output file 'encrypted.txt'!" << endl;
        return 1;
    }
    string ciphertext = encryptPolygram(plaintext, 3);
    encryptedFile << ciphertext;
    encryptedFile.close();

    cout << "Plaintext: \"" << plaintext << "\"" << endl;
    cout << "Ciphertext: \"" << ciphertext << "\"" << endl;

    string decryptedText = decryptPolygram(ciphertext, 3);
    cout << "Decrypted back: \"" << decryptedText << "\"" << endl;

    return 0;
}
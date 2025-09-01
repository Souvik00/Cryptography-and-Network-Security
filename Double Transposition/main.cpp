#include <bits/stdc++.h>
using namespace std;

string encryptMsg(string msg, int width)
{
    int msgLen = msg.size();
    int col = msgLen / width, rem = msgLen % width, x = 0, y = 0;
    string ans = msg;

    for (int i = 0; i < msgLen; i++)
    {
        if (i % width == 0)
            x = y, y++;
        else if (i % width <= rem)
            x += 1;
        ans[x] = msg[i];
        x += col;
    }
    return ans;
}

string decryptMsg(string msg, int width)
{
    int msgLen = msg.size();
    int col = msgLen / width, rem = msgLen % width, x = 0, y = 0;
    string ans = msg;

    for (int i = 0; i < msgLen; i++)
    {
        if (i % width == 0)
            x = y, y++;
        else if (i % width <= rem)
            x += 1;
        ans[i] = msg[x];
        x += col;
    }
    return ans;
}

int main()
{
    string msg, encMsg, decMsg;
    ifstream inFile("message.txt");
    getline(inFile, msg);
    inFile.close(); 

    int width1, width2;
    cout << "Enter the first key (Width): ";
    cin >> width1;
    cout << "Enter the second key (Width): ";
    cin >> width2;

   
    cout << "Input Text: " << msg << endl;

    encMsg = encryptMsg(msg, width1);
    cout << "CipherText(1): " << encMsg << endl;

  
    encMsg = encryptMsg(encMsg, width2);
    cout << "CipherText(2): " << encMsg << endl;


    decMsg = decryptMsg(encMsg, width2);
    decMsg = decryptMsg(decMsg, width1);


    cout << "PlainText: " << decMsg << endl;

    return 0;
}
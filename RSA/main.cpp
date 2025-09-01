#include <bits/stdc++.h>
using namespace std;

// Function to calculate (base^exp) % mod using modular exponentiation
long power(long a, long b,long mod){ // a raised to power b
  long res=1;
  while(b){
    if(b&1) res=(res*a)%mod;
    b>>=1;
    a=(a*a)%mod;
  }
  return res;
}


vector<long long> splitMessageIntoBlocks(string message, int blockSize)
{
    vector<long long> blocks;
    for (int i = 0; i < message.length(); i += blockSize)
    {
        
        string block = message.substr(i, blockSize);
        blocks.push_back(stoll(block)); 
    }
    return blocks;
}

void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout<<endl;
}
int main()
{
    // Given RSA parameters
    long long p = 47;
    long long q = 71;
    long long n = p * q;              
    long long phi = (p - 1) * (q - 1); 
    long long e = 79;                 
    long long d = 1019;               

   
    string message = "6882326879666683";

   
    int blockSize = to_string(n).length() - 1;
    cout << "Block size: " << blockSize << " digits" << endl;

    vector<long long> chunksMessage, chunksCipher;
    vector<int> chunksLength;

    
    for (int i = 0; i < message.size(); i += blockSize)
    {
        string chunk = message.substr(i, blockSize);
        chunksMessage.push_back(stoll(chunk)); 
        chunksLength.push_back(chunk.size()); 
    }

   

    // Encryption: ci = mi^e % n
    cout << "Ciphertext: ";
    for (long long chunk : chunksMessage)
    {
        long long ciphertext = power(chunk, e, n);
        chunksCipher.push_back(ciphertext);
        cout << ciphertext << " ";
    }
    cout << endl;

    // Decryption: mi = ci^d % n
    cout << "Decrypted text: ";
    for (int i = 0; i < chunksCipher.size(); i++)
    {
        long long decrypted_long = power(chunksCipher[i], d, n);
        string decrypted = to_string(decrypted_long);
        decrypted = string(chunksLength[i] - decrypted.size(), '0') + decrypted;
        cout << decrypted << ' ';        
    }
    cout << endl;

    return 0;
}
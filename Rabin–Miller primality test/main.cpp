#include <bits/stdc++.h>
using namespace std;

int power(int a, int b ,int mod){
  int res=1;
  while(b){
    if(b&1) res=(res*a)%mod;
    b>>=1;
    a=(a*a)%mod;
  }
  return res;
}

bool millerTest(long long d, long long n, long long a) {
    long long x = power(a, d, n);

    if (x == 1 || x == n - 1) return true;

    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1) return false;
        if (x == n - 1) return true;
    }

    return false;
}


bool isPrime(long long n, int k = 5) { 
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

  
    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 4);
        if (!millerTest(d, n, a))
            return false;
    }
    return true;
}

int main() {
    srand(time(0));
    vector<long long> testNumbers = {2, 3, 4, 5, 9, 17, 21, 561, 1105};

    for (auto n : testNumbers) {
        cout << n << (isPrime(n) ? " is probably prime" : " is composite") << endl;
    }

    return 0;
}

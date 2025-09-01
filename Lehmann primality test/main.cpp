
#include <bits/stdc++.h>
using namespace std;


int power(int a, int b, int mod){ 
  int res=1;
  while(b){
    if(b&1) res=(res*a)%mod;
    b>>=1;
    a=(a*a)%mod;
  }
  return res;
}

bool lehmannTest(int n, int k) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    int e = (n - 1) / 2;
    srand(time(0));

    for (int i = 0; i < k; i++) {
        int a = 2 + rand() % (n - 3);
        if (__gcd(a, n) != 1) return false; 
        int r = power(a, e, n);

        if (r != 1 && r != n - 1) return false; 
    }
    return true;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (lehmannTest(n, 10))
        cout << n << " is probably prime.\n";
    else
        cout << n << " is composite.\n";

    return 0;
}

#include <iostream>
using namespace std;

long long mod=1000000007;
long long expo(long long base, long long exp) {
    long long ans = 1;
    while(exp !=0 ) {
        if(exp&1 == 1) {
            ans = ans*base ;
            ans = ans%mod;
        }
        base = base*base;
        base %= mod;
        exp>>= 1;
    }
    return ans;
 }



long long CnR(long long n, long long k) {
    if (n<k){
        return 0;
    }
    long long number = 1;
    for (int i=0; i<k; i++) {
        number = (number * (n-i) ) % mod;
    }

    long long d = 1;
    for (int i=1; i<=k; i++) {
        d = (d*i) % mod;
    }
    return (number*expo(d,mod-2))%1000000007;
}
int main(){
    long long a,b,c;
    cin >> a >> b >> c;
    cout<<CnR(a-1,b-1);
   
}


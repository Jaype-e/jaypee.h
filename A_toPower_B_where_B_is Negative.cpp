#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long expo(long long base, long long exp,long long mod) {
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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long t,n,m,j,i,a,b;
    cin>>t;
    // use it as a pre calculation 
    long long phi[1000002];
    for(i=1;i<=1000000;i++) phi[i]=i;
    for(i=2;i<=1000000;i++){
        if(phi[i]==i){
            for(j=i;j<=1000000;j+=i){
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
    
    while(t--){
        cin>>a>>b>>n;
        m=1;
        if(b<0){
        
            m=expo(a,phi[n]-1,n);  // finding moduler inverse 
            m=expo(m,-b,n);
        
        }
        else{
            m=expo(a,b,n);
        }
        cout<<m<<endl;
    }
    return 0;
}


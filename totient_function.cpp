#include <iostream>
#define ll long long
using namespace std;
ll a[1000003];
int main()
{
    ll n,i,j;
    cin>>n;
    for(i=2;i*i<=n;i++){
        if(a[i]==0){
            for(j=i*i;j<=n;j+=i){
                a[j]=1;
            }
        }
    }
    for(i=2;i<=n;i++){
        if(a[i]==0 && n%i==0)
        {
            n=(n/i)*(i-1);
        }
    }
    if(n!=1)
    cout<<n;
    else
    cout<<"0";
    return 0;
}

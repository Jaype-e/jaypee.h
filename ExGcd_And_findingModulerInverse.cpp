#include <bits/stdc++.h>

using namespace std;

void exgcd(long long a,long long b,long long &x,long long &y)
{
    if (b) {	
	   exgcd(b,a%b,y,x);
	   y=y-x*(a/b);	
	}
    else x=1,y=0;
}
long long modulerInverse(long long a,long long mod){
    long long m,y,j=1;
    exgcd(a,mod,m,y);
    j=1;
    while(m<0){
    m+=j*mod;j++;
    }
    return m;
}
int main(){
	long long a,b,x,y;
	cin>>a>>b;
	exgcd(a,b,x,y);
	cout<<x<<" "<<y;
}

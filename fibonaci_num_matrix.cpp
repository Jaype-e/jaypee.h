#include <iostream>
#define ll long long
#define mod 1000000007
using namespace std;
class Mtx{
    public:
    long long a,b,c,d;
    
    Mtx operator*(const Mtx &q){
        Mtx p;
        p.a=((this->a)*(q.a) + (this->b)*(q.c))%mod;
        p.c=((this->c)*(q.a) + (this->d)*(q.c))%mod;
        p.b=((this->a)*(q.b) + (this->b)*(q.d))%mod;
        p.d=((this->c)*(q.b) + (this->d)*(q.d))%mod; 
        return p;
    } 
};
Mtx Mul(Mtx d,ll n){
    if(n==1)
        return d;
    if(n%2==0){
        Mtx s;
        s=Mul(d,n/2);
        return s*s;
    }
    Mtx s;
    s=Mul(d,n/2);
    return s*s*d;
}

ll fib(ll x,ll y,ll n){
	Mtx ss,uu;
    ss.a=1;
    ss.b=1;
    ss.c=1;
    ss.d=0;
    ss=Mul(ss,n);
    uu.a=y;
    uu.b=0;
    uu.c=x;
    uu.d=0;
   Mtx u=(ss*uu);
    return u.c;
    
}
int main(){
	ll t,x,y,n;
    cin>>t;
  while(t--){
      cin>>x>>y>>n;
      cout<<fib(x,y,n)<<endl;
  }
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll p[1000007];
int main()
{
    ll i,j,k,n,m,l,r,t,a[100009],b[100009],c[100009];
    for(i=2;i<=1000000ll;i++){
        if(p[i]==0){
            for(j=i*i;j<=1000000;j+=i)
                p[j]=1;
        }
    }
    double ae;
    cin>>t;
    while(t--){
        cin>>l>>r>>k;
        for(i=0;i<r-l+3;i++)
            a[i]=1;
        for(i=0;i<r-l+1;i++)
            c[i]=b[i]=l+i;
            
        for(i=2;i*i<=r;i++){
            if(p[i]==0){
               
                for(j=((l+i-1)/i)*i;j<=r;j+=i){
                
                    
                    while(b[j-l]%i==0)
                        b[j-l]=b[j-l]/i;
                        
                        c[j-l]=(c[j-l]/i)*(i-1);    
                }
            }    
        }
        m=0;
        for(i=0;i<r-l+1;i++){
           if(b[i]>1){
               c[i]=(c[i]/b[i])*(b[i]-1);
           }
           if(c[i]%k==0)
                m++;
        }
            
        ae=m/((r-l+1.00)*1.0);
        cout<<setprecision(6)<<fixed<<ae<<endl;
        
    }
    
}


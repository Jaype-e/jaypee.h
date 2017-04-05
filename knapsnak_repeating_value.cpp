#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,i,j,k,t,m,w,dp[2005][2005],val[2006],x,y;
    cin>>t;
    while(t--){
        cin>>n>>m;
        w=m;
        for(i=1;i<=n;i++)
            cin>>val[i];
        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if( val[i]<=j){
                    x=j;
                    dp[i][j]=max(val[i]+dp[i-1][j-val[i]],dp[i-1][j]);
                    x=j-val[i];
                    y=2;
                    while(x>=val[i]){  
                        dp[i][j]=max(y*val[i]+dp[i-1][x-val[i]],dp[i][j]);
                        x=x-val[i];y++;
                    }
                }
                else
                    dp[i][j]=dp[i-1][j];
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,i,j,k,t,m,capacity,x,y;
        cout<<" Enter the number of item and capacity "<<endl;
        cin>>n>>capacity;
        int dp[n+2][capacity+2],val[n+2],weight[capacity+2];
        cout<<" Enter the value of items"<<endl;
        for(i=1;i<=n;i++)
            cin>>val[i];
        cout<<" Enter the weight of each items"<<endl;
        for(i=1;i<=n;i++)
            cin>>weight[i];

        for(i=0;i<=n;i++){
            for(j=0;j<=capacity;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if( val[i]<=j ){
                    dp[i][j]=max(weight[i]+dp[i-1][j-val[i]],dp[i-1][j]);
                }
                else
                    dp[i][j]=dp[i-1][j];
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        cout<<" Answer : ";
        cout<<dp[n][capacity]<<endl;
        cout<<"\n"<<" One possible solution's value weight pair"<<endl;
        i=capacity;
        x=n;
        y=capacity;
        while(y>0){
            if(dp[x][y]== ( weight[x]+dp[x-1][y-val[x]] ) ){
                cout<<val[x]<<" "<<weight[x]<<endl;
                y=y-val[x];
                x=x-1;
            }
            else{
                x=x-1;
            }
        }

    return 0;
}

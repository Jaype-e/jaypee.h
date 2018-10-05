#include <bits/stdc++.h>
#include<stack>
#include <string>
using namespace std;
map < pair<int,int> ,int > mp;

string str(int i,int j){
	if( i==j)
		return to_string(i);
	int k=mp[make_pair(i,j)];

	return "("+str(i,k)+") * ("+str(k+1,j)+")"; 
}
int main(){
	int n,i,m,j,l,k,x,arr[100],a,b,c;
	cout<<"Enter the number of matrixs :";
	cin>>n;
	c=-1;
	for(i=1;i<=n;i++){
		cout<<"Matrix "<<(i+1)<<" :";
		cin>>a>>b;
		if(c!=-1){
			if(c!=a){
				cout<<" wrong dimentions error\n";
				return 0;
			}
		}
		arr[i-1]=a;
		arr[i]=b;
	}
	int dp[n+2][n+2];
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			dp[i][j]=10000000;
		}
	}
	for(i=0;i<=n;i++) 
		dp[i][i]=0;
	for(l=2;l<=n;l++){
		for(i=1;i<=n-l+1;i++){
			j=i+l-1;
			for(k=i;k<j;k++){

				if(dp[i][j] > dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j])
				{	dp[i][j]=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
					x=k;
				}	
				//cout<<i<<" "<<k<<" "<<j<<" "<<dp[i][j]<<endl;
			}
			mp[make_pair(i,j)]=x;
			cout<<i<<" "<<x<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<"Ans :";
	cout<<dp[1][n]<<endl;
	cout<<str(1,n);

}

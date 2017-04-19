//strConCom.cpp
#include <bits/stdc++.h>
#define INF 100000000
#define F first
#define S second
using namespace std;

int parent[100];
int disc[100];
int low[100];
bool vis[100];
bool ap[100];
vector <int> adj[100];
stack <int> stk;
void dfs(int vertex,int time){
	int u,child=0;
	vis[vertex]=true;
	stk.push(vertex);
	disc[vertex]=time+1;
	low[vertex]=time+1;
	for(int i=0;i<adj[vertex].size();i++){
		u=adj[vertex][i];
		if(vis[u]==false){
			child++;
			parent[u]=vertex;
			dfs(u,time+1);
			low[vertex]=min(low[vertex],low[u]);
			if(parent[vertex]==-1 && child>1)
				ap[vertex]=true;
			else if(parent[vertex]!=-1 && disc[vertex] <=low[u])
				ap[vertex]=true;

		}
		else if(parent[vertex]!=u ){
			low[vertex]=min(low[vertex],disc[u]);
		}
	}
	if(low[vertex]==disc[vertex]){
		u=stk.top();
		while(u!=vertex){
			cout<<u<<" ";
			stk.pop();
			u=stk.top();
		}
		cout<<u<<endl;
		stk.pop();
	}
}


int main(){
	int n,m,i,a,b,j;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(i=0;i<=n;i++){
		vis[i]=false;
		low[i]=INF;
		ap[i]=false;
	}

	for(i=1;i<=n;i++){
		if(vis[i]==false){
			parent[i]=-1;
			dfs(i,0);
		}
	}
	for(i=1;i<=n;i++){
		cout<<i<<" "<<ap[i]<<endl;
	}

}
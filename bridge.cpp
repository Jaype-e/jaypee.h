#include <bits/stdc++.h>
#define INF 100000000
#define F first
#define S second
using namespace std;

int parent[1000];
int disc[1000];
int low[1000];
bool vis[1000];
vector < pair<int,int> > ap;
vector <int> adj[600000];
void dfs(int vertex,int time){
	int u,child=0;
	vis[vertex]=true;
	disc[vertex]=time+1;
	low[vertex]=time+1;
	for(int i=0;i<adj[vertex].size();i++){
		u=adj[vertex][i];
		if(vis[u]==false){
			child++;
			parent[u]=vertex;
			dfs(u,time+1);
			low[vertex]=min(low[vertex],low[u]);
			if(low[u]>disc[vertex]){
                if(u<vertex)
                ap.push_back(make_pair(u,vertex));
                else
                    ap.push_back(make_pair(vertex,u));
            }    

		}
		else if(parent[vertex]!=u ){
			low[vertex]=min(low[vertex],disc[u]);
		}
	}
}


int main(){
	int n,m,i,a,b,j,t;
    cin>>t;
    for(int y=1;y<=t;y++){
	cin>>n>>m;
    if(n==0 && m==0) break;
        
	for(i=0;i<m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(i=0;i<=n;i++){
		vis[i]=false;
		low[i]=INF;
	
	}

	for(i=1;i<=n;i++){
		if(vis[i]==false){
			parent[i]=-1;
			dfs(i,0);
		}
	}
    sort(ap.begin(),ap.end());
        cout<<"Caso #"<<y<<endl;
    if(ap.size()){    
        cout<<ap.size()<<endl;
	for(i=0;i<ap.size();i++){
	     cout<<ap[i].first<<" "<<ap[i].second<<endl;
	}
    }
    else{
        cout<<"Sin bloqueos"<<endl;
    }    
    
    for(i=1;i<=n;i++)
        adj[i].clear(); ap.clear();
  }

}
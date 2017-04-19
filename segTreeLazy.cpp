    #include<iostream>
    #include<vector>
    using namespace std;
    int lp[1000004],A[1000004],n;
    void leastPrimeFac(){
    	int i,j,k;
    	lp[0]=1;
    	lp[1]=1;
    	for(i=2;i<1000002;i++){
    	  if(lp[i]==0){
    	  	for(j=i;j<1000002;j=j+i){
    	  		if(lp[j]==0)
    	  		lp[j]=i;
    		  }
    	  }
    	}
    }
    int tree[2000003];
    void build(int node, int start, int end)
    {
    	if(start == end)
    	{
    	  tree[node] = lp[A[start]];
    	}
    	else
    	{
    	int mid = (start + end) / 2;
    	build(2*node, start, mid);
        build(2*node+1, mid+1, end);
     
            tree[node] =tree[2*node]>tree[2*node+1]?tree[2*node]:tree[2*node+1];
        }
    }
    void updateRange(int node, int start, int end, int l, int r)
    {
     
       if (start > end or start > r or end < l)
        return;
        if(tree[node]!=1){
       	if (start == end)
    	{		
    	   A[start]=A[start]/lp[A[start]];
    	   tree[node]=lp[A[start]];
    	return;
    	}
        
    	int mid = (start + end) / 2;
    	updateRange(node*2, start, mid, l, r);
    	updateRange(node*2 + 1, mid + 1, end, l, r);
        tree[node] =tree[2*node]>tree[2*node+1]?tree[2*node]:tree[2*node+1];
        
        }    
    }
     
    int query(int node, int start, int end, int l, int r)
    {
    	if(r < start or end < l)
    	{
    	return 1;
    	}
    	if(l <= start and end <= r)
    	{
     
    	return tree[node];
    	}
     
     
    	int mid = (start + end) / 2;
    	int p1 = query(2*node, start, mid, l, r);
    	int p2 = query(2*node+1, mid+1, end, l, r);
    	return p1>p2?p1:p2;
    }
    int main(){ 
      ios_base::sync_with_stdio(false);  
      int i,kk,j,k,t,m,aa,bb,cc,ttt[101][3];  
      leastPrimeFac();
      cin>>t;
      vector <int> ans[t+1];  
      for(int y=0;y<t;y++){
      	cin>>n>>m;
      	for(i=0;i<n;i++)
      	   cin>>A[i];
      	build(1,0,n-1);   
      	for(j=0;j<m;j++){
      	   cin>>aa>>bb>>cc;
    	  if(aa==0)
    	  updateRange(1,0,n-1,bb-1,cc-1);
    	  else{
    	  	ans[y].push_back(query(1,0,n-1,bb-1,cc-1));
    	  }	 	
    	}
          	
      }
      for(int y=0;y<t;y++){
          for(i=0;i<ans[y].size();i++)
              cout<<ans[y][i]<<" ";
          cout<<endl;
      }  
      
    }  

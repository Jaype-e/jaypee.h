#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
 
int N, Q;
 
int answers[100060];
int BLOCK_SIZE;
int arr[100060];
int idx[100060];
int cm[100060];
int idy[100060];
 
 
pair< pair<int, int>, pair<int,int> > queries[100060];
 
 
bool mo_cmp(const pair< pair<int, int>, pair<int,int> > &x, const pair< pair<int, int>, pair<int,int> > &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}
 
int main()
{   int t,i,j,k,p;
   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //cout<<"hjhjh";
 
    cin>>t;
    //cout<<t;
 
    while(t--){
 
      cin>>N>>Q;   
      BLOCK_SIZE = static_cast<int>(sqrt(N)); 
       
      for(int i = 0; i < N; i++){
        cin>>arr[i]; cm[i+1]=0;
      }
      idx[0]=0;
      for(int i=1;i<N;i++){
         if(arr[i-1]==arr[i])
          idx[i]=idx[i-1];
         else
          idx[i]=i;
      }
      idy[N-1]=N-1;
      for(int i=N-2;i>=0;i--){
         if(arr[i+1]==arr[i])
          idy[i]=idy[i+1];
         else
          idy[i]=i;
      }
   
      for(int i = 0; i < Q; i++ ) {
        //cout<<Q<<"d]\n";
        //scanf("%d %d %d",&queries[i].first.first,&queries[i].first.second,&queries[i].second.first);
        
        cin>>queries[i].first.first>>queries[i].first.second>>queries[i].second.first;
        queries[i].second.second = i;
      
      }
 
      sort(queries, queries + Q,mo_cmp);
   
      int mo_left = 0, mo_right = -1;
    
 
 
    for(int i = 0; i < Q; i++) {
       
        int left = queries[i].first.first-1;
        int right = queries[i].first.second-1;
        
        while(mo_right < right) {
            mo_right++;
            p=idx[mo_right]> mo_left ? idx[mo_right]:mo_left;
            cm[mo_right-p+1]++;
           // cout<<" = "<<(mo_right-p+1)<<" "<<cm[mo_right-p+1]<<" ";
        }
        //cout<<endl;
        
        while(mo_right > right) {
            p=idx[mo_right]> mo_left ? idx[mo_right]:mo_left;
            cm[mo_right-p+1]--;
            mo_right--;
        }
 
        while(mo_left < left) {
            p=idy[mo_left]< mo_right ? idy[mo_left]:mo_right;
            cm[p-mo_left+1]--;
            
            //cout<<(p-mo_left+1)<<" "<<cm[p-mo_left+1]<<" ";
            mo_left++;
            
        }
        //cout<<endl;
        while(mo_left > left) {
            mo_left--;
            p=idy[mo_left]< mo_right ? idy[mo_left]:mo_right;
            cm[p-mo_left+1]++;
        }
        //for(int j=1;j<=5;j++) cout<<cm[j]<<" "; cout<<endl;
        answers[queries[i].second.second]=cm[queries[i].second.first];  
        
    }
    
    for(int i = 0; i < Q; i++)
        cout<<answers[i]<<endl;
   
    }    
    return 0;
}
 

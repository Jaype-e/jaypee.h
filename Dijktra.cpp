#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <typeinfo>
#define F first
#define S second
#define vertex second
#define weight first
#define Max 1000000000
using namespace std;

template < class T >
class PriorityQueue{ 
   private: 
      vector< T > elems;     // elements 

   public: 
      void push(T n); 
      T pop(); 
      bool isEmpty();      
}; 

template < class T >
void PriorityQueue< T >::push (T n) { 
   
        elems.push_back(n); 
        int j=elems.size()-1;
        T k;
         while(j>0)
        {
      	    if(elems[(j-1)/2].F>elems[j].F)
			 	  {
			 			k=elems[j];
			 			elems[j]=elems[(j-1)/2];
			 			elems[(j-1)/2]=k;
		     		}
			 		j=(j-1)/2;	
			}  	
	         
} 

template < class T >
bool PriorityQueue< T >::isEmpty () {
     if(elems.size()==0)
     return true;
     return false;
}
	
template < class T >
T PriorityQueue< T >::pop () { 
   
        T temp,res;
        int i,j;
        j=elems.size()-1;
        res=elems[0];
        temp=elems[0];
        elems[0]=elems[j];
        elems[j]=temp;
        i=0;
        while(i<j/2){
            
        	if(2*i+2<j){
        		if(elems[i].F > elems[2*i+1].F && elems[i].F > elems[2*i+2].F ){
                    if( elems[2*i+1].F <= elems[2*i+2].F){
					     temp=elems[i];
        				 elems[i]=elems[2*i+1];
        				 elems[2*i+1]=temp;
        				 i=2*i+1;                  
                    }
                    else{
                    		temp=elems[i];
        						elems[i]=elems[2*i+2];
        						elems[2*i+2]=temp;
        						i=2*i+2;
                    }
        		} 
        		else if(elems[i].F > elems[2*i+2].F ){
        				  temp=elems[i];
        				  elems[i]=elems[2*i+2];
        				  elems[2*i+2]=temp;
        				  i=2*i+2;
        		} 
        		else if(elems[i].F > elems[2*i+1].F ){
        				  temp=elems[i];
        				  elems[i]=elems[2*i+1];
        				  elems[2*i+1]=temp;
        				  i=2*i+1;
        		} 
        		else
        		    break;      
        }
        else if(2*i+1<j){
        	 if(elems[i].F > elems[2*i+1].F ){
        				  temp=elems[i];
        				  elems[i]=elems[2*i+1];
        				  elems[2*i+1]=temp;
        				  i=2*i+1;
        		} 
        		else
        		    break;
        }
        else 
                break;
    }
    elems.pop_back();
    return res ;           	
	         
} 

vector < pair<int,int> > v[3003];
int count[3003]={Max};
void dijktra(int n,int f){
	int i,j,k;
	bool isVisited[n+1]={false};
	PriorityQueue < pair< int,int > > A;
    pair< int,int > temp;	
	
    A.push(make_pair(0,f));
    count[f]=0;
    while( !A.isEmpty()){
        temp=A.pop();
 
        if( count[temp.vertex] < temp.weight) 
            continue;
        
	    for(i=0;i<v[temp.vertex].size();i++){
                    		
            if( count[ v[temp.vertex][i].F ] > count[ temp.vertex ]+v[ temp.vertex ][i].S){
                
        	   		 count[ v[temp.vertex][i].F ]=count[temp.vertex]+v[temp.vertex][i].S;
                
                     A.push( make_pair( count[ v[temp.vertex][i].F ], v[temp.vertex][i].F ) );
            }        
        } 
           	
    }
}


int main() { 
        ios_base::sync_with_stdio(false);
    
		int n,i,j,m,k,a,b,w,f,t;
        cin>>t;
        while(t--){
		cin>>n>>m;
		for(i=0;i<m;i++){
			cin>>a>>b>>w;
			v[a].push_back( make_pair(b,w));	
			//v[b].push_back( make_pair(a,w));	
		}	
		cin>>f;
		for(i=0;i<=n;i++)
			count[i]=Max;
	   dijktra(n,f);
	   for(i=1;i<=n;i++){
           if( i!=f) {
               if(count[i]!=Max)
               cout<<count[i]<<" ";
               else
                   cout<<"-1 ";
           }
       }    
	   	
	   cout<<endl;
         for(i=0;i<=n;i++)
             v[i].clear();
        }     
      
} 

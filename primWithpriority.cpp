#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <typeinfo>
#define F first
#define S second

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

vector < pair<int,int> > v[100];

void prim(int n){
	int i,j,k;
	bool isVisited[n+1]={false};
	PriorityQueue < pair< int,pair< int,int > > > A;
   pair< int,pair < int,int > > temp;	
	
   A.push(make_pair(0,make_pair(1,1)));
   
   while( !A.isEmpty()){
        temp=A.pop();
        
        if( !isVisited[temp.S.S]){
        	   cout<<temp.S.F<<" "<<temp.S.S<<endl; //in minimum spanning tree
        	   
        	   isVisited[temp.S.S]=true;
				for(i=0;i<v[temp.S.S].size();i++){
					
					if( !isVisited[v[temp.S.S][i].F] )
				     A.push( make_pair( v[temp.S.S][i].S, make_pair(temp.S.S,v[temp.S.S][i].F ) ) );
				}        
        } 
           
   }	
	
}



int main() { 
		int n,i,j,m,k,a,b,w;
		cin>>n>>m;
		for(i=0;i<m;i++){
			cin>>a>>b>>w;
			v[a].push_back( make_pair(b,w));	
			v[b].push_back( make_pair(a,w));	
		}	
	   prim(n);
} 

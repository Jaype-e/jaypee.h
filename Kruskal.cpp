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

class set{

public:
	vector<int> parent,size;
	set(int n){
		
		for(int i=0;i<=n;i++)	
		{
		 parent.push_back(i);
		 size.push_back(1);
		}
	}

	int find(int a){
		int i,j;
		i=parent[a];
		while(i!=a){
		a=i;
		i=parent[a];
		}
     		return i;
	}

	void union_(int a,int b){
		int i,j;
		i=find(a);
		j=find(b);
		if( size[i] >size[j]){
			parent[j]=i;
			size[i]+=size[j];
		}
		else{
			parent[i]=j;
			size[j]+=size[i];
		}

	}

};




vector < pair<int ,pair<int,int> > > v;

void kruskul(int n,int m){
	int i,j,k;
	pair<int ,pair<int,int> >  temp;
	PriorityQueue < pair<int ,pair<int,int> > > A;
	for (i=0;i<m;i++) A.push(v[i]);
	
   set s=set(n);
   while(!A.isEmpty()){
		temp=A.pop();
		i=s.find(temp.S.F);
		j=s.find(temp.S.S);
		if(i!=j) 
		{
			cout<<temp.S.F<<" "<<temp.S.S<<endl;
			s.union_(i,j);		
		}
		 
   }	
}



int main() { 
		int n,i,j,m,k,a,b,w;
		cin>>n>>m;
		for(i=0;i<m;i++){
			cin>>a>>b>>w;
			v.push_back(  make_pair( w,make_pair(a,b)) );	
		}	
	   kruskul(n,m);
} 

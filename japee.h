
int bsearch(int arr[],int size,int item){
	int mid,beg,last;
	beg=0;
	last=size-1;
	while(beg<last)
	{	mid=(beg+last)/2;
	if(arr[mid]==item)
	return mid;
	else if(arr[mid]<item)
	beg=mid+1;
	else
	last=mid-1;
	}
	
}
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    string s;
    cin >> s;
    string t;
    cin >> t;
    int k;
    cin >> k;
    int l1,l2,i,j,p,q;
    l1=s.size();
    l2=t.size();
    for(i=0;i<l2;i++){
        if(i<l1){
            if(s[i]!=t[i]){
                p=i;
            }
        }
        else
            p=i;
    }
    if(i==l2){
        q=l1-l2;
    }
    else{
        p--;
        q=l1+l2-p-p;
    }
    if(q==k) {
       cout<<"Yes";
        return 0;
    }
    if(q>k) {
        cout<<"No";
        return 0;
    }
    q=k-q;
    if(q>2*l1){
        cout<<"Yes";
        return 0;
    }
    if(q%2==0){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
    return 0;
}

int sort(int arr[],int size){
	int i,t,y,j,k;

	for(i=0;i<=size-1;i++)
	{	
	int y=arr[i];
	for(j=i;j<=size-1;j++)
	{
	if(arr[j]<=y)
	{y=arr[j];
	k=j;}
	}
	t=arr[k];
	arr[k]=arr[i];
	arr[i]=t;

    }
    
	
}
int sort1(int arr[],int size){
	int i,j,t;

	for(i=0;i<=size-1;i++)
	{	
	for(j=0;j<=size-1;j++)
	{
	if(arr[j]<arr[j+1]){
	t=arr[j];
	arr[j]=arr[j+1];
	arr[j+1]=t;}
    }
    }
    
    	
}
void sort3(int arr[],int size){
	int i,j,k;
	
	for(i=1;i<=size-1;i++){
		{
			for(j=0;j<=i;j++)
			{if(arr[i]<=arr[j])
			   {k=arr[i];
			   arr[i]=arr[j];
			   arr[j]=k;
			   }
			   
			}
		}
		
	}
}
 void quicksort(int x[10],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);
}
}
void jquicksort(int arr[],int beg,int last){
	int t,j,k,pivot;
        t=beg;
	if(beg<last){
        pivot=last;
	for(j=beg;j<=last;j++){
		if(arr[j]<=arr[pivot]){
			k=arr[t];
			arr[t]=arr[j];
			arr[j]=k;
			t++;
			
	       }
	 }
	jquicksort(arr,t,last);
	jquicksort(arr,beg,t-2);

	}
	
}
void insertionsort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
           
       }
       arr[j+1] = key;
   }
}
void merge(int l[],int r[],int arr[],int nl,int nr){
	int i=0,j=0,k=0;
	while(i<nl&&j<nr){
		if(l[i]<=r[j])
		{ arr[k]=l[i];
		k++;
		i++;
	}
	else{
		arr[k]=r[j];
		k++;
		j++;
	}
	}
	while(i<nl){
		arr[k]=l[i];
		i++;
		k++;
	}
		while(j<nr){
		arr[k]=r[j];
		j++;
		k++;
	}
	
}
void mergesort(int arr[],int n){
	int i,nl,nr;
	int l[n],r[n];
	nl=n/2;
	nr=n-n/2;
	for(i=0;i<nl;i++)
	l[i]=arr[i];
	for(i=0;i<nr;i++)
	r[i]=arr[n/2+i];
	if(nl>1)
	mergesort(l,nl);
	if(nr>1)
	mergesort(r,nr);
	merge(l,r,arr,nl,nr);
}
long long fastexp(long long x,long long y){
	if(y==0) return 1;
	if(y==1) return x;
	long long a=fastexp(x,y/2);
	if(y%2==0){
		return a*a;
	}
	else return a*a*x;
}
// if we have to find ax+by=gcd(a,b)   this gives integeral solution(-,+) 
//than we can generalised it (x+nb,y-na) and return gcd of a,b
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
int numDiffpF[1000001];
void numDiffPF(int MaxSize){ // num of diff power fac of a range
	for(int i=1;i<MaxSize;i++) numDiffpF[i]=0;
	for(int i=2;i<MaxSize;i++){
		if(numDiffpF[i]==0){
			for(int j=i;j<MaxSize;j+=i)
			 numDiffpF[j]++;
		}
	}
}

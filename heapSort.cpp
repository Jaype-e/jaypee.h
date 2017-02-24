#include<iostream>
using namespace std;

void buildMaxHeap(int *a,int n){
	  int i,j,k;
      for(i=1;i<n;i++){
      	j=i;
      	while(j>0){
      	     if(a[(j-1)/2]<a[j])
			 {
			 	k=a[j];
			 	a[j]=a[(j-1)/2];
			 	a[(j-1)/2]=k;
		     }
			 j=(j-1)/2;	
		}  	
	  }
	
}

void maxHeapify(int *a,int n,int index){
	int j;
	
	if(2*index+2<n){
		if(a[2*index+1]>a[2*index+2]){
		  if(a[index]<a[2*index+1]){
				j=a[2*index+1];
				a[2*index+1]=a[index];
				a[index]=j;
				maxHeapify(a,n,2*index+1);
	       } 
		}
		else{
			if(a[index]<a[2*index+2]){
				j=a[2*index+2];
				a[index*2+2]=a[index];
				a[index]=j;
				maxHeapify(a,n,2*index+2);
		    }
		}
	}
	else if(2*index+1<n){
		if(a[2*index+1]>a[index]){
			j=a[2*index+1];
			a[2*index+1]=a[index];
			a[index]=j;
			maxHeapify(a,n,2*index+1);
		}
	}
	
}
int main(){
	int i,j,n,arr[100];
	cout<<"Enter the number of element "<<endl;
	cin>>n;
	cout<<"Enter the element \n";
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	
      buildMaxHeap(arr,n);

	
	for(i=n-1;i>=1;i--){
		j=arr[0];
		arr[0]=arr[i];
		arr[i]=j;
		maxHeapify(arr,i,0);
	}
	 
	cout<<"sorted array\n";
	for(i=0;i<n;i++)
	cout<<arr[i]<<" ";
}

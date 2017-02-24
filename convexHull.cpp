#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class Line{
    private:
	   float x1,x2,y1,y2;
	public:
	   Line(int a1,int b1,int a2,int b2){
	   	x1=a1;
	   	y1=b1;
	   	x2=a2;
	   	y2=b2;
	   }
	   
	   float dis(int x,int y){
	   	    float a,b,d=0;
			b=y2-y1;    
	   	    a=x2-x1;
	   	    d=b*x-a*y-b*x1+a*y1;
	   	    d=d;
	   	    if(d<0){
	   	    	return -1.0*d;
			}
	   	    else
	   	        return d;
	   } 
	   
	   float area(int x3,int y3)
	   {
			return x1*(y2-y3)+y2*(x3-x1)+y3*(x1-x2);
	   } 
	   
	   bool IsSameSide(int x,int y,int c,int d){
	   		float a,b;
			b=y2-y1;    
	   	    a=x2-x1;
	   	    if( (b*x-a*y-b*x1+a*y1)*(b*c-a*d-b*x1+a*y1) <0 ) return true;
	   	    else return false;
	   } 	
};

struct Point{
	int x,y;
	
};


void hull(int x1,int y1,int x2,int y2,Point *a,int n,int dir){
	
	if(n<=0) return;
	
	int i,j=-1,k;
	
	float distance=0.0;
	Line l1=Line(x1,y1,x2,y2);
	for(i=0;i<n;i++){
		if(distance<l1.dis(a[i].x,a[i].y) ){
			distance=l1.dis(a[i].x,a[i].y);
			j=i;
		}	
	}
	
	Point s1[n],s2[n];
	
	int a1,b1,n1,n2;
	a1=a[j].x;
	b1=a[j].y;
	
	Line l2=Line(x1,y1,a1,b1);
	n1=0;
	for(i=0;i<n;i++)
    {  
        if(l2.IsSameSide(x2,y2,a[i].x,a[i].y) == true){
        	s1[n1]=a[i];
        	n1++;
		}	
	}
	Line l3=Line(a1,b1,x2,y2);
	n2=0;
	for(i=0;i<n;i++)
    {  
        if(l3.IsSameSide(x1,y1,a[i].x,a[i].y) == true){
        	s2[n2]=a[i];
        	n2++;
		}	
	}	
	if(dir<0){
		hull(a1,b1,x2,y2,s2,n2,-1);
		cout<<a1<<" "<<b1<<endl;
		hull(x1,y1,a1,b1,s1,n1,-1);
	}
	else{
	hull(x1,y1,a1,b1,s1,n1,1);
	cout<<a1<<" "<<b1<<endl;
	hull(a1,b1,x2,y2,s2,n2,1);
	
    }
}


int main(){

        freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int i,j,k,n,x1,x2,y1,y2;
	Point p[100];
	
	cin>>n;
	for(i=0;i<n;i++){
		cin>>p[i].x>>p[i].y;
	}
	j=100000;
	for(i=0;i<n;i++){
		if(j>p[i].x)
		{
			x1=p[i].x;
			y1=p[i].y;
			j=x1;
		}
	}
	
	j=-100000;
	for(i=0;i<n;i++){
		if(j<p[i].x)
		{
			x2=p[i].x;
			y2=p[i].y;
			j=x2;
		}
	}
	
	Point s1[100],s2[100];
	
	Line l1=Line(x1,y1,x2,y2);
	int n1,n2;
	n1=0;
	for(i=0;i<n;i++)
    {  
        if(l1.IsSameSide(x2,y2-1,p[i].x,p[i].y) == true){
        	s1[n1]=p[i];
        	n1++;
		}	
	}
	
	n2=0;
	for(i=0;i<n;i++)
    {  
        if(l1.IsSameSide(x2,y2+1,p[i].x,p[i].y) == true){
        	s2[n2]=p[i];			
        	n2++;
		}	
	}
		
	cout<<x1<<" "<<y1<<endl;
	hull(x1,y1,x2,y2,s1,n1,1);
	cout<<x2<<" "<<y2<<endl;
	hull(x1,y1,x2,y2,s2,n2,-1);

	cout<<x1<<" "<<y1<<endl;
		
}

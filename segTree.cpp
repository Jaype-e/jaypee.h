#include<iostream>
#include<cmath>
#include<string>
using namespace std;
struct a{
	int left;
	int mid;
	int right;
};
a tree[3000020];
string str;
void build(int node,int start,int end){
	if(start==end){
		if(str[start]==')'){
			tree[node].mid=0;
			tree[node].left=1;
			tree[node].right=0;
		}
		if(str[start]=='('){
			tree[node].mid=0;
			tree[node].left=0;
			tree[node].right=1;
		}
		return;
	}
	int mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
    
	tree[node].mid=tree[2*node].mid+2*min(tree[2*node].right,tree[2*node+1].left)+tree[2*node+1].mid;
    
    if(tree[2*node].right<tree[2*node+1].left){
	   tree[node].left=tree[2*node].left+tree[2*node+1].left-tree[2*node].right;
	   tree[node].right=tree[2*node+1].right;
    }
	else if(tree[2*node].right>tree[2*node+1].left){
	   tree[node].right=tree[2*node+1].right+tree[2*node].right-tree[2*node+1].left;
	   tree[node].left=tree[2*node].left;
    }
    else{
        tree[node].right=tree[2*node+1].right;
        tree[node].left=tree[2*node].left;
    }
}
a query(int node,int start,int end,int l,int r){
	a b;
	if((r<start) || (l>end)){
		b.mid=0;
		b.left=0;
		b.right=0;
		return b;
	}
	if((start>=l)&&(end<=r)){
		return tree[node];
	}
	a x1,x2;
	int mid=(start+end)/2;
	x1=query(2*node,start,mid,l,r);
	x2=query(2*node+1,mid+1,end,l,r);
	
    b.mid=x1.mid+x2.mid+2*min(x1.right,x2.left);
    if(x1.right<x2.left){
	   b.left=x1.left+x2.left-x1.right;
	   b.right=x2.right;
    }
	else if(x1.right>x2.left){
	   b.right=x2.right+x1.right-x2.left;
	   b.left=x1.left;
    }
    else{
        b.right=x2.right;
        b.left=x1.left;
    }
	return b;
}
int main(){
	int i,j,l,m,n,len;
	a c;
	cin>>str;
	len=str.length();
	build(1,0,len-1);
	/*for(i=0;i<len*2+2;i++)
	cout<<tree[i].left<<" "<<tree[i].mid<<" "<<tree[i].right<<endl;*/
	cin>>n;
	for(i=0;i<n;i++){
	cin>>l>>m;
	c=query(1,0,len-1,l-1,m-1);
	cout<<c.mid<<endl;	
	}
}

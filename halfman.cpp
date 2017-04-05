#include <bits/stdc++.h>
#include <stdlib.h>
#define F first
#define S second
using namespace std;

struct node{
	char value;
	int data;
	node *left;
	node *right;
};

struct LessThanByFre
{
  bool operator()(const node * lhs, const node* rhs) const
  {
    return lhs->data > rhs->data;
  }
};

node* getnode(char a,int b){
	node * temp=new node();
	temp->data=b;
	temp->value=a;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}


void huffman(node *r,string sr){
	if(r->left==NULL && r->right==NULL){
		cout<<r->value<<" "<<sr<<endl;
		return;
	}
	huffman(r->right,sr+'1');
	huffman(r->left,sr+'0');

}


void decode_huff(node * root,string s)
{
    string ans="";
    node *curr=root;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') curr = curr->left;
        else curr = curr->right;
        if(!curr->left and !curr->right){ //reached leaf node
            ans=ans + curr->value;
            curr=root;
        }
    }
    cout<<ans<<endl;
}
int main(){

	string str;
	int i,j,k,n;
	char aa;
	map < char,int> mp;
	vector < char > v;
	priority_queue < node* ,vector< node* >,LessThanByFre > pq;
	cout<<mp['a'];
	while(1){
		aa=cin.get();
		if(aa=='\n')
			break;
		else if(mp[aa]==0){
			v.push_back(aa);
			mp[aa]=1;
		}
		else
			mp[aa]+=1;
	}
	node * temp1,*temp2,*root;
	for(i=0;i<v.size();i++)
		pq.push(getnode(v[i],mp[v[i]] ));

	while( pq.size()>1 ){
		temp1=pq.top();
		pq.pop();
		temp2=pq.top();
		pq.pop();
		root=getnode('\0',temp1->data+temp2->data);
		root->left=temp1;
		root->right=temp2;
        pq.push(root);
	}
	root=pq.top();
	huffman(root,"");
	cout<<"Enter code for decode\n";
    cin>>str;
    decode_huff(root,str);

}
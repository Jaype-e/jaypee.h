#include<iostream>
#include<stdexcept>
#include<cmath>
using namespace std;

class Matrix{
	
	public:
	
	   int **matrix,n,m;	
		Matrix(int row_=2,int col_=2){
			n=row_;
			m=col_;
			matrix=new int*[n+1];
			for(int i=0;i<n+1;i++){
				matrix[i]=new int[m+1];
			}
		}
		
		/*~Matrix(){
			for(int i=0;i<n;i++){
				delete matrix[i];			
			}
			delete matrix;		
		}*/
			
		void input(){
			cout<<"Enter your matrix :\n";
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++)
				cin>>matrix[i][j];		
			}		
		}
		
		void print(){
			cout<<"Your Matrix :\n";
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++)
				   cout<<matrix[i][j]<<" ";
				cout<<"\n";   		
			}
			cout<<"\n";
		}
		int row(){
		return n;
		}
		
		int col(){
		return m;
		}
		
		 
		
		Matrix operator+(const Matrix &other){
			if( other.n!=this->n || other.m!=this->m )
			{
             throw invalid_argument( "wrong operation :: no match of dimension ");			
			}
			
			Matrix tem(this->n,this->m);
			
			for(int i=0;i<this->n;i++){
				for(int j=0;j<this->m;j++){
				tem.matrix[i][j]=this->matrix[i][j]+other.matrix[i][j];
				}			
			}
			
			return tem;
		}
		
		Matrix operator*(const Matrix &other){
			if(other.n!=this->m )
			{
             throw invalid_argument( "wrong operation :: no match of dimension ");			
			}
			
			Matrix tem(this->n,other.m);
			
			for(int i=0;i<this->n;i++){
				for(int j=0;j<this->m;j++){
					 tem.matrix[i][j]=0;
					 for(int k=0;k<other.n;k++){
					    tem.matrix[i][j]+=this->matrix[i][k]*other.matrix[k][j];
					 }
				
				}			
			}
			
			return tem;
		}
		
		Matrix operator-(const Matrix &other){
			if( other.n!=this->n || other.m!=this->m )
			{
             throw invalid_argument( "wrong operation :: no match of dimension ");			
			}
			
			Matrix tem(this->n,this->m);
			
			for(int i=0;i<this->n;i++){
				for(int j=0;j<this->m;j++){
				tem.matrix[i][j]=this->matrix[i][j]-other.matrix[i][j];
				}			
			}
			
			return tem;
		}
		
};

Matrix Multi(Matrix mat1,Matrix mat2){
	  Matrix ans(mat1.n,mat2.m);
     if(mat1.n==1){
         ans.matrix[0][0]=mat1.matrix[0][0]*mat2.matrix[0][0];
         //cout<<ans.matrix[0][0]<<endl; 
         return ans;    
     }
     int i,j,n,m;
     n=mat1.n;
     m=mat1.m;
     Matrix a11(n/2,m/2),a12(n/2,m/2),a21(n/2,m/2),a22(n/2,m/2),b11(n/2,m/2),b12(n/2,m/2),b21(n/2,m/2),b22(n/2,m/2);     
     
     for( i=0;i<n/2;i++){
			for(j=0;j<m/2;j++){
				a11.matrix[i][j]=mat1.matrix[i][j];
				a12.matrix[i][j]=mat1.matrix[i][j+m/2];
				a21.matrix[i][j]=mat1.matrix[i+n/2][j];	
				a22.matrix[i][j]=mat1.matrix[i+n/2][j+m/2];
				
				b11.matrix[i][j]=mat2.matrix[i][j];
				b12.matrix[i][j]=mat2.matrix[i][j+m/2];
				b21.matrix[i][j]=mat2.matrix[i+n/2][j];
				b22.matrix[i][j]=mat2.matrix[i+n/2][j+m/2];			
			}     
     }  
      
     Matrix p=Multi( (a11+a22),(b11+b22) );    
     Matrix q=Multi( (a21+a22),b11 ); 
     Matrix r=Multi( a11,(b12-b22) );
     Matrix s=Multi( a22,(b21-b11) );
     Matrix t=Multi( (a11+a12),b22 );
     Matrix u=Multi((a21-a11),(b11+b12)) ; 
     Matrix v=Multi((a12-a22),(b21+b22)) ; 
     
     Matrix c11=p+s-t+v;
     Matrix c12=r+t;
     Matrix c21=q+s;
     Matrix c22=p+r-q+u;
     
     for( i=0;i<n/2;i++){
			for(j=0;j<m/2;j++){
				ans.matrix[i][j]=c11.matrix[i][j];
				ans.matrix[i][j+m/2]=c12.matrix[i][j];	
				ans.matrix[i+n/2][j]=c21.matrix[i][j];	
				ans.matrix[i+n/2][j+m/2]=c22.matrix[i][j];		
			}     
     }     
     
     //ans.print();  
    return ans;  
}


int main(){
   int i,m,n,j;
   cout<<"Enter the dimension of matrix :";
   cin>>n;
   m=pow( 2,int( ceil(log2(n)) ) );
   if(m==n){ 
	Matrix a(n,n),b(n,n);
   a.input();
   b.input();	
	Multi(a,b).print();
   }
   else{
   	 Matrix a(m,m),b(m,m);
   	 cout<<"Enter your matrix 1:\n";
       for(i=0;i<m;i++){
          
          for(j=0;j<m;j++){
              if(j<n && i<n)
                cin>>a.matrix[i][j];
              else
                a.matrix[i][j]=0; 
          }       
       }
       cout<<"Enter your matrix 2\n";
       for(i=0;i<m;i++){
          
          for(j=0;j<m;j++){
              if(j<n && i<n)
                cin>>b.matrix[i][j];
              else
                b.matrix[i][j]=0; 
          }       
       }
       
       Matrix c=Multi(a,b);
       cout<<"Your Matrix :\n";
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
				   cout<<c.matrix[i][j]<<" ";
				cout<<"\n";   		
			}
			cout<<"\n";
       
   }

}

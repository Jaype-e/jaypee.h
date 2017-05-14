    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;
    ll g, x, y;
    void extendedEuclid(ll A,ll B) {
        if(B == 0) {
            g = A;
            x = 1;
            y = 0;
        }
        else {
            extendedEuclid(B, A%B);
            ll temp = x;
            x = y;
            y = temp - (A/B)*y;
        }
    }
    int main()
    {   //number of nonnegative solution of ax+by=d
        int q;
        cin>>q;
        while(q--)
        {
            ll a,b,d,e=0;
            cin>>a>>b>>d;
            extendedEuclid(a,b);
    		if(d%g !=0){
    		    cout<<"0\n";
    		    continue;
    		}
    		//cout<<x<<" "<<y<<endl;
            ll k1=ceil(-x*(d*1.0)/b);
            ll k2=floor(y*(d*1.0)/a);
    		if(k1<=k2)
    			cout<<k2-k1+1<<"\n";
    		else
    			cout<<"0\n";
        }
        return 0;
    }




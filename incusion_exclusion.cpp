    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;
    ll arr[100];
    ll gcd(ll a, ll b){ return b==0 ? a : gcd(b,a%b); }
    ll lcm(ll a, ll b){ return a*(b/gcd(a,b)); }
     
    ll intersectionCardinality(vector<ll> indices){
        ll i,j;
        j=1;
        for(i=0;i<indices.size();i++)
            j=lcm(j,arr[indices[i]]);
        return j;
    }
    
    ll res(ll n,ll K){
        ll result;
        result=0;
            for(ll b = 0; b < (1 << n); ++b)
            {
                 vector<ll> indices;
                 for(ll k = 0; k < n; ++k)
                 {
                      if(b & (1 << k))
                      {
                           indices.push_back(k);
                      }
                 }
                 ll cardinality = intersectionCardinality(indices);
                 //cout<<cardinality<<endl;
                 if(indices.size()==0) continue;
                 
                 if(indices.size() % 2 == 1)
                    result += (K/cardinality);
                 else 
                    result -= (K/cardinality);
            }
            return result;
    }
     
    int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
        ll n,i,t,K1,K2; // the number of sets in the set A
        ll result = 0;
        cin>>n>>t;
        for(i=0;i<n;i++)
            cin>>arr[i];
        while(t--){
            
            cin>>K1>>K2;
            cout<<(res(n,K2)-res(n,K1))<<endl;
            
            
        }
        
        
        return 0;
    }

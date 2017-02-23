#include <bits/stdc++.h>

using namespace std;

long long ans = 0;
const int maxn = 1e6 + 6;
long long primes[maxn];
long long d[1000];
int size_d = 0;
long long dd[1000][2];
int cur_d = 0;
long long tmpans = 0;
long long bound = 0;

void rec(int pos, long long mask, int sign)
{
    if (pos == cur_d) {
        tmpans += sign * (bound / mask);
        return;
    }
    int tmp = 1;
    int si = 1;
    for (int i = 0; i <= 1; i++) {
        rec(pos + 1, mask * tmp, sign * si);
        si = -si;
        tmp = tmp * dd[pos][0];
    }
}

long long solve(int p, int r)
{
    if (p == 1)
        return r;
    bound = r;
    int size_d = 0;
    while (primes[p] != 1)
    {
        d[size_d++] = primes[p];
        p /= primes[p];
    }
    sort(d, d + size_d);
    dd[0][0] = d[0];
    dd[0][1] = 1;
    cur_d = 1;
    for (int i = 1; i < size_d; i++)
    {
        if (d[i] == d[i - 1])
        {
            dd[cur_d - 1][1]++;
        } else
        {
            dd[cur_d][0] = d[i];
            dd[cur_d][1] = 1;
            cur_d++;
        }
    }
    tmpans = 0;
    rec(0, 1, 1);
    return tmpans;
}

int main()
{     
    int n = 0;
    cin >> n;
    int m = sqrt(n);
    for (int i = 1; i <= m; i++)
    {   
        primes[i] = i;
    }
    for (int i = 2; i * i <=m; i++)
    {
        if (primes[i] == i)
        {
            for (int j = i * i; j <= m; j += i)
                primes[j] = i;
        }
    }
    /* if you want to find co prime number of x in given range 1 to N then call solve(x,N) 
	   above m is must be greater then x
	*/
    
    
    ans = 0;
    for (int i = 2; i * i < n; i++) {
        int r = n / i;
        ans += solve(i, r) - solve(i, i);
    }
    cout << ans << endl;
    return 0;
}

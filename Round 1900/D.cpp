#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef LOKAL
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
const int N = 1e5 + 5;
typedef pair<int,int> pii;


vector<int>divisors[N+1];

void Divisors()
{
    int n= N;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}

vector<int>all[N];
int cur[N];

ll cal(vector<int>&a, int n)
{
    ll ans = 0;
    for(int i=0;i<a.size();i++)
    {
        // fixing j
        ans += i *1ll* (n-a[i]-1);
    }
    return ans;
}

void TEST_CASES()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<N;i++)
    {
        all[i].clear();
        cur[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j:divisors[a[i]])
        {
            all[j].push_back(i);
        }
    }
    ll ans = 0;
    for(int i=1;i<N;i++)
    {
        int need = i;
        for(int j:divisors[i])
        {
            if(j==i)
                continue;
            need -= cur[j];
        }
        ans += need * cal(all[i],n);
        cur[i] = need;
    }
    cout<<ans<<"\n";
}

int32_t main()
{
#ifndef LOKAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    Divisors();
    int t;
    cin>>t;
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}

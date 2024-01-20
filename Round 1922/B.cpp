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
typedef pair<int,int> pii;

ll nc2(ll n)
{
    return (n*(n-1))/2;
}

ll nc3(ll n)
{
    return (n*(n-1)*(n-2))/6;
}

void TEST_CASES()
{
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>freq;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        freq[a[i]]++;
    }
    ll ans = 0;
    ll small = 0;
    for(auto [val, cnt]: freq)
    {
        ans += nc3(cnt);
        ans += nc2(cnt) * small;
        small += cnt;
    }
    cout<<ans<<"\n";
}

int32_t main()
{
#ifndef LOKAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t=1;
    cin>>t;
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}

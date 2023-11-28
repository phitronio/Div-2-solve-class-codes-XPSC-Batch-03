#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef APURBA
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
typedef pair<int,int> pii;

void TEST_CASES()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<ll>pMax(n);
    vector<ll>sMax(n);
    for(int i=0;i<n;i++)
    {
        pMax[i] = a[i] + (n-i-1);
    }
    for(int i=1;i<n;i++)
    {
        pMax[i] = max(pMax[i], pMax[i-1]);
    }
    for(int i=n-1;i>=0;i--)
    {
        sMax[i] = a[i] + i;
    }
    for(int i=n-2;i>=0;i--)
    {
        sMax[i] = max(sMax[i] , sMax[i+1]);
    }
    ll ans = 1e18;
    for(int i=0;i<n;i++)
    {
        ll x = a[i];
        if(i-1>=0)
            x = max(x, pMax[i-1]);
        if(i+1<n)
            x = max(x, sMax[i+1]);
        ans = min(ans, x);
    }
    cout<<ans<<"\n";
}

int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t=1;
//    cin>>t;
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}

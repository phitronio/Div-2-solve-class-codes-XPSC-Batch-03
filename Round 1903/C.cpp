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

void TEST_CASES()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<ll>suff(n+1);
    for(int i=n-1;i>=0;i--)
    {
        suff[i] = suff[i+1] + a[i];
    }
    vector<ll>dp(n);
    ll maxDp = 0;
    for(int i=n-1;i>=0;i--)
    {
        dp[i] = suff[i] + maxDp;
        maxDp = max(maxDp, dp[i]);
    }
    cout<<dp[0]<<"\n";
}

int32_t main()
{
#ifndef LOKAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}

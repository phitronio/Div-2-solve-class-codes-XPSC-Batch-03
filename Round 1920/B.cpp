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
const int N = 2e5 +5;
typedef pair<int,int> pii;

int p[N];

int getSum(int l, int r)
{
    if(l>r)
        return 0;
    return p[r] - (l-1>=0?p[l-1] : 0);
}

void TEST_CASES()
{
    int n,k,x;
    cin>>n>>k>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.rbegin(),a.rend());
    p[0] = a[0];
    for(int i=1;i<n;i++)
    {
        p[i] = p[i-1] + a[i];
    }
    int ans = -2e9;
    for(int i=0;i<=k;i++)
    {
        int mnL = i;
        int mnR = min(i + x - 1, n-1);
        int tmp = -getSum(mnL,mnR) + getSum(mnR+1, n-1);
        ans = max(ans , tmp);
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

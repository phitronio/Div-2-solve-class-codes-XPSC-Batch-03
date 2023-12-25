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
    ll k;
    cin>>n>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(a[0]==a.back())
    {
        cout<<"0\n";
        return;
    }
    ll g = 0;
    int positiveCount = 0;
    int negativeCount = 0;
    for(int i=0;i<n;i++)
    {
        a[i] -= k;
        if(a[i] > 0)
            positiveCount++;
        else if(a[i] < 0)
            negativeCount++;
        g = __gcd(g, abs(a[i]));
    }
    if(positiveCount!=n && negativeCount!=n)
    {
        cout<<"-1\n";
        return;
    }
    if(negativeCount==n)
        g = -g;

    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += (a[i] / g - 1);
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

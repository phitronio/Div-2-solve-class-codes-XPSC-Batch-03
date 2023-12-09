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
    vector<ll>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<"1\n";
        return;
    }
    sort(a.begin(),a.end());
    ll g = 0;
    for(int i=0;i<n;i++)
    {
        g = __gcd(a[n-1]-a[i],g);
    }
    ll op = 0;
    for(int i=0;i<n;i++)
    {
        op += (a[n-1] - a[i]) / g;
    }
    ll baki = n;
    for(ll i=a[n-1];;i-=g)
    {
        if(binary_search(a.begin(),a.end(),i))
            continue;
        baki = min(baki,(a[n-1]- i)/g);
        break;
    }
    op += baki;
    cout<<op<<"\n";
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

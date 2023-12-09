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

ll n,p,l,t;

bool check(ll x)
{
    ll baki = p - x*l;
    ll task = min((n+6)/7,2*x);
    baki -= task * t;
    return baki <= 0;
}

void TEST_CASES()
{
    cin>>n>>p>>l>>t;
    ll low = 1, high = n;
    ll ans = 0;
    while(low<=high)
    {
        ll mid = (low + high)/2;
        if(check(mid))
        {
            ans = n-mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
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

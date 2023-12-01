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

ll solve(vector<ll>a, ll k)
{
    int n = a.size();
    ll ans = 0;
    for(int bit=60; bit>=0; bit--)
    {
        ll need = 0;
        for(int i=0; i<n; i++)
        {
            if(!(a[i]&(1ll<<bit)))
                need += (1ll << bit) - (a[i] % (1ll << bit));
            if(need > k)
                break;
        }
        if(need <= k)
        {
            k -= need;
            ans += (1ll << bit);
            for(int i=0; i<n; i++)
            {
                if(!(a[i]&(1ll<<bit)))
                {
                    a[i] = a[i] - (a[i] % (1ll << bit));
                    a[i] |= (1ll << bit);
                }
            }
        }
    }
    return ans;
}

void TEST_CASES()
{
    int n,q;
    cin>>n>>q;
    vector<ll>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    while(q--)
    {
        ll k;
        cin>>k;
        ll ans = solve(a, k);
        cout<<ans<<"\n";
    }
}

int32_t main()
{
#ifndef LOKAL
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

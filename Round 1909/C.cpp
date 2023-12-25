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
    vector<int>l(n);
    vector<int>r(n);
    vector<int>c(n);

    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>r[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    sort(c.rbegin(),c.rend()); //decreasing order

    vector<int>intervals;
    set<int>st(l.begin(),l.end());

    for(int i=0;i<r.size();i++)
    {
        auto it = st.lower_bound(r[i]);
        it--;
        intervals.push_back(r[i] - (*it));
        st.erase(it);
    }
    sort(intervals.begin(),intervals.end());
    ll ans =0;
    for(int i=0;i<intervals.size();i++)
    {
        ans += intervals[i] *1ll* c[i];
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

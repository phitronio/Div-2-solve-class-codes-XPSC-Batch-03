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


int fun(int a, int b, int c)
{
    return b%2 == c%2;
}

void TEST_CASES()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<fun(a,b,c)<<" "<<fun(b,a,c)<<" "<<fun(c,a,b)<<"\n";
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

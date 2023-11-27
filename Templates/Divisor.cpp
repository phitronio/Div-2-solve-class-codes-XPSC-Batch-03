// O(sqrt(n))
vector<int> getDivisors(int n)
{
    vector<int>d;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            d.push_back(i);
            if(i!=n/i)
                d.push_back(n/i);
        }
    }
    return d;
}

// To get all divisors from 1 to N

int N = 1e5 + 5;
vector<int>divisors[N+1];

void Divisors()
{
    int n = N;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}

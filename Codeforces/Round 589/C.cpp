    
#include <bits/stdc++.h>
#define pb      push_back
#define fastIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define PI      3.141592653589793238462643383
#define mp      make_pair
#define ff      first
#define ss      second
#define endl    "\n"
#define all(v)  v.begin(),v.end()
#define int     long long

using namespace std;
typedef pair<int,int> pii;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T> >;

vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
        s << arr[n - 1] << "]";
    return s.str();
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << endl;
}
    template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int mod=1e9+7;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

set<int> primes;
void primeFactors(int n)  
{  
    while (n % 2 == 0)  
    {  
        primes.insert(2) ;
        n = n/2;  
    }  
  

    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  

        while (n % i == 0)  
        {  
            primes.insert(i);
            n = n/i;  
        }  
    }  

    if (n > 2)  
        primes.insert(n); 
}  

int x,n;

int32_t main()
{


    fastIO;

    cin>>x>>n;
    primeFactors(x);

    int ans=1;
    for(int p:primes)
    {
        double lgp=(log2(n)/log2(p));
        int count=0,y=p;
        for(int i=1;i<=lgp;i++)
        {
            count+=n/y;
            y*=p;
        }
        ans=(ans*binpow(p,count,mod))%mod;
    }
    cout<<ans;
    return 0;
}

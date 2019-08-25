/**
 *    author: Gaurav Tiwari, Delhi Technological University
**/        
#include <bits/stdc++.h>
#define pb      push_back
#define fastIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define PI      3.141592653589793238462643383
#define mp      make_pair
#define ff      first
#define ss      second
#define endl       "\n"
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
int oo = 0x3f3f3f3f;
const int N=3e5+5,MOD=998244353;
pii arr[300005];
int fact[N];
map<int,int> m1,m2;
map<pii,int> m3;
int n;
 
void precompute()
{
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
}
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
 
    fastIO;
    precompute();
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].ff>>arr[i].ss;
        m1[arr[i].ff]++;
        m2[arr[i].ss]++;
        m3[arr[i]]++;
    }
    int ans=fact[n];
    int ffsorted=1;
    for(auto &p:m1)
    {
        ffsorted=(ffsorted*fact[p.ss])%MOD;
    }
    int sssorted=1;
    for(auto &p:m2)
    {
        sssorted=(sssorted*fact[p.ss])%MOD;
    }
    sort(arr,arr+n);
    int flag=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i].ff<arr[i-1].ff || arr[i].ss<arr[i-1].ss)
        {
            flag=0;
        }
    }
    if(flag)
    {
        int both=1;
        for(auto &p:m3)
        {
            both=(both*fact[p.ss])%MOD;
        }
        ans=(ans+both)%MOD;
    }
    ans=(ans-ffsorted+MOD)%MOD;
    ans=(ans-sssorted+MOD)%MOD;
    cout<<ans;
    
    return 0;
}
    
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
const int oo = 0x3f3f3f3f,N=3e5+5;

int n,len[N],cost[N],cache[N][4];

int dp(int curr, int prev)
{
    if(curr==n)
    {
        return 0;
    }
    if(cache[curr][prev]!=-1)
        return cache[curr][prev];
    cache[curr][prev]=2e18;
    for(int i=0;i<=3;i++)
    {
        if(len[curr-1]+prev!=len[curr]+i)
        {
            cache[curr][prev]=min(cache[curr][prev],cost[curr]*i+dp(curr+1,i));
        }
    }
    return cache[curr][prev];
}


int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif

    fastIO;
    int testcases;cin>>testcases;
    for(int test=1;test<=testcases;test++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>len[i]>>cost[i];
        }
        for(int i=0;i<=n;i++)
        {
            cache[i][0]=cache[i][1]=cache[i][2]=cache[i][3]=-1;
        }
        cout<<min({dp(1,0),cost[0]+dp(1,1),cost[0]*2+dp(1,2),cost[0]*3+dp(1,3)});
        cout<<endl;
    }
    
    return 0;
}

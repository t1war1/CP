/**
 *    author: Gaurav Tiwari, Delhi Technological University
**/        
#include <bits/stdc++.h>
#define mod 1000000007ll
#define mod2 100000009ll
#define mod3 998244353
#define pb push_back
#define fastIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define readi(x) scanf("%d",&x)
#define reads(x)  scanf("%s", x)
#define readl(x) scanf("%I64d",&x)
#define PI 3.141592653589793238462643383
#define mp make_pair
#define sorti(a,b) sort(a,b)
#define sortd(a,b,tp) sort(a,b,greater<tp>())
#define ff first
#define ss second
#define endl "\n"
#define int long long

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

int n,k,arr[300005],cache[300005][3];

int dp(int i, int state)
{
    if(i==n)
    {
        return 0;
    }
    int &ans=cache[i][state];
    if(ans!=-1)
        return ans;
    ans=0; 
    if(state==0)
    {
        ans=max(ans,arr[i]+dp(i+1,0));
        ans=max(ans,arr[i]*k+dp(i+1,1));
    }
    else if(state==1)
    {
        ans=max(ans,arr[i]*k+dp(i+1,1));
        ans=max(ans,arr[i]+dp(i+1,2));
    }
    else
    {
        ans=max(ans,arr[i]+dp(i+1,2));
    }
    return ans;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif

    fastIO;
    memset(cache,-1,sizeof(cache));
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dp(i,0));
    }
    cout<<ans;
    
    return 0;
}

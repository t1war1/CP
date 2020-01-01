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
        if(n > 0)
            s << arr[n - 1] ;
        s<< "]";
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
const int N=5002;
int n,m,k,a[N],b[N],c[N], last[N], cache[N][N];
vector<int>  graph[N];
 
int dp(int i, int have)
{   
    if(have < a[i])
        return -1e9;
    if(i > n)
        return 0;
    int &ans = cache[i][have];
    if(ans != -1)
        return ans;
    ans = dp(i + 1, have + b[i]);
    int x = have + b[i];
    int sum = 0;
    for(int j = 0; j < graph[i].size(); j++)
    {
        sum += graph[i][j];
        if(x >= j + 1)
            ans = max(ans, sum + dp(i + 1, x - (j + 1)));
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
 
    memset(cache, -1, sizeof(cache));
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        last[i] = i;
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        last[v] = max(last[v], u);
    }
    for(int i = 1; i <= n; i++)
        graph[last[i]].push_back(c[i]);
    for(int i = 1; i <= n; i++)
        sort(graph[i].rbegin(), graph[i].rend());
    int ans = dp(1, k);
    if(ans < 0)
        ans = -1;
    cout << ans;
    
    return 0;
}
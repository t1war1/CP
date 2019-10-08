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
const int N=1010,W=1010;
int cache[N][W],weights[N],beauty[N],visited[N];
vector<int> groups[N];
vector<int> graph[N];
int n,m,w,g;

void dfs(int curr)
{
    visited[curr]=1;
    groups[g].pb(curr);
    for(int &j:graph[curr])
    {
        if(!visited[j])
        {
            dfs(j);
        }
    }
}

int dp(int curr, int wleft)
{
    if(wleft<0)
    {
        return -1*1e15;
    }
    if(curr==g)
    {
        return 0;
    }

    int &ans=cache[curr][wleft];
    if(ans!=-1)
    {
        return ans; 
    }
    ans=dp(curr+1,wleft);
    int sumw=0,sumb=0;
    for(int i=0;i<groups[curr].size();i++)
    {
        sumw+=weights[groups[curr][i]];
        sumb+=beauty[groups[curr][i]];
    }
    ans=max(ans,dp(curr+1,wleft-sumw)+sumb);

    for(int i=0;i<groups[curr].size();i++)
    {
        ans=max(ans,dp(curr+1,wleft-weights[groups[curr][i]])+beauty[groups[curr][i]]);
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

    cin>>n>>m>>w;
    for(int i=1;i<=n;i++)
    {
        cin>>weights[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>beauty[i];
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            g++;
        }
    }
    
    memset(cache,-1,sizeof(cache));
    cout<<dp(0,w);

    return 0;
}
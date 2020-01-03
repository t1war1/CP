    
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
const int N=2e5+10;
int n,arr[N], ans[N];
vector<int> graph[N];
vector<int> odd,even;

void bfs(int parity)
{
    queue<int> q;
    vector<int> dist(n,-1), visited(n,0);
    vector<int> sources=odd;
    if(parity==0)
    {
        sources=even;
    }
    for(int &x:sources)
    {
        q.push(x);
        visited[x]=1;
        dist[x]=0;
    }
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int &x:graph[curr])
        {
            if(visited[x]==0)
            {
                visited[x]=1;
                q.push(x);
                dist[x]=dist[curr]+1;
            }
        }
    }
    vector<int> destinations=even;
    if(parity==0)
    {
        destinations=odd;
    }
    for(int &x:destinations)
    {
        ans[x]=dist[x];
    }
    trace(parity);
    trace(arrStr(dist,n));
    trace(arrStr(ans,n));
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif

    fastIO;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x&1)odd.pb(i);
        else even.pb(i);

        if(i-x>=0)
        {
            graph[i-x].pb(i);
        }
        if(i+x<n)
        {
            graph[i+x].pb(i);
        }
    }
    bfs(1);
    bfs(0);
    
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

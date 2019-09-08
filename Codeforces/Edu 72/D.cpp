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
const int oo = 0x3f3f3f3f;
int n,m;
vector<int> graph[5003];
vector<pii> edges;
bool visited[5003],recstack[5003];
map<pii,int> coloring;
bool dfs1(int curr)
{
    if(recstack[curr])
    {
        return 1;
    }
    if(visited[curr])
    {
        return 0;
    }
    visited[curr]=1;
    recstack[curr]=1;
    for(int i=0;i<graph[curr].size();i++)
    {
        if(dfs1(graph[curr][i]))
        {
            return 1;
        }
    }
    recstack[curr]=0;
    return 0;
}

void dfs2(int curr, int color)
{
    visited[curr]=1;
    for(int i=0;i<graph[curr].size();i++)
    {
        coloring[{curr,graph[curr][i]}]=color;
        if(!visited[graph[curr][i]])
        {
            if(color==1)
            {
                dfs2(graph[curr][i],2);
            }
            else
                dfs2(graph[curr][i],1);
            
        }
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

    cin>>n>>m;
    for(int i=0;i<m;i++) 
    {
        int x,y;
        cin>>x>>y;
        edges.pb({x,y});
        graph[x].pb(y);
    }
    bool cycle=0;
    for(int i=1;i<=n;i++)
    {
        if(dfs1(i))
        {
            cycle=1;
            break;
        }
    }
    if(cycle)
    {
        cout<<2<<endl;
        for(int i=0;i<edges.size();i++)
        {
            cout<<1+(edges[i].ff>edges[i].ss)<<" ";
        }
    }
    else
    {
        cout<<1<<endl;
        for(int i=0;i<m;i++)
        {
            cout<<1<<" ";
        }
    }
    
    return 0;
}

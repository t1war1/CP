    
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
const int N=1e5+10;

bool visited[N];
vector<int> graph[N];
int color[N];
string str;
int n;


bool dfs(int curr, int col)
{
    // trace(curr,col);
    if(visited[curr])
    {
        if(color[curr]!=col)
        {
            return 0;
        }
        return 1;
    }

    visited[curr]=1;
    color[curr]=col;
    // trace(graph[curr].size());
    for(int &ne:graph[curr])
    {
        if(!dfs(ne,col^1))
        {
            return 0;
        }
    }
    return 1;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif

    fastIO;

    cin>>n>>str;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(str[i]>str[j])
            {
                graph[i].pb(j);
                graph[j].pb(i);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(!dfs(i,0))
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)
    {
        cout<<color[i];
    }
    
    return 0;
}

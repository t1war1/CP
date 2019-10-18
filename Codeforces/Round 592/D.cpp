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
vector<int> graph[N];
int n,arr[N][4];
int forwd[3]={1,2,3};
int ans1[3]={0,0,0};
int ans2[3]={0,0,0};
// vector<int> ans1v[3],ans2v[3];
int backward[3]={1,2,3};
int color[N];
void dfs(int curr, int par)
{
    // ans1[0]=arr[curr][forwd[0]];
    for(int i=0;i<3;i++)
    {
        // trace(ans1[i],arr[curr][forwd[i]]);
        ans1[i]+=arr[curr][forwd[i]];
        // forwd[i]=(forwd[i]+1)%3;
        forwd[i]++;
        if(forwd[i]==4)
        {
            forwd[i]=1;
        }
        // ans1v[i].pb(curr);
        // trace(i,curr,ans1[i],forwd[i]);
    }
    for(int i=0;i<3;i++)
    {
        ans2[i]+=arr[curr][backward[i]];
        backward[i]--;
        if(backward[i]==0)
        {
            backward[i]=3;
        }
 
        // trace(i,curr,ans2[i],backward[i]);
    }
    for(int &j:graph[curr])
    {
        if(j!=par)
        {
            dfs(j,curr);
        }
    }
}
 
void dfs2(int curr, int par, int which, int ind)
{
    if(which==1)
    {
        color[curr]=forwd[ind];
        forwd[ind]++;
        // trace(curr,forwd[ind]);
        if(forwd[ind]==4)
        {
            forwd[ind]=1;
        }
 
    }
    else
    {
        color[curr]=backward[ind];
                backward[ind]--;
        if(backward[ind]==0)
        {
            backward[ind]=3;
        }
        // trace(curr,backward[ind]);
        
 
    }
    for(int &j:graph[curr])
    {
        if(j!=par)
        {
            dfs2(j,curr,which,ind);
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
 
    cin>>n;
    for(int j=1;j<=3;j++)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i][j];
        }
        
    }
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    int start=-1;
    for(int i=1;i<=n;i++)
    {
        if(graph[i].size()>2)
        {
            cout<<-1;
            return 0;
        }
        if(graph[i].size()==1)
        {
            start=i;
        }
    }
    
    dfs(start,0);
 
    int ans=1e18,which=1,ind=-1;
    for(int i=0;i<3;i++)
    {
        if(ans1[i]<ans)
        {
            ans=ans1[i];
            which=1;
            ind =i;
        }
        if(ans2[i]<ans)
        {
            ans=ans2[i];
            which=2;
            ind =i;
        }
    }
    cout<<ans<<endl;
    forwd[0]=1;
    forwd[1]=2;
    forwd[2]=3;
    backward[0]=1;
    backward[1]=2;
    backward[2]=3;
    dfs2(start,0,which,ind);
    
    for(int i=1;i<=n;i++)
    {
        cout<<color[i]<<" ";
    }
    return 0;
}
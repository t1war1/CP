    
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

struct DSU
{
    int connected;
    int par[N], sz[N];

    DSU() {} 

    void init(int n) 
    {
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            sz[i]=1;
        }
        connected=n;
    }

    int getPar(int k)
    {
        while(k!=par[k])
        {
            par[k]=par[par[k]];
            k=par[k];
        }
        return k;
    }

    int getSize(int k)
    {
        return sz[getPar(k)];
    }

    void unite(int u, int v)
    {
        int par1=getPar(u), par2=getPar(v);

        if(par1==par2)
            return;

        connected--;

        if(sz[par1]>sz[par2])
            swap(par1, par2);

        sz[par2]+=sz[par1];
        sz[par1]=0;
        par[par1]=par[par2];
    }
};
DSU dsu;

int sieve[N],nxt[N];
vector<pii> v[N];
int n;

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("debug.txt", "w", stderr);
    // #endif

    fastIO;
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<N;i++)
        {
            v[i].clear();
        }
        memset(sieve,0,sizeof(sieve));
        memset(nxt,0,sizeof(nxt));
        cin>>n;
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            maxx=max(maxx,x);
            sieve[x]=1;
        }
        // trace("hi");
        for(int i=maxx;i>0;i--)
        {
            if(sieve[i])
            {
                nxt[i]=i;
            }
            else
            {
                nxt[i]=nxt[i+1];
            }
        }

        for(int i=1;i<maxx;i++)
        {
            if(sieve[i])
            {
                for(int j=i;j<=maxx;j++)
                {
                    int x;
                    if(i==j)
                    {
                        x=nxt[j+1];
                    }
                    else
                    {
                        x=nxt[j];
                    }
                    if(x%i>=0)
                    {
                        v[x%i].pb({x,i});
                    }
                }
            }
        }
        dsu.init(maxx);
        int ans=0;
        for(int i=0;i<=maxx;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                if(dsu.getPar(v[i][j].ff)!=dsu.getPar(v[i][j].ss))
                {
                    dsu.unite(v[i][j].ff,v[i][j].ss);
                    ans+=i;
                }
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}

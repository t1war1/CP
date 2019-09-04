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
const int N=100000+10, MOD=1e9+7;
bool ans;
int n,q;
struct DSU
{
    int connected;
    int par[N], sz[N], parity[N];

    DSU() {} 

    void init(int n) 
    {
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            sz[i]=1;
            parity[i]=0;
        }
        connected=n;
    }

    int getPar(int k)
    {
        if(par[k]!=k)
        {
            int t = par[k];
            par[k] = getPar(par[k]);
            parity[k] ^= parity[t];
        }
        return par[k];
    }

    int getSize(int k)
    {
        return sz[getPar(k)];
    }

    void unite(int u, int v, int x)
    {
        int par1=getPar(u), par2=getPar(v);

        if(par1==par2)
        {
            if(parity[par1]^parity[par2]^x)
            {
                ans=0;
            }
            return;
        }

        connected--;

        if(sz[par1]>sz[par2])
            swap(par1, par2);

        sz[par2]+=sz[par1];
        sz[par1]=0;
        par[par1]=par[par2];
        parity[par2]=parity[u]^parity[v]^x;
    }
};
DSU dsu;


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
        cin>>n>>q;
        ans=1;
        dsu.init(n);
        for(int i=0;i<n-1;i++) 
        {
            int x,y;
            cin>>x>>y;
        }
        while(q--)
        {
            int u,v,x;
            cin>>u>>v>>x;
            dsu.unite(u,v,x);
        }
        if(!ans)
        {
            cout<<0;
        }
        else
        {
            int p=0;
            for(int i=1;i<=n;i++)
            {
                if(dsu.par[i]==i)
                    p++;
            }
            int ans=1;
            for(int i=1;i<p;i++)
            {
                ans=(ans*2)%MOD;
            }
            cout<<ans;
        }

        cout<<endl;
    }
    
    return 0;
}

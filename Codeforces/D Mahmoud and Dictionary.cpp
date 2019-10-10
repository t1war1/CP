    
#include <bits/stdc++.h>
#define pb      push_back
#define fastIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define PI      3.141592653589793238462643383
#define mp      make_pair
#define ff      first
#define ss      second
#define endl    "\n"
#define all(v)  v.begin(),v.end()
// #define int     long long

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

    pii getPar(int k)
    {
        if(k==par[k])
        {
            parity[k]=0;
            return {k,0};

        }
        pii tmp=getPar(par[k]);
        par[k]=tmp.ff;
        parity[k]=tmp.ss^parity[k];
        return {par[k],parity[k]};
    }

    int getSize(int k)
    {
        return sz[getPar(k).ff];
    }

    bool unite(int u, int v, int z)
    {
        int par1=getPar(u).ff, par2=getPar(v).ff;
        // trace(par1,par2,z,u,v);
        if(par1==par2)
        {
            // trace(parity[u],parity[v]);
            if(parity[u]^parity[v]^z)
            {
                return 0;
            }
            return 1;
        }

        connected--;

        if(sz[par1]>sz[par2])
            swap(par1, par2);

        sz[par2]+=sz[par1];
        sz[par1]=0;
        par[par1]=par[par2];
        parity[par1]=parity[u]^parity[v]^z;
        // cerr<<arrStr(parity,4)<<endl;
        return 1;
    }
};
DSU dsu;
int n,m,q;
string words[N];
map<string,int> enumeration;

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("debug.txt", "w", stderr);
    // #endif

    fastIO;
    cin>>n>>m>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>words[i];
        enumeration[words[i]]=i;
    }
    dsu.init(n);

    for(int i=0;i<m;i++)
    {
        int z;
        string str1,str2;
        cin>>z>>str1>>str2;
        z--;
        int x=enumeration[str1],y=enumeration[str2];
        // trace(i,x,y);
        if(dsu.unite(x,y,z))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

    }
    for(int i=0;i<q;i++)
    {
        string str1,str2;
        cin>>str1>>str2;
        int x=enumeration[str1];
        int y=enumeration[str2];
        int p1=(dsu.getPar(x)).ff,p2=(dsu.getPar(y)).ff;
        if(p1!=p2)
        {
            cout<<3<<endl;
        }
        else
        {
            if(dsu.parity[x]==dsu.parity[y])
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<2<<endl;
            }
        }
    }

    
    return 0;
}

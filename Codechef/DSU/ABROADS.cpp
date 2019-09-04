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
const int N=500010;
int n,m,q,currPop[N],popBefore[N],x[N],y[N],ans[N],A[N],B[N];
multiset<int> s;
bool del[N];
string type[N];

struct DSU
{
    int connected;
    int par[N], sz[N], total[N];

    DSU() {
        
    } 

    void init(int n) 
    {
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            sz[i]=1;
            total[i]=currPop[i];
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
        s.erase(s.find(total[par1]));
        s.erase(s.find(total[par2]));
        total[par2]+=total[par1];
        s.insert(total[par2]);
    }
};

DSU dsu;

int mostPopulation()
{
    auto it=s.end();
    --it;
    return *it;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif

    fastIO;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>currPop[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>type[i];
        if(type[i]=="D")
        {
            cin>>A[i];
            del[A[i]]=1;
        }
        else
        {
            cin>>A[i]>>B[i];
            popBefore[i]=currPop[A[i]];
            currPop[A[i]]=B[i];
        }
    }

    dsu.init(n);

    for(int i=1;i<=n;i++)
    {
        s.insert(currPop[i]);
    }

    for(int i=1;i<=m;i++)
    {
        if(!del[i])
        {
            dsu.unite(x[i],y[i]);
        }
    }
    ans[q]=mostPopulation();
    for(int i=q;i>=1;i--)
    {
        if(type[i]=="D")
        {
            dsu.unite(x[A[i]],y[A[i]]);
        }
        else
        {
            int rep=dsu.getPar(A[i]);
            s.erase(s.find(dsu.total[rep]));
            dsu.total[rep]-=currPop[A[i]];
            currPop[A[i]]=popBefore[i];
            dsu.total[rep]+=currPop[A[i]];
            s.insert(dsu.total[rep]);
        }
        ans[i-1]=mostPopulation();
    }
    for(int i=1;i<=q;i++)
    {
        cout<<ans[i]<<endl;
    }
    
    return 0;
}

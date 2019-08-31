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
 
int n,k;
int arr1[2002][2002],arr2[2002][2002],grid[2002][2002];
int ro[2002],c[2002];
char x;
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
 
    fastIO;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int f=1;
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            if(x!='W')
            {
                grid[i][j]=1;
            }
        }
    }
 
    //handling rows
    for(int i=1;i<=n;i++)
    {
        int l=0,r=0;
        for(int j=1;j<=n;j++)
        {
            if(grid[i][j])
            {
                if(!l)
                {
                    l=j;
                }
                r=j;
            }
        }
        if(!l)
        {
            ro[i]=1;
        }
        else
        {
            if(r-l<k)
            {
                arr1[i][max(1ll,min(r-k+1,l))]=1;
                arr1[i][l+1]=-1;
            }
        }
    }
 
    //handling cols
    for(int j=1;j<=n;j++)
    {
        int u=0,d=0;
        for(int i=1;i<=n;i++)
        {
            if(grid[i][j])
            {
                if(!u)
                {
                    u=i;
                }
                d=i;
            }
        }
        if(!u)
        {
            c[j]=1;
        }
        else
        {
            if(d-u<k)
            {
                arr2[max(1ll,min(u,d-k+1))][j]=1;
                arr2[u+1][j]=-1;
            }
        }
    }
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            arr1[i][j]=arr1[i][j-1]+arr1[i][j];
        }
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            arr2[i][j]=arr2[i-1][j]+arr2[i][j];
        }
    }
 
 
 
    for(int i=1;i<=n;i++)
    {
        ro[i]=ro[i-1]+ro[i];
        c[i]=c[i-1]+c[i];
    }
 
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            arr1[i][j]=arr1[i-1][j]+arr1[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            arr2[i][j]=arr2[i][j-1]+arr2[i][j];
        }
    }
 
    int ans=0;
    int ans1=ro[n]+c[n];
 
    for(int i=1;i<=n-k+1;i++)
    {
        for(int j=1;j<=n-k+1;j++)
        {
            int tmp=arr1[i+k-1][j]-arr1[i-1][j] +arr2[i][j+k-1]-arr2[i][j-1];
            ans=max(ans, tmp);
        }
    }
    trace(ans);
    cout<<ans+ans1;
    return 0;
}

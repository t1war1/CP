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
const int mod=1000000007;
int n,m;
int arr1[1001][1001],arr2[1001][1001];
int r[1001],c[1001];
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
 
    fastIO;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>c[i];
    }
 
    for(int i=0;i<n;i++)
    {
        int x=r[i];
        for(int j=0;j<x;j++)
        {
            arr1[i][j]=-1;
        }
    }
    for(int i=0;i<m;i++)
    {
        int x=c[i];
        for(int j=0;j<x;j++)
        {
            arr1[j][i]=-1;
        }
    }
    int f=0;
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<m;j++)
        {
            if(arr1[i][j]!=-1)
            {
                break;
            }
            count++;
        }
        if(count!=r[i])
        {
            f=1;
            break;
        }
    }
    for(int j=0;j<m;j++)
    {
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(arr1[i][j]!=-1)
            {
                break;
            }
            count++;
        }
        if(count!=c[j])
        {
            f=1;
            break;
        }
    }
    if(f)
    {
        cout<<0;
        return 0;
    }
 
    int ans=1;
    for(int i=0;i<n;i++)
    {
        int j=0;
        for(;j<m;j++)
        {
            if(arr1[i][j]!=-1)
                break;
        }
        j++;
        for(;j<m;j++)
        {
            if(arr1[i][j]!=-1)
            {
                arr2[i][j]++;
            }
        }
    }
    for(int j=0;j<m;j++)
    {
        int i=0;
        for(;i<n;i++)
        {
            if(arr1[i][j]!=-1)
            {
                break;
            }
        }
        i++;
        for(;i<n;i++)
        {
            if(arr1[i][j]!=-1)
            {
                arr2[i][j]++;
            }
        }
    }
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr2[i][j]==2)
            {
                ans=(ans*2)%mod;
            }
        }
    }
    cout<<ans;
    return 0;
}

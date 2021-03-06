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
const int N=7005;
vector<pii> arr;
int n;
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
 
    fastIO;
    cin>>n;
 
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.pb({x,-1});
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].ss;
    }
    sort(all(arr));
    bool check[n];
    for(int i=0;i<n;i++) check[i]=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i].ff==arr[i-1].ff)
        {
            check[i]=1;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(!check[i])
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                if(check[j] && (arr[i].ff|arr[j].ff)==arr[j].ff)
                {
                    check[i]=1;
                    break;
                }
            }
        }
    }
 
    int maxx=0;
    for(int i=0;i<n;i++)
    {
        maxx=(check[i])?i:maxx;
    }
    if(maxx==0) {
        cout<<0;return 0;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(check[i])
        {
            ans+=arr[i].ss;
        }
    }
    cout<<ans;
    return 0;
}
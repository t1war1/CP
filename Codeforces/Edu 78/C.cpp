    
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
//const int N=;
void solve()
{
    int n;
    cin>>n;
    vector<int>a(2*n), pref(2*n+1,0);
    map<int,int>rm;
    for(int i=0;i<2*n;i++)
    {
        cin>>a[i];
        if( a[i] == 2 )
            a[i] = -1;
        pref[i+1] = pref[i] + a[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        if( rm.find(pref[i+1]) == rm.end() )
            rm[pref[i+1]] = i;
    }
    if( rm.find(0) == rm.end() )
        rm[0] = -1;
 
    int sum = 0;
    int ans = 2*n;
    if( rm.find(sum) != rm.end() )
        ans = min(ans, 2*n - 1 - rm[sum] );
    for(int i=2*n-1;i>=n;i--)
    {
        sum += a[i];
        int xx = -sum;
        if( rm.find(xx) != rm.end() )
        {
            ans = min(ans, i - rm[xx] - 1 );
        }
    }
    cout<<ans;
}

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
        solve();
        cout<<endl;
    }
    
    return 0;
}

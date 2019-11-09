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
const int N = 200005;
int cache[N], b[N], n, m;
pii a[N];
 
int dp(int i)
{
     if (i == n)
          return 0;
 
     int &ans = cache[i];
     if (ans != -1)
          return ans;
     ans = 1e18;
 
     int x = min(a[i].ff, a[i + 1].ff);
     int y = max(a[i].ff, a[i + 1].ff);
 
     for (int j = i + 2; j < min(n, i + 10); j++)
     {
          x = min(x, a[j].ff);
          y = max(y, a[j].ff);
          ans = min(ans, y - x + dp(j + 1));
     }
     return ans;
}
 
void path(int i)
{
     if (i == n)
          return ;
 
     int ans = dp(i);
     int x = min(a[i].ff, a[i + 1].ff);
     int y = max(a[i].ff, a[i + 1].ff);
 
     for (int j = i + 2; j < min(n, i + 10); j++)
     {
          x = min(x, a[j].ff);
          y = max(y, a[j].ff);
          if (ans == y - x + dp(j + 1))
          {
               m++;
               for (int k = i; k <= j; k++)
                    b[a[k].ss] = m;
               return path(j + 1);
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
 
     cin >> n;
     for (int i = 0; i < n; i++)
          cin >> a[i].ff, a[i].ss = i;
 
     sort(a, a + n);
     memset(cache, -1, sizeof(cache));
     dp(0);
     path(0);
     cout << dp(0) << " " << m << endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
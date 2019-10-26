    
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


int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif

    fastIO;

    int n,k,ans=0;
    cin>>n>>k;

    vector<int> arr(n);
    for(int &i:arr)
    {
        cin>>i;
    }
    map<vector<pii>,int> m;

    for(int &e:arr)
    {
        vector<pii> v1;
        for(int j=2; j*j<=e; j++) {
            int p=0;
            while(e%j==0) {
                ++p;
                e/=j;
            }
            if(p%k) {
                v1.pb(mp(j, p%k));
            }
        }
        if(e>1)
        {
            v1.pb(mp(e,1));
        }
        vector<pii> v2;
        for(pii &p:v1)
        {
            v2.pb(mp(p.ff,k-p.ss));
        }
        if(m.find(v2)!=m.end())
        {
            ans+=m[v2];
        }
        m[v1]++;
    }
    cout<<ans;
    
    return 0;
}

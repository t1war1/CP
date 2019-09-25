 
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
const int oo = 0x3f3f3f3f;
 
int a,x2,x3,x4,x5,x6,b,y2,y3,y4,y5,y6;
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr); 
    #endif
 
    fastIO;
    cin>>a>>b>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;
 
    int x11=max(a,x3);
    int y11=max(b,y3);
    int x12=min(x2,x4);
    int y12=min(y2,y4);
 
    int x21=max(a,x5);
    int y21=max(b,y5);
    int x22=min(x2,x6);
    int y22=min(y2,y6);
 
    int x31=max(x11,x21);;
    int y31=max(y11,y21);
    int x32=min(x12,x22);
    int y32=min(y12,y22);
 
    int area=max(x12-x11,0ll)*max(y12-y11,0ll)+max(x22-x21,0ll)*max(y22-y21,0ll)-max((x32-x31),0ll)*max((y32-y31),0ll);
    if(area<(x2-a)*(y2-b))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
    
    return 0;
}
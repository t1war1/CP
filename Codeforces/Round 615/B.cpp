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
//const int N=;
 
 
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
        int n;
        cin>>n;
        map<int,set<int>> m;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            m[x].insert(y);
        }
        int x=0,y=0;
        string str="";
        bool f=0;
        // trace(test);
        for(auto &p:m)
        {
            trace(x,y);
            int xt=p.ff-x;
            for(int i=0;i<xt;i++)
            {
                str+='R';
            }
            x=p.ff;
            if(*p.ss.begin()<y)
            {
                f=1;
                break;
            }
 
            for(int cx:p.ss)
            {
                for(int i=0;i<(cx-y);i++)
                {
                    str+='U';
                }
                y=cx;
            }
            // trace(x,y);
        }
        if(f)
        {
            cout<<"NO";
        }
        else
        {
            cout<<"YES\n";
            cout<<str;
        }
 
        cout<<endl;
    }
    
    return 0;
}
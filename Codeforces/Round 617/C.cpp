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
        int l=-1,r=-1,n;
        cin>>n;
        int ans=2e5+10;
        l=-1,r=-1;
        string str;
        cin>>str;
 
        map<pii,int> m;
        int x=0,y=0;
        m[{0,0}]=0;
        for(int i=1;i<=n;i++)
        {
            if(str[i-1]=='U')
            {
                y++;
            }
            if(str[i-1]=='D')
            {
                y--;
            }
            if(str[i-1]=='L')
            {
                x--;
            }
            if(str[i-1]=='R')
            {
                x++;
            }
            if(m.find({x,y})!=m.end())
            {
                int ppt=m[{x,y}];
                if(i-ppt<ans)
                {
                    ans=i-ppt;
                    l=ppt+1;
                    r=i;;
                }
            }
            m[{x,y}]=i;
        }
        if(l==-1)
        {
            cout<<l;
        }
        else
            cout<<l<<" "<<r;
        cout<<endl;
    }
    
    return 0;
}
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
 
int onepos[200005];
 
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
        int n,a,b;
        cin>>n>>a>>b;
        string str;
        cin>>str;
        int ones=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='1')
            {
                onepos[ones++]=i;
            }
        }
        int cost=0;
        for(int i=0;i<ones;i++)
        {
            int diff=onepos[i+1]-onepos[i]-1;
            cost+=a+2*b;
            if(i==0)    
            {
                cost+=2*b;
            }
            if(diff==0 || i==ones-1)
            {
                continue;
            }
            cost+=2*b;
            if(diff==1)
            {
                cost+=a;
            }
            else
            {
                int c1=(diff-1)*b+4*a+(diff-2)*a;
                int c2=diff*a+(diff-1)*2*b;
                cost+=min(c1,c2);
            }
        }
        int before,after;
        if(ones==0)
        {
            before=n;
            cost+=before*a+(before+1)*b;
        }
        else
        {
            before=onepos[0];
            after=n-onepos[ones-1]-1;
            cost+=2*a+b+(before-1)*a+(before-1)*b;
            cost+=2*a+b+(after-1)*a+(after-1)*b;
        }
        cout<<cost<<endl;
    }
    
    return 0;
}
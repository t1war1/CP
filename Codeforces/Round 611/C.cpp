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
 
    int n;
    cin>>n;
    int give[n+1], take[n+1];
    for(int i=1;i<=n;i++)
    {
        take[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>give[i];
        if(give[i]!=0)
            take[give[i]]=1;
    }
    vector<int> common;
    for(int i=1;i<=n;i++)
    {
        if(give[i]==0 && take[i]==0)
        {
 
            common.push_back(i);
        }
    }
    if(common.size()>1 )
    {
        for(int i=0;i<common.size()-1;i++)
        {
            give[common[i]]=common[i+1];
            take[common[i+1]]=1;
        }
        give[common[common.size()-1]]=common[0];
        take[common[0]]=1;  
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(take[i]==0)
        {
            q.push(i);
        }
    }
    if(common.size()==1)
    {
        if(q.front()!=common[0])
        {
            give[common[0]]=q.front();
            q.pop();
        }
        else
        {
            int x=q.front();
            q.pop();
            q.push(x);
            give[common[0]]=q.front();
            q.pop();
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(give[i]==0)
        {
            int f=q.front();
 
            q.pop();
            if(f==i)
            { 
                q.push(f);
                i--;
            }
            else
            {
                give[i]=f;
                take[f]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<give[i]<<" ";
    }
    
    return 0;
}
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
const int N=300;
int arr[N];
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
 
    fastIO;
 
    int n,k;
    cin>>n>>k;
    vector<pii> segs(n);
 
    for(int i=0;i<n;i++)
    {
        cin>>segs[i].ff>>segs[i].ss;
        arr[segs[i].ff]++;
        arr[segs[i].ss+1]--;
        
    }
 
    for(int i=1;i<N;i++)
    {
        arr[i]=arr[i]+arr[i-1];
    }
 
    vector<int> ans(n,0);
    
    for(int i=0;i<N;i++)
    {
        while(arr[i]>k)
        {
            int pos=-1;
            for(int j=0;j<segs.size();j++)
            {
                if(!ans[j] && segs[j].ff<=i && segs[j].ss>=i && (pos==-1 || segs[j].ss>segs[pos].ss))
                {
                    pos=j;
                }
            }
            for(int j=segs[pos].ff;j<=segs[pos].ss;j++)
            {
                arr[j]--;
            }
            ans[pos]=1;
        }
    }
 
 
    int sum=0;
    for(int i=0;i<ans.size();i++)
    {
        sum+=ans[i];
    }
    cout<<sum<<endl;
    for(int i=0;i<n;i++)
    {
        if(ans[i])
        {
            cout<<i+1<<" ";
        }
    }
 
 
 
    
    return 0;
}

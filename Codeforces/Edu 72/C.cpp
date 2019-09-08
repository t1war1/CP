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
        string str;
        cin>>str;
        int n=str.size();
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=str[i]-'0';
        }
        // trace(arrStr(arr,n));
        int ans=0;
        vector<int> lt[n];
        for(int i=0;i<n;i++)
        {
            if(arr[i])
            {
                int curr=0,j=i;
                while(curr<=n && j<n)
                {
                    curr=curr*2+arr[j];
                    lt[i].pb(curr);
                    if(curr==j-i+1 )
                    {
                        ans++;
                        // trace(i,j);
                    }
                    j++;
                }
            }
        }
        int next[n];
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]==1 || i==n-1)
            {
                next[i]=i;
            }
            else
                next[i]=next[i+1];
        }
        for(int i=0;i<n;i++)
        {
            if(!arr[i])
            {
                // trace(i);
                if(!lt[next[i]].empty())
                {
                    for(int j=0;j<lt[next[i]].size();j++)
                    {
                        if(lt[next[i]][j]==next[i]+j-i+1)
                            ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
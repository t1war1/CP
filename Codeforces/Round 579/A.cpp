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
 
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
 
    fastIO;
    clock_t clk = clock();
 
    int testcases;cin>>testcases;
 
    for(int test=1;test<=testcases;test++)
    {
        trace(test);
        int n;
        cin>>n;
        vector<int> arr(2*n);
        int ind;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            arr[i+n]=arr[i];
            if(arr[i]==1)
            {
                ind=i;
            }
        }
        int flag=0;
        if(n==1)
        {
            flag=1;
        }
        trace(arrStr(arr,arr.size()));
        for(int i=ind+1;i<2*n;i++)
        {
            trace(i);
            if(arr[i]==(arr[i-1]+1))
            {
                if(arr[i]==n)
                {
                    flag=1;
                    break;
                }
            }
            else
            {
 
                break;
            }
        }
        for(int i=ind+n-1;i>=0;i--)
        {
            if(arr[i]==arr[i+1]+1)
            {
                if(arr[i]==n)
                {
                    flag=1;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if(flag)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
        cout<<endl;
    }
    
    clk = clock() - clk;
    cerr << "Time Elapsed: " << fixed << setprecision(10) << ((long double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}
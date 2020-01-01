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
vector<int> arr,ans;
 
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
    string str;
    cin>>str;
    cerr<<str<<endl;
    
    bool allSame=1;
    for(int i=1;i<n;i++)
    {
        if(str[i]!=str[0])
        {
            allSame=0;
        }
    }
    if(allSame)
    {
        cout<<0;
        return 0;
    }
    int countA=0,countB=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='W')
        {
            countA++;
        }
        else
            countB++;
    }
    // trace(countA,countB);
    if(countA&1 && countB&1)
    {
        cout<<-1;
        return 0;
    }
    char chosen='X';
    if(countA%2==0)
    {
        chosen='W';
    }
    if(countB%2==0)
    {
        if(chosen=='X') 
            chosen='B';
        else
        {
            if(countB<countA)
            {
                chosen='B';
            }
        }
    }
    // trace(chosen);
 
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==chosen)
        {
            arr.pb(i+1);
        }
    }
    trace(arrStr(arr,arr.size()));
    for(int i=0;i<arr.size();i+=2)
    {
        for(int j=arr[i];j<arr[i+1];j++)
        {
            ans.pb(j);
        }
    }
    assert(ans.size()<=3*n);
    cout<<ans.size()<<endl;
    for(int x:ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    
    return 0;
}

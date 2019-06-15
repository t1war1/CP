/**
 *    author: Gaurav Tiwari, Delhi Technological University
**/        
#include <bits/stdc++.h>
#define mod 1000000007ll
#define mod2 100000009ll
#define mod3 998244353
#define pb push_back
#define fastIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define readi(x) scanf("%d",&x)
#define reads(x)  scanf("%s", x)
#define readl(x) scanf("%I64d",&x)
#define PI 3.141592653589793238462643383
#define mp make_pair
#define sorti(a,b) sort(a,b)
#define sortd(a,b,tp) sort(a,b,greater<tp>())
#define ff first
#define ss second
#define endl "\n"
#define int long long

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

int fact(int n)
{
    int ans=1;
    for(int i=1;i<=n;i++)
        ans*=i;
    return ans;
}

int sgn(int x)
{
    if(x<=0)return 0;
    return x;
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif

    fastIO;

    string str1,str2;
    cin>>str1>>str2;
    int p1=0,s1=0,p2=0,q2=0,s2=0;
    for(int i=0;i<str1.length();i++)
    {

        if(str1[i]=='+')
            p1++;
        if(str1[i]=='-')
            s1++;
    }
    
    for(int i=0;i<str2.length();i++)
    {
        if(str2[i]=='+')
            p2++;
        if(str2[i]=='-')
            s2++;
        if(str2[i]=='?')
            q2++;
    }

    if(abs(p1-p2)>q2 || abs(s1-s2)>q2)
    {
        printf("%.12f",0);
        return 0;
    }
    double ans=0,den=pow(2,q2),pr=sgn(p1-p2),nr=sgn(s1-s2);
    double num=fact(pr+nr)/(fact(pr)*fact(nr));
    printf("%.12f",num/den);
    return 0;
}

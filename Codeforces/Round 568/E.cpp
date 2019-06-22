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

int n,m;
char a[2005][2005],b[2005][2005];
map<char,int > lx,rx,ly,ry;

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
        lx.clear();ly.clear();rx.clear();ry.clear();
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                b[i][j] = '.';
                cin >> a[i][j];
                if(a[i][j] == '.')
                    continue;
                if(lx.find(a[i][j]) == lx.end())
                    lx[a[i][j]] = i;
                else
                    lx[a[i][j]] = min(lx[a[i][j]], i);
                if(rx.find(a[i][j]) == rx.end())
                    rx[a[i][j]] = i;
                else
                    rx[a[i][j]] = max(rx[a[i][j]], i);
                if(ly.find(a[i][j]) == ly.end())
                    ly[a[i][j]] = j;
                else
                    ly[a[i][j]] = min(ly[a[i][j]], j);
                if(ry.find(a[i][j]) == ry.end())
                    ry[a[i][j]] = j;
                else
                    ry[a[i][j]] = max(ry[a[i][j]], j);
            }
        }
        if(!lx.size())
        {
            cout<<"YES"<<endl;
            cout<<0<<endl;
            continue;
        }
        bool check=1;
        for(char ch='a';ch<='z';ch++)
        {
            if(lx.find(ch) == lx.end())
                continue;
            if(lx[ch] != rx[ch] && ly[ch] != ry[ch])
            {
                check = 0;
                break;
            }
            for(int i = lx[ch]; i <= rx[ch]; i++)
                for(int j = ly[ch]; j <= ry[ch]; j++)
                    b[i][j] = ch;
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                check &= (a[i][j] == b[i][j]);

        if(!check)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            char last = lx.rbegin() -> first;
            int num = last - 'a' + 1;
            cout << num << endl;
            for(char ch = 'a'; ch <= last; ch++)
            {
                if(lx.find(ch) != lx.end())
                    cout << lx[ch] << " " << ly[ch] << " " << rx[ch] << " " << ry[ch] << endl;
                else
                {
                    char temp = ch;
                    ch = last;
                    cout << lx[ch] << " " << ly[ch] << " " << lx[ch] << " " << ly[ch] << endl;
                    ch = temp;
                }
            }
        }


    }
    return 0;
}

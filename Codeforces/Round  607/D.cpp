    
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

    int testcases;
    cin>>testcases;
    for(int test=1;test<=testcases;test++)
    {
        int n,m;
        cin>>n>>m;

        string arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        bool isMortal=1, isImmortal=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]=='A')
                {
                    isMortal=0;
                }
                else
                {
                    isImmortal=0;
                }
            }
        }
        if(isMortal)
        {
            cout<<"MORTAL\n";
            continue;
        }
        if(isImmortal)
        {
            cout<<"0\n";
            continue;
        }
        bool row1=1,rown=1, col1=1,coln=1, oneA=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i][0]=='P')
            {
                col1=0;
            }
            else
                oneA=1;
            if(arr[i][m-1]=='P')
            {
                coln=0;
            }
            else
                oneA=1;
        }
        for(int i=0;i<m;i++)
        {
            if(arr[0][i]=='P')
            {
                row1=0;
            }
            else
                oneA=1;
            if(arr[n-1][i]=='P')
            {
                rown=0;
            }
            else
                oneA=1;
        }
        if(col1||coln||row1||rown)
        {
            cout<<1<<endl;
            continue;
        }

        if(arr[0][0]=='A' || arr[0][m-1]=='A' || arr[n-1][0]=='A' || arr[n-1][m-1]=='A')
        {
            cout<<2<<endl;
            continue;
        }
        bool wholeA=0;
        for(int i=0;i<n;i++)
        {
            int f1=1;
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]=='P')
                {
                    f1=0;
                }
            }
            if(f1)
            {
                wholeA=1;
            }
        }

        for(int i=0;i<m;i++)
        {
            int f1=1;
            for(int j=0;j<n;j++)
            {
                if(arr[j][i]=='P')
                {
                    f1=0;
                }
            }
            if(f1)
            {
                wholeA=1;
            }
        }
        if(wholeA)
        {
            cout<<2<<endl;
            continue;
        }

        if(oneA)
        {
            cout<<3<<endl;
        }
        else
            cout<<4<<endl;;

        cout<<endl;
    }
    
    return 0;
}
    
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
        string str1,str2;
        cin>>str1>>str2;

        int n1=str1.size(),n2=str2.size();
        string str=str1;
        int minn=n1-1;
        for(int i=n1-2;i>=0;i--)
        {
            if(str1[i]>str1[minn])
            {
                str=str1;
                swap(str[i],str[minn]);
            }
            else if(str1[i]<str1[minn])
            {
                minn=i;
            }
            // trace(i,minn,str,str1);

        }
        int flag=0;
        int i=0;
        for(i=0;i<n1 && i<n2;i++)
        {
            if(str[i]<str2[i])
            {
                flag=1;
                break;
            }
            else if(str[i]>str2[i])
            {
                flag=-1;
                break;
            }
        }
        if(flag==1)
            cout<<str;
        else if(flag==-1)
        {
            cout<<"---";
        }
        else
        {
            if(n1<n2)
            {
                cout<<str;
            }
            else
                cout<<"---";
        }



        cout<<endl;
    }
    
    return 0;
}
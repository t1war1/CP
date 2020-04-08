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
 
map<int,int> m;
void primeFactors(int n)  
{  
    if(n%2==0)  
    {
        int cnt=0;
        while (n % 2 == 0)  
        {  
            n = n/2;  
            cnt++;
        }  
        m[2]=cnt;
    }
    int sqt=sqrt(n);
    for (int i = 3; i <=sqt ; i = i + 2)  
    {  
        if(n%i==0)
        {
            int cnt=0;
            while (n % i == 0)  
            {  
                n = n/i;  
                cnt++;
            } 
            m[i]=cnt;
        }
         
    }  
 
    if (n > 2)  
    {
        m[n]=1;
    }
}  
 
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
        m.clear();
        int n;cin>>n;
        primeFactors(n);
        if(m.size()>=3)
        {
            cout<<"YES\n";
            auto it=m.begin();
            int x=1,y=1;
            for(int i=1;i<=(*it).ss;i++) x*=(*it).ff;
            it++;
            for(int i=1;i<=(*it).ss;i++) y*=(*it).ff;
            cout<<x<<" "<<y<<" "<<(n/(x*y));
        }
        else if(m.size()==2)
        {
            auto it=m.begin();
            int c1=0,c2=0,n1=0,n2=0;
            c1=(*it).ss;
            n1=(*it).ff;
            it++;
            c2=(*it).ss;
            n2=(*it).ff;
            // trace(n1,n2,c1,c2);
            if(c1>=2 && c2>=2)
            {
                cout<<"YES\n";
                cout<<n1<<" "<<n2<<" "<<(n/(n1*n2));
            }
            else if(c1==1 && c2>2)
            {
                cout<<"YES\n";
                cout<<n1<<" "<<n2<<" "<<(n/(n1*n2));
            }
            else if(c2==1 && c1>2)
            {
                cout<<"YES\n";
                cout<<n2<<" "<<n1<<" "<<(n/(n1*n2));
            }
            else
                cout<<"NO";
            
        }
        else
        {
            auto it=m.begin();
            if((*it).ss>5)
            {
                cout<<"YES\n";
                int num=(*it).ff;
                cout<<num<<" "<<num*num<<" "<<(n/(num*num*num));
            }
            else
                cout<<"NO";
        }
 
        cout<<endl;
    }
    
    return 0;
}

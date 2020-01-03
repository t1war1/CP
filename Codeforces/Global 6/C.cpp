#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define pb                      push_back
#define rep(i,a,b,c)            for(ll i=(a);i<=(b);i+=(c))
#define repb(i,a,b,c)           for(ll i=(a);i>=(b);i-=(c))
#define MOD                     1000000007
#define inf                     3e18
#define ld                      long double
//#define mp                      make_pair
#define vpll                    vector<pair<ll,ll>>
#define sll                     set<ll>
#define vll                     vector<ll>
#define vld                     vector<ld>
#define vvll                    vector<vector<ll>>
#define vvld                    vector<vector<ld>>
#define pll                     pair<ll,ll>
#define vvpll                   vector<vector<pair<ll,ll>>>
#define pqll                    priority_queue<ll>
#define mll                     map<ll,ll>
#define mlc                     map<ll,char>
#define um                      unordered_map
#define umll                    um<ll,ll>
#define umlc                    um<ll,char>
#define all(x)                  x.begin(),x.end()
#define fi                      first
#define se                      second
#define ln                      cout<<"\n";
#define endl                    "\n"
#define test                    ll Testcases;cin>>Testcases;while(Testcases--)
#define isvowel(a)              (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define fastIO                  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define show(w,size)            for(ll i=0;i<size;i++) cout<<w[i]<<" ";
#define print(a)                cout<<a<<"\n";
#define mset(dp,no)             memset(dp,no,sizeof(dp))
#define input(a,n)              rep(i,0,n-1,1) cin>>a[i];
#define countbit                __builtin_popcount                                           //Number of setbits in decimal notation
#define lb(v,val)               lower_bound(all(v),val)-v.begin()
#define ub(v,val)               upper_bound(all(v),val)-v.begin()
#define SS                      stringstream
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
 
ll poww(ll b,ll e){if(e==0)return 1;else if(e%2==0){ll a=pow(b,e/2);return a*a;}else {ll a=pow(b,e/2);return b*a*a;}}
ll powm(ll x,ll y,ll m=MOD){x=x%m;ll res=1;while(y){if(y&1)res=res*x;res%=m;y=y>>1;x=x*x;x%=m;}return res;}
ll modInverse(ll a, ll m=MOD) { return powm(a, m-2, m);}
 
int main()
{
    fastIO
    ll r,c,t=0;
    cin>>r>>c;
    ll row[r],col[c];
    
    if(r<c)
    {
    rep(i,0,r-1,1)
        row[i]=++t;
    rep(j,0,c-1,1)
        col[j]=++t;
    }
    else
    {
    rep(j,0,c-1,1)
        col[j]=++t;
    
    rep(i,0,r-1,1)
        row[i]=++t;
    }
    
    if((r==1)&&(c==1))
        cout<<0;
    else
    {
        rep(i,0,r-1,1)
        {
            rep(j,0,c-1,1)
                cout<<row[i]*col[j]<<" ";
            cout<<"\n";
        }
    }
        
    return 0;
}
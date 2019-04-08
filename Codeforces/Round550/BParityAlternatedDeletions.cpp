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
#define repi(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a;i>b;i--)
#define mp make_pair
#define ll long long
#define sorti(a,b) sort(a,b)
#define sortd(a,b,tp) sort(a,b,greater<tp>())
#define ff first
#define ss second

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;
int oo = 0x3f3f3f3f;
class BParityAlternatedDeletions {
    vector<int> even,odd;
    int n;
    ll find(vector<int> a, vector<int >b)
    {
        ll sum=0;
        for(int i=b.size()+1;i<a.size();i++)
        {
            sum+=a[i];
        }
        return sum;
    }
public:
	void solve(istream& cin, ostream& cout) {
        cin>>n;
        repi(i,0,n)
        {
            int x;
            cin>>x;
            if(x&1)
                odd.pb(x);
            else
                even.pb(x);
        }
        int diff=odd.size()-even.size();
        if(abs(diff)<2)
        {
            cout<<0;
            return;
        }
        sortd(odd.begin(),odd.end(),int);
        sortd(even.begin(),even.end(),int);
        if(diff<0)
        {
            cout<<find(even,odd);
        }
        else
            cout<<find(odd,even);

	}
};

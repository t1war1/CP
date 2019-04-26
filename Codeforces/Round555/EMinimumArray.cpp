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
class EMinimumArray {
    int n;
    int arr[200005];
    multiset<int> m;
public:
	void solve(istream& cin, ostream& cout) {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];

        for(int i=0;i<n;i++)
        {
            int x;cin>>x;m.insert(x);
        }
        for(int i=0;i<n;i++)
        {
            auto it1=m.lower_bound(n-arr[i]);
            auto it2=m.upper_bound(n-arr[i]);
            int x1,x2;
            if(it1!=m.end())
                x1=(arr[i]+*it1)%n;
            if(it2!=m.end())
                x2=(arr[i]+*it2)%n;
            if(it1!=m.end() && it2!=m.end()) {
                if (x1 <= x2) {
                    m.erase(it1);
                    cout << x1 << " ";
                } else {
                    m.erase(it2);
                    cout << x2 << " ";
                }
            }
            else if(it1==m.end() && it2==m.end()){
                cout<<(*m.begin()+arr[i])%n<<" ";
                m.erase(m.begin());
            }
            else if(it1!=m.end())
            {
                m.erase(it1);
                cout << x1 << " ";
            }
        }
	}
};

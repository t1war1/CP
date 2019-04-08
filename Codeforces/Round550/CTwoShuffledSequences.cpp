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
class CTwoShuffledSequences {
    int n;
    vector<int> arr;
public:
	void solve(istream& cin, ostream& cout) {
        cin>>n;
        arr.resize(n);
        repi(i,0,n)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        vector<int> arr1,arr2;
        for(int i=0;i<n;i++)
        {
            if(arr1.size()==0 || arr1[arr1.size()-1]<arr[i])
            {
                arr1.pb(arr[i]);
            }
            else if(arr2.size()==0 || arr2[arr2.size()-1]<arr[i])
            {
                arr2.pb(arr[i]);
            }
            else{
                cout<<"NO";
                return;
            }
        }
        cout<<"YES"<<"\n";
        cout<<arr1.size()<<"\n";
        for(int i=0;i<arr1.size();i++)
        {
            if(i!=0)
                cout<<" ";
            cout<<arr1[i];
        }
        cout<<"\n";
        cout<<arr2.size()<<"\n";
        
        for(int i=arr2.size()-1;i>=0;i--)
        {
            if(i!=arr2.size()-1)
                cout<<" ";
            cout<<arr2[i];
        }

	}
};

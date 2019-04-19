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
#define endl "\n"

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T> >;
int oo = 0x3f3f3f3f;



int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	fastIO;

    	int n,m;
    	cin>>n>>m;
    	int arr[n][m];
    	int ans=0;
    	vector<int> indexes;
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			cin>>arr[i][j];
    		}
    		ans^=arr[i][0];
    		indexes.pb(0);
    	}
    	if(ans>0)
    	{
    		cout<<"TAK\n";
    		repi(i,0,n)
    		{
    			cout<<indexes[i]+1<<" ";
    		}
    		return 0;
    	}
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			if(((ans^arr[i][0])^arr[i][j])>0)
    			{
    				cout<<"TAK\n";
    				for(int k=0;k<n;k++)
    				{
    					if(i==k)
    					{
    						cout<<j+1<<" ";
    					}
    					else
    					{
    						cout<<indexes[k]+1<<" ";
    					}
    				}
    				return 0;
    			}
    		}
    	}
    	cout<<"NIE";
	return 0;
}

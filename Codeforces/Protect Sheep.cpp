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
using min_pq = priority_queue<T,vector<T>,greater<T> >;
int oo = 0x3f3f3f3f;

int r,c;
char arr[501][501];

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	fastIO;

    	cin>>r>>c;
    	repi(i,0,r)
    	{
    		repi(j,0,c)
    		{
    			cin>>arr[i][j];
    			if(arr[i][j]=='.')
    				arr[i][j]='D';
    		}
    	}
    	repi(i,0,r)
    	{
    		repi(j,0,c)
    		{
    			if(arr[i][j]=='W')
    			{
    				if(arr[i][j-1]=='S' || arr[i][j+1]=='S' || arr[i-1][j]=='S' || arr[i+1][j]=='S' )
    				{
    					cout<<"No";
    					return 0;
    				}
    			}
    		}
    	}
    	cout<<"Yes\n";
    	repi(i,0,r)
    	{
    		repi(j,0,c)
    		{
    			cout<<arr[i][j];
    		}
    		cout<<"\n";
    	}


	return 0;
}

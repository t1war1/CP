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

    	int m,s;
    	cin>>m>>s;
    	if((s==0 && m>1) || (m==1 && s>9))
    	{
    	    cout<<-1<<" "<<-1;	
    		return 0;
    	}

    	vector<int> ans1(m,0),ans2(m,0);
    	int x=s;
    	for(int i=0;i<m;i++)
    	{
    		if(x<=9)
    		{
    			ans2[i]=x;
    			x=0;
    		}	
    		else
    		{
    			ans2[i]=9;
    			x-=9;
    		}
    	}
    	if(x!=0)
    	{
    		cout<<-1<<" "<<-1;	
    		return 0;
    	}

    	x=s;
    	int i;
    	for(i=m-1;i>=1;i--)
    	{
    		if(x>9)
    		{
    			ans1[i]=9;
    			x-=9;
    		}
    		else{
    			break;
    		}
    	}
    	if(x>9)
    	{
    		cout<<-1<<" "<<-1;
    	}
    	else{
    		if(x==1 || i==0)
    		{
    			ans1[0]=x;
    		}
    		else{
    			ans1[i]=x-1;
    			ans1[0]=1;
    		}

    		for(int i=0;i<m;i++)
    		{
    			cout<<ans1[i];
    		}
    		cout<<" ";
    		for(int i=0;i<m;i++)
    		{
    			cout<<ans2[i];
    		}
    	}


	return 0;
}

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

    // int testcases;cin>>testcases;
    // while(testcases--)
    // {
    	set<int> ab,ba;
    	string str;cin>>str;
    	for(int i=0;i<str.length()-1;i++)
    	{
    		if(str[i]=='A' && str[i+1]=='B')
    		{
    			ab.insert(i);
    		}
    		else if(str[i]=='B' && str[i+1]=='A')
    		{
    			ba.insert(i);
    		}
    	}
    	if(ab.empty() || ba.empty())
    	{
    		cout<<"NO"<<endl;
    		return 0;
    	}
    	bool flag=0;
    	for(auto it=ab.begin();it!=ab.end();it++)
    	{
    		auto it2=ba.upper_bound((*it)+1);
    		if(it2!=ba.end())
    		{
    			cout<<"YES"<<endl;
    			flag=1;
    			break;
    		}
    	}
    	if(!flag)
    	{
    		for(auto it=ba.begin();it!=ba.end();it++)
    		{
    			auto it2=ab.upper_bound((*it)+1);
    			if(it2!=ab.end())
    			{
    				cout<<"YES"<<endl;
    				flag=1;
    				break;
    			}
    		}
    	}
    	if(!flag)
    		cout<<"NO"<<endl;

    // }

	return 0;
}

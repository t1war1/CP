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

struct trainer
{
	ll day,lectures,sadness;
};

bool mycomparator(trainer t1, trainer t2)
{
	return t1.sadness<t2.sadness;
}

bool mycomp(trainer t1, trainer t2)
{
	return t1.day<t2.day;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    fastIO;


    	int t;
    	cin>>t;
    	while(t--)
    	{
    		int n,d;
    		cin>>n>>d;
    		ll sum=0,total=0;
    		priority_queue<trainer,vector<trainer>, function<bool(trainer,trainer)> > maxheap(mycomparator);
    		trainer arr[n];
    		for(int i=0;i<n;i++)
    		{
    			cin>>arr[i].day>>arr[i].lectures>>arr[i].sadness;
    			total+=arr[i].sadness *arr[i].lectures;
    		}
    		sort(arr,arr+n, mycomp);
    		int i=0;
    		for(int k=1;k<=d;k++)
    		{
    			while(i<n && arr[i].day==k)
    			{
    				maxheap.push(arr[i]);
    				i++;
    			}
    			if(maxheap.empty())
    				continue;
    			sum+=maxheap.top().sadness;
    			trainer curr=maxheap.top();
    			maxheap.pop();
    			curr.lectures--;
    			if(curr.lectures)
    				maxheap.push(curr);

    		}
    		cout<<total-sum<<"\n";
    	}
    

	return 0;
}
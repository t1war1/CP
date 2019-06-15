/**
 *    author: Gaurav Tiwari, Delhi Technological University
**/        
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
#define sorti(a,b) sort(a,b)
#define sortd(a,b,tp) sort(a,b,greater<tp>())
#define ff first
#define ss second
#define endl "\n"
// #define int long long

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
		s << arr[n - 1] << "]";
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
int oo = 0x3f3f3f3f;

int n,w,h,cache[5002],chain[5002];
pair<pii,int> arr[5002];

bool comp(pair<pii,int> p1,pair<pii,int> p2)
{
	return p1.ff.ff<p2.ff.ff?1:(p1.ff.ff==p2.ff.ff?p1.ff.ss>p2.ff.ss:0);
}

int dp(int i)
{
	if(i==n)
		return 0;
	if(cache[i]!=-1)
		return cache[i];
	cache[i]=1;
	for(int j=i+1;j<n;j++)
	{
		if(arr[j].ff.ff>arr[i].ff.ff && arr[j].ff.ss>arr[i].ff.ss)
		{
			int x=dp(j);
			if(x+1>cache[i])
			{
				cache[i]=x+1;
				chain[i]=j;
			}
		}
	}
	return cache[i];
}

void printchain(int i)
{
	if(i==-1)
		return;
	cout<<arr[i].ss<<" ";
	printchain(chain[i]);
}

int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
	#endif

	fastIO;

	memset(cache,-1,sizeof(cache));
	memset(chain,-1,sizeof(chain));
	cin>>n>>w>>h;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].ff.ff>>arr[i].ff.ss;
		arr[i].ss=i+1;
	}

	sort(arr,arr+n,comp);

	for(int i=0;i<n;i++)
	{
		if(arr[i].ff.ff>w && arr[i].ff.ss>h)
		{
			cache[i]=dp(i);
		}
		else
		{
			cache[i]=0;
		}
	}
	int maxx=0,ind=-1;
	for(int i=0;i<n;i++)
	{
		if(cache[i]>maxx)	
		{
			maxx=cache[i];
			ind=i;
		}
	}
	cout<<maxx<<endl;
	printchain(ind);
	cout<<endl;


	return 0;
}

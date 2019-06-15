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
#define int long long

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

int h,w;
char arr[505][505];
int hor[505][505],ver[505][505];
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
	#endif

	fastIO;
	cin>>h>>w;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			hor[i][j]=hor[i-1][j]+hor[i][j-1]-hor[i-1][j-1];
			ver[i][j]=ver[i-1][j]+ver[i][j-1]-ver[i-1][j-1];
			if(arr[i][j]=='.' && arr[i][j-1]=='.')
				hor[i][j]++;
			if(arr[i][j]=='.' && arr[i-1][j]=='.')
				ver[i][j]++;
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		int x=hor[r2][c2]-hor[r1-1][c2]-hor[r2][c1]+hor[r1-1][c1];
		int y=ver[r2][c2]-ver[r1][c2]-ver[r2][c1-1]+ver[r1][c1-1];
		cout<<x+y<<endl;
	}

	return 0;
}
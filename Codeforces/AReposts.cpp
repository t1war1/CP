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

int n;
map<string,vector<string>> m;
map<string,int> cache;
set<string> visited;

void dp(string curr)
{

	visited.insert(curr);
	cache[curr]=1;
	for(string s:m[curr])
	{
		if(visited.find(s)==visited.end())
			dp(s);
		cache[curr]=max(cache[curr],cache[s]+1);
	}
}

int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
	#endif

	fastIO;

	m.clear();m.clear();visited.clear();
	cin>>n;
	string str;
	getline(cin,str);
	for(int i=0;i<n;i++)
	{
		string s1="",s2="";
		getline(cin,str);
		int j=0;
		for(;j<str.length() && str[j]!=' ';j++)
		{
			s1+=tolower(str[j]);
		}
		j++;
		for(;j<str.length() && str[j]!=' ';j++)
			j++;
		j++;
		for(;j<str.length();j++)
		{
			s2+=tolower(str[j]);
		}
		// cerr<<s1<<" "<<s2<<endl;
		for(int k=0;k<s1.length();k++)
		{
			s1[k]=tolower(s1[k]);
		}
		for(int k=0;k<s2.length();k++)
		{
			s2[k]=tolower(s2[k]);
		}
		if(m.find(s2)==m.end())
		{
			vector<string> tmp={s1};
			m.insert({s2,tmp});
		}
		else
		{
			m[s2].pb(s1);
		}
	}

	for(auto p:m)
	{
		if(visited.find(p.ff)==visited.end())
		{
			dp(p.ff);
		}

	}

	int ans=0;
	for(auto p:m)
	{
		ans=max(ans,cache[p.ff]);
	}
	cout<<ans<<endl;

	return 0;
}

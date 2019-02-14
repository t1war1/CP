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
#define fi first
#define se second

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;

int n,m,x,y;
char mat[50][50];
bool visited[50][50];

bool isValid(int x,int y)
{
	if(x>=0 && x<m)
		return 1;
	return 0;
}

class Continents {
public:
	void solve(istream& cin, ostream& cout) {
		memset(visited,0, sizeof(visited));
        cin>>m>>n;
		repi(i,0,m)
			repi(j,0,n)
			cin>>mat[i][j];

		cin>>x>>y;
		x--;y--;
		char l=mat[x][y];
		int count=0;
		queue<pair<int,int>> q;

		visited[x][y]=1;
		q.push({x,y});


		while(q.size()!=0)
		{
			pii curr=q.front();
			q.pop();
			count++;x
			if(isValid(curr.fi+1,curr.se) && mat[curr.fi+1][curr.se]==l && !visited[curr.fi+1][curr.se]) {
				q.push({curr.fi + 1, curr.se});
				visited[curr.fi+1][curr.se]=1;
			}
			if(isValid(curr.fi-1,curr.se) && mat[curr.fi-1][curr.se]==l && !visited[curr.fi-1][curr.se]) {
				q.push({curr.fi-1, curr.se});
				visited[curr.fi-1][curr.se]=1;
			}
			if(isValid(curr.fi,(curr.se+1)%n) && mat[curr.fi][(curr.se+1)%n]==l && !visited[curr.fi][(curr.se+1)%n]) {
				q.push({curr.fi, (curr.se+1)%n});
				visited[curr.fi][(curr.se+1)%n]=1;
			}
			if(isValid(curr.fi,(curr.se-1+n)%n) && mat[curr.fi][(curr.se-1+n)%n]==l  && !visited[curr.fi][(curr.se-1+n)%n]) {
				q.push({curr.fi, (curr.se-1+n)%n});
				visited[curr.fi][(curr.se-1+n)%n]=1;
			}
		}
		cout<<count<<endl;

	}
};

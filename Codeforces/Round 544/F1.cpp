#include <bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define inf 1000000000000000000
using namespace std;
const int sz=200010;
vector<int> g[sz];
int c[sz];
bool vis[sz];
int main ()
{
    int n, m;
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        c[u]++;
        c[v]++;
    }
    int centre=1;
    for (int i=1; i<=n; i++) {
        if (c[i]>c[centre]) {
            centre=i;
        }
    }
    vis[centre]=true;
    queue<int> q;
    q.push(centre);
    while (q.empty()==false) {
        int u=q.front();
        q.pop();
        for (int i=0; i<g[u].size(); i++) {
            int v=g[u][i];
            if (vis[v]==false) {
                cout<<u<<" "<<v<<endl;
                vis[v]=true;
                q.push(v);
            }
        }
    }
    return 0;
}
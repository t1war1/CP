/*
 * http://www.codah.club/tasks.php?show_task=5000000355
 */

#include <bits/stdc++.h>
using namespace std;

int dest,n,k;
vector<pair<int,int>> graph;
int cache[60][4];
string str="";
int dp(int i, int source)
{
	if(cache[i][source]!=-1)
	{
		return cache[i][source];
	}
	if(i==0)
	{
		if(source==dest)
		{
			return cache[i][source]=1;
		}
		return cache[i][source]=0;
	}


	cache[i][source]=dp(i-1,graph[source].first)+dp(i-1,graph[source].second);
	return cache[i][source];
}
void rec(int len, int num, int source)
{
	if(len==0)
	{
		return;
	}
	bool flag=0;
	if(dp(len-1,graph[source].first)>=num)
	{
		str+='0';
		rec(len-1,num,graph[source].first);
	}
	else{
		str+='1';
		num-=dp(len-1,graph[source].first);
		rec(len-1,num,graph[source].second);
	}
}



int main() {
	memset(cache,-1, sizeof(cache));
	graph.push_back({2,1});
	graph.push_back({3,0});
	graph.push_back({0,3});
	graph.push_back({1,2});
	char ch;
	cin>>ch;
	dest=ch-'A';
	cin>>n>>k;
	if(dp(n,0)<k)
	{
		cout<<"impossible\n";
	}else{
		rec(n,k,0);
		cout<<str<<"\n";
	}
}


#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 17;

int n, per[maxn], cnt[3];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	n = s.size();
	string p;
	int c1 = 0;
	for(auto c : s)
		if(c != '1')
			p.push_back(c);
		else
			c1++;
	for(int i = 0; i < p.size(); i++)
		if(p[i] == '2')
			cout << string(c1, '1') << '2', c1 = 0;
		else
			cout << p[i];
	cout << string(c1, '1') << '\n';
}
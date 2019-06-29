#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    queue<string> q;
    set<string> s;
    int ans=0;
    q.push(str);
    s.insert(str);
    while(!q.empty())
    {
        string curr=q.front();
        q.pop();
        ans+=n-curr.size();
        k--;
        if(k==0)
        {
            break;
        }
        for(int i=0;i<curr.size();i++)
        {
            string x=curr.substr(0,i)+curr.substr(i+1);
            if(s.find(x)==s.end())
            {
                s.insert(x);
                q.push(x);
            }
        }
    }
    if(k==0)
    cout<<ans;
    else
    cout<<-1;
}
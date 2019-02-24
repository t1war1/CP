/*
*http://www.codah.club/tasks.php?show_task=5000000286
 */

#include <bits/stdc++.h>
using namespace std;

int r,c,k;
char arr[501][501];
int cache[501][501];

int dp(int i, int j)
{
    if(i==(r-1) && j==(c-1))
    {
        return 1;
    }

    if(cache[i][j]!=-1)
        return cache[i][j];
    int ans=0;
    if(i+1<r && arr[i+1][j]=='.')
    {
        ans+=dp(i+1,j);
    }
    if(j+1<c && arr[i][j+1]=='.')
    {
        ans+=dp(i,j+1);
    }
    cache[i][j]=ans;
    return ans;
}

void rec(int i, int j, int k)
{
    if(i==r-1 && j==c-1)
    {
        return;
    }

    if(i+1<r && arr[i+1][j]=='.' && dp(i+1,j)>=k)
    {
        cout<<"D";
        rec(i+1,j,k);
    }
    else{
        if(i+1<r)
            k-=dp(i+1,j);
        cout<<"R";
        rec(i,j+1,k);
    }
}

int main() {
    memset(cache,-1, sizeof(cache));
    cin>>r>>c>>k;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }

    if(dp(0,0)<k)
    {
        cout<<"impossible\n";
    }
    else{
        rec(0,0,k);
        cout<<"\n";
    }

}


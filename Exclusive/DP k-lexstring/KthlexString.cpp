/* Problem:
 * Example 1
Consider all strings of length n using letters a,b,c such that substrings "ab", "bb", "ca" are forbidden. Find the lexicographically Kth string (K is 1 based)

 http://vivekcp.blogspot.com/2017/05/advanced-dp-part-1lexicographic-order.html
 */


#include <bits/stdc++.h>
using namespace std;

int d[101][3];
string str="";
void rec(int len, int k, int prev)
{
    if(len==0)
    {
        return;
    }

    int i;
    for(i=0;i<3;i++)
    {
        if((prev==0 && i==1)||(prev==1 && i==1)||(prev==2 && i==0))
            continue;

        if(k>d[len][i])
        {
            k-=d[len][i];
        }else{
            break;
        }
    }
    str+=(char)('a'+i);
    rec(len-1,k,i);
}

int main() {
    int k=5;
//    cin>>k;

    d[0][0]=1;
    d[0][1]=1;
    d[0][2]=1;
    for(int i=1;i<=10;i++)
    {
        d[i][0]=d[i-1][0]+((i!=1)?d[i-1][2]:0);
        d[i][1]=d[i-1][0]+((i!=1)?d[i-1][2]:0);
        d[i][2]=d[i-1][1]+((i!=1)?d[i-1][2]:0);
    }
    rec(4,k,-1);
    cout<<str;
}


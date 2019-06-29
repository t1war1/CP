#include <bits/stdc++.h>
using namespace std;
void printarr(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    int c[n],f[n],s1=0,s2=0;
    for(int i=0;i<n;i++)
    {
        double x;
        cin>>x;
        c[i]=(int)ceil(x);
        s1+=c[i];
        f[i]=(int)floor(x);
        s2+=f[i];
    }
    int tmp[n];
    for(int i=0;i<n;i++)
    {
        tmp[i]=c[i]-f[i];
    }
    if(s1==0)
    {
        printarr(c,n);
        return 0;
    }
    if(s2==0)
    {
        printarr(f,n);
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(s2>0)
        {
            if(tmp[i]==-1)
            {
                f[i]=c[i];
                s2--;
            }
        }
        else{
            if(tmp[i]==1)
            {
                f[i]=c[i];
                s2++;
            }
        }
        if(s2==0)
        {
            break;
        }
    }
    printarr(f,n);
}
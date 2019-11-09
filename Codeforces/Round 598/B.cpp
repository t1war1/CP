#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int testcases;
    cin>>testcases;
 
    while(testcases--)
    {
        int n;
        cin>>n;
 
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        int i=0;
        while(i<n)
        {
            int j=i, minn=n, pos=n;
            while(j<n)
            {
                if(arr[j] < minn)
                {
                    minn=arr[j];
                    pos=j;
                }
                j++;
            }
            j=pos-1;
            while(j>=i)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[i]=minn;
            if(pos!=i)
                i=pos;
            else
                i++;
        }
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
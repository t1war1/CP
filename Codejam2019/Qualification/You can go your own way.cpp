#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        string ans="";
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='E')
            {
                ans+='S';
            }else{
                ans+='E';
            }
        }
        cout<<"Case #"<<x<<": "<<ans<<"\n";
    }
}

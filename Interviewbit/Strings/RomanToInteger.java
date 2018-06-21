public class Solution {
    public int romanToInt(String A) {
        int m=0,d=0,c=0,l=0,x=0,v=0,i=0,k=0,ans=0;
        for( k=0;k<A.length();k++)
        {
            if(A.charAt(k)=='M')
            {
                if(k>0)
                {
                    if(A.charAt(k-1)=='C')
                    {
                        ans+=800;
                    }
                    else
                    {
                        ans+=1000;
                    }
                }
                else
                {
                    ans+=1000;
                }
            }
            else if(A.charAt(k)=='D')
            {
                if(k>0)
                {
                    if(A.charAt(k-1)=='C')
                    {
                        ans+=300;
                    }
                    else
                    {
                        ans+=500;
                    }
                }
                else
                {
                    ans+=500;
                }
            }
            else if(A.charAt(k)=='C')
            {
                if(k>0)
                {
                    if(A.charAt(k-1)=='X')
                    {
                        ans+=80;
                    }
                    else
                    {
                        ans+=100;
                    }
                }
                else
                {
                    ans+=100;
                }
            }
            else if(A.charAt(k)=='L')
            {
                if(k>0)
                {
                    if(A.charAt(k-1)=='X')
                    {
                        ans+=30;
                    }
                    else
                    {
                        ans+=50;
                    }
                }
                else
                {
                    ans+=50;
                }
            }
            else if(A.charAt(k)=='X')
            {
                if(k>0)
                {
                    if(A.charAt(k-1)=='I')
                    {
                        ans+=8;
                    }
                    else
                    {
                        ans+=10;
                    }
                }
                else
                {
                    ans+=10;
                }
            }
            else if(A.charAt(k)=='V')
            {
                if(k>0)
                {
                    if(A.charAt(k-1)=='I')
                    {
                        ans+=3;
                    }
                    else
                    {
                        ans+=5;
                    }
                }
                else
                {
                    ans+=5;
                }
            }
            else if(A.charAt(k)=='I')
            {
                ans+=1;
            }
            else
            {
                return 0;
            }
        }
        return ans;
    }
}

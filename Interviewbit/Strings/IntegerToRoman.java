public class Solution {
    public String intToRoman(int A) {
        int place=0;
        String ans="";
        while(A>0)
        {
            String temp="";
            int rem=A%10;
            A/=10;
            if(place==0)
            {
                if(rem>0 && rem<=3)
                {
                    for(int i=0;i<rem;i++)
                    {
                        temp+='I';
                    }
                }
                else if(rem==4)
                {
                    temp+="IV";
                }
                else if(rem==9)
                {
                    temp+="IX";
                }
                else if(rem>=5 && rem<9)
                {
                    temp+="V";
                    for(int i=0;i<rem-5;i++)
                    {
                        temp+='I';
                    }
                }
                ans=temp+ans;
            }
            else if(place==1)
            {
                if(rem>0 && rem<=3)
                {
                    for(int i=0;i<rem;i++)
                    {
                        temp+='X';
                    }
                }
                else if(rem==4)
                {
                    temp+="XL";
                }
                else if(rem==9)
                {
                    temp+="XC";
                }
                else if(rem>=5 && rem<9)
                {
                    temp+="L";
                    for(int i=0;i<rem-5;i++)
                    {
                        temp+='X';
                    }
                }
                ans=temp+ans;
            }
            else if(place==2)
            {
                if(rem>0 && rem<=3)
                {
                    for(int i=0;i<rem;i++)
                    {
                        temp+='C';
                    }
                }
                else if(rem==4)
                {
                    temp+="CD";
                }
                else if(rem==9)
                {
                    temp+="CM";
                }
                else if(rem>=5 && rem<9)
                {
                    temp+="D";
                    for(int i=0;i<rem-5;i++)
                    {
                        temp+='C';
                    }
                }
                ans=temp+ans;
            }
            else if(place==3)
            {
                if(rem>0 && rem<=3)
                {
                    for(int i=0;i<rem;i++)
                    {
                        temp+='M';
                    }
                }
                ans=temp+ans;
            }
            place++;
        }
        return ans;
    }
}

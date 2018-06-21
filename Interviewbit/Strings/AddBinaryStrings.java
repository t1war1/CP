public class Solution {
    public String addBinary(String A, String B) {
        int diff=Math.abs(A.length()-B.length());
        String small="",big="";
        if(A.length()<B.length())
        {
            small=A;
            big=B;
        }
        else
        {
            small=B;
            big=A;
        }
        
        for(int i=0;i<diff;i++)
        {
            small='0'+small;
        }
        int carry=0;
        String ans="";
        for(int i=small.length()-1;i>=0;i--)
        {
            int a=small.charAt(i)-'0';
            int b=big.charAt(i)-'0';
            int sum=a^b^carry;
            carry=(a&b)|(b&carry)|(carry&a);
            ans=sum+ans;
        }
        if(carry==1)
        {
            ans=1+ans;
        }
        return ans;
    }
}

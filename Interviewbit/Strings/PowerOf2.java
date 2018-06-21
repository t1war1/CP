import java.math.BigInteger;

public class Solution {
    public int power(String A) {
        BigInteger num=new BigInteger(A);
        BigInteger two=new BigInteger("2");
        BigInteger ans=new BigInteger("2");
        while(true)
        {
            if(num.compareTo(ans)==0)
            {
                return 1;
            }
            else if(ans.compareTo(num)==1)
            {
                return 0;
            }
             ans=ans.multiply(two);
            
        }
    }
}

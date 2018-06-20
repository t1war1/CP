import java.math.BigInteger;
public class Solution {
    public int compareVersion(String A, String B) {
         String splitA[]=A.split("\\.");
           String splitB[]=B.split("\\.");
           int i=0;
    
           for(i=0;i<splitA.length && i<splitB.length;i++)
           {
                       BigInteger A1=new BigInteger(splitA[i]);
                       BigInteger B1=new BigInteger(splitB[i]);
                       if(A1.compareTo(B1)==1)
                       {
                           return 1;
                       }
                       else if(A1.compareTo(B1)==-1)
                       {
                           return -1;
                       }
           }
           if(i<splitA.length)
           {
                       while(i<splitA.length)
                       {
                           BigInteger A1=new BigInteger(splitA[i]);
                           if(A1.compareTo(new BigInteger(0+""))==1)
                           {
                               return 1;
                           }
                           i++;
                       }
           }
           else if(i<splitB.length)
           {
                       while(i<splitB.length)
                       {
                           BigInteger A1=new BigInteger(splitB[i]);
                           if(A1.compareTo(new BigInteger(0+""))==1)
                           {
                               return -1;
                           }
                           i++;
                       }
           }
           return 0;
    }
}

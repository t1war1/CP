import java.math.BigInteger;
public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
         public static int strStr(final String A, final String B) {
            if(A.length()==0 || B.length()==0 || A.length()<B.length())
            {
                return -1;
            }
            
            String pat=B;
            String text=A;
            
            BigInteger patHash=createHash(pat);
            BigInteger currentHash=createHash(text.substring(0,pat.length()));
            
            for(int i=0;i<=(text.length()-pat.length());i++ )
            {
                if(currentHash.equals(patHash))
                {
                    if(checkEqual(pat,text.substring(i,i+pat.length())))
                    {
                        return i;
                    }
                }
                
                if( i<(text.length()-pat.length()) )
                {
                    currentHash.subtract(new BigInteger(""+(text.charAt(i)-'a')));
                    currentHash.add(new BigInteger(""+(((text.charAt(i+pat.length())-'a')*((int)Math.pow(101,pat.length()-1))))));
                    
                }
            }
            return -1;
        }
        
        public static boolean checkEqual(String a,String b)
        {
            for(int i=0;i<a.length();i++ )
            {
                if(a.charAt(i)!=b.charAt(i) )
                {
                    return false;
                }
            }
            return true;
        }
        
        public static BigInteger createHash(String str)
        {
            BigInteger ans=new BigInteger(0+"");
            for(int i=0;i<str.length();i++ )
            {
                    int temp=((str.charAt(i)-'a')*(int)Math.pow(101,i));
                ans.add(new BigInteger(""+temp));
            }
            return ans;
        }

}

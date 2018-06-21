public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int lengthOfLastWord(final String A) {
        
        int i=A.length()-1;
        while(i>=0)
            {
                    if(A.charAt(i)==' ')
                i--;
                    else
                        break;
            }
        if(i<0)
        {
            return 0;
        }
        int count=0;
        while(i>=0)
        {
            if(A.charAt(i)!=' ' )
            {
                count++;i--;
            }
            else
            {
                break;
            }
        }
        return count;
    }
}

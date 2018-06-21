public class Solution {
    public String reverseWords(String a) {
        String arr[]=a.split(" ");
        String ans="";
        int i=arr.length-1;
        while(i>=0)
        {
            String curr=arr[i];
            i--;
            if(curr.equals(""))
                continue;
            if(ans.equals(""))
            {
                ans=ans+curr;
            }
            else
            {
                ans=ans+" "+curr;
            }
        }
        return ans;
    }
}

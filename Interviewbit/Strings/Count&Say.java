public class Solution {
    public String countAndSay(int A) {
       String prev="1"; //Taking first sequence as prev variable
            if(A==1)  //If A==1 return 1
                return "1";
                String ans="";
            for(int i=2;i<=A;i++) //Compute every ith sequence where i<=A
            {
                char p=prev.charAt(0);int count=1; //Count of 1st character of previous sequence
                for(int j=1;j<prev.length();j++ ) //counting contiguous characters
                {
                    if(prev.charAt(j)==p)//if same as previous character
                    {
                        count++;
                    }
                    else //else append count to ans of current sequence and then append p
                    {
                        ans=ans+count+p;
                        p=prev.charAt(j);
                        count=1;
                    }
                }
                ans=ans+count+p; //to append for the last character
                prev=ans; //change prev to ans
                ans=""; //change ans to empty string to compute next sequence
            }
            return prev; //answer will be in prev variable as ans variable is turned to empty string after every iteration
            
    }
}

public class Solution {
    // DO NOT MODIFY THE LIST
    public int repeatedNumber(final List<Integer> a) {
            int temp=a.get(0);
            while(true)
            {
                if(a.get(temp)==-1)
                {
                    return temp;
                }
                else{
                int t=a.get(temp);
                a.set(temp,-1);
                temp=t;}
            }
    }
}

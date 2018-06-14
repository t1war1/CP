public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public ArrayList<Integer> findPerm(final String A, int B) {
        ArrayList<Integer> arr=new ArrayList<>();
        int beg=1,last=B;
        for(int i=0;i<A.length();i++)
        {
            if(A.charAt(i)=='D')
            {
                arr.add(last);
                last--;
            }
            else
            {
                arr.add(beg);
                beg++;
            }
        }
        arr.add(last);
        return arr;
    }
}
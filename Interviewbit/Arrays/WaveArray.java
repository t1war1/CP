public class Solution {
    public ArrayList<Integer> wave(ArrayList<Integer> A) {
        Collections.sort(A);
        ArrayList<Integer> ans=new ArrayList<>();
        int i=1;
        if(A.size()<1)
        {
            ans.add(A.get(0));
            return ans;
        }
        while(i<A.size())
        {
            ans.add(A.get(i));
            ans.add(A.get(i-1));
            i+=2;
        }
        if(i==A.size())
        {
            ans.add(A.get(A.size()-1));
        }
        return ans;
    }
}

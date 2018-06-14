public class Solution {
    public boolean hotel(ArrayList<Integer> arrive, ArrayList<Integer> depart, int K) {
        Collections.sort(arrive);
        Collections.sort(depart);
        
        int rooms=1,i=1,j=0;
        while(i<arrive.size() && j<depart.size()  )
        {
            if(arrive.get(i) < depart.get(j))
            {
                rooms++;
                i++;
            }
            else
            {
                rooms--;
                j++;
            }
            if(rooms>K)
            {
                return false;
            }
        }
        return true;
    }
}

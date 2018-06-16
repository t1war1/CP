public class Solution {
    public int findMedian(ArrayList<ArrayList<Integer>> A) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        int r=A.size();
        int c=A.get(0).size();
        for(int i=0; i<A.size() ; i++)
        {
            if(A.get(i).get(0)< min)
                min = A.get(i).get(0);
    
            if(A.get(i).get(A.get(0).size()-1) > max)
                max = A.get(i).get(c-1);
        }
        int desired=(r*c+1)/2;
        
        while(min<max)
        {
            int mid = min + (max - min) / 2;
            int place = 0;
            int get = 0;
            
            for(int i = 0; i < r; ++i)
            {
                 
                get = Collections.binarySearch(A.get(i),mid);

                if(get < 0)
                    get = Math.abs(get) - 1;

                else
                {
                    while(get < A.get(i).size() && A.get(i).get(get) == mid)
                        get += 1;
                }
                 
                place = place + get;
            }
              if (place < desired)
                min = mid + 1;
            else
                max = mid;
        }
        return min;
    }
}

public class Solution {
    // DO NOT MODIFY THE LIST
    public int search(final List<Integer> a, int b) {
        return searcher(a,b,0,a.size()-1);
    }
    
    public static int searcher(final List<Integer> a,int key,int l,int h)
    {
        if (l > h) 
            return -1;
       
        int mid = (l+h)/2;
        if (a.get(mid) == key)
            return mid;
            
        if (a.get(l) <= a.get(mid))
        {
            if (key >= a.get(l) && key <= a.get(mid))
               return searcher(a,key, l, mid-1);
       
            return searcher(a,key, mid+1, h);
        }

        if (key >= a.get(mid) && key <= a.get(h))
            return searcher(a,key, mid+1, h);
       
        return searcher(a,key, l, mid-1);
    }
}

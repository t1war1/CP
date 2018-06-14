public class Solution {
    public void nextPermutation(ArrayList<Integer> a) {
        PriorityQueue<Integer> minHeap=new PriorityQueue<>();
         boolean swap=false;
          int i=a.size()-2;
         for(;i>=0;i--)
         {
             if(a.get(i)<a.get(i+1))
             {
                 swap=true;
                 int temp=a.get(i);
                 a.set(i,a.get(i+1));
                 a.set(i+1, temp);
                 break;
             }else {
                 minHeap.add(a.get(i+1));
             }
         }
         if(swap) {
             i++;
             minHeap.add(a.get(i));
         }else {
             i=0;
         }
         while(!minHeap.isEmpty())
         {
             a.set(i, minHeap.poll());
             i++;
         }
    }
}

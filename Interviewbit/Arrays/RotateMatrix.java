public class Solution {
    public void rotate(ArrayList<ArrayList<Integer>> a) {
       PriorityQueue<Integer> minHeap=new PriorityQueue<>(Collections.reverseOrder());
         boolean swap=false;
          int i=a.size()-2;
         for(;i>=0;i--)
         {
             if(a.get(i)<a.get(i+1))
             {
                 int max=Integer.MAX_VALUE,index=-1;
                 for(int j=i+1;j<a.size();j++)
                 {
                     if(a.get(i)<a.get(j) && a.get(j)<max)
                     {
                        max=a.get(j);
                        index=j;
                     }
                 }
                 int temp=a.get(i);
                 a.set(i, a.get(index));
                 a.set(index, temp);
                 i++;
                 swap=true;
                 break;
             }
         }  
         if(swap) {
         while(i<a.size())
         {
             minHeap.add(a.get(i));
             i++;
         }
         i=a.size()-1;
         while(!minHeap.isEmpty())
         {
             a.set(i, minHeap.poll());
             i--;
         }
         }
         else {
             for(int j=0,k=a.size()-1;j<(a.size())/2;j++,k--)
                {
                    int temp=a.get(j);
                    a.set(j,a.get(k));
                    a.set(k,temp);
                }
         }
    }
}

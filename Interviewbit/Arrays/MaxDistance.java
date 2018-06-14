public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int maximumGap(final List<Integer> A) {
        pair elements[]=new pair[A.size()];
        for(int i=0;i<A.size();i++)
        {
                elements[i]=new pair(i,A.get(i));
        }
        Arrays.sort(elements,new Comparator<pair>(){

            @Override
            public int compare(pair o1, pair o2) {
                return o1.value-o2.value;
            }
            
        });
        
        int maxIndexes[]=new int[A.size()];
        maxIndexes[A.size()-1]=0;
        int ans=0;
        for(int i=A.size()-2;i>=0;i--)
        {
                int temp=Math.max(maxIndexes[i+1], elements[i+1].index);
                maxIndexes[i]=temp;
                ans=Math.max(ans, temp-elements[i].index);
        }
        return ans;
        
        
    }
}
class pair{
    int index;
    int value;
    pair(int index,int value)
    {
        this.index=index;
        this.value=value;
    }
}
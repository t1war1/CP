public class Solution {
    public ArrayList<Integer> plusOne(ArrayList<Integer> A) {
        
        ArrayList<Integer> ans=new ArrayList<>();
        int lsd=(A.get(A.size()-1)+1)%10;
        int carry=(A.get(A.size()-1)+1)/10;
        ans.add(lsd);
        int count=0;
        for(int i=0;i<A.size();i++)
        {
            if(A.get(i)!=0)
            {
                break;
            }
            count++;
        }
        for(int i=A.size()-2;i>=count;i--)
        {
            
            ans.add((A.get(i)+carry)%10);
            
            carry=(A.get(i)+carry)/10;
        }
        
        if(carry==1)
        {
            ans.add(1);
        }
        
        for(int i=0,j=ans.size()-1;i<ans.size()/2;i++,j--)
        {
            int temp=ans.get(i);
            ans.set(i,ans.get(j));
            ans.set(j,temp);
        }
        
        return ans;
}
}
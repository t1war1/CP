public class Solution {
    public ArrayList<String> fullJustify(ArrayList<String> A, int B) {
       ArrayList<String> arr=new ArrayList<>();
        int i=0,j=0,currLength=0;
        while(i<A.size() && j<A.size())
        {
            i=j;
            currLength=0;
            while(i<A.size())
            {
                currLength+=A.get(i).length();
                if(!(currLength<B && B-currLength>=i-j))
                {
                    break;
                }
                i++;
            }
            if(i!=A.size())
            {
                currLength-=A.get(i).length();
            }
            i--;
            int totalSpace=B-currLength;
            int evenSpace=B-A.get(i).length();
            if(i-j!=0)
            evenSpace=totalSpace/(i-j);
            int oddSpace=0;
            if(i-j!=0)
            oddSpace=totalSpace%(i-j);
            String ab="";
            int evenDone=0;
            if(i!=A.size()-1)
            {
            for(int k=j;k<=i;k++)
            {
                ab+=A.get(k);
                if(k!=i)
                {
                for(int z=0;z<evenSpace;z++)
                {
                    ab+=" ";
                }
                evenDone++;
                if(oddSpace>0)
                {
                    ab+=" ";
                    oddSpace--;
                }
                }
                else
                {
                    if(evenDone==0)
                    {
                        int l=B-A.get(i).length();
                        for(int m=0;m<l;m++)
                        {
                            ab+=" ";
                        }
                    }
                }
                
            }
            }
            else
            {
                for(int k=j;k<=i;k++)
                {
                    ab+=A.get(k);
                    if(k!=i)
                    {
                        ab+=" ";
                    }
                }
                int l=B-ab.length();
                for(int m=0;m<l;m++)
                {
                    ab+=" ";
                }
            }

            arr.add(ab);
            j=i+1;
            i=j;
        }
        return arr;
    }
}

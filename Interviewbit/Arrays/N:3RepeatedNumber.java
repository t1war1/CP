public class Solution {
    // DO NOT MODIFY THE LIST
    public int repeatedNumber(final List<Integer> a) {
        
        ArrayList<Pair> numbers=new ArrayList<>();
        if(a.size()==0)
        {
            return -1;
        }
        if(a.size()==1)
        {
            return a.get(0);
        }
        for(int i=0;i<a.size();i++)
        {
            int curr=a.get(i);
            if(numbers.size()<2)
            {
                    if(numbers.size()!=0)
                    {
                        if(numbers.get(0).value==curr)
                        {
                            numbers.set(0, new Pair(curr,numbers.get(0).count+1));
                        }
                        else {
                            numbers.add(new Pair(curr,1));
                        }
                    }
                    else
                    numbers.add(new Pair(curr,1));
            }
            else
            {
                    if(curr==numbers.get(0).value)
                    {
                        numbers.set(0, new Pair(curr,numbers.get(0).count+1));
                    }
                    else if(curr==numbers.get(1).value)
                    { 
                        numbers.set(1, new Pair(curr,numbers.get(1).count+1));
                    }
                    else {
                        int temp=numbers.get(1).count-1;
                        if(temp==0)
                            numbers.remove(1);
                        else
                        numbers.set(1, new Pair(numbers.get(1).value,temp));
                        
                        temp=numbers.get(0).count-1;
                        if(temp==0)
                        {
                            numbers.remove(0);
                        }
                        else
                        {
                            numbers.set(0, new Pair(numbers.get(0).value,temp));
                        }
                    }
            }
            
        }
        int c1=Integer.MAX_VALUE;
        if(numbers.size()>0)
        c1=numbers.get(0).value;
        int c2=Integer.MAX_VALUE;
        if(numbers.size()==2)
        c2=numbers.get(1).value;
        int c1count=0,c2count=0;
        for(int i=0;i<a.size();i++)
        {
                if(a.get(i)==c1)
                    c1count++;
                else if(a.get(i)==c2)
                {
                    c2count++;
                }
        }
        if(c1count>a.size()/3)
        {
                return c1;
        }
        if(c2count>a.size()/3)
        {
            return c2;
        }
        return -1;
    }
}
class Pair{
    int value;
    int count;
    Pair(int value,int count)
    {
        this.value=value;
        this.count=count;
    }
}
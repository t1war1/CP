package trial;

import java.util.*;
 
public import java.util.*;

class Trial2 {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        HashSet<Integer> hashset=new HashSet<>();
        int t=s.nextInt();
        for(int i=0;i<t;i++)
        {
            for(int j=0;j<4;j++) {
                int temp=s.nextInt();
                if(hashset.contains(temp))
                {
                    hashset.remove(temp);
                }
                else
                {
                    hashset.add(temp);
                }
            }
            if(hashset.size()!=0)
            {
                System.out.println("NO");
            }
            else {
                System.out.println("YES");
            }
            hashset.clear();
        }
    }
}
 

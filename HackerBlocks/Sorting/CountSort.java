import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int arr[]=new int[n];
                int frequency[]=new int[1000001];
        for(int i=0;i<n;i++)
        {
            arr[i]=s.nextInt();
            frequency[arr[i]]++;
        }
        
        int i=0;
        for(int j=0;j<frequency.length;j++)
        {
            if(frequency[j]==0)
            {
                continue;
            }
            int count=0;
            while(count<frequency[j])
            {
                count++;
                arr[i++]=j;
            }
        }
        for(int k:arr)
        {
            System.out.print(k+" ");
        }
    }
}

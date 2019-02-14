/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s=new Scanner(System.in);
        int t=s.nextInt();
        s.nextLine();
        while(t-->0)
        {
            String str=s.nextLine();
            String[] arr=str.split(" ");
            int flag=0;
            for(String i:arr)
            {
                if(i.equals("not"))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                System.out.println("Real Fancy");
            }
            else
            {
                System.out.println("regularly fancy");
            }
        }
	}
}

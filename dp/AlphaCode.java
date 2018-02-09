package dp;
import java.util.*;
public class AlphaCode {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		while(true)
		{
			String str=s.nextLine();
			if(!str.equals("0"))
			System.out.println(decode(str));
			else 
				break;
		}
	}

	public static long decode(String str) {
		long[] output=new long[str.length()+1];
		output[0]=1;
		output[1]=1;
		
		for(int i=2;i<=str.length();i++)
		{
			output[i]=output[i-1];
			if((str.charAt(i-2)-'0')*10 + (str.charAt(i-1)-'0') <=26)
				output[i]+=output[i-2];
			output[i]=output[i]%1000000007;
		}
		return output[str.length()];
	}
	
	
}

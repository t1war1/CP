package trial;

import java.util.Scanner;

public class KCON {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		printCodes("4523","");
	}
	
	public static void printCodes(String input,String currOutput)
	{
		if(input.length()==0)
		{
			System.out.println(currOutput);
			return;
		}
		
		char code1=getChar(""+input.charAt(0));
		printCodes(input.substring(1),currOutput+code1);
		
		if(input.length()>1) {
			if(Integer.parseInt(input.substring(0,2))<=26) {
				char code2=getChar(input.substring(0,2));
				printCodes(input.substring(2),currOutput+code2);
			}
		}
	}

	private static char getChar(String string) {
		// TODO Auto-generated method stub
		int a=Integer.parseInt(string);
		String alphabets="abcdefghijklmnopqrstuvwxyz";
		return alphabets.charAt(a-1);
	}
}

public class Countandsay {
	
	public static void main(String[] args) {
		
		System.out.println(countAndSay(5));
		}

	
    public static String countAndSay(int A) {
       String prev="1"; //Taking first sequence as prev variable
            if(A==1)  //If A==1 return 1
                return "1";
                String ans="";
            for(int i=2;i<=A;i++) //Compute every ith sequence where i<=A
            {
                char p=prev.charAt(0);int count=1; //Count of 1st character of previous sequence
                for(int j=1;j<prev.length();j++ ) //counting contiguous characters
                {
                    if(prev.charAt(j)==p)//if same as previous character
                    {
                        count++;
                    }
                    else //else append count to ans of current sequence and then append p
                    {
                        ans=ans+count+p;
                        p=prev.charAt(j);
                        count=1;
                    }
                }
                ans=ans+count+p; //to append for the last character
                prev=ans; //change prev to ans
                ans=""; //change ans to empty string to compute next sequence
            }
            return prev; //answer will be in prev variable as ans variable is turned to empty string after every iteration
            
    }
}


//Another approach using lps array

package Searching;

import java.util.*;
    
public class SearchInRotatedArray {

    public static void main(String[] args) {
            System.out.println(countAndSay("AACECAAAA"));
        }
     public static int countAndSay(String A) {
         String temp=A;
            String revA=reverse(A);
            A=A+'$'+revA;
            int lps[]=getLPS(A);
            return temp.length()-lps[lps.length-1];
        }
    private static String reverse(String a) {
        String ans="";
        for(int i=a.length()-1;i>=0;i--)
        {
            ans+=a.charAt(i);
        }
        return ans;
    }
    private static int[] getLPS(String a) {
        int arr[]=new int[a.length()];
        arr[0]=0;
        int i=0,j=1;
        while(j<a.length())
        {
            if(a.charAt(i)==a.charAt(j))
            {
                arr[j]=i+1;
                i++;
                j++;
            }
            else
            {
                if(i!=0)
                {
                    i=arr[i-1];
                }
                else
                {
                    arr[j]=0;
                    j++;
                }
            }
        }
        return arr;
    }
     
        }

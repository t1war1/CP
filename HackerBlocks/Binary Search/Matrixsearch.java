package Searching;

import java.util.Scanner;

public class SearchInRotatedArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);        
        int rows=s.nextInt();
        int cols=s.nextInt();
        int arr[][]=new int[rows][cols];
        for(int i=0;i<rows;i++)
        {
        		for(int j=0;j<cols;j++)
        		{
        			arr[i][j]=s.nextInt();
        		}
        }
        int x=s.nextInt(),flag=0;
        for(int i=0;i<rows;i++)
        {
        		int beg=0,last=cols-1;
        		while(beg<=last)
        		{
        			int mid=(beg+last)/2;		
        			if(arr[i][mid]==x)
        			{
        				flag=1;
        				break;
        			}
        			else if(arr[i][mid]>x)
        			{
        				last=mid-1;
        			}
        			else
        			{
        				beg=mid+1;
        			}
        		}
        		if(flag==1)
        		{
        			System.out.println(1);
        			break;
        		}
        }
        if(flag==0)
        	System.out.println(0);
	}		
	
}

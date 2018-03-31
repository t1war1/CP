package gaga;

import java.util.Scanner;

public class christmas {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int m=s.nextInt();
		
		int edges[][]=new int[n][n];

		for(int i=0;i<n-1;i++)
		{
			int fv=s.nextInt();
			int sv=s.nextInt();
			edges[fv-1][sv-1]=1; 
			edges[sv-1][fv-1]=1;
		}
		
		System.out.println(maxGifts(edges,s,m));
	}

	public static int maxGifts(int[][] edges,Scanner s,int m) {
		int max=Integer.MIN_VALUE;
		int record[]=new int[edges.length];
		for(int i=0;i<m;i++) {
			int sv=s.nextInt();
			int fv=s.nextInt();	
			boolean visited[]=new boolean[edges.length];
			maxGiftshelp(edges,sv-1,fv-1,visited,record);
			
		}
		for(int i=0;i<record.length;i++)
		{
			if(record[i]>max)
				max=record[i];
		}
		return max;
	}

	private static boolean maxGiftshelp(int[][] edges, int sv, int fv, boolean[] visited,int[] record) {
		
		visited[sv]=true;
		if(sv==fv)
		{
			record[sv]++;
			return true;
		}
		int temp=record[sv];
		for(int i=0;i<edges.length;i++)
		{
			if(edges[sv][i]==1 && !visited[i])
			{
				boolean t=maxGiftshelp(edges,i, fv, visited, record);
				if(t) {
					record[sv]++;
					break;
				}
			}
		}
		if(record[sv]>temp)
		return true;
		return false;
	}
	
	
	
}

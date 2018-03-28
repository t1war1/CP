package Implementation;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Graph {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int e=s.nextInt();
		
		int edges[][]=new int[n][n];
		
		for(int i=0;i<e;i++)
		{
			int fv=s.nextInt();
			int sv=s.nextInt();
			edges[fv][sv]=1; 
			edges[sv][fv]=1;  //undirected graph
		}
		
		printBFS(edges);
		
	}
	
	public static void printDFS(int[][] edges)
	{
		boolean visited[]=new boolean[edges.length];
		for(int i=0;i<visited.length;i++)
		{
			if(!visited[i])
			printHelper(edges, i,visited);
		}
	}
	
	private static void printHelper(int[][] edges,int sv,boolean[] visited) //sv is the starting vertex
	{
		System.out.println(sv);
		visited[sv]=true;
		for(int i=0;i<edges.length;i++)
		{
			if(edges[sv][i]==1 && !visited[i])
			{
				printHelper(edges,i,visited);
			}
		}
		
	}
	
	
	
	private static void printBFShelper(int[][] edges,int sv,boolean visited[])
	{
		Queue<Integer> queue=new LinkedList<>();
		


				queue.add(sv);
				visited[sv]=true;
		
		while(!queue.isEmpty())
		{
			int x=queue.poll(); //current vertex
			System.out.println(x);
			for(int i=0;i<edges.length;i++)
			{
				if(edges[x][i]==1 && !visited[i])
				{
					visited[i]=true;
					queue.add(i);
				}
			}
		}
		}
		
	public static void printBFS(int [][] edges)
	{
		boolean[] visited=new boolean[edges.length];
		for(int i=0;i<visited.length;i++)
		{
			if(!visited[i])
			{
				printBFShelper(edges, i, visited);
			}
		}
		
	}
	
	
	
}

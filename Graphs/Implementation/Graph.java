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
//		printBFS(edges);
		int a =s.nextInt();
		int b=s.nextInt();
		System.out.println(getPath(edges, a, b));
		s.close();
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
	
	public static boolean hasPath(int[][] edges,int sv,int fv)
	{
		boolean visited[]=new boolean[edges.length];
		return hasPathhelper(edges, sv, fv, visited);
	}
	
	private static boolean hasPathhelper(int[][] edges,int sv,int fv,boolean[] visited)
	{
		visited[sv]=true;
		if(edges[sv][fv]==1)
			return true;
		for(int i=0;i<edges.length;i++)
		{
			if(edges[sv][i]==1 && !visited[i])
			{
				if(hasPathhelper(edges, i, fv, visited))
					return true;
			}
		}
		return false;
	}

	
	public static String getPath(int[][] edges,int sv,int fv)
	{
		boolean visited[]=new boolean[edges.length];
		return getPathBFS(edges,sv,fv,visited);
	}

	private static String getPathDFS(int[][] edges, int sv, int fv, boolean[] visited) {
		visited[sv]=true;
		if(sv==fv)
		{
			return ""+sv;
		}
		String smallAns="";
		for(int i=0;i<edges.length;i++)
		{
			if(edges[sv][i]==1 && !visited[i])
			{
				 smallAns=getPathDFS(edges,i,fv,visited);
				if(smallAns!="")
					break;
			}
		}
		if(smallAns!="")
		{
			return smallAns+" "+sv;
		}
		return smallAns;
	}
	
	private static String getPathBFS(int[][] edges,int sv,int fv, boolean [] visited)
	{
		int[] parent=new int[edges.length]; //for mapping on which vertex is put by which vertex in queue 	during BFS
		Queue<Integer> queue=new LinkedList<>();
		queue.add(sv);
		visited[sv]=true;
		String ans="";
		while(!queue.isEmpty())
		{
			int curr=queue.poll();
			if(curr==fv)
				break;
			for(int i=0;i<edges.length;i++)
			{
				if(edges[curr][i]==1 && !visited[i])
				{
					parent[i]=curr;
					visited[i]=true;
					queue.add(i);
				}
			}
		}
		
		int i=fv;
		while(visited[i] && i!=sv) {
			ans=ans+i+" ";
			i=parent[i];
		}
		if(visited[fv])
		return ans+sv;
		return ans;
	}
	
}

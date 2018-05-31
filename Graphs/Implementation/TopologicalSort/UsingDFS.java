package TopologicalSort;

import java.util.*;

public class UsingDFS {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=6;
		int e=6;
		
		Graph g=new Graph(n,e);
		
		g.addEdge(5, 2);
        g.addEdge(5, 0);
        g.addEdge(4, 0);
        g.addEdge(4, 1);
        g.addEdge(2, 3);
        g.addEdge(3, 1);
        
        topologicalSort(g);
	}

	public static void topologicalSort(Graph g) {
		
		Stack<Integer> stack=new Stack<>(); //stack for storing topological sort
		boolean[] visited=new boolean[g.n];
		
		for(int i=0;i<visited.length;i++)
		{
			if(!visited[i]) {
				dfsHelper(g,i,visited,stack);
			}
		}
		
		while(!stack.isEmpty())
		{
			System.out.println(stack.pop());
		}
		
	}

	private static void dfsHelper(Graph g,int i, boolean[] visited, Stack<Integer> stack) {
		visited[i]=true;
		Iterator<Integer> iterator=g.list[i].listIterator();
		
		while(iterator.hasNext()) //first add adjacent vertices to stack
		{
			int j=iterator.next();
			if(!visited[j])
			{
				dfsHelper(g, j, visited, stack);
			}
		}
		
		stack.push(i);//add current vertex
	}

}

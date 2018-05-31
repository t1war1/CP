package TopologicalSort;

import java.util.*;

public class UsingBFS {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
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
		int indegree[]=new int[g.n];
		for(int i=0;i<g.list.length;i++)
		{
			Iterator<Integer> iterator=g.list[i].listIterator();
			
			while(iterator.hasNext()) 
			{
				int j=iterator.next();
				indegree[j]++;
			}
		}
		
		Queue<Integer> queue=new LinkedList<>();
		for(int i=0;i<indegree.length;i++) //add vertices with indegree 0 to queue
		{
			if(indegree[i]==0)
			{
				queue.add(i);
			}
		}
		
		int count=0; //count of visited nodes
		ArrayList<Integer> sort=new ArrayList<>();
		
		while(!queue.isEmpty())
		{
			int currV=queue.poll();
			sort.add(currV);
			count++;
			
			Iterator<Integer> iterator=g.list[currV].listIterator();
			
			while(iterator.hasNext()) 
			{
				int j=iterator.next();
				indegree[j]--;
				if(indegree[j]==0)
				{
					queue.add(j);
				}
			}
		}
		
		if(count!=g.n)
		{
			System.out.println("There is a cycle in the graph");
			return;
		}
		
		for(int i:sort)
		{
			System.out.println(i);
		}
		
	}

}

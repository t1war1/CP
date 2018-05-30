package Implementation;
import java.util.*;
public class UsingAdjacencyList {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int e=s.nextInt();
		GraphAdjList graph=new GraphAdjList(n, e);
		
		for(int i=0;i<e;i++)
		{
			int fv=s.nextInt();
			int sv=s.nextInt();
			graph.addEdge(fv, sv);
			graph.addEdge(sv, fv);
		}
		
		graph.printDFS();
	}

}
class GraphAdjList{
	private int n;
	private int e;
	private LinkedList<Integer> list[];
	
	public GraphAdjList(int n,int e) {
		this.n=n;
		this.e=e;
		list=new LinkedList[n];
		for(int i=0;i<n;i++)
		{
			list[i]=new LinkedList<Integer>();
		}
	}
	
	void addEdge(int i,int j)
	{
		list[i].add(j);
	}
	
	void printDFS()
	{
		boolean visited[]=new boolean[n];
		for(int i=0;i<visited.length;i++)
		{
			if(!visited[i])
			printDFSHelper(i,visited);
		}
		
	}

	private void printDFSHelper(int currentVertex, boolean[] visited) {
		visited[currentVertex]=true;
		System.out.print(currentVertex+" ");
		
		Iterator<Integer> i=list[currentVertex].listIterator();
		while(i.hasNext())
		{
			int j=i.next();
			if(!visited[j])
			{
				printDFSHelper(j, visited);
			}
		}
		
	}
	
}	
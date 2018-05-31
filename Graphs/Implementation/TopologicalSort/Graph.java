package TopologicalSort;

import java.util.*;

public class Graph {
	 int n;
	 int e;
	 LinkedList<Integer> list[];
	
	public Graph(int n,int e) {
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
}

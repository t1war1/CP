package gaga;

import java.util.ArrayList;
import java.util.Scanner;

public class Delete {
	
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		TreeNode root =null;
		TreeNode arr[]=new TreeNode[n];
		for(int i=0;i<n;i++)
		{
			int x=s.nextInt();
			TreeNode node=null;
			if(arr[i]==null)
				node=new TreeNode(i);
			else
				node=arr[i];
			if(x==-1)
				root=node;
			else
			{
				TreeNode parent=null;
				if(arr[x]==null)
				{
					parent=new TreeNode(x);
				}
				else
					parent=arr[x];
				parent.children.add(node);
				arr[x]=parent;
			}
			arr[i]=node;
			
		}
		
		int d=s.nextInt();
		root=deleteTree(root,d);
		System.out.println(countLeafNodes(root));
		
	}
	
	public static TreeNode deleteTree(TreeNode root,int d) {
		
		if(root.data==d)
			return null;
		
		for(int i=0;i<root.children.size();i++)
		{
			TreeNode child=root.children.get(i);
			TreeNode result=deleteTree(child, d);
			if(result!=null)
			root.children.set(i,result);
			else {
				root.children.remove(i);
			}
		}
		
		return root;
	}
	
	public static int countLeafNodes(TreeNode root){

if(root.children.size()==0)
		{
			return 1;
		}
		int count=0;

		for(int i=0;i<root.children.size();i++)
		{
			count+=countLeafNodes(root.children.get(i));
		}
		return count;
	}
	
}
class TreeNode {
	int data;
	ArrayList<TreeNode> children;
	TreeNode(int data){
		this.data = data;
		children = new ArrayList<TreeNode>();
	}
}
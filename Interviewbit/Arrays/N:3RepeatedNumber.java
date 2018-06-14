package rough;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class TreeInVerticalOrder {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BinaryTreeNode<Integer> root=new BinaryTreeNode<>(1);
		root.left=new BinaryTreeNode<>(2);
		root.right=new BinaryTreeNode<>(3);
		root.left.left=new BinaryTreeNode<>(4);
		root.left.left.right=new BinaryTreeNode<>(8);
		root.left.right=new BinaryTreeNode<>(5);
		root.right.left=new BinaryTreeNode<>(6);
		root.right.right=new BinaryTreeNode<>(7);
		printBinaryTreeVerticalOrder(root);
	}
	
	public static void printBinaryTreeVerticalOrder(BinaryTreeNode<Integer> root){
		HashMap<Integer,ArrayList<Integer>> map=new HashMap<>();
		help(root,map,0);
		for(ArrayList<Integer> arr:map.values())
		{
			for(int i:arr)
			{
				System.out.print(i+" ");
			}
			System.out.println();
		}
		
	}
	
	public static void help(BinaryTreeNode<Integer> root,HashMap<Integer,ArrayList<Integer>> map,int distanceFromRoot)
	{
		if(root==null)
			return;
		
		if(!map.containsKey(distanceFromRoot))
		{
			ArrayList<Integer> temp=new ArrayList<>();
			temp.add(root.data);
			map.put(distanceFromRoot, temp);
		}else {
			ArrayList<Integer> temp=map.get(distanceFromRoot);
			temp.add(root.data);
			map.put(distanceFromRoot, temp);
		}
		
		help(root.left,map,distanceFromRoot-1);
		help(root.right,map,distanceFromRoot+1);
	}
}


package rough;

public class PrintNodeAtDistanceK {

	public static void main(String[] args) {
		BinaryTreeNode<Integer> root=new BinaryTreeNode<>(5);
		root.left=new BinaryTreeNode<>(6);
		root.right=new BinaryTreeNode<>(10);
		root.left.left=new BinaryTreeNode<>(2);
		root.left.right=new BinaryTreeNode<>(3);
//		root.left.right.left=new BinaryTreeNode<>(10);
		root.left.right.right=new BinaryTreeNode<>(9);	
		nodesAtDistanceK(root, 3, 1);
		
	}
	public static void nodesAtDistanceK(BinaryTreeNode<Integer> root, int node, int k) {
		
		nodeAtDistanceKhelp(root, node, k);
	}
	 
	private static int nodeAtDistanceKhelp(BinaryTreeNode<Integer> root, int node, int k)
	{
		
		if(root==null)
			return -1;
		
		if(root.data.compareTo(node)==0)
		{
			printDown(root,k);
			return 0;
		}
		
		int distanceLeft=nodeAtDistanceKhelp(root.left, node, k);
		if(distanceLeft!=-1)
		{
			if(distanceLeft+1==k)
			{
				System.out.println(root.data);
			}
			else {
				printDown(root.right,k-distanceLeft-2);
			}
			return distanceLeft+1;
		}
		
		int distanceRight=nodeAtDistanceKhelp(root.right, node, k);
		if(distanceRight!=-1)
		{
			if(distanceRight+1==k)
			{
				System.out.println(root.data);
			}
			else {
				printDown(root.left,k-distanceRight-2);
			}
			return distanceRight+1;
		}
		return -1;
		
	}
	private static void printDown(BinaryTreeNode<Integer> root, int k) {
		if(root==null)
			return;
		if(k==0)
		{
			System.out.println(root.data);
			return;
		}
		printDown(root.left,k-1);
		printDown(root.right,k-1);
	}
}
class BinaryTreeNode<T> {
	T data;
	BinaryTreeNode<T> left;
	BinaryTreeNode<T> right;
	
	public BinaryTreeNode(T data) {
		this.data = data;
	}	
}
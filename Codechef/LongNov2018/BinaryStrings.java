package codeChef.LongNov2018;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
public class BinaryStrings {

	public static void main(String[] args) {
		InputReader s=new InputReader(System.in);
		PrintWriter w=new PrintWriter(System.out);

		int n=s.nextInt();
		int q=s.nextInt();
		Trie trie=new Trie();
		for(int i=1;i<=n;i++)
		{
			String str=s.readString();
			trie.add(str, i);
		}
		
		for(int i=1;i<=q;i++)
		{
			int l=s.nextInt();
			int r=s.nextInt();
			String str=s.readString();
			w.println(trie.find(l,r,str));
		}
		w.close();
	}

	static class Trie{
		TrieNode root;
		Trie()
		{
			root=new TrieNode();
		}

		public void add(String str,int index)
		{
			add(root,32-str.length(),str,index,0);
		}

		private void add(TrieNode root, int zerosLeft, String str, int index,int i) {
			if(zerosLeft>0)
			{
				if(root.nodes[0]==null)
				{
					root.nodes[0]=new TrieNode();
					root.nodes[0].ch='0';
				}
				root.zero.root=root.zero.insert(root.zero.root,index);
				add(root.nodes[0],zerosLeft-1,str,index,i);
			}
			else
			{
				if(i!=str.length())
				{
					char ch=str.charAt(i);
					if(root.nodes[ch-'0']==null)
					{
						root.nodes[ch-'0']=new TrieNode();
						root.nodes[ch-'0'].ch=ch;
					}
					if(ch=='1')
						root.one.root=root.one.insert(root.one.root,index);
					else
						root.zero.root=root.zero.insert(root.zero.root,index);
					add(root.nodes[ch-'0'],zerosLeft,str,index,i+1);
				}
				else
				{
					if(root.end>index)
					root.end=index;
				}
			}
		}

		public int find(int l,int r,String str)
		{
			return find(root,32-str.length(),str,0, l, r);
		}

		private int find(TrieNode root, int zerosLeft, String str, int i, int l, int r) {
			if(zerosLeft>0)
			{
//				System.out.println(root.ch);
				if(root.nodes[1]!=null)
				{
					if(root.one.search(root.one.root, l, r))
					{
						return find(root.nodes[1],zerosLeft-1,str,i,l,r);
					}
				}
				if(root.nodes[0]!=null)
				{
					if(root.zero.search(root.zero.root, l, r))
					{
						return find(root.nodes[0],zerosLeft-1,str,i,l,r);
					}
				}
			}

			if(i!=str.length())
			{
//				System.out.println(root.ch);
				char ch=str.charAt(i);
				if(ch=='0')
				{
					if(root.nodes[1]!=null)
					{
						if(root.one.search(root.one.root, l, r))
						{
							return find(root.nodes[1],zerosLeft,str,i+1,l,r);
						}
					}
					if(root.nodes[0]!=null)
					{
						if(root.zero.search(root.zero.root, l, r))
						{
							return find(root.nodes[0],zerosLeft,str,i+1,l,r);
						}
					}
				}
				else
				{
					if(root.nodes[0]!=null)
					{
						if(root.zero.search(root.zero.root, l, r))
						{
							return find(root.nodes[0],zerosLeft,str,i+1,l,r);
						}
					}
					if(root.nodes[1]!=null)
					{
						if(root.one.search(root.one.root, l, r))
						{
							return find(root.nodes[1],zerosLeft,str,i+1,l,r);
						}
					}
				}
			}
//			System.out.println(root.ch);
			return root.end;

		}


	}

	static class TrieNode
	{
		char ch;
		int end;
		AVLTree zero,one;
		TrieNode nodes[];
		TrieNode()
		{
			end=Integer.MAX_VALUE;
			zero=new AVLTree();
			one=new AVLTree();
			nodes=new TrieNode[2];
		}
	}

	static class Node { 
		int key, height; 
		Node left, right; 

		Node(int d) { 
			key = d; 
			height = 1; 
		} 
	} 

	static class AVLTree { 

		Node root; 

		// A utility function to get the height of the tree 
		int height(Node N) { 
			if (N == null) 
				return 0; 

			return N.height; 
		} 

		// A utility function to get maximum of two integers 
		int max(int a, int b) { 
			return (a > b) ? a : b; 
		} 

		// A utility function to right rotate subtree rooted with y 
		// See the diagram given above. 
		Node rightRotate(Node y) { 
			Node x = y.left; 
			Node T2 = x.right; 

			// Perform rotation 
			x.right = y; 
			y.left = T2; 

			// Update heights 
			y.height = max(height(y.left), height(y.right)) + 1; 
			x.height = max(height(x.left), height(x.right)) + 1; 

			// Return new root 
			return x; 
		} 

		// A utility function to left rotate subtree rooted with x 
		// See the diagram given above. 
		Node leftRotate(Node x) { 
			Node y = x.right; 
			Node T2 = y.left; 

			// Perform rotation 
			y.left = x; 
			x.right = T2; 

			//  Update heights 
			x.height = max(height(x.left), height(x.right)) + 1; 
			y.height = max(height(y.left), height(y.right)) + 1; 

			// Return new root 
			return y; 
		} 

		// Get Balance factor of node N 
		int getBalance(Node N) { 
			if (N == null) 
				return 0; 

			return height(N.left) - height(N.right); 
		} 
		boolean search(Node node,int l,int r)
		{
			if(node==null)
				return false;
			if(node.key>=l && node.key<=r)
			{
				return true;
			}
			if(node.key>r)
			{
				return search(node.left,l,r);
			}
			return search(node.right,l,r);
		}
		Node insert(Node node, int key) { 

			/* 1.  Perform the normal BST insertion */
			if (node == null) 
				return (new Node(key)); 

			if (key < node.key) 
				node.left = insert(node.left, key); 
			else if (key > node.key) 
				node.right = insert(node.right, key); 
			else // Duplicate keys not allowed 
				return node; 

			/* 2. Update height of this ancestor node */
			node.height = 1 + max(height(node.left), 
					height(node.right)); 

			/* 3. Get the balance factor of this ancestor 
	              node to check whether this node became 
	              unbalanced */
			int balance = getBalance(node); 

			// If this node becomes unbalanced, then there 
			// are 4 cases Left Left Case 
			if (balance > 1 && key < node.left.key) 
				return rightRotate(node); 

			// Right Right Case 
			if (balance < -1 && key > node.right.key) 
				return leftRotate(node); 

			// Left Right Case 
			if (balance > 1 && key > node.left.key) { 
				node.left = leftRotate(node.left); 
				return rightRotate(node); 
			} 

			// Right Left Case 
			if (balance < -1 && key < node.right.key) { 
				node.right = rightRotate(node.right); 
				return leftRotate(node); 
			} 

			/* return the (unchanged) node pointer */
			return node; 
		} 

		void preOrder(Node node) { 
			if (node != null) { 
				System.out.print(node.key + " "); 
				preOrder(node.left); 
				preOrder(node.right); 
			} 
		} 

	} 



	static class InputReader {

		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public double nextDouble() //read double
		{
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			double res = 0;
			boolean dec = false;
			int count = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				if (dec)
					count--;
				res *= 10;
				res += c - '0';
				c = snext();
				if (c == '.') {
					if (!dec) {
						dec = true;
						c = snext();
					} else {
						throw new InputMismatchException();
					}
				}
			} while (!isSpaceChar(c));
			res *= Math.pow(10, count);
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}

		public String readString() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public String nextLine() { //considers space in same string
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}

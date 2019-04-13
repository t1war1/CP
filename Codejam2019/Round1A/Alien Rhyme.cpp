// package trial;
import java.io.*;
import java.util.*;

import java.text.*; 
import java.lang.*;

public class Solution {

	static PrintWriter out=new PrintWriter(new OutputStreamWriter(System.out));		
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main (String[] args) throws Exception {

		String st[]=br.readLine().split(" ");
		int t=Integer.parseInt(st[0]);
		for(int x=1;x<=t;x++)
		{
			st=br.readLine().split(" ");
			int n=Integer.parseInt(st[0]);
			Trie trie=new Trie();
			for(int i=0;i<n;i++)
			{
				st=br.readLine().split(" ");
				trie.addWord(st[0]);
			}
			int size=0;
			for(Map.Entry<Character, TrieNode> entry:trie.root.children.entrySet())
			{
				size+=trie.findPairs(entry.getValue());
			}
			out.println("Case #"+x+": "+size);
		}
		
			
		out.flush();
		out.close();
    }
	

	public static void debug(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
}
class TrieNode {
	char ch;
	HashMap<Character,TrieNode> children;
	int noOfWords;
	
	TrieNode(char ch)
	{
		noOfWords=0;
		children=new HashMap<>();
		this.ch=ch;
	}
}
class Trie {
	TrieNode root;
	
	Trie()
	{
		root=new TrieNode('/');
	}
	
	public void addWord(String word)
	{
		addWord(root,word);
	}

	private void addWord(TrieNode root, String word) {
		if(word.length()==0)
		{
			root.noOfWords++;
			return ;
		}
		
		char currChar=word.charAt(word.length()-1);
		if(!root.children.containsKey(currChar))
		{
			TrieNode newNode=new TrieNode(currChar);
			root.children.put(currChar, newNode);
		}
		addWord(root.children.get(currChar),word.substring(0,word.length()-1));
		root.noOfWords++;
		
	}
	
	public int findPairs(TrieNode root)
	{
		int no=root.noOfWords,ans=0;
		for(Map.Entry<Character, TrieNode> entry:root.children.entrySet())
		{
			int x=findPairs(entry.getValue());
			if(x>0)
			{
				no-=x;
				ans+=x;
			}
		}
		if(no>=2)
			ans+=2;
		return ans;
	}
	
}

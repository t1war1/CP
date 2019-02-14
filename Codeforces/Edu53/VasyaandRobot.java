package codeforces.Edu53;
import java.util.*;
import java.io.*;
public class VasyaandRobot {

	public static void main(String[] args) {
		InputReader s=new InputReader(System.in);
		PrintWriter w=new PrintWriter(System.out);
		int n=s.nextInt();
		String str=s.readString();
		int x=s.nextInt();
		int y=s.nextInt();
		
		if((Math.abs(x)+Math.abs(y))>n || (Math.abs(x)+Math.abs(y))%2!=n%2)
		{
			w.println(-1);
		}
		else 
		{
		int low=0,high=n,ans=n;
		while(low<=high)
		{
			int mid=(low+high)/2;
			if(isValid(mid,str,n,x,y))
			{
				ans=Math.min(ans, mid);
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		w.println(ans);
		}
		w.close();

	}
	
	public static boolean isValid(int length, String str,int n,int x,int y)
	{
		Pair p=new Pair(0,0);
		for(int i=length;i<n;i++)
		{
			change(p,str.charAt(i),1);
		}
		for(int i=0;i+length<=n;i++)
		{
			int dis=Math.abs(x-p.x)+Math.abs(y-p.y);
			if(dis%2==length%2 & dis<=length)
				return true;
			if(i+length>=n)
			{
				break;
			}
			change(p,str.charAt(i),1);
			change(p,str.charAt(i+length),-1);
		}
		return false;
	}
	
	public static void change(Pair p,char ch,int op)
	{
		if(ch=='L')
		{
			p.x-=op;
		}
		else if(ch=='R')
		{
			p.x+=op;
		}
		else if(ch=='U')
		{
			p.y+=op;
		}
		else
		{
			p.y-=op;
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
	
	static class Pair{
		int x,y;
		Pair(int x,int y)
		{
			this.x=x;this.y=y;
		}
	}
}

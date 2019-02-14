package codeChef.LongNov2018;
import java.util.*;
import java.io.*;
public class ChefandHappiness {

	public static void main(String[] args) {
		InputReader s=new InputReader(System.in);
		PrintWriter w=new PrintWriter(System.out);
		int t=s.nextInt();
		while(t--!=0)
		{
			int n=s.nextInt();
			Pair arr[]=new Pair[n+1];
			HashSet<Integer> set=new HashSet<>();
			for(int i=1;i<=n;i++)
			{
				int num=s.nextInt();
				arr[i]=new Pair(num,i);
				set.add(num);
			}
			Arrays.sort(arr, 1, n+1,new PairCompare());
			if(find(n,arr,set))
			{
				w.println("Truly Happy");
			}
			else
			{
				w.println("Poor Chef");
			}
		}
		w.close();
	}
	private static boolean find(int n, Pair[] arr, HashSet<Integer> set) {
		int a=0,b=0;
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				a=arr[i].index;
				if(!set.contains(a))
					a=-1;
				continue;
			}
			else
			{
				if(arr[i].num==arr[i-1].num)
				{
					if(a!=-1)
					{
						b=arr[i].index;
						if(!set.contains(b))
						{
							b=-1;continue;
						}
						else
						{
							return true;
						}
					}
					else
					{
						a=arr[i].index;
						if(!set.contains(arr[i].index))
							a=-1;
					}
				}
				else
				{
					a=arr[i].index;
					if(!set.contains(a))
						a=-1;
				}
			}
		}
		return false;
	}
	
	static class Pair
	{
		int num,index;
		Pair(int num,int index)
		{
			this.num=num;
			this.index=index;
		}
	}
	
	static class PairCompare implements Comparator<Pair>
	{

		@Override
		public int compare(Pair o1, Pair o2) {
			return o1.num>o2.num?1:o1.num<o2.num?-1:0;
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

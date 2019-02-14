package codeforces.Edu53;	
import java.util.*;
import java.io.*;
public class BerlandFair {

	public static void main(String[] args) {
		InputReader s=new InputReader(System.in);
		PrintWriter w=new PrintWriter(System.out);
		int n=s.nextInt();
		long t=s.nextLong();
		int arr[]=new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=s.nextInt();
		}
		long count=0;
		while(t>0)
		{
			long t1=t;
			long sum=0;
			int countcurr=0;
			for(int i=0;i<n;i++)
			{
				if(t1==0)
				{
					break;
				}
				if(t1>=arr[i])
				{
					sum+=arr[i];
					t1-=arr[i];
					countcurr++;
				}
			}
			if(countcurr==0)
			{
				break;
			}
			long temp=t/sum;
			count+=temp*countcurr;
			t=t%sum;
		}
		w.println(count);
		w.close();
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

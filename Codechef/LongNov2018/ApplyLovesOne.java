package codeChef.LongNov2018;
import java.util.*;
import java.io.*;
public class ApplyLovesOne {

	public static void main(String[] args) {
		InputReader s=new InputReader(System.in);
		PrintWriter w=new PrintWriter(System.out);
		int n=s.nextInt();
		int q=s.nextInt();
		int k=s.nextInt();
		int arr[]=new int[n];
		int check0=0;
		for(int i=0;i<n;i++)
		{
			arr[i]=s.nextInt();
			if(arr[i]==0)
				check0=1;
		}
		String str=s.readString();
		int begCount=0,beg1=-1,end1=-1;
		for(;begCount<n && arr[begCount]!=0;begCount++);
		if(begCount!=0)
		{
			beg1=0;end1=begCount-1;
		}
		int endCount=0,beg2=-1,end2=-1,i=n-1;
		for( ;i>=0 && arr[i]!=0;i--)
		{
			endCount++;
		}
		if(endCount!=0)
		{
			beg2=i+1;end2=n-1;
		}

		int betCount=0,beg3=-1,end3=-1,count=0,maxBet=Integer.MIN_VALUE,indbeg=-1,indend=-1;
		for(i=begCount;i<n-endCount;i++)
		{
			if(arr[i]==1)
			{
				if(count==0)
				{
					beg3=i;
					count++;
				}
				else
				{
					count++;
				}
			}
			else
			{
				if(count>0)
				{
					end3=i-1;
					if(count>maxBet)
					{
						indbeg=beg3;indend=end3;
						maxBet=count;
					}
					count=0;beg3=-1;end3=-1;
				}
			}
		}
		betCount=maxBet;beg3=indbeg;end3=indend;
		count=0;
		int smaxCount=0,beg4=-1,end4=-1,smax=Integer.MIN_VALUE,smaxbeg=-1,smaxend=-1;
		for(i=begCount;i<n-endCount;i++)
		{
			if(arr[i]==1)
			{
				if(count==0)
				{
					beg4=i;
					count++;
				}
				else
				{
					count++;
				}
			}
			else
			{
				if(count>0)
				{
					end4=i-1;
					if(count>smax && count<=betCount && beg4!=beg3)
					{
						smaxbeg=beg4;smaxend=end4;
						smax=count;
					}
					count=0;beg4=-1;end4=-1;
				}
			}
		}
		smaxCount=smax;beg4=smaxbeg;end4=smaxend;
		if(endCount!=0)
		{
			beg1=beg2;
			end1=n+end1;begCount+=endCount;
		}
		HashMap<Integer,Integer> map=new HashMap<>();int flag1=0,flag2=0;
		if(begCount>betCount)
		{
			if(arr[0]==1 && arr[n-1]==1)
				flag1=1;
			smax=maxBet;
			smaxbeg=indbeg;smaxend=indend;
			maxBet=begCount;
			indbeg=beg1;indend=end1;
		}
		else if(begCount>smax && begCount<=maxBet)
		{
			if(arr[0]==1)
				flag2=1;
			smax=begCount;
			smaxbeg=beg1;smaxend=end1;
		}

		int shift=0;
		for(i=0;i<str.length();i++)
		{
			char ch=str.charAt(i);
			if(ch=='!')
			{
				shift--;
				if(shift==-1)
					shift=n-1;
			}
			else
			{
				if(check0==0)
				{
					w.println(Math.min(k, n));
					continue;
				}
				if(map.containsKey(shift))
				{
					w.println(map.get(shift));
					continue;
				}

				if(flag1==1)
				{
					if(shift>=(indbeg%n))
					{
						int temp=n-shift+(indend%n)+1;
						temp=Math.max(temp,Math.max(shift-(indbeg%n), smax));
						temp=Math.min(temp,k);
						map.put(shift, temp);
						System.out.println(temp);continue;
					}
					else if(shift<=(indend%n))
					{
						int temp=(indend%n)-shift+1;
						temp=Math.max(temp, Math.max(smax,shift+n-(indbeg%n)));
						temp=Math.min(temp, k);
						map.put(shift, temp);
						System.out.println(temp);
						continue;
					}	
				}
				else
				{
					if((shift>=indbeg%n) && (shift<=indend%n))
					{
						int temp=(indend%n)-shift+1;
						temp=Math.max(temp, Math.max(shift-(indbeg%n),smax));
						temp=Math.min(temp, k);
						map.put(shift, temp);
						System.out.println(temp);
						continue;
					}

				}
				int temp=Math.min(maxBet, k);
				map.put(shift, temp);
				System.out.println(temp);
			}
		}


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

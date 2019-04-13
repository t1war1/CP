import java.io.*;
import java.util.*;
import java.text.*; 
import java.lang.*;
import java.math.*;

public class Solution{
    static PrintWriter out=new PrintWriter(new OutputStreamWriter(System.out));        
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n=0,m=0,visited=0;
    static boolean vis[][];
    static Deque<Integer> list;
    static boolean dfs(int start,int end){
        vis[start][end]=true;
        list.add(start);
        list.add(end);
        
        if(list.size()==2*n*m){
            vis[start][end]=false;
            return true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i!=start&&j!=end&&i-j!=start-end&&i+j!=start+end&&!vis[i][j]){
                    if(dfs(i,j)){
                        vis[start][end]=false;
                        return true;
                    }
                }
            }
        }
        vis[start][end]=false;
        list.pollLast();
        list.pollLast();
        return false;
    }
    public static void main (String[] args) throws Exception {
        String st[]=br.readLine().split(" ");
        int t=Integer.parseInt(st[0]);
        int tc=0;
        while(t-->0){
            st=br.readLine().split(" ");
            n=Integer.parseInt(st[0]);
            m=Integer.parseInt(st[1]);
            tc++;
            out.print("Case #"+tc+": ");
            list=new ArrayDeque<>();
            vis=new boolean[n+1][m+1];
            boolean flag=false;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(dfs(i,j)){
                        out.println("POSSIBLE");
                        while(!list.isEmpty()){
                            out.println(list.pollFirst()+" "+list.pollFirst());
                        }
                        flag=true;
                        break;
                    }
                }
                if(flag)break;
            }
            if(!flag){
                out.println("IMPOSSIBLE");
            }
        }
        out.flush();
        out.close();
    }


}
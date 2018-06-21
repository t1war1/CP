public class Solution {
    public ArrayList<String> prettyJSON(String A) {
        ArrayList<String> ans=new ArrayList<>();
        String temp="";int indent=0;
        for(int i=0;i<A.length();i++)
        {
            char ch=A.charAt(i);
            if(ch=='{' || ch=='[')
            {
                if(!temp.equals(""))
                {
                    ans.add(temp);
                    temp="";
                }
                for(int j=0;j<indent;j++)
                {
                    temp+='\t';
                }
                temp+=ch;
                ans.add(temp);
                temp="";
                indent++;
            }
            else if(ch=='}' || ch==']')
            {
               if(!temp.equals(""))
                ans.add(temp);
                indent--;
                temp="";
                for(int j=0;j<indent;j++)
                {
                    temp+='\t';
                }
                temp+=ch;
                if(i<A.length()-1)
                {
                if(A.charAt(i+1)==',')
                {
                    temp+=',';
                    i++;
                }
                }
                ans.add(temp);
                temp="";
            }
            else
            {
                if(ch==' ')
                    continue;
                if(temp.equals(""))
                {
                    for(int j=0;j<indent;j++)
                    {
                        temp+='\t';
                    }
                }
                temp+=ch;
                if(ch==',')
                {
                    ans.add(temp);
                    temp="";
                }
            }
        }
        return ans;
    }
}

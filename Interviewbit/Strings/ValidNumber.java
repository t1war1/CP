public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int isNumber(final String a) {
        
       if(a == null || a.length() == 0 || a.charAt(a.length()-1) == '.' )
            return 0;
        int i = 0;
        int dot = 0;
        int e = 0;
        int num = 0;
        char temp = a.charAt(i);
        if(temp == '+' || temp == '-' || temp == ' ')
            i++;
        while(i < a.length()){
            temp = a.charAt(i);
            if((temp >= '0' && temp <= '9') ){
                num++;                
            }
            else if(temp == '+' || temp == '-'|| temp == ' '){
                
            }
            else if(temp == '.' && i < a.length()-1 && (a.charAt(i+1) >= '0' && a.charAt(i+1) <= '9')){
                if(e > 0)
                    return 0;
                else
                    dot++;
            }
            else if(temp == 'e'){
                e++;
            }            
            else
                return 0;
            i++;
        }

        if(num < 1) return 0;
        if(dot > 1 || e > 1) return 0;
        
        return 1;
        
    }
}

package rough;

public class SmallestSubstring {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str = "Looks for minimum string";
        String pat = "mums";
      
       System.out.print("Smallest window is :" +
                        findSubString(str, pat));
	}
    
    static String findSubString(String str, String pat)
    {
        int len1 = str.length();
        int len2 = pat.length();
      
        if (len1 < len2)
        {
            System.out.println("No such window exists");
            return "";
        }
      
        int arr1[] = new int[256];
        int arr2[] = new int[256];
      
        for (int i = 0; i < len2; i++)
            arr2[pat.charAt(i)]++;
      
        int start = 0, start_index = -1, length = Integer.MAX_VALUE;
        int count = 0;  
        for (int j = 0; j < len1 ; j++)
        {
            arr1[str.charAt(j)]++;

            if (arr2[str.charAt(j)] != 0 &&
                arr1[str.charAt(j)] <= arr2[str.charAt(j)] )
                count++;
      
            if (count == len2)
            {

                while ( arr1[str.charAt(start)] > arr2[str.charAt(start)]
                       || arr2[str.charAt(start)] == 0)
                {
      
                    if (arr1[str.charAt(start)] >arr2[str.charAt(start)])
                        arr1[str.charAt(start)]--;
                    start++;
                }
      
                int len_window = j - start + 1;
                if (length > len_window)
                {
                    length = len_window;
                    start_index = start;
                }
            }
        }
      
        if (start_index == -1)
        {
           System.out.println("No such window exists");
           return "";
        }

        return str.substring(start_index, start_index + length);
    }
    
}

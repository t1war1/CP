public class Solution {
    public int firstMissingPositive(ArrayList<Integer> A) {
         int len = A.size();
        for (int i = 0; i < len; i++) {
            while (A.get(i) != (i + 1) || A.get(i) <= 0) {
                int num = A.get(i);
                int targetIndex = num - 1;
                if ((targetIndex < 0 || targetIndex >= len) || num == A.get(num - 1)) {
                    break;
                }
                A.set(i, A.get(num - 1));
                A.set(num - 1, num);
            }
        }
        for (int i = 0; i < len ; i++) {
            if (A.get(i) != i + 1) {
                return i + 1;
            }
        }
        return len + 1;
    }
}

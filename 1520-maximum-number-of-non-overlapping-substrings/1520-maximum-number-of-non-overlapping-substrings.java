import java.util.*;

class Solution {
    public List<String> maxNumOfSubstrings(String s) {
        int n = s.length();
        int[] first = new int[26];
        int[] last = new int[26];
        Arrays.fill(first, -1);
        
        for (int i = 0; i < n; i++) {
            int c = s.charAt(i) - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        
        List<int[]> intervals = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            int c = s.charAt(i) - 'a';
            if (first[c] != i) continue; // only start from first occurrence
            
            int start = i;
            int end = last[c];
            boolean valid = true;
            
            int j = start;
            while (j <= end) {
                int cj = s.charAt(j) - 'a';
                if (first[cj] < start) {
                    valid = false;
                    break;
                }
                end = Math.max(end, last[cj]);
                j++;
            }
            
            if (valid) {
                intervals.add(new int[]{start, end});
            }
        }
        
        // Greedy: sort by end index, pick non-overlapping
        intervals.sort((a, b) -> a[1] - b[1]);
        
        List<String> result = new ArrayList<>();
        int prevEnd = -1;
        
        for (int[] iv : intervals) {
            if (iv[0] > prevEnd) {
                result.add(s.substring(iv[0], iv[1] + 1));
                prevEnd = iv[1];
            }
        }
        
        return result;
    }
}
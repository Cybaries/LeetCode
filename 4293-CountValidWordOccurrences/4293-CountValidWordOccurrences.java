// Last updated: 11/05/2026, 01:29:51
import java.util.*;
import java.util.regex.*;

class Solution {
    public int[] countWordOccurrences(String[] chunks, String[] queries) {
        StringBuilder sb = new StringBuilder();
        for (String chunk : chunks) {
            sb.append(chunk);
        }
        String s = sb.toString();

        Map<String, Integer> freq = new HashMap<>();
        Matcher matcher = Pattern.compile("[a-z]+(-[a-z]+)*").matcher(s);

        while (matcher.find()) {
            String word = matcher.group();
            freq.merge(word, 1, Integer::sum);
        }

        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            ans[i] = freq.getOrDefault(queries[i], 0);
        }

        return ans;
    }
}
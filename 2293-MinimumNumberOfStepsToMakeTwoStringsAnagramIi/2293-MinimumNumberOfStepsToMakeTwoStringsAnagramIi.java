// Last updated: 11/05/2026, 01:30:53
class Solution {
    public int minSteps(String s, String t) {
        int[] arr = new int[26];
        // for(int i = 0; i < 26; i++){
        //     arr[i]= 0;
        // }
        int count = 0;
        for (int i  = 0; i < s.length(); i++){
            arr[s.charAt(i)-'a']++;
        }
        for (int i  = 0; i < t.length(); i++){
            if (arr[t.charAt(i)-'a'] == 0){
                count++;
                continue;
            }
            arr[t.charAt(i)-'a']--;
        }
        for(int i = 0; i < 26; i++){
            count += arr[i];
         }
        return count;
    }
}
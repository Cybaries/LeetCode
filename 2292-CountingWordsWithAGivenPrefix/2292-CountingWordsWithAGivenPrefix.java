// Last updated: 11/05/2026, 01:30:55
class Solution {
    public int prefixCount(String[] words, String pref) {
        int l = pref.length();
        int count = 0;
        for(int i = 0; i < words.length; i++)
            if(words[i].length() >= l){
                String str = words[i].substring(0,l);
                if (str.equals(pref))
                count++;
            }
        
        return count;
    }
}
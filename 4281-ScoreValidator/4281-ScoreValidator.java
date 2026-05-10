// Last updated: 11/05/2026, 01:29:57
class Solution {
    public int[] scoreValidator(String[] events) {
        int[] ans = new int[2];
        for (String var: events){
            if (ans[1] == 10) return ans;
            if (var.equals("W")){
                ans[1]++;
            }
            else if (var.equals("WD") || var.equals("NB")){
                ans[0]++;
            }
            else{
                ans[0] += Integer.parseInt(var);
            }
        }
        return ans;
    }
}
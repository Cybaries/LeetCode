// Last updated: 11/05/2026, 01:31:25
class Solution {
    public String capitalizeTitle(String title) {
        String[] arr = title.split(" ");
        String s="";
        for (int i = 0; i < arr.length; i++) {
            String str = "";
            if (arr[i].length() <= 2) {
                str += arr[i].toLowerCase();
            }
            else {
                // System.out.println((char) (arr[i].charAt(0) - 'a' + 'A'));
                if (arr[i].charAt(0) >= 97)
                    str += (char) (arr[i].charAt(0) - 'a' + 'A');
                else
                    str += arr[i].charAt(0);
                str += arr[i].substring(1).toLowerCase();
            }
            if (i < arr.length-1)
                s += str + " ";
            else
                s += str;
        }
        return s;
    }
}
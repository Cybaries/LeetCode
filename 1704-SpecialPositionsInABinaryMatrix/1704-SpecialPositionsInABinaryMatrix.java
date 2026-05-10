// Last updated: 11/05/2026, 01:31:41
class Solution {
    public int numSpecial(int[][] mat) {
        int cnt = 0;
        int [] col = new int[mat[0].length];
        int [] row = new int[mat.length];
        for (int i = 0; i < mat.length; i++){
            for (int j = 0; j < mat[0].length; j++){
                if (mat[i][j] == 1){
                    col[j]++;
                    row[i]++;
                }
            }
        }
        for (int i = 0; i < mat.length; i++){
            for (int j = 0; j < mat[0].length; j++){
                if (mat[i][j] == 1){
                   
                    if (col[j] == 1 && row[i] == 1)
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
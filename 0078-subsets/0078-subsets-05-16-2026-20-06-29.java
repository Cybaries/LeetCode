class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int num: nums){
            s.add(num);
        }
        List<Integer> li = new ArrayList<>(s);
        int n = li.size();
        List<List<Integer>> l = new ArrayList<>();
        for (int mask = 0; mask < (1 << n); mask++){
            List<Integer> temp = new ArrayList<>();
            for (int i = 0; i < n; i++){
                if ((mask & (1 << i)) != 0){
                    temp.add(li.get(i));
                }
            }
            l.add(temp);
        }
        return l;
    }
}
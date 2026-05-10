// Last updated: 11/05/2026, 01:30:46
class Solution {
    public int mostFrequent(int[] nums, int key) {
        HashMap<Integer, Integer> hashmap = new HashMap<>(10);
        for(int i = 0; i < nums.length-1; i++){
            if(nums[i] == key){
                if(hashmap.containsKey(nums[i+1])){
                    hashmap.put(nums[i+1], hashmap.get(nums[i+1])+1);
                }
                else{
                    hashmap.put(nums[i+1], 1);
                }
            }
        }
        int n = 0; int m = 0;
        for(var entry : hashmap.entrySet()){
            if(entry.getValue()>n){
                n = entry.getValue();
                m = entry.getKey();
            }
        }
        return m;
    }
}
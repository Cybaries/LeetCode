# Last updated: 11/05/2026, 01:31:34
class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        count=0
        for i in range(0,len(nums)):
            for j in range(i,len(nums)):
                if abs(nums[j]-nums[i])==k:
                    print(nums[j],nums[i], sep=" ")
                    print(abs(nums[j]-nums[i]), end=" ")
                    count+=1
           
        return count
        
# Last updated: 11/05/2026, 01:31:35
class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        nums=[0]+nums+[0]
        for i in range(1,len(nums)-1):
            if sum(nums[:i])==sum(nums[i+1:]):
                return i-1
        return -1
        
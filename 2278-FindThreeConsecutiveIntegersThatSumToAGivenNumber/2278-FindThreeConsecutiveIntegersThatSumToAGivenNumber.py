# Last updated: 11/05/2026, 01:31:04
class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        l = []
        if (num % 3 == 0):
            l.append(num//3-1)
            l.append(num//3)
            l.append(num//3+1)
        return l
            
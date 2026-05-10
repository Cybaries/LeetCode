# Last updated: 11/05/2026, 01:31:27
class Solution(object):
    def numberOfArrays(self, differences, lower, upper):
        """
        :type differences: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        lo, up = lower, upper
        for diff in differences:
            lo, up = max(lower, lo + diff), min(upper, up + diff)
            if lo > upper or up < lower: return 0

        return up - lo + 1
        
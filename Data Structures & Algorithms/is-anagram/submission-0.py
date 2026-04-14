class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sorted_S = sorted(s)
        sorted_T = sorted(t)
        return sorted_S == sorted_T


        
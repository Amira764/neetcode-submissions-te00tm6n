class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(len(nums)):
            n = 1
            for j in range (len(nums)):
                if i != j:
                    n *= nums[j]
            res.append(n)
        return res

        
class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        list_len = len(nums)
        set_nums = set(nums)
        set_len = len(set_nums)
        return list_len != set_len
        
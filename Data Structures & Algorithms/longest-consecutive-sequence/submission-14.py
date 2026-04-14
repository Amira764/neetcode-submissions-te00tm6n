class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        store = set(nums)

        # iterate over store to automatically skip duplicates
        for num in store:
            # this is a start of a sequence
            if num - 1 not in store:
                current_length, current_num = 0, num

                while current_num in store:
                    current_length += 1
                    current_num += 1
            
                res = max(res, current_length)

        return res
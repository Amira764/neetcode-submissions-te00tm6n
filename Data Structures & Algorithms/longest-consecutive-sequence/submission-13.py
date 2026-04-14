class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        if len(nums) == 0:
            return 0

        nums.sort()
        biggest_count = 1
        current_count = 1

        for i in range(len(nums)-1):
            # same number: skip
            if nums[i+1] == nums[i]:
                continue
            # consequetive: increment count
            if nums[i+1] == nums[i] + 1:
                current_count += 1
                continue
            # does not fit sequence: reset counter
            if current_count > biggest_count:
                biggest_count = current_count
            # reset counter
            current_count = 1

        # if the last element incremented the count
        if current_count > biggest_count:
            biggest_count = current_count

        return biggest_count


        
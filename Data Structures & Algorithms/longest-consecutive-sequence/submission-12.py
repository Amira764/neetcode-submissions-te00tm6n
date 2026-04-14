class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        nums.sort()
        biggest_count = 1
        current_count = 1
        print(nums)
        for i in range(len(nums)-1):
            if nums[i+1] == nums[i]:
                continue
            if nums[i+1] == nums[i] + 1:
                current_count += 1
                print(i, nums[i+1], current_count)
                continue
            if current_count > biggest_count:
                biggest_count = current_count
            current_count = 1
        if current_count > biggest_count:
            biggest_count = current_count

        return biggest_count


        
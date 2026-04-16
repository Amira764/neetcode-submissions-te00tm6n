class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        current = -nums[0]
        if current == 0:
            current = -1
        ans = set()
        for i in range(len(nums)):
            if nums[i] == current:
                continue
            current = nums[i]

            left_index = i+1
            right_index = len(nums) - 1
            while left_index < right_index:
                current_sum = current + nums[right_index] + nums[left_index]
                if current_sum == 0:
                    ans.add(tuple(sorted([current, nums[right_index], nums[left_index]])))
                    left_index +=1
                    continue
                if current_sum > 0:
                    right_index -= 1
                if current_sum < 0:
                    left_index += 1
        return list(ans)
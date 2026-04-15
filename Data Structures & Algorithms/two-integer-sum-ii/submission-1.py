class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # If the sum is too small, 
        # we move the left pointer 
        # forward to get a larger number.

        # If the sum is too large, 
        # we move the right pointer 
        # backward to get a smaller number.
        left_index = 0
        right_index = len(numbers) - 1
        while right_index > left_index:
            current_sum = numbers[right_index] + numbers[left_index]
            if current_sum == target and numbers[right_index] != numbers[left_index]:
                return [left_index+1, right_index+1]
            if current_sum > target:
                right_index -= 1
            if current_sum < target:
                left_index += 1

        
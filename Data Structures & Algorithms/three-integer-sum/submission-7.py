from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()  # Sort the array to enable the two-pointer technique
        ans = []

        for i in range(len(nums)):
            # 1. Skip duplicate elements for the outer loop
            # This ensures we don't start a new triplet with the same number twice.
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            # 2. Set up the two pointers
            left = i + 1
            right = len(nums) - 1
            
            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]
                
                if current_sum == 0:
                    # Match found!
                    ans.append([nums[i], nums[left], nums[right]])
                    
                    # Move both pointers inwards to search for other combinations
                    left += 1
                    right -= 1
                    
                    # 3. Skip duplicates for the left pointer
                    # This prevents recording the exact same triplet again if the array has repeats
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                        
                elif current_sum < 0:
                    # If the sum is too small, move the left pointer right to increase the sum
                    left += 1
                else:
                    # If the sum is too large, move the right pointer left to decrease the sum
                    right -= 1
                    
        return ans
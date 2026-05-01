class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int a = 0; a < n - 3; a++)
        {
            // Skip duplicate for 'a'
            if (a > 0 && nums[a] == nums[a - 1]) continue;

            for (int b = a + 1; b < n - 2; b++)
            {
                // Skip duplicate for 'b'
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;

                // Two Pointers for 'c' and 'd'
                int left = b + 1;
                int right = n - 1;

                while (left < right)
                {
                    // Using long long to prevent overflow during addition
                    long long sum = (long long)nums[a] + nums[b] + nums[left] + nums[right];

                    if (sum == target)
                    {
                        result.push_back({nums[a], nums[b], nums[left], nums[right]});
                        
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } 
                    else if (sum < target) left++;
                    else right--;
                }
            }
        }
        return result;
    }
};
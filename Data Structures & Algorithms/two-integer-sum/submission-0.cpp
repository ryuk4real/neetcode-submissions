class Solution
{
   public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> solution = {0, 1};

        for (unsigned int i = 0; i < nums.size(); ++i)
        {
            for (unsigned int j = 0; j < nums.size(); ++j)
            {
                if ((i != j) && (nums[i] + nums[j]) == target)
                {
                    solution[0] = i;
                    solution[1] = j;
                    return solution;
                }
                    
            }
        }
        return solution;
    }
};

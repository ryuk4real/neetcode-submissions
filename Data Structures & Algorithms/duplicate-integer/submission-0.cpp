#include<unordered_map>

class Solution
{
    public:
        bool hasDuplicate(vector<int>& nums)
        {
            std::unordered_map<int, int> mymap;

            for(unsigned int i = 0; i < nums.size(); ++i)
            {
                if (!mymap.contains(nums[i]))
                {
                    mymap.insert({nums[i], i});
                }
                else
                {
                    return true;
                }
            }

            return false;
        }
};
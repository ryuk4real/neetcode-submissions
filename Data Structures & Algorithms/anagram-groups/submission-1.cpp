#include <unordered_map>

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        // store sorted string and array index
        unordered_map<string, unsigned int> anagrams;

        vector<vector<string>> solution = {};
        unsigned int index = 0;

        for (unsigned short i = 0; i < strs.size(); ++i)
        {
            string sorted = strs[i];
            std::sort(sorted.begin(), sorted.end());

            if (anagrams.contains(sorted))
            {
                solution[anagrams[sorted]].push_back(strs[i]);
            }
            else
            {
                anagrams[sorted] = index;
                solution.push_back({strs[i]});
                ++index;
            }

        }

        return solution;
    }
};

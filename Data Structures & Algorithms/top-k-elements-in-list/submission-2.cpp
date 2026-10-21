#include <unordered_map>

#define DUMMY 9999

class Solution
{
    public:
        vector<int> topKFrequent(vector<int>& nums, int k)
        {
            vector<int> top_k (k, DUMMY);
            unordered_map<int, int> occurrences;

            // count all the frequencies
            for (auto element : nums)
            {
                occurrences[element]++;
            }

            // Sort the map from the most frequent element of nums to lowest
            for (auto & [key, freq] : occurrences)
            {
                update_top_k(key, top_k, occurrences, k);
            }

            return top_k;
        }

        void update_top_k(int n, vector<int> & v, unordered_map<int, int> & occurrences, int & k)
        {
            if (v[k - 1] != DUMMY && occurrences[n] <= occurrences[v[k - 1]])
            {
                return;
            }

            for (int i = 0; i < k; ++i)
            {
                if (v[i] == DUMMY)
                {
                    v[i] = n;
                    return;
                }

                if (occurrences[v[i]] <= occurrences[n])
                {
                    int temp = v[i];
                    v[i] = n;
                    n = temp;
                }
            }
        }
};

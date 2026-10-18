#include <unordered_map>

class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            if (s.length() != t.length()) return false;

            unordered_map<char, short> my_map;

            for(unsigned short i = 0; i < s.length(); ++i)
            {
                if(!my_map.contains(s[i]))
                {
                    my_map.insert({s[i], 1});
                }
                else
                {
                    my_map.at(s[i]) += 1;
                }


                if(!my_map.contains(t[i]))
                {
                    my_map.insert({t[i], -1});
                }
                else
                {
                    my_map.at(t[i]) -= 1;
                }
            }

            for(const auto& [key, value]: my_map)
            {
                if (value != 0) return false;
            }

            return true;
        }
};

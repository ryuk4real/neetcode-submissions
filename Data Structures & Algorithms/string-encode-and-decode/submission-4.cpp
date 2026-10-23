class Solution
{
    public:

        const char delimiter = '#';

        string encode(vector<string>& strs)
        {
            std::string s;

            for (unsigned int i = 0; i < strs.size(); ++i)
            {
                s.append(std::to_string(strs[i].size())); // add the length of the string
                s.push_back(delimiter); // add the string delimiter #
                s.append(strs[i]); // add the string
            }

            return s;
        }

        vector<string> decode(string s)
        {
            vector<string> strs;
            bool is_reading_digits = true;
            string digits = "";
            unsigned int index = 0;

            while (index < s.length() || !is_reading_digits)
            {
                if (!is_reading_digits)
                {
                    int len = std::stoi(digits);
                    strs.push_back(s.substr(index, len));
                    index += len;
                    digits.clear();
                    is_reading_digits = true;
                }
                else
                {
                    if (s[index] == delimiter)
                    {
                        is_reading_digits = false;
                    }
                    else
                    {
                        digits.push_back(s[index]);
                    }
                    ++index;
                }
            }

            return strs;
        }
};

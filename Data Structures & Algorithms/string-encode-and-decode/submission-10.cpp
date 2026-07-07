class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string{};

        for (int i=0; i<strs.size(); i++)
        {
            encoded_string += (to_string(strs[i].size()) + '#' + strs[i]);
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strings{};
        int index = 0;

        while (index < s.size())
        {
            int pos = s.find('#', index);
            string str_size = s.substr(index, pos - index);
            int size = stoi(str_size);

            index = pos + 1;

            decoded_strings.push_back(s.substr(index, size));

            index += size;
        }

        return decoded_strings;
    }
};

class Solution {
public:

    string encode(vector<string>& strs) 
    {
        //Add string length and # right in front of it
        string s = "";
        for(string word : strs)
        {
            s += to_string(word.size())+"#"+word;
        }
        return s;
    }
    vector<string> decode(string s) 
    {
        vector<string> solution;
        int i = 0;

        while (i < s.size()) 
        {
            int j = i;

            while (s.at(j) != '#') 
            {
                j++;
            }

            //substr first number is start index and second number is length
            int length = stoi(s.substr(i, j - i));

            string word = s.substr(j + 1, length);
            solution.push_back(word);
            i = j + 1 + length;
        }
        return solution;
    }
};

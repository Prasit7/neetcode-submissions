class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
       unordered_map<string, vector<string>> tracker;
       vector<vector<string>> solution;
       //this word is sorted word
       for(string word : strs)
       {
            string actualWord = word;
            //the sort happens right here
            sort(word.begin(), word.end());
            tracker[word].push_back(actualWord);
       }
       for(auto &entry : tracker)
       {
            solution.push_back(entry.second);
       }
       return solution;
    }
};

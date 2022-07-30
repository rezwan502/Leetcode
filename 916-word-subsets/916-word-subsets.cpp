class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector <int> frequency_need(26);        // we'll store the maximum requirement of each character. eg. words2 are 'e' and 'ee'. So, the words should have atleast 2 e.
    vector <string> ans;
    
    for (string s : words2)
    {
        vector <int> temp(26);
        for (char c : s)
            temp[c - 97]++;
        
        for (int i = 0; i < 26; i++)
            frequency_need[i] = max (frequency_need[i], temp[i]);
    }
    
    for (string s : words1)
    {
        vector <int> temp(26);
        bool consider = true;
        
        for (char c : s)
        {
            temp[c - 97]++;
        }
        
        for (int i = 0; i < 26; i++)
        {
            if (temp[i] < frequency_need[i])
            {
                consider = false;
                break;
            }
        }
        
        if (consider)
            ans.push_back (s);
    }
    
    return ans;
    }
};
/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
*/

bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[n]=1;
        unordered_set<string> dict;
        for(string& word:wordDict)
            dict.insert(word);
        for(int i=n-1;i>=0;i--){
            string word;
            for(int j=i;j<n;j++){
                word.push_back(s[j]);
                if(dict.find(word)!=dict.end()){
                    if(dp[j+1])
                        dp[i]=1;
                }
            }
        }       
        return dp[0];
}
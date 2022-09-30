# https://leetcode.com/problems/delete-operation-for-two-strings/description/
# https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
class Solution {
public:
    int LCS(string word1,string word2){
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
             
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int lcs = LCS(word1,word2);
        int insertion = n - lcs;
        int deletion = m - lcs;
        return insertion+deletion;
    }
};

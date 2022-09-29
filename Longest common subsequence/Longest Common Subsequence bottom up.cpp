int getLCS(int i, int j){
        if(i >= n || j >= m) return 0;
        
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        
        if(text1[i] == text2[j]) return ans = 1 + getLCS(i+1, j+1);
        return ans = max(getLCS(i+1, j), getLCS(i, j+1));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        this->text1 = text1;
        this->text2 = text2;
        this->n = text1.length();
        this->m = text2.length();
        dp.resize(n+1, vector<int>(m+1, -1));
        return getLCS(0, 0);
    }

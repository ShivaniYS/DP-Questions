# https://leetcode.com/problems/target-sum
class Solution {
public:
    int perfectSum(vector<int>& arr, int n, int sum)
	{
    
        int dp[n+1][sum+1];

    	for(int i=0; i<=n; i++) dp[i][0] = 1;
    	for(int j=1; j<=sum; j++) dp[0][j] = 0;
    
    
    	for(int i=1; i<=n; i++)
    	{
    		for(int j=0; j<=sum; j++)
    		{
    		    if(arr[i-1]<=j){
    		        dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
    		    }
    		    else{
    		        dp[i][j]=dp[i-1][j];
    		    }
    		}	
    	}

	    return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& arr, int target) {
         target=abs(target);
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        
        if(sum<target||(sum+target)%2!=0)
            return 0;
        int val=(target+sum)/2;
        
        return perfectSum(arr,n,val);
        
    }
};

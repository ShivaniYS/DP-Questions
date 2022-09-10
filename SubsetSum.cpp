//Recurssive Code
#include <iostream>
using namespace std;
bool subsetSum(int set[],int n,int sum){
    //base case
    if(sum==0)
    return true;
    if(n==0)
    return false;
    
    //choice 
    if(set[n-1]>sum)
    return subsetSum(set,n-1,sum);
    else
    return subsetSum(set,n-1,sum) || subsetSum(set,n-1,sum - set[n-1]);
    
}
int main() {
    int set[] = {1,5,9,6,2};
    int sum = 11;
    int n = sizeof(set);
    int cnt=0;
    if(subsetSum(set,sum,n) == true){
    cnt++;
    cout<<cnt<<" ";
    }
    
    else
	return 0;
}
//top-down approach
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        bool dp[arr.size()+1][sum+1];
        for(int i=0;i<arr.size()+1;i++){
            for(int j = 0;j<sum+1;j++){
                if(i==0)
                dp[i][j]=false;
                if(j==0)
                dp[i][j]=true;
                if(i>0 && j>0){
                    if(arr[i-1]<=j){
                        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[arr.size()][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends



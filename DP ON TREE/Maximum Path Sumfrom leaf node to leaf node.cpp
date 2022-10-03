# https://practice.geeksforgeeks.org/problems/maximum-path-sum/1
class Solution {
public:
    int solve(Node* root,int &res){
        if(!root) return INT_MIN;
        if(root && !root->left && !root->right)
        return root->data;
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        if(root->left && root->right){
            res = max(res,l+r+root->data);
        }
        return root->data + max(l,r);
    }
    int maxPathSum(Node* root)
    {
        // code here
        int res = INT_MIN;
       int a = solve(root,res);
       if(!root->left || !root->right)
       return max(a,res);
       return res;
        
    }
};

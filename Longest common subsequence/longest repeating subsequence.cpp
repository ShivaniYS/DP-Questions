# https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
int LongestRepeatingSubsequence(string x){
		    // Code here
		     int n=x.length();

     int t[n+1][n+1];

     string y=x;

     for(int i=0;i<n+1;i++){

         for(int j=0;j<n+1;j++){

             if(i==0 or j==0){

                 t[i][j]=0;

             }

             if(i>0 and j>0){

                 if(x[i-1]==y[j-1] and i!=j){

                     t[i][j]=1+t[i-1][j-1];

                 }

                 else{

                     t[i][j]=max(t[i-1][j],t[i][j-1]);

                 }

             }

         }

     }

     return t[n][n];
		}

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

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int n){
    //complete the function here
    long long int all_a = 1;
    long long int one_b = n;
    long long int one_c = n;
    long long int one_b_one_c = n*(n-1);
    long long int two_c = (n*(n-1))/2;
    long long int one_b_two_c = (n*(n-1)*(n-2))/2;
    
    long long int ans = all_a + one_b + one_c + one_b_one_c + two_c + one_b_two_c;
    
    return ans;
}
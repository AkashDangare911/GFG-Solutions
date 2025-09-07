class Solution {
    public int nthRoot(int n, int m) {
        // code here
       
        int s = 0, e = m;
        while(s<=e){
            int mid = (s+e)/2;
            int val = mid;
            for(int i=1;i<n;i++){
                val = val * mid;
            }
            if(val==m) return mid;
            else if(val<m) s=mid+1;
            else e= mid-1;
        }
        
        return -1;
    }
}
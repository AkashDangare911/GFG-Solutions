class Solution {
    public int median(int[][] mat) {
        // code here
        // code here
        int s=1, e = 2000;
        int n = mat.length, m = mat[0].length;
        int res = -1;
        
        while(s<=e){
            // System.out.println(s+" "+e);
            int mid = (s+e)/2;
            int ans = 1;
            int cnt = 0;
            for(int i=0;i<n;i++){
                int f = 0, l = m-1;
                int pi = -1;
                while(f<=l){
                    int mi = (f+l)/2;
                    if(mat[i][mi]<=mid){
                         f=mi+1;
                         pi = mi;

                    }
                    else l = mi-1;
                    // System.out.println(i+" "+f+" "+l);
                }
                if (pi>=0) {
                    cnt = cnt + (pi+1);
                    ans = ans < mat[i][pi]?mat[i][pi]:ans;
                }
                
            }
            // System.out.println(cnt);
            if((n*m/2)<cnt){
                res = ans;
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
            
        }
        
        return res;
        
    }
}
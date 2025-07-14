class Solution {
  private:
    int rev(int n)
    {
        int ans=0;
        while(n)
        {
            int dig=n%10;
            ans=ans*10+dig;
            n/=10;
        }
        return ans;
    }
    
  public:
    int reverseExponentiation(int a) {
        // reverse the number
        int b = rev(a);
        
        // finding a^b
        int ans=1;
        
        while(b!=0)
        {
            // even power
            if(b%2 == 0)
            {
                a*=a;
                b/=2;
            }
            else
            {
                ans*=a;
                b--;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    bool isPalindrome(int x) {
        long long p =x;
        long long rev =0;
        if(x<0) return false;
        while(x){
            long long last = x%10;
            rev = rev*10;
            rev = rev + last;
            x= x/10;
        }
        return (p == rev);
    }
};
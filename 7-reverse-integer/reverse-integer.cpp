class Solution {
public:
    long long rev =0;
    int reverse(int x) {
        while(x)
        {
            int last = x%10;
            rev = rev*10+last;
        if (rev > INT_MAX || rev < INT_MIN) {
             return 0;}
            x=x/10;
        }
        return static_cast<int>(rev);
    }
};
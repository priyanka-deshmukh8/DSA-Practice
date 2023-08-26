class Solution {
public:
    int fib(int n) {
	if(n<=0)
    return n;
    int currentnumber;
    int dusranumber=0;
    int pehlanumber = 1;
    for(int i =2;i<=n;i++){
         currentnumber = dusranumber + pehlanumber;
    dusranumber = pehlanumber;
    pehlanumber = currentnumber;}
    return currentnumber;
}
};
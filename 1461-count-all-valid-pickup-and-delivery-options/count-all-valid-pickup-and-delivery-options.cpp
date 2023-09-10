class Solution {   
public:
const int M = 1e9 + 7;
int countOrders(int n) {
  if(n==1)
    return 1;
  long long result = 1;
  for(int i =2;i<=n;i++)
  {
    int space = (i-1)*2+1;
    int temp = space * (space+1)/2;
    result *= temp;
    result%=M;
  }
  return result;
  }
};
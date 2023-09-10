 class Solution {
 public:
     bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
         int minsteps = 0;
         int a = abs(fx-sx);
         int b = abs(fy-sy);
        
         if(a==0 && b==0) return t!=1;

         
         if(a<b){
            
            if(sy<fy){
                 return fy - (sy+a) + a <=t;
             }
             else{
                 return sy - (fy+a) + a <=t;
             }
         }

         
         else{
             
             if(sx<fx){
                 return fx - (sx+b) + b <=t;
             }
             else{
                 return sx - (fx+b) + b <=t;
             }
         }
        
         return false;
        
      }
 };

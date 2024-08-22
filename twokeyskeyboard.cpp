#include <iostream>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if (n==1){
            return 0;
        }
        memset(t,-1,sizeof(t));
        return 1+ solve(1,1,n);
        }
    int t[1001][1001];
    
    int solve (int currA,int clipA,int n){
            if (currA==n){
                return 0;
                }
            if (currA>n){
                return 100000;
            }      
            if (t[currA][clipA]!=-1){
                return t[currA][clipA];
            }

        int copyallpaste=1+1+solve(currA+currA,currA,n);
        int paste = 1+solve(currA+clipA,clipA,n);

        return t[currA][clipA]=min(copyallpaste,paste);
  }
};
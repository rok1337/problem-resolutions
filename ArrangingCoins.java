// Source: https://leetcode.com/problems/arranging-coins/ 
public class ArrangingCoins {
    public int arrangingCoins(int n){
        int a = 0;
        int b = n;

        while (a <= b) {
            int k = (a + b) / 2;

            if(k*(k+1)/2 == n) {
                return k;
            }
            if (k*(k+1)/2 > n) b = k - 1;
            else a = k + 1;
        }
        return a - 1;
    }
}

public class Solution{
    int[] vs = {0,2,4,3,7};
    int[] ws = {0,2,3,5,5};
    Integer[][] results = new Integer[5][11];
    
    
    public void testKnapsack3() {
        int result = ks3(4,10);
        System.out.println(result);
    }

    private int ks3(int i, int j){
        // 初始化
        for (int m = 0; m <= i; m++){
            results[m][0] = 0;
        }
        for (int m = 0; m <= j; m++){
            results[0][m] = 0;
        }
        // 开始填表
        for (int m = 1; m <= i; m++){
            for (int n = 1; n <= j; n++){
                if (n < ws[m]){
                    // 装不进去
                    results[m][n] = results[m-1][n];
                } else {
                    // 容量足够
                    if (results[m-1][n] > results[m-1][n-ws[m]] + vs[m]){
                        // 不装该珠宝，最优价值更大
                        results[m][n] = results[m-1][n];
                    } else {
                        results[m][n] = results[m-1][n-ws[m]] + vs[m];
                    }
                }
            }
        }
        return results[i][j];
    }
}
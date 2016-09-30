public class Dice {
	public int dfs(int i, int n, int remain, int[][] cache) { //第i到n个筛子，和为remain的种类数
		if(i >= n) {
			if(remain == 0) {
				return 1;
			}
			return -1;
		}
		if(remain < 0) {
			return -1;
		}
		if(cache[i][remain] != 0) {
			return cache[i][remain];
		}
		int count = 0;
		for(int j = 1; j <= 6; ++j) {
			int temp = dfs(i+1, n, remain-j, cache);
			if(temp != -1) {
				count += temp;
			}
		}
		cache[i][remain] = count;
		return count;
	}
	@Test
	public void test() {
		int n = 5; 
		int sum = 7;
		int cache[][] = new int[n+1][sum+1]; 
		int count = dfs(0, n, sum, cache);
		System.out.print(count);
	}
}

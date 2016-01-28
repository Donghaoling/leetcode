class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        //每一个质数都跟没乘过的当前结果superUglyNumber里最小的数乘,idxs[i]记录的是质数primes[i]的没有乘过的最小值。
        vector<int> superUglyNumber;
        superUglyNumber.push_back(1);
        int nPrimes = primes.size();
        vector<int> idxs(nPrimes, 0);
        while(superUglyNumber.size() < n) {
            int nextSuperUglyNumber = primes[0] * superUglyNumber[idxs[0]];
            for(int i = 0; i < nPrimes; ++i) {
                nextSuperUglyNumber = min(nextSuperUglyNumber, primes[i] * superUglyNumber[idxs[i]]);
            }
            for(int i = 0; i < nPrimes; ++i) {
                if(nextSuperUglyNumber == primes[i] * superUglyNumber[idxs[i]]) {
                    idxs[i] ++;
                }
            }
            superUglyNumber.push_back(nextSuperUglyNumber);
        }
        return superUglyNumber[n-1];
    }
};

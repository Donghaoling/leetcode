class Solution {
public:
    int min(int a, int b) {
        if(a <= b) return a;
        else return b;
    }
    //borad用来记录每个cell的状态，每个cell有两位，低位是当前的状态，高位是一个单位时间后的状态，开始的状态是00或01，之后会变成00,10,11,01四个状态
    int liveNum(vector<vector<int>>& board, int i, int j, int m, int n) {
        int lives = 0;
        for(int a = max(i-1, 0); a <= min(i+1, m-1); ++a) {
            for(int b = max(j-1, 0); b <= min(j+1, n-1); ++b) {
                lives += board[a][b] & 1;
            }
        }
        lives -= board[i][j]; 
        return lives;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        int lives;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                lives = liveNum(board, i, j, m, n);
                if(board[i][j] == 0) {
                    if(lives == 3) {
                        board[i][j] = 2;
                    }
                }
                else {
                    if(lives == 2 || lives == 3) {
                        board[i][j] = 3;
                    }
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};

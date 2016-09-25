class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
	int used[10];
	int i, j, k;
	char ch;
	for(i = 0; i < 9; ++i) {
	    memset(used, 0, sizeof(used));
	    for(j = 0; j < 9; ++j) {
		if(board[i][j] != '.') used[board[i][j] -'0']++;
	    }
	    for(j = 1; j <= 9; ++j) if(used[j] > 1) return false;
	}
	for(j = 0; j < 9; ++j) {
	    memset(used, 0, sizeof(used));
	    for(i = 0; i < 9; ++i) {
		if(board[i][j] != '.') used[board[i][j] -'0']++;
	    }
	    for(i = 1; i <= 9; ++i) if(used[i] > 1) return false;
	}
	for(k = 0; k < 9; ++k) {
	    memset(used, 0, sizeof(used));
	    for(i = 0; i < 3; ++i) {
		for(j = 0; j < 3; ++j) {
		    ch = board[i + (k / 3) * 3][j + (k % 3) * 3];
		    if(ch != '.') used[ch - '0']++;
		}
	    }
	    for(i = 1; i <= 9; ++i) if(used[i] > 1) return false;
	}

	return true;
    }
};

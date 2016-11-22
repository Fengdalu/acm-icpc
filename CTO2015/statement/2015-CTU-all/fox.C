/*
Author: Mimino
Solution: O(length(N))
*/
 
#include <cstdio>
#include <cstring>
using namespace std;
 
const int MAX = 100000+100;  // |N| <= 10^(10^5) + reserve
int len;
char N[MAX];
 
// shift the digits of N by `off` places to the right
void shift(int off) {
	if (off > 0) {
		for (int i = len-1; i >= 0; --i)
			N[i+off] = N[i];
	} else {
		for (int i = 0; i < len; ++i)
			N[i] = N[i-off];
	}
	len += off;
}
 
int main() {
	while (true) {
		scanf("%s", N);
		if (N[0] == 'E') break;
		len = strlen(N);
		if (N[0] == '-') {
			// N is negative
			int i = len-1;
			while (i > 0 && N[i] == '9') --i;
			if (i == 0) {
				// number in form -99..99 => -199..99
				shift(1);
				N[0] = '-';
				N[1] = '1';
			} else {
				// number in form -..x..99 => -..(x+1)..99
				N[i] += 1;
			}
		} else {
			// N is positive
			int i = len-1;
			while (i >= 0 && N[i] == '9') --i;
			if (i == -1) {
				// number in form 99..99 => -199..99
				shift(2);
				N[0] = '-';
				N[1] = '1';
			} else if (i == 0) {
				// number in form x99..99 => -(x+1)99.99
				shift(1);
				N[0] = '-';
				N[1] += 1;
			} else {
				N[i]++;
				while (i > 0 && N[i] == '9') --i;
				if (i == -1 || i == 0) {
					// number in form 99..8..99 => -99..9..99
					// number in form y99..8..99 => -y99..9..99
					shift(1);
					N[0] = '-';
				} else {
					N[i] += 1;
					i--;
					while (N[i] == '0') --i;
					N[i] -= 1;
					// from i-th position to the right, rearrange the digits in the form: 9..9x0..0..
					int s = 0;
					for (int j = i+1; j < len; ++j)
						s += N[j] - '0';
					for (int j = i+1; j < len; ++j) {
						if (s > 9) {
							N[j] = '9';
							s -= 9;
						} else {
							N[j] = s + '0';
							s = 0;
						}
					}
					// if N starts with zero, shift the digits
					if (N[0] == '0')
						shift(-1);
				}
			}
		}
		N[len] = 0;
		printf("%s\n", N);
	}
 
	return 0;
}

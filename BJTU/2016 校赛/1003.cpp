#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

char s[1000][1000];

int main() {
	int T;
	scanf("%d", &T);
	for(int ii = 0; ii < T; ii++) {
		int n;
		scanf("%d", &n);
		int w = 4 * n + 5;
		int h = 4 * n + 5;
		for(int i = 0; i < w; i++) {
			for(int j = 0; j < h; j++)
				s[i][j] = '.';
			s[i][h] = 0;
		}
		for(int i = 0; i < 5; i++) s[2 + 2 * n][2 * n + i] = '$';
		int l = 0; 
		for(int c = 0; c < n; c++) {
			for(int i = l + 2; i < l + w - 2; i++) {
				s[l][i] = s[l + w - 1][i] = '$';
			}
			for(int i = 0; i < 3; i++) {
				s[l + 2][l + i] = s[l + 2][l + w - 1 - i] = '$';
				s[l + w - 3][l + i] = s[l + w - 3][l + w - 1 - i] = '$';
			}
			l += 2;
			w -= 4;
		}
	 	w = 4 * n + 5;
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++) 
			if(s[i][j] == '$') s[j][i] = '$';
			else if(s[j][i] == '$') s[i][j] = '$';
		printf("Case %d:\n", ii + 1);
		for(int i = 0; i < h; i++) printf("%s\n", s[i]);
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

std::queue< std::pair<int, int> >qa, qb;

int n, a, b;
int id[200][200];
int main() {
	std::cin >> n >> a >> b;	
	for(int i = 0; i < a; i++)
		for(int j = 0; j < b; j++)
			if((i + j) % 2) qa.push(std::make_pair(i, j));
			else qb.push(std::make_pair(i, j));
	if(n % 2 == 1) {
		if(qa.size() < qb.size()) std::swap(qa, qb);
	}
	if((n + 1) / 2 > qa.size() || n / 2 > qb.size()) {
		puts("-1");
		return 0;
	}
	for(int i = 1; i <= n; i++) 
	if(i % 2 == 0) {
		id[qa.front().first][qa.front().second] = i;
		qa.pop();
	}
	else {
		id[qb.front().first][qb.front().second] = i;
		qb.pop();
	}
	for(int i = 0; i < a; i++) {
		for(int j = 0; j < b; j++)
			std::cout << id[i][j] << " ";
		std::cout << std::endl;
	}
}

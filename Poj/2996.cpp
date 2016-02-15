#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct node {
	char c;
	int x, y;
	node(){}
	node(char c, int x, int y) : c(c), x(x), y(y) {}
};
vector<node>black, white;
map<char, int>order;

char line[100];
void init() {
	order['K'] = 0;
	order['Q'] = 1;
	order['R'] = 2;
	order['B'] = 3;
	order['N'] = 4;
	order['P'] = 5;
}

int cmp2(node a, node b) {
	if(order[toupper(a.c)] == order[toupper(b.c)])
		return make_pair(a.x, a.y) < make_pair(b.x, b.y);
	return order[toupper(a.c)] < order[toupper(b.c)];
}

int cmp1(node a, node b) {
	if(order[toupper(a.c)] == order[toupper(b.c)])
		return make_pair(-a.x, a.y) < make_pair(-b.x, b.y);
	return order[toupper(a.c)] < order[toupper(b.c)];
}

void run() {
	init();
	black.clear();
	white.clear();
	for(int i = 8; i >= 1; i--) {
		gets(line);
		gets(line);
		int cur = 0;
		for(int j = 1; j <= 8; j++) {
			cur++;
			if(line[cur + 1] != ':' && line[cur + 1] != '.') {
				if(islower(line[cur + 1])) black.push_back(node(line[cur + 1], i, j));
				else white.push_back(node(line[cur + 1], i, j));
			}
			cur += 3;
		}
	}
	sort(black.begin(), black.end(), cmp1);
	sort(white.begin(), white.end(), cmp2);

	printf("White: ");
	for(int i = 0; i < white.size(); i++) {
		if(i != 0) printf(",");
		node &p = white[i];
		if(tolower(p.c) != 'p') printf("%c%c%d", toupper(p.c), p.y + 'a' - 1, p.x);
		else printf("%c%d", p.y + 'a' - 1, p.x);
	}
	puts("");
	printf("Black: ");
	for(int i = 0; i < black.size(); i++) {
		if(i != 0) printf(",");
		node &p = black[i];
		if(tolower(p.c) != 'p') printf("%c%c%d", toupper(p.c), p.y + 'a' - 1, p.x);
		else printf("%c%d", p.y + 'a' - 1, p.x);
	}
}

int main() {
	run();
}

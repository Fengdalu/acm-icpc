#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

char line[1000];
char f[10][10];
string s;

void run() {
	scanf("White: %s", line);
	s = string(line);
	memset(f, 0, sizeof f);
	for(int i = 0; i < s.length(); i++) if(s[i] == ',') s[i] = ' ';
		
	string word;
	istringstream is(s);
	while(is >> word) {
		if(word.size() == 2) word = 'p' + word;
		int c = word[1] - 'a' + 1;
		int r = word[2] - '1' + 1;
		r = 9 - r;
		f[r][c] = toupper(word[0]);
	}
	gets(line);
	scanf("Black: %s", line);
	s = string(line);
	for(int i = 0; i < s.length(); i++) if(s[i] == ',') s[i] = ' ';
	
	istringstream iss(s);
	while(iss >> word) {
		if(word.size() == 2) word = 'p' + word;
		int c = word[1] - 'a' + 1;
		int r = word[2] - '1' + 1;
		r = 9 - r;
		f[r][c] = tolower(word[0]);
	}
	for(int i = 1; i <= 8; i++) {
		puts("+---+---+---+---+---+---+---+---+");
		for(int j = 1; j <= 8; j++) {
			if((i + j) % 2 == 0) {
				if(f[i][j] == 0) printf("|...");
				else printf("|.%c.", f[i][j]);
			}
			else {
				if(f[i][j] == 0) printf("|:::");
				else printf("|:%c:", f[i][j]);
			}
		}
		puts("|");
	}
	puts("+---+---+---+---+---+---+---+---+");
}

int main() {
	run();
	return 0;
}

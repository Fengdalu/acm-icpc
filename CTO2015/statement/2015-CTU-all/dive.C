// Author Pavel
 
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
 
// MxN
int M;
int N;
// Falcon 
char l,F,r;
 
int main() {
    while(true) {
	int p1_x = -1;
        int p1_y = -1;
	int p2_x = -1;
	int p2_y = -1;
	string line;
	getline(cin, line);
	stringstream ss(line);
	ss >> M >> N >> l >> F >> r;
	N+=1;
	if(M==0) return 0;
	char p1[M][N];    
	char p2[M][N];    
	char p3[M][N];    
	for(int i=0; i<M; ++i) {
	    cin.getline(p1[i],N);
	}
	getline(cin, line);
	for(int i=0; i<M; ++i) {
	    cin.getline(p2[i],N);
	}
	for(int i=0; i<M; ++i) {
	    for(int j=0; j<N; ++j) {
		if(p1[i][j]==p2[i][j]){
		    p3[i][j] = p1[i][j];    
		} else if(p1[i][j] == F) {
		    if(p1_x == -1) {
			p1_x = i;
			p1_y = j;
		    }
		    p3[i][j] = p2[i][j];
		} else {
		    if(p2_x == -1) {
			p2_x = i;
			p2_y = j;
		    }
		    p3[i][j] = p1[i][j];
		}
	    }
	}
	int diff_x = 2*(p2_x - p1_x);
	int diff_y = 2*(p2_y - p1_y);
	for(int fx=0;fx<M;++fx) {
	    for(int fy=0;fy<N-1;++fy) {
		if((p1[fx][fy] == F) && ((fx + diff_x) < M) && ((fy + diff_y) < N-1) && ((fx + diff_x) >= 0) && ((fy + diff_y) >= 0))
		    p3[fx+diff_x][fy+diff_y]=F;
	    }
 
	}
 
	for(int i=0;i<M;i++) cout << p3[i] << endl;
	cout << endl;
	getline(cin,line);
    }
    return 0;
}

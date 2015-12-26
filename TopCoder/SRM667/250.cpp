#include vector
#include list
#include map
#include set
#include deque
#include stack
#include bitset
#include algorithm
#include functional
#include numeric
#include utility
#include sstream
#include iostream
#include iomanip
#include cstdio
#include cmath
#include cstdlib
#include ctime
#include cstring

using namespace std;

class PalindromePrime {
public
	int count(int, int);
};

char buf[100];
int check(int x) {
  if(x  2) return false;
  if(x == 2) return true;
  for(int i = 2; i  x; i++) if(x % i == 0) return false;
  sprintf(buf, %d, x);
  int len = strlen(buf);
  for(int i = 0; i  len; i++) if(buf[i] != buf[len - i - 1]) return false;
  return true;
}

int PalindromePrimecount(int L, int R) {
	int cnt = 0;
	for(int i = L; i = R; i++) { 
		if(check(i)) cnt++;	
	}
	return cnt;
}


Powered by [KawigiEdit] 2.0!
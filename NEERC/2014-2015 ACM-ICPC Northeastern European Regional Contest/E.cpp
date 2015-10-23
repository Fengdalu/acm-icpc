/******************************************************************/
/* ACM ICPC 2014-2015                                             */
/* Northeastern European Regional Contest                         */
/* St Petersburg - Barnaul - Tbilisi - Tashkent, December 7, 2014 */
/******************************************************************/
/* Problem E. Epic Win!                                           */
/*                                                                */
/* Original idea         Mikhail Dvorkin                          */
/* Problem statement     Mikhail Dvorkin                          */
/* Test set              Mikhail Dvorkin                          */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Niyaz Nigmatullin                        */
/******************************************************************/

#include <cstdio>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
 
using namespace std;
 
#define next next31749hahkds
 
const char moves[] = "RPS";
const int N = 110;
const int M = N * N;
int choice[N];
int next[N][3];
int my_choice[M];
int my_next[M][3];
 
vector <int> all(int n) {
  vector <int> v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = i;
  }
  return v;
}
 
int findMoveCharNum(char ch) {
  int i = 0;
  while (i < 3 && moves[i] != ch) {
    ++i;
  }
  assert(i < 3);
  return i;
}
 
void normalize(vector <int> & v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
 
int main() {
  freopen("epic.in", "r", stdin);
  freopen("epic.out", "w", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char ch;
    scanf(" %c", &ch);
    for (int j = 0; j < 3; ++j) {
      scanf("%d", &next[i][j]);
      --next[i][j];
    }
    choice[i] = findMoveCharNum(ch);
  }
   
  vector <vector <int> > my_states;
  map <vector <int>, int> my_states_map;
  my_states.push_back(all(n));
  my_states_map[my_states.back()] = 0;
  for (int i = 0; i < int(my_states.size()); ++i) {
    vector <int> & current = my_states[i];
    vector <int> nextSets[3];
    for (int j = 0; j < 3; ++j) {
      nextSets[j].clear();
    }
    for (int j = 0; j < int(current.size()); ++j) {
      nextSets[choice[current[j]]].push_back(current[j]);
    }
    my_choice[i] = 0;
    for (int j = 1; j < 3; ++j) {
      if (nextSets[j].size() > nextSets[my_choice[i]].size()) {
        my_choice[i] = j;
      }
    }
    my_choice[i] = (my_choice[i] + 1) % 3;
    for (int j = 0; j < 3; ++j) {
      if (nextSets[j].empty()) {
        continue;
      }
      for (int k = 0; k < int(nextSets[j].size()); ++k) {
        nextSets[j][k] = next[nextSets[j][k]][my_choice[i]];
      }
      normalize(nextSets[j]);
      auto iter = my_states_map.find(nextSets[j]);
      int nextNumber = -1;
      if (iter == my_states_map.end()) {
        nextNumber = (int)my_states.size();
        my_states.push_back(nextSets[j]);
        my_states_map[my_states.back()] = nextNumber;
      } else {
        nextNumber = iter->second;
      }
      my_next[i][j] = nextNumber;
    }
  }
  printf("%d\n", my_states.size());
  for (int i = 0; i < int(my_states.size()); ++i) {
    printf("%c", moves[my_choice[i]]);
    for (int j = 0; j < 3; ++j) {
      printf(" %d", my_next[i][j] + 1);
    }
    printf("\n");
  }
  return 0;
}
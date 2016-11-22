#include <bits/stdc++.h>

typedef long long ll;
const int N = 5e5;
struct node {int l, r, type, id;}; 
node nodes[N*5], *curNode;
ll ans[N];
int a[N];
int sz;

void add(int l, int r, int type, int id) {
  if(l > r) return ;
  curNode->l = l;
  curNode->r = r;
  curNode->type = type;
  curNode->id = id;
  curNode++;
}


int operator < (const node &a, const node &b) {
  if(a.l / sz == b.l / sz) return a.r < b.r;
  return a.l / sz < b.l / sz;
}

int sum[N];
void deal() {
  int l = 1, r = 0;
  ll tot = 0;
  for(int i = 0; i < curNode - nodes; i++) {
    node &cur = nodes[i];
    while(r < cur.r) { 
      r++; 
      sum[a[r]]++; 
      tot += sum[a[r]];
    }
    while(r > cur.r) { 
      tot -= sum[a[r]]; 
      sum[a[r]]--; 
      r--;  
    }
    while(l > cur.l) { 
      l--; 
      sum[a[l]]++; 
      tot += sum[a[l]]; 
    }
    while(l < cur.l) { 
      tot -= sum[a[l]]; 
      sum[a[l]]--; 
      l++; 
    }
    ans[cur.id] += nodes[i].type * tot;
  }
}

int main() {
  int n; scanf("%d", &n);

  curNode = nodes;
  for(int i = 0; i < n; i++) scanf("%d", a + i + 1);
  int m; scanf("%d", &m);
  int cnt = 0;

  for(int i = 0; i < m; i++) {
    // puts("==============");
    int l1, r1, l2, r2;
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    if(l1 > l2) {
      std::swap(l1, l2);
      std::swap(r1, r2);
    }
    if(r1 >= l2) {
      add(l1, std::max(r1, r2), 1, i);
      add(l1, std::max(l1, l2) - 1, -1, i);
      add(std::min(r1, r2) + 1, std::max(r1, r2), -1, i);
      add(std::max(l1, l2), std::min(r1, r2), 1, i);
      ans[i] -= std::min(r1, r2) - std::max(l1, l2) + 1;
      continue;
    }
    add(l1, r2, 1, i);
    add(l1, l2 - 1, -1, i);
    add(r1 + 1, r2, -1, i);
    add(r1 + 1, l2 - 1, 1, i);
  }
  sz = sqrt(n);
  std::sort(nodes, curNode);

  deal();
  for(int i = 0; i < m; i++) printf("%I64d\n", ans[i]);
  return 0;
}

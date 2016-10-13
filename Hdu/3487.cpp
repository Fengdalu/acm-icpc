#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX_NODE = 3e5+10;
// 注意初始化内存池和 null 节点
struct Node{
	int rev,size; Node *ch[2],*p;
	int w;
	void set(Node*,int); int dir(); void update(); void relax(); void appRev();
} nodePool[MAX_NODE],*curNode,*null;
Node *newNode(){
	Node *t=curNode++; t->rev=0, t->size=1;
	t->ch[0]=t->ch[1]=t->p=null; return t;
}
struct Splay{
	Node *root;
	Splay(){ root=newNode(); root->set(newNode(),0); root->update(); }
	void rot(Node *t){
		Node *p=t->p; int d=t->dir();
		p->relax(); t->relax();
		if(p==root) root=t;
		p->set(t->ch[!d],d); p->p->set(t,p->dir()); t->set(p,!d);
		p->update();
	}
	void splay(Node *t,Node *f=null){
		for(t->relax();t->p!=f;)
			if(t->p->p==f) rot(t);
			else t->dir()==t->p->dir()?(rot(t->p),rot(t)):(rot(t),rot(t));
		t->update();
	}

};
void initNull(){ curNode=nodePool; null=curNode++;null->size=0; }
void Node::set(Node *t,int _d){ ch[_d]=t; t->p=this; }
int Node::dir(){ return this==p->ch[1]; } void Node::update(){ size=ch[0]->size+ch[1]->size+1;} void Node::relax(){ if(rev) ch[0]->appRev(), ch[1]->appRev(), rev=false; }
void Node::appRev(){ if(this==null) return; rev^=true; std::swap(ch[0],ch[1]); }

void build(Node* p, int l, int r) {
	int mid = (l + r) / 2;
	p->w = mid; 
	if(l == r) return;
	if(l <= mid - 1) { p->set(newNode(), 0); build(p->ch[0], l, mid - 1); }
	if(mid + 1 <= r) { p->set(newNode(), 1); build(p->ch[1], mid + 1, r);  }
	p->update();
}

Node* find(Node *p, int t) {
	while(true) {
		p->relax();
		int L = (p->ch[0]->size) + 1;
		if(L == t) return p;
		if(t < L) p = p->ch[0];
		else {
			p = p->ch[1];
			t -= L;
		}
	}
}

int n, m;
int ans[MAX_NODE];
int cnt = 0;
void print(Node *rt) {
	if(rt == null) return;
	rt->relax();
	print(rt->ch[0]);
	if(rt->w != n + 1 && rt->w != 0) ans[cnt++] = rt->w;
	print(rt->ch[1]);
}

int main() {
	char op[10];
	while(~scanf("%d%d", &n, &m)) {
		memset(nodePool, 0, sizeof nodePool);
		if(n == -1 && m == -1) break;
		initNull();
		Splay T;
		build(T.root, 0, n + 1);
		while(m--) {
			scanf("%s", op);
			if(op[0] == 'C') {
				int l, r, c;
				scanf("%d%d%d", &l, &r, &c);

				Node *R = find(T.root, r + 2);
				T.splay(R); 
				Node *L = find(T.root, l); 
				T.splay(L, R);

				Node *LR = L->ch[1];
				L->ch[1] = null;
				L->update(); R->update();

				Node *RR = find(T.root, c + 2);
				T.splay(RR); 
				Node *LL = find(T.root, c + 1); 
				T.splay(LL, RR);
				LL->set(LR, 1);
				LL->update(); 
				RR->update();
			}
			else if(op[0] == 'F') {
				int l, r, c;
				scanf("%d%d", &l, &r);
				Node *R = find(T.root, r + 2); 
				T.splay(R);
				Node *L = find(T.root, l);
				T.splay(L, R);
				L->ch[1]->appRev();
			}
		}
		T.splay(find(T.root, T.root->size / 2));
		cnt = 0;
		print(T.root);
		for(int i = 0; i < cnt; i++) if(i == 0) printf("%d", ans[i]);
		else printf(" %d", ans[i]);
		puts("");
	}
	return 0;
}

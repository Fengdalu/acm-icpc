// 注意初始化内存池和 null 节点
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>


const int MAX_NODE = 3e6;
struct Node{
	int rev, size; 
	int K, P;
	bool del;
	Node *ch[2], *p;
	
	void set(Node*,int); 
	int dir(); 
	void update(); 
	void relax(); 
	void appRev();

} nodePool[MAX_NODE],*curNode,*null;

Node *newNode(){
	Node *t=curNode++; 
	t->rev=0, t->size=1;
	t->del = false;
	t->ch[0]=t->ch[1]=t->p=null; return t;
}
struct Splay{
	int tot;
	Node *root;
	Splay(){ root=newNode(); tot = 0; }//root->set(newNode(),0); root->update(); }
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

	void insert(Node *t) {
		Node *rt = this->root;
		if(!tot) {
			tot++;
			rt->K = t->K;
			rt->P = t->P;
			return;
		}
		tot++;
		while(true) {
			int d;
			rt->size++;
			if(t->P <= rt->P) d = 0; else d = 1;
			if(rt->ch[d]->size == 0) { rt->set(t, d);  break; }
			else rt = rt->ch[d];
		}
		splay(t);
	}

	int find(int mode) {
		Node *rt = this->root;
		if(tot == 0) return 0;
		tot--;
		while(true) {
			if(rt->ch[mode]->size) rt = rt->ch[mode];
			else break;
		}
		splay(rt);
		int ans = rt->K;
		if(rt->ch[0] != null) this->root = rt->ch[0];
		else if(rt->ch[1] != null) this->root = rt->ch[1];
		this->root->p = null;
		return ans;
	}
};

void initNull(){ curNode=nodePool;null=curNode++;null->del=true;null->size=0; }
void Node::set(Node *t,int _d){ ch[_d]=t; t->p=this; }
int Node::dir(){ return this==p->ch[1]; }
void Node::update() {}
void Node::relax() {}
void Node::appRev(){ if(this==null) return; rev^=true; std::swap(ch[0],ch[1]); }

int main() {
	initNull();
	Splay T;
	int op;
	T.root->K = T.root->P = 0;
	int cnt = 0;
	while(true) {
		scanf("%d", &op);
		if(op == 1) {
			int K, P;
			scanf("%d%d", &K, &P);
			Node *t = newNode();
			t->K = K;
			t->P = P;
			T.insert(t);
		}
		else if(op == 2) {
			printf("%d\n", T.find(1));
		}
		else if(op == 3) {
			printf("%d\n", T.find(0));
		}
		else break;
	}
	return 0;
}

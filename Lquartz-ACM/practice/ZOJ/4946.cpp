#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define MP make_pair
#define SZ size()
#define AA first
#define BB second
#define OP begin()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define Maxn 100000
#define LEN 200000
int n;
//string line[Maxn];
char ss[LEN];
string str;
int tot;
int mem[1111];//here point, all, map<string, int>, vector<Order>
int all, point;
map<string, int> mp;

struct Param{
    int type, num;
    Param() {type = num = 0;}
    Param(int n, int t): num(n), type(t) {}
    int getV() {
        if(type == 0) return num;
        else return mem[num];
    }
    int getVV() {
        return num;
    }
};
struct Order {
    vector<Param> ps;
    int next, cur;
    int type;
    Order() {next = cur = -1; ps.clear();type = -1;}
    Order(int c) : cur(c), next(c + 1){ps.clear();type = -1;}
    Order(int c, int n) : cur(c), next(n) {ps.clear(); type = -1;}
    void init() {
        init(-1, -1); //
    }
    void init(int c, int n) {
        cur = c; next = n; ps.clear();
    }
    void addP(Param & p) {
        ps.PB(p);
    }
    void addP(int num, int type) {
        ps.PB(Param(num, type));
    }
    void setit() {
        int x = ps[0].getVV();
//        cout << "\tRRRR " << "setit " << x << " " << ps[1].getV();
        if(x != 0) mem[x] = ps[1].getV();
    }
    void addit() {
        int x = ps[0].getVV();
//        cout << "\tRRRR " << "addit " << x << " " << ps[1].getV() << " " << ps[2].getV();
        if(x != 0) mem[x] = ps[1].getV() + ps[2].getV();
    }
    void subit() {
        int x = ps[0].getVV();
        if(x != 0) mem[x] = ps[1].getV() - ps[2].getV();
    }
    void mulit() {
        int x = ps[0].getVV();
        if(x != 0) mem[x] = ps[1].getV() * ps[2].getV();
    }
    void divit() {
        int x = ps[0].getVV();
        if(x != 0) mem[x] = ps[1].getV() / ps[2].getV();
    }
    void modit() {
        int x = ps[0].getVV();
        if(x != 0) mem[x] = ps[1].getV() % ps[2].getV();
    }
    void settagit() {
    
    }
    void gotoit() {
        point = next;
    }
    void ifit() {
        if(ps[0].getV() > 0) point = ps[1].getV();
        else point = ps[2].getV();
    }
    void printit() {
//        cout << "\tRRRR " << "printit " << ps[0].getV();
        printf("%d\n", ps[0].getV());
    }
    void run() {
//        cout << "run " << cur << " " << next << " " << type << endl;
        switch(type) {
        case 0: setit(); point = next; break;
        case 1: addit(); point = next; break;
        case 2: subit(); point = next; break;
        case 3: mulit(); point = next; break;
        case 4: divit(); point = next; break;
        case 5: modit(); point = next; break;
        case 6: settagit(); assert(0);break;
        case 7: gotoit(); break;
        case 8: ifit(); break;
        case 9: printit(); point = next; break;
        default: break;
        }
    }
};
vector<Order> orders;
Order now, next;
Param p1, p2, p3;
void getParam(string & str, Param & p) {
//    cout << "\t get " << str << endl;
    int head = 0, tail = str.length() - 1, ret = 0, x = 10, sgn;
    if(str[0] == '$') {
        p.type = 1;
        head++;
    }
    else {
        p.type = 0;
    }
    if(str[tail] == 'B' || str[tail] == 'b') {x = 2; tail--;}
    else if(str[tail] == 'H' || str[tail] == 'h') {x = 16; tail--;}
    else if(str[tail] == 'D' || str[tail] == 'd') {x = 10; tail--;}
    if(str[head] == '-') {sgn = -1; head++; }else {sgn = 1;}//
    ret = 0;
    for(int i = head; i <= tail; i++) {
        if('0' <= str[i] && str[i] <= '9') ret = ret * x + str[i] - '0';
        else if('a' <= str[i] && str[i] <= 'z') ret = ret * x + str[i] - 'a' + 10;
        else if('A' <= str[i] && str[i] <= 'Z') ret = ret * x + str[i] - 'A' + 10;
    }
    ret *= sgn;
    p.num = ret;
//    cout << "\t " << ret << " " << p.type << endl;
}

void readParam(stringstream & sin, int n) {
    string str;
    if(n > 0) {
        sin >> str;
        getParam(str, p1);
    }
    if(n > 1) {
        sin >> str;
        getParam(str, p2);
    }
    if(n > 2) {
        sin >> str;
        getParam(str, p3);
    }
}
string cao;
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("no.txt", "w", stdout);
    int i, j, k, u, v, w, len;
    while(scanf("%d", &n) != EOF) {
        tot = 0;
        gets(ss);
        cao = " ";
        for(i = 0; i < n; i++) {
            gets(ss);
            str = string(ss);
            len = str.length();
            if(len) {
                for(j = 0; j < len; j++) if(str[j] == '#') break;
//                str.erase(str.BG + j, str.ED);
                len = j;
            }
            if(len) {
                u = 0;
                for(j = 0; j < len; j++){
                    if(str[j] == ';') {
//                        line.PB(str.substr(u, j - u)); tot++;
                        cao += ' ';
                        for(k = u; k < j; k++) cao += str[k];
                        cao += ' ';
//                        cao = cao + " " + str.substr(u, j - u);
                        u = j + 1;
                    }
                }
                if(u < j) {
//                    line.PB(str.substr(u, j - u)); tot++;
                        cao += ' ';
                        for(k = u; k < j; k++) cao += str[k];
                        cao += ' ';
//                    cao = cao + " " + str.substr(u, j - u);
                }
            }
        }
//        cout << cao << endl;
//        cout << tot <<endl;
//        for(i = 0; i < tot; i++) cout << i << " ~ " << line[i] << endl;
        
        mp.clear();
        all = 1;
        stringstream sin(cao);
        while(sin>>str) {
            {
                if(str == "SETTAG") {
                    sin>>str;
                    mp[str] = all;
//                    cout << "mp " << str << " " << all << endl;
                } else if(str == "SET" || str == "ADD" || str == "SUB"
                          || str == "MUL"|| str == "DIV"|| str == "MOD"
                          || str == "GOTO"|| str == "IF"|| str == "PRINT") {
                    sin>>str;
                    all++;
                }
            }
        }
//        cout << all << " + " << endl;
        point = 1;
        orders.clear();
        orders.PB(now);
        stringstream sin1(cao);
        while(sin1>>str) {
            {
//                cout << i << " @ " << str << endl;
                if(str == "SETTAG") {
                    sin1 >> str;
//                    continue;
                } else if(str == "SET") {//init
                    now.init();
                    now.type = 0;
                    now.cur = point;
                    now.next = point + 1;
                    readParam(sin1, 2);
                    now.addP(p1); now.addP(p2);
                    orders.PB(now);
                    point++;
                }else if(str == "ADD") {
                    now.init();
                    now.type = 1;
                    now.cur = point;
                    now.next = point + 1;
                    readParam(sin1, 3);
                    now.addP(p1); now.addP(p2); now.addP(p3);
                    orders.PB(now);
                    point++;
                
                }else if(str == "SUB") {
                    now.init();
                    now.type = 2;
                    now.cur = point;
                    now.next = point + 1;
                    readParam(sin1, 3);
                    now.addP(p1); now.addP(p2); now.addP(p3);
                    orders.PB(now);
                    point++;
                
                }
                else if(str == "MUL"){
                    now.init();
                    now.type = 3;
                    now.cur = point;
                    now.next = point + 1;
                    readParam(sin1, 3);
                    now.addP(p1); now.addP(p2); now.addP(p3);
                    orders.PB(now);
                    point++;
                    
                }
                else if(str == "DIV"){
                    now.init();
                    now.type = 4;
                    now.cur = point;
                    now.next = point + 1;
                    readParam(sin1, 3);
                    now.addP(p1); now.addP(p2); now.addP(p3);
                    orders.PB(now);
                    point++;
                    
                }
                else if(str == "MOD") {
                    now.init();
                    now.type = 5;
                    now.cur = point;
                    now.next = point + 1;
                    readParam(sin1, 3);
                    now.addP(p1); now.addP(p2); now.addP(p3);
                    orders.PB(now);
                    point++;
                    
                }
                else if(str == "GOTO") {
                    now.init();
                    now.type = 7;
                    now.cur = point;
                    now.next = point + 1;
                    sin1 >> str;
                    now.next = mp[str];
                    orders.PB(now);
                    point++;
                }
                else if(str == "IF"){
                    now.init();
                    now.type = 8;
                    now.cur = point;
                    now.next = point + 1;
                    readParam(sin1, 1);
                    sin1>>str;
                    p2.num = mp[str];
                    p2.type = 0;
                    sin1>>str;
                    p3.num = mp[str];
                    p3.type = 0;
                    now.addP(p1); now.addP(p2); now.addP(p3);
                    orders.PB(now);
                    point++;
                }
                else if(str == "PRINT") {
                    now.init();
                    now.type = 9;
                    now.cur = point;
                    now.next = point + 1;
                    readParam(sin1, 1);
                    now.addP(p1);
                    orders.PB(now);
                    point++;
                }
            }
        }
//        assert(point == all);
//        cout << point << " ! " << all << endl;
        point = 1;
        memset(mem, 0, sizeof(mem));
        while(point < all) {
            orders[point].run();
        }
        printf("\n");
    }
    return 0;
}

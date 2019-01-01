#include <bits/stdc++.h>
#include <atomic>
#include <thread>
const char* value[] =
{
    "73167176531330624919225119674426574742355349194934",
    "96983520312774506326239578318016984801869478851843",
    "85861560789112949495459501737958331952853208805511",
    "12540698747158523863050715693290963295227443043557",
    "66896648950445244523161731856403098711121722383113",
    "62229893423380308135336276614282806444486645238749",
    "30358907296290491560440772390713810515859307960866",
    "70172427121883998797908792274921901699720888093776",
    "65727333001053367881220235421809751254540594752243",
    "52584907711670556013604839586446706324415722155397",
    "53697817977846174064955149290862569321978468622482",
    "83972241375657056057490261407972968652414535100474",
    "82166370484403199890008895243450658541227588666881",
    "16427171479924442928230863465674813919123162824586",
    "17866458359124566529476545682848912883142607690042",
    "24219022671055626321111109370544217506941658960408",
    "07198403850962455444362981230987879927244284909188",
    "84580156166097919133875499200524063689912560717606",
    "05886116467109405077541002256983155200055935729725",
    "71636269561882670428252483600823257530420752963450"
};

typedef std::pair<int, int> pii;
typedef long long ll;

int n = sizeof(value) / sizeof(value[0]);
int m = strlen(value[0]);
std::atomic_llong ans(0);
std::atomic_int count(0);
void bfs(int i, int j) {
    const int N = 13;
    std::queue< std::set<pii> > q;
    std::set<pii> op; op.insert(std::make_pair(i, j));
    q.push(op);
    long long t_ans = 0;
    while(q.size()) {
        std::set<pii> now = q.front(); q.pop();
        if(now.size() == N) {
            ll product = 1;
            for(pii s: now) {
                product *= value[s.first][s.second] - '0';
            }
            t_ans = std::max(t_ans, product);
            continue;
        }
        int x = now.rbegin()->first;
        int y = now.rbegin()->second;
        for(int dx = -1; dx <= 1; dx++)
            for(int dy = -1; dy <= 1; dy++)
                if(std::abs(dx) + std::abs(dy) == 1)  {
                    int tx = x + dx, ty = y + dy;
                    if(tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                    if(now.find(std::make_pair(tx, ty)) == now.end()) {
                        std::set<pii> next = now;
                        next.insert(std::make_pair(tx, ty));
                        q.push(next);
                    }
                }
    }
    if(t_ans > ans.load())
        ans.store(t_ans);
    printf("finish: %d %d\n", i, j);
    count.store(count.load() - 1);
}

int main() {
    std::vector<std::thread> threads;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            threads.push_back(std::thread(bfs, i, j));
            if(threads.size() == 4) {
                count.store(4);
                for(auto &th : threads)
                    th.join();
                while(count != 0);
                threads.clear();
            }
        }


    printf("result: %lld\n", ans.load());
    return 0;
}

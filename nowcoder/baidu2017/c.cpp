#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


pair<int, int>p[5000];
int main()  {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &p[i].first, &p[i].second);
        }
        int tot = 0;
        sort(p, p + n);
        int cur = p[0].first;
        for(int i = 0; i < n; i++) {
            tot += (cur - p[i].first);
            cur += p[i].second;
        }
        /*
        priority_queue< pair<int, int> >q;
        int tot = 0;
        int J = 0;
        while(true) {
            while(J < n && p[J].first <= cur) {
                q.push(make_pair(-p[J].second, -p[J].first));
                J++;
            }
            if(q.size()) {
                pair<int, int> t = q.top();
                q.pop();
                tot += cur + t.second;
                cout << cur + t.second << endl;
                cur -= t.first;
                cout << t.second << " " << t.first << endl;
            }
            else cur++;
            if(q.size() == 0 && J == n)  break;
        }
        */
       printf("%.4f\n", 1.0 * tot / n);
    }
    return 0;
}


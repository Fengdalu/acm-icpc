/*
* 倍增算法 , r 为待匹配数组,
* n 为总长度 +1 , m 为字符范围 , num 保存字符串
* 使用时注意 num[] 有效位为 [0, n) ,
* 但是需要将 num[n] = 0 ,
* 另外 , 对于模板的处理将空串也处理了 ,
* 作为rank最小的串 ,
* 因此有效串为 [0, n] 共 n-1 个 ,
* 在调用da()函数时, 需要调用 da(num, n + 1, m)
* 对于 sa[], rank[], height[] 数组都将空串考虑在内, 作为 rank 最小的后缀
* 注意 rank , height 范围从 [0, n]
*/

const int N = 1e5;
namespace SA
{
    int len;
    int num[N];
    // sa[1~n]value(0~n-1) ; rank[0..n-1] value(1..n) ; height[2..n]
    int sa[N], rank[N], height[N];
    int wa[N], wb[N], wv[N], wd[N];

    int cmp(int *r, int a, int b, int x) {
        return r[a] == r[b] && r[a + x] == r[b + x];
    }

    //  倍增算法 r 为待匹配数组  n 为总长度 +1 , m 为字符范围
    void da(int *r, int n, int m) {
        int i, j, k, p, *x = wa, *y = wb, *t;
        for(i = 0; i < m; i++) wd[i] = 0;
     for(i = 0; i < n; i++) wd[x[i] = r[i]]++;
        for(i = 1; i < m; i++) wd[i] += wd[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
        for(j = 1, p = 1; p < n; j <<= 1, m = p) {
            for(p = 0, i = n - j; i < n; i++) y[p++] = i;
            for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
            for(i = 0; i < n; i++) wv[i] = x[y[i]];
            for(i = 0; i < m; i++) wd[i] = 0;
            for(i = 0; i < n; i++) wd[wv[i]]++;
            for(i = 1; i < m; i++) wd[i] += wd[i - 1];
            for(i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
            for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
                x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
            }
        }

        for(i = 0, k = 0; i < n; i++) rank[sa[i]] = i;
        for(i = 0; i < n - 1; height[rank[i++]] = k) {
            for(k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
        }
    }
}

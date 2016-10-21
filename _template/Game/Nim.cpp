// hdu 3404

const int maxn = 22;
int f[maxn][maxn];
int nim (int x, int y);
int _nim (int x, int y) {
    if (!x || !y) return 1 << (x + y);
    int &F = f[x][y];
    if (F != -1) return F;
    int ret = 1, e = 1;
    for (int i = 0; i < 16; ++i)
        if ( ( (x ^ y) >> i) & 1) e *= 1 << (1 << i);
        else if ( (x >> i) & 1) ret = nim (ret, 3 * (1 << (1 << i)) / 2);
    return F = nim (ret, e);
}
int nim (int x, int y) {        // nim 积调用
    if (x < 2 || y < 2) return x * y;
    int ret = 0;
    for (int i = 0; i < 16; ++i)
        if ( (x >> i) & 1)
            for (int j = 0; j < 16; ++j)
                if ( (y >> j) & 1)
                    ret ^= _nim (i, j);
    return ret;
}

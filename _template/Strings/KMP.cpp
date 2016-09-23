/* Hdu 1711
*/
const int N = 2000000;

int Next[N];
int a[N], b[N];
// a 为主串 ， b 为钥串
void getNext(int b[N], int m) {
    int j,k;
    j = 0;
    k = -1;
    Next[0] = -1;
    while(j < m) {
        if(k == -1 || b[j] == b[k])
            Next[++j] = ++k;
        else k = Next[k];
    }
}
// 得到 b 在 a 中的第一次出现位置
// 因为 next 与 STL 冲突所以用Next代替
int KMP_Index(int a[N], int b[N], int n, int m) {
    int i = 0, j = 0;
    getNext(b, m);
    while(i < n && j < m) {
        if(j == -1||a[i] == b[j]) {
            i++;
            j++;
        }
        else j = Next[j];
    }
    if(j == m) return i - m + 1;
    else return -1;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define N 5010
#define INF 1e200
int a1[N], b1[N], a2[N], b2[N];
int n;
double f[N];
int sa1[N];
int sa2[N];
int sb1[N];
int sb2[N];
double c[N][N];

void gen()
{
    freopen("braess.in ", "w", stdout);
    cout << 5000 << endl;
    for(int i = 0; i < 5000; i++)
    {
        cout << 1000; cout << " ";
        cout << 1; cout << " ";
        cout << 1000; cout << " ";
        cout << 1; cout << " ";
        cout << endl;
    }
    fclose(stdout);
}

double cal1()
{
    static int A, B, A1, B1;
    A = B = A1 = B1 = 0;
    for(int i = 0; i < n; i++) { A += a1[i]; B += b1[i]; };
    for(int i = 0; i < n; i++) { A1 += a2[i]; B1 += b2[i]; };

    if(A == 0 && A1 == 0) return min(B, B1);
    double p = ((double)A1 + B1 - B) / (A + A1);
    if((A1 + B1 - B) >= (A + A1)) return A + B;
    else if(A1 + B1 <= B) return A1 + B1;
    else return (double)A * p + B;
}

double cal2()
{
    static int A, B, A1, B1;
    static double p;
    double ans = 0;

    for(int i = 0; i < n; i++)
    {
        A = a1[i]; B = b1[i]; A1 = a2[i]; B1 = b2[i];
        if(A == 0 && A1 == 0) { ans += min(B, B1); continue; }
        double p = ((double)A1 + B1 - B) / (A + A1);
        if((A1 + B1 - B) >= (A + A1)) ans += (A + B);
        else if(A1 + B1 <= B) ans += (A1 + B1);
        else ans += ((double)A * p + B);
    }
    return ans;
}

int ss(int s[N], int i, int j)
{
    if(i == 0) return s[j];
    return s[j] - s[i - 1];
}

double init()
{
    static int A, B, A1, B1;
    memset(sa1, 0, sizeof sa1);
    memset(sa2, 0, sizeof sa2);
    memset(sb1, 0, sizeof sb1);
    memset(sb2, 0, sizeof sb2);

    sa1[0] = a1[0];
    for(int i = 1; i < n; i++) sa1[i] = sa1[i - 1] + a1[i];
    sa2[0] = a2[0];
    for(int i = 1; i < n; i++) sa2[i] = sa2[i - 1] + a2[i];
    sb1[0] = b1[0];
    for(int i = 1; i < n; i++) sb1[i] = sb1[i - 1] + b1[i];
    sb2[0] = b2[0];
    for(int i = 1; i < n; i++) sb2[i] = sb2[i - 1] + b2[i];

    memset(c, 0, sizeof c);
    for(int i = 0; i < n; i++) for(int j = i; j < n; j++)
    {
        A = ss(sa1, i, j); B = ss(sb1, i, j); A1 = ss(sa2, i, j); B1 = ss(sb2, i, j);
        if(A == 0 && A1 == 0) { c[i][j] = min(B, B1); continue; }
        double p = ((double)A1 + B1 - B) / (A + A1);
        if((A1 + B1 - B) >= (A + A1)) c[i][j] = A + B;
        else if(A1 + B1 <= B) c[i][j] = A1 + B1;
        else c[i][j] = (double)A * p + B;
    }
    /*
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
    {
        printf("%5.2f ", c[i][j]);
        if(j == n - 1)putchar('\n');
    }
    */
}

double cal3()
{
    for(int i = 0; i < n; i++) f[i] = INF;
    for(int i = 0; i < n; i++)
    {
        f[i] = c[0][i];
        for(int j = 0; j < i; j++)
            f[i] = min(f[i], f[j] + c[j + 1][i]);
    }
    //for(int i = 0; i < n; i++) printf("%.2f ", f[i]);
    //putchar('\n');
    return f[n - 1];
}

double cal4()
{
    memset(f, 0, sizeof f);
    for(int i = 0; i < n; i++)
    {
        f[i] = c[0][i];
        for(int j = 0; j < i; j++)
            f[i] = max(f[i], f[j] + c[j + 1][i]);
    }
    return f[n - 1];
}

int main()
{
    //
    //gen(); return 0;
    freopen("braess.in ", "r", stdin);
    freopen("braess.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d%d%d%d", &a1[i], &b1[i], &a2[i], &b2[i]);
    init();
    cout <<fixed<<setprecision(10)<<cal1() << endl;
    cout <<fixed<<setprecision(10)<<cal2() << endl;
    cout <<fixed<<setprecision(10)<<cal3() << endl;
    cout <<fixed<<setprecision(10)<<cal4() << endl;
    fclose(stdout);
    return 0;
}
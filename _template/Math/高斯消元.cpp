// 二进制版本 , hdu5833
#include <bits/stdc++.h>
const int N = 1000;
std::bitset<N>a[N];
int gauss(int eq, int var) {
    int line = 0, ret = 0;
    for(int i = 0; i < var; i++) {
        int target = line;
        while(target < eq && a[target][i] == 0) target++;
        if(target == eq) { ret++; continue; }
        swap(a[target], a[line]);
        for(int j = 0; j < eq; j++) if(j != line && a[j][i]) a[j] ^= a[line];
        line++;
    }
    return ret;
}

// 小数版本 , hdu 5833
int Gauss(int equ, int var) {
    int i, j, k;
    int max_r; // 当前这列绝对值最大的行 .
    int col; // 当前处理的列
    // 转换为阶梯阵 .
    col = 0; // 当前处理的列
    for(k = 0; k < equ && col < var; k++,col++) {
        // 枚举当前处理的行 .
        // 找到该 col 列元素绝对值最大的那行与第 k 行交换  .
        // (为了在除法时减小误差)
        max_r=k;
        for(i = k + 1; i < equ; i++) {
            if((a[i][col]) > (a[max_r][col])) max_r = i;
        }
        if(max_r != k) {
            // 与第k行交换 .
            for(j=k; j<var+1; j++) swap(a[k][j], a[max_r][j]);
        }
        if((a[k][col])==0) {
            // 说明该 col 列第 k 行以下全是 0 了 , 则处理当前行的下一列 .
            k--;
            continue;
        }
        for(i=k+1; i<equ; i++) {
            // 枚举要删去的行 .
            if((a[i][col]) > 0) {
                for(j = var; j >= col; j--) {
                    a[i][j] ^= a[k][j] * (a[i][col] / a[k][col]);
                }
            }
        }
    }
    // 无穷解 , 返回自由变元个数
    // 会改变解的顺序
    if(k < var) {
        for(int i=0; i<equ; i++) {
            if(a[i][i]!= 0) continue;
            else {
                int flag=0;
                for(int j=i+1; j<var; j++) {
                    if(a[i][j] != 0) {
                        flag = 1;
                        for(int k = 0; k <= i; k++) {
                            swap(a[k][i], a[i][j]);
                        }
                        break;
                    }
                }
                if(!flag)
                    return var - i;
            }
        }
        return var - equ;
    }
    return 0;
}

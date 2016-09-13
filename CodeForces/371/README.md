# CodeForces 371

## A

区间交

## B
set计数，讨论元素个数

## C
dp[mask]表示mask状态下的数目，计数
 
## D

六次二分

## E

首先令a[i]-i，构造不下降序列，设dp[i][j]表示在i位置为j的最小值，转移为dp[i][j] = dp[i - 1][k], k <= j，维护pre[j]，表示在i下k<=j的最小值
 
 
 
 
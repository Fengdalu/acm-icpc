#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <math.h>
using namespace std;

const int N = 3000005;

int prime[N];
int phi[N];
bool is_prime[N];

void get_phi()
{
    int i, j, k;
    k = 0;
    for(i = 2; i < N; i++)
    {
        if(is_prime[i] == false)
        {
            prime[k++] = i;
            phi[i] = i-1;
        }
        for(j = 0; j<k && i*prime[j]<N; j++)
        {
            is_prime[ i*prime[j] ] = true;
            if(i%prime[j] == 0)
            {
                phi[ i*prime[j] ] = phi[i] * prime[j];
                break;
            }
            else
            {
                phi[ i*prime[j] ] = phi[i] * (prime[j]-1);
            }
        }
    }
}

int main()
{
    get_phi();
    int T; scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", phi[n + 1]);
    }
    return 0;
}


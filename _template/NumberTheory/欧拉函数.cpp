/*
* 对正整数 $n$ ,
* 欧拉函数是少于或等于$n$的数中与$n$互质的数的数目
* $P$是素数 :
* 若$p$是$x$的约数 , 则$ E(x p)=E(x)p $
* $p$不是$x$的约数 , 则$ E(x p)=E(x)E(p)=E(x)(p-1) $
*/
const int N = 1e5;
int prime[N];
int phi[N];
bool is_prime[N];

void get_phi() {
    int i, j, k;
    k = 0;
    for(i = 2; i < N; i++) {
        if(is_prime[i] == false) {
            prime[k++] = i;
            phi[i] = i - 1;
        }
        for(j = 0; j < k && i * prime[j] < N; j++) {
            is_prime[ i * prime[j] ] = true;
            if( i % prime[j] == 0) {
                phi[ i * prime[j] ] = phi[i] * prime[j];
                break;
            }
            else {
                phi[ i * prime[j] ] = phi[i] * ( prime[j] - 1 );
            }
        }
    }
}

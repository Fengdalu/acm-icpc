LL ind[MOD], nt[N], v[N];

bool find(LL x)
{
	LL p = abs(x) % MOD;
	for(int k = ind[p]; p != 0; p = nt[p]) if(v[k] == x) return true;
	return false;
}

void add(LL x)
{
	cnt++;
	LL p = abs(x) % MOD;
	v[cnt] = x;
	nt[cnt] = ind[p];
	ind[p] = cnt;
}

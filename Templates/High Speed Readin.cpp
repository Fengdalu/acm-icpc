void gn(LL &x){
    char c;
    LL sgn=1;
    while(((c=getchar())<'0'||c>'9') && c!='-');
    if(c=='-')sgn=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sgn;
}
#include<cstdio>
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<__int64>s;
    __int64 sum,t;
    char str[8];
    int n,i,e;
    while(scanf("%d",&n) != EOF){
        s.clear();
            e=0;
        for(i = 0 ; i < n ; i ++){
            scanf("%s",str);
            if(str[0] == 'a'){
                scanf("%I64d",&t);
                s.insert(lower_bound(s.begin(),s.end(),t),t);
                e++;
            }
            else if(str[0] == 'd'){
                scanf("%I64d",&t);
                s.erase(lower_bound(s.begin(),s.end(),t));
            }
            else{
                sum=0;
               // set<__int64>::iterator ite;
                //ite=s.begin();
                if(e>=3){
                for(int j=2;j<s.size();j+=5)
                {

                    sum+=s[j];

                }
                }
                printf("%I64d\n",sum);
            }
        }
    }
    return 0;
}

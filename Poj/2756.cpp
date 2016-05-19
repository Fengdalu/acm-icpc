#include"iostream"
#include"string"
using namespace std;
int alen1,alen2;
string s1,s2;
int sum[50000],an[50000],am[50000];
bool compare();
void Jian(string s1,string s2)
{
    int i,s,f;
    memset(an,0,sizeof(an));
    memset(am,0,sizeof(am));
    memset(sum,0,sizeof(sum));
    alen1=s1.size();
    alen2=s2.size();
    f=0;
    for(i=0;i<alen1;i++)
        an[i]=s1[alen1-i-1]-'0';
    for(i=0;i<alen2;i++)
        am[i]=s2[alen2-i-1]-'0';
    if(alen1>alen2||(alen1==alen2&&s1[0]>=s2[0]))
    {
        for(i=0;i<alen1;i++)
        {
            sum[i]=an[i]-am[i];
            if(sum[i]<0)
            {
                sum[i]+=10;
                an[i+1]--;
            }
        }
    }
    else
    {
        for(i=0;i<alen2;i++)
        {
            sum[i]=am[i]-an[i];
            if(sum[i]<0)
            {
                sum[i]+=10;
                am[i+1]--;
            }
        }
        f=1;
        
    }
    s=i;
    while(s>=0)
    {
        if(s==0){cout<<sum[0];break;}
        if(sum[s]){
            if(f)cout<<"-";
            cout<<sum[s];break;
        }
        s--;
    }
    for(i=s-1;i>=0;i--)cout<<sum[i];
    cout<<endl;
}

void Jia(string s1,string s2)
{
    int i,j,t,t2,k;
    t=0;k=0;
    t2=s2.size()-1;
    for(i=s1.size()-1;i>=0;i--)
    {
        if(t2>=0)
        {
            sum[t++]=(s1[i]-'0'+s2[t2]-'0')+k;
            k=0;
            if(sum[t-1]>=10){
                k=1;
                sum[t-1]-=10;
            }
            t2--;
        }
        else {
            sum[t++]=(s1[i]-'0')+k;
            k=0;
            if(sum[t-1]>=10){
                k=1;
                sum[t-1]-=10;
            }
        }
        
    }
    for(j=t2;j>=0;j--)
    {
        sum[t++]=(s2[j]-'0')+k;
        k=0;
        if(sum[t-1]>=10){
            k=1;
            sum[t-1]-=10;
        }
    }
	   if(k)cout<<k;
	   for(i=t-1;i>=0;i--)cout<<sum[i];
	   cout<<endl;
}

int main()
{
    int t,f1,f2;
    cin>>t;
    while(t--)
    {
        memset(sum,0,sizeof(sum));
        f1=f2=1;
        cin>>s1>>s2;
        if(s1[0]=='+')s1.erase(0,1);
        if(s2[0]=='+')s2.erase(0,1);
        if(s1[0]=='-'){f1=-1;s1.erase(0,1);}
        if(s2[0]=='-'){f2=-1;s2.erase(0,1);}
        if(f1*f2==1)
        {
            if(f1==1)Jia(s1,s2);
            else {
                cout<<"-";
                Jia(s1,s2);
            }
        }
        else {
            if(f1==-1)
            {
                Jian(s2,s1);
            }
            else Jian(s1,s2);
        }
    }		
    
    return 0;
}
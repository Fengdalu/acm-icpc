#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    int n;
    cin>>n;
    
    for (int i = 1; i <= n; i++)
    {
        float a, b;
        cin>>a>>b;
        float x = (a * a + b * b) * 3.1415;
        
        cout<<"Property "<<i<<": This property will begin eroding in year "<<ceil(x / 100)<<"."<<endl;
    }
    
    cout<<"END OF OUTPUT."<<endl;
    
    return 0;
}
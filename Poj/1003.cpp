#include <stdio.h>

using namespace std;

int main()
{
    float f;
    while (scanf("%f", &f) == 1)
    {
        if (f == 0) break;
        int i;
        for (i = 1; f > 0; i++)
        {
            f -= 1 / (float)(i + 1);
        }
        
        printf("%d card(s)\n", i - 1);
    }
    
    return 0;
}
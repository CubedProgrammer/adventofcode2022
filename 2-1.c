#include<stdio.h>
unsigned outcome(unsigned oppo, unsigned self)
{
    if(oppo == 2 && self == 2)
        return 7;
    else if(oppo == 0 && self == 0)
        return 3;
    else
        return self * 4 + oppo;
}
int main(int argl, char *argv[])
{
    char o, s;
    unsigned score = 0;
    o = getchar();
    getchar();
    s = getchar();
    getchar();
    while(!feof(stdin))
    {
        o -= 'A';
        s -= 'X';
        score += outcome(o, s);
        o = getchar();
        getchar();
        s = getchar();
        getchar();
    }
    printf("%u\n", score);
    return 0;
}

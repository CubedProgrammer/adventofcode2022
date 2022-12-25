#include<stdio.h>
unsigned outcome(unsigned oppo, unsigned self)
{
    if(oppo == 0 && self == 2)
        return 0;
    else if(oppo == 2 && self == 0)
        return 6;
    else
        return(self + 1 - oppo) * 3;
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
        score += outcome(o, s) + s + 1;
        o = getchar();
        getchar();
        s = getchar();
        getchar();
    }
    printf("%u\n", score);
    return 0;
}

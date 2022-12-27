#include<stdio.h>
int main(int argl, char *argv[])
{
    char instr[5];
    int op, x = 1;
    int sig = 0;
    unsigned cycle = 0, next = 18;
    while(scanf("%s", instr) == 1)
    {
        if(instr[0] == 'a')
        {
            scanf("%d", &op);
            x += op;
            cycle += 2;
        }
        else
            ++cycle;
        if(cycle >= next)
        {
            sig += x * (next + 2);
            if(next == 218)
                next = 9999;
            else
                next += 40;
        }
    }
    printf("%d\n", sig);
    return 0;
}

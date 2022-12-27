#include<stdio.h>
int main(int argl, char *argv[])
{
    char instr[5];
    char screen[240];
    int op, x = 1;
    int sig = 0;
    int cycle = 0, pos;
    while(scanf("%s", instr) == 1)
    {
        pos = cycle % 40;
        if(pos >= x - 1 && pos <= x + 1)
            screen[cycle] = '#';
        else
            screen[cycle] = '.';
        ++cycle;
        if(instr[0] == 'a')
        {
            scanf("%d", &op);
            pos = cycle % 40;
            if(pos >= x - 1 && pos <= x + 1)
                screen[cycle] = '#';
            else
                screen[cycle] = '.';
            ++cycle;
            x += op;
        }
    }
    for(int i = 0; i < 6; ++i)
    {
        fwrite(screen + i * 40, 1, 40, stdout);
        putchar('\n');
    }
    return 0;
}

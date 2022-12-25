#include<stdio.h>
#include<string.h>
#define scan(l, m, n)scanf("move %u from %u to %u", &(l), &(m), &(n))
int main(int argl, char *argv[])
{
    unsigned n, from, to;
    unsigned height = 0, chcnt = 0;
    unsigned stkcnt;
    unsigned stklen[9];
    char tops[10];
    char stacks[9][81];
    memset(stacks, 0, sizeof stacks);
    for(char ch = getchar(); ch != '1'; ch = getchar())
    {
        ++chcnt;
        if(ch >= 'A' && ch <= 'Z')
            stacks[chcnt >> 2][height] = ch;
        else if(ch == '\n')
        {
            ++height;
            chcnt = 0;
        }
    }
    while((n = getchar()) != '\n')
    {
        if(n != ' ')
            stkcnt = n - '0';
    }
    for(unsigned i = 0; i < height >> 1; ++i)
    {
        for(unsigned j = 0; j < stkcnt; ++j)
            stacks[j][i] ^= stacks[j][height - i - 1] ^= stacks[j][i] ^= stacks[j][height - i - 1];
    }
    for(unsigned j = 0; j < stkcnt; ++j)
        for(unsigned i = 0; stacks[j][i] != 0; stklen[j] = ++i);
    getchar();
    while(scan(n, from, to) == 3)
    {
        getchar();
        --from, --to;
        for(; n; --n)
            stacks[to][stklen[to]++] = stacks[from][--stklen[from]];
    }
    for(unsigned j = 0; j < stkcnt; ++j)
        tops[j] = stacks[j][stklen[j] - 1];
    tops[stkcnt] = '\0';
    printf("%s\n", tops);
    return 0;
}

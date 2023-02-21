#include<stdio.h>
#include<string.h>
#define STONE '#'
#define EMPTY '.'
char grid[1000][1000];
int rdln(char *buf)
{
    int ch = getchar();
    if(ch == -1)
        return 0;
    for(*buf = ch; *buf != '\n'; *++buf = getchar());
    *buf = 0;
    return 1;
}
int main(int argl, char *argv[])
{
    char cbuf[361];
    char *str;
    unsigned x, y;
    unsigned lx, ly;
    unsigned from, to;
    unsigned cnt = 0;
    char abyss = 0;
    memset(grid, EMPTY, sizeof grid);
    while(rdln(cbuf))
    {
        str = cbuf;
        sscanf(str, "%u,%u", &lx, &ly);
        for(; *str && *str != '-'; ++str);
        str += 3 * (*str == '-');
        while(sscanf(str, "%u,%u", &x, &y) == 2)
        {
            for(; *str && *str != '-'; ++str);
            str += 3 * (*str == '-');
            if(lx == x)
            {
                if(ly < y)
                    from = ly, to = y;
                else
                    from = y, to = ly;
                for(; from <= to; ++from)
                    grid[from][x] = STONE;
            }
            else
            {
                if(lx < x)
                    from = lx, to = x;
                else
                    from = x, to = lx;
                for(; from <= to; ++from)
                    grid[y][from] = STONE;
            }
            lx = x, ly = y;
        }
    }
    for(;; ++cnt)
    {
        x = 500, y = 0;
        while(!abyss)
        {
            ++y;
            if(grid[y][x] == EMPTY);
            else if(grid[y][x - 1] == EMPTY)
                --x;
            else if(grid[y][x + 1] == EMPTY)
                ++x;
            else
            {
                grid[--y][x] = STONE;
                break;
            }
            if(y == 999)
                abyss = 1;
        }
        if(abyss)
            break;
    }
    printf("%u\n", cnt);
    return 0;
}

#include<stdio.h>
#include<string.h>
struct posi
{
    int x, y;
    char exist;
};
int main(int argl, char *argv[])
{
    struct posi htable[57913];
    char dir;
    unsigned const bcnt = 57913;
    unsigned num, ind;
    int dx, dy;
    int htx, hty;
    int hx = 0, hy = 0;
    int tx = 0, ty = 0;
    unsigned cnt = 0;
    memset(htable, 0, sizeof htable);
    dir = getchar();
    while(!feof(stdin))
    {
        getchar();
        num = 0;
        for(char ch = getchar(); ch != '\n'; ch = getchar())
            num = num * 10 + ch - '0';
        switch(dir)
        {
            case'D':
                dx = 0;
                dy = 1;
                break;
            case'U':
                dx = 0;
                dy = -1;
                break;
            case'R':
                dx = 1;
                dy = 0;
                break;
            case'L':
                dx = -1;
                dy = 0;
                break;
        }
        for(; num; --num)
        {
            hx += dx;
            hy += dy;
            htx = hx - tx;
            hty = hy - ty;
            if(htx > 1 || htx < -1 || hty > 1 || hty < -1)
            {
                if(htx < -1)
                    htx = -1;
                else if(htx > 1)
                    htx = 1;
                if(hty < -1)
                    hty = -1;
                else if(hty > 1)
                    hty = 1;
                tx += htx;
                ty += hty;
            }
            ind = ty * 76000 + tx;
            ind %= bcnt;
            for(; htable[ind].exist; ++ind)
            {
                if(htable[ind].x == tx && htable[ind].y == ty)
                    break;
                if(ind + 1 == bcnt)
                    ind = -1;
            }
            if(!htable[ind].exist)
            {
                htable[ind].x = tx;
                htable[ind].y = ty;
                htable[ind].exist = 1;
                ++cnt;
            }
        }
        dir = getchar();
    }
    printf("%u\n", cnt);
    return 0;
}

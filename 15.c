#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DESIRED 2000000
int icmpr(const void *x, const void *y)
{
    int ix = *(const int*)x, iy = *(const int*)y;
    return ix > iy ? 1 : ix < iy ? -1 : 0;
}
int nxtln(char *buf)
{
    char ch, *it;
    for(it = buf, ch = getchar(); ch != '\n' && !feof(stdin); *it++ = ch, ch = getchar());
    *it = '\0';
    return!(it == buf && ch != '\n');
}
int main(int argl, char *argv[])
{
    int begins[60], ends[60];
    char ln[361];
    char *it;
    int sx, sy, bx, by;
    int dist, range;
    unsigned cnt = 0, tot = 0;
    while(nxtln(ln))
    {
        it = strchr(ln, '=') + 1;
        sx = atoi(it);
        it = strchr(it, '=') + 1;
        sy = atoi(it);
        it = strchr(it, '=') + 1;
        bx = atoi(it);
        it = strchr(it, '=') + 1;
        by = atoi(it);
        dist = abs(DESIRED - sy);
        range = abs(sx - bx) + abs(sy - by) - dist;
        if(range > 0)
        {
            begins[cnt] = sx - range;
            ends[cnt] = sx + range;
            ++cnt;
        }
    }
    qsort(begins, cnt, sizeof(int), icmpr);
    qsort(ends, cnt, sizeof(int), icmpr);
    if(cnt > 0)
        tot = ends[0] - begins[0];
    for(unsigned i = 1; i < cnt; ++i)
    {
        if(ends[i - 1] > begins[i])
            begins[i] = ends[i - 1];
        tot += ends[i] - begins[i];
    }
    printf("%u\n", tot);
    return 0;
}

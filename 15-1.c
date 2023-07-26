#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef LENGTH
#define LENGTH 4000001
#endif
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
    char ln[361];
    char *it;
    int sx, sy, bx, by;
    int dist, range;
    unsigned cnt = 0;
    long tot = 0;
    int **begins = malloc(LENGTH * sizeof(*begins));
    int **ends = malloc(LENGTH * sizeof(*ends));
    for(unsigned i = 0; i < LENGTH; ++i)
    {
        begins[i] = malloc(60 * sizeof(*begins[i]));
        ends[i] = malloc(60 * sizeof(*ends[i]));
    }
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
        for(int i = 0; i < LENGTH; ++i)
        {
            dist = abs(i - sy);
            range = abs(sx - bx) + abs(sy - by) - dist;
            if(range < 0)
                ends[i][cnt] = begins[i][cnt] = 0;
            else
            {
                begins[i][cnt] = sx - range;
                ends[i][cnt] = sx + range + 1;
            }
        }
        ++cnt;
    }
    for(unsigned i = 0; i < LENGTH; ++i)
    {
        qsort(begins[i], cnt, sizeof(int), icmpr);
        qsort(ends[i], cnt, sizeof(int), icmpr);
    }
    for(unsigned i = 0; i < LENGTH; ++i)
    {
        for(unsigned j = 1; j < cnt; ++j)
        {
            if(ends[i][j - 1] < begins[i][j] && ends[i][j - 1] >= 0 && ends[i][j - 1] < LENGTH)
                tot = ends[i][j - 1] * (long)(LENGTH - 1) + i;
        }
        if(ends[i][cnt - 1] >= 0 && ends[i][cnt - 1] < LENGTH)
            tot = ends[i][cnt - 1] * (long)(LENGTH - 1) + i;
    }
    printf("%li\n", tot);
    return 0;
}

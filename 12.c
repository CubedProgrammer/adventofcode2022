#include<stdio.h>
int main(int argl, char *argv[])
{
    unsigned startx, starty;
    unsigned endx, endy;
    char h;
    char hmap[1000][1000];
    short dist[1000][1000];
    int q[9001];
    unsigned r = 0, c = 0;
    unsigned ind = 0;
    unsigned qfront = 0, qend = 0;
    for(char ch = getchar(); !feof(stdin); ch = getchar())
    {
        if(ch == '\n')
        {
            c = ind;
            ind = 0;
            ++r;
        }
        else
        {
            dist[r][ind] = 9999;
            if(ch == 'S')
            {
                dist[r][ind] = 0;
                starty = r;
                startx = ind;
                ch = 'a';
            }
            else if(ch == 'E')
            {
                endy = r;
                endx = ind;
                ch = 'z';
            }
            hmap[r][ind] = ch;
            ++ind;
        }
    }
    q[0] = starty * c + startx;
    ++qfront;
    while(qfront != qend)
    {
        startx = q[qend] % c;
        starty = q[qend] / c;
        h = hmap[starty][startx];
        if(starty > 0)
        {
            if(h + 1 >= hmap[starty - 1][startx] && dist[starty - 1][startx] == 9999)
            {
                dist[starty - 1][startx] = dist[starty][startx] + 1;
                q[qfront] = q[qend] - c;
                ++qfront;
            }
        }
        if(startx > 0)
        {
            if(h + 1 >= hmap[starty][startx - 1] && dist[starty][startx - 1] == 9999)
            {
                dist[starty][startx - 1] = dist[starty][startx] + 1;
                q[qfront] = q[qend] - 1;
                ++qfront;
            }
        }
        if(starty + 1 < r)
        {
            if(h + 1 >= hmap[starty + 1][startx] && dist[starty + 1][startx] == 9999)
            {
                dist[starty + 1][startx] = dist[starty][startx] + 1;
                q[qfront] = q[qend] + c;
                ++qfront;
            }
        }
        if(startx + 1 < c)
        {
            if(h + 1 >= hmap[starty][startx + 1] && dist[starty][startx + 1] == 9999)
            {
                dist[starty][startx + 1] = dist[starty][startx] + 1;
                q[qfront] = q[qend] + 1;
                ++qfront;
            }
        }
        ++qend;
    }
    printf("%d\n", dist[endy][endx]);
    return 0;
}

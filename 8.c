#include<stdio.h>
#include<string.h>
int main(int argl, char *argv[])
{
    char heights[99][99];
    char visi[99][99];
    unsigned tall;
    unsigned r = 0, c = 0;
    unsigned tot = 0;
    memset(visi, 0, sizeof visi);
    for(int ch = getchar(); ch > 0; ch = getchar())
    {
        if(ch == '\n')
        {
            ++r;
            c = 0;
        }
        else
        {
            heights[r][c] = ch;
            ++c;
        }
    }
    c = r;
    for(unsigned i = 0; i < r; ++i)
    {
        tall = 0;
        for(unsigned j = 0; j < c; ++j)
        {
            if(heights[i][j] > tall)
            {
                visi[i][j] = 1;
                tall = heights[i][j];
            }
        }
    }
    for(unsigned i = 0; i < r; ++i)
    {
        tall = 0;
        for(int j = c - 1; j >= 0; --j)
        {
            if(heights[i][j] > tall)
            {
                visi[i][j] = 1;
                tall = heights[i][j];
            }
        }
    }
    for(int i = c - 1; i >= 0; --i)
    {
        tall = 0;
        for(unsigned j = 0; j < r; ++j)
        {
            if(heights[j][i] > tall)
            {
                visi[j][i] = 1;
                tall = heights[j][i];
            }
        }
    }
    for(int i = c - 1; i >= 0; --i)
    {
        tall = 0;
        for(int j = r - 1; j >= 0; --j)
        {
            if(heights[j][i] > tall)
            {
                visi[j][i] = 1;
                tall = heights[j][i];
            }
        }
    }
    for(unsigned i = 0; i < r; ++i)
    {
        for(unsigned j = 0; j < c; ++j)
            tot += visi[i][j];
    }
    printf("%u\n", tot);
    return 0;
}

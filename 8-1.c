#include<stdio.h>
int main(int argl, char *argv[])
{
    char heights[99][99];
    unsigned curr;
    unsigned left, right, d, u;
    unsigned r = 0, c = 0;
    unsigned tot = 0;
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
        for(unsigned j = 0; j < c; ++j)
        {
            left = right = d = u = 0;
            for(unsigned k = i; k > 0 && heights[k - 1][j] < heights[i][j]; --k, ++u);
            for(unsigned k = j; k > 0 && heights[i][k - 1] < heights[i][j]; --k, ++left);
            for(unsigned k = i + 1; k < r && heights[k][j] < heights[i][j]; ++k, ++d);
            for(unsigned k = j + 1; k < c && heights[i][k] < heights[i][j]; ++k, ++right);
            left += left < j;
            right += right < c - j - 1;
            d += d < r - i - 1;
            u += u < i;
            curr = left * right * d * u;
            tot = curr > tot ? curr : tot;
        }
    }
    printf("%u\n", tot);
    return 0;
}

#include<stdio.h>
#include<string.h>
#define scanl(x) scanf("%li", &(x))
#define scanu(x) scanf("%u", &(x))
long addition(long m, long n)
{
    return m + n;
}
long multiplication(long m, long n)
{
    return m * n;
}
long square(long m, long n)
{
    return m * m;
}
void readuntil(char c)
{
    for(int rd = getchar(); rd > 0 && rd != c; rd = getchar());
}
int main(int argl, char *argv[])
{
    unsigned ind;
    unsigned maxi, prod;
    long item[8][60];
    unsigned itemcnt[8];
    char op;
    long(*ops[8])(long m, long n);
    long nums[8];
    unsigned mod[8];
    unsigned true[8], false[8];
    unsigned inspected[8];
    unsigned monkey = 0;
    memset(itemcnt, 0, sizeof itemcnt);
    readuntil(':');
    for(;!feof(stdin);++monkey)
    {
        readuntil(':');
        for(scanl(item[monkey][itemcnt[monkey]++]); getchar() == ','; scanl(item[monkey][itemcnt[monkey]++]));
        readuntil('d');
        getchar();
        op = getchar();
        switch(op)
        {
            case'+':
                ops[monkey] = addition;
                break;
            case'*':
                ops[monkey] = multiplication;
                break;
        }
        if(scanl(nums[monkey]) == 0)
            ops[monkey] = square;
        readuntil('y');
        scanu(mod[monkey]);
        readuntil('y');
        scanu(true[monkey]);
        readuntil('y');
        scanu(false[monkey]);
        readuntil(':');
    }
    memset(inspected, 0, sizeof inspected);
    for(int gay = 0; gay < 20; ++gay)
    {
        for(unsigned i = 0; i < monkey; ++i)
        {
            for(unsigned j = 0; j < itemcnt[i]; ++j)
            {
                item[i][j] = ops[i](item[i][j], nums[i]) / 3;
                if(item[i][j] % mod[i] == 0)
                    item[true[i]][itemcnt[true[i]]++] = item[i][j];
                else
                    item[false[i]][itemcnt[false[i]]++] = item[i][j];
            }
            inspected[i] += itemcnt[i];
            itemcnt[i] = 0;
        }
    }
    prod = 1;
    for(int gay = 0; gay < 2; ++gay)
    {
        maxi = 0;
        for(int i = 0; i < monkey; ++i)
        {
            if(inspected[i] > maxi)
            {
                maxi = inspected[i];
                ind = i;
            }
        }
        prod *= maxi;
        inspected[ind] = 0;
    }
    printf("%u\n", prod);
    return 0;
}

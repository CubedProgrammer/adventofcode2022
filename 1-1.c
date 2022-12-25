#include<stdio.h>
int main(int argl, char *argv[])
{
    unsigned arr[2601], len = 0;
    unsigned maxi = 0, maxind;
    unsigned tot = 0, num = 0;
    for(char c = getchar(); !feof(stdin); c = getchar())
    {
        switch(c)
        {
            case'0':
            case'1':
            case'2':
            case'3':
            case'4':
            case'5':
            case'6':
            case'7':
            case'8':
            case'9':
                num *= 10;
                num += c - '0';
                break;
            case'\n':
                if(num == 0)
                {
                    arr[len++] = tot;
                    tot = 0;
                }
                else
                {
                    tot += num;
                    num = 0;
                }
        }
    }
    arr[len++] = tot;
    tot = 0;
    for(int i = 3; i; --i)
    {
        maxi = 0;
        for(unsigned j = 0; j < len; ++j)
        {
            if(maxi < arr[j])
            {
                maxi = arr[j];
                maxind = j;
            }
        }
        tot += maxi;
        arr[maxind] = 0;
    }
    printf("%u\n", tot);
    return 0;
}

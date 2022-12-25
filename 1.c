#include<stdio.h>
int main(int argl, char *argv[])
{
    unsigned maxi = 0, tot = 0, num = 0;
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
                    maxi = tot > maxi ? tot : maxi;
                    tot = 0;
                }
                else
                {
                    tot += num;
                    num = 0;
                }
        }
    }
    maxi = tot > maxi ? tot : maxi;
    printf("%u\n", maxi);
    return 0;
}

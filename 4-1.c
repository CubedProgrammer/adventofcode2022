#include<stdio.h>
void scan(unsigned *restrict s, unsigned *restrict t, unsigned *restrict u, unsigned *restrict v)
{
    scanf("%u-%u,%u-%u", s, t, u, v);
}
int main(int argl, char *argv[])
{
    unsigned fl, fr, sl, sr;
    unsigned cnt = 0;
    for(scan(&fl, &fr, &sl, &sr); !feof(stdin); scan(&fl, &fr, &sl, &sr))
        cnt += fr >= sl && fl <= sr;
    printf("%u\n", cnt);
    return 0;
}

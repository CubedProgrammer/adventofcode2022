#include<stdio.h>
#include<string.h>
int main(int argl, char *argv[])
{
    char cbuf[4096];
    unsigned ind, dup = 0;
    char freq[26];
    memset(freq, 0, sizeof freq);
    scanf("%s", cbuf);
    for(int i = 0; i < 4; ++i)
    {
        cbuf[i] -= 'a';
        ++freq[cbuf[i]];
        if(freq[cbuf[i]] == 2)
            ++dup;
    }
    for(ind = 4; dup > 0; ++ind)
    {
        cbuf[ind] -= 'a';
        --freq[cbuf[ind - 4]];
        if(freq[cbuf[ind - 4]] == 1)
            --dup;
        ++freq[cbuf[ind]];
        if(freq[cbuf[ind]] == 2)
            ++dup;
    }
    printf("%u\n", ind);
    return 0;
}

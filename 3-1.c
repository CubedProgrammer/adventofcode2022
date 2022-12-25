#include<stdio.h>
#include<string.h>
char getprio(char c)
{
    if(c >= 'a' && c <= 'z')
        return c - 'a' + 1;
    else if(c >= 'A' && c <= 'Z')
        return c - 'A' + 27;
    else
        return 0;
}
int main(int argl, char *argv[])
{
    char rucksack[81];
    char freq[3][52];
    char ch, ind = 0;
    unsigned prio = 0, len;
    for(scanf("%s", rucksack); !feof(stdin); scanf("%s", rucksack))
    {
        len = strlen(rucksack);
        if(ind == 0)
            memset(freq, 0, sizeof freq);
        for(unsigned i = 0; i < len; ++i)
        {
            ch = getprio(rucksack[i]) - 1;
            ++freq[ind][ch];
        }
        if(ind == 2)
        {
            for(int i = 0; i < 52; ++i)
                prio += (i + 1) * (freq[0][i] * freq[1][i] * freq[2][i] != 0);
            ind = 0;
        }
        else
            ++ind;
    }
    printf("%u\n", prio);
    return 0;
}

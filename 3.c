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
    char freqfirst[52], freqsecond[52];
    char ch;
    unsigned prio = 0, len;
    for(scanf("%s", rucksack); !feof(stdin); scanf("%s", rucksack))
    {
        len = strlen(rucksack) >> 1;
        memset(freqfirst, 0, sizeof freqfirst);
        memset(freqsecond, 0, sizeof freqsecond);
        for(unsigned i = 0; i < len; ++i)
        {
            ch = getprio(rucksack[i]) - 1;
            ++freqfirst[ch];
            ch = getprio(rucksack[i + len]) - 1;
            ++freqsecond[ch];
        }
        for(int i = 0; i < 52; ++i)
            prio += (i + 1) * (freqfirst[i] && freqsecond[i]);
    }
    printf("%u\n", prio);
    return 0;
}

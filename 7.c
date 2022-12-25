#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct entry
{
    char name[49];
    long size;
    struct entry **children;
    unsigned chldlen, chldcapa;
    struct entry *up;
};
int getln(char *cbuf)
{
    for(*cbuf = getchar(); *cbuf != -1 && *cbuf != '\n'; *++cbuf = getchar());
    int succ = *cbuf != -1;
    *cbuf = '\0';
    return succ;
}
struct entry *mkentry(const char *name, long size)
{
    struct entry *en = malloc(sizeof(*en));
    if(size < 0)
    {
        en->size = 0;
        en->chldcapa = 10;
        en->chldlen = 0;
        en->children = malloc(en->chldcapa * sizeof(*en->children));
    }
    else
    {
        en->size = size;
        en->children = NULL;
    }
    strcpy(en->name, name);
    return en;
}
void adden(struct entry *en, struct entry *ch)
{
    if(en->chldlen == en->chldcapa)
    {
        struct entry **tmp;
        en->chldcapa += en->chldcapa >> 1;
        tmp = malloc(en->chldcapa * sizeof(*tmp));
        memcpy(tmp, en->children, en->chldlen * sizeof(struct entry*));
        free(en->children);
        en->children = tmp;
    }
    ch->up = en;
    en->children[en->chldlen] = ch;
    ++en->chldlen;
}
struct entry *geten(const struct entry *en, const char *str)
{
    for(struct entry **it = en->children; it != en->chldlen + en->children; ++it)
    {
        if(strcmp(str, (*it)->name) == 0)
            return*it;
    }
    return NULL;
}
void freeen(struct entry *en)
{
    if(en->children != NULL)
    {
        for(struct entry **it = en->children; it != en->chldlen + en->children; ++it)
            freeen(*it);
        free(en->children);
    }
    free(en);
}
long sumsize(const struct entry *en, long *tot)
{
    if(en->children != NULL)
    {
        long size = 0;
        for(struct entry **it = en->children; it != en->chldlen + en->children; ++it)
            size += sumsize(*it, tot);
        if(size < 100001)
            *tot += size;
        return size;
    }
    return en->size;
}
int main(int argl, char *argv[])
{
    char cmd[121];
    char *name;
    char lastcd = 0;
    struct entry *rootdir, *currdir;
    long size;
    while(getln(cmd))
    {
        if(cmd[0] == '$')
        {
            lastcd = cmd[2] == 'c' && cmd[3] == 'd';
            if(lastcd)
            {
                if(cmd[5] == '/')
                    currdir = rootdir = mkentry("", -1);
                else if(cmd[5] == '.')
                    currdir = currdir->up;
                else
                    currdir = geten(currdir, cmd + 5);
            }
        }
        else
        {
            if(cmd[0] == 'd')
                adden(currdir, mkentry(cmd + 4, -1));
            else
            {
                size = 0;
                for(name = cmd; *name != ' '; ++name)
                    size = size * 10 + *name - '0';
                ++name;
                adden(currdir, mkentry(name, size));
            }
        }
    }
    size = 0;
    sumsize(rootdir, &size);
    freeen(rootdir);
    printf("%li\n", size);
    return 0;
}

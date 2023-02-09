#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const char lsb = 91;
const char rsb = 93;
struct list;
union listnum
{
    unsigned num;
    struct list *ptr;
};
struct listelem
{
    union listnum v;
    char l;
};
struct list
{
    struct listelem *elem;
    unsigned cnt, capa;
};
void lappend(struct list *restrict ls, const struct listelem *restrict item)
{
    if(ls->cnt == ls->capa)
    {
        struct listelem *tmp;
        ls->capa += ls->capa >> 1;
        tmp = malloc(ls->capa * sizeof(*tmp));
        memcpy(tmp, ls->elem, ls->cnt * sizeof(struct listelem));
        free(ls->elem);
        ls->elem = tmp;
    }
    ls->elem[ls->cnt] = *item;
    ++ls->cnt;
}
struct list *mkls(void)
{
    struct list *ls = malloc(sizeof(*ls));
    ls->cnt = 0;
    ls->capa = 4;
    ls->elem = malloc(ls->capa * sizeof(*ls->elem));
    return ls;
}
void freels(struct list *ls)
{
    for(unsigned i = 0; i < ls->cnt; ++i)
    {
        if(ls->elem[i].l)
            freels(ls->elem[i].v.ptr);
    }
    free(ls->elem);
    free(ls);
}
struct list *parsehelp(const char *ls, const char **end)
{
    char dig = 0;
    unsigned num = 0;
    struct listelem elem;
    struct list *ret = mkls();
    for(const char *it = ls + 1; *it; ++it)
    {
        switch(*it)
        {
            case lsb:
                elem.v.ptr = parsehelp(it, &it);
                elem.l = 1;
                lappend(ret, &elem);
                break;
            case rsb:
            case',':
                if(dig)
                {
                    elem.v.num = num;
                    elem.l = 0;
                    lappend(ret, &elem);
                    num = 0;
                    dig = 0;
                }
                if(*it == ',')
                    break;
                *end = it;
                return ret;
            default:
                num *= 10;
                num += *it - '0';
                dig = 1;
        }
    }
    freels(ret);
    return NULL;
}
struct list *parse(const char *ls)
{
    return parsehelp(ls, &ls);
}
int lscmp(const struct list *l, const struct list *r)
{
    int cmp;
    struct list *tmpls;
    for(unsigned i = 0; i < l->cnt && i < r->cnt; ++i)
    {
        if(l->elem[i].l)
        {
            if(r->elem[i].l)
                cmp = lscmp(l->elem[i].v.ptr, r->elem[i].v.ptr);
            else
            {
                if(l->elem[i].v.ptr->cnt == 0)
                    return-1;
                else
                {
                    tmpls = mkls();
                    lappend(tmpls, r->elem + i);
                    cmp = lscmp(l->elem[i].v.ptr, tmpls);
                    freels(tmpls);
                }
            }
        }
        else
        {
            if(r->elem[i].l)
            {
                if(r->elem[i].v.ptr->cnt == 0)
                    return 1;
                else
                {
                    tmpls = mkls();
                    lappend(tmpls, l->elem + i);
                    cmp = lscmp(tmpls, r->elem[i].v.ptr);
                    freels(tmpls);
                }
            }
            else
                cmp = l->elem[i].v.ptr > r->elem[i].v.ptr ? 1 : l->elem[i].v.ptr < r->elem[i].v.ptr ? -1 : 0;
        }
        if(cmp)
            return cmp;
    }
    return l->cnt > r->cnt ? 1 : l->cnt < r->cnt ? -1 : 0;
}
unsigned check(const char *l, const char *r)
{
    struct list *lls = parse(l), *rls = parse(r);
    int cmp = lscmp(lls, rls);
    freels(lls);
    freels(rls);
    return cmp < 0;
}
void getline(char *cbuf)
{
    for(int ch = getchar(); ch != '\n' && ch > 0; ch = getchar())
        *cbuf++ = ch;
    *cbuf = '\0';
}
int main(int argl, char *argv[])
{
    char l[1000], r[1000];
    unsigned inorder = 0, ind = 1;
    for(char ch = 1; !feof(stdin); ch = getchar())
    {
        getline(l);
        getline(r);
        inorder += check(l, r) * ind;
        ++ind;
    }
    printf("%u\n", inorder);
    return 0;
}

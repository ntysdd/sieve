#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct LinkNode
{
    int v1;
    int v2;
    struct LinkNode *next;
};

static void *xmalloc(size_t n)
{
    void *p = calloc(n, 1);
    if (p == NULL)
    {
        exit(2);
    }
    return p;
}

static void f(int s)
{
    bool *p = (bool *)xmalloc(s);

    memset(p, 1, s);
    p[0] = 0;
    p[1] = 0;
    p[s - 1] = 0;

    struct LinkNode *head = (struct LinkNode *)xmalloc(sizeof(struct LinkNode));
    struct LinkNode *tail = head;

    for (int i = 2; i * i < s; i++)
    {
        int counting = 0;
        for (int j = i * i; j < s; j += i)
        {
            const char *m = "N";
            if (p[j])
            {
                p[j] = 0;
                counting++;
                m = "Y";
            }
            if (p[s - j])
            {
                p[s - j] = 0;
                counting++;
                m = "Y";
            }
            printf("%s %d %d %d\n", m, i, j, s - j);
        }
        if (counting > 0)
        {
            struct LinkNode *newNode = (struct LinkNode *)xmalloc(sizeof(struct LinkNode));
            tail->next = newNode;
            tail = newNode;
            newNode->v1 = i;
            newNode->v2 = counting;
        }
    }

    puts("");

    for (int i = 1; i < s; i++)
    {
        if (p[i])
        {
            printf("R %d\n", i);
        }
    }

    puts("");

    struct LinkNode *pnode = head;
    while (1)
    {
        pnode = pnode->next;
        if (pnode == NULL)
        {
            break;
        }
        printf("C %d %d\n", pnode->v1, pnode->v2);
    }
}

int main(int argc, char **argv)
{
    static const char N_ERROR[] = "expect an even number greater than 6";
    if (argc < 2)
    {
        puts(N_ERROR);
        exit(1);
    }
    int s = -1;
    sscanf(argv[1], "%d", &s);
    if (s < 6 || s % 2 != 0)
    {
        puts(N_ERROR);
        exit(1);
    }
    char buf[30];
    if (snprintf(buf, sizeof buf, "%d", s) >= (int)(sizeof buf) || 0 != strcmp(buf, argv[1]))
    {
        puts(N_ERROR);
        exit(1);
    }

    f(s);
}

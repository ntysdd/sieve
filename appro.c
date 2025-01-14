#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
    p[1] = 0;

    for (int i = 2; i * i < s; i++)
    {
        for (int j = i * i; j < s; j += i)
        {
            p[j] = 0;
        }
    }

    int count = 0;
    for (int i = 3; i <= s - 3; i++)
    {
        if (p[i] && p[s - i])
        {
            count++;
        }
    }

    double v = 0.5 * s;
    for (int i = 3; i * i < s; i++)
    {
        if (p[i])
        {
            if (s % i == 0)
            {
                v *= 1 - 1.0 / i;
            }
            else
            {
                v *= 1 - 2.0 / i;
            }
        }
    }

    printf("%d\t%d\t%.2f\n", s, count, (count - v) / v);
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

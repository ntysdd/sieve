#include <stdio.h>

#define N 1000000

char p[N];

int main()
{
    for (int i = 2; i < N; i++)
    {
        p[i] = 1;
    }

    for (int i = 2; i * i < N; i++)
    {
        for (int j = i * i; j < N; j += i)
        {
            p[j] = 0;
        }
    }

    for (int s = 10; s <= N; s += 2)
    {
        int count = 0;
        for (int i = 3; i <= s - 3; i += 2)
        {
            if (p[i] && p[s - i])
            {
                count++;
            }
        }
        printf("%d %d\n", s, count);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int num, same, a, b;
    int i, j, k;
    int m, n;
    int len;
    char ans[4];
    char input[50];

    for (i = 0; i < 4; i++)
    {
        do
        {
            same = 0;
            num = rand() % 10;
            ans[i] = num + '0';

            for (j = 0; j < i; j++)
            {
                if (ans[i] == ans[j])
                {
                    same = 1;
                }
            }
        } while (same == 1);
    }

    do
    {
        m = 0;
        n = 0;

        do
        {
            a = 0;
            b = 0;
            //printf("%s", ans);
            printf("Please enter your number: ");
            gets(input);
            len = strlen(input);

            if (len > 4 || len < 4)
            {
                printf("Illegal answer\n");
                a = 1;
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < i; j++)
                    {
                        if (input[i] == input[j])
                        {
                            a = 1;
                            b = 1;
                            break;
                        }
                    }
                }
            }

            if (b == 1)
            {
                printf("Illegal answer\n");
            }
        } while (a == 1);

        for (i = 0; i < 4; i++)
        {
            if (input[i] == ans[i])
            {
                m++;
            }
        }

        printf("%dA", m);

        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (input[i] == ans[j] && i != j)
                {
                    n++;
                }
            }
        }

        printf("%dB\n", n);

        if (m == 4)
        {
            printf("You Win.\n");
            break;
        }
        
    } while (m != 4);

    return 0;
}
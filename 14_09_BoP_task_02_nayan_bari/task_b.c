#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *p;
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Entered number of elements: %d\n", n);

    p = (int *)malloc(n * sizeof(int));

    if (p == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory successfully allocated using malloc.\n");
        for (i = 0; i < n; ++i)
        {
            printf("\nEnter Number-%d: ", i + 1);
            scanf("%d", &p[i]);
        }

        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i)
        {
            printf("%d, ", p[i]);
        }

        printf("\nEnter new size of array: ");
        scanf("%d", &n);
        printf("New number of elements: %d\n", n);
        p = realloc(p, n * sizeof(int));
        for (i = 0; i < n; i++)
        {
            printf("Enter number-%d: ", i + 1);
            scanf("%d", p[i]);
        }
        printf("\nNew elements in array p are: ");
        for (i = 0; i < n; i++)
        {
            printf("%d,", p[i]);
        }
        free(p);
    }
    return 0;
}

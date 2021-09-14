#include <stdio.h>
#include <string.h>

struct backCustomers
{
    int accontNumber;
    char name[20];
    float balance;
};

int main(int argc, char const *argv[])
{
    int n;
    char dummy;
    printf("\nEnter the total number of customers: ");
    scanf("%d %*c", &n);
    printf("----------------------------------");
    struct backCustomers list[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the details of customer-%d", i + 1);
        printf("\nEnter Name: ");
        scanf("%s", &list[i].name);
        printf("\nEnter Account Number: ");
        scanf("%d", &list[i].accontNumber);
        printf("\nEnter Balance: ");
        scanf("%f", &list[i].balance);
    }

    for (int j = 0; j < n; j++)
    {
        printf("Struct-%d\n", j + 1);
        printf("Account Number-%d = %d\n", j + 1, list[j].accontNumber);
        printf("Balance-%d = %f\n", j + 1, list[j].balance);
        printf("------------------------------\n");
    }

    printf("\nCustomer with balance below 100RS");
    for (int j = 0; j < n; j++)
    {
        if (list[j].balance < 100)
        {
            printf("\nCustomer-%d", j + 1);
            printf("\nName: %s", list[j].name);
            printf("\nAccount Number: %d", list[j].accontNumber);
            printf("\nAvailable Balance: %f", list[j].balance);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        printf("\nCustomer-%d do you want to make any transactions(Yes=1/No=0): ", i + 1);
        scanf("%d", &temp);
        if (temp == 1)
        {
            int operation;
            float amount;
            printf("\nChoose your opereation");
            printf("\n0. Withdrawal");
            printf("\n1. Deposit");
            printf("\nEnter option number: ");
            scanf("%d", &operation);
            switch (operation)
            {
            case 0:
                printf("\nHow much amount you want to withdrawal: ");
                scanf("%f", &amount);
                if (amount < list[i].balance)
                {
                    list[i].balance -= amount;
                    printf("\nAvailable Balance: %f", list[i].balance);
                    printf("\nCollect money from counter");
                }
                else
                {
                    printf("\nAvailable Balance: %f", list[i].balance);
                    printf("\nYour balance is insufficient");
                }
                break;
            case 1:
                printf("\nHow much amount you want to deposit: ");
                scanf("%f", &amount);
                list[i].balance += amount;
                printf("\nYour money is succesfuly deposite");
                printf("\nAvailable Balance: %f", list[i].balance);
                break;
            }
        }
    }
    return 0;
}

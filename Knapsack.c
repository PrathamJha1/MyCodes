#include <stdio.h>
void fractionalKnapsack(int n, float w[], float p[], float c)
{
    float x[n], profit = 0;
    int curr = 0, remain;
    int i, j;
    for (i = 0; i < n; i++)
        x[i] = 0.0;
    for (i = 0; i < n; i++)
    {
        if (curr + w[i] <= c)
        {
            x[i] = 1.0;
            profit += p[i];
            curr += w[i];
        }
        else
        {
            remain = c - curr;
            x[i] = remain / w[i];
            profit += (p[i] * x[i]);
            break;
        }
    }
    printf("\nThe fraction of each item included : ");
    for (i = 0; i < n; i++)
        printf("%f ", x[i]);
    printf("\n");
    printf("\nThe total profit is %f\n", profit);
}
int main()
{
    float w[10], p[10], c;
    int n;
    int i, j;
    int choice;
    int ok;
    float r[10], temp;
    printf("\nEnter the size you want : ");
    scanf("%d", &n);
    printf("\nEnter the weight of each item : \n");
    for (i = 0; i < n; i++)
        scanf("%f", &w[i]);
    printf("\nEnter the profit from each item : \n");
    for (i = 0; i < n; i++)
        scanf("%f", &p[i]);
    printf("\nEnter the capacity of the bag : ");
    scanf("%f", &c);
    do
    {
        printf("\nEnter the choice :\n1. Maximum Profit (Profit Based)\n2. Minimum Weight (Weight Based)\n3. Fractional(Ratio Based)\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (i = 0; i < n - 1; i++)
            {
                for (j = 0; j < n - i - 1; j++)
                {
                    if (p[j] < p[j + 1])
                    {
                        temp = p[j];
                        p[j] = p[j + 1];
                        p[j + 1] = temp;

                        temp = w[j];
                        w[j] = w[j + 1];
                        w[j + 1] = temp;
                    }
                }
            }
            fractionalKnapsack(n, w, p, c);
            break;
        case 2:
            for (i = 0; i < n - 1; i++)
            {
                for (j = 0; j < n - i - 1; j++)
                {
                    if (w[j] > w[j + 1])
                    {
                        temp = p[j];
                        p[j] = p[j + 1];
                        p[j + 1] = temp;

                        temp = w[j];
                        w[j] = w[j + 1];
                        w[j + 1] = temp;
                    }
                }
            }
            fractionalKnapsack(n, w, p, c);
            break;
        case 3:
            for (i = 0; i < n; i++)
                r[i] = p[i] / w[i];
            for (i = 0; i < n; i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    if (r[i] < r[j])
                    {
                        temp = r[j];
                        r[j] = r[i];
                        r[i] = temp;

                        temp = w[j];
                        w[j] = w[i];
                        w[i] = temp;

                        temp = p[j];
                        p[j] = p[i];
                        p[i] = temp;
                    }
                }
            }
            fractionalKnapsack(n, w, p, c);
            break;
        default:
            printf("\nYou have entered a wrong choice.\n");
            break;
        }
        printf("\nIf you want to continue press 1 : ");
        scanf("%d", &ok);
    } while (ok == 1);
    return 0;
}
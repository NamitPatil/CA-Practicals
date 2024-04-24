#include<stdio.h>

int wtarr[3]; // Changed from dline to wtarr
int profit[3];
float ratio[3];
char jname[4];

// Function to swap two integers
void swap1(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubble Sort
void bubbleSort(int profits[], int wtarr[], float ratio[], int n) { // Updated function parameter
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                swap1(&ratio[j], &ratio[j + 1]);
                swap(&profits[j], &profits[j + 1]);
                swap(&wtarr[j], &wtarr[j + 1]); // Updated array name
            }
        }
    }
}

// Function to solve the Fractional Knapsack Problem
void fractionalKnapsack(int capacity) {
    int i;
    float totalProfit = 0;

    printf("\nItems selected:\n");
    for (i = 0; i < 3; i++) {
        if (wtarr[i] <= capacity) {
            capacity -= wtarr[i];
            totalProfit += profit[i];
            printf("Item %d: Weight = %d, Profit = %d\n", i + 1, wtarr[i], profit[i]);
        } else {
            float fraction = (float)capacity / wtarr[i];
            totalProfit += profit[i] * fraction;
            printf("Item %d: Weight = %d, Profit = %.2f\n", i + 1, wtarr[i], profit[i] * fraction);
            break;
        }
    }

    printf("\nTotal profit is: %.2f\n", totalProfit);
}

int main() {
    int i;
    int capacity;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    for (i = 0; i < 3; i++) {
        printf("Enter profit of %d: ", i + 1);
        scanf("%d", &profit[i]);
        printf("Enter the weight of %d: ", i + 1);
        scanf("%d", &wtarr[i]); // Updated array name
    }

    int n = sizeof(profit) / sizeof(profit[0]);
    for (i = 0; i < n; i++) {
        ratio[i] = (float)profit[i] / wtarr[i]; // Updated array name
    }

    bubbleSort(profit, wtarr, ratio, n); // Updated function call

    printf("\nSorted Profits and Weights ratio:\n");
    printf("Ratio\tProfit\tWeight\n");
    for (i = 0; i < n; i++) {
        printf("%f\t%d\t%d\n", ratio[i], profit[i], wtarr[i]); // Updated array name
    }

    fractionalKnapsack(capacity);

    return 0;
}

#include<stdio.h>
int dline[5];
int profit[5];
char jname[5];

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubble Sort
void bubbleSort(int profits[], int deadlines[], int n) {
	int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (profits[j] < profits[j + 1]) {
                swap(&profits[j], &profits[j + 1]);
                swap(&deadlines[j], &deadlines[j + 1]);
            }
        }
    }
}

int main() {
	int j=1,i=0;
    int dmax,count=0,r=0;
    int pr=0;
    int slot[5]={-1};
    for(i=0;i<5;i++)
    {
        printf("enter profit of %d : ",i+1);
        scanf("%d",&profit[i]);
        printf("enter the deadline of %d : ",i+1);
        scanf("%d",&dline[i]);

    }
    //int profits[] = {60, 100, 120}; // Example profit array
    //int deadlines[] = {2, 1, 3};     // Example deadline array
    int n = sizeof(profit) / sizeof(profit[0]);

    // Sorting both arrays based on profit
    bubbleSort(profit, dline, n);

    // Printing the sorted arrays
    printf("\nSorted Profits and Deadlines based on Profit:\n");
    printf("Profit\tDeadline\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", profit[i], dline[i]);
    }
     
    for(i=0;i<n;i++)
    {
        if(dline[i]>dmax)
        {
            dmax=dline[i];
        }
    }
    for(i=1;i<=dmax;i++)
    {
        slot[i]=-1;
    }
    for(i=0;i<5;i++)
    {
        for(r=dline[i];r>=1;r--){
            if(slot[r]==-1)
            {
                slot[r]=i;
                pr+=profit[i];
                count++;
                break;
            }
        }
        if(count ==dmax)
        {
            break;
        }
    }
    printf("\n\nTotal profit is : %d",pr);
    printf("\nMaximum deadline is : %d",dmax);
    return 0;
}



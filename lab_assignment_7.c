#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int n_arr[], int s_arr[], int n)
{
    int i, j;

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(n_arr[j] > n_arr[j+1])
            {
                swap(&n_arr[j], &n_arr[j+1]);
                s_arr[j]++;
                s_arr[j+1]++;
            }
        }
    }
}

int main()
{
    int num_vals, i, val;

    printf("# of values:");
    scanf("%d", &num_vals);

    int *num_array = (int*) malloc(num_vals * sizeof(int));
    int *swap_array = (int*) malloc(num_vals * sizeof(int));

    for(i=0; i<num_vals; i++)
    {
        swap_array[i] = 0;
        scanf(" %d", &val);
        num_array[i] = val;
    }

    bubbleSort(num_array, swap_array, num_vals);

    for(i=0; i<num_vals; i++)
        printf("%d ", num_array[i]);

    printf("\n");

    for(i=0; i<num_vals; i++)
        printf("Index %d was sorted after %d swaps.\n", i, swap_array[i]);

    return 0;
}

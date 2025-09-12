#include <stdio.h>
#include <stdlib.h>

long long mc(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    long long count = 0;
    int *temp = (int *)malloc((right - left + 1) * sizeof(int));
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            count += (mid - i + 1);
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (i = 0; i < k; i++)
    {
        arr[left + i] = temp[i];
    }
    free(temp);
    return count;
}
long long ms(int arr[], int left, int right)
{
    long long count = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        count += ms(arr, left, mid);
        count += ms(arr, mid + 1, right);
        count += mc(arr, left, mid, right);
    }
    return count;
}
int main(void)
{
    int n;
    int m = 0;
    scanf("%i", &n);
    if (n < 1 || n > 1000)
    {
        printf("Error\n");
        return 1;
    }
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
        if (arr[i] < 1 || arr[i] > 100000)
        {
            printf("Error\n");
            free(arr);
            return 1;
        }
    }
    long long result = ms(arr, 0, n - 1);
    printf("%lld\n", result);

    free(arr);
    return 0;
}
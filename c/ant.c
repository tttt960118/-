#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int case_n;
    int ant_n[100], length_line[100];
    if (scanf("%d", &case_n) != 1 || case_n < 1 || case_n > 100)
    {
        printf("Invalid number of test cases!\n");
        return 1;
    }
    int min_time[100], max_time[100];
    for (int case_i = 0; case_i < case_n; case_i++)
    {
        if (scanf("%d %d", &length_line[case_i], &ant_n[case_i]) != 2 || ant_n[case_i] < 1 || ant_n[case_i] > 10000 || length_line[case_i] < 1 || length_line[case_i] > 10000)
        {
            printf("Invalid input for number of ants or length of line!\n");
            return 1;
        }

        int *ant_pos = (int *)malloc(ant_n[case_i] * sizeof(int));
        if (!ant_pos)
        {
            printf("Memory allocation failed!\n");
            free(ant_pos);
            return 1;
        }
        for (int j = 0; j < ant_n[case_i]; j++)
        {
            if (scanf("%d", &ant_pos[j]) != 1 || ant_pos[j] < 0 || ant_pos[j] > length_line[case_i])
            {
                printf("Invalid ant position!\n");
                free(ant_pos);
                return 1;
            }
        }

        min_time[case_i] = 0;
        max_time[case_i] = 0;
        for (int i = 0; i < ant_n[case_i]; i++)
        {
            int dist_to_left = ant_pos[i];
            int dist_to_right = length_line[case_i] - ant_pos[i];
            int min_dist = dist_to_left < dist_to_right ? dist_to_left : dist_to_right;
            int max_dist = dist_to_left > dist_to_right ? dist_to_left : dist_to_right;

            if (min_dist > min_time[case_i])
            {
                min_time[case_i] = min_dist;
            }
            if (max_dist > max_time[case_i])
            {
                max_time[case_i] = max_dist;
            }
        }
        free(ant_pos);
    }
    for (int case_i = 0; case_i < case_n; case_i++)
    {
        printf("%d %d\n", min_time[case_i], max_time[case_i]);
    }
    return 0;
}

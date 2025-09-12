#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int box_n;
    scanf("%d", &box_n);

    int weight_m;
    scanf("%d", &weight_m);

    int *box, *weight;
    float *per;


    box = (int *)malloc(box_n * sizeof(int));
    weight = (int *)malloc(box_n * sizeof(int));
    per = (float *)malloc(box_n * sizeof(float));
    if (!box || !weight || !per)
    {
        printf("Memory allocation failed!\n");
        free(box);
        free(weight);
        free(per);
        return 1;
    }
    for (int i = 0; i < box_n; i++)
    {
        scanf("%d %d", &box[i], &weight[i]);
        per[i] = (float)box[i] / weight[i];
    }
    float value_m = 0.0;
    int remaining_weight = weight_m;
    while (remaining_weight > 0)
    {
        float per_max = 0.0;
        int max_index = -1;
        for (int j = 0; j < box_n; j++)
        {
            if (per[j] > per_max)
            {
                per_max = per[j];
                max_index = j;
            }
        }
        if (per_max == 0.0 || max_index == -1)
        {
            break;
        }
        if (remaining_weight >= weight[max_index])
        {
            remaining_weight -= weight[max_index];
            value_m += box[max_index];
            per[max_index] = 0.0; // Mark this item as used // Exit the inner loop to recalculate per_max
        }
        else
        {
            value_m += per[max_index] * remaining_weight;
            remaining_weight = 0; // Return the value if we can't take the whole item
        }
    }

    printf("Total value: %.2f\n", value_m);

    free(box);
    free(weight);
    free(per);

    return 0;
}

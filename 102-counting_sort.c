#include "sort.h"

int get_range(int *array, size_t size)
{
    int i, range = 0;
    
    for (i = 0; i < (int)size; i++)
    {
        if (array[i] > range)
            range = array[i];
    }
    return (range);
}

void counting_sort(int *array, size_t size) 
{
    int *count, *count_array_for_checker, range, i, tick = 0, j, k;

    if (size < 2 || !array)
        return;
    range = get_range(array, size);
    count = malloc((range + 1) * sizeof(int));
    count_array_for_checker = malloc((range + 1) * sizeof(int));
    memset(count, 0, (range + 1) * sizeof(int));
    memset(count_array_for_checker, 0, (range + 1) * sizeof(int));

    for (i = 0; i < (int)size; ++i)
        ++count[array[i]];
    for (i = 0; i < range + 1; i++)
    {
        if (!count[i])
            count_array_for_checker[i] = tick;
        else
        {
            j = count[i];
            k = i;
            while (j > 0)
            {
                tick++;
                count_array_for_checker[k] = tick;
                j--;
                k++;
            }
            i = k - 1;
        }
    }
    tick = 0;
    j = 0;
    for (i = 0; i < range; i++)
        printf("%d, ", count_array_for_checker[i]);
    printf("%d", count_array_for_checker[i]);
    printf("\n");
    for (i = 0; i <= range; ++i)
    {
        if (count_array_for_checker[i] > tick)
        {
            array[j] = i;
            j++;
            tick++;
        }
        tick = count_array_for_checker[i];
    }

    free(count);
    free(count_array_for_checker);
}
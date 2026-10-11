#include <stdio.h>
#include <string.h>

#define MAX 10005
#define CHARSET 256

typedef struct
{
    unsigned char character;
    int frequency;
} Item;

int main()
{
    char str[MAX];
    char result[MAX];
    int k;
    int frequency[CHARSET] = {0};

    printf("Enter string and K: ");

    if (scanf("%10000s %d", str, &k) != 2)
    {
        return 1;
    }

    int n = (int)strlen(str);

    // If K is 0 or 1, the original string is valid.
    if (k <= 1)
    {
        printf("Reorganised string: %s\n", str);
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        frequency[(unsigned char)str[i]]++;
    }

    Item heap[CHARSET + 1];
    int heapSize = 0;

    // Insert each distinct character into a max-heap.
    for (int c = 0; c < CHARSET; c++)
    {
        if (frequency[c] > 0)
        {
            Item item = {(unsigned char)c, frequency[c]};
            int i = ++heapSize;

            while (i > 1 &&
                   heap[i / 2].frequency < item.frequency)
            {
                heap[i] = heap[i / 2];
                i /= 2;
            }

            heap[i] = item;
        }
    }

    // Cooldown queue: characters cannot return before
    // their release position.
    Item cooldown[MAX];
    int release[MAX];
    int head = 0, tail = 0;

    for (int position = 0; position < n; position++)
    {
        // Return characters whose cooldown has expired.
        while (head < tail && release[head] <= position)
        {
            Item item = cooldown[head++];
            int i = ++heapSize;

            while (i > 1 &&
                   heap[i / 2].frequency < item.frequency)
            {
                heap[i] = heap[i / 2];
                i /= 2;
            }

            heap[i] = item;
        }

        // No character is available for this position.
        if (heapSize == 0)
        {
            printf("Empty string: rearrangement impossible\n");
            return 0;
        }

        // Remove the most frequent available character.
        Item current = heap[1];
        Item last = heap[heapSize--];
        int i = 1;

        while (2 * i <= heapSize)
        {
            int child = 2 * i;

            if (child + 1 <= heapSize &&
                heap[child + 1].frequency >
                heap[child].frequency)
            {
                child++;
            }

            if (last.frequency >= heap[child].frequency)
            {
                break;
            }

            heap[i] = heap[child];
            i = child;
        }

        if (heapSize > 0)
        {
            heap[i] = last;
        }

        result[position] = (char)current.character;
        current.frequency--;

        // Reinsert only after K positions have passed.
        if (current.frequency > 0)
        {
            cooldown[tail] = current;
            release[tail] = position + k;
            tail++;
        }
    }

    result[n] = '\0';

    printf("Reorganised string: %s\n", result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 256

typedef struct Node
{
    long long frequency;
    int character;
    struct Node *left;
    struct Node *right;
} Node;

Node *heap[MAX * 2];
int heapSize = 0;
int codeLength[MAX] = {0};

// Create a new Huffman tree node.
Node *createNode(long long frequency, int character,
                 Node *left, Node *right)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        exit(1);
    }

    node->frequency = frequency;
    node->character = character;
    node->left = left;
    node->right = right;

    return node;
}

// Insert a node into the minimum heap.
void insert(Node *node)
{
    int i = ++heapSize;

    while (i > 1 &&
           heap[i / 2]->frequency > node->frequency)
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }

    heap[i] = node;
}

// Remove and return the node with minimum frequency.
Node *removeMin()
{
    Node *minimum = heap[1];
    Node *last = heap[heapSize--];

    int i = 1;

    while (2 * i <= heapSize)
    {
        int child = 2 * i;

        if (child + 1 <= heapSize &&
            heap[child + 1]->frequency <
            heap[child]->frequency)
        {
            child++;
        }

        if (last->frequency <= heap[child]->frequency)
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

    return minimum;
}

// Record the depth of each leaf as its code length.
void findLengths(Node *root, int depth)
{
    if (root == NULL)
    {
        return;
    }

    if (root->character >= 0)
    {
        codeLength[root->character] =
            (depth == 0) ? 1 : depth;
        return;
    }

    findLengths(root->left, depth + 1);
    findLengths(root->right, depth + 1);
}

// Sort symbols by code length, then by character code.
int compareSymbols(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (codeLength[x] != codeLength[y])
    {
        return codeLength[x] - codeLength[y];
    }

    return x - y;
}

int main()
{
    int n;
    int symbols[MAX];
    int count = 0;

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of symbols\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        int character;
        long long frequency;

        printf("Enter ASCII code and frequency: ");
        scanf("%d %lld", &character, &frequency);

        if (character < 0 || character > 255 ||
            frequency <= 0)
        {
            printf("Invalid input\n");
            return 1;
        }

        insert(createNode(frequency, character,
                          NULL, NULL));
    }

    // Build the Huffman tree by combining the two
    // minimum-frequency nodes at every iteration.
    while (heapSize > 1)
    {
        Node *left = removeMin();
        Node *right = removeMin();

        Node *parent = createNode(
            left->frequency + right->frequency,
            -1, left, right
        );

        insert(parent);
    }

    Node *root = removeMin();
    findLengths(root, 0);

    // Collect all symbols that have a code length.
    for (int c = 0; c < MAX; c++)
    {
        if (codeLength[c] > 0)
        {
            symbols[count++] = c;
        }
    }

    qsort(symbols, count, sizeof(int), compareSymbols);

    // Generate canonical codes in sorted order.
    unsigned long long code = 0;
    int previousLength = 0;

    printf("\nCanonical Huffman Codebook:\n");

    for (int i = 0; i < count; i++)
    {
        int c = symbols[i];
        int length = codeLength[c];

        if (i > 0)
        {
            code = (code + 1) << (length - previousLength);
        }

        printf("Character ASCII %d, length %d, code ",
               c, length);

        for (int bit = length - 1; bit >= 0; bit--)
        {
            putchar((code & (1ULL << bit)) ? '1' : '0');
        }

        putchar('\n');
        previousLength = length;
    }

    return 0;
}
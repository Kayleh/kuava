// #include "uthash.h"

#define INF 0x3f3f3f3f  // 无穷大
#define NINF 0xc0c0c0c0 // 无穷小

typedef struct
{
    int key;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key)
{
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key)
{
    if (hashFindItem(obj, key))
    {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem **obj)
{
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp)
    {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

/**
 *  比较大小，从大到小排序
 */
int cmp(const void *p1, const void *p2)
{
    return *(const int *)p1 - *(const int *)p2;
}

long long min(long long a, long long b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

bool checkXMatrix(int **grid, int gridSize, int *gridColSize)
{
    int n = gridSize;
    int m = *gridColSize;
    for (int i = 0; i < n; i++)
    {
        int *row = *(grid + i);
        for (int j = 0; j < m; j++)
        {
            if (row[j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

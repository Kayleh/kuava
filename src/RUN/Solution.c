// #include "uthash.h"

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

/**
如果出现下述两种情况，交易 可能无效：

1 交易金额超过 $1000
2 或者，它和 另一个城市 中 同名 的另一笔交易相隔不超过 60 分钟（包含 60 分钟整）

给定字符串数组交易清单 transaction 。
transactions[i] = 交易的名称，时间（分钟），金额以及城市。

返回 transactions，返回可能无效的交易列表。你可以按 任何顺序 返回答案。
**/
char **invalidTransactions(char **transactions, int n, int *returnSize)
{
    HashItem *hash = NULL;
    for (int i = 0; i < n; i++)
    {
        char *str = transactions[i];
        char **spilt = strtok(str, ',');

        char *name = spilt[0];
        int time = atoi(spilt[1]);
        int money = atoi(spilt[2]);
        char *city = spilt[3];
    }
    return NULL;
}

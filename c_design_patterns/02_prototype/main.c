#include "stdlib.h"
#include "stdio.h"
#include <assert.h>
#include <string.h>

typedef struct _PROTOTYPE_DATA {
    struct _PROTOTYPE_DATA *(*copy)(struct _PROTOTYPE_DATA *pData);

    int num;
} DATA;

struct _PROTOTYPE_DATA *data_copy_a(struct _PROTOTYPE_DATA *pData) {
    DATA *result = (DATA *) malloc(sizeof(DATA));
    assert(result != NULL);
    memmove(result, pData, sizeof(DATA));
    return result;
}

struct _PROTOTYPE_DATA *clone(struct _PROTOTYPE_DATA *pData) {
    if (pData == NULL)
        return NULL;
    return pData->copy(pData);
}

int main() {
    DATA data_A = {data_copy_a, 1};
    DATA *data_B = clone(&data_A);
    // DATA *data_B = data_A.copy(&data_A);
    printf("data B's num = %d.\n", data_B->num);
    return 0;
}
//
// Created by wangly on 2024/5/4.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct _SINGLETON_DATA {
    void *pData;
    int num;
} DATA;

void *get_data() {
    static DATA *pData = NULL;
    if (pData != NULL) {
        return pData;
    } else {
        pData = malloc(sizeof(DATA));
        pData->pData = malloc(1024);
        pData->num = 10;
        return pData;
    }
}

int main(int argc, char **argv) {
    printf("Hello, World!\n");
    void *pData = get_data();
    printf("pData: %p\n", pData);
    void *pData1 = get_data();
    printf("pData: %p\n", pData1);
    return 0;
}
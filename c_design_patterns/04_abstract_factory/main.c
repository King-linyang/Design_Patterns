#include <stdio.h>
#include <stdlib.h>

// 定义两个产品类型
typedef struct {
    void (*use)(void);
} ProductA_Abstract;

typedef struct {
    void (*use)(void);
} ProductB_Abstract;

// 定义两个产品的创建接口
typedef struct {
    ProductA_Abstract *(*createProductA)(void);

    ProductB_Abstract *(*createProductB)(void);
} Factory_Abstract;

// 实现两个具体产品的功能
void product_a_use(void) {
    printf("Product A is used.\n");
}

void product_b_use(void) {
    printf("Product B is used.\n");
}

// 实现具体工厂的创建功能
ProductA_Abstract *create_product_a(void) {
    ProductA_Abstract *a = malloc(sizeof(ProductA_Abstract));
    a->use = product_a_use;
    return a;
}

ProductB_Abstract *create_product_b(void) {
    ProductB_Abstract *b = malloc(sizeof(ProductB_Abstract));
    b->use = product_b_use;
    return b;
}

// 实现具体工厂的结构
Factory_Abstract factory = {
        .createProductA = create_product_a,
        .createProductB = create_product_b
};

// 使用工厂来创建并使用产品
int main() {
    ProductA_Abstract *a = factory.createProductA();
    a->use();

    ProductB_Abstract *b = factory.createProductB();
    b->use();

    free(a);
    free(b);

    return 0;
}
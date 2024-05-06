#include <stdio.h>
#include <stdlib.h>

// 定义产品结构体
typedef struct {
    void (*show)(void);
} Single_Factory_Product;

void showConcreteProductA(void) {
    printf("产品A显示\n");
}

// 创建具体产品的函数
Single_Factory_Product *createConcreteProductA() {
    Single_Factory_Product *p = (Single_Factory_Product *) malloc(sizeof(Single_Factory_Product));
    p->show = showConcreteProductA;
    return p;
}

// 定义工厂方法
typedef Single_Factory_Product *(*CreateProductFunc)(void);

// 创建工厂
Single_Factory_Product *createProduct(CreateProductFunc func) {
    return func();
}

int main() {
    // 设置工厂方法
    CreateProductFunc funcA = createConcreteProductA;

    // 通过工厂创建产品
    Single_Factory_Product *product = createProduct(funcA);

    // 使用产品
    if (product != NULL) {
        product->show();
        free(product);
    }

    return 0;
}
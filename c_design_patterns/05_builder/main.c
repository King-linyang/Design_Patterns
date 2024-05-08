#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义一个Person结构体
typedef struct {
    char *name;
    int age;
} Person_Builder;

// 定义一个建造者结构体，包含设置各个部分的函数指针
typedef struct {
    void (*set_name)(Person_Builder *, char *);

    void (*set_age)(Person_Builder *, int);

    Person_Builder *(*build)(struct Person_Builder *);
} PersonBuilder;

// 实现具体的设置函数
void set_name(Person_Builder *p, char *name) {
    p->name = strdup(name);
}

void set_age(Person_Builder *p, int age) {
    p->age = age;
}

// 实现构建函数
Person_Builder *build(PersonBuilder *builder) {
    Person_Builder *person = malloc(sizeof(Person_Builder));
    person->name = NULL;
    person->age = 0;
    if (builder->set_name) builder->set_name(person, "Alice");
    if (builder->set_age) builder->set_age(person, 30);
    return person;
}

// 主函数
int main() {
    PersonBuilder builder = {
            .set_name = set_name,
            .set_age = set_age,
            .build = build
    };

    Person_Builder *person = builder.build(&builder);
    printf("Name: %s, Age: %d\n", person->name, person->age);

    // 清理资源
    free(person->name);
    free(person);

    return 0;
}
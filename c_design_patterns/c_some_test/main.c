//
// Created by wangly on 2024/5/5.
//
#include <stdio.h>
#include "./header/file_util.h"
#include "./header/001_lexical_analysis.h"

int main(int argc, char **argv) {
    //遍历文件夹输出文件
//    const char *directory = "E:\\A_learning_data\\Design_Patterns\\c_design_patterns\\c_some_test\\src";
//    traverseDirectory(directory);

//    char input[] = "int a = 10, b = 20; if (a > b) { a = b; } else { b = a; }";
//    lexicalAnalysis(input);

    // 定义保留字
    char *reservedWords[] = {"main", "if", "else", "int", "while", "do", "return"};
    char *data = "a b c d e f gh <=";
    char ch;
    char *world;
    while (*data != '\0') {
        ch = *data++;
//        world = (char *) malloc(strlen(&ch));
        //复制字符串
//        strcpy(world, &ch);
        // 检查是否为空格或制表符
        if (ch == ' ' || ch == '\t') {
            continue;
        }
        printf("%c\n", ch);
//        printf("%s\n", world);
//        free(world);
//        world = NULL;
    }
    // 测试 strlen
//    char str[] = "Hello, World!";
//    int length = strlen(str);
//    printf("字符串长度为: %d\n", length);
    return 0;
}

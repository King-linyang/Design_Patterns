//
// Created by wangly on 2024/5/5.
//
#include "../header/001_lexical_analysis.h"


// 定义保留字
const char *reservedWords[] = {"main", "if", "else", "int", "while", "do", "return"};

// 检查字符是否为字母
int isLetter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// 检查字符是否为数字
int isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

// 词法分析函数
void lexicalAnalysis(char *input) {
    char ch;
    int tokenType = 0;

    while (*input != '\0') {
        ch = *input++;

        // 检查是否为空格或制表符
        if (ch == ' ' || ch == '\t') {
            continue;
        }

            // 检查是否为字母或下划线
        else if (isLetter(ch) || ch == '_') {
            // 构建标识符
            char identifier[32];
            int i = 0;

            while (isLetter(ch) || isDigit(ch) || ch == '_') {
                identifier[i++] = ch;
                ch = *input++;
            }

            identifier[i] = '\0';

            // 检查是否为保留字
            for (int j = 0; j < sizeof(reservedWords) / sizeof(reservedWords[0]); j++) {
                if (strcmp(identifier, reservedWords[j]) == 0) {
                    tokenType = j + 1;
                    break;
                }
            }

            // 如果不是保留字，则视为标识符
            if (tokenType == 0) {
                tokenType = 10;
            }
        }

            // 检查是否为数字
        else if (isDigit(ch)) {
            // 构建数字
            char num[32];
            int i = 0;

            while (isDigit(ch)) {
                num[i++] = ch;
                ch = *input++;
            }

            num[i] = '\0';

            tokenType = 20;
        }

            // 检查是否为其他符号
        else {
            switch (ch) {
                case '=':
                    tokenType = 30;
                    break;
                case '+':
                    tokenType = 40;
                    break;
                case '-':
                    tokenType = 50;
                    break;
                case '*':
                    tokenType = 60;
                    break;
                case '/':
                    tokenType = 70;
                    break;
                case '<':
                    tokenType = 80;
                    break;
//                case '<=':
//                    tokenType = 90;
//                    break;
                case '>':
                    tokenType = 100;
                    break;
//                case '>=':
//                    tokenType = 110;
//                    break;
                case ';':
                    tokenType = 120;
                    break;
                case ',':
                    tokenType = 130;
                    break;
                case '(':
                    tokenType = 140;
                    break;
                case ')':
                    tokenType = 150;
                    break;
                case '{':
                    tokenType = 160;
                    break;
                case '}':
                    tokenType = 170;
                    break;
                case '%':
                    tokenType = 200;
                    break;
                case '?':
                    tokenType = 210;
                    break;
                case ':':
                    tokenType = 220;
                    break;
                default:
                    printf("非法字符 '%c'\n", ch);
                    break;
            }
        }
        // 输出词法单元
        printf("(%d, '%s')\n", tokenType, input - 1);
    }
}

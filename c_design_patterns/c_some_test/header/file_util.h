//
// Created by wangly on 2024/5/5.
//

#ifndef C_PRO_DATA_TEST_STRING_FILE_UTIL_H
#define C_PRO_DATA_TEST_STRING_FILE_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void traverseDirectory(const char *directory);

void readFile(const char *filename);

#endif //C_PRO_DATA_TEST_STRING_FILE_UTIL_H

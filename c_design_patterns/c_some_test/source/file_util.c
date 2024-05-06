//
// Created by wangly on 2024/5/5.
//
#include "../header/file_util.h"

void traverseDirectory(const char *directory) {
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(directory)) == NULL) {
        perror("无法打开目录");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG && strstr(entry->d_name, ".mc") != NULL) {
            // 文件类型为普通文件
            printf("文件: %s\n", entry->d_name);
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // 子文件夹
            char subDirectory[1024];
            snprintf(subDirectory, sizeof(subDirectory), "%s/%s", directory, entry->d_name);
            traverseDirectory(subDirectory);
        }
    }
    closedir(dir);
}

void readFile(const char *filename) {
    FILE *fp;
    char ch;
    fp = fopen(filename, "r"); // 替换为你的文件路径
    if (fp == NULL) {
        printf("无法打开文件\n");
    }
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
}

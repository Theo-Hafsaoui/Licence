#ifndef FILE_H
#define FILE_H

typedef struct _file_ {
    unsigned long long rec;
    struct _file_ *nxt;
} bluefile, *file;

void enfile(unsigned long long v, file* f);
unsigned long long defile(file* f);

#endif // FILE_H

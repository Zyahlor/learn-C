#ifndef THUVIEN_H
#define THUVIEN_H
typedef struct {
  char time[16];
  char ip[46];
  char username[64];
  int success;
} logentry;
void read_log(void);
#endif // !THUVIEN_H

#ifndef BIGGEST_PAL_H
#define BIGGEST_PAL_H

void    putchar_fd(char c);
void    putstr_fd(const char *s);
int     is_pal(const char *s, int start, int end);
void    find_biggest_pal(const char *s, int *best_start, int *best_len);

#endif


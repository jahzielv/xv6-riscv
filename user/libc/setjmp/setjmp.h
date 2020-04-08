#define _JBLEN 18

typedef unsigned int jmp_buf[_JBLEN];
int setjmp(jmp_buf);
void longjmp(jmp_buf, int)  __attribute__((noreturn));



#define SIGTERM  15
#define SIGSEGV  11
#define SIGINT   2
#define SIGILL   4
#define SIGFPE   8
#define SIGABRT  6

#define SIG_IGN (void (*)(int))0
#define SIG_DFL (void (*)(int))-2
#define sig_atomic_t int
#define SIG_ERR (void (*)(int))-1

void (*signal(int sig, void (*func)(int)))(int);

int raise(int sig);
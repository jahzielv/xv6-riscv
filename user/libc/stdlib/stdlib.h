#define NULL (void*)0

// new types
typedef struct div_type {
    int quot;
    int rem;
} div_t;

typedef struct ldiv_type {
    long quot;
    long rem;
} ldiv_t;

typedef unsigned int size_t;
//helpers
int is_digit(char);
int is_space(char);

int atoi_os(char*);
int abs_os(int);
long atol_os(char*);
void *bsearch_os(const void *key, const void *base, size_t nel, size_t width, int (*cmp)(const void *, const void *));
long long atoll_os(char*);
div_t div_os(int, int);
long labs_os(long);
ldiv_t ldiv_os(long, long);
void qsort_os(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

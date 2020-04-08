typedef __builtin_va_list va_list;
#define va_start(list, param) __builtin_va_start(list, param)//(list = (((va_list)&param) + sizeof(param)))
#define va_arg(list, type)    __builtin_va_arg(list, type)//(*(type *)((list += sizeof(type)) - sizeof(type)))
#define va_end(ap) __builtin_va_end(ap)


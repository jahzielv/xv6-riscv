#include "../../types.h"
#include "../../user.h"

#define errno (*geterrno())


#define EILGHDLR 1000 // Illegal handler

int *geterrno(void);
void seterrno(void);



#include "Declaration.h"

inline void print (long long int x)
{ printf ("key = %I64u", x); }

inline void print (string x)
{ printf ("key = %s", x.c_str ()); }

inline int sprint (char* copy_in, long long int x)
{ return sprintf (copy_in, "key = %I64u\n", x); }

inline int sprint (char* copy_in, string x)
{ return sprintf (copy_in, "%s", x.c_str()); }

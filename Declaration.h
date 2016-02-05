#pragma GCC diagnostic ignored "-Wcpp"

#include "StdFax.h"

#define DUMP(x)  { fprintf (__DUMP__.dump_, "%s = ", #x); fprint (__DUMP__.dump_, (x)); }

const long long int POISON = -0xBADBEEF;

struct Dump
{
    private:
        Dump (const Dump& from);

        Dump& operator = (const Dump& from);

    public:
        FILE* dump_;

        Dump ():
            dump_ (fopen ("DumpFile\\Data.txt", "a"))
            {}

        ~Dump()
            { fclose (dump_); dump_ = nullptr; }
};

Dump __DUMP__;

inline bool IsPoison (void* check)
{
    return check == (void*) POISON;
}

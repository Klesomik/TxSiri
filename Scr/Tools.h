#ifndef Dec_h

#define Dec_h

#include "TXLib.h"

#include <stdarg.h>
#include <vector>
#include <map>

#include <stdio.h>
#include <iostream>

#include <assert.h>

#include <string.h>

#pragma GCC diagnostic ignored "-Wcpp"

#define DUMP(x)  { fprintf (__DUMP__.dump_, "%s = ", #x); fprint (__DUMP__.dump_, (x)); }

using std :: string;
using std :: cout;
using std :: cin;

using std :: vector;
using std :: max;
using std :: map;
using std :: pair;

const char* SIRI_PATH   = "C:\\Temp";
const char* SIRI_SPEECH = "~txSiri.vbs";
const char* SIRI_ANSWER = "C:\\Temp\\~txSiri.vbs";
const char* SIRI_CMD    = "start C:\\Temp\\~txSiri.vbs";

const int CMD_SIZE  = 128,
          NAME_SIZE = 512;
bool nextAsk = true;

const long long int POISON = -0xBADBEEF;

struct Dump
{
    private:
        Dump (const Dump& from);

        Dump& operator = (const Dump& from);

    public:
        FILE* dump_;

        Dump ():
            dump_ (/*fopen ("DumpFile\\Data.txt", "a")*/)
            {}

        ~Dump()
            { fclose (dump_); dump_ = nullptr; }
};

Dump __DUMP__;

const char* answerSiri[64] = { "Я не понимаю. Введите 'Да' или 'Нет':\n",
                                "Я не заслуживаю к себе такого отношения\n",
                                "Может быть хватит?\n",
                                "Ха-ха-ха как смешно!\n" };

const char* buySiri[64] = { "До встречи! Я буду скучать!\n",
                            "Вы лучший! Приходите ещё!\n",
                            "Спасибо вам за всё! Я буду ждать!\n",
                            "До скорых встреч!\n" };

const char* rusSiri[64] = { "Я не понимаю по-английски. Я русская Сири!\n",
                            "Давайте общаться по-русски\n",
                            "Переключите язык на русский\n",
                            "I don't speak English\n" };

const char* treeSiri[64] = { "Я поделюсь с вами своими знаниями:\n",
                             "Вот что мне удалось найти по вашему запросу:\n",
                             "Я передаю вам во владения все знания человечества:\n",
                             "Видимо Google бессилен:\n" };

void SS (string name);

void SS (string name)
{
    for (int i = name.length (); i >= 0; i--) if (name[i] == '\n') name[i] = ' ';

    FILE* f = fopen (SIRI_ANSWER, "w");

    fprintf (f, "On Error Resume Next\n\n"
                "Dim Speechobject\n"
                "Set Speechobject = CreateObject (\"sapi.spvoice\")\n"
                "SpeechObject.Speak \"%s\"\n", name.c_str ());

    fclose (f);

    system (SIRI_CMD);
    Sleep (25 * name.length ());
}

inline bool IsPoison (void* check)
{
    return check == (void*) POISON;
}

inline void print (long long int x)
{ printf ("key = %I64u", x); }

inline void print (string x)
{ printf ("key = %s", x.c_str ()); }

inline int sprint (char* copy_in, long long int x)
{ return sprintf (copy_in, "key = %I64u\n", x); }

inline int sprint (char* copy_in, string x)
{ return sprintf (copy_in, "%s", x.c_str()); }

inline void fprint (FILE* out, long long int x)
{ fprintf (out, "key = %I64u", x); }

inline void fprint (FILE* out, string x)
{ fprintf (out, "key = %s", x.c_str ()); }

void prints (const char param_print[], ...);
const char* printsScan (const char param_print[], ...);
const char* printScan (const char param_print[], ...);

void prints (const char param_print[], ...)
{
    va_list list;
    va_start (list, param_print);

    char buff[512] = "";

    vsprintf (buff, param_print, list);

    printf ("%s", buff);

    SS (buff);

    va_end (list);
}

const char* printsScan (const char param_print[], ...)
{
    va_list list;
    va_start (list, param_print);

    char buff[512] = "";

    vsprintf (buff, param_print, list);

    $c printf ("%s", buff); $d

    SS (buff);

    va_end (list);

    fflush (stdin);

    static char scan_data[CMD_SIZE] = "";
    fgets (scan_data, sizeof (scan_data) - 1, stdin);

    int len = strlen (scan_data) - 1;
    if (len >= 1 && scan_data[len] == '\n') scan_data[len] = 0;

    return scan_data;
}

const char* printScan (const char param_print[], ...)
{
    va_list list;
    va_start (list, param_print);

    $c; vprintf (param_print, list); $d;

    va_end (list);

    fflush (stdin);

    static char scan_data[CMD_SIZE] = "";
    fgets (scan_data, sizeof (scan_data) - 1, stdin);

    int len = strlen (scan_data) - 1;
    if (len >= 1 && scan_data[len] == '\n') scan_data[len] = 0;

    return scan_data;
}

#endif /* Dec_h */

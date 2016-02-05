#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
    setlocale   (LC_CTYPE, "Russian");
    _wsetlocale (LC_ALL, L"UTF-8");

    char name[] = "Вася любит мышей";

    wchar_t dest[512] = L"";

    mbstowcs (dest, name, 512);

    FILE* test = _wfopen (L"test.txt", L"w");

    fwprintf (test, L"%S", dest);

    fclose (test);

    return 0;
}

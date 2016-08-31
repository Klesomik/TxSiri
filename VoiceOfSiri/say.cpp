#include "TXLib.h"

void SiriSpeak (string name);

int main()
{
    txCreateWindow (800, 600);

    string str;
    cin >> str;

    SiriSpeak (str);

    return 0;
}

void SiriSpeak (string name)
{
    mkdir ("C:\\Temp");

    FILE* f = fopen ("C:\\Temp\\~txSiri.vbs", "w");

    fprintf (f, "dim speechobject\n"
                "set speechobject = createobject (\"sapi.spvoice\")\n"
                "speechobject.speak \"%s\"\n", name.c_str ());

    fclose (f);

    system ("start C:\\Temp\\~txSiri.vbs");
}



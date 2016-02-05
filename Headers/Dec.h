#include "..\\Node.h"

#include "TXLib.h"

#include <stdarg.h>
#include <vector>
#include <map>

using std :: vector;
using std :: max;
using std :: map;
using std :: pair;

const int CMD_SIZE  = 128,
          NAME_SIZE = 512;
bool nextAsk = true;

const char* answerSiri[64] = { "� �� �������. ������� '��' ��� '���':\n",
                                "� �� ���������� � ���� ������ ���������\n",
                                "����� ���� ������?\n",
                                "��-��-�� ��� ������!\n" };

const char* buySiri[64] = { "�� �������! � ���� �������!\n",
                            "�� ������! ��������� ���!\n",
                            "������� ��� �� ��! � ���� �����!\n",
                            "�� ������ ������!\n" };

const char* rusSiri[64] = { "� �� ������� ��-���������. � ������� ����!\n",
                            "������� �������� ��-������\n",
                            "����������� ���� �� �������\n",
                            "I don't speak English\n" };

const char* treeSiri[64] = { "� �������� � ���� ������ ��������:\n",
                             "��� ��� ��� ������� ����� �� ������ �������:\n",
                             "� ������� ��� �� �������� ��� ������ ������������:\n",
                             "������ Google ��������:\n" };

void SS (string name);

void SS (string name)
{
    mkdir  ("C:\\Temp");
    unlink ("C:\\Temp\\~txSiri.vbs");

    for (int i = name.length (); i >= 0; i--) if (name[i] == '\n') name[i] = ' ';

    FILE* f = fopen ("C:\\Temp\\~txSiri.vbs", "w");

    fprintf (f, "On Error Resume Next\n\n"
                "Dim Speechobject\n"
                "Set Speechobject = CreateObject (\"sapi.spvoice\")\n"
                "SpeechObject.Speak \"%s\"\n", name.c_str ());

    fclose (f);

    system ("start C:\\Temp\\~txSiri.vbs");
    Sleep (25 * name.length ());
}

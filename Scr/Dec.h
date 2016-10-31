#include "Node.h"

#include "TXLib.h"

#include <stdarg.h>
#include <vector>
#include <map>

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

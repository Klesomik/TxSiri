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

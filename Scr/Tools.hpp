#ifndef Tools_h

#define Tools_h

#include "TXLib.h"

#include <stdarg.h>
#include <vector>
#include <map>

#include <stdio.h>
#include <iostream>

#include <assert.h>

#include <string.h>

#include "Dotter//Dotter.hpp"

#pragma GCC diagnostic ignored "-Wcpp"

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

bool Compare (const std::string& first, const std::string& second);

bool Compare (const std::string& first, const std::string& second)
{
    return (stricmp (first.c_str (), second.c_str ()) == 0);
}

void Speak (const char* message, ...);
void PrintSiri (const char* message, ...);
void PrintSystem (const char* message, ...);

void Speak (const char* message, ...) // SS
{
    const int size = 512;

    va_list args;
    va_start (args, message);

    char buffer[size] = "";

    vsprintf (buffer, message, args);

    va_end (args);

    for (int i = 0; i < size; i++)
        if (buffer[i] == '\n')
            buffer[i] = ' ';

    std::ofstream out (SIRI_ANSWER);

    out << "On Error Resume Next\n\n";
    out << "Dim Speechobject\n";
    out << "Set Speechobject = CreateObject (\"sapi.spvoice\")\n";
    out << "SpeechObject.Speak \"" << buffer << "\"\n";

    out.close ();

    system (SIRI_CMD);
    //Sleep (25 * size);
}

void PrintSiri (const char* message, ...) // prints
{
    const int size = 512;

    va_list args;
    va_start (args, message);

    char buffer[size] = "";

    vsprintf (buffer, message, args);

    va_end (args);

    $c
    std::cout << buffer;
    $d

    Speak (buffer);
}

void PrintSystem (const char* message, ...) // prints
{
    const int size = 512;

    va_list args;
    va_start (args, message);

    char buffer[size] = "";

    vsprintf (buffer, message, args);

    va_end (args);

    $y
    std::cout << buffer;
    $d
}

#endif /* Tools_h */

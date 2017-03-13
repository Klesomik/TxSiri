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

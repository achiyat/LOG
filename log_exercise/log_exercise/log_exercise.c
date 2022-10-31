#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable : 4996)

void Log(char message[100]);
void LogError(char message[100]);
void LogEvent(char message[100]);

FILE* f;

int main()
{

    char str[100];
    int num;

    LogEvent("Event - The system started running\n");

    LogEvent("Event - a new file named 'myProg.log' will be opened\n");

    LogEvent("Event - The user requests a number\n");
    scanf("%d", &num);
    sprintf(str, "%d", num);

    LogEvent("Event - the number was received from the user successfully\n");

    LogEvent("Event - a new file named 'numbers.txt' will be opened\n");
    FILE* f1 = fopen("numbers.txt", "a");
    if (f1)
    {
        LogEvent("Event - The user requests a number\n");
        scanf("%d", &num);
        sprintf(str, "%d", num);

        LogEvent("Event - the number was received from the user successfully\n");

        LogEvent("Event - opening the program and running it successfully\n");
        LogEvent("Event - the loop has opened\n");
        for (int i = 1; i <= num; i++)
        {
            sprintf(str, "%d ", i);
            LogEvent("Event - the number was put in a string\n");
            fputs(str, f1);
            LogEvent("Event - the string was printed to a file\n");
        }
        LogEvent("Event - the loop is closed\n");
        fputs("\n", f1);
        fclose(f1);
        LogEvent("Event - the file named 'numbers.txt' is closed\n");
        LogEvent("Event - the program was successfully closed\n");
    }
    else
    {
        LogError("Error - File Not Opened\n");
    }

    fclose(f);
    LogEvent("Event - the file named 'myProg.log' is closed\n");
    LogEvent("Event - the System has ended the program\n");

    return 0;
}

void Log(char message[100])
{
    f = fopen("myProg.log", "a");
    
    time_t t;
    time(&t);
    struct tm* timeinfo;
    timeinfo = localtime(&t);

    char str[100];

    sprintf(str, "%d/%d/%d  %d:%d  ", timeinfo->tm_wday + 1, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min);
    fputs(str, f);
    fputs(message, f);
    


}

void LogError(char message[100])
{
    Log(message);
}

void LogEvent(char message[100])
{
    Log(message);
}
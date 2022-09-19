// Velikanov_Amontsev.cpp 
//Великанов Алексей и Амонцев Никита 3-09ПС-3

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");

    char myText[255];
    char path[255];
    char fileName[255];
    char* next_token1 = NULL;
    bool vote = false;
    char yesOrNo;
    int errCode;

    cout << "Введите путь до файла и текст для файла\n";
    cin.getline(fileName, 255);
    strcpy_s(path, strtok_s(fileName, " ", &next_token1));
    strcpy_s(myText, strtok_s(NULL, " ", &next_token1)); \

        HANDLE hFile = CreateFileA(path, GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
    errCode = GetLastError();
    cout << errCode << "\n";
    if (errCode == 3)
    {
        cout << "Ошибка в пути";
        return 0;
    }

    if (errCode == 80)
    {
        cout << "Файл с таким названием уже существует, не хотите ли Вы его перезаписать? Y - да, N - нет.\n";
        cin >> yesOrNo;
        if (yesOrNo == 'Y')
        {
            vote = true;
        }
        else if (yesOrNo == 'N') {
            cout << "Хорошо, файл не будет перезаписан\n";
            CloseHandle(hFile);
        }

        else {
            cout << "Вы ввели неверное значение";
            CloseHandle(hFile);
        }

        if (vote == true)
        {
            HANDLE hFile = CreateFileA(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

            DWORD dwBytesToWrite;



            WriteFile(hFile, myText, strlen(myText), &dwBytesToWrite, NULL);

            cout << "Введённые данные являются верными и текстовый файл был создан";
        }
    }
    DWORD dwBytesToWrite;

    WriteFile(hFile, myText, strlen(myText), &dwBytesToWrite, NULL);
}

#pragma once

#define _USE_MATH_DEFINES
#define MAX_LOADSTRING 100
#define MAX_EVENTS 1000
#define _CRT_SECURE_NO_WARNINGS

#include "resource.h"
#include <string>
#include <iostream>
#include <cmath>
#include <comdef.h>

using namespace std;

// Глобальные переменные:
// start
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // Имя класса окна
// Текст для локализации:
    // Текст для MessageBox:
WCHAR sNoInput[MAX_LOADSTRING];
WCHAR sInvalidInput[MAX_LOADSTRING];
WCHAR sTitleError[MAX_LOADSTRING];
WCHAR sEndTimer[MAX_LOADSTRING];
WCHAR sTitleTimer[MAX_LOADSTRING];
WCHAR sChangeLang[MAX_LOADSTRING];
WCHAR sChangeLangTitle[MAX_LOADSTRING];
// Текст для окон, используется при создании, статичен:
// Static
WCHAR sOutput[MAX_LOADSTRING];
WCHAR sInput[MAX_LOADSTRING];
WCHAR sDayOfWeek[MAX_LOADSTRING];
WCHAR sMonth[MAX_LOADSTRING];
WCHAR sYear[MAX_LOADSTRING];
WCHAR sDay[MAX_LOADSTRING];
WCHAR sHour[MAX_LOADSTRING];
WCHAR sMinute[MAX_LOADSTRING];
WCHAR sSecond[MAX_LOADSTRING];
WCHAR sChangeLangText[MAX_LOADSTRING];
WCHAR sDescribtionText[MAX_LOADSTRING];
WCHAR sDayChoosing[MAX_LOADSTRING];
WCHAR sTimeText[MAX_LOADSTRING];
WCHAR sHoursBegin[MAX_LOADSTRING];
WCHAR sMinutesBegin[MAX_LOADSTRING];
WCHAR sHoursEnd[MAX_LOADSTRING];
WCHAR sMinutesEnd[MAX_LOADSTRING];
// Btn
WCHAR sStart[MAX_LOADSTRING];
WCHAR sStop[MAX_LOADSTRING];
WCHAR sPause[MAX_LOADSTRING];
WCHAR sContinue[MAX_LOADSTRING];
WCHAR sReset[MAX_LOADSTRING];
// main menu strings
WCHAR sMenuFile[MAX_LOADSTRING];
WCHAR sMenuHelp[MAX_LOADSTRING];
WCHAR sMenuEvent[MAX_LOADSTRING];
WCHAR sMenuLanguage[MAX_LOADSTRING];
WCHAR sMenuTimer[MAX_LOADSTRING];
WCHAR sMenuClock[MAX_LOADSTRING];
// submenu strings
WCHAR sSubmenuExit[MAX_LOADSTRING];
WCHAR sSubmenuAbout[MAX_LOADSTRING];
WCHAR sSubmenuLanguage[MAX_LOADSTRING];
WCHAR sSubmenuEventSave[MAX_LOADSTRING];
WCHAR sSubmenuEventLoad[MAX_LOADSTRING];
WCHAR sSubmenuEventAdd[MAX_LOADSTRING];
WCHAR sSubmenuEventDelete[MAX_LOADSTRING];
WCHAR sSubmenuTimerDefault[MAX_LOADSTRING];
WCHAR sSubmenuTimerReverse[MAX_LOADSTRING];
WCHAR sSubmenuTimerSD[MAX_LOADSTRING];
WCHAR sSubmenuStopwatch[MAX_LOADSTRING];
WCHAR sSubmenuClockModern[MAX_LOADSTRING];
WCHAR sSubmenuClockOld[MAX_LOADSTRING];

HWND hwnd;

bool mainReturn;
bool language_en = true;
bool language_ru = false;
bool counter_day = true;

COLORREF white = RGB(255, 255, 255);
COLORREF black = RGB(0, 0, 0);
COLORREF red = RGB(255, 0, 0);
COLORREF current_dialog = 15790320;

const int RADIUS_INNER = 151;
const int RADIUS_OUTER = 161;

const int structWidghtNum = 30;
const int structWidghtDesc = 1000;
const int structWidghtDayOfWeek = 80;
const int structWidghtTimeHour = 40;
const int structWidghtTimeMin = 40;
const int helpHeight = 40;
const int structHeight = 25;

// high precision time measurement variables
LARGE_INTEGER StartingTime;
LARGE_INTEGER EndingTime;
LARGE_INTEGER ElapsedMicroseconds;
LARGE_INTEGER Frequency;
int msecond_counter;

// Используется для получения размеров окна. Изменения проверяются с каждым обновлением окна
RECT winCord;
// Используется для получения системного времени. Изменения проверяются с каждым обновлением окна
SYSTEMTIME sys_time;

// structures
struct planStruct {
    int posY{};
    WCHAR strDescribtion[100000]{};
    bool onMonday = false; // 0|1
    bool onTuesday = false;
    bool onWednesday = false;
    bool onThursday = false;
    bool onFriday = false;
    bool onSaturday = false;
    bool onSunday = false; // 0|1
    int hourBegin = -1;
    int minuteBegin = -1;
    int hourEnd = -1;
    int minuteEnd = -1;

    HWND hEditDesc{};
    HWND hEditDays{};
    HWND hEditTimeHourBegin{};
    HWND hEditTimeMinBegin{};
    HWND hEditTimeHourEnd{};
    HWND hEditTimeMinEnd{};
    void createStructure(HWND hWnd, HINSTANCE hInstance, int up, int lastEvent);
    void helpUserInfoStructure(HWND hWnd, HINSTANCE hInstance);
    void deleteStructure(HWND hwnd, HINSTANCE hinstance, int element);
};
// variables for planStruct
const int beginUp = 60;
int lastUp = 60;
int lastEvent = 0;
// arrays
planStruct events[MAX_EVENTS]; // основной массив событий
int eventsIndex[6][MAX_EVENTS];
planStruct temp;

// bool variables
bool fillAndDrawStructure = true;
bool add_days = true;
bool wasOpened = false;
bool lastEventIncrement = false;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Language_choosing(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Add_event(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Choose_day(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Timer_default(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Timer_reverse(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Timer_systemdependent(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Stopwatch(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Clock_modern(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Clock_old(HWND, UINT, WPARAM, LPARAM);

// funct logic
void ConvertDayOfWeekToString(HWND hDlg, int nIDDlgItem, int day_of_week, bool language_en, bool language_ru);
void ConvertMonthToString(HWND hDlg, int nIDDlgItem, int month, bool language_en, bool language_ru);
int FillEventsWithDaysOfWeek(HWND hDlg);
void DlgDaysOfWeekWasOpened(HWND hDlg);

wchar_t* int_to_string(int num);
const char* WCHAR_to_char(WCHAR* string);
void changeMenuElement(HWND hWnd);
void saveCurrentEventsInFile();
void loadCurrentEventsFromFile();
void sortEventsByDay();

// func for static/dynamic painting structures
void CreateStructureWatch(int left, int right, int up, int bottom, int centerX, int centerY, HDC hdc);
void DrawHourLine(int left, int right, int up, int bottom, int centerX, int centerY, int hour, HDC hdc);
void DrawMinuteLine(int left, int right, int up, int bottom, int centerX, int centerY, int minute, HDC hdc);
void DrawSecondLine(int left, int right, int up, int bottom, int centerX, int centerY, int second,HDC hdc);

// func graphics
void L(int x1, int y1, int x2, int y2, int width, COLORREF color, HDC hdc);
void LTO(int x2, int y2, int width, COLORREF color, HDC hdc);
void R(int x1, int y1, int x2, int y2, int width, COLORREF color, HDC hdc);
void C(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int width, COLORREF color_pen, COLORREF color_brush, HDC hdc);
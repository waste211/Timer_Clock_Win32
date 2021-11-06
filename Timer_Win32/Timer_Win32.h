#pragma once

#define _USE_MATH_DEFINES
#define MAX_LOADSTRING 100

#include "resource.h"
#include <string>
#include <iostream>
#include <cmath>

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
// Btn
WCHAR sStart[MAX_LOADSTRING];
WCHAR sStop[MAX_LOADSTRING];
WCHAR sPause[MAX_LOADSTRING];
WCHAR sContinue[MAX_LOADSTRING];
WCHAR sReset[MAX_LOADSTRING];
// main menu strings
WCHAR sMenuFile[MAX_LOADSTRING];
WCHAR sMenuHelp[MAX_LOADSTRING];
WCHAR sMenuLanguage[MAX_LOADSTRING];
WCHAR sMenuTimer[MAX_LOADSTRING];
WCHAR sMenuClock[MAX_LOADSTRING];
// submenu strings
WCHAR sSubmenuExit[MAX_LOADSTRING];
WCHAR sSubmenuAbout[MAX_LOADSTRING];
WCHAR sSubmenuLanguage[MAX_LOADSTRING];
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
    HWND hEditNum{};
    HWND hEditDesc{};
    HWND hEditDays{};
    HWND hEditTimeHour{};
    HWND hEditTimeMin{};
    int posY;
    void createStructure(HWND hWnd, HINSTANCE hInstance, int up, int lastEvent);
    void helpUserInfoStructure(HWND hWnd, HINSTANCE hInstance);
    // void addNewEvent();
};
int lastUp = 60;
int lastEvent = 0;
// arrays
planStruct events[100];

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Language_choosing(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Timer_default(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Timer_reverse(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Timer_systemdependent(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Stopwatch(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Clock_modern(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Clock_old(HWND, UINT, WPARAM, LPARAM);

// funct logic
bool processMainWindow(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, HINSTANCE hInstance);

void ConvertDayOfWeekToString(HWND hDlg, int nIDDlgItem, int day_of_week, bool language_en, bool language_ru);
void ConvertMonthToString(HWND hDlg, int nIDDlgItem, int month, bool language_en, bool language_ru);

// func for static/dynamic painting structures
void CreateStructureWatch(int left, int right, int up, int bottom, int centerX, int centerY, HDC hdc);
void DrawHourLine(int left, int right, int up, int bottom, int centerX, int centerY, int hour, HDC hdc);
void DrawMinuteLine(int left, int right, int up, int bottom, int centerX, int centerY, int minute, HDC hdc);
void DrawSecondLine(int left, int right, int up, int bottom, int centerX, int centerY, int second,HDC hdc);
wchar_t *int_to_string(int num);

// func graphics
void L(int x1, int y1, int x2, int y2, int width, COLORREF color, HDC hdc);
void LTO(int x2, int y2, int width, COLORREF color, HDC hdc);
void R(int x1, int y1, int x2, int y2, int width, COLORREF color, HDC hdc);
void C(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int width, COLORREF color_pen, COLORREF color_brush, HDC hdc);
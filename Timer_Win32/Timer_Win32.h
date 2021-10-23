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
// Текст для окон, используется при создании, статичен:
WCHAR sOutput[MAX_LOADSTRING];

HWND hwnd;

bool language_ru = false;
bool language_en = true;
bool counter_day = true;

COLORREF white = RGB(255, 255, 255);
COLORREF black = RGB(0, 0, 0);
COLORREF red = RGB(255, 0, 0);
COLORREF current_dialog = 15790320;

const int RADIUS_INNER = 151;
const int RADIUS_OUTER = 161;

// high precision time measurement variables
LARGE_INTEGER StartingTime;
LARGE_INTEGER EndingTime;
LARGE_INTEGER ElapsedMicroseconds;
LARGE_INTEGER Frequency;

int msecond_counter;

// funct logic
void ConvertDayOfWeekToString(HWND hDlg, int nIDDlgItem, int day_of_week);
void ConvertMonthToString(HWND hDlg, int nIDDlgItem, int month);

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
#pragma once

#include "resource.h"
#include <string>

using namespace std;

// funct logic

void ConvertDayOfWeekToString(HWND hDlg, int day_of_week);
void ConvertMounthToString(HWND hDlg, int mounth);

// func graphics

void L(int x1, int y1, int x2, int y2, COLORREF color);
void LTO(int x2, int y2, COLORREF color);
void R(int x1, int y1, int x2, int y2, COLORREF color);
void C(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, COLORREF color);
void createField();
void looseAlgorythm();
void FaceElectron(HDC hdc, double x, double y, COLORREF ecolor);
void MagnetField(HDC hdc, double B);
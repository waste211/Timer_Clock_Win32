// Timer_Win32.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Timer_Win32.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
double B;
HWND hwnd;
HDC hdc;
double dt;
COLORREF white = RGB(255, 255, 255);
COLORREF red = RGB(255, 0, 0);
bool start_game;
HBITMAP hbm;


// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Timer_default(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Timer_reverse(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Stopwatch(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Clock_modern(HWND, UINT, WPARAM, LPARAM);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TIMERWIN32, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TIMERWIN32));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TIMERWIN32));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TIMERWIN32);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                // to make a movable and sel-extended window
                CreateDialog(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case ID_TIMER_DEFAULT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_DEFAULT_TIMER), hWnd, Timer_default);
                break;
            case ID_TIMER_REVERSETIMER:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_REVERSE_TIMER), hWnd, Timer_reverse);
                break;
            case ID_TIMER_SYSTEM:
                // DialogBox(hInst, MAKEINTRESOURCE(IDD_SYSTEM_TIMER), hWnd, Timer_system);
                break;
            case ID_TIMER_STOPWATCH:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_STOPWATCH), hWnd, Stopwatch);
                break;
            case ID_CLOCK_MODERN:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_CLOCK_MODERN), hWnd, Clock_modern);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Timer_default(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    int input_hour = 0;
    int input_minute = 0;
    int input_second = 0;

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_START)
        {
            input_hour = GetDlgItemInt(hDlg, IDC_EDIT_HOUR_INPUT, NULL, TRUE);
            input_minute = GetDlgItemInt(hDlg, IDC_EDIT_MINUTE_INPUT, NULL, TRUE);
            input_second = GetDlgItemInt(hDlg, IDC_EDIT_SECOND_INPUT, NULL, TRUE);

            SetTimer(hDlg, 1, 1000, NULL);
            if (input_hour == 0) {
                if (input_minute == 0) {
                    if (input_second == 0) {
                        KillTimer(hDlg, 1);
                        MessageBox(GetActiveWindow(), (LPCWSTR)L"No input", (LPCWSTR)L"ERROR", MB_ICONERROR);
                    }
                }
            }

            SetDlgItemInt(hDlg, IDC_EDIT_HOUR1, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_MINUTE, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SECOND, 0, TRUE);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_STOP)
        {
            KillTimer(hDlg, 1);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_PAUSE)
        {
            //KillTimer(hDlg, 1);
            return (INT_PTR)TRUE;
        }

        break;
    case WM_TIMER:
        if (LOWORD(wParam) == 1) {
            input_hour = GetDlgItemInt(hDlg, IDC_EDIT_HOUR_INPUT, NULL, TRUE);
            input_minute = GetDlgItemInt(hDlg, IDC_EDIT_MINUTE_INPUT, NULL, TRUE);
            input_second = GetDlgItemInt(hDlg, IDC_EDIT_SECOND_INPUT, NULL, TRUE);

            int edit_hour = GetDlgItemInt(hDlg, IDC_EDIT_HOUR1, NULL, TRUE);
            int edit_min = GetDlgItemInt(hDlg, IDC_EDIT_MINUTE, NULL, TRUE);
            int edit_sec = GetDlgItemInt(hDlg, IDC_EDIT_SECOND, NULL, TRUE);

            edit_sec++;

            if (edit_hour == input_hour) {
                if (edit_min == input_minute) {
                    if (edit_sec == input_second) {
                        KillTimer(hDlg, 1);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, edit_hour, TRUE);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, edit_min, TRUE);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, edit_sec + 1, TRUE);
                        MessageBox(GetActiveWindow(), (LPCWSTR)L"Timer ended", (LPCWSTR)L"TIMER", MB_ICONINFORMATION);
                    }
                    else {
                        if (edit_sec == 60) {
                            edit_min++;
                            edit_sec = 0;
                        }
                    }
                }
                else {
                    if (edit_sec == 60) {
                        edit_min++;
                        edit_sec = 0;
                    }
                    if (edit_min == 60) {
                        edit_hour++;
                        edit_min = 0;
                        edit_sec = 0;
                    }
                }
            }
            else {
                if (edit_sec == 60) {
                    edit_min += 1;
                    edit_sec = 0;
                }
                if (edit_min == 60) {
                    edit_hour++;
                    edit_min = 0;
                    edit_sec = 0;
                }
            }

            SetDlgItemInt(hDlg, IDC_EDIT_HOUR1, edit_hour, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_MINUTE, edit_min, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SECOND, edit_sec, TRUE);
            return (INT_PTR)TRUE;
        }

        break;
    default:
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Timer_reverse(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    int input_hour; 
    int input_minute;
    int input_second;

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_R_START)
        {
            input_hour = GetDlgItemInt(hDlg, IDC_EDIT_R_HOUR_INPUT, NULL, TRUE);
            input_minute = GetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE_INPUT, NULL, TRUE);
            input_second = GetDlgItemInt(hDlg, IDC_EDIT_R_SECOND_INPUT, NULL, TRUE);

            SetTimer(hDlg, 2, 1000, NULL);
            if (input_hour == 0) {
                if (input_minute == 0) {
                    if (input_second == 0) {
                        KillTimer(hDlg, 2);
                        MessageBox(GetActiveWindow(), (LPCWSTR)L"No input", (LPCWSTR)L"ERROR", MB_ICONERROR);
                    }
                }
            }

            SetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, input_hour, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, input_minute, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, input_second, TRUE);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_R_STOP)
        {
            KillTimer(hDlg, 2);
            SetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, 0, TRUE);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_R_PAUSE)
        {
            KillTimer(hDlg, 2);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_R_CONTINUE)
        {
            SetTimer(hDlg, 2, 1000, NULL);
            return (INT_PTR)TRUE;
        }
        break;
    case WM_TIMER:
        if (LOWORD(wParam) == 2) {
            int edit_hour = GetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, NULL, TRUE);
            int edit_min = GetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, NULL, TRUE);
            int edit_sec = GetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, NULL, TRUE);
            edit_sec--;

            if (edit_hour == 0) {
                if (edit_min == 0) {
                    if (edit_sec == 0) {
                        KillTimer(hDlg, 2);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, edit_hour, TRUE);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, edit_min, TRUE);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, edit_sec, TRUE);
                        MessageBox(GetActiveWindow(), (LPCWSTR)L"Timer ended", (LPCWSTR)L"TIMER", MB_ICONINFORMATION);
                    }
                    else {
                        if (edit_sec == 0) {
                            edit_sec = 0;
                        }
                    }
                }
                else {
                    if (edit_sec == 0) {
                        edit_min--;
                        edit_sec = 60;
                    }
                    if (edit_min == 0) {
                        edit_sec = 60;
                    }
                }
            }
            else {
                if (edit_hour != 0 && edit_min != 0) {
                    if (edit_sec == 0) {
                        edit_min--;
                        edit_sec = 60;
                    }
                    if (edit_min == 0) {
                        edit_hour--;
                        edit_min = 60;
                        edit_sec = 60;
                    }
                }
            }

            SetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, edit_hour, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, edit_min, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, edit_sec, TRUE);
            return (INT_PTR)TRUE;
        }
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Stopwatch(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_SW_START)
        {
            SetTimer(hDlg, 4, 100, NULL);
            /*
            * 
            wstring h = L"text";
            h[3] = 0;

            string number = to_string(0);
            LPCWSTR Last = h.c_str();
            SetDlgItemText(hDlg, IDC_EDIT_SW_HOUR, (LPCWSTR)Last);

            */
            SetDlgItemInt(hDlg, IDC_EDIT_SW_HOUR, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SW_MINUTE, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SW_SECOND, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SW_MSECOND, 0, TRUE);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_SW_STOP)
        {
            KillTimer(hDlg, 4);

            SetDlgItemInt(hDlg, IDC_EDIT_SW_HOUR, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SW_MINUTE, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SW_SECOND, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SW_MSECOND, 0, TRUE);

            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_SW_PAUSE)
        {
            KillTimer(hDlg, 4);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_SW_CONTINUE)
        {
            SetTimer(hDlg, 4, 100, NULL);
            return (INT_PTR)TRUE;
        }

        break;
    case WM_TIMER:
        if (LOWORD(wParam) == 4) {
            int edit_hour = GetDlgItemInt(hDlg, IDC_EDIT_SW_HOUR, NULL, TRUE);
            int edit_min = GetDlgItemInt(hDlg, IDC_EDIT_SW_MINUTE, NULL, TRUE);
            int edit_sec = GetDlgItemInt(hDlg, IDC_EDIT_SW_SECOND, NULL, TRUE);
            int edit_msec = GetDlgItemInt(hDlg, IDC_EDIT_SW_MSECOND, NULL, TRUE);

            edit_msec++;
            if (edit_msec == 10) {
                edit_sec += 1;
                edit_msec = 0;
            }
            if (edit_sec == 60) {
                edit_min += 1;
                edit_sec = 0;
                edit_msec = 0;
            }
            if (edit_min == 60) {
                edit_hour++;
                edit_min = 0;
                edit_sec = 0;
            }

            SetDlgItemInt(hDlg, IDC_EDIT_SW_MINUTE, edit_min, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SW_HOUR, edit_hour, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SW_SECOND, edit_sec, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SW_MSECOND, edit_msec, TRUE);

            return (INT_PTR)TRUE;
        }

        break;
    default:
        break;
    }
    return (INT_PTR)FALSE;
}
// GetSystemTime(...)

INT_PTR CALLBACK Clock_modern(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    int hour, minute, second;
    int day_of_week, day, mounth, year;

    SYSTEMTIME sys_time;
    SetTimer(hDlg, 5, 100, NULL);
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;   
        }
        break;
    case WM_TIMER:
        GetLocalTime(&sys_time);
        

        hour = sys_time.wHour;
        minute = sys_time.wMinute;
        second = sys_time.wSecond;


        day_of_week = sys_time.wDayOfWeek;
        ConvertDayOfWeekToString(hDlg, day_of_week);

        day = sys_time.wDay;

        mounth = sys_time.wMonth;
        ConvertMounthToString(hDlg, mounth);

        year = sys_time.wYear;

        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_HOUR, hour, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_MINUTE, minute, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_SECOND, second, TRUE);

        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_DAY, sys_time.wDay, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_YEAR, sys_time.wYear, TRUE);

        break;
    }
    return (INT_PTR)FALSE;
}

void ConvertDayOfWeekToString(HWND hDlg, int day_of_week) {
    switch (day_of_week) {
    case 1:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_DAYOFWEEK, (LPCWSTR)L"Monday");
        break;
    case 2:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_DAYOFWEEK, (LPCWSTR)L"Tuesday");
        break;
    case 3:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_DAYOFWEEK, (LPCWSTR)L"Wednesday");
        break;
    case 4:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_DAYOFWEEK, (LPCWSTR)L"Thursday");
        break;
    case 5:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_DAYOFWEEK, (LPCWSTR)L"Friday");
        break;
    case 6:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_DAYOFWEEK, (LPCWSTR)L"Saturday");
        break;
    case 7:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_DAYOFWEEK, (LPCWSTR)L"Sunday");
        break;
    default:
        break;
    }
}

void ConvertMounthToString(HWND hDlg, int mounth) {
    switch (mounth) {
    case 1:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_MOUNTH, (LPCWSTR)L"January");
        break;
    case 2:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_MOUNTH, (LPCWSTR)L"February");
        break;
    case 3:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_MOUNTH, (LPCWSTR)L"March");
        break;
    case 4:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_MOUNTH, (LPCWSTR)L"April");
        break;
    case 5:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_MOUNTH, (LPCWSTR)L"May");
        break;
    case 6:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_MOUNTH, (LPCWSTR)L"June");
        break;
    case 7:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_MOUNTH, (LPCWSTR)L"July");
        break;
    case 8:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_MOUNTH, (LPCWSTR)L"August");
        break;
    case 9:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_MOUNTH, (LPCWSTR)L"September");
        break;
    case 10:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_MOUNTH, (LPCWSTR)L"October");
        break;
    case 11:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_MOUNTH, (LPCWSTR)L"November");
        break;
    case 12:
        SetDlgItemTextW(hDlg, IDC_EDIT_CLOCK_MOUNTH, (LPCWSTR)L"December");
        break;
    default:
        break;
    }
}


// FUNC DRAWING

void L(int x1, int y1, int x2, int y2, COLORREF color)
{
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 1, color);
    SelectObject(hdc, hPen);
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    DeleteObject(hPen);
}

void LTO(int x2, int y2, COLORREF color)
{
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 1, color);
    SelectObject(hdc, hPen);
    LineTo(hdc, x2, y2);
    DeleteObject(hPen);
}

void R(int x1, int y1, int x2, int y2, COLORREF color)
{
    HPEN hPen;
    HBRUSH hBrush;
    hPen = CreatePen(PS_SOLID, 1, color);
    SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(color);
    SelectObject(hdc, hBrush);
    Rectangle(hdc, x1, y1, x2, y2);
    DeleteObject(hPen);
    DeleteObject(hBrush);
}

void C(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, COLORREF color)
{
    HPEN hPen;
    HBRUSH hBrush;
    hPen = CreatePen(PS_SOLID, 1, color);
    SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(color);
    SelectObject(hdc, hBrush);
    Chord(hdc, x1, y1, x2, y2, x3, y3, x4, y4);
    DeleteObject(hPen);
    DeleteObject(hBrush);
}

void createField()
{
    L(50, 250, 50, 450, red);
    LTO(60, 450, red);
    L(50, 250, 60, 250, red);

    /*
    L(950, 250, 950, 450, red);
    LTO(940, 450, red);
    L(950, 250, 940, 250, red);
    */
    R(0, 0, 1000, 50, red);
    R(0, 700, 1000, 650, red);

    L(490, 0, 490, 700, red);
}


void FaceElectron(HDC hdc, double x, double y, COLORREF ecolor)
{
    unsigned rand_value = 5;
    int x1;
    int y1;
    int x0;
    int y0;

    int i;
    i = 0;
    while (i < 50)
    {
        x1 = -5 + rand() % 11;
        y1 = -5 + rand() % 11;
        x0 = (int)x + x1;
        y0 = (int)y + y1;
        int R;
        int G;
        int B;
        SetPixel(hdc, x0, y0, RGB(R = 100 + rand() % 255, G = 100 + rand() % 255, B = 100 + rand() % 255));
        i++;

    }
}

void MagnetField(HDC hdc, double B)
{
    if (B > 0)
    {
        HPEN hPen;
        hPen = CreatePen(PS_SOLID, 1, RGB(100, 100, 255));
        SelectObject(hdc, hPen);
        for (int i = 100; i < 950; i = i + 100)
            for (int j = 100; j < 600; j = j + 100)
            {
                SetPixel(hdc, i, j, RGB(100, 100, 255));
                Arc(hdc, i - (int)(B * 10), j - (int)(B * 10), i + (int)(B * 10), j + (int)(B * 10), i - (int)(B * 10), j - (int)(B * 10), i - (int)(B * 10), j - (int)(B * 10));
            }
        DeleteObject(hPen);

    }
    if (B < 0)
    {
        HPEN hPen;
        hPen = CreatePen(PS_SOLID, 1, RGB(255, 100, 100));
        SelectObject(hdc, hPen);
        for (int i = 100; i < 950; i = i + 100)
            for (int j = 100; j < 600; j = j + 100)
            {
                MoveToEx(hdc, i - (int)(B * 10), j - (int)(B * 10), NULL);
                LineTo(hdc, i + (int)(B * 10), j + (int)(B * 10));
                MoveToEx(hdc, i - (int)(B * 10), j + (int)(B * 10), NULL);
                LineTo(hdc, i + (int)(B * 10), j - (int)(B * 10));

                DeleteObject(hPen);
                Arc(hdc, i - (int)(B * 10), j - (int)(B * 10), i + (int)(B * 10), j + (int)(B * 10), i - (int)(B * 10), j - (int)(B * 10), i - (int)(B * 10), j - (int)(B * 10));
            }
        DeleteObject(hPen);

    }

}

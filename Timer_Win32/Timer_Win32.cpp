// Timer_Win32.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Timer_Win32.h"

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



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // hp time
    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);

    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
    ElapsedMicroseconds.QuadPart *= 1000000;
    ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
    msecond_counter = ElapsedMicroseconds.QuadPart;
    //end hp time
    
    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TIMERWIN32, szWindowClass, MAX_LOADSTRING);

    LoadStringW(hInstance, IDS_NO_INPUT_EN, sNoInput, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_INVALID_INPUT_EN, sInvalidInput, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TITLE_ERROR_EN, sTitleError, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_END_TIMER_EN, sEndTimer, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TITLE_TIMER_EN, sTitleTimer, MAX_LOADSTRING);

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

   HWND hWnd{};
   /* uncomment, in case you will want to ask user for changing language when the program runs */
   // DialogBox(hInst, MAKEINTRESOURCE(IDD_CHANGE_LANGUAGE), hWnd, Language_choosing);
   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
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
            case ID_LANGUAGE:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_CHANGE_LANGUAGE), hWnd, Language_choosing);
                break;
            case ID_TIMER_DEFAULT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_DEFAULT_TIMER), hWnd, Timer_default);
                break;
            case ID_TIMER_REVERSETIMER:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_REVERSE_TIMER), hWnd, Timer_reverse);
                break;
            case ID_TIMER_SYSTEM:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_SYSTEM_TIMER), hWnd, Timer_systemdependent);
                break;
            case ID_TIMER_STOPWATCH:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_STOPWATCH), hWnd, Stopwatch);
                break;
            case ID_CLOCK_MODERN:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_CLOCK_MODERN), hWnd, Clock_modern);
                break;
            case ID_CLOCK_OLD:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_CLOCK_OLD), hWnd, Clock_old);
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

// Функция окна "Смена языка"
INT_PTR CALLBACK Language_choosing(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    HINSTANCE hInstance{};
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        switch (wParam)
        {
        case IDCANCEL:
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
            break;
        case IDC_CHOICE_EN:
            // start
            // MesageBox strings
            LoadStringW(hInstance, IDS_NO_INPUT_EN, sNoInput, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_INVALID_INPUT_EN, sInvalidInput, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_ERROR_EN, sTitleError, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_END_TIMER_EN, sEndTimer, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_TIMER_EN, sTitleTimer, MAX_LOADSTRING);

            // Window titles strings ??? - where to paste, need a class?

            // Static text strings

            //end
            MessageBox(hDlg, (LPCWSTR)L"Language succesfully changed! Thanks for using our application!", (LPCWSTR)L"Application \"Timer\"", MB_ICONINFORMATION);
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
            break;
        case IDC_CHOICE_RU:
            LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
            LoadStringW(hInstance, IDC_TIMERWIN32, szWindowClass, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_NO_INPUT_RU, sNoInput, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_INVALID_INPUT_RU, sInvalidInput, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_ERROR_RU, sTitleError, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_END_TIMER_RU, sEndTimer, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_TIMER_RU, sTitleTimer, MAX_LOADSTRING);
            MessageBox(hDlg, (LPCWSTR)L"Язык успешно изменен! Спасибо, что пользуетесь нашим приложением!", (LPCWSTR)L"Приложение \"Таймер\"", MB_ICONINFORMATION);
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
            break;
        default:
            break;
        }

        break;
    case BN_CLICKED:
        break;
    }
    return (INT_PTR)FALSE;
}

// Функция окна "О программе", ничего не изменялось
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

// Функция окна "Обычного таймера". Отсчет идет вперед (от 0 до заданного времени)
INT_PTR CALLBACK Timer_default(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    int input_hour = 0;
    int input_minute = 0;
    int input_second = 0;

    bool continue_timer = true;

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
                        MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                        continue_timer = false;
                    }
                }
            }
            else if (input_minute > 60 || input_second > 59) {
                MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                continue_timer = false;
            }

            if (continue_timer == true) {
                
                SetDlgItemInt(hDlg, IDC_EDIT_HOUR1, 0, TRUE);
                SetDlgItemInt(hDlg, IDC_EDIT_MINUTE, 0, TRUE);
                SetDlgItemInt(hDlg, IDC_EDIT_SECOND, 0, TRUE);
            }
            else 
                KillTimer(hDlg, 1);

            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_STOP)
        {
            KillTimer(hDlg, 1);
            SetDlgItemInt(hDlg, IDC_EDIT_HOUR1, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_MINUTE, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SECOND, 0, TRUE);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_PAUSE)
        {
            KillTimer(hDlg, 1);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_CONTINUE)
        {
            SetTimer(hDlg, 1, 1000, NULL);
        }
            return (INT_PTR)TRUE;
        break;
    case WM_TIMER:
        if (LOWORD(wParam) == 1) {
            input_hour = GetDlgItemInt(hDlg, IDC_EDIT_HOUR_INPUT, NULL, TRUE);
            input_minute = GetDlgItemInt(hDlg, IDC_EDIT_MINUTE_INPUT, NULL, TRUE);
            input_second = GetDlgItemInt(hDlg, IDC_EDIT_SECOND_INPUT, NULL, TRUE);

            int edit_hour = GetDlgItemInt(hDlg, IDC_EDIT_HOUR1, NULL, TRUE);
            int edit_min = GetDlgItemInt(hDlg, IDC_EDIT_MINUTE, NULL, TRUE);
            int edit_sec = GetDlgItemInt(hDlg, IDC_EDIT_SECOND, NULL, TRUE);

            if (edit_hour == input_hour) {
                if (edit_min == input_minute) {
                    if (edit_sec == input_second) {
                        KillTimer(hDlg, 1);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, edit_hour, TRUE);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, edit_min, TRUE);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, edit_sec, TRUE);
                        MessageBox(GetActiveWindow(), sEndTimer, sTitleTimer, MB_ICONINFORMATION);
                    }
                }
            }
            else {
                if (edit_sec == 59) {
                    edit_min += 1;
                    edit_sec = -1;
                }
                if (edit_min == 60) {
                    edit_hour++;
                    edit_min = 0;
                    edit_sec = -1;
                }
            }

            edit_sec++;

            SetDlgItemInt(hDlg, IDC_EDIT_HOUR1, edit_hour, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_MINUTE, edit_min, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SECOND, edit_sec, TRUE);
            return (INT_PTR)TRUE;
        }
        break;
    case WM_DESTROY:
        KillTimer(hDlg, 1);
        break;
    default:
        break;
    }
    return (INT_PTR)FALSE;
}

// Функция окна "Обратного таймера". Отсчет идет от времени, которое задал пользователь, до 0
INT_PTR CALLBACK Timer_reverse(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    int input_hour;
    int input_minute;
    int input_second;

    bool continue_timer = true;

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
                        MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                        continue_timer = false;
                    }
                }
            }
            if (input_minute > 60 || input_second > 59) {
                MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                continue_timer = false;
            }

            if (continue_timer == true) {
                SetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, input_hour, TRUE);
                SetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, input_minute, TRUE);
                SetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, input_second, TRUE);
            }
            else 
                KillTimer(hDlg, 2);
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

            if (edit_hour == 0) {
                if (edit_min == 0) {
                    if (edit_sec == 0) {
                        KillTimer(hDlg, 2);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, edit_hour, TRUE);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, edit_min, TRUE);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, edit_sec, TRUE);
                        MessageBox(GetActiveWindow(), sEndTimer, sTitleTimer, MB_ICONINFORMATION);
                    }
                }
            }
            else {
                if (edit_sec == 0) {
                    if (edit_min != 0) {
                        edit_sec = 60;
                        edit_min--;
                    } 
                    else {
                        edit_hour--;
                        edit_sec = 60;
                        edit_min = 60;
                    }
                }
            }

            edit_sec--;

            SetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, edit_hour, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, edit_min, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, edit_sec, TRUE);
            return (INT_PTR)TRUE;
            }
    case WM_DESTROY:
        KillTimer(hDlg, 2);
        break;
    }
    return (INT_PTR)FALSE;
}

/*
Функция окна "Системного таймера".Пользователь задает точное время в часах, секундах, минутах, программа
ведет отсчет от текукщего времени до заданного пользователем. Есть возможность поставить отсчет более чем
на один день, добавлением числа в ячейку "День"
*/
INT_PTR CALLBACK Timer_systemdependent(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    int input_day = 0;
    int input_hour = 0;
    int input_minute = 0;
    int input_second = 0;

    SYSTEMTIME sys_time;
    int sys_hour = 0;
    int sys_minute = 0;
    int sys_second = 0;

    bool continue_timer = true;

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
        if (LOWORD(wParam) == IDC_S_START)
        {
            input_day = GetDlgItemInt(hDlg, IDC_EDIT_DAY_INPUT, NULL, TRUE);
            input_hour = GetDlgItemInt(hDlg, IDC_EDIT_HOUR_INPUT, NULL, TRUE);
            input_minute = GetDlgItemInt(hDlg, IDC_EDIT_MINUTE_INPUT, NULL, TRUE);
            input_second = GetDlgItemInt(hDlg, IDC_EDIT_SECOND_INPUT, NULL, TRUE);

            SetTimer(hDlg, 3, 100, NULL);

            GetLocalTime(&sys_time);

            sys_time.wHour = sys_time.wHour;
            sys_minute = sys_time.wMinute;
            sys_second = sys_time.wSecond;

            if (input_hour > 23 || input_minute > 60 || input_second > 59) {
                MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                continue_timer = false;
            }
            else {
                if (input_day == 0) {
                    if (input_hour == 0) {
                        if (input_minute == 0) {
                            if (input_second == 0) {
                                MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                                continue_timer = false;
                            }
                        }
                    }
                    else {
                        if (input_hour < sys_hour) {
                            MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                            continue_timer = false;
                            break;
                        }
                        if (input_hour == sys_hour) {
                            if (input_minute < sys_minute) {
                                MessageBox(GetActiveWindow(), sInvalidInput, sTitleError, MB_ICONERROR);
                                continue_timer = false;
                                break;
                            }
                            if (input_minute == sys_minute) {
                                if (input_second < sys_second) {
                                    MessageBox(GetActiveWindow(), sInvalidInput, sTitleError, MB_ICONERROR);
                                    continue_timer = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            if (continue_timer == true) {
                SetDlgItemInt(hDlg, IDC_EDIT_HOUR1, input_day, TRUE);
                SetDlgItemInt(hDlg, IDC_EDIT_HOUR1, sys_hour, TRUE);
                SetDlgItemInt(hDlg, IDC_EDIT_MINUTE, sys_minute, TRUE);
                SetDlgItemInt(hDlg, IDC_EDIT_SECOND, sys_second, TRUE);
            }
            else
                KillTimer(hDlg, 3);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_S_RESET)
        {
            KillTimer(hDlg, 3);
            SetDlgItemInt(hDlg, IDC_EDIT_HOUR1, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_MINUTE, 0, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SECOND, 0, TRUE);
            return (INT_PTR)TRUE;
        }

        break;
    case WM_TIMER:
        if (LOWORD(wParam) == 3) {
            input_day = GetDlgItemInt(hDlg, IDC_EDIT_DAY_INPUT, NULL, TRUE);
            input_hour = GetDlgItemInt(hDlg, IDC_EDIT_HOUR_INPUT, NULL, TRUE);
            input_minute = GetDlgItemInt(hDlg, IDC_EDIT_MINUTE_INPUT, NULL, TRUE);
            input_second = GetDlgItemInt(hDlg, IDC_EDIT_SECOND_INPUT, NULL, TRUE);
            int edit_day = GetDlgItemInt(hDlg, IDC_EDIT_DAY, NULL, TRUE);

            GetLocalTime(&sys_time);

            sys_hour = sys_time.wHour;
            sys_minute = sys_time.wMinute;
            sys_second = sys_time.wSecond;

            if (edit_day == 0) {
                if (sys_hour == input_hour) {
                    if (sys_minute == input_minute) {
                        if (sys_second == input_second) {
                            KillTimer(hDlg, 3);
                            MessageBox(GetActiveWindow(), sEndTimer, sTitleTimer, MB_ICONINFORMATION);
                            break;
                        }
                    }
                }
            }

            if (counter_day == true) {
                if (sys_hour == 0) {
                    if (sys_minute == 0) {
                        if (sys_second == 0) {
                            edit_day--;
                            counter_day = false;
                        }
                        if (sys_second == 1) {
                            counter_day = true;
                        }
                    }
                }
            }

            SetDlgItemInt(hDlg, IDC_EDIT_HOUR1, input_day, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_HOUR1, sys_hour, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_MINUTE, sys_minute, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SECOND, sys_second, TRUE);

            return (INT_PTR)TRUE;
        }

        break;
    case WM_DESTROY:
        KillTimer(hDlg, 3);
        break;
    default:
        break;
    }
    return (INT_PTR)FALSE;
}

// Функция окна "Секундомер"
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
            SetTimer(hDlg, 4, msecond_counter / 1000, NULL);
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
            if (edit_msec == 100) {
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
    case WM_DESTROY:
        KillTimer(hDlg, 4);
        break;
    default:
        break;
    }
    return (INT_PTR)FALSE;
}

// Функция окна "Новые часы". Имеет цифровое представление времени, без циферблата
INT_PTR CALLBACK Clock_modern(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    int hour, minute, second;
    int day_of_week, day, month, year;

    SYSTEMTIME sys_time;

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        SetTimer(hDlg, 5, 300, NULL);
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
        ConvertDayOfWeekToString(hDlg, IDC_EDIT_CLOCK_DAYOFWEEK, day_of_week);
        day = sys_time.wDay;
        month = sys_time.wMonth;
        ConvertMonthToString(hDlg, IDC_EDIT_CLOCK_MONTH, month);
        year = sys_time.wYear;

        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_HOUR, hour, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_MINUTE, minute, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_SECOND, second, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_DAY, sys_time.wDay, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_YEAR, sys_time.wYear, TRUE);

        break;
    case WM_DESTROY:
        KillTimer(hDlg, 5);
        break;
    }
    return (INT_PTR)FALSE;
}

// Функция окна "Старые часы". Имеет представление времени с помощью циферблата
INT_PTR CALLBACK Clock_old(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    SYSTEMTIME sys_time;
    GetLocalTime(&sys_time);

    RECT winCord;
    GetClientRect(hDlg, &winCord);
    int left = winCord.left;
    int right = winCord.right;
    int up = winCord.top;
    int bottom = winCord.bottom;

    int centerX = (right - left) / 2;
    int centerY = (bottom - up) / 2;

    RECT redraw_struct;
    redraw_struct.left = centerX - 110;
    redraw_struct.right = centerX + 110;
    redraw_struct.top = centerY + 110;
    redraw_struct.bottom = centerY - 110;


    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        SetTimer(hDlg, 6, 1000, NULL);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_O_DAY, sys_time.wDay, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_O_MONTH, sys_time.wMonth, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_O_YEAR, sys_time.wYear, TRUE);
        return (INT_PTR)TRUE;
        break;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    case WM_TIMER:
        ConvertDayOfWeekToString(hDlg, IDC_EDIT_CLOCK_O_DAYOFWEEK, sys_time.wDayOfWeek);

        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_O_DAY, sys_time.wDay, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_O_MONTH, sys_time.wMonth, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_O_YEAR, sys_time.wYear, TRUE);
        InvalidateRect(hDlg, &redraw_struct, TRUE);
        UpdateWindow(hDlg);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc_paint = BeginPaint(hDlg, &ps);

        HBRUSH hBrush;

        CreateStructureWatch(left, right, up, bottom, centerX, centerY, hdc_paint);
        DrawHourLine(left, right, up, bottom, centerX, centerY, sys_time.wHour, hdc_paint);
        DrawMinuteLine(left, right, up, bottom, centerX, centerY, sys_time.wMinute, hdc_paint);
        DrawSecondLine(left, right, up, bottom, centerX, centerY, sys_time.wSecond, hdc_paint);
        EndPaint(hDlg, &ps);
    }
        break;
    case WM_DESTROY:
        KillTimer(hDlg, 6);
        break;
    }
    return (INT_PTR)FALSE;
}

// func logic
/* 
Функция для конвертирования дня недели из числового в строчное представление. Использование:
Использование:
    HWND hDlg             A handle to the dialog box that contains the control.
    int nIDDlgItem        The identifier of the control whose title or text is to be retrieved.
    int day_of_week       Принимает день недели в числовом виде, которій будет конвертироваться
*/
void ConvertDayOfWeekToString(HWND hDlg, int nIDDlgItem, int day_of_week) {
    switch (day_of_week) {
    case 1:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Monday");
        break;
    case 2:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Tuesday");
        break;
    case 3:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Wednesday");
        break;
    case 4:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Thursday");
        break;
    case 5:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Friday");
        break;
    case 6:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Saturday");
        break;
    case 7:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Sunday");
        break;
    default:
        break;
    }
}

/* 
Функция для конвертирования месяца из числового в строчное представление. 
Использование:
    HWND hDlg             A handle to the dialog box that contains the control.
    int nIDDlgItem        The identifier of the control whose title or text is to be retrieved.
    int month             Принимает месяц в числовом виде, которій будет конвертироваться
*/
void ConvertMonthToString(HWND hDlg, int nIDDlgItem, int month) {
    switch (month) {
    case 1:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"January");
        break;
    case 2:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"February");
        break;
    case 3:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"March");
        break;
    case 4:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"April");
        break;
    case 5:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"May");
        break;
    case 6:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"June");
        break;
    case 7:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"July");
        break;
    case 8:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"August");
        break;
    case 9:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"September");
        break;
    case 10:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"October");
        break;
    case 11:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"November");
        break;
    case 12:
        SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"December");
        break;
    default:
        break;
    }
}

// func for static/dynamic painting structures
/*
Функция для рисования структуры ЧАСЫ.
Используется Функцией диалогового окна Clock_old
*/
void CreateStructureWatch(int left, int right, int up, int bottom, int centerX, int centerY, HDC hdc) {
    C(centerX - RADIUS_OUTER, centerY - RADIUS_OUTER, centerX + RADIUS_OUTER, centerY + RADIUS_OUTER, 0, 0, 0, 0, 4, black, current_dialog, hdc);

    int x = 0;
    int y = 0;
    int x_inner = 0;
    int y_inner = 0;

    double step = 6;
    double gMat = 0;
    double gPr = 6;
    double f = 0;
    int check_wighth = 30;
    for (int i = 1; i <= 60; i++) {
        gMat = 90 - gPr;
        f = M_PI / 180 * gMat;

        x = RADIUS_OUTER * cos(f) + centerX;
        y = -RADIUS_OUTER * sin(f) + centerY;
        x_inner = RADIUS_INNER * cos(f) + centerX;
        y_inner = -RADIUS_INNER * sin(f) + centerY;


        if (check_wighth == gPr) {
            L(x_inner, y_inner, x, y, 4, black, hdc);
            check_wighth += 30;
        }
        else
            L(x_inner, y_inner, x, y, 2, black, hdc);

        gPr += step;
    }
    // f - угол в радианах
    // g - угол в градусах Mat - matematicheskij, pr - programnij

}

/*
Функция для рисования часовой стрелки в структуре часы.
Используется Функцией диалогового окна Clock_old
*/
void DrawHourLine(int left, int right, int up, int bottom, int centerX, int centerY, int hour, HDC hdc) {
    if (hour == 0)
        hour = 12;
    else if (hour > 12)
        hour = hour - 12;

    int x = 0;
    int y = 0;

    double step = 30;
    double gMat = 0;
    double gPr = 30;
    double f = 0;
    for (int i = 1; i <= 12; i++) {
        if (i == hour) {
            gMat = 90 - gPr;
            f = M_PI / 180 * gMat;

            x = (RADIUS_INNER - 70) * cos(f) + centerX;
            y = (-RADIUS_INNER + 70) * sin(f) + centerY;
            L(centerX, centerY, x, y, 2, black, hdc);
        }
        gPr += step;
    }
}

/*
Функция для рисования минутной стрелки в структуре часы.
Используется Функцией диалогового окна Clock_old
*/
void DrawMinuteLine(int left, int right, int up, int bottom, int centerX, int centerY, int minute, HDC hdc) {
    if (minute == 0)
        minute = 60;

    int x = 0;
    int y = 0;

    double step = 6;
    double gMat = 0;
    double gPr = 6;
    double f = 0;
    for (int i = 1; i <= 60; i++) {
        if (i == minute) {
            gMat = 90 - gPr;
            f = M_PI / 180 * gMat;

            x = (RADIUS_INNER - 40) * cos(f) + centerX;
            y = (-RADIUS_INNER + 40) * sin(f) + centerY;
            L(centerX, centerY, x, y, 2, black, hdc);
        }
        gPr += step;
    }
}

/*
Функция для рисования минутной стрелки в структуре часы.
Используется Функцией диалогового окна Clock_old
*/
void DrawSecondLine(int left, int right, int up, int bottom, int centerX, int centerY, int second, HDC hdc) {
    if (second == 0)
        second = 60;

    int x = 0;
    int y = 0;

    double step = 6;
    double gMat = 0;
    double gPr = 6;
    double f = 0;
    for (int i = 1; i <= 60; i++) {
        if (i == second) {
            gMat = 90 - gPr;
            f = M_PI / 180 * gMat;

            x = (RADIUS_INNER - 44) * cos(f) + centerX;
            y = (-RADIUS_INNER + 44) * sin(f) + centerY;
            L(centerX, centerY, x, y, 1, black, hdc);
        }
        gPr += step;
    }
}

// func drawing
/* 
Функция для рисования линии от координат x1 и y1, до координат х2, y2
Использование:
int x1              Кордината х, линия рисуется от неё
int y1              Кордината у, линия рисуется от неё
int x2              Кордината х, линия рисуется до неё
int y2              Кордината у, линия рисуется до неё
int width           Толщина линии
COLORREF color      Цвет линии
HDC hdc             ---
*/
void L(int x1, int y1, int x2, int y2, int width, COLORREF color, HDC hdc)
{
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, width, color);
    SelectObject(hdc, hPen);
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    DeleteObject(hPen);
}

/*
Функция для рисования линии от текущих координат, до координат x2, y2
Использование :
int x2              Кордината х, линия рисуется до неё
int y2              Кордината у, линия рисуется до неё
int width           Толщина линии
COLORREF color      Цвет линии
HDC hdc             ---
*/
void LTO(int x2, int y2, int width, COLORREF color, HDC hdc)
{
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, width, color);
    SelectObject(hdc, hPen);
    LineTo(hdc, x2, y2);
    DeleteObject(hPen);
}

/*
Функция для рисования линии от текущих координат, до координат x2, y2
Использование :
int x1              Кордината х, левый нижний угол прямоугольнка
int y1              Кордината у, левый нижний угол прямоугольнка
int x2              Кордината х, правый верхний угол прямоугольнка
int y2              Кордината у, правый верхний угол прямоугольнка
int width           Толщина линии
COLORREF color      Цвет линии
HDC hdc             ---
*/
void R(int x1, int y1, int x2, int y2, int width, COLORREF color, HDC hdc)
{
    HPEN hPen;
    HBRUSH hBrush;
    hPen = CreatePen(PS_SOLID, width, color);
    SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(color);
    SelectObject(hdc, hBrush);
    Rectangle(hdc, x1, y1, x2, y2);
    DeleteObject(hPen);
    DeleteObject(hBrush);
}

/*
Функция для рисования линии от текущих координат, до координат x2, y2
Использование :
int x1              Кордината х, левый нижний угол прямоугольнка, описывающего круг
int y1              Кордината у, левый нижний угол прямоугольнка, описывающего круг
int x2              Кордината х, правый верхний угол прямоугольнка, описывающего круг
int y2              Кордината у, правый верхний угол прямоугольнка, описывающего круг
int х3              Кордината у, вырезанные фигуры ??? (не используется, шаблон)
int y3              Кордината у, вырезанные фигуры ??? (не используется, шаблон)
int х4              Кордината у, вырезанные фигуры ??? (не используется, шаблон)
int у4              Кордината у, вырезанные фигуры ??? (не используется, шаблон)
int width           Толщина линии
COLORREF color      Цвет линии
HDC hdc             ---
*/
void C(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int width, COLORREF color_pen, COLORREF color_brush, HDC hdc)
{
    HPEN hPen;
    HBRUSH hBrush;
    hPen = CreatePen(PS_SOLID, width, color_pen);
    SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(color_brush);
    SelectObject(hdc, hBrush);
    Chord(hdc, x1, y1, x2, y2, x3, y3, x4, y4);
    DeleteObject(hPen);
    DeleteObject(hBrush);
}
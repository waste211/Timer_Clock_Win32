// Timer_Win32.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Timer_Win32.h"

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
    LoadStringW(hInstance, IDS_APP_TITLE_EN, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TIMERWIN32, szWindowClass, MAX_LOADSTRING);
    // Titles
    LoadStringW(hInstance, IDS_TITLE_ABOUT_EN, sTitleAbout, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TITLE_CHOOSE_LANG_EN, sTitleChooseLang, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TITLE_ADD_EVENT_EN, sTitleAddEvent, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TITLE_CHOOSE_DAY_EN, sTitleChooseDay, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TITLE_TIMER_DEFAULT_EN, sTitleTimerDefault, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TITLE_TIMER_REVERSE_EN, sTitleTimerReverse, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TITLE_TIMER_SD_EN, sTitleTimerSD, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TITLE_STOPWATCH_EN, sTitleStopwatch, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TITLE_CLOCK_MODERN_EN, sTitleClockModern, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TITLE_CLOCK_OLD_EN, sTitleClockOld, MAX_LOADSTRING);
    // MesageBox strings
    LoadStringW(hInstance, IDS_NO_INPUT_EN, sNoInput, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_INVALID_INPUT_EN, sInvalidInput, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TITLE_ERROR_EN, sTitleError, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_END_TIMER_EN, sEndTimer, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TITLE_TIMER_EN, sTitleTimer, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_CHANGELANG_EN, sChangeLang, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_CHANGELANG_TITLE_EN, sChangeLangTitle, MAX_LOADSTRING);

    // Static text strings
    LoadStringW(hInstance, IDS_OUTPUT_EN, sOutput, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_INPUT_EN, sInput, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_DAY_OF_WEEK_EN, sDayOfWeek, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_MONTH_EN, sMonth, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_YEAR_EN, sYear, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_DAY_EN, sDay, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_HOUR_EN, sHour, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_MINUTE_EN, sMinute, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_SECOND_EN, sSecond, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_CHANGELANG_TEXT_EN, sChangeLangText, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_DESCRIBTION_TEXT_EN, sDescribtionText, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_DAY_CHOOSING_EN, sDayChoosing, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TIME_TEXT_EN, sTimeText, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_HOURS_BEGIN_EN, sHoursBegin, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_MINUTES_BEGIN_EN, sMinutesBegin, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_HOURS_END_EN, sHoursEnd, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_MINUTES_END_EN, sMinutesEnd, MAX_LOADSTRING);
    // Check-box text strings
    LoadStringW(hInstance, IDS_TEXT_ONMONDAY_EN, sOnMonday, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TEXT_ONTUESDAY_EN, sOnTuesday, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TEXT_ONWEDNESDAY_EN, sOnWednesday, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TEXT_ONTHURSDAY_EN, sOnThursday, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TEXT_ONFRIDAY_EN, sOnFriday, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TEXT_ONSATURDAY_EN, sOnSaturday, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_TEXT_ONSUNDAY_EN, sOnSunday, MAX_LOADSTRING);

    // Btn text strings
    LoadStringW(hInstance, IDS_START_EN, sStart, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_STOP_EN, sStop, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_PAUSE_EN, sPause, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_CONTINUE_EN, sContinue, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_RESET_EN, sReset, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_BTN_CHOOSE_DAY_EN, sChooseDayBtn, MAX_LOADSTRING);

    // menu strings
    LoadStringW(hInstance, IDS_MENU_FILE_EN, sMenuFile, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_MENU_HELP_EN, sMenuHelp, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_MENU_EVENT_EN, sMenuEvent, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_MENU_LANGUAGE_EN, sMenuLanguage, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_MENU_TIMER_EN, sMenuTimer, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_MENU_CLOCK_EN, sMenuClock, MAX_LOADSTRING);
    // submenu strings
    LoadStringW(hInstance, IDS_SUBMENU_EXIT_EN, sSubmenuExit, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_SUBMENU_ABOUT_EN, sSubmenuAbout, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_SUBMENU_LANGUAGE_EN, sSubmenuLanguage, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_SUBMENU_EVENT_SAVE_EN, sSubmenuEventSave, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_SUBMENU_EVENT_LOAD_EN, sSubmenuEventLoad, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_SUBMENU_EVENT_ADD_EN, sSubmenuEventAdd, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_SUBMENU_EVENT_DELETE_EN, sSubmenuEventDelete, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_SUBMENU_TIMER_DEFAULT_EN, sSubmenuTimerDefault, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_SUBMENU_TIMER_REVERSE_EN, sSubmenuTimerReverse, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_SUBMENU_TIMER_SD_EN, sSubmenuTimerSD, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_SUBMENU_STOPWATCH_EN, sSubmenuStopwatch, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_SUBMENU_CLOCK_OLD_EN, sSubmenuClockOld, MAX_LOADSTRING);
    LoadStringW(hInstance, IDS_SUBMENU_CLOCK_MODERN_EN, sSubmenuClockModern, MAX_LOADSTRING);

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

   /* uncomment, in case you will want to ask user for changing language when the program runs */
   // DialogBox(hInst, MAKEINTRESOURCE(IDD_CHANGE_LANGUAGE), hWnd, Language_choosing);
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   changeMenuElement(hWnd);
   if (!hWnd)
   {
       return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

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
    HINSTANCE hInstance{};
    switch (message)
    {
    case WM_CREATE:
    {
        temp.planStruct::helpUserInfoStructure(hWnd, hInstance);
        loadCurrentEventsFromFile();
        if (lastEvent != 0) {
            for (int i = 0; i <= lastEvent; i++) {
                events[i].posY = lastUp;
                events[i].planStruct::createStructure(hWnd, hInstance, events[i].posY, i);
                lastUp += structHeight + 10;
            }
        }
        break;
    }
    case WM_COMMAND:
        {
            int wmenuId = LOWORD(wParam);
            // Разобрать выбор меню таймеров, секундомеров, выбора языка, разных видов часов и т.д.
            switch (wmenuId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case ID_LANGUAGE:
            {
                DialogBox(hInst, MAKEINTRESOURCE(IDD_CHANGE_LANGUAGE), hWnd, Language_choosing);
                changeMenuElement(hWnd);
                break;
            }
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

            // Разобрать выбор меню, связанных с событиями и их обработкой (т.е. главным окном)
            case ID_EVENTS_SAVE:
            {
                saveCurrentEventsInFile();
                break;
            }
            case ID_EVENTS_LOAD:
            {
                // удаление визуальных событий
                if (lastEvent >= 0) {
                    for (int i = 0; i <= lastEvent; i++)
                        events[i].planStruct::deleteStructure(hWnd, hInstance, i);
                }
                loadCurrentEventsFromFile(); // если событий в файле меньше чем в текущем масиве, то ошибок это не вызывает
                lastUp = 60; // обнулются координаты
                for (int i = 0; i <= lastEvent && events[0].hEditDesc; i++) { // вывод событий на экран пользователя
                    events[i].planStruct::createStructure(hWnd, hInstance, lastUp, i);
                    lastUp += structHeight + 10;
                }
                break;
            }
            case ID_EVENTS_ADD:
            {
                if (lastEvent == 0 && lastEventIncrement == false)
                    lastEventIncrement = true;
                else 
                    lastEvent += 1;
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ADD_EVENT), hWnd, Add_event); // доработать функцию Add_event
                if (fillAndDrawStructure == true) {
                    events[lastEvent].posY = lastUp;
                    events[lastEvent].planStruct::createStructure(hWnd, hInstance, events[lastEvent].posY, lastEvent);
                    lastUp += structHeight + 10;
                }
                fillAndDrawStructure = true;
                break;
            }
            case ID_EVENTS_DELETE:
            {
                if (lastEvent >= 0) {
                    lastUp = lastUp - structHeight - 10;
                    events[lastEvent].planStruct::deleteStructure(hWnd, hInstance, lastEvent);
                    lastEvent -= 1;
                }
                else {
                    MessageBox(GetActiveWindow(), L"Nothing to delete", L"ERROR", MB_ICONERROR);
                }
                break;
            }
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
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
    {
        SetWindowText(hDlg, sTitleChooseLang);
        HWND text{};
        text = GetDlgItem(hDlg, IDC_STATIC);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sChangeLangText);
        return (INT_PTR)TRUE;
    }

    case WM_COMMAND:
        switch (wParam)
        {
        case IDCANCEL:
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
            break;
        case IDC_CHOICE_EN:
        {
            language_en = true;
            language_ru = false;

            // start
            // Titles
            LoadStringW(hInstance, IDS_TITLE_ABOUT_EN, sTitleAbout, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_CHOOSE_LANG_EN, sTitleChooseLang, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_ADD_EVENT_EN, sTitleAddEvent, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_CHOOSE_DAY_EN, sTitleChooseDay, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_TIMER_DEFAULT_EN, sTitleTimerDefault, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_TIMER_REVERSE_EN, sTitleTimerReverse, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_TIMER_SD_EN, sTitleTimerSD, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_STOPWATCH_EN, sTitleStopwatch, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_CLOCK_MODERN_EN, sTitleClockModern, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_CLOCK_OLD_EN, sTitleClockOld, MAX_LOADSTRING);
            // MesageBox strings
            LoadStringW(hInstance, IDS_NO_INPUT_EN, sNoInput, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_INVALID_INPUT_EN, sInvalidInput, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_ERROR_EN, sTitleError, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_END_TIMER_EN, sEndTimer, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_TIMER_EN, sTitleTimer, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_CHANGELANG_EN, sChangeLang, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_CHANGELANG_TITLE_EN, sChangeLangTitle, MAX_LOADSTRING);
            // Window titles strings ??? - where to paste, need a class?

            // Static text strings
            LoadStringW(hInstance, IDS_OUTPUT_EN, sOutput, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_INPUT_EN, sInput, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_DAY_OF_WEEK_EN, sDayOfWeek, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MONTH_EN, sMonth, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_YEAR_EN, sYear, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_DAY_EN, sDay, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_HOUR_EN, sHour, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MINUTE_EN, sMinute, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SECOND_EN, sSecond, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_CHANGELANG_TEXT_EN, sChangeLangText, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_DESCRIBTION_TEXT_EN, sDescribtionText, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_DAY_CHOOSING_EN, sDayChoosing, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TIME_TEXT_EN, sTimeText, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_HOURS_BEGIN_EN, sHoursBegin, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MINUTES_BEGIN_EN, sMinutesBegin, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_HOURS_END_EN, sHoursEnd, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MINUTES_END_EN, sMinutesEnd, MAX_LOADSTRING);
            // Check-box text strings
            LoadStringW(hInstance, IDS_TEXT_ONMONDAY_EN, sOnMonday, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TEXT_ONTUESDAY_EN, sOnTuesday, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TEXT_ONWEDNESDAY_EN, sOnWednesday, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TEXT_ONTHURSDAY_EN, sOnThursday, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TEXT_ONFRIDAY_EN, sOnFriday, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TEXT_ONSATURDAY_EN, sOnSaturday, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TEXT_ONSUNDAY_EN, sOnSunday, MAX_LOADSTRING);
            // Btn text strings
            LoadStringW(hInstance, IDS_START_EN, sStart, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_STOP_EN, sStop, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_PAUSE_EN, sPause, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_CONTINUE_EN, sContinue, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_RESET_EN, sReset, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_BTN_CHOOSE_DAY_EN, sChooseDayBtn, MAX_LOADSTRING);
            // menu strings
            LoadStringW(hInstance, IDS_MENU_FILE_EN, sMenuFile, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MENU_HELP_EN, sMenuHelp, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MENU_EVENT_EN, sMenuEvent, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MENU_LANGUAGE_EN, sMenuLanguage, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MENU_TIMER_EN, sMenuTimer, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MENU_CLOCK_EN, sMenuClock, MAX_LOADSTRING);
            // submenu strings
            LoadStringW(hInstance, IDS_SUBMENU_EXIT_EN, sSubmenuExit, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_ABOUT_EN, sSubmenuAbout, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_LANGUAGE_EN, sSubmenuLanguage, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_EVENT_SAVE_EN, sSubmenuEventSave, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_EVENT_LOAD_EN, sSubmenuEventLoad, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_EVENT_ADD_EN, sSubmenuEventAdd, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_EVENT_DELETE_EN, sSubmenuEventDelete, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_TIMER_DEFAULT_EN, sSubmenuTimerDefault, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_TIMER_REVERSE_EN, sSubmenuTimerReverse, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_TIMER_SD_EN, sSubmenuTimerSD, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_STOPWATCH_EN, sSubmenuStopwatch, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_CLOCK_OLD_EN, sSubmenuClockOld, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_CLOCK_MODERN_EN, sSubmenuClockModern, MAX_LOADSTRING);
            //end
            // Раскомментировать, чтобы появился MessageBox о смене языка
            // MessageBox(hDlg, (LPCWSTR)L"Language succesfully changed! Thanks for using our application!", (LPCWSTR)L"Application \"Timer\"", MB_ICONINFORMATION);
            EndDialog(hDlg, LOWORD(wParam));
        }
            return (INT_PTR)TRUE;
            break;
        case IDC_CHOICE_RU:
        {
            language_en = false;
            language_ru = true;

            // start
            // Titles
            LoadStringW(hInstance, IDS_TITLE_ABOUT_RU, sTitleAbout, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_CHOOSE_LANG_RU, sTitleChooseLang, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_ADD_EVENT_RU, sTitleAddEvent, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_CHOOSE_DAY_RU, sTitleChooseDay, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_TIMER_DEFAULT_RU, sTitleTimerDefault, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_TIMER_REVERSE_RU, sTitleTimerReverse, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_TIMER_SD_RU, sTitleTimerSD, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_STOPWATCH_RU, sTitleStopwatch, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_CLOCK_MODERN_RU, sTitleClockModern, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_CLOCK_OLD_RU, sTitleClockOld, MAX_LOADSTRING);
            // MesageBox strings
            LoadStringW(hInstance, IDS_NO_INPUT_RU, sNoInput, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_INVALID_INPUT_RU, sInvalidInput, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_ERROR_RU, sTitleError, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_END_TIMER_RU, sEndTimer, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TITLE_TIMER_RU, sTitleTimer, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_CHANGELANG_RU, sChangeLang, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_CHANGELANG_TITLE_RU, sChangeLangTitle, MAX_LOADSTRING);
            // Window titles strings ??? - where to paste, need a class?

            // Static text strings
            LoadStringW(hInstance, IDS_OUTPUT_RU, sOutput, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_INPUT_RU, sInput, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_DAY_OF_WEEK_RU, sDayOfWeek, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MONTH_RU, sMonth, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_YEAR_RU, sYear, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_DAY_RU, sDay, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_HOUR_RU, sHour, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MINUTE_RU, sMinute, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SECOND_RU, sSecond, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_CHANGELANG_TEXT_RU, sChangeLangText, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_DESCRIBTION_TEXT_RU, sDescribtionText, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_DAY_CHOOSING_RU, sDayChoosing, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TIME_TEXT_RU, sTimeText, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_HOURS_BEGIN_RU, sHoursBegin, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MINUTES_BEGIN_RU, sMinutesBegin, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_HOURS_END_RU, sHoursEnd, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MINUTES_END_RU, sMinutesEnd, MAX_LOADSTRING);
            // Check-box text strings
            LoadStringW(hInstance, IDS_TEXT_ONMONDAY_RU, sOnMonday, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TEXT_ONTUESDAY_RU, sOnTuesday, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TEXT_ONWEDNESDAY_RU, sOnWednesday, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TEXT_ONTHURSDAY_RU, sOnThursday, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TEXT_ONFRIDAY_RU, sOnFriday, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TEXT_ONSATURDAY_RU, sOnSaturday, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_TEXT_ONSUNDAY_RU, sOnSunday, MAX_LOADSTRING);
            // Btn text strings
            LoadStringW(hInstance, IDS_START_RU, sStart, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_STOP_RU, sStop, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_PAUSE_RU, sPause, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_CONTINUE_RU, sContinue, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_RESET_RU, sReset, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_BTN_CHOOSE_DAY_RU, sChooseDayBtn, MAX_LOADSTRING);
            // menu strings
            LoadStringW(hInstance, IDS_MENU_FILE_RU, sMenuFile, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MENU_HELP_RU, sMenuHelp, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MENU_EVENT_RU, sMenuEvent, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MENU_LANGUAGE_RU, sMenuLanguage, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MENU_TIMER_RU, sMenuTimer, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_MENU_CLOCK_RU, sMenuClock, MAX_LOADSTRING);
            // submenu strings
            LoadStringW(hInstance, IDS_SUBMENU_EXIT_RU, sSubmenuExit, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_ABOUT_RU, sSubmenuAbout, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_LANGUAGE_RU, sSubmenuLanguage, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_EVENT_SAVE_RU, sSubmenuEventSave, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_EVENT_LOAD_RU, sSubmenuEventLoad, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_EVENT_ADD_RU, sSubmenuEventAdd, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_EVENT_DELETE_RU, sSubmenuEventDelete, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_TIMER_DEFAULT_RU, sSubmenuTimerDefault, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_TIMER_REVERSE_RU, sSubmenuTimerReverse, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_TIMER_SD_RU, sSubmenuTimerSD, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_STOPWATCH_RU, sSubmenuStopwatch, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_CLOCK_OLD_RU, sSubmenuClockOld, MAX_LOADSTRING);
            LoadStringW(hInstance, IDS_SUBMENU_CLOCK_MODERN_RU, sSubmenuClockModern, MAX_LOADSTRING);

            // end
            // Раскомментировать, чтобы появился MessageBox о смене языка
            // MessageBox(hDlg, (LPCWSTR)L"Язык успешно изменен! Спасибо, что пользуетесь нашим приложением!", (LPCWSTR)L"Приложение \"Таймер\"", MB_ICONINFORMATION);
            EndDialog(hDlg, LOWORD(wParam));
        }
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
        SetWindowText(hDlg, sTitleAbout);
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

// Функция окна "Добавление события";
INT_PTR CALLBACK Add_event(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        SetWindowText(hDlg, sTitleAddEvent);

        HWND text{};
        text = GetDlgItem(hDlg, IDC_DESCRIBTION_TEXT);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sDescribtionText);
        text = GetDlgItem(hDlg, IDC_DAY_CHOOSING_TEXT);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sDayChoosing);
        text = GetDlgItem(hDlg, IDC_TIME_TEXT);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sTimeText);
        text = GetDlgItem(hDlg, IDC_HB);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sHoursBegin);
        text = GetDlgItem(hDlg, IDC_MB);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sMinutesBegin);
        text = GetDlgItem(hDlg, IDC_HE);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sHoursBegin);
        text = GetDlgItem(hDlg, IDC_ME);
        SendMessageW(text, WM_SETTEXT, 0, (LPARAM)sMinutesEnd);

        HWND btn{};
        btn = GetDlgItem(hDlg, IDC_CHOOSE_DAY);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sChooseDayBtn);
        return (INT_PTR)TRUE;
    }
    case WM_COMMAND:
    {
        if (LOWORD(wParam) == IDCANCEL)
        {
            fillAndDrawStructure = false;
            lastEventIncrement == false;
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_CHOOSE_DAY)
        {
            DialogBox(hInst, MAKEINTRESOURCE(IDD_CHOOSE_DAY), hDlg, Choose_day);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == ID_BTN_ADD)
        {
            GetDlgItemTextA(hDlg, IDC_EDIT_DESC, LPSTR(events[lastEvent].strDescribtion), 100000);
            events[lastEvent].hourBegin = GetDlgItemInt(hDlg, IDC_EDIT_HOURS_BEGIN, NULL, FALSE);
            events[lastEvent].minuteBegin = GetDlgItemInt(hDlg, IDC_EDIT_MINUTES_BEGIN, NULL, FALSE);
            events[lastEvent].hourEnd = GetDlgItemInt(hDlg, IDC_EDIT_HOURS_END, NULL, FALSE);
            events[lastEvent].minuteEnd = GetDlgItemInt(hDlg, IDC_EDIT_MINUTES_END, NULL, FALSE);
            EndDialog(hDlg, LOWORD(wParam));
            fillAndDrawStructure = true;
            lastEventIncrement = true;
            return (INT_PTR)TRUE;
        }
        return (INT_PTR)TRUE;
        break;
    }
    case WM_DESTROY:
        KillTimer(hDlg, 1);
        break;
    default:
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Choose_day(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        if (wasOpened == true) {
            DlgDaysOfWeekWasOpened(hDlg);
        }

        SetWindowText(hDlg, sTitleChooseDay);

        HWND CheckBox{};
        CheckBox = GetDlgItem(hDlg, IDC_ON_MONDAY);
        SendMessage(CheckBox, WM_SETTEXT, 0, (LPARAM)sOnMonday);
        CheckBox = GetDlgItem(hDlg, IDC_ON_TUESDAY);
        SendMessage(CheckBox, WM_SETTEXT, 0, (LPARAM)sOnTuesday);
        CheckBox = GetDlgItem(hDlg, IDC_ON_WEDNESDAY);
        SendMessage(CheckBox, WM_SETTEXT, 0, (LPARAM)sOnWednesday);
        CheckBox = GetDlgItem(hDlg, IDC_ON_THURSDAY);
        SendMessage(CheckBox, WM_SETTEXT, 0, (LPARAM)sOnThursday);
        CheckBox = GetDlgItem(hDlg, IDC_ON_FRIDAY);
        SendMessage(CheckBox, WM_SETTEXT, 0, (LPARAM)sOnFriday);
        CheckBox = GetDlgItem(hDlg, IDC_ON_SATURDAY);
        SendMessage(CheckBox, WM_SETTEXT, 0, (LPARAM)sOnSaturday);
        CheckBox = GetDlgItem(hDlg, IDC_ON_SUNDAY);
        SendMessage(CheckBox, WM_SETTEXT, 0, (LPARAM)sOnSunday);
        return (INT_PTR)TRUE;
    }
    case WM_COMMAND:
    {
        if (LOWORD(wParam) == IDCANCEL)
        {
            add_days = false;
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == ID_BTN_OK)
        {
            int countDays = FillEventsWithDaysOfWeek(hDlg);

            if (countDays == 7) {
                MessageBox(GetActiveWindow(), L"No days wew choosen", L"ERROR", MB_ICONERROR);
                add_days = false;
            }
            else {
                EndDialog(hDlg, LOWORD(wParam));
                wasOpened = true;
            }
            return (INT_PTR)TRUE;
        }
        return (INT_PTR)TRUE;
        break;
    }
    case WM_DESTROY:
        KillTimer(hDlg, 1);
        break;
    default:
        break;
    }
    return (INT_PTR)FALSE;
}

// Функция окна "Обычного таймера". Отсчет идет вперед (от 0 до заданного времени)
INT_PTR CALLBACK Timer_default(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    static int second_output = 0;
    static int minute_output = 0;
    static int hour_output = 0;
    static double temp = 0;
    static int input_hour = 0;
    static int input_minute = 0;
    static int input_second = 0;
    static bool continue_timer = true;
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        SetWindowText(hDlg, sTitleTimerDefault);

        HWND text{};
        text = GetDlgItem(hDlg, IDC_TEXT_INPUT);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sInput);
        text = GetDlgItem(hDlg, IDC_TEXT_OUTPUT);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sOutput);
        text = GetDlgItem(hDlg, IDC_TEXT_HOUR);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sHour);
        text = GetDlgItem(hDlg, IDC_TEXT_MINUTE);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sMinute);
        text = GetDlgItem(hDlg, IDC_TEXT_SECOND);
        SendMessageW(text, WM_SETTEXT, 0, (LPARAM)sSecond);

        HWND btn{};
        btn = GetDlgItem(hDlg, IDC_START);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sStart);
        btn = GetDlgItem(hDlg, IDC_STOP);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sStop);
        btn = GetDlgItem(hDlg, IDC_PAUSE);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sPause);
        btn = GetDlgItem(hDlg, IDC_CONTINUE);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sContinue);
        return (INT_PTR)TRUE;
    }
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
            QueryPerformanceCounter(&StartingTime);
            SetTimer(hDlg, 1, 100, NULL);

            if (input_hour == 0) {
                if (input_minute == 0) {
                    if (input_second == 0) {
                        KillTimer(hDlg, 1);
                        MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                        continue_timer = false;
                    }
                }
            }
            if (input_minute > 60 || input_second > 60 && continue_timer) {
                KillTimer(hDlg, 1);
                MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                continue_timer = false;
            }

            if (continue_timer == true) {
                
                SetDlgItemInt(hDlg, IDC_EDIT_HOUR1, 0, TRUE);
                SetDlgItemInt(hDlg, IDC_EDIT_MINUTE, 0, TRUE);
                SetDlgItemInt(hDlg, IDC_EDIT_SECOND, 0, TRUE);
            }

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
            SetTimer(hDlg, 1, 100, NULL);
        }
            return (INT_PTR)TRUE;
        break;
    case WM_TIMER:
        if (LOWORD(wParam) == 1) {
            input_hour = GetDlgItemInt(hDlg, IDC_EDIT_HOUR_INPUT, NULL, TRUE);
            input_minute = GetDlgItemInt(hDlg, IDC_EDIT_MINUTE_INPUT, NULL, TRUE);
            input_second = GetDlgItemInt(hDlg, IDC_EDIT_SECOND_INPUT, NULL, TRUE);

            hour_output = GetDlgItemInt(hDlg, IDC_EDIT_HOUR1, NULL, TRUE);
            minute_output = GetDlgItemInt(hDlg, IDC_EDIT_MINUTE, NULL, TRUE);
            second_output = GetDlgItemInt(hDlg, IDC_EDIT_SECOND, NULL, TRUE);

            QueryPerformanceCounter(&EndingTime);
            ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
            ElapsedMicroseconds.QuadPart *= 1000000;
            ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
            msecond_counter = ElapsedMicroseconds.QuadPart;
            temp = msecond_counter / 1000000;

            second_output = round(temp);
            minute_output = (second_output / 60) % 60;
            hour_output = second_output / 3600;
            second_output = second_output % 60;
            
            if (hour_output == input_hour)
                if (minute_output == input_minute) 
                    if (second_output == input_second) {
                        KillTimer(hDlg, 1);
                        SetDlgItemInt(hDlg, IDC_EDIT_HOUR1, hour_output, TRUE);
                        SetDlgItemInt(hDlg, IDC_EDIT_MINUTE, minute_output, TRUE);
                        SetDlgItemInt(hDlg, IDC_EDIT_SECOND, second_output, TRUE);
                        MessageBox(GetActiveWindow(), sEndTimer, sTitleTimer, MB_ICONINFORMATION);
                    }

            SetDlgItemInt(hDlg, IDC_EDIT_HOUR1, hour_output, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_MINUTE, minute_output, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SECOND, second_output, TRUE);
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
    static int second_output = 0;
    static int minute_output = 0;
    static int hour_output = 0;
    static double temp = 0;
    static int previous_sec = -1;
    static int input_hour = 0;
    static int input_minute = 0;
    static int input_second = 0;
    static bool continue_timer = true;

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        SetWindowText(hDlg, sTitleTimerReverse);

        HWND text{};
        text = GetDlgItem(hDlg, IDC_TEXT_INPUT);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sInput);
        text = GetDlgItem(hDlg, IDC_TEXT_OUTPUT);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sOutput);
        text = GetDlgItem(hDlg, IDC_TEXT_HOUR);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sHour);
        text = GetDlgItem(hDlg, IDC_TEXT_MINUTE);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sMinute);
        text = GetDlgItem(hDlg, IDC_TEXT_SECOND);
        SendMessageW(text, WM_SETTEXT, 0, (LPARAM)sSecond);

        HWND btn{};
        btn = GetDlgItem(hDlg, IDC_START);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sStart);
        btn = GetDlgItem(hDlg, IDC_STOP);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sStop);
        btn = GetDlgItem(hDlg, IDC_PAUSE);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sPause);
        btn = GetDlgItem(hDlg, IDC_CONTINUE);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sContinue);
        return (INT_PTR)TRUE;
    }
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
            QueryPerformanceCounter(&StartingTime);
            SetTimer(hDlg, 2, 100, NULL);
            if (input_hour == 0) {
                if (input_minute == 0) {
                    if (input_second == 0) {
                        KillTimer(hDlg, 2);
                        MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                        continue_timer = false;
                    }
                }
            }
            if (input_minute > 60 || input_second > 59) {
                KillTimer(hDlg, 2);
                MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                continue_timer = false;
            }

            if (continue_timer == true) {
                SetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, input_hour, TRUE);
                SetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, input_minute, TRUE);
                SetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, input_second, TRUE);
            }
            
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
            SetTimer(hDlg, 2, 100, NULL);
            return (INT_PTR)TRUE;
        }
        break;
    case WM_TIMER:
        if (LOWORD(wParam) == 2) {
            input_hour = GetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, NULL, TRUE);
            input_minute = GetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, NULL, TRUE);
            input_second = GetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, NULL, TRUE);

            QueryPerformanceCounter(&EndingTime);
            ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
            ElapsedMicroseconds.QuadPart *= 1000000;
            ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
            msecond_counter = ElapsedMicroseconds.QuadPart;
            temp = msecond_counter / 1000000;

            second_output = round(temp);
            second_output = second_output % 60;
            
            if (input_hour == 0) {
                if (input_minute == 0) {
                    if (input_second == 0) {
                        KillTimer(hDlg, 2);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, input_hour, TRUE);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, input_minute, TRUE);
                        SetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, input_second, TRUE);
                        MessageBox(GetActiveWindow(), sEndTimer, sTitleTimer, MB_ICONINFORMATION);
                    }
                }
            }
            
            if (second_output > previous_sec || second_output < previous_sec) {
                previous_sec = second_output;

                if (input_second == 0) {
                    if (input_minute != 0) {
                        input_second = 60;
                        input_minute -= 1;
                    }
                    else {
                        input_hour -= 1;
                        input_second = 60;
                        input_minute = 60;
                    }
                }
                    
                input_second -= 1;
            }

            SetDlgItemInt(hDlg, IDC_EDIT_R_HOUR1, input_hour, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_R_MINUTE, input_minute, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_R_SECOND, input_second, TRUE);
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

    int sys_hour = 0;
    int sys_minute = 0;
    int sys_second = 0;

    bool continue_timer = true;

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        SetWindowText(hDlg, sTitleTimerSD);

        HWND text{};
        text = GetDlgItem(hDlg, IDC_TEXT_INPUT);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sInput);
        text = GetDlgItem(hDlg, IDC_TEXT_OUTPUT);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sOutput);
        text = GetDlgItem(hDlg, IDC_TEXT_DAY);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sDay);
        text = GetDlgItem(hDlg, IDC_TEXT_HOUR);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sHour);
        text = GetDlgItem(hDlg, IDC_TEXT_MINUTE);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sMinute);
        text = GetDlgItem(hDlg, IDC_TEXT_SECOND);
        SendMessageW(text, WM_SETTEXT, 0, (LPARAM)sSecond);

        HWND btn{};
        btn = GetDlgItem(hDlg, IDC_S_START);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sStart);
        btn = GetDlgItem(hDlg, IDC_S_RESET);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sReset);
        return (INT_PTR)TRUE;
    }
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
                KillTimer(hDlg, 3);
                MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                continue_timer = false;
            }
            else {
                if (input_day == 0) {
                    if (input_hour == 0) {
                        if (input_minute == 0) {
                            if (input_second == 0) {
                                KillTimer(hDlg, 3);
                                MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                                continue_timer = false;
                            }
                        }
                    }
                    else {
                        if (input_hour < sys_hour) {
                            KillTimer(hDlg, 3);
                            MessageBox(GetActiveWindow(), sNoInput, sTitleError, MB_ICONERROR);
                            continue_timer = false;
                            break;
                        }
                        if (input_hour == sys_hour) {
                            if (input_minute < sys_minute) {
                                KillTimer(hDlg, 3);
                                MessageBox(GetActiveWindow(), sInvalidInput, sTitleError, MB_ICONERROR);
                                continue_timer = false;
                                break;
                            }
                            if (input_minute == sys_minute) {
                                if (input_second < sys_second) {
                                    KillTimer(hDlg, 3);
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
    static int msecond_output = 0;
    static int second_output = 0;
    static int minute_output = 0;
    static int hour_output = 0;
    static double temp = 0;
    static double temp2 = 0;
    static int input_hour = 0;
    static int input_minute = 0;
    static int input_second = 0;
    static bool continue_timer = true;

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        SetWindowText(hDlg, sTitleStopwatch);

        HWND text{};
        text = GetDlgItem(hDlg, IDC_TEXT_OUTPUT);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sOutput);

        HWND btn{};
        btn = GetDlgItem(hDlg, IDC_SW_START);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sStart);
        btn = GetDlgItem(hDlg, IDC_SW_STOP);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sStop);
        btn = GetDlgItem(hDlg, IDC_SW_PAUSE);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sPause);
        btn = GetDlgItem(hDlg, IDC_SW_CONTINUE);
        SendMessage(btn, WM_SETTEXT, 0, (LPARAM)sContinue);
        return (INT_PTR)TRUE;
    }
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
            input_hour = 0;
            input_minute = 0;
            input_second = 0;
            QueryPerformanceCounter(&StartingTime);
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
            int sec = 0;
            QueryPerformanceCounter(&EndingTime);
            ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
            ElapsedMicroseconds.QuadPart *= 1000000;
            ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
            msecond_counter = ElapsedMicroseconds.QuadPart;
            temp = msecond_counter / 100000;
            temp2 = msecond_counter / 1000000;
            msecond_output = round(temp);
            second_output = round(temp2);
            minute_output = (second_output / 60) % 60;
            hour_output = second_output / 3600;
            second_output %= 60;
            msecond_output %= 10;

            sec += 1;
            SetDlgItemInt(hDlg, IDC_EDIT_SW_HOUR, hour_output, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SW_MINUTE, minute_output, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SW_SECOND, second_output, TRUE);
            SetDlgItemInt(hDlg, IDC_EDIT_SW_MSECOND, msecond_output, TRUE);

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

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        SetTimer(hDlg, 5, 300, NULL);

        SetWindowText(hDlg, sTitleClockModern);

        HWND text{};
        text = GetDlgItem(hDlg, IDC_TEXT_DAY_OF_WEEK);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sDayOfWeek);
        text = GetDlgItem(hDlg, IDC_TEXT_MONTH);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sMonth);
        text = GetDlgItem(hDlg, IDC_TEXT_YEAR);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sYear);
        text = GetDlgItem(hDlg, IDC_TEXT_DAY);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sDay);
        text = GetDlgItem(hDlg, IDC_TEXT_HOUR);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sHour);
        text = GetDlgItem(hDlg, IDC_TEXT_MINUTE);
        SendMessageW(text, WM_SETTEXT, NULL, (LPARAM)sMinute);
        text = GetDlgItem(hDlg, IDC_TEXT_SECOND);
        SendMessageW(text, WM_SETTEXT, 0, (LPARAM)sSecond);

        GetLocalTime(&sys_time);

        hour = sys_time.wHour;
        minute = sys_time.wMinute;
        second = sys_time.wSecond;
        day_of_week = sys_time.wDayOfWeek;
        ConvertDayOfWeekToString(hDlg, IDC_EDIT_CLOCK_DAYOFWEEK, day_of_week, language_en, language_ru);
        day = sys_time.wDay;
        month = sys_time.wMonth;
        ConvertMonthToString(hDlg, IDC_EDIT_CLOCK_MONTH, month, language_en, language_ru);
        year = sys_time.wYear;

        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_HOUR, hour, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_MINUTE, minute, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_SECOND, second, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_DAY, sys_time.wDay, TRUE);
        SetDlgItemInt(hDlg, IDC_EDIT_CLOCK_YEAR, sys_time.wYear, TRUE);

        return (INT_PTR)TRUE;
    }
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
        ConvertDayOfWeekToString(hDlg, IDC_EDIT_CLOCK_DAYOFWEEK, day_of_week, language_en, language_ru);
        day = sys_time.wDay;
        month = sys_time.wMonth;
        ConvertMonthToString(hDlg, IDC_EDIT_CLOCK_MONTH, month, language_en, language_ru);
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
        SetWindowText(hDlg, sTitleClockOld);

        ConvertDayOfWeekToString(hDlg, IDC_EDIT_CLOCK_O_DAYOFWEEK, sys_time.wDayOfWeek, language_en, language_ru);
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
        ConvertDayOfWeekToString(hDlg, IDC_EDIT_CLOCK_O_DAYOFWEEK, sys_time.wDayOfWeek, language_en, language_ru);

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
    bool language_en      Определяет, какой язык используется в программе
    bool language_ru      Определяет, какой язык используется в программе 
*/
void ConvertDayOfWeekToString(HWND hDlg, int nIDDlgItem, int day_of_week, bool language_en, bool language_ru) {
    
    if (language_en == true) {
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
    else if (language_ru == true) {
        switch (day_of_week) {
        case 1:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Понедельник");
            break;
        case 2:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Вторник");
            break;
        case 3:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Среда");
            break;
        case 4:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Четверг");
            break;
        case 5:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Пятница");
            break;
        case 6:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Суббота");
            break;
        case 7:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Восресенье");
            break;
        default:
            break;
        }
    }
}

/* 
Функция для конвертирования месяца из числового в строчное представление. 
Использование:
    HWND hDlg             A handle to the dialog box that contains the control.
    int nIDDlgItem        The identifier of the control whose title or text is to be retrieved.
    int month             Принимает месяц в числовом виде, которій будет конвертироваться
    bool language_en      Определяет, какой язык используется в программе
    bool language_ru      Определяет, какой язык используется в программе
*/
void ConvertMonthToString(HWND hDlg, int nIDDlgItem, int month, bool language_en, bool language_ru) {
    if (language_en == true) {
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
    else if (language_ru == true) {
        switch (month) {
        case 1:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Январь");
            break;
        case 2:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Февраль");
            break;
        case 3:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Март");
            break;
        case 4:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Апрель");
            break;
        case 5:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Май");
            break;
        case 6:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Июнь");
            break;
        case 7:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Июль");
            break;
        case 8:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Август");
            break;
        case 9:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Сентяьрь");
            break;
        case 10:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Октябрь");
            break;
        case 11:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Ноябрь");
            break;
        case 12:
            SetDlgItemTextW(hDlg, nIDDlgItem, (LPCWSTR)L"Декабрь");
            break;
        default:
            break;
        }
    }
}

int FillEventsWithDaysOfWeek(HWND hDlg) {
    int countDays = 0;
    UINT isChecked;
    HWND CheckBox;
    CheckBox = GetDlgItem(hDlg, IDC_ON_MONDAY);
    isChecked = SendMessage(CheckBox, BM_GETCHECK, NULL, NULL);
    if (isChecked == BST_CHECKED)
        events[lastEvent].onMonday = true;
    else {
        events[lastEvent].onMonday = false;
        countDays++;
    }

    CheckBox = GetDlgItem(hDlg, IDC_ON_TUESDAY);
    isChecked = SendMessage(CheckBox, BM_GETCHECK, NULL, NULL);
    if (isChecked == BST_CHECKED)
        events[lastEvent].onTuesday = true;
    else {
        events[lastEvent].onTuesday = false;
        countDays++;
    }

    CheckBox = GetDlgItem(hDlg, IDC_ON_WEDNESDAY);
    isChecked = SendMessage(CheckBox, BM_GETCHECK, NULL, NULL);
    if (isChecked == BST_CHECKED)
        events[lastEvent].onWednesday = true;
    else {
        events[lastEvent].onWednesday = false;
        countDays++;
    }

    CheckBox = GetDlgItem(hDlg, IDC_ON_THURSDAY);
    isChecked = SendMessage(CheckBox, BM_GETCHECK, NULL, NULL);
    if (isChecked == BST_CHECKED)
        events[lastEvent].onThursday = true;
    else {
        events[lastEvent].onThursday = false;
        countDays++;
    }

    CheckBox = GetDlgItem(hDlg, IDC_ON_FRIDAY);
    isChecked = SendMessage(CheckBox, BM_GETCHECK, NULL, NULL);
    if (isChecked == BST_CHECKED)
        events[lastEvent].onFriday = true;
    else {
        events[lastEvent].onFriday = false;
        countDays++;
    }
    CheckBox = GetDlgItem(hDlg, IDC_ON_SATURDAY);
    isChecked = SendMessage(CheckBox, BM_GETCHECK, NULL, NULL);
    if (isChecked == BST_CHECKED)
        events[lastEvent].onSaturday = true;
    else {
        events[lastEvent].onSaturday = false;
        countDays++;
    }
    CheckBox = GetDlgItem(hDlg, IDC_ON_SUNDAY);
    isChecked = SendMessage(CheckBox, BM_GETCHECK, NULL, NULL);
    if (isChecked == BST_CHECKED)
        events[lastEvent].onSunday = true;
    else {
        events[lastEvent].onSunday = false;
        countDays++;
    }

    return countDays;
}

void DlgDaysOfWeekWasOpened(HWND hDlg) {
    HWND CheckBox{};
    if (events[lastEvent].onMonday) {
        CheckBox = GetDlgItem(hDlg, IDC_ON_MONDAY);
        SendMessage(CheckBox, BM_SETCHECK, 1, NULL);
    }
    if (events[lastEvent].onTuesday) {
        CheckBox = GetDlgItem(hDlg, IDC_ON_TUESDAY);
        SendMessage(CheckBox, BM_SETCHECK, 1, NULL);
    }
    if (events[lastEvent].onWednesday) {
        CheckBox = GetDlgItem(hDlg, IDC_ON_WEDNESDAY);
        SendMessage(CheckBox, BM_SETCHECK, 1, NULL);
    }
    if (events[lastEvent].onThursday) {
        CheckBox = GetDlgItem(hDlg, IDC_ON_THURSDAY);
        SendMessage(CheckBox, BM_SETCHECK, 1, NULL);
    }
    if (events[lastEvent].onFriday) {
        CheckBox = GetDlgItem(hDlg, IDC_ON_FRIDAY);
        SendMessage(CheckBox, BM_SETCHECK, 1, NULL);
    }
    if (events[lastEvent].onSaturday) {
        CheckBox = GetDlgItem(hDlg, IDC_ON_SATURDAY);
        SendMessage(CheckBox, BM_SETCHECK, 1, NULL);
    }
    if (events[lastEvent].onSunday) {
        CheckBox = GetDlgItem(hDlg, IDC_ON_SUNDAY);
        SendMessage(CheckBox, BM_SETCHECK, 1, NULL);
    }
}

/*
Функция для конвертирования числа в стоку wchar_t. Возвращает указатель на строку.
Использование:
    int num                 Число, которое необходимо конвертировать
*/
wchar_t *int_to_string(int num) {
    wchar_t strListNumber[256];
    swprintf_s(strListNumber, L"%d", num);
    // wprintf(L"%s\n", strListNumber);
    wchar_t* resultNumber = strListNumber;

    return resultNumber;
}

/*
Функция для конвертирования WCHAR* в строку const char*. Возвращает указатель на строку. 
Использование:
    WCHAR* string                 Строка, которую необходимо конвертировать
*/
// !!! ISN'T CURRENTLY IN USE !!!
const char* WCHAR_to_char(WCHAR* string) {
    _bstr_t bstrStr(string);
    const char* resultStr = bstrStr;

    return resultStr;
}

void changeMenuElement(HWND hWnd) {
    HMENU hmenu = GetMenu(hWnd);
    LPMENUITEMINFO LPmii = new MENUITEMINFO;
    UINT size_of_string = 10000;
    LPWSTR ItemText;
    // CHANGING MAIN MENU:
    // menu "File"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, 0, TRUE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sMenuFile);
    LPmii->fMask = MIIM_STRING;
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, 0, TRUE, LPmii);
    // menu "Help"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, 1, TRUE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sMenuHelp);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, 1, TRUE, LPmii);
    // menu "Language"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, 2, TRUE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sMenuEvent);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, 2, TRUE, LPmii);
    // menu "Timer"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, 3, TRUE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sMenuTimer);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, 3, TRUE, LPmii);
    // menu "Clock"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, 4, TRUE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sMenuClock);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, 4, TRUE, LPmii);

    // CHANGING SUBMENUES
    // sumbenu "Edit"
    // LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, IDM_EXIT, FALSE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sSubmenuExit);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, IDM_EXIT, FALSE, LPmii);
    // submenu "About"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, IDM_ABOUT, FALSE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sSubmenuAbout);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, IDM_ABOUT, FALSE, LPmii);
    // submenu "Choose Language"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, ID_LANGUAGE, FALSE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sSubmenuLanguage);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, ID_LANGUAGE, FALSE, LPmii);
    // submenu "Save current events"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, ID_EVENTS_SAVE, FALSE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sSubmenuEventSave);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, ID_EVENTS_SAVE, FALSE, LPmii);
    // submenu "Load events from save"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, ID_EVENTS_LOAD, FALSE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sSubmenuEventLoad);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, ID_EVENTS_LOAD, FALSE, LPmii);
    // submenu "Add new event" 
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, ID_EVENTS_ADD, FALSE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sSubmenuEventAdd);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, ID_EVENTS_ADD, FALSE, LPmii);
    // submenu "Delete event"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, ID_EVENTS_DELETE, FALSE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sSubmenuEventDelete);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, ID_EVENTS_DELETE, FALSE, LPmii);
    // submenu "Default timer"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, ID_TIMER_DEFAULT, FALSE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sSubmenuTimerDefault);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, ID_TIMER_DEFAULT, FALSE, LPmii);
    // submenu "Reverse timer"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, ID_TIMER_REVERSETIMER, FALSE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sSubmenuTimerReverse);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, ID_TIMER_REVERSETIMER, FALSE, LPmii);
    // submenu "System-dependent timer"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, ID_TIMER_SYSTEM, FALSE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sSubmenuTimerSD);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, ID_TIMER_SYSTEM, FALSE, LPmii);
    // submenu "Stopwatch timer"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, ID_TIMER_STOPWATCH, FALSE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sSubmenuStopwatch);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, ID_TIMER_STOPWATCH, FALSE, LPmii);
    // submenu "Clock modern"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, ID_CLOCK_MODERN, FALSE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sSubmenuClockModern);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, ID_CLOCK_MODERN, FALSE, LPmii);
    // submenu "Clock old"
    LPmii->cbSize = sizeof(*LPmii);
    GetMenuItemInfo(hmenu, ID_CLOCK_OLD, FALSE, LPmii);
    ItemText = new wchar_t[size_of_string];
    wcscpy_s(ItemText, size_of_string, sSubmenuClockOld);
    LPmii->dwTypeData = ItemText;
    LPmii->cch = size_of_string;
    SetMenuItemInfo(hmenu, ID_CLOCK_OLD, FALSE, LPmii);
    DrawMenuBar(hWnd);
}

// Функция сортировки событий по дням недели и по времени
void sortEventsByDay() {
    GetLocalTime(&sys_time);
    int currentDay = sys_time.wDayOfWeek;

    int indexMonday = 0;
    int indexTuesday = 0;
    int indexWednesday = 0;
    int indexThursday = 0;
    int indexFriday = 0;
    int indexSaturday = 0;
    int indexSunday = 0;
    for (int i = 0; i <= lastEvent; i++) {
        // считываем количесво событий, которые произошли в каждый из дней недели (с дублированием)
        if (events[i].onMonday) {
            eventsIndex[0][indexMonday] = i;
            indexMonday += 1;
        }
        if (events[i].onTuesday) {
            eventsIndex[0][indexTuesday] = i;
            indexTuesday += 1;
        }
        if (events[i].onWednesday) {
            eventsIndex[0][indexWednesday] = i;
            indexWednesday += 1;
        }
        if (events[i].onThursday) {
            eventsIndex[0][indexThursday] = i;
            indexThursday += 1;
        }
        if (events[i].onFriday) {
            eventsIndex[0][indexFriday] = i;
            indexFriday += 1;
        }
        if (events[i].onSaturday) {
            eventsIndex[0][indexSaturday] = i;
            indexSaturday += 1;
        }
        if (events[i].onSunday) {
            eventsIndex[0][indexSunday] = i;
            indexSunday += 1;
        }
    }

    int temp = 0;
    int day = 0;
    while (day <= 6) { // прогоняем через каждый из дней недели - первый индекс массива eventsIndex
        for (int j = 0; j <= MAX_EVENTS && (events[j].hEditDesc); j++) { // (events[i].hEditDesc) - фактическая проверка на заполнение элемента события
            if (events[j].hourBegin == events[j + 1].hourBegin) {
                if (events[j].minuteBegin > events[j + 1].minuteBegin) {
                    temp = eventsIndex[day][j];
                    eventsIndex[day][j] = eventsIndex[day][j + 1];
                    eventsIndex[day][j + 1] = temp;
                }
            }
            else if (events[j].hourBegin > events[j + 1].hourBegin) {
                temp = eventsIndex[day][j];
                eventsIndex[day][j] = eventsIndex[day][j + 1];
                eventsIndex[day][j + 1] = temp;
            }
        }
        day += 1;
    }    
}

/*
Функция для записи текущих ивентов в файл(которые создал пользователь)
Функция не принимает значений, использует глобальные переменные
TODO: Добавление названия файла в будущем
*/
void saveCurrentEventsInFile() {
    FILE* file;
    errno_t err;
    err = fopen_s(&file, "currentLayoutEvents.bin", "wb");
    if (file == NULL)
    {
        MessageBox(GetActiveWindow(), L"Save file does not exist", L"ERROR", MB_ICONERROR);
    }
    else {
        fwrite(&lastEvent, sizeof(int), 1, file);

        for (int i = 0; i <= lastEvent; i++) {
            int size1 = wcslen(events[i].strDescribtion);
            fwrite(&size1, sizeof(int), 1, file);
            fwrite(events[i].strDescribtion, sizeof(char), size1, file);
            fwrite(&events[i].onMonday, sizeof(events[i].onMonday), 1, file);
            fwrite(&events[i].onTuesday, sizeof(events[i].onTuesday), 1, file);
            fwrite(&events[i].onWednesday, sizeof(events[i].onWednesday), 1, file);
            fwrite(&events[i].onThursday, sizeof(events[i].onThursday), 1, file);
            fwrite(&events[i].onFriday, sizeof(events[i].onFriday), 1, file);
            fwrite(&events[i].onSaturday, sizeof(events[i].onSaturday), 1, file);
            fwrite(&events[i].onSunday, sizeof(events[i].onSunday), 1, file);
            fwrite(&events[i].hourBegin, sizeof(events[i].hourBegin), 1, file);
            fwrite(&events[i].minuteBegin, sizeof(events[i].minuteBegin), 1, file);
            fwrite(&events[i].hourEnd, sizeof(events[i].hourEnd), 1, file);
            fwrite(&events[i].minuteEnd, sizeof(events[i].minuteEnd), 1, file);
        }
       fclose(file);
    }
}

/*
Функция для записи текущих ивентов в массив структур "events" (чтобы впоследствии передать в окно пользователю)
Функция не принимает значений, использует глобальные переменные
*/
void loadCurrentEventsFromFile() {
    FILE* file;
    errno_t err;
    err = fopen_s(&file, "currentLayoutEvents.bin", "rb");
    if (file == NULL)
    {
        MessageBox(GetActiveWindow(), L"Save file does not exist", L"ERROR", MB_ICONERROR);
    }
    else {
        fread(&lastEvent, sizeof(int), 1, file);

        int temp = 0;
        for (int i = 0; i < lastEvent; i++)
        {
            fread(&temp, 4, 1, file);
            fread(events[i].strDescribtion, 1, temp, file);
            fread(&events[i].onMonday, sizeof(events[i].onMonday), 1, file);
            fread(&events[i].onTuesday, sizeof(events[i].onTuesday), 1, file);
            fread(&events[i].onWednesday, sizeof(events[i].onWednesday), 1, file);
            fread(&events[i].onThursday, sizeof(events[i].onThursday), 1, file);
            fread(&events[i].onFriday, sizeof(events[i].onFriday), 1, file);
            fread(&events[i].onSaturday, sizeof(events[i].onSaturday), 1, file);
            fread(&events[i].onSunday, sizeof(events[i].onSunday), 1, file);
            fread(&events[i].hourBegin, sizeof(events[i].hourBegin), 1, file);
            fread(&events[i].minuteBegin, sizeof(events[i].minuteBegin), 1, file);
            fread(&events[i].hourEnd, sizeof(events[i].hourEnd), 1, file);
            fread(&events[i].minuteEnd, sizeof(events[i].minuteEnd), 1, file);
        }
        fclose(file);
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
Функция для создания структуры из edit и static, которые будут использоваться в качетсве подсказки пользователю.
*/
void planStruct::helpUserInfoStructure(HWND hWnd, HINSTANCE hInstance) {
    int up = 5;
    int left = 5;
    HFONT hf = CreateFont(-16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, FF_ROMAN, TEXT("Times New Roman"));

    HWND hTextDesc{};
    HWND hTextDays{};
    HWND hTextTimeHourBegin{};
    HWND hTextTimeMinBegin{};
    HWND hTextTimeHourEnd{};
    HWND hTextTimeMinEnd{};

    hTextDesc = CreateWindowW(L"STATIC", NULL, WS_GROUP | WS_CHILD | WS_VISIBLE, left, up, structWidghtDesc, structHeight, hWnd, NULL, hInstance, NULL);
    left += structWidghtDesc + 30;
    hTextDays = CreateWindowW(L"STATIC", NULL, WS_GROUP | WS_CHILD | WS_VISIBLE, left, up, structWidghtDayOfWeek, structHeight, hWnd, NULL, hInstance, NULL);
    left += structWidghtDayOfWeek + 30;
    hTextTimeHourBegin = CreateWindowW(L"STATIC", NULL, WS_TABSTOP | WS_CHILD | WS_VISIBLE, left, up, structWidghtTimeHour, helpHeight, hWnd, NULL, hInstance, NULL);
    left += structWidghtTimeHour + 2;
    hTextTimeMinBegin = CreateWindowW(L"STATIC", NULL, WS_TABSTOP | WS_CHILD | WS_VISIBLE, left, up, structWidghtTimeMin, helpHeight, hWnd, NULL, hInstance, NULL);
    left += structWidghtTimeHour + 15;
    hTextTimeHourEnd = CreateWindowW(L"STATIC", NULL, WS_TABSTOP | WS_CHILD | WS_VISIBLE, left, up, structWidghtTimeMin, helpHeight, hWnd, NULL, hInstance, NULL);
    left += structWidghtTimeHour + 2;
    hTextTimeMinEnd = CreateWindowW(L"STATIC", NULL, WS_TABSTOP | WS_CHILD | WS_VISIBLE, left, up, structWidghtTimeMin, helpHeight, hWnd, NULL, hInstance, NULL);

    SendMessageW(hTextDesc, WM_SETFONT, (WPARAM)hf, 0);
    SetWindowTextA(hTextDesc, "Event describtion");
    SendMessageW(hTextDays, WM_SETFONT, (WPARAM)hf, 0);
    SetWindowTextA(hTextDays, "Days");
    SendMessageW(hTextTimeHourBegin, WM_SETFONT, (WPARAM)hf, 0);
    SetWindowTextA(hTextTimeHourBegin, "Start hour");
    SendMessageW(hTextTimeMinBegin, WM_SETFONT, (WPARAM)hf, 0);
    SetWindowTextA(hTextTimeMinBegin, "Start min");
    SendMessageW(hTextTimeHourEnd, WM_SETFONT, (WPARAM)hf, 0);
    SetWindowTextA(hTextTimeHourEnd, "End hour");
    SendMessageW(hTextTimeMinEnd, WM_SETFONT, (WPARAM)hf, 0);
    SetWindowTextA(hTextTimeMinEnd, "End min");
}

/*
Функция для создания структуры из edit и static, которые будут заполняться пользователем.
*/
void planStruct::createStructure(HWND hWnd, HINSTANCE hInstance, int up, int lastEvent) {
    HFONT hf = CreateFont(-16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, FF_ROMAN, TEXT("Times New Roman"));
    int left = 5;

    events[lastEvent].hEditDesc = CreateWindowW(L"EDIT", NULL, WS_GROUP | WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL, left, up, structWidghtDesc, structHeight, hWnd, NULL, hInstance, NULL);
    left += structWidghtDesc + 30;
    events[lastEvent].hEditDays = CreateWindowW(L"EDIT", NULL, WS_GROUP | WS_BORDER | WS_CHILD | WS_VISIBLE, left, up, structWidghtDayOfWeek, structHeight, hWnd, NULL, hInstance, NULL);
    left += structWidghtDayOfWeek + 30;
    events[lastEvent].hEditTimeHourBegin = CreateWindowW(L"EDIT", NULL, WS_TABSTOP | WS_BORDER | WS_CHILD | WS_VISIBLE, left, up, structWidghtTimeHour, structHeight, hWnd, NULL, hInstance, NULL);
    left += structWidghtTimeHour + 2;
    events[lastEvent].hEditTimeMinBegin = CreateWindowW(L"EDIT", NULL, WS_TABSTOP | WS_BORDER | WS_CHILD | WS_VISIBLE, left, up, structWidghtTimeMin, structHeight, hWnd, NULL, hInstance, NULL);
    left += structWidghtTimeHour + 15;
    events[lastEvent].hEditTimeHourEnd = CreateWindowW(L"EDIT", NULL, WS_TABSTOP | WS_BORDER | WS_CHILD | WS_VISIBLE, left, up, structWidghtTimeMin, structHeight, hWnd, NULL, hInstance, NULL);
    left += structWidghtTimeHour + 2;
    events[lastEvent].hEditTimeMinEnd = CreateWindowW(L"EDIT", NULL, WS_TABSTOP | WS_BORDER | WS_CHILD | WS_VISIBLE, left, up, structWidghtTimeMin, structHeight, hWnd, NULL, hInstance, NULL);

    // wchar_t* days = int_to_string(events[lastEvent].days);
    wchar_t* hourBegin = int_to_string(events[lastEvent].hourBegin);
    wchar_t* minuteBegin = int_to_string(events[lastEvent].minuteBegin);
    wchar_t* hourEnd = int_to_string(events[lastEvent].hourEnd);
    wchar_t* minuteEnd = int_to_string(events[lastEvent].minuteEnd);

    SendMessageW(events[lastEvent].hEditDesc, WM_SETFONT, (WPARAM)hf, 0);
    SetWindowTextW(events[lastEvent].hEditDesc, LPCWSTR(events[lastEvent].strDescribtion));
    // SetWindowTextA();
    // SetWindowText();
    SendMessageW(events[lastEvent].hEditDays, WM_SETFONT, (WPARAM)hf, 0);
    //SetWindowTextW(events[lastEvent].hEditDays, LPCWSTR(days));
    SendMessageW(events[lastEvent].hEditTimeHourBegin, WM_SETFONT, (WPARAM)hf, 0); // меняется шрифт для EDIT
    SetWindowTextW(events[lastEvent].hEditTimeHourBegin, LPWSTR(hourBegin)); // EDIT заполняется информацией
    SendMessageW(events[lastEvent].hEditTimeMinBegin, WM_SETFONT, (WPARAM)hf, 0);
    SetWindowTextW(events[lastEvent].hEditTimeMinBegin, LPWSTR(minuteBegin));
    SendMessageW(events[lastEvent].hEditTimeHourEnd, WM_SETFONT, (WPARAM)hf, 0);
    SetWindowTextW(events[lastEvent].hEditTimeHourEnd, LPWSTR(hourEnd));
    SendMessageW(events[lastEvent].hEditTimeMinEnd, WM_SETFONT, (WPARAM)hf, 0);
    SetWindowTextW(events[lastEvent].hEditTimeMinEnd, LPWSTR(minuteEnd));
}

/*
Функция для удаления структуры из edit и static.
*/
void planStruct::deleteStructure(HWND hWnd, HINSTANCE hInstance, int element) {
    HWND hDeleted{};
    DestroyWindow(events[element].hEditDesc);
    events[element].hEditDesc = hDeleted;
    DestroyWindow(events[element].hEditDays);
    events[element].hEditDays = hDeleted;
    DestroyWindow(events[element].hEditTimeHourBegin);
    events[element].hEditTimeHourBegin = hDeleted;
    DestroyWindow(events[element].hEditTimeMinBegin);
    events[element].hEditTimeMinBegin = hDeleted;
    DestroyWindow(events[element].hEditTimeHourEnd);
    events[element].hEditTimeHourEnd = hDeleted;
    DestroyWindow(events[element].hEditTimeMinEnd);
    events[element].hEditTimeMinEnd = hDeleted;
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

//                                              :::ISSUES:::
/*
*           checkbox - how to use BM_GETCHECK in dialog windows
*           literation error in main window while writing/reading information from controls
*           problem with days organization:
*                   working with drop-out windows/comboboxes -- what's better and how to work with them
*           writing boolean variables in file
*           sorting out elements in an events[] array by days of week (monday, tuesday, etc.)
*/

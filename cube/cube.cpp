// cube.cpp: Определяет точку входа для приложения.
//
#include "libs.hpp"
#include "resource.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CUBE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CUBE));

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
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CUBE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CUBE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

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
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне.
//
//  WM_COMMAND — обработать меню приложения
//  WM_PAINT — отрисовать главное окно
//  WM_DESTROY — отправить сообщение о выходе и вернуться
//
//
SHORT TimeX = 0, TimeY = 0;
SHORT MouseX = 0, MouseY = 0;
Cuboid cube;
bool MouseDown = false;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    
    RECT rt;
    
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
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    
    case WM_MOUSEMOVE:
        TimeX = MouseX;
        TimeY = MouseY;
        MouseX = LOWORD(lParam);
        MouseY = HIWORD(lParam);
        if (MouseDown) {
            cube.RotateCube(MouseX, MouseY, TimeX, TimeY);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    case WM_LBUTTONDOWN:
        MouseDown = true;
        break;
    case WM_LBUTTONUP:
        MouseDown = false;
        break;
    case WM_RBUTTONUP:
        ReleaseCapture();
        break;
    case WM_KEYUP:
        if (wParam == 0x57)
            cube.SetScale(0.1, true);
        if (wParam == 0x53)
            cube.SetScale(0.1, false);
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_PAINT:
        {
        try
        {
            GetClientRect(hWnd, &rt);
            hdc = BeginPaint(hWnd, &ps);

            HPEN hPen; //Объявляется кисть
            hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 255)); //Создаётся объект
            SelectObject(hdc, hPen); //Объект делается текущим

            Rectangle(hdc, 10, 10, rt.right - 10, rt.bottom - 10);
            char buf[80];
            TextOut(hdc, 10, 10, (LPCSTR)buf, wsprintf((LPSTR)buf, "X position :  %5d", MouseX));
            TextOut(hdc, 10, 30, (LPCSTR)buf, wsprintf((LPSTR)buf, "Y position :  %5d", MouseY));
            TextOut(hdc, 10, 50, (LPCSTR)buf, wsprintf((LPSTR)buf, "FLU X: %i", (int)cube.getCP().getX()));
            TextOut(hdc, 10, 70, (LPCSTR)buf, wsprintf((LPSTR)buf, "FLU Y: %i", (int)cube.getCP().getY()));
            TextOut(hdc, 10, 90, (LPCSTR)buf, wsprintf((LPSTR)buf, "FLU Z: %i", (int)cube.getCP().getZ()));
            TextOut(hdc, 10, 110, (LPCSTR)buf, wsprintf((LPSTR)buf, "Angle: %i", (int)cube.getAngle()));
            TextOut(hdc, 10, 130, (LPCSTR)buf, wsprintf((LPSTR)buf, "Scale: %f", (float)cube.GetScale()));
            cube.DrawCube(hWnd, hdc, rt);


            EndPaint(hWnd, &ps);
        }
        catch (const std::exception& ex)
        {
            MessageBox(hWnd, (LPCSTR)ex.what(), NULL, NULL);
        }
            
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
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

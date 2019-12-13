#include <windows.h>
LRESULT CALLBACK MyWndProc(HWND, UINT, WPARAM, LPARAM);
HDC hdc;
RECT rt;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    HWND hWnd;
    MSG msg;
    WNDCLASS wc;
    LPCSTR lpszAppName="CTemplate1";
    BOOL ret;
    //ИНИЦИАЛИЗАЦИЯ КЛАССА ОКНА
    wc.lpszClassName = lpszAppName;//Имя класса окна
    wc.hInstance=hInstance;//дескриптор экземпляра приложения
    wc.lpfnWndProc = (WNDPROC)MyWndProc;//указатель на процедуру окна
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);//вид курсора над окном
    wc.hIcon = 0;
    //LoadIcon(hInstance, (LPCTR)IDI_CTEMPLATE);//идентификатор пиктограммы
    wc.lpszMenuName = 0;// идентификатор ресурса меню
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);//цвет закраски окна
    wc.style=CS_HREDRAW|CS_VREDRAW;//стиль окна
    wc.cbClsExtra=0;//рудимент, инициализируется нулём
    if(!RegisterClass(&wc))//Регистрация класса окна
        return 0;
    hWnd=CreateWindow(lpszAppName, //имя класса окна
            lpszAppName,// имя окна
            WS_OVERLAPPEDWINDOW, //Стиль окна(перекрывающееся окно)
            100, //CW_USEDEFAULT,x-коорд. верхнего-левого угла
            100, //y- коорд. верхнего-левого угла
            400, //CW_USEDEFAULT, ширина
            200, //высота
            NULL, //дескриптор родительского окна
            NULL, //дескриптор меню
            hInstance, //дескриптор экземпляра приложения
            NULL);//указатель на структуру, содержащую дополнительные параметры окна
            ret=RegisterHotKey(hWnd,0xB001,MOD_CONTROL | MOD_ALT, 'W');
            ShowWindow(hWnd,SW_HIDE);//SW_SHOW... способ представления окна
            UpdateWindow(hWnd);//прорисовывает клиентскую область окна, генерирует сообщение WM_PAINT
            while(GetMessage(&msg, NULL,0,0)){//Извлечение сообщения из очереди сообщений
                TranslateMessage(&msg);//трансляция сообщений выиртуальных ключей WM_KEYDOWN, WM_KEYDOWN, WM_KEYUP и т.п.
                //в сообщение символа WM_CHAR
                DispatchMessage(&msg);//направляет сообщения оконной процедуре
                 }
            return msg.wParam;
}
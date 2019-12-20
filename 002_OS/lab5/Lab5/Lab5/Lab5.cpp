#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <math.h>

static TCHAR szWindowClass[] = _T("win32app");
static TCHAR szTitle[] = _T("Calculator");

TCHAR buf[256];
int nFunc = 0, nNew = 1;
double dTotal = 0;
HINSTANCE hInst;
static HWND hEdit;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(182, 182, 182));
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = NULL;

	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("Win32 Guided Tour"), 0);
		return 1;
	}

	hInst = hInstance;
	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect);
	int x = screen_rect.right / 2 - 200;
	int y = screen_rect.bottom / 2 - 300;

	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_POPUP, x, y, 390, 635, NULL, NULL, hInstance, NULL);
	if (!hWnd) {
		MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("Win32 Guided Tour"), 0);
		return 1;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

#define ID_BUTTON_PERSENT  1
#define ID_BUTTON_SQRT  2
#define ID_BUTTON_EXP  3
#define ID_BUTTON_DIV1X  4
#define ID_BUTTON_CE  5
#define ID_BUTTON_C  6
#define ID_BUTTON_BACK  7
#define ID_BUTTON_DIV  8
#define ID_BUTTON_7  9
#define ID_BUTTON_8 10
#define ID_BUTTON_9 11
#define ID_BUTTON_MUL 12
#define ID_BUTTON_4 13
#define ID_BUTTON_5 14
#define ID_BUTTON_6 15
#define ID_BUTTON_SUB 16
#define ID_BUTTON_1 17
#define ID_BUTTON_2 18
#define ID_BUTTON_3 19
#define ID_BUTTON_ADD 20
#define ID_BUTTON_ADDSUB  21
#define ID_BUTTON_ZERO  22
#define ID_BUTTON_POINT  23
#define ID_BUTTON_EQUALLY  24
#define ID_BUTTON_CLOSE 25
#define ID_EDIT 26
#define ID_STATIC 27

extern COLORREF clrs[]
{
	RGB(212, 212, 212), RGB(212, 212, 212), RGB(212, 212, 212), RGB(212, 212, 212),
	RGB(212, 212, 212), RGB(212, 212, 212), RGB(212, 212, 212), RGB(212, 212, 212),
	RGB(240, 240, 240), RGB(240, 240, 240), RGB(240, 240, 240), RGB(212, 212, 212),
	RGB(240, 240, 240), RGB(240, 240, 240), RGB(240, 240, 240), RGB(212, 212, 212),
	RGB(240, 240, 240), RGB(240, 240, 240), RGB(240, 240, 240), RGB(212, 212, 212),
	RGB(212, 212, 212), RGB(240, 240, 240), RGB(212, 212, 212), RGB(212, 212, 212),
	RGB(182, 182, 182)
};

void CreateButton(HWND& hwnd, LPCWSTR textButton, int x, int y, int Width, int Height, HWND hParent, int ID_BUTTON_, HFONT hfont, int sizeFont) {
	hwnd = CreateWindowW(L"Button", textButton, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | WS_CLIPSIBLINGS, x, y, Width, Height, hParent, (HMENU)ID_BUTTON_, hInst, 0);
	if (sizeFont < 25) {
		if (sizeFont == 21)
			hfont = CreateFont(sizeFont, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Lucida Calligraphy"));
		else hfont = CreateFont(sizeFont, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Gadugi"));
	}
	else hfont = CreateFont(sizeFont, 0, 0, 0, FW_DEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Gadugi"));

	SendMessage(hwnd, WM_SETFONT, WPARAM(hfont), TRUE);
}

void drawButtonRed(DRAWITEMSTRUCT* dis, HWND hwnd, int R, int G, int B)
{
	RECT rc;
	GetClientRect(hwnd, &rc);
	SetBkMode(dis->hDC, TRANSPARENT);
	SetTextColor(dis->hDC, RGB(R, G, B));
	TCHAR buf[255];
	GetWindowText(hwnd, buf, 255);
	DrawText(dis->hDC, buf, _tcslen(buf), &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void setvalue(char* val)
{
	if (nNew) {
		buf[0] = 0;
		SetWindowText(hEdit, buf);
		nNew = 0;
	}
	if (strlen(buf) < sizeof(buf)) {
		strcat(&buf[0], val);
		SetWindowText(hEdit, buf);
	}
}

void calculations()
{
	switch (nFunc) {
	case 0: {
		GetWindowText(hEdit, buf, sizeof(buf));
		dTotal = atof(buf);
		break;
	}
	case 1: {
		GetWindowText(hEdit, buf, sizeof(buf));
		dTotal += atof(buf);
		break;
	}
	case 2: {
		GetWindowText(hEdit, buf, sizeof(buf));
		dTotal -= atof(buf);
		break;
	}
	case 3: {
		GetWindowText(hEdit, buf, sizeof(buf));
		dTotal = dTotal * atof(buf);
		break;
	}
	case 4: {
		GetWindowText(hEdit, buf, sizeof(buf));
		dTotal = dTotal / atof(buf);
		break;
	}
	}
	buf[0] = 0;
	_gcvt(dTotal, sizeof(buf), buf);
	SetWindowText(hEdit, buf);
	nNew = 1;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	const int ITEMS = 25;
	static bool dot;
	static bool backsp;
	static HWND hButton[ITEMS], hTitle;
	HDC MemDC;
	PAINTSTRUCT ps;
	HDC hdc;
	static HFONT hFont;
	static HBRUSH hBrush[ITEMS];
	RECT rt;
	char cTemp[sizeof(buf)];

	switch (message) {
	case WM_CREATE: {
		hTitle = CreateWindowW(L"static", L"Êàëüêóëÿòîð", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10, 10, 100, 20, hWnd, (HMENU)ID_STATIC, hInst, 0);
		hEdit = CreateWindowW(L"edit", L"0", WS_CHILD | WS_VISIBLE | ES_RIGHT, 3, 135, 383, 65, hWnd, (HMENU)ID_EDIT, hInst, 0);
		CreateButton(hButton[0], L" % ", 3, 238, 95, 64, hWnd, ID_BUTTON_PERSENT, hFont, 20);
		CreateButton(hButton[1], L"\u221A", 99, 238, 95, 64, hWnd, ID_BUTTON_SQRT, hFont, 20);
		CreateButton(hButton[2], L"x\u00B2", 195, 238, 95, 64, hWnd, ID_BUTTON_EXP, hFont, 21);
		CreateButton(hButton[3], L"\u215Fx", 291, 238, 95, 64, hWnd, ID_BUTTON_DIV1X, hFont, 21);
		CreateButton(hButton[4], L" CE ", 3, 304, 95, 64, hWnd, ID_BUTTON_CE, hFont, 20);
		CreateButton(hButton[5], L" C ", 99, 304, 95, 64, hWnd, ID_BUTTON_C, hFont, 20);
		CreateButton(hButton[6], L"\u232B", 195, 304, 95, 64, hWnd, ID_BUTTON_BACK, hFont, 20);
		CreateButton(hButton[7], L"\u00F7", 291, 304, 95, 64, hWnd, ID_BUTTON_DIV, hFont, 24);
		CreateButton(hButton[8], L" 7 ", 3, 370, 95, 64, hWnd, ID_BUTTON_7, hFont, 25);
		CreateButton(hButton[9], L" 8 ", 99, 370, 95, 64, hWnd, ID_BUTTON_8, hFont, 25);
		CreateButton(hButton[10], L" 9 ", 195, 370, 95, 64, hWnd, ID_BUTTON_9, hFont, 25);
		CreateButton(hButton[11], L"\u2573", 291, 370, 95, 64, hWnd, ID_BUTTON_MUL, hFont, 18);
		CreateButton(hButton[12], L" 4 ", 3, 436, 95, 64, hWnd, ID_BUTTON_4, hFont, 25);
		CreateButton(hButton[13], L" 5 ", 99, 436, 95, 64, hWnd, ID_BUTTON_5, hFont, 25);
		CreateButton(hButton[14], L" 6 ", 195, 436, 95, 64, hWnd, ID_BUTTON_6, hFont, 25);
		CreateButton(hButton[15], L"\u2013", 291, 436, 95, 64, hWnd, ID_BUTTON_SUB, hFont, 25);
		CreateButton(hButton[16], L" 1 ", 3, 502, 95, 64, hWnd, ID_BUTTON_1, hFont, 25);
		CreateButton(hButton[17], L" 2 ", 99, 502, 95, 64, hWnd, ID_BUTTON_2, hFont, 25);
		CreateButton(hButton[18], L" 3 ", 195, 502, 95, 64, hWnd, ID_BUTTON_3, hFont, 25);
		CreateButton(hButton[19], L" + ", 291, 502, 95, 64, hWnd, ID_BUTTON_ADD, hFont, 24);
		CreateButton(hButton[20], L"\u00B1", 3, 568, 95, 64, hWnd, ID_BUTTON_ADDSUB, hFont, 24);
		CreateButton(hButton[21], L" 0 ", 99, 568, 95, 64, hWnd, ID_BUTTON_ZERO, hFont, 25);
		CreateButton(hButton[22], L" , ", 195, 568, 95, 64, hWnd, ID_BUTTON_POINT, hFont, 25);
		CreateButton(hButton[23], L"\uFF1D", 291, 568, 95, 64, hWnd, ID_BUTTON_EQUALLY, hFont, 25);
		CreateButton(hButton[24], L"\u2573", 344, 0, 46, 32, hWnd, ID_BUTTON_CLOSE, hFont, 13);

		hFont = CreateFont(55, 0, 0, 0, FW_DEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Gadugi"));
		SendMessage(hEdit, WM_SETFONT, WPARAM(hFont), TRUE);

		hFont = CreateFont(15, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Gadugi"));
		SendMessage(hTitle, WM_SETFONT, WPARAM(hFont), TRUE);
		break;
	}
	case WM_INITDIALOG: {
		for (int i = 0; i < ITEMS; i++)
			hBrush[i] = 0;
		return (INT_PTR)TRUE;
		break;
	}
	case WM_CTLCOLORSTATIC: {
		SetTextColor((HDC)wParam, RGB(0, 0, 0));
		SetBkMode((HDC)wParam, TRANSPARENT);
		return (INT_PTR)GetStockObject(NULL_BRUSH);
		break;
	}
	case WM_CTLCOLOREDIT: {
		SetBkMode((HDC)wParam, TRANSPARENT);
		return (INT_PTR)CreateSolidBrush(RGB(182, 182, 182));;
		break;
	}
	case WM_DRAWITEM: {
		DRAWITEMSTRUCT* dis = (DRAWITEMSTRUCT*)lParam;
		switch (dis->CtlID) {
		case ID_BUTTON_PERSENT: { drawButtonRed(dis, hButton[0], 0, 0, 0); break; }
		case ID_BUTTON_SQRT: { drawButtonRed(dis, hButton[1], 0, 0, 0); break; }
		case ID_BUTTON_EXP: { drawButtonRed(dis, hButton[2], 0, 0, 0); break; }
		case ID_BUTTON_DIV1X: { drawButtonRed(dis, hButton[3], 0, 0, 0); break; }
		case ID_BUTTON_CE: { drawButtonRed(dis, hButton[4], 0, 0, 0); break; }
		case ID_BUTTON_C: { drawButtonRed(dis, hButton[5], 0, 0, 0); break; }
		case ID_BUTTON_BACK: { drawButtonRed(dis, hButton[6], 0, 0, 0); break; }
		case ID_BUTTON_DIV: { drawButtonRed(dis, hButton[7], 0, 0, 0); break; }

		case ID_BUTTON_7: { drawButtonRed(dis, hButton[8], 0, 0, 0); break; }
		case ID_BUTTON_8: { drawButtonRed(dis, hButton[9], 0, 0, 0); break; }
		case ID_BUTTON_9: { drawButtonRed(dis, hButton[10], 0, 0, 0); break; }
		case ID_BUTTON_MUL: { drawButtonRed(dis, hButton[11], 0, 0, 0); break; }

		case ID_BUTTON_4: { drawButtonRed(dis, hButton[12], 0, 0, 0); break; }
		case ID_BUTTON_5: { drawButtonRed(dis, hButton[13], 0, 0, 0); break; }
		case ID_BUTTON_6: { drawButtonRed(dis, hButton[14], 0, 0, 0); break; }
		case ID_BUTTON_SUB: { drawButtonRed(dis, hButton[15], 0, 0, 0); break; }

		case ID_BUTTON_1: { drawButtonRed(dis, hButton[16], 0, 0, 0); break; }
		case ID_BUTTON_2: { drawButtonRed(dis, hButton[17], 0, 0, 0); break; }
		case ID_BUTTON_3: { drawButtonRed(dis, hButton[18], 0, 0, 0); break; }
		case ID_BUTTON_ADD: { drawButtonRed(dis, hButton[19], 0, 0, 0); break; }

		case ID_BUTTON_ADDSUB: { drawButtonRed(dis, hButton[20], 0, 0, 0); break; }
		case ID_BUTTON_ZERO: { drawButtonRed(dis, hButton[21], 0, 0, 0); break; }
		case ID_BUTTON_POINT: { drawButtonRed(dis, hButton[22], 0, 0, 0); break; }
		case ID_BUTTON_EQUALLY: { drawButtonRed(dis, hButton[23], 0, 0, 0); break; }
		case ID_BUTTON_CLOSE: { drawButtonRed(dis, hButton[24], 0, 0, 0); break; }
		}
		return TRUE;
	}
	case WM_CTLCOLORBTN: {
		for (int i = 0; i < ITEMS; i++) {
			if ((HWND)lParam == hButton[i]) {
				if (!hBrush[i])
					hBrush[i] = CreateSolidBrush(clrs[i]);
				return (INT_PTR)hBrush[i];
			}
		}
		break;
	}
	case WM_COMMAND: {
		switch (LOWORD(wParam)) {
		case ID_BUTTON_CLOSE: {
			for (int i = 0; i < ITEMS; i++) {
				SelectObject((HDC)wParam, hBrush[i]);
				DeleteObject(hBrush[i]);
			}
			DestroyWindow(hWnd);
			break;
		}
		case ID_BUTTON_1: {
			setvalue("1");
			backsp = true;
			break;
		}
		case ID_BUTTON_2: {
			setvalue("2");
			backsp = true;
			break;
		}
		case ID_BUTTON_3: {
			setvalue("3");
			backsp = true;
			break;
		}
		case ID_BUTTON_4: {
			setvalue("4");
			backsp = true;
			break;
		}
		case ID_BUTTON_5: {
			setvalue("5");
			backsp = true;
			break;
		}
		case ID_BUTTON_6: {
			setvalue("6");
			backsp = true;
			break;
		}
		case ID_BUTTON_7: {
			setvalue("7");
			backsp = true;
			break;
		}
		case ID_BUTTON_8: {
			setvalue("8");
			backsp = true;
			break;
		}
		case ID_BUTTON_9: {
			setvalue("9");
			backsp = true;
			break;
		}
		case ID_BUTTON_ZERO: {
			if (nNew) {
				buf[0] = 0;
				SetWindowText(hEdit, "0.");
				nNew = 0;
			}
			if ((strlen(buf) > 0) && (strlen(buf) < sizeof(buf))) {
				strcat(&buf[0], "0");
				SetWindowText(hEdit, buf);
			}
			backsp = true;
			break;
		}
		case ID_BUTTON_ADD: {
			calculations();
			nFunc = 1;
			dot = false;
			backsp = false;
			break;
		}
		case ID_BUTTON_SUB: {
			calculations();
			nFunc = 2;
			dot = false;
			backsp = false;
			break;
		}
		case ID_BUTTON_MUL: {
			calculations();
			nFunc = 3;
			dot = false;
			backsp = false;
			break;
		}
		case ID_BUTTON_DIV: {
			calculations();
			nFunc = 4;
			dot = false;
			backsp = false;
			break;
		}
		case ID_BUTTON_PERSENT: {
			double dRecip;

			GetWindowText(hEdit, buf, sizeof(buf));
			dRecip = atof(buf) / 100;

			buf[0] = 0;
			_gcvt(dRecip, sizeof(buf), buf);
			SetWindowText(hEdit, buf);
			nNew = 1;
			dot = false;
			backsp = false;
			break;
		}
		case ID_BUTTON_SQRT: {
			double dRoot;

			GetWindowText(hEdit, buf, sizeof(buf));
			dRoot = sqrt(atof(buf));

			buf[0] = 0;
			_gcvt(dRoot, sizeof(buf), buf);
			SetWindowText(hEdit, buf);
			nNew = 1;
			dot = false;
			backsp = false;
			break;
		}
		case ID_BUTTON_EXP: {
			double dRecip;

			GetWindowText(hEdit, buf, sizeof(buf));
			dRecip = pow(atof(buf), 2);

			buf[0] = 0;
			_gcvt(dRecip, sizeof(buf), buf);
			SetWindowText(hEdit, buf);
			nNew = 1;
			dot = false;
			backsp = false;
			break;
		}
		case ID_BUTTON_DIV1X: {
			double dRecip;

			GetWindowText(hEdit, buf, sizeof(buf));
			dRecip = 1 / atof(buf);

			buf[0] = 0;
			_gcvt(dRecip, sizeof(buf), buf);
			SetWindowText(hEdit, buf);
			nNew = 1;
			dot = false;
			backsp = false;
			break;
		}
		case ID_BUTTON_ADDSUB: {
			double dSignChg;

			GetWindowText(hEdit, buf, sizeof(buf));
			dSignChg = 0 - atof(buf);

			buf[0] = 0;
			_gcvt(dSignChg, sizeof(buf), buf);
			SetWindowText(hEdit, buf);
			nNew = 1;
			dot = false;
			backsp = false;
			break;
		}
		case ID_BUTTON_CE: {
			SetWindowText(hEdit, TEXT("0"));
			buf[0] = 0;
			break;
		}
		case ID_BUTTON_C: {
			SetWindowText(hEdit, TEXT("0"));
			buf[0] = 0;
			break;
		}
		case ID_BUTTON_BACK: {
			if (backsp) {
				if (strlen(buf) > 1) {
					char cLast[1];
					int iSLen = strlen(buf);
					cLast[0] = buf[iSLen - 1];
					if (strncmp(cLast, ".", 1) == 0)
						dot = false;
					strncpy(cTemp, buf, (iSLen - 1));
					cTemp[(iSLen - 1)] = '\0';
					strcpy(buf, cTemp);
					SetWindowText(hEdit, buf);
				}
				else {
					if (strlen(buf) == 1) {
						buf[0] = 0;
						SetWindowText(hEdit, "0.");
						nNew = 1;
						dot = false;
					}
				}
			}
			break;
		}
		case ID_BUTTON_POINT: {
			if (nNew) {
				buf[0] = 0;
				SetWindowText(hEdit, buf);
				nNew = 0;
			}
			if ((!dot) && (strlen(buf) < sizeof(buf))) {
				strcat(&buf[0], ".");
				SetWindowText(hEdit, buf);
				dot = true;
			}
			backsp = true;
			break;
		}
		case ID_BUTTON_EQUALLY: {
			calculations();
			nFunc = 0;
			dot = false;
			backsp = false;
			break;
		}
		}
		break;
	}
	case WM_COPYDATA: {
		GetClientRect(hWnd, &rt);
		hdc = GetDC(hWnd);
		DrawText(hdc, (TCHAR*)(((COPYDATASTRUCT*)lParam)->lpData), ((COPYDATASTRUCT*)lParam)->cbData, &rt, DT_RIGHT);
		ReleaseDC(hWnd, hdc);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}


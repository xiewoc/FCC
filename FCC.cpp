#include <windows.h>

int main()
{
	RECT rsw;//定义结构 
	int cx = GetSystemMetrics(SM_CXSCREEN);   
	int cy = GetSystemMetrics(SM_CYSCREEN);
	HWND cmd =FindWindow("ConsoleWindowClass",NULL);
	SetWindowPos(cmd,HWND_BOTTOM,0,0,0,0,SWP_HIDEWINDOW | SWP_NOOWNERZORDER);//隐藏窗口 
		while(1)
		{
			HWND sw=FindWindow(NULL,"希沃管家");//找同名窗口(类是chrome的，能查，但是用名字会好点)
			HWND swf =GetForegroundWindow(); //找顶置 
				if (sw!=0&&sw==swf){
					GetClientRect(sw,&rsw);//查窗口大小 
					if(rsw.right==cx&&rsw.bottom==cy){
						SetWindowPos(sw,HWND_BOTTOM,0,0,0,0,SWP_HIDEWINDOW | SWP_NOOWNERZORDER);//隐藏窗口(*在win10的某些机子上用不了)
					}
			}
			Sleep(1000);
		}
	return 0;
} 

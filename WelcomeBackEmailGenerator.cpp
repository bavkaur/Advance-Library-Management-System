
#include <windows.h>

using namespace std;

int main(){
    char* command = "curl smtp://smtp.gmail.com:587 -v --mail-from \"library.project.prabsimar.bavleen@gmail.com\" --mail-rcpt \"simarsingh1112@gmail.com\" --ssl -u library.project.prabsimar.bavleen@gmail.com:Library001 -T \"WelcomeBackEmail.txt\" -k --anyauth";
    WinExec(command, SW_HIDE);
    return 0;
}


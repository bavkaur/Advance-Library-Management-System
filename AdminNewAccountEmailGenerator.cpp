
#include <windows.h>

using namespace std;

int main(){
    char* command = "curl smtp://smtp.gmail.com:587 -v --mail-from \"library.project.prabsimar.bavleen@gmail.com\" --mail-rcpt \"bavleen3kaur@gmail.com\" --ssl -u library.project.prabsimar.bavleen@gmail.com:Library001 -T \"AdminNewAccountEmail.txt\" -k --anyauth";
    WinExec(command, SW_HIDE);
    return 0;
}


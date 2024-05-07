using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

termios unbuffered_tio;
termios original_tio;

int kbhit(){
    int count = 0;
	ioctl(STDIN_FILENO, FIONREAD, &count);
	return count;
}

void set_unbuffered_input(bool unbuffered){
    if(unbuffered){
        tcgetattr(STDIN_FILENO, &original_tio);
        unbuffered_tio = original_tio;
        unbuffered_tio.c_lflag &= ~(ICANON | ECHO); // Disable echo and canonical (cooked) mode
        tcsetattr(STDIN_FILENO, TCSANOW, &unbuffered_tio);
    } 
	else { //Restore original settings
		tcsetattr(STDIN_FILENO,TCSANOW, &original_tio);
	}
}

int main(){
    string command;
    vector<string> command_buffer;
    while(1){
        int bytes_available = kbhit();
        if(bytes_available){
            char c = getchar();
            if(c == ' '){
                cout << "Space pressed" << endl;
            }
        }
    }
}
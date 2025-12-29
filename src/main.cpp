//Krecikowa 29-12-2025
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include "command.hpp"
int main(){
        chdir(home);
        signal(SIGINT, sigint_handler);
        while(true){
            std::string input = commandTyping();
            std::vector<char*> argv = commandPars(input, tokens);
            commandExecute(input, tokens, argv);
        }
        return 0;
}


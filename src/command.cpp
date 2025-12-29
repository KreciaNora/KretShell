#include "command.hpp"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <signal.h>
const char* home = std::getenv("HOME");
const char* ps1 = std::getenv("PS1") ?: " -> ";
void sigint_handler(int){
        std::cout << "\n";

}
std::string input;
std::vector<std::string> tokens;
std::vector<char*> argv;

std::string commandTyping(){
        std::cout << ps1;
        if(!std::getline(std::cin, input)){
                std::cout << "\n";
                std::exit(0);
        }
        return input;
}

std::vector<char*> commandPars(const std::string input, std::vector<std::string>& tokens){
        tokens.clear();
        argv.clear();
        std::istringstream iss(input);
        std::string token;
        while (iss >> token){
                tokens.push_back(token);
        }
        for(auto& t : tokens){
                argv.push_back(const_cast<char*>(t.c_str()));
        }
        argv.push_back(nullptr);
        return argv;
}

void commandExecute(const std::string input, const std::vector<std::string>& tokens, const std::vector<char*>& argv){
        if(input == "exit"){
            std::exit(0);
        }
        std::string com = (tokens.size() > 0) ? tokens[0] : "";
        std::string arg = (tokens.size() > 1) ? tokens[1] : "";
        if(com == "cd"){
                if(arg == "~" or arg.empty()){
                       chdir(home);
                }else{
                    chdir(argv[1]);
                }
            
        }else{
            pid_t pid = fork();

            if(pid == 0){
                    

                    execvp(argv[0], argv.data());
                    perror("Command not found");
                    std::exit(1);
            }else if(pid > 0){
                int status;
                waitpid(pid, &status, 0);
            }else{
                perror("fork failed");
            }
        }
}


#pragma once
#include <string>
#include <vector>

extern const char* home;
extern const char* ps1;
extern std::string input;
extern std::vector<std::string> tokens;
extern std::vector<char*> argv;

void sigint_handler(int);

std::string commandTyping();
std::vector<char*> commandPars(const std::string input, std::vector<std::string>& tokens);
void commandExecute(const std::string input, const std::vector<std::string>& tokens, const std::vector<char*>& argv);

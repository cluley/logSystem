#include "logCommand.h"

void ConsoleLog::print(const std::string& message) {
	std::cout << message << std::endl;
}

void FileLog::print(const std::string& message) {
	logs << message << std::endl;
}
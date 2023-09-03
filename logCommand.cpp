#include "logCommand.h"

namespace fs = std::filesystem;

void ConsoleLog::print(const std::string& message) {
	std::cout << message << std::endl;
}

void FileLog::print(const std::string& message) {
	fs::path path{ "C:/Users/oo43/Documents" };
	path /= "logs.txt";
	if (!fs::create_directories(path.parent_path())) log.open(path);
	
	log << message << std::endl;
}
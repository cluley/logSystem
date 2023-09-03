#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>

class LogCommand {
public:
    virtual ~LogCommand() = default;

    virtual void print(const std::string& message) = 0;
};

class ConsoleLog : public LogCommand {
public:
    ~ConsoleLog() override = default;

    void print(const std::string& message) override;
};

class FileLog : public LogCommand {
public:
    ~FileLog() override { log.close(); }

    void print(const std::string& message) override;
private:
    std::ofstream log;
};
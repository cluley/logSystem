#pragma once

#include <iostream>
#include <fstream>

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
    ~FileLog() override { logs.close(); }

    void print(const std::string& message) override;
private:
    std::ofstream logs{"logs.txt"};
};
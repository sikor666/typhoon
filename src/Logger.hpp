#pragma once

// Basic logging system

#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

namespace vmo
{

constexpr auto yellow  {"\033[33m"};
constexpr auto red     {"\033[91m"};
constexpr auto green   {"\033[92m"};
constexpr auto orange  {"\033[93m"};
constexpr auto blue    {"\033[94m"};
constexpr auto magenta {"\033[95m"};
constexpr auto cyan    {"\033[96m"};
constexpr auto white   {"\033[97m"};
constexpr auto end     {"\033[0m"};

} // namespace vmo

class Loggex
{
private:
    std::stringstream mCache;
    std::function<void(std::stringstream &)> mPrint;

public:
    Loggex()
        : mPrint{[](std::stringstream & stream) { std::cout << stream.str() << vmo::end << std::endl; }}
    {
    }

    Loggex(std::function<void(std::stringstream &)> print)
        : mPrint{print}
    {
    }

    ~Loggex()
    {
        // flush on destroy
        mPrint(mCache);
    }

    template <typename T> Loggex & operator<<(const T & v)
    {
        mCache << v;
        return *this;
    }
};

#define logE (Loggex{} << vmo::red)
#define logW (Loggex{} << vmo::yellow)
#define logI (Loggex{} << vmo::green)
#define logD (Loggex{} << vmo::blue)

// Enum to represent log levels
enum LogLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class Logger
{
public:
    // Constructor: Opens the log file in append mode
    Logger(const std::string & filename)
    {
        logFile.open(filename, std::ios::app);

        if (not logFile.is_open())
        {
            std::cerr << "Error opening log file." << std::endl;
        }
    }

    // Destructor: Closes the log file
    ~Logger() { logFile.close(); }

    // Logs a message with a given log level
    void log(LogLevel level, const std::string & message)
    {
        // Get current timestamp
        time_t now = time(0);
        tm * timeinfo = localtime(&now);
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

        // Create log entry
        std::ostringstream logEntry;
        logEntry << "[" << timestamp << "] " << levelToString(level) << ": " << message << std::endl;

        // Output to console
        // std::cout << logEntry.str();

        // Output to log file
        if (logFile.is_open())
        {
            logFile << logEntry.str();
            logFile.flush(); // Ensure immediate write to file
        }
    }

private:
    std::ofstream logFile; // File stream for the log file

    // Converts log level to a string for output
    std::string levelToString(LogLevel level)
    {
        switch (level)
        {
            case DEBUG: return "DEBUG";
            case INFO: return "INFO";
            case WARNING: return "WARNING";
            case ERROR: return "ERROR";
            case CRITICAL: return "CRITICAL";
            default: return "UNKNOWN";
        }
    }
};

Logger logger("logfile.txt"); // Create logger instance

#define logF Loggex{[](std::stringstream & stream) { logger.log(INFO, stream.str()); }}

#include <filesystem>
#include <fstream>
#include "utils/Logger.hpp"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace ForgeMind
{
    std::ofstream Logger::logFile;
    void Logger::initialize()
    {
        std::filesystem::create_directories("logs");

        logFile.open("logs/forge_mind_ai.log", std::ios::app);

        if (logFile.is_open())
        {
            logFile << "\n============================================\n";
            logFile << "FORGE MIND AI Session Started\n";
            logFile << "============================================\n";
        }
    }

    void Logger::shutdown()
    {
        if (logFile.is_open())
        {
            logFile << "Session Ended\n";

            logFile.close();
        }
    }
    std::string Logger::getCurrentTime()
    {
        auto now = std::chrono::system_clock::now();

        auto currentTime = std::chrono::system_clock::to_time_t(now);

        std::tm localTime{};

#ifdef _WIN32
        localtime_s(&localTime, &currentTime);
#else
        localtime_r(&currentTime, &localTime);
#endif

        std::ostringstream output;

        output << std::put_time(&localTime, "%H:%M:%S");

        return output.str();
    }

    std::string Logger::levelToString(LogLevel level)
    {
        switch (level)
        {
        case LogLevel::INFO:
            return "INFO";

        case LogLevel::WARNING:
            return "WARNING";

        case LogLevel::ERROR:
            return "ERROR";

        case LogLevel::DEBUG:
            return "DEBUG";

        default:
            return "UNKNOWN";
        }
    }

    void Logger::log(LogLevel level, const std::string &message)
    {
        std::cout

            << "["
            << getCurrentTime()
            << "] "
            << "["
            << levelToString(level)
            << "] "
            << message
            << std::endl;

        if (logFile.is_open())
        {
            logFile
                << "["
                << getCurrentTime()
                << "] "
                << "["
                << levelToString(level)
                << "] "
                << message
                << std::endl;
        }
    }

    void Logger::info(const std::string &message)
    {
        log(LogLevel::INFO, message);
    }

    void Logger::warning(const std::string &message)
    {
        log(LogLevel::WARNING, message);
    }

    void Logger::error(const std::string &message)
    {
        log(LogLevel::ERROR, message);
    }

    void Logger::debug(const std::string &message)
    {
        log(LogLevel::DEBUG, message);
    }
}
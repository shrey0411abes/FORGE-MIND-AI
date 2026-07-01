#pragma once

#include <fstream>
#include <string>

namespace ForgeMind
{
    enum class LogLevel
    {
        INFO,
        WARNING,
        ERROR,
        DEBUG
    };

    class Logger
    {
    public:
        static void initialize();

        static void shutdown();

        static void log(LogLevel level, const std::string &message);

        static void info(const std::string &message);

        static void warning(const std::string &message);

        static void error(const std::string &message);

        static void debug(const std::string &message);

    private:
        static std::ofstream logFile;

        static std::string getCurrentTime();

        static std::string levelToString(LogLevel level);
    };
}
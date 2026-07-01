#include "core/Application.hpp"
#include "utils/Logger.hpp"
namespace ForgeMind
{
    Application::Application()
    {
        Logger::info("Application initialized.");
    }

    int Application::run()
    {
        Logger::info("FORGE MIND AI is running.");
        Logger::debug("Logger module initialized.");
        Logger::warning("Configuration file not loaded yet.");
        Logger::error("Sample error log for testing.");

        return 0;
    }
}
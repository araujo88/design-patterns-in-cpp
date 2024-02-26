#include <iostream>
#include <memory>

class Logger {
public:
    virtual ~Logger() {}
    virtual void log(const std::string& message) = 0;
};

class FileLogger : public Logger {
public:
    void log(const std::string& message) override {
        // Imagine file logging implementation here
        std::cout << "Logging to a file: " << message << std::endl;
    }
};

class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override {
        // Console logging implementation
        std::cout << "Logging to console: " << message << std::endl;
    }
};

class LoggerFactory {
public:
    enum LoggerType {
        FILE,
        CONSOLE
        // Additional logger types can be added here
    };

    static std::unique_ptr<Logger> createLogger(LoggerType type) {
        switch (type) {
            case FILE:
                return std::make_unique<FileLogger>();
            case CONSOLE:
                return std::make_unique<ConsoleLogger>();
            default:
                throw std::invalid_argument("Unsupported logger type");
        }
    }
};

int main() {
    // Create a console logger
    auto consoleLogger = LoggerFactory::createLogger(LoggerFactory::CONSOLE);
    consoleLogger->log("This is a console log message.");

    // Create a file logger
    auto fileLogger = LoggerFactory::createLogger(LoggerFactory::FILE);
    fileLogger->log("This is a file log message.");

    return 0;
}


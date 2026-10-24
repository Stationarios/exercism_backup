#include <string>

namespace log_line {
std::string message(std::string line) {
    // return the message
    int start = line.find(":");
    return line.substr(start + 2);
}

std::string log_level(std::string line) {
    // return the log level
    int end = line.find("]");
    return line.substr(1, end - 1);
}

std::string reformat(std::string line) {
    // return the reformatted message
    std::string message_line = message(line);
    std::string log_level_line = log_level(line);
    return message_line + " (" + log_level_line + ")";
}
}  // namespace log_line

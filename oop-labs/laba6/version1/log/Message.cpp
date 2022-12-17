#include "Message.h"


Message::Message(Levels level, std::string text) {
    this->level=level;
    this->text=std::move(text);
    time_t seconds = time(nullptr);
    tm* timeInfo = localtime(&seconds);
    std::string temp = asctime(timeInfo);
    temp.pop_back();
    timeMessage = temp;
}


std::ostream &operator<<(std::ostream& stream, Message& message) {
    stream << message.levelsConverter.at(message.level) << '\t';
    stream << message.timeMessage << '\t';
    stream << message.text << '\t';
    return stream;
}


Levels Message::getLevel() {
    return level;
}

#ifndef ENGINE
#define ENGINE


#include "../wrapper/Wrapper.h"

template <typename Type>
class Engine {
    std::map<std::string, Wrapper<Type>*> commands;

public:
    void register_command(Wrapper<Type>* wrapper, const std::string& command) {
        commands[command] = wrapper;
    }

    Type execute(const char* name, const std::map<std::string, Type>& args) {
        if (!commands.contains(name)) {
            throw std::exception();
        }

        return commands[name]->execute(args);
    }
};


#endif //ENGINE
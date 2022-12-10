#include <iostream>
#include "src/wrapper/Wrapper.h"
#include "src/engine/Engine.h"

class Object {
public:
    int fInt(int a, int b) {
        return a + b;
    }

    double fDouble(double a, double b) {
        return a + b;
    }

    std::string fString(const std::string& a, const std::string& b) {
        return a + b;
    }
};

int main() {
    Object obj;

    // int example
    Wrapper wrapperInt(&obj, &Object::fInt, {{"arg1", 0}, {"arg2", 0}});
    Engine<int> engineInt;
    engineInt.register_command(&wrapperInt, "command1");
    std::cout << engineInt.execute("command1", {{"arg1", 4}, {"arg2", 5} }) << std::endl;

    // double example
    Wrapper wrapperDouble(&obj, &Object::fDouble, {{"arg1", 0.0}, {"arg2", 0.0}});
    Engine<double> engineDouble;
    engineDouble.register_command(&wrapperDouble, "command1");
    std::cout << engineDouble.execute("command1", {{"arg1", 4.33}, {"arg2", 5.33} }) << std::endl;

    // std::string example
    Wrapper wrapperString(&obj, &Object::fString, {{"arg1", ""}, {"arg2", ""}});
    Engine<std::string> engineString;
    engineString.register_command(&wrapperString, "command1");
    std::cout << engineString.execute("command1", { {"arg1", "abra"}, {"arg2", "cadabra"} }) << std::endl;
}

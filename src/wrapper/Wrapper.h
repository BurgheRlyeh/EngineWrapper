#ifndef WRAPPER
#define WRAPPER


#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <functional>

template <typename Type>
class Wrapper {
    std::vector<std::string> argsOrder;
    std::function<Type(std::vector<Type>)> function;

public:
    Wrapper() = delete;

    template <typename Obj, typename... Args>
    Wrapper(Obj* object, Type (Obj::*method)(Args...), const std::map<std::string, Type>& args) {
        if (object == nullptr || method == nullptr || sizeof...(Args) != args.size()) {
            throw std::exception();
        }

        for (auto arg : args) {
            argsOrder.push_back(arg.first);
        }
        function = [this, object, method](std::vector<Type> args) {
            return executeFunction(object, method, args, std::make_index_sequence<sizeof...(Args)>{});
        };
    }

    Type execute(const std::map<std::string, Type>& args) {
        if (argsOrder.size() != args.size()) {
            throw std::exception();
        }

        std::vector<Type> argsVector;
        for (auto arg : argsOrder) {
            auto value = args.find(arg);
            value == args.end() ? throw std::exception() : argsVector.push_back(value->second);
        }

        return function(argsVector);
    }

private:
    template <typename Obj, typename... Args, size_t... I>
    Type executeFunction(Obj* obj, Type (Obj::*func)(Args...), std::vector<Type> args, std::index_sequence<I...>) {
        return (obj->*func)(args[I]...);
    }
};


#endif //WRAPPER

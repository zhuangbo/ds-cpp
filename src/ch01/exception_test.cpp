///////////////////////////////////////
/// file: exception_test.cpp
/// Examples for standard exceptions.
///////////////////////////////////////

#include <iostream>
#include <exception>
#include <stdexcept>

// 使用 std::invalid_argument 的例子
int mydiv(int a, int b)
{
    if(b==0)
        throw std::invalid_argument("Division by zero.");
    return a/b;
}

// 自定义异常的例子（继承逻辑错误类 std::logic_error）
class InvalidArgumentException : public std::logic_error
{
public:
    explicit InvalidArgumentException(const std::string& msg)
      : std::logic_error(msg) {}
    explicit InvalidArgumentException(const char *msg)
      : std::logic_error(msg) {}
};

// 抛出自定义的异常
int f(int n)
{
    if(n<0)
        throw InvalidArgumentException("Invalid argument n<0.");
    return n;
}

///
/// 异常处理的例子
///
int main()
{
    try {
        std::cout << mydiv(1,0) << std::endl;
    } catch(std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    } catch(std::exception& e) {  // 也可以用超类
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << f(-1) << std::endl;
    } catch(InvalidArgumentException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
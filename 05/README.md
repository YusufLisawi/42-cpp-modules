# Introduction to Exceptions

Exceptions in C++ provide a structured way to handle unexpected errors or exceptional conditions in your code. They allow you to separate the error-handling code from the normal program flow. Here, we'll provide a step-by-step explanation of how exceptions work and how to use them effectively.

## Handling Exceptions

### `try` and `catch`

The core components of exception handling in C++ are `try` and `catch` blocks.

- **`try` block**: Code that may throw an exception is enclosed within a `try` block. When an exception occurs inside this block, the program looks for an appropriate `catch` block to handle it.

- **`catch` block**: A `catch` block follows a `try` block and is responsible for handling exceptions. Each `catch` block specifies the type of exception it can catch. If an exception matching the specified type is thrown, that `catch` block is executed.

### Example of Handling an Exception

```cpp
#include <iostream>
#include <stdexcept>

int main() {
    try {
        int numerator = 10;
        int denominator = 0;

        if (denominator == 0) {
            throw std::runtime_error("Division by zero is not allowed.");
        }

        int result = numerator / denominator;
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
```

In this example:
- We have a `try` block that performs division and throws a `std::runtime_error` if the denominator is zero.
- The `catch` block catches the `std::runtime_error` and prints its error message using the `what()` function.

## Throwing Exceptions

### `throw` Keyword

The `throw` keyword is used to raise or throw an exception. You can throw exceptions of different types, including built-in types, standard library exception classes, or custom exception classes.

### Example of Throwing an Exception

```cpp
#include <iostream>
#include <stdexcept>

int main() {
    try {
        int age = -5;

        if (age < 0) {
            throw std::invalid_argument("Age cannot be negative.");
        }

        std::cout << "Age: " << age << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
```

Here, we throw a `std::invalid_argument` exception when the age is negative.

## Under the Hood

Under the hood, when an exception is thrown:

- The program searches for a matching `catch` block, starting from the innermost `try` block and moving outward through the call stack.
- If a matching `catch` block is found, the code in that block is executed.
- If no matching `catch` block is found, the program terminates, and if uncaught, the system generates an error message.

## Creating Custom Exception Classes

You can create custom exception classes for handling specific exceptions in your code.

### Example of Custom Exception Class

```cpp
#include <iostream>
#include <stdexcept>

class MyCustomException : public std::exception {
public:
    MyCustomException(const char* message) : msg(message) {}

    const char* what() const throw() {
        return msg;
    }

private:
    const char* msg;
};

int main() {
    try {
        throw MyCustomException("Custom exception message");
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
```

Here, we define a `MyCustomException` class derived from `std::exception`. It overrides the `what()` function to provide a custom error message.

### Prototype: `const char* what() const throw();`

This prototype defines the `what()` function in a custom exception class. It returns a pointer to a constant character (`const char*`) and is marked with `throw()`, indicating that this function will not throw any exceptions itself.

Using `const char*` as the return type allows you to return a C-style string that describes the exception when you override the `what()` function in your custom exception class.

In summary, exception handling involves `try` and `catch` blocks, the `throw` keyword for raising exceptions, and custom exception classes for handling specific exceptions. Exceptions work under the hood by searching for matching `catch` blocks in the call stack. The `what()` function provides a custom error message, and its prototype is defined with `const char* what() const throw();`.
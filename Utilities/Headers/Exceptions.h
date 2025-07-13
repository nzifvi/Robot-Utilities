//
// Created by benja on 10.07.2025.
//

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class invalid_dimensions : public std::exception {
public:
    const char* what() const noexcept override {
        return "Matrix operation operands have invalid dimensions\n";
    }
};

class func_not_yet_implemented : public std::exception {
public:
    const char* what() const noexcept override {
        return "Called function not yet implemented\n";
    }
};

class case_not_yet_implemented : public std::exception {
public:
    const char* what() const noexcept override {
        return "Function call for this specific case not yet implemented\n";
    }
};

#endif //EXCEPTIONS_H

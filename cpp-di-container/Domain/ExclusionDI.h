#pragma once

#ifndef ExclusionDI_H
#define ExclusionDI_H

#include <iostream>

class ExclusionDI
{
public:
    ExclusionDI(std::string name);
    ExclusionDI() = delete;

    void DisplayName();
private:
    std::string name_;
};

// constructors
inline ExclusionDI::ExclusionDI(std::string name)
    :name_(name)
{};

void inline ExclusionDI::DisplayName()
{
    std::cout << "name is " << name_.c_str() << std::endl;
}

#endif //ExclusionDI_H

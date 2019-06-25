#pragma once

#ifndef IOBJECT_H
#define IOBJECT_H

#include<memory>

class IObject
{
public:
    static std::unique_ptr<IObject> Create() { return nullptr;}

protected:
    //virtual std::unique_ptr<IObject> createMain();
};

#endif //IOBJECT_H

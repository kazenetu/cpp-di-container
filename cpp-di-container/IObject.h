#pragma once

#ifndef IOBJECT_H
#define IOBJECT_H

#include<memory>

class IObject
{
public:
    static std::unique_ptr<IObject> Create() { return nullptr;}

protected:
    //virtual void created() = 0;
    //virtual void deleted() = 0;
};

#endif //IOBJECT_H

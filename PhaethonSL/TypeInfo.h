#pragma once

class TypeInfo
{
public:
    virtual unsigned int GetSize() = 0;
    virtual bool IsBasic() = 0;
};

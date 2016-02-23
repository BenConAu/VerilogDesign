#pragma once

class TypeInfo
{
public:
    virtual int GetSize() = 0;
    virtual bool IsBasic() = 0;
};

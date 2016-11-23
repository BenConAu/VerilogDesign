#pragma once

#include "AssemblerNode.h"
#include <vector>

class StructMember : public AssemblerNode
{
public:
    int GetSize()
    {
        if (GetIntProperty("type") != AddSymbol("word"))
        {
            printf("Non-word members of structs not supported yet\n");
        }

        int arraySize = GetIntProperty("arraySize");
        if (arraySize == 0)
        {
            // Nothing stored means it is not an array
            return 4;
        }
        else
        {
            // Array of word
            return arraySize * 4;
        }
    }
};

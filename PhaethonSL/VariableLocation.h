#pragma once

typedef unsigned char RegIndex;

enum class LocationType
{
    None,
    Register,
    Memory,
};

/*struct VariableLocation
{
    VariableLocation() { _type = LocationType::None; }
    VariableLocation(RegIndex_ index) { _type = LocationType::Register; _regIndex = index; }

    LocationType _type;
    union
    {
        RegIndex_ _regIndex;
        unsigned int _memLocation;
    };

    static VariableLocation None() { return VariableLocation(); }
};*/

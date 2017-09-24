#pragma once

enum class VariableLocationType
{
    None,       // Uninitialized / unknown
    Member,     // Member of a module
    Input,      // Input to a module / function
    Output,     // Output from a module / function
    Generic,    // Generic argument to function
};

#pragma once

// Functions that are generic are defined either with a constant
// or with an identifier. Constants are matched before identifers.
enum class FunctionType
{
  Standard,
  Stage,
  GenericConstant,
  GenericIdentifier,
};

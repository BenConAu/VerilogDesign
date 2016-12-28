#include "Operand.h"
#include <vector>

enum class ExpressionResultType
{
    None = 0,            // Used for error conditions and the such or unintialized types
    Constant,            // The operand is a constant
    Register,            // The operand is a register
    DerefConstant,       // The operand is a memory location at the given constant location
    DerefRegisterOffset, // Just like above, but with a constant offset
    DerefRegisterIndex,  // Just like above, but with an index offset
};

ExpressionResultType ConvertType(OperandType type);

class OperandList
{
  public:
    OperandList(const Operand &o);
    OperandList();
    void push_back(const Operand& op);
    size_t size() const;
    ExpressionResultType GetResultType() const;
    RegIndex GetRegIndex();
    Operand& GetOperand(size_t index);

  private:
    // The aggregate type of the operands (how to interpret them)
    mutable ExpressionResultType _type;

    // The operands
    std::vector<Operand> _operandList;
};

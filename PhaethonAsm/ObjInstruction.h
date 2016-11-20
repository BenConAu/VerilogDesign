#pragma once

// Data required to store the object data for an instruction
struct ObjInstruction
{
    ObjInstruction(
        OpCodes::Enum opCode,
        Argument a1,
        Argument a2,
        Argument a3,
        int wordArg
        )
    {
        _opCode = opCode;
        _args[0] = a1;
        _args[1] = a2;
        _args[2] = a3;
        _wordArg = wordArg;
    }

    ObjInstruction()
    {
        ::memset(this, 0, sizeof(*this));
    }

    void Output()
    {
    	OutputBytes(_opCode, _args[0]._value, _args[1]._value, _args[2]._value);

    	if (_wordArg != -1)
    	{
            if (_args[_wordArg]._offset == -1)
            {
                //printf("Output word %d\n", _args[_wordArg]._value);
        		OutputWord(_args[_wordArg]._value);
            }
            else
            {
                //printf("Output word %d\n", _args[_wordArg]._offset);
        		OutputWord(_args[_wordArg]._offset);
            }
    	}
    }    

    OpCodes::Enum _opCode;
    Argument _args[3];
    int _wordArg;    
};

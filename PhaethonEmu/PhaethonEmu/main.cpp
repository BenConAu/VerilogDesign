//
//  main.cpp
//  PhaethonEmu
//
//  Created by Ben Constable on 2/7/16.
//  Copyright © 2016 Ben Constable. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "../../PhaethonAsm/Codegen/PhaethonOpCode.h"
#include "../../PhaethonAsm/InstructionData.h"

typedef unsigned int WORD;
typedef unsigned char BYTE;

struct byteWord
{
    union
    {
        WORD word;
        float fl;
        struct
        {
            BYTE byte[4];
        };
    };

    byteWord(WORD w = 0)
    {
        word = w;
    }
};

class PaoReader
{
public:
    PaoReader(const char* pszFile)
    {
        _pFile = ::fopen(pszFile, "r");
    }

    bool ReadWord(byteWord *pWord)
    {
        char bs[4][4];
        if (::fscanf(_pFile, "%s %s %s %s\n", bs[0], bs[1], bs[2], bs[3]) == 4)
        {
            for (int i = 0; i < 4; i++)
            {
                pWord->byte[i] = ::strtol(bs[i], nullptr, 16);
            }

            return true;
        }

        return false;
    }

    ~PaoReader()
    {
        ::fclose(_pFile);
    }

private:
    FILE* _pFile;
};

class RAM
{
public:
    byteWord ReadWord(WORD addr)
    {
        byteWord ret;
        for (int i = 0; i < 4; i++)
        {
            ret.byte[i] = ram[addr + i];
        }
        return ret;
    }

    void WriteWord(WORD addr, byteWord w)
    {
        for (int i = 0; i < 4; i++)
        {
            ram[addr + i] = w.byte[i];
        }
    }
private:
    BYTE ram[2048];
};

int main(int argc, const char * argv[])
{
    PaoReader ramReader(argv[1]);
    RAM ram;

    // Load up the ram
    byteWord newWord;
    WORD ramPos;
    while (ramReader.ReadWord(&newWord))
    {
        ram.WriteWord(ramPos, newWord);
        ramPos += 4;
    }

    WORD ip = 0;
    byteWord reg[66];
    WORD rPos = 2;
    WORD iCount = 0;

    for (;;)
    {
        // If we run off the end then we are done
        if (ip > ramPos)
        {
            break;
        }

        // Read the opCode
        byteWord ramCode = ram.ReadWord(ip);
        OpCode opCode = static_cast<OpCode>(ramCode.byte[0]);
        WORD regAddr1 = (ramCode.byte[1] >= 64) ? (ramCode.byte[1] - 64) : (ramCode.byte[1] + rPos);
        WORD regAddr2 = (ramCode.byte[2] >= 64) ? (ramCode.byte[2] - 64) : (ramCode.byte[2] + rPos);
        WORD regAddr3 = (ramCode.byte[3] >= 64) ? (ramCode.byte[3] - 64) : (ramCode.byte[3] + rPos);

        byteWord regValue1 = reg[regAddr1];
        byteWord regValue2 = reg[regAddr2];
        byteWord regValue3 = reg[regAddr3];

        WORD opWord = 0xdeadbeef;
        if (Is8ByteOpcode(opCode))
        {
            opWord = ram.ReadWord(ip + 4).word;
        }

        bool condJump = false;

        switch(opCode)
        {
            case MovRR:
                reg[regAddr1] = regValue2;
                break;

            case MovRC:
                reg[regAddr1].word = opWord;
                break;

            case MovRdR:
                reg[regAddr1] = ram.ReadWord(regValue2.word);
                break;

            case MovRdC:
                reg[regAddr1] = ram.ReadWord(opWord);
                break;

            case MovRdRo:
                reg[regAddr1] = ram.ReadWord(regValue2.word + opWord);
                break;

            case MovdCR:
                ram.WriteWord(opWord, regValue2);
                break;

            case MovdRoR:
                ram.WriteWord(regValue1.word + opWord, regValue2);
                break;

            case AddRC:
                reg[regAddr1].word += opWord;
                break;

            case AddRR:
                reg[regAddr1].word += regValue2.word;
                break;

            case DecR:
                reg[regAddr1].word--;
                break;

            case IncR:
                reg[regAddr1].word++;
                break;

            case FdivRR:
                reg[regAddr1].fl = regValue1.fl / regValue2.fl;
                break;

            case FminRR:
                reg[regAddr1].fl = fmin(regValue1.fl, regValue2.fl);
                break;

            case FmaxRR:
                reg[regAddr1].fl = fmax(regValue1.fl, regValue2.fl);
                break;

            case MulAddRRC:
                reg[regAddr1].word = regValue1.word + regValue2.word * opWord;
                break;

            case PushR:
                ram.WriteWord(reg[0].word, regValue1);
                reg[0].word += 4;
                break;

            case PopR:
                reg[0].word -= 4;
                reg[regAddr1] = ram.ReadWord(reg[0].word);
                break;

            case CallR:
                ram.WriteWord(reg[0].word, ip);
                reg[0].word += 4;
                ip = regValue1.word;
                break;

            case Ret:
                reg[0].word -= 4;
                ip = ram.ReadWord(reg[0].word).word + 4;
                break;

            case RCallRC:
                reg[rPos + opWord] = ip;
                reg[rPos + opWord + 1] = opWord;
                rPos += (opWord + 2);
                ip = regValue1.word;
                break;

            case RRet:
                ip = reg[rPos - 2].word + 8;
                rPos -= (reg[rPos - 1].word + 2);
                break;

            case JmpC:
                ip = opWord;
                break;

            case JneC:
                condJump = (reg[1].word & 1) == 0;
                break;

            case JeC:
                condJump = (reg[1].word & 1) != 0;
                break;

            case CmpRC:
                if (regValue1.word == opWord)
                {
                    reg[1].word |= 1;
                }
                else
                {
                    reg[1].word &= (~1);
                }

                if (regValue1.word < opWord)
                {
                    reg[1].word |= 2;
                }
                else
                {
                    reg[1].word &= (~2);
                }

                if (regValue1.word > opWord)
                {
                    reg[1].word |= 4;
                }
                else
                {
                    reg[1].word &= (~4);
                }
                break;

            case DoutR:
                printf("DebugOut %x\n", regValue1.word);
                break;

            default:
                printf("Unknown opcode %d\n", opCode);
                break;
        }

        if (condJump)
        {
            ip = opWord;
        }
        else
        {
            if (opCode != CallR &&
                opCode != JmpC &&
                opCode != Ret &&
                opCode != RRet &&
                opCode != RCallRC
                )
            {
                if (Is8ByteOpcode(opCode))
                {
                    ip += 8;
                }
                else
                {
                    ip += 4;
                }
            }
        }

        printf("OP:%10s::%4x:%4x:%4x:%4x:%4x\n",
               InstructionData::s_data[opCode - 1].pszName,
               reg[rPos].word,
               reg[rPos + 1].word,
               reg[rPos + 2].word,
               reg[rPos + 3].word,
               reg[rPos + 4].word
               );

        iCount++;

        if (iCount >= 100)
            break;
    }

    return 0;
}

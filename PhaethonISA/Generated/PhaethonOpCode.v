`define MovRR 1
`define MovRC 2
`define MovRdR 3
`define MovRdRo 4
`define MovRdRoR 5
`define MovRdC 6
`define MovdCR 7
`define MovdRoR 8
`define MovdRoRR 9
`define PackRRR 10
`define PushR 11
`define PopR 12
`define CmpRR 13
`define CmpRC 14
`define CmpERRR 15
`define CmpNeRRR 16
`define CmpLtRRR 17
`define CmpGtRRR 18
`define JmpC 19
`define JneC 20
`define JeC 21
`define JzRC 22
`define JnzRC 23
`define CallR 24
`define Ret 25
`define RCallRC 26
`define RRet 27
`define AddRRC 28
`define AddRRR 29
`define SubRRC 30
`define SubRRR 31
`define MulAddRRC 32
`define IncR 33
`define DecR 34
`define ShlRRR 35
`define ShrRRR 36
`define NegRR 37
`define FaddRRR 38
`define FsubRR 39
`define FconvR 40
`define FmulRRR 41
`define FdivRR 42
`define FmuladdRRR 43
`define FminRR 44
`define FmaxRR 45
`define VfaddRRR 46
`define DoutR 47
`define DinR 48
`define DlenR 49
`define ReadPortRR 50
`define WritePortRR 51
`define ExecR 52
`define Exit 53
`define VpEnable 54
`define LeaRRoR 55
`define MaxOpCode 55

function [0:0] Is8ByteOpcode;
  input [7:0] opCodeParam;
  if (opCodeParam == `MovRC ||
      opCodeParam == `MovRdRo ||
      opCodeParam == `MovRdRoR ||
      opCodeParam == `MovRdC ||
      opCodeParam == `MovdCR ||
      opCodeParam == `MovdRoR ||
      opCodeParam == `MovdRoRR ||
      opCodeParam == `CmpRC ||
      opCodeParam == `JmpC ||
      opCodeParam == `JneC ||
      opCodeParam == `JeC ||
      opCodeParam == `JzRC ||
      opCodeParam == `JnzRC ||
      opCodeParam == `RCallRC ||
      opCodeParam == `AddRRC ||
      opCodeParam == `SubRRC ||
      opCodeParam == `MulAddRRC ||
      opCodeParam == `LeaRRoR)
    Is8ByteOpcode = 1;
  else
    Is8ByteOpcode = 0;
endfunction

function [0:0] IsRAMOpcode;
  input [7:0] opCodeParam;
  if (opCodeParam == `MovRdR ||
      opCodeParam == `MovRdRo ||
      opCodeParam == `MovRdRoR ||
      opCodeParam == `MovRdC ||
      opCodeParam == `MovdCR ||
      opCodeParam == `MovdRoR ||
      opCodeParam == `MovdRoRR ||
      opCodeParam == `PushR ||
      opCodeParam == `PopR ||
      opCodeParam == `CallR ||
      opCodeParam == `Ret)
    IsRAMOpcode = 1;
  else
    IsRAMOpcode = 0;
endfunction

function [0:0] IsIOOpcode;
  input [7:0] opCodeParam;
  if (opCodeParam == `DoutR ||
      opCodeParam == `DinR ||
      opCodeParam == `ReadPortRR ||
      opCodeParam == `WritePortRR)
    IsIOOpcode = 1;
  else
    IsIOOpcode = 0;
endfunction


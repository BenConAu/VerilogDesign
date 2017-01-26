`define MovRR 1
`define MovRC 2
`define MovRdR 3
`define MovRdRo 4
`define MovRdRoR 5
`define MovRdC 6
`define MovdCR 7
`define MovdRoR 8
`define MovdRoRR 9
`define PushR 10
`define PopR 11
`define CmpRR 12
`define CmpRC 13
`define CmpERRR 14
`define CmpNeRRR 15
`define CmpLtRRR 16
`define CmpGtRRR 17
`define JmpC 18
`define JneC 19
`define JeC 20
`define JzRC 21
`define JnzRC 22
`define CallR 23
`define Ret 24
`define RCallRC 25
`define RRet 26
`define AddRRC 27
`define AddRRR 28
`define SubRRC 29
`define SubRRR 30
`define MulAddRRC 31
`define IncR 32
`define DecR 33
`define ShlRRR 34
`define ShrRRR 35
`define NegRR 36
`define FaddRRR 37
`define FsubRR 38
`define FconvR 39
`define FmulRRR 40
`define FdivRR 41
`define FmuladdRRR 42
`define FminRR 43
`define FmaxRR 44
`define VfaddRRR 45
`define DoutR 46
`define ReadPortRR 47
`define Stall 48

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
      opCodeParam == `MulAddRRC)
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


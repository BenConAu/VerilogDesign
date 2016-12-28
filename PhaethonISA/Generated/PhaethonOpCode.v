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
`define JmpC 16
`define JneC 17
`define JeC 18
`define JzRC 19
`define JnzRC 20
`define CallR 21
`define Ret 22
`define RCallRC 23
`define RRet 24
`define AddRRC 25
`define AddRRR 26
`define SubRRC 27
`define SubRRR 28
`define MulAddRRC 29
`define IncR 30
`define DecR 31
`define ShlRRR 32
`define ShrRRR 33
`define FaddRRR 34
`define FsubRR 35
`define FconvR 36
`define FmulRRR 37
`define FdivRR 38
`define FmuladdRRR 39
`define FminRR 40
`define FmaxRR 41
`define VfaddRRR 42
`define DoutR 43
`define Stall 44

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


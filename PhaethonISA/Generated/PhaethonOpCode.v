`define MovRR 1
`define MovRC 2
`define MovRdR 3
`define MovRdRo 4
`define MovRdC 5
`define MovdCR 6
`define MovdRoR 7
`define PushR 8
`define PopR 9
`define CmpRR 10
`define CmpRC 11
`define CmpERRR 12
`define CmpNeRRR 13
`define JmpC 14
`define JneC 15
`define JeC 16
`define JzRC 17
`define JnzRC 18
`define CallR 19
`define Ret 20
`define RCallRC 21
`define RRet 22
`define AddRRC 23
`define AddRRR 24
`define SubRRC 25
`define SubRRR 26
`define MulAddRRC 27
`define IncR 28
`define DecR 29
`define FaddRRR 30
`define FsubRR 31
`define FconvR 32
`define FmulRRR 33
`define FdivRR 34
`define FmuladdRRR 35
`define FminRR 36
`define FmaxRR 37
`define VfaddRRR 38
`define DoutR 39
`define Stall 40

function [0:0] Is8ByteOpcode;
  input [7:0] opCodeParam;
  if (opCodeParam == `MovRC ||
      opCodeParam == `MovRdRo ||
      opCodeParam == `MovRdC ||
      opCodeParam == `MovdCR ||
      opCodeParam == `MovdRoR ||
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
      opCodeParam == `MovRdC ||
      opCodeParam == `MovdCR ||
      opCodeParam == `MovdRoR ||
      opCodeParam == `PushR ||
      opCodeParam == `PopR ||
      opCodeParam == `CallR ||
      opCodeParam == `Ret)
    IsRAMOpcode = 1;
  else
    IsRAMOpcode = 0;
endfunction


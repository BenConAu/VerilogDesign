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
`define JmpC 13
`define JneC 14
`define JeC 15
`define JzRC 16
`define JnzRC 17
`define CallR 18
`define Ret 19
`define RCallRC 20
`define RRet 21
`define AddRRC 22
`define AddRRR 23
`define SubRRC 24
`define SubRRR 25
`define MulAddRRC 26
`define IncR 27
`define DecR 28
`define FaddRRR 29
`define FsubRR 30
`define FconvR 31
`define FmulRRR 32
`define FdivRR 33
`define FmuladdRRR 34
`define FminRR 35
`define FmaxRR 36
`define VfaddRRR 37
`define DoutR 38
`define Stall 39

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


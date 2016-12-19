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
`define JmpC 12
`define JneC 13
`define JeC 14
`define CallR 15
`define Ret 16
`define RCallRC 17
`define RRet 18
`define AddRRC 19
`define AddRRR 20
`define SubRRC 21
`define SubRRR 22
`define MulAddRRC 23
`define IncR 24
`define DecR 25
`define FaddRRR 26
`define FsubRR 27
`define FconvR 28
`define FmulRRR 29
`define FdivRR 30
`define FmuladdRRR 31
`define FminRR 32
`define FmaxRR 33
`define VfaddRRR 34
`define DoutR 35
`define Stall 36

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


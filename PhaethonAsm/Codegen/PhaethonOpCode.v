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
`define CallR 14
`define Ret 15
`define AddRC 16
`define MulAddRRC 17
`define IncR 18
`define DecR 19
`define FaddRR 20
`define FsubRR 21
`define FconvR 22
`define FmulRR 23
`define FdivRR 24
`define FmuladdRRR 25
`define FminRR 26
`define FmaxRR 27
`define VfaddRR 28
`define DoutR 29

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
      opCodeParam == `AddRC ||
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


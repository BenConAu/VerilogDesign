`define MovRC 1
`define MovRcA 2
`define MovRR 3
`define MovcAR 4
`define MovRrAC 5
`define MovrACR 6
`define MovRrA 7
`define PushR 8
`define PopR 9
`define CmpRR 10
`define CmpRC 11
`define JmpC 12
`define JneC 13
`define JnzC 14
`define CallR 15
`define Ret 16
`define AddRC 17
`define MulAddRRC 18
`define IncR 19
`define DecR 20
`define FaddRR 21
`define FsubRR 22
`define FconvR 23
`define FmulRR 24
`define FmuladdRRR 25
`define FminRR 26
`define FmaxRR 27
`define VfaddRR 28
`define DoutR 29

function [0:0] Is8ByteOpcode;
  input [7:0] opCodeParam;
  if (opCodeParam == `MovRC ||
      opCodeParam == `MovRcA ||
      opCodeParam == `MovcAR ||
      opCodeParam == `MovRrAC ||
      opCodeParam == `MovrACR ||
      opCodeParam == `CmpRC ||
      opCodeParam == `JmpC ||
      opCodeParam == `JneC ||
      opCodeParam == `JnzC ||
      opCodeParam == `AddRC ||
      opCodeParam == `MulAddRRC)
    Is8ByteOpcode = 1;
  else
    Is8ByteOpcode = 0;
endfunction

function [0:0] IsRAMOpcode;
  input [7:0] opCodeParam;
  if (opCodeParam == `MovRcA ||
      opCodeParam == `MovcAR ||
      opCodeParam == `MovRrAC ||
      opCodeParam == `MovrACR ||
      opCodeParam == `MovRrA ||
      opCodeParam == `PushR ||
      opCodeParam == `PopR ||
      opCodeParam == `CallR ||
      opCodeParam == `Ret)
    IsRAMOpcode = 1;
  else
    IsRAMOpcode = 0;
endfunction


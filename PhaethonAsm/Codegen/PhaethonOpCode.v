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
`define CallR 14
`define Ret 15
`define AddRC 16
`define IncR 17
`define DecR 18
`define FaddRR 19
`define FsubRR 20
`define FconvR 21
`define FmulRR 22
`define FmuladdRRR 23
`define FminRR 24
`define FmaxRR 25
`define DoutR 26

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
      opCodeParam == `AddRC)
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


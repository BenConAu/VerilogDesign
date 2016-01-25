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
`define AddRC 14
`define IncR 15
`define DecR 16
`define FaddRR 17
`define FsubRR 18
`define FconvR 19
`define FmulRR 20
`define FmuladdRRR 21
`define FminRR 22
`define FmaxRR 23
`define DoutR 24

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
      opCodeParam == `PopR)
    IsRAMOpcode = 1;
  else
    IsRAMOpcode = 0;
endfunction


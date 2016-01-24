`define MovRC 1
`define MovRcA 2
`define MovRR 3
`define MovcAR 4
`define MovRrAC 5
`define MovrACR 6
`define MovRrA 7
`define CmpRR 8
`define CmpRC 9
`define JmpC 10
`define JneC 11
`define AddRC 12
`define IncR 13
`define DecR 14
`define FaddRR 15
`define FsubRR 16
`define FconvR 17
`define FmulRR 18
`define FmuladdRRR 19
`define FminRRR 20
`define FmaxRRR 21
`define DoutR 22

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
      opCodeParam == `MovRrA)
    IsRAMOpcode = 1;
  else
    IsRAMOpcode = 0;
endfunction


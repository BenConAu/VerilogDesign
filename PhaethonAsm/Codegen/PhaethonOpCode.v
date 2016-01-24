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
`define DecR 13
`define FaddRR 14
`define FsubRR 15
`define FconvR 16
`define FmulRR 17
`define FmuladdRRR 18
`define FminRRR 19
`define FmaxRRR 20
`define DoutR 21

function [0:0] Is8ByteOpcode;
  input [7:0] opCodeParam;
  if (opCodeParam == MovRC,
      opCodeParam == MovRcA,
      opCodeParam == MovcAR,
      opCodeParam == MovRrAC,
      opCodeParam == MovrACR,
      opCodeParam == CmpRC,
      opCodeParam == JmpC,
      opCodeParam == JneC,
      opCodeParam == AddRC)
    Is8ByteOpcode = 1;
  else
    Is8ByteOpcode = 0;
endfunction

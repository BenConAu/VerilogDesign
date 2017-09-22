all: UARTReceive.sv UARTReceive_TB.sv UARTReceive_TB.result

%.sv : %.vs ../../VSharpC
	../../VSharpC $<

UARTReceive_TB.result : UARTReceive.sv UARTReceive_TB.sv ../../VSharpC
	iverilog -o temp.vvpo UARTReceive.sv UARTReceive_TB.sv
	vvp temp.vvpo > $@


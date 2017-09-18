all: MemoryController.sv PhysicalRAM.sv MMU_tb.sv MMU_tb.result

%.sv : %.vs ../../VSharpC
	../../VSharpC $<

MMU_tb.result : MemoryController.sv PhysicalRAM.sv MMU_tb.sv ../../VSharpC
	iverilog -o MMU_tb.vvpo MemoryController.sv PhysicalRAM.sv MMU_tb.sv
	vvp MMU_tb.vvpo > $@


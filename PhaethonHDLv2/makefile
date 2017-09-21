all: MemoryController.sv CPU.sv ControlUnit.sv CPU.vvpo

%.sv : %.vs ../VSharp/VSharpC
	../VSharp/VSharpC $<

CPU.vvpo : MemoryController.sv CPU.sv ControlUnit.sv Verilog/FloatingAdd.sv ../VSharp/VSharpC
	iverilog -o CPU.vvpo MemoryController.sv CPU.sv Verilog/FloatingAdd.sv ControlUnit.sv


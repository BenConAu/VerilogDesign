all: MemoryController.sv CPU.sv ControlUnit.sv CPU.vvpo

%.sv : %.vs ../VSharp/VSharpC
	../VSharp/VSharpC $<

CPU.vvpo : TestBench/PhysicalRAM.sv MemoryController.sv CPU.sv CPU_tb.sv ControlUnit.sv StagedFloatingAdder.sv ../VSharp/VSharpC
	iverilog -Wall -o CPU_tb.vvpo TestBench/PhysicalRAM.sv MemoryController.sv CPU_tb.sv CPU.sv StagedFloatingAdder.sv ControlUnit.sv


default: PhysicalRAM.sv \
	AdderTestBench.sv \
	StagedFloatingAdder.sv \
	StagedFloatingDivide.sv \
	../CPU.sv \
	../MemoryController.sv \
	../ControlUnit.sv \
	CPU_tb.vvpo \
	AdderTestBench.vvpo \
	AdderTestBench.result

%.sv: \
	../StagedFloatingAdder.vs \
	../StagedFloatingDivide.vs \
	../FloatingHelper.vs \
	../CPU.vs \
	../MemoryController.vs \
	../ControlUnit.vs \
    AdderTestBench.vs \
	PhysicalRAM.vs \
	CPU_tb.vs
	../../VSharp/VSharpC AdderTestBench.vs
	../../VSharp/VSharpC PhysicalRAM.vs
	../../VSharp/VSharpC ../StagedFloatingAdder.vs
	../../VSharp/VSharpC ../StagedFloatingDivide.vs
	../../VSharp/VSharpC ../CPU.vs
	../../VSharp/VSharpC ../MemoryController.vs
	../../VSharp/VSharpC ../ControlUnit.vs
	../../VSharp/VSharpC CPU_tb.vs

CPU_tb.vvpo: \
	../MemoryController.sv \
	../CPU.sv \
	../ControlUnit.sv \
	../StagedFloatingAdder.sv \
	../StagedFloatingDivide.sv \
	PhysicalRAM.sv \
	CPU_tb.sv \
	../../VSharp/VSharpC
	iverilog -Wall -o CPU_tb.vvpo \
	../MemoryController.sv \
	../CPU.sv \
	../ControlUnit.sv \
	../StagedFloatingAdder.sv \
	../StagedFloatingDivide.sv \
	PhysicalRAM.sv \
	CPU_tb.sv

AdderTestBench.vvpo: \
	AdderTestBench.sv \
	StagedFloatingAdder.sv
	iverilog -o AdderTestBench.vvpo AdderTestBench.sv ../StagedFloatingAdder.sv

AdderTestBench.result: \
	AdderTestBench.vvpo
	vvp AdderTestBench.vvpo > AdderTestBench.result

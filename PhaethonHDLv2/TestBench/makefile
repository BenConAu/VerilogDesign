default: AdderTestBench.sv StagedFloatingAdder.sv CPU.sv CPU_tb.vvpo AdderTestBench.vvpo AdderTestBench.result

%.sv: \
	../StagedFloatingAdder.vs \
	../FloatingHelper.vs \
	../CPU.vs \
    AdderTestBench.vs \
	CPU_tb.vs
	../../VSharp/VSharpC AdderTestBench.vs
	../../VSharp/VSharpC ../StagedFloatingAdder.vs
	../../VSharp/VSharpC ../CPU.vs
	../../VSharp/VSharpC CPU_tb.vs

CPU.vvpo: \
	../MemoryController.sv \
	../CPU.sv \
	../ControlUnit.sv \
	../StagedFloatingAdder.sv \
	PhysicalRAM.sv \
	CPU_tb.sv \
	../../VSharp/VSharpC
	iverilog -Wall -o CPU_tb.vvpo \
	../MemoryController.sv \
	../CPU.sv \
	../ControlUnit.sv \
	../StagedFloatingAdder.sv \
	PhysicalRAM.sv \
	CPU_tb.sv

AdderTestBench.vvpo: \
	AdderTestBench.sv \
	StagedFloatingAdder.sv
	iverilog -o AdderTestBench.vvpo AdderTestBench.sv ../StagedFloatingAdder.sv

AdderTestBench.result: \
	AdderTestBench.vvpo
	vvp AdderTestBench.vvpo > AdderTestBench.result

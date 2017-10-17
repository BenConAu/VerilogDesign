default: AdderTestBench.sv StagedFloatingAdder.sv AdderTestBench.vvpo AdderTestBench.result

%.sv: \
    AdderTestBench.vs \
	../StagedFloatingAdder.vs \
	../FloatingHelper.vs
	../../VSharp/VSharpC AdderTestBench.vs
	../../VSharp/VSharpC ../StagedFloatingAdder.vs

AdderTestBench.vvpo: \
	AdderTestBench.sv \
	StagedFloatingAdder.sv
	iverilog -o AdderTestBench.vvpo AdderTestBench.sv StagedFloatingAdder.sv

AdderTestBench.result: \
	AdderTestBench.vvpo
	vvp AdderTestBench.vvpo > AdderTestBench.result

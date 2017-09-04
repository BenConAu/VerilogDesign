all: *.sv *.vvpo *.result

%.sv : %.vs ../VSharpC
	../VSharpC $<

%.result : %.sv ../VSharpC
	iverilog -o temp.vvpo $<
	vvp temp.vvpo > $@


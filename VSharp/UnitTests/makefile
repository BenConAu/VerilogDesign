all: *.sv *.vvpo *.result

%.sv : %.vs ../VSharpC
	../VSharpC $<

%.vvpo : %.sv
	iverilog -o $@ $<

%.result : %.vvpo
	vvp $< > $@

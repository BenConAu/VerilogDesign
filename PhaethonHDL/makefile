default: RingBuffer_tb_4 RingBuffer_tb_4.result RingBuffer_tb_8 RingBuffer_tb_8.result ALU_tb

RingBuffer_tb_4: \
    RingBuffer.sv \
	RingBuffer_tb.sv
	iverilog -DUNITTEST -DBITLENGTH=2 -o RingBuffer_tb_4 \
    RingBuffer.sv \
    RingBuffer_tb.sv

RingBuffer_tb_4.result: \
    RingBuffer_tb_4
	vvp RingBuffer_tb_4 > RingBuffer_tb_4.result

RingBuffer_tb_8: \
    RingBuffer.sv \
	RingBuffer_tb.sv
	iverilog -DUNITTEST -DBITLENGTH=3 -o RingBuffer_tb_8 \
    RingBuffer.sv \
    RingBuffer_tb.sv

RingBuffer_tb_8.result: \
    RingBuffer_tb_8
	vvp RingBuffer_tb_8 > RingBuffer_tb_8.result

ALU_tb: \
	../PhaethonISA/Generated/PhaethonOpCode.v \
	ALU_tb.sv \
	ALU.sv \
	RingBuffer.sv \
	FloatingAdd.sv \
	FloatingFromInt.sv \
	FloatingMultiply.sv \
	FloatingMultiplyAdd.sv \
	FloatingCompare.sv \
	FloatingDivide.sv \
	MemoryController.sv
	iverilog -o ALU_tb \
	ALU_tb.sv \
	ALU.sv \
	RingBuffer.sv \
	FloatingAdd.sv \
	FloatingFromInt.sv \
	FloatingMultiply.sv \
	FloatingMultiplyAdd.sv \
	FloatingCompare.sv \
	FloatingDivide.sv \
	MemoryController.sv

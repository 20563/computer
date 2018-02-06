CC = gcc --std=c99
LD = ${CC}
ROOT_DIR = $(shell pwd)
TEST_DIR = ${ROOT_DIR}/tests
COMPONENTS_DIR = ${ROOT_DIR}/components
INCDIRS = -I${ROOT_DIR} -I${TEST_DIR} -I${COMPONENTS_DIR}
# override pass additional params through command line
CFLAGS += -c -Wall -pedantic -DCONFIG_USE_STDINT ${INCDIRS}

# -Q Makes the compiler print out each function name
# as it is compiled, and print some statistics about each pass when it finishes.

# -ftime-report Makes the compiler print some statistics
# about the time consumed by each pass when it finishes.

DEBUG = -ggdb -O0
TARGET = alu

TRANSISTOR_ENABLE = ON
AND_ENABLE = ON
OR_ENABLE = ON
NOT_ENABLE = ON
NOR_ENABLE = ON
NAND_ENABLE = ON
LATCH_ENABLE = ON
FLIPFLOP_ENABLE = ON
XOR_ENABLE = ON
ADDER_ENABLE = ON
MULTIPLEXER_ENABLE = ON
TEST_MODE = ON

C_SRC = alu_main.c

ifeq ($(TEST_MODE),ON)
	CFLAGS += -DTEST_MODE
	C_SRC += ${TEST_DIR}/tests.c
endif

ifeq ($(TRANSISTOR_ENABLE),ON)
	CFLAGS += -DTRANSISTOR_ENABLE \
	-DTRANSISTOR_LATENCY=1
	C_SRC += ${COMPONENTS_DIR}/transistor.c
	ifeq ($(TEST_MODE),ON)
		C_SRC += ${TEST_DIR}/transistor_test.c
	endif

	ifeq ($(AND_ENABLE),ON)
		CFLAGS += -DAND_ENABLE
		C_SRC += ${COMPONENTS_DIR}/and_gate.c
		ifeq ($(TEST_MODE),ON)
			C_SRC += ${TEST_DIR}/and_gate_test.c
		endif
	endif

	ifeq ($(OR_ENABLE),ON)
		CFLAGS += -DOR_ENABLE
		C_SRC += ${COMPONENTS_DIR}/or_gate.c
		ifeq ($(TEST_MODE),ON)
			C_SRC += ${TEST_DIR}/or_gate_test.c
		endif
		ifeq ($(XOR_ENABLE),ON)
			ifeq ($(AND_ENABLE),ON)
				CFLAGS += -DXOR_ENABLE
				C_SRC += ${COMPONENTS_DIR}/xor_gate.c
				ifeq ($(TEST_MODE),ON)
					C_SRC += ${TEST_DIR}/xor_gate_test.c
				endif

				ifeq ($(ADDER_ENABLE),ON)
					CFLAGS += -DADDER_ENABLE
					C_SRC += ${ROOT_DIR}/half_adder.c
					C_SRC += ${ROOT_DIR}/full_adder.c
					C_SRC += ${ROOT_DIR}/adder_8bit.c
					ifeq ($(TEST_MODE),ON)
						C_SRC += ${TEST_DIR}/adder_test.c
					endif
				endif
			endif
		endif
	endif

	ifeq ($(NOT_ENABLE),ON)
		CFLAGS += -DNOT_ENABLE
		C_SRC += ${COMPONENTS_DIR}/not_gate.c
		ifeq ($(TEST_MODE),ON)
			C_SRC += ${TEST_DIR}/not_gate_test.c
		endif

		ifeq ($(NOR_ENABLE),ON)
			CFLAGS += -DNOR_ENABLE
			C_SRC += ${COMPONENTS_DIR}/nor_gate.c
			ifeq ($(TEST_MODE),ON)
				C_SRC += ${TEST_DIR}/nor_gate_test.c
			endif
		endif

		ifeq ($(MULTIPLEXER_ENABLE),ON)
			ifeq ($(AND_ENABLE),ON)
				ifeq ($(OR_ENABLE),ON)
					CFLAGS += -DMULTIPLEXER_ENABLE
					C_SRC += ${ROOT_DIR}/multiplexer.c
					ifeq ($(TEST_MODE),ON)
						C_SRC += ${TEST_DIR}/multiplexer_test.c
					endif
				endif
			endif
		endif
	endif

	ifeq ($(NAND_ENABLE),ON)
		CFLAGS += -DNAND_ENABLE
		C_SRC += ${COMPONENTS_DIR}/nand_gate.c
		ifeq ($(TEST_MODE),ON)
			C_SRC += ${TEST_DIR}/nand_gate_test.c
		endif

		ifeq ($(LATCH_ENABLE),ON)
			CFLAGS += -DLATCH_ENABLE
			C_SRC += ${ROOT_DIR}/latch.c
			ifeq ($(TEST_MODE),ON)
				C_SRC += ${TEST_DIR}/latch_test.c
			endif

			ifeq ($(FLIPFLOP_ENABLE),ON)
				CFLAGS += -DFLIPFLOP_ENABLE
				C_SRC += ${ROOT_DIR}/flipflop_rs.c
				ifeq ($(TEST_MODE),ON)
					C_SRC += ${TEST_DIR}/flipflop_test.c
				endif

				ifeq ($(NOT_ENABLE),ON)
					C_SRC += ${ROOT_DIR}/flipflop_d.c
				endif
			endif
		endif
	endif
endif

#OBJECTS = $(patsubst %.c, %.o, $(shell find . -name "*.c"))
OBJECTS = $(patsubst %.c, %.o, $(C_SRC))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(DEBUG) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) $^ -o $@

clean:
	rm -rf $(TARGET) $(OBJECTS)

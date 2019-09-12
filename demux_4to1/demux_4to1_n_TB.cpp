//testbench for the default case where bus is 64bits
#include "Vdemux_4to1_n.h"
#include "verilated.h"

#define ncahnnels 4

struct TestCase {
	const char* name;
    uint64_t in;
    uint8_t sel;
    uint64_t expected_val;
};

TestCase test_cases[] {
  { "In_0x00_Ch1"                   ,0x00                   ,0b00    ,0},
  { "In_0x00_Ch2"                   ,0x00                   ,0b01    ,0},
  { "In_0x00_Ch3"                   ,0x00                   ,0b10    ,0},
  { "In_0x00_Ch4"                   ,0x00                   ,0b11    ,0},
  { "In_0xffffffff_Ch1"             ,0xffffffff             ,0b00    ,0xffffffff},
  { "In_0xffffffff_Ch2"             ,0xffffffff             ,0b01    ,0xffffffff},
  { "In_0xffffffff_Ch3"             ,0xffffffff             ,0b10    ,0xffffffff},
  { "In_0xffffffff_Ch4"             ,0xffffffff             ,0b11    ,0xffffffff},
  { "In_0xffffffffffffffff_Ch1"     ,0xffffffffffffffff     ,0b00    ,0xffffffffffffffff},
  { "In_0xffffffffffffffff_Ch2"     ,0xffffffffffffffff     ,0b01    ,0xffffffffffffffff},
  { "In_0xffffffffffffffff_Ch3"     ,0xffffffffffffffff     ,0b10    ,0xffffffffffffffff},
  { "In_0xffffffffffffffff_Ch4"     ,0xffffffffffffffff     ,0b11    ,0xffffffffffffffff},
};

int main(int argc, char **argv, char **env) {
  Verilated::commandArgs(argc, argv);
  //----------waveform
  //----------
  Vdemux_4to1_n* demux = new Vdemux_4to1_n;
  uint64_t* channels[ncahnnels]={&demux->ch_1,&demux->ch_2,&demux->ch_3,&demux->ch_4};

  demux->sel = 0;
  demux->ch_in = 0;
  demux->eval();
  // while (!Verilated::gotFinish()) { 
  int num_test_cases = sizeof(test_cases)/sizeof(TestCase);

  for(int k = 0; k < num_test_cases; k++) {
    TestCase *test_case = &test_cases[k];
    demux->sel = test_case->sel;
    demux->ch_in = test_case->in;
    demux->eval();
    if (*channels[k%ncahnnels] == test_case->expected_val) {
    	printf("%s: passed\n", test_case->name);
    } else {
    	printf("%s: fail (expected %04X but was %04X)\n",
    		test_case->name, test_case->expected_val,
    		*channels[k%ncahnnels]);
    }
  }
  demux->final();
  delete demux;
exit(0);
}

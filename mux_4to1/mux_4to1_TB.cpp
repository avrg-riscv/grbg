#include "Vmux_4to1.h"
#include "verilated.h"

struct TestCase {
	const char* name;
    uint8_t sel,in;
    bool  expected_val;
};

TestCase test_cases[] {
  { "InHigh_Ch1"    ,0b00    ,0b0001    ,1},
  { "InHigh_Ch2"    ,0b01    ,0b0010    ,1},
  { "InHigh_Ch3"    ,0b10    ,0b0100    ,1},
  { "InHigh_Ch4"    ,0b11    ,0b1000    ,1},
  { "InLow_Ch1"     ,0b00    ,0b1110    ,0},
  { "InLow_Ch2"     ,0b01    ,0b1101    ,0},
  { "InLow_Ch3"     ,0b10    ,0b1011    ,0},
  { "InLow_Ch4"     ,0b11    ,0b0111    ,0},
};

int main(int argc, char **argv, char **env) {
  Verilated::commandArgs(argc, argv);
  
  Vmux_4to1* mux = new Vmux_4to1;
  
  mux->sel = 0;
  mux->in = 0;
  mux->eval();

  // while (!Verilated::gotFinish()) { 
  int num_test_cases = sizeof(test_cases)/sizeof(TestCase);

  for(int k = 0; k < num_test_cases; k++) {
    TestCase *test_case = &test_cases[k];
    
    mux->sel = test_case->sel;
    mux->in = test_case->in;
    mux->eval();

    if (mux->out == test_case->expected_val) {
    	printf("%s: passed\n", test_case->name);
    } else {
    	printf("%s: fail (expected %04X but was %04X)\n",
    		test_case->name, test_case->expected_val,
    		mux->out);
    }
  }
  mux->final();
  delete mux;
exit(0);
}

#include "Vup_counter_64.h"
#include "verilated.h"
//only tested up to 16bit due to time of simulation
#define _UI64_MAX 0xffff

struct TestCase {
	const char* name;
    bool reset,en;
    uint64_t expected_val;
};

TestCase test_cases[] {
  { "disabled"  ,0  ,0  ,0},
  { "reseted"   ,1  ,1  ,0},
  { "enabled"   ,0  ,1  ,_UI64_MAX},
};

int main(int argc, char **argv, char **env) {
  Verilated::commandArgs(argc, argv);
  
  Vup_counter_64* counter = new Vup_counter_64;
  
  counter->clk = 0;
  counter->reset = 0;
  counter->en = 0;
  counter->eval();

  // while (!Verilated::gotFinish()) { 
  int num_test_cases = sizeof(test_cases)/sizeof(TestCase);

  for(int k = 0; k < num_test_cases; k++) {
    TestCase *test_case = &test_cases[k];
    
    counter->en = test_case->en;
    counter->reset = test_case->reset;
    counter->eval();
    
    for(uint64_t i=0;i<_UI64_MAX;i++){
    counter->clk = 1;
    counter->eval();
    counter->clk = 0;
    counter->eval();
    }

    if (counter->out == test_case->expected_val) {
    	printf("%s: passed\n", test_case->name);
    } else {
    	printf("%s: fail (expected %04X but was %04X)\n",
    		test_case->name, test_case->expected_val,
    		counter->out);
    }
  }
  counter->final();
  delete counter;
exit(0);
}

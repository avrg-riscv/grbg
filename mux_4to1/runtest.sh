RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${RED} Modify the script if you need to set your verilator path ${NC}"
#____________start set path verilator
#export TOP=/home/bscuser/BSC/lowrisc
#export VERILATOR_ROOT=$TOP/verilator
#____________end set path verilator
rm -rf obj_dir 
verilator -Wall --cc --trace mux_4to1.sv --exe mux_4to1_TB.cpp -CFLAGS "-std=c++14"
cd obj_dir/
make -f Vmux_4to1.mk 
./Vmux_4to1

RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${RED} Modify the script if you need to set your verilator path ${NC}"
#____________start set path verilator
#export TOP=/home/bscuser/BSC/lowrisc
#export VERILATOR_ROOT=$TOP/verilator
#____________end set path verilator
rm -rf obj_dir 
verilator -Wall --cc --trace demux_4to1_n.sv --exe demux_4to1_n_TB.cpp -CFLAGS "-std=c++14"
cd obj_dir/
make -f Vdemux_4to1_n.mk 
./Vdemux_4to1_n

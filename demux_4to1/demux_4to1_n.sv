//-----------------------------------------------------
// Design Name  : demux_4to1_n
// File Name    : demux_4to1_n.sv
// Function     : 4:1 demux for n bit bus. By default 64 bit.
// Coder        : GCabo
//-----------------------------------------------------
module demux_4to1_n #(
parameter DATA_WIDTH = 64)
(
    output  wire [DATA_WIDTH-1:0]    ch_1   ,// Output channel
    output  wire [DATA_WIDTH-1:0]    ch_2   ,// Output channel
    output  wire [DATA_WIDTH-1:0]    ch_3   ,// Output channel
    output  wire [DATA_WIDTH-1:0]    ch_4   ,// Output channel
    input   wire [DATA_WIDTH-1:0]    ch_in  ,// input channel
    input  wire [1:0]   sel                 // Select output
);

//-------------Code Starts Here-------
always_comb
        case (sel)
            2'b00:begin
                  ch_1=ch_in;
                  //ch_2=Z;
                  //ch_3=Z;
                  //ch_4=Z;
                  end

            2'b01:begin
                  //ch_1=Z;
                  ch_2=ch_in;
                  //ch_3=Z;
                  //ch_4=Z;
                  end

            2'b10:begin
                  //ch_1=Z;
                  //ch_2=Z;
                  ch_3=ch_in;
                  //ch_4=Z;
                  end

            2'b11:begin
                  //ch_1=Z;
                  //ch_2=Z;
                  //ch_3=Z;
                  ch_4=ch_in;
                  end

            default:begin
                  //ch_1=Z;
                  //ch_2=Z;
                  //ch_3=Z;
                  //ch_4=Z;
                  end
        endcase
endmodule 

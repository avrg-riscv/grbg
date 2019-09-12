//-----------------------------------------------------
// Design Name  : mux_4to1
// File Name    : mux_4to1.sv
// Function     : 4:1 Mux
// Coder        : GCabo
//-----------------------------------------------------
module mux_4to1    (
    output wire         out      ,     // Output channel
    input  wire [3:0]   in       ,     // Input channels
    input  wire [1:0]   sel            // Select input
);

//-------------Code Starts Here-------
always_comb
        case (sel)
            2'b00:out=in[0];
            2'b01:out=in[1];
            2'b10:out=in[2];
            2'b11:out=in[3];
            default:out=1;
        endcase
endmodule 

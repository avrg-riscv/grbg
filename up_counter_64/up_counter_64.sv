//-----------------------------------------------------
// Design Name  : up_counter_64
// File Name    : up_counter_64.sv
// Function     : 64bit Up counter with asyncronous reset. Enable must be active in any case
// Coder        : GCabo
//-----------------------------------------------------
module up_counter_64    (
    output reg  [63:0] out     ,    // Output of the counter
    input  wire       clk      ,    // clock input
    input  wire       reset    ,    // reset input
    input  wire       en            // en input
);

//-------------Code Starts Here-------
always_ff @(posedge clk, posedge reset)
    if (reset) begin                // active high reset
      out <= 64'b0 ;
    end else if (en) begin
      out <=out+1;
    end
endmodule 

module PDDW04808
  (
   inout logic       PAD,
   input logic       IE,
   input logic       OE,
   input logic [2:0] DS,
   input logic       I,
   output logic      O
   );

   bufif1 i_tx_buffer(PAD, I, OE);
   assign O = IE ? PAD : 1'b0;

endmodule : PDDW04808

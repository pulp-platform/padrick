module PDDW04808
  (
   inout logic       PAD,
   input logic       IE,
   input logic       OE,
   input logic [2:0] DS,
   input logic       I,
   output logic      O,
   // TB diagnostics signals
   output string     pad_version,
   output logic [2:0] driving_strength
   );

   bufif1 i_tx_buffer(PAD, I, OE);
   assign O = IE ? PAD : 1'b0;

   assign pad_version = "PDDW0408";
   assign driving_strength = DS;

endmodule : PDDW04808


module PDDW04808
  (
   inout logic        PAD,
   input logic        IE,
   input logic        OE,
   input logic [2:0]  DS,
   input logic        I,
   output logic       O,
   // TB diagnostics signals
   output string      pad_version,
   output logic [2:0] driving_strength
   );

   bufif1 i_tx_buffer(PAD, I, OE);
   assign O = IE ? PAD : 1'b0;

   assign pad_version = "PDDW0408";
   assign driving_strength = DS;

endmodule : PDDW04808


module PDLL0206
  (
   inout logic        Z,
   input logic        TXEN,
   input logic        I,
   output logic       O,
   // TB diagnostics signals
   output string      pad_version
   );

   bufif1 i_tx_buffer(Z, I, TXEN);
   assign O = Z;

   assign pad_version = "PDLL0206";

endmodule : PDLL0206


module SUPER_PAD
  (
   inout logic        PAD,
   input logic        IE,
   input logic        OEN,
   input logic [2:0]  DS,
   input logic        PULLD_EN,
   input logic        PULLU_EN,
   input logic        SHMT_EN,
   input logic        I,
   output logic       O,
   // TB diagnostics signals
   output string      pad_version,
   output logic [2:0] driving_strength
   );

   bufif0 i_tx_buffer(PAD, I, OEN);
   assign O = IE ? PAD : 1'b0;

   assign pad_version = "SUPER_PAD";

endmodule

module CRYSTAL_PAD
    (
     inout logic        PAD_A,
     inout logic        PAD_B,
     output logic       O,
     // TB diagnostics signals
     output string      pad_version
     );

   assign O = PAD_A ^ PAD_B;


endmodule

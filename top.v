module top (
    // input signals
    input  wire       A,
    input  wire       B,

    // output signals
    output wire       C
);
    assign C = A&B;
endmodule

/* m0proto_const.h
 */


#ifndef PARROT_M0PROTO_CONST_H_GUARD
#define PARROT_M0PROTO_CONST_H_GUARD

#define M0_REG_COUNT          256

/* &gen_from_enum(m0proto_const.pasm) */
typedef enum {
    M0_CX = 0, /* current context */
    M0_PC,     /* PC */
    M0_EH,     /* currently active exception handler */
    M0_EX,     /* currently thrown exception */
    M0_PCX,    /* calling (a.k.a. parent) context */
    M0_VAR,    /* variables table */
    M0_MDS,    /* metadata segment */
    M0_BCS,    /* bytecode segment */
    M0_I0,
    M0_I1,
    M0_I2,
    M0_I3,
    M0_I4,
    M0_I5,
    M0_I6,
    M0_I7,
    M0_I8,
    M0_I9,
    M0_I10,
    M0_I11,
    M0_I12,
    M0_I13,
    M0_I14,
    M0_I15,
    M0_I16,
    M0_I17,
    M0_I18,
    M0_I19,
    M0_I20,
    M0_I21,
    M0_I22,
    M0_I23,
    M0_I24,
    M0_I25,
    M0_I26,
    M0_I27,
    M0_I28,
    M0_I29,
    M0_I30,
    M0_I31,
    M0_I32,
    M0_I33,
    M0_I34,
    M0_I35,
    M0_I36,
    M0_I37,
    M0_I38,
    M0_I39,
    M0_I40,
    M0_I41,
    M0_I42,
    M0_I43,
    M0_I44,
    M0_I45,
    M0_I46,
    M0_I47,
    M0_I48,
    M0_I49,
    M0_I50,
    M0_I51,
    M0_I52,
    M0_I53,
    M0_I54,
    M0_I55,
    M0_I56,
    M0_I57,
    M0_I58,
    M0_I59,
    M0_I60,
    M0_I61,
    M0_N0,
    M0_N1,
    M0_N2,
    M0_N3,
    M0_N4,
    M0_N5,
    M0_N6,
    M0_N7,
    M0_N8,
    M0_N9,
    M0_N10,
    M0_N11,
    M0_N12,
    M0_N13,
    M0_N14,
    M0_N15,
    M0_N16,
    M0_N17,
    M0_N18,
    M0_N19,
    M0_N20,
    M0_N21,
    M0_N22,
    M0_N23,
    M0_N24,
    M0_N25,
    M0_N26,
    M0_N27,
    M0_N28,
    M0_N29,
    M0_N30,
    M0_N31,
    M0_N32,
    M0_N33,
    M0_N34,
    M0_N35,
    M0_N36,
    M0_N37,
    M0_N38,
    M0_N39,
    M0_N40,
    M0_N41,
    M0_N42,
    M0_N43,
    M0_N44,
    M0_N45,
    M0_N46,
    M0_N47,
    M0_N48,
    M0_N49,
    M0_N50,
    M0_N51,
    M0_N52,
    M0_N53,
    M0_N54,
    M0_N55,
    M0_N56,
    M0_N57,
    M0_N58,
    M0_N59,
    M0_N60,
    M0_N61,
    M0_S0,
    M0_S1,
    M0_S2,
    M0_S3,
    M0_S4,
    M0_S5,
    M0_S6,
    M0_S7,
    M0_S8,
    M0_S9,
    M0_S10,
    M0_S11,
    M0_S12,
    M0_S13,
    M0_S14,
    M0_S15,
    M0_S16,
    M0_S17,
    M0_S18,
    M0_S19,
    M0_S20,
    M0_S21,
    M0_S22,
    M0_S23,
    M0_S24,
    M0_S25,
    M0_S26,
    M0_S27,
    M0_S28,
    M0_S29,
    M0_S30,
    M0_S31,
    M0_S32,
    M0_S33,
    M0_S34,
    M0_S35,
    M0_S36,
    M0_S37,
    M0_S38,
    M0_S39,
    M0_S40,
    M0_S41,
    M0_S42,
    M0_S43,
    M0_S44,
    M0_S45,
    M0_S46,
    M0_S47,
    M0_S48,
    M0_S49,
    M0_S50,
    M0_S51,
    M0_S52,
    M0_S53,
    M0_S54,
    M0_S55,
    M0_S56,
    M0_S57,
    M0_S58,
    M0_S59,
    M0_S60,
    M0_S61,
    M0_P0,
    M0_P1,
    M0_P2,
    M0_P3,
    M0_P4,
    M0_P5,
    M0_P6,
    M0_P7,
    M0_P8,
    M0_P9,
    M0_P10,
    M0_P11,
    M0_P12,
    M0_P13,
    M0_P14,
    M0_P15,
    M0_P16,
    M0_P17,
    M0_P18,
    M0_P19,
    M0_P20,
    M0_P21,
    M0_P22,
    M0_P23,
    M0_P24,
    M0_P25,
    M0_P26,
    M0_P27,
    M0_P28,
    M0_P29,
    M0_P30,
    M0_P31,
    M0_P32,
    M0_P33,
    M0_P34,
    M0_P35,
    M0_P36,
    M0_P37,
    M0_P38,
    M0_P39,
    M0_P40,
    M0_P41,
    M0_P42,
    M0_P43,
    M0_P44,
    M0_P45,
    M0_P46,
    M0_P47,
    M0_P48,
    M0_P49,
    M0_P50,
    M0_P51,
    M0_P52,
    M0_P53,
    M0_P54,
    M0_P55,
    M0_P56,
    M0_P57,
    M0_P58,
    M0_P59,
    M0_P60,
    M0_P61
} m0_reg_consts;
/* &end_gen */



#endif /* PARROT_M0PROTO_CONST_H_GUARD */

/*
 * Local variables:
 *   c-file-style: "parrot"
 * End:
 * vim: expandtab shiftwidth=4 cinoptions='\:2=2' :
 */

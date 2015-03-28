/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/matthias/vex-3.43 -I../include/ -ms -mas_g -mas_t -O2 -fmm=./risc.mm -DVEX -o edge_detect" */

/********************************************/
/*         SYSTEM HEADER                    */
/********************************************/

extern int sim_mem_probe(volatile unsigned int);
extern unsigned int sim_mem_access32(volatile unsigned int);
extern unsigned short sim_mem_access16(volatile unsigned int);
extern unsigned char sim_mem_access8(volatile unsigned int);
extern unsigned long long sim_cycle_counter;
extern unsigned long long sim_stall_counter;
extern unsigned long long sim_branch_stall;
extern unsigned long long sim_bundle_index[];
extern unsigned long long sim_oper_counter;
extern unsigned long long sim_bnt_counter;
extern unsigned long long sim_btc_counter;
extern unsigned long long sim_btu_counter;
extern unsigned long long sim_nop_counter;
extern unsigned int mem_trace_ld(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_st(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_pf(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_lds(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_sts(unsigned int, unsigned int, unsigned int);
extern unsigned int mem_trace_pfs(unsigned int, unsigned int, unsigned int);
extern void sim_ta_init(int);
/*         TRACING HANDLES                */
#define GOTO(x) /**/
#define CALL(x) /**/
#define ENTRY(x) /**/
#define RETURN(x) /**/
#define BRANCH(x) /**/
#define BRANCHF(x) /**/
#define LABEL(x) /**/
#define INC_STALL_CNT() sim_stall_counter += sim_branch_stall
#define INC_BNT_CNT() sim_bnt_counter++
#define INC_BTC_CNT() sim_btc_counter++
#define INC_BTU_CNT() sim_btu_counter++
#define INC_NOP_CNT(n) sim_nop_counter += (n)
#define INC_BUNDLE_CNT(index) sim_bundle_index[index]++
#define ADD_CYCLES(cycles)  sim_cycle_counter += (cycles)

typedef struct
{
  char *name;
  int length;
  int init;
  int offset;
  int linesize;
  int rta;
} sim_fileinfo_t;

extern int sim_init_fileinfo(sim_fileinfo_t *);
extern void sim_icache_fetch(int, int);
extern void sim_gprof_enter(int *, char *f);
extern void sim_gprof_start(int *);
extern void sim_gprof_stop(int *);
extern void sim_gprof_exit(int *);
/***********************************************/
/*         MACHINE MODEL HEADER                */
/***********************************************/

#define UINT8(s)  ((s) & 0xff)
#define INT8(s)   (((int) ((s) << 24)) >> 24)
#define UINT16(s) ((s) & 0xffff)
#define INT16(s)  (((int) ((s) << 16)) >> 16)
#define UINT32(s) ((unsigned int) (s))
#define INT32(s)  ((int) (s))


 		 /*  MEMORY MACROS */

#define ADDR8(a)  ((a) ^ 0x3)
#define ADDR16(a) ((a) ^ 0x2)
#define ADDR32(a) (a)
#define MEM8(a) (*((volatile unsigned char  *)(ADDR8(a))))
#define MEM16(a) (*((volatile unsigned short *)(ADDR16(a))))
#define MEM32(a) (*((volatile unsigned int *)(ADDR32(a))))
#define MEMSPEC8(a) sim_mem_access8(ADDR8(a))
#define MEMSPEC16(a) sim_mem_access16(ADDR16(a))
#define MEMSPEC32(a) sim_mem_access32(ADDR32(a))
#define LDBs(t,s1) t = INT8(MEMSPEC8(s1))
#define LDB(t,s1) t = INT8(MEM8(s1))
#define LDBUs(t,s1) t = UINT8(MEMSPEC8(s1))
#define LDBU(t,s1) t = UINT8(MEM8(s1))
#define LDHs(t,s1) t = INT16(MEMSPEC16(s1))
#define LDH(t,s1) t = INT16(MEM16(s1))
#define LDHUs(t,s1) t = UINT16(MEMSPEC16(s1))
#define LDHU(t,s1) t = UINT16(MEM16(s1))
#define LDWs(t,s1) t = INT32(MEMSPEC32(s1))
#define LDW(t,s1) t = INT32(MEM32(s1))
#define STB(t,s1) MEM8(t) = UINT8(s1)
#define STH(t,s1) MEM16(t) = UINT16(s1)
#define STW(t,s1) MEM32(t) = UINT32(s1)


 		 /*  INSTRUCTION MACROS */

#define MULL(t,s1,s2) t = (s1) * INT16(s2)
#define MULLU(t,s1,s2) t = (s1) * UINT16(s2)
#define MULH(t,s1,s2) t = (s1) * INT16((s2) >> 16)
#define MULHU(t,s1,s2) t = (s1) * UINT16((s2) >> 16)
#define MULHS(t,s1,s2) t = ((s1) * UINT16((s2) >> 16)) << 16
#define MULLL(t,s1,s2)  t = INT16(s1) * INT16(s2)
#define MULLLU(t,s1,s2) t = UINT16(s1) * UINT16(s2)
#define MULLH(t,s1,s2)  t = INT16(s1) * INT16((s2) >> 16)
#define MULLHU(t,s1,s2) t = UINT16(s1) * UINT16((s2) >> 16)
#define MULHH(t,s1,s2)  t = INT16((s1) >> 16) * INT16((s2) >> 16)
#define MULHHU(t,s1,s2) t = UINT16((s1) >> 16) * UINT16((s2) >> 16)
#define ADD(t,s1,s2) t = (s1) + (s2)
#define AND(t,s1,s2) t = (s1) & (s2)
#define ANDC(t,s1,s2) t = ~(s1) & (s2)
#define ANDL(t,s1,s2) t = ((((s1) == 0) | ((s2) == 0)) ? 0 : 1)
#define CMPEQ(t,s1,s2) t = ((s1) == (s2))
#define CMPGE(t,s1,s2) t = ((int) (s1) >= (int) (s2))
#define CMPGEU(t,s1,s2) t = ((unsigned int) (s1) >= (unsigned int) (s2))
#define CMPGT(t,s1,s2) t = ((int) (s1) > (int) (s2))
#define CMPGTU(t,s1,s2) t = ((unsigned int) (s1) > (unsigned int) (s2))
#define CMPLE(t,s1,s2) t = ((int) (s1) <= (int) (s2))
#define CMPLEU(t,s1,s2) t = ((unsigned int) (s1) <= (unsigned int) (s2))
#define CMPLT(t,s1,s2) t = ((int) (s1) < (int) (s2))
#define CMPLTU(t,s1,s2) t = ((unsigned int) (s1) < (unsigned int) (s2))
#define CMPNE(t,s1,s2) t = ( (s1) !=  (s2))
#define MAX(t,s1,s2) t = ((int) (s1) > (int) (s2)) ? (s1) : (s2)
#define MAXU(t,s1,s2) t = ((unsigned int) (s1) > (unsigned int) (s2)) ? (s1) : (s2)
#define MIN(t,s1,s2) t = ((int) (s1) < (int) (s2)) ? (s1) : (s2)
#define MINU(t,s1,s2) t = ((unsigned int) (s1) < (unsigned int) (s2)) ? (s1) : (s2)
#define MFB(t,s1) t = s1
#define MFL(t,s1) t = s1
#define MOV(t,s1) t = s1
#define MTL(t,s1) t = s1
#define MTB(t,s1) t = ((s1) == 0) ? 0 : 1
#define MTBINV(t,s1) t = ((s1) == 0) ? 1 : 0
#define MUL(t,s1,s2) t = (s1) * (s2)
#define NANDL(t,s1,s2) t = (((s1) == 0) | ((s2) == 0)) ? 1 : 0
#define NOP()
#define NORL(t,s1,s2) t = (((s1) == 0) & ((s2) == 0)) ? 1 : 0
#define ORL(t,s1,s2) t = (((s1) == 0) & ((s2) == 0)) ? 0 : 1
#define OR(t,s1,s2) t = (s1) | (s2)
#define ORC(t,s1,s2) t = (~(s1)) | (s2)
#define PFT(s1) (s1)
#define SBIT(t,s1,s2) t = (s1) | ((unsigned int) 1 << (s2))
#define SBITF(t,s1,s2) t = (s1) & ~((unsigned int) 1 << (s2))
#define SH1ADD(t,s1,s2) t = ((s1) << 1) + (s2)
#define SH2ADD(t,s1,s2) t = ((s1) << 2) + (s2)
#define SH3ADD(t,s1,s2) t = ((s1) << 3) + (s2)
#define SH4ADD(t,s1,s2) t = ((s1) << 4) + (s2)
#define SHL(t,s1,s2) t = ((int) (s1)) << (s2)
#define SHR(t,s1,s2) t = ((int) (s1)) >> (s2)
#define SHRU(t,s1,s2) t = ((unsigned int) (s1)) >> (s2)
#define SLCT(t,s1,s2,s3) t = (unsigned int) (((s1) != 0) ? (s2) : (s3))
#define SLCTF(t,s1,s2,s3) t = (unsigned int) (((s1) == 0) ? (s2) : (s3))
#define SUB(t,s1,s2) t = (s1) - (s2)
#define SXTB(t,s1) t = (unsigned int) (((signed int) ((s1) << 24)) >> 24)
#define SXTH(t,s1) t = (unsigned int) (((signed int) ((s1) << 16)) >> 16)
#define TBIT(t,s1,s2) t = ((s1) & ((unsigned int) 1 << (s2))) ? 1 : 0
#define TBITF(t,s1,s2) t = ((s1) & ((unsigned int) 1 << (s2))) ? 0 : 1
#define XNOP(s1)
#define XOR(t,s1,s2) t = (s1) ^ (s2)
#define ZXTB(t,s1) t = ((s1) & 0xff)
#define ZXTH(t,s1) t = ((s1) & 0xffff)
#define ADDCG(t,cout,s1,s2,cin) {\
    t = (s1) + (s2) + ((cin) & 0x1);\
    cout =   ((cin) & 0x1)\
           ? ((unsigned int) t <= (unsigned int) (s1))\
           : ((unsigned int) t <  (unsigned int) (s1));\
}
#define DIVS(t,cout,s1,s2,cin) {\
    unsigned int tmp = ((s1) << 1) | (cin);\
    cout = (unsigned int) (s1) >> 31;\
    t = cout ? tmp + (s2) : tmp - (s2);\
}
static sim_fileinfo_t t_thisfile;
extern void sim_asm_op0(int, ...);
extern unsigned int sim_asm_op1(int, ...);
typedef struct { unsigned int n0,n1; } sim_asm2_t;
extern sim_asm2_t sim_asm_op2(int, ...);
typedef struct { unsigned int n0,n1,n2; } sim_asm3_t;
extern sim_asm3_t sim_asm_op3(int, ...);
typedef struct { unsigned int n0,n1,n2,n3; } sim_asm4_t;
extern sim_asm4_t sim_asm_op4(int, ...);

/*********************************
            BSS SYMBOLS
*********************************/

unsigned int qt[1575000];
unsigned int qy2[1575000];
unsigned int qy1[1575000];
unsigned int t[1575000];
unsigned int y2[1575000];
unsigned int y1[1575000];

/*********************************
            ENTRY SYMBOLS
*********************************/

extern  deriche_float( unsigned int, unsigned int );
extern  deriche_fused( unsigned int, unsigned int );
extern  deriche_slow( unsigned int, unsigned int );
extern  _r_ilfloat(  );
extern  _r_ufloat(  );
extern  _r_ufix(  );
extern  _r_mul(  );
extern  _r_add(  );

/*********************************
            DATA SYMBOLS
*********************************/

extern unsigned int out[];
extern unsigned int in[];

/*********************************
            TEXT
*********************************/
extern unsigned int sim_create_stack(unsigned int, unsigned int);
extern void sim_check_stack(unsigned int, unsigned int);
extern void sim_bad_label(int);
extern unsigned int reg_b0_0;
extern unsigned int reg_b0_1;
extern unsigned int reg_b0_2;
extern unsigned int reg_b0_3;
extern unsigned int reg_b0_4;
extern unsigned int reg_b0_5;
extern unsigned int reg_l0_0;
extern unsigned int reg_r0_0;
extern unsigned int reg_r0_1;
extern unsigned int reg_r0_2;
extern unsigned int reg_r0_3;
extern unsigned int reg_r0_4;
extern unsigned int reg_r0_5;
extern unsigned int reg_r0_6;
extern unsigned int reg_r0_7;
extern unsigned int reg_r0_8;
extern unsigned int reg_r0_9;
extern unsigned int reg_r0_10;
extern unsigned int reg_r0_11;
extern unsigned int reg_r0_12;
extern unsigned int reg_r0_13;
extern unsigned int reg_r0_14;
extern unsigned int reg_r0_15;
extern unsigned int reg_r0_16;
extern unsigned int reg_r0_17;
extern unsigned int reg_r0_18;
extern unsigned int reg_r0_19;
extern unsigned int reg_r0_20;
extern unsigned int reg_r0_21;
extern unsigned int reg_r0_22;
extern unsigned int reg_r0_23;
extern unsigned int reg_r0_24;
extern unsigned int reg_r0_25;
extern unsigned int reg_r0_26;
extern unsigned int reg_r0_27;
extern unsigned int reg_r0_57;
extern unsigned int reg_r0_58;
extern unsigned int reg_r0_59;
extern unsigned int reg_r0_60;
extern unsigned int reg_r0_61;
extern unsigned int reg_r0_62;
extern unsigned int reg_r0_63;


extern  deriche_float( unsigned int arg0, unsigned int arg1 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   ENTRY(deriche_float);
  sim_check_stack(reg_r0_1, -192); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (198 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(0 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_1, reg_r0_1, (unsigned int) -192); /* line 19 */
} /* line 19 */
  sim_icache_fetch(1 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 21 */
} /* line 21 */
  sim_icache_fetch(2 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 140),0,4), reg_r0_57); /* line 23 */
} /* line 23 */
  sim_icache_fetch(3 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 144),0,4), reg_r0_58); /* line 25 */
} /* line 25 */
  sim_icache_fetch(4 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 148),0,4), reg_r0_59); /* line 27 */
} /* line 27 */
  sim_icache_fetch(5 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 152),0,4), reg_r0_60); /* line 29 */
} /* line 29 */
  sim_icache_fetch(6 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 156),0,4), reg_r0_61); /* line 31 */
} /* line 31 */
  sim_icache_fetch(7 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 160),0,4), reg_r0_62); /* line 33 */
} /* line 33 */
  sim_icache_fetch(8 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 164),0,4), reg_r0_63); /* line 35 */
} /* line 35 */
  sim_icache_fetch(9 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 128),0,4), reg_r0_3); /* line 37 */
} /* line 37 */
  sim_icache_fetch(10 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, 0, reg_r0_3); /* line 39 */
} /* line 39 */
  sim_icache_fetch(11 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_3); /* line 41 */
} /* line 41 */
  sim_icache_fetch(12 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, (unsigned int) in); /* line 43 */
} /* line 43 */
  sim_icache_fetch(14 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_4); /* line 45 */
} /* line 45 */
  sim_icache_fetch(15 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) y1); /* line 47 */
} /* line 47 */
l_L0X3: ;/* line 50 */
LABEL(l_L0X3);
  sim_icache_fetch(17 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 51 */
} /* line 51 */
  sim_icache_fetch(18 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 96),0,4), reg_r0_3); /* line 53 */
} /* line 53 */
  sim_icache_fetch(19 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 100),0,4), reg_r0_4); /* line 55 */
} /* line 55 */
  sim_icache_fetch(20 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 104),0,4), reg_r0_5); /* line 57 */
} /* line 57 */
  sim_icache_fetch(21 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 59 */
  sim_icache_fetch(22 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, 0, reg_r0_3); /* line 61 */
} /* line 61 */
  sim_icache_fetch(23 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, reg_r0_3); /* line 63 */
} /* line 63 */
  sim_icache_fetch(24 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_62, reg_r0_4); /* line 65 */
} /* line 65 */
  sim_icache_fetch(25 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, reg_r0_5); /* line 67 */
} /* line 67 */
  sim_icache_fetch(26 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, 0); /* line 69 */
} /* line 69 */
  sim_icache_fetch(27 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, 0); /* line 71 */
} /* line 71 */
  sim_icache_fetch(28 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, 0); /* line 73 */
} /* line 73 */
  sim_icache_fetch(29 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, reg_r0_2); /* line 75 */
} /* line 75 */
l_L2X3: ;/* line 78 */
LABEL(l_L2X3);
  sim_icache_fetch(30 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_57, 0); /* line 79 */
} /* line 79 */
  sim_icache_fetch(31 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 81 */
} /* line 81 */
  sim_icache_fetch(33 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 83 */
  sim_icache_fetch(34 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_58); /* line 85 */
} /* line 85 */
		 /* line 86 */
  sim_icache_fetch(35 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 88 */
l_lr_3: ;/* line 88 */
LABEL(l_lr_3);
  sim_icache_fetch(37 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_3); /* line 90 */
} /* line 90 */
  sim_icache_fetch(38 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, reg_r0_59); /* line 92 */
} /* line 92 */
  sim_icache_fetch(39 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 94 */
} /* line 94 */
  sim_icache_fetch(41 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 96 */
} /* line 96 */
		 /* line 97 */
  sim_icache_fetch(42 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 99 */
l_lr_5: ;/* line 99 */
LABEL(l_lr_5);
  sim_icache_fetch(44 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_3); /* line 101 */
} /* line 101 */
  sim_icache_fetch(45 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1038202178); /* line 103 */
} /* line 103 */
  sim_icache_fetch(47 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_60); /* line 105 */
} /* line 105 */
		 /* line 106 */
  sim_icache_fetch(48 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 108 */
l_lr_7: ;/* line 108 */
LABEL(l_lr_7);
  sim_icache_fetch(50 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 48),0,4), reg_r0_3); /* line 110 */
} /* line 110 */
  sim_icache_fetch(51 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_59, mem_trace_ld(reg_r0_61,0,1)); /* line 112 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 113 */
   ADD_CYCLES(2);
} /* line 113 */
  sim_icache_fetch(53 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 115 */
} /* line 115 */
		 /* line 116 */
  sim_icache_fetch(54 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_ilfloat);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _r_ilfloat;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 118 */
l_lr_9: ;/* line 118 */
LABEL(l_lr_9);
  sim_icache_fetch(56 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1103022629); /* line 120 */
} /* line 120 */
		 /* line 121 */
  sim_icache_fetch(58 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 123 */
l_lr_11: ;/* line 123 */
LABEL(l_lr_11);
  sim_icache_fetch(60 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 52),0,4), reg_r0_3); /* line 125 */
} /* line 125 */
  sim_icache_fetch(61 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 127 */
} /* line 127 */
  sim_icache_fetch(62 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 129 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 130 */
   ADD_CYCLES(1);
} /* line 130 */
		 /* line 131 */
  sim_icache_fetch(64 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 133 */
l_lr_13: ;/* line 133 */
LABEL(l_lr_13);
  sim_icache_fetch(66 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 135 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 136 */
   ADD_CYCLES(1);
} /* line 136 */
		 /* line 137 */
  sim_icache_fetch(68 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 139 */
l_lr_15: ;/* line 139 */
LABEL(l_lr_15);
  sim_icache_fetch(70 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 141 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 142 */
   ADD_CYCLES(1);
} /* line 142 */
		 /* line 143 */
  sim_icache_fetch(72 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 145 */
l_lr_17: ;/* line 145 */
LABEL(l_lr_17);
  sim_icache_fetch(74 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 56),0,4), reg_r0_3); /* line 147 */
} /* line 147 */
  sim_icache_fetch(75 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_62,0,4), reg_r0_3); /* line 149 */
} /* line 149 */
  sim_icache_fetch(76 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 151 */
} /* line 151 */
		 /* line 152 */
  sim_icache_fetch(77 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_ufloat);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _r_ufloat;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 154 */
l_lr_19: ;/* line 154 */
LABEL(l_lr_19);
  sim_icache_fetch(79 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 1); /* line 156 */
} /* line 156 */
  sim_icache_fetch(80 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_62, reg_r0_62, (unsigned int) 4); /* line 158 */
} /* line 158 */
  sim_icache_fetch(81 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 160 */
} /* line 160 */
  sim_icache_fetch(82 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 162 */
} /* line 162 */
  sim_icache_fetch(83 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, reg_r0_3); /* line 164 */
} /* line 164 */
  sim_icache_fetch(84 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L2X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L2X3;
} /* line 166 */
l_L3X3: ;/* line 169 */
LABEL(l_L3X3);
  sim_icache_fetch(85 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 104),0,4)); /* line 170 */
} /* line 170 */
  sim_icache_fetch(86 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 100),0,4)); /* line 172 */
} /* line 172 */
  sim_icache_fetch(87 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_63, (unsigned int) 1); /* line 174 */
} /* line 174 */
  sim_icache_fetch(88 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 1050); /* line 176 */
} /* line 176 */
  sim_icache_fetch(90 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 4200); /* line 178 */
} /* line 178 */
  sim_icache_fetch(92 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 180 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 181 */
   ADD_CYCLES(1);
} /* line 181 */
  sim_icache_fetch(94 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L0X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L0X3;
} /* line 183 */
l_L1X3: ;/* line 186 */
LABEL(l_L1X3);
  sim_icache_fetch(95 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 96),0,4), reg_r0_3); /* line 187 */
} /* line 187 */
  sim_icache_fetch(96 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 189 */
} /* line 189 */
  sim_icache_fetch(97 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, (unsigned int) y2); /* line 191 */
} /* line 191 */
  sim_icache_fetch(99 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_3, (unsigned int) -1); /* line 193 */
} /* line 193 */
  sim_icache_fetch(100 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_7, 0, reg_r0_7); /* line 195 */
} /* line 195 */
  sim_icache_fetch(101 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_7); /* line 197 */
} /* line 197 */
  sim_icache_fetch(102 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) in); /* line 199 */
} /* line 199 */
l_L4X3: ;/* line 202 */
LABEL(l_L4X3);
  sim_icache_fetch(104 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 108),0,4), reg_r0_2); /* line 203 */
} /* line 203 */
  sim_icache_fetch(105 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 112),0,4), reg_r0_4); /* line 205 */
} /* line 205 */
  sim_icache_fetch(106 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 116),0,4), reg_r0_5); /* line 207 */
} /* line 207 */
  sim_icache_fetch(107 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 120),0,4), reg_r0_6); /* line 209 */
} /* line 209 */
  sim_icache_fetch(108 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 211 */
} /* line 211 */
  sim_icache_fetch(109 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_62, reg_r0_4, reg_r0_5); /* line 213 */
} /* line 213 */
  sim_icache_fetch(110 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 215 */
  sim_icache_fetch(111 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_63, reg_r0_5, reg_r0_6); /* line 217 */
} /* line 217 */
  sim_icache_fetch(112 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, 0); /* line 219 */
} /* line 219 */
  sim_icache_fetch(113 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, 0); /* line 221 */
} /* line 221 */
  sim_icache_fetch(114 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, 0); /* line 223 */
} /* line 223 */
  sim_icache_fetch(115 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, 0); /* line 225 */
} /* line 225 */
  sim_icache_fetch(116 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, reg_r0_5); /* line 227 */
} /* line 227 */
l_L6X3: ;/* line 230 */
LABEL(l_L6X3);
  sim_icache_fetch(117 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_57, 0); /* line 231 */
} /* line 231 */
  sim_icache_fetch(118 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 233 */
} /* line 233 */
  sim_icache_fetch(120 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L7X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 235 */
  sim_icache_fetch(121 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_58); /* line 237 */
} /* line 237 */
		 /* line 238 */
  sim_icache_fetch(122 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 240 */
l_lr_25: ;/* line 240 */
LABEL(l_lr_25);
  sim_icache_fetch(124 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_3); /* line 242 */
} /* line 242 */
  sim_icache_fetch(125 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, reg_r0_59); /* line 244 */
} /* line 244 */
  sim_icache_fetch(126 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 246 */
} /* line 246 */
  sim_icache_fetch(128 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 248 */
} /* line 248 */
		 /* line 249 */
  sim_icache_fetch(129 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 251 */
l_lr_27: ;/* line 251 */
LABEL(l_lr_27);
  sim_icache_fetch(131 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_3); /* line 253 */
} /* line 253 */
  sim_icache_fetch(132 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1103022629); /* line 255 */
} /* line 255 */
  sim_icache_fetch(134 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_60); /* line 257 */
} /* line 257 */
		 /* line 258 */
  sim_icache_fetch(135 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 260 */
l_lr_29: ;/* line 260 */
LABEL(l_lr_29);
  sim_icache_fetch(137 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_3); /* line 262 */
} /* line 262 */
  sim_icache_fetch(138 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, reg_r0_61); /* line 264 */
} /* line 264 */
  sim_icache_fetch(139 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1103358174); /* line 266 */
} /* line 266 */
  sim_icache_fetch(141 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_61); /* line 268 */
} /* line 268 */
		 /* line 269 */
  sim_icache_fetch(142 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 271 */
l_lr_31: ;/* line 271 */
LABEL(l_lr_31);
  sim_icache_fetch(144 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 273 */
} /* line 273 */
  sim_icache_fetch(145 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 275 */
} /* line 275 */
  sim_icache_fetch(146 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 277 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 278 */
   ADD_CYCLES(1);
} /* line 278 */
		 /* line 279 */
  sim_icache_fetch(148 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 281 */
l_lr_33: ;/* line 281 */
LABEL(l_lr_33);
  sim_icache_fetch(150 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 283 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 284 */
   ADD_CYCLES(1);
} /* line 284 */
		 /* line 285 */
  sim_icache_fetch(152 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 287 */
l_lr_35: ;/* line 287 */
LABEL(l_lr_35);
  sim_icache_fetch(154 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 289 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 290 */
   ADD_CYCLES(1);
} /* line 290 */
		 /* line 291 */
  sim_icache_fetch(156 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 293 */
l_lr_37: ;/* line 293 */
LABEL(l_lr_37);
  sim_icache_fetch(158 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_3); /* line 295 */
} /* line 295 */
  sim_icache_fetch(159 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_2, mem_trace_ld(reg_r0_62,0,1)); /* line 297 */
} /* line 297 */
  sim_icache_fetch(160 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_63,0,4), reg_r0_3); /* line 299 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 300 */
   ADD_CYCLES(1);
} /* line 300 */
  sim_icache_fetch(162 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_2); /* line 302 */
} /* line 302 */
		 /* line 303 */
  sim_icache_fetch(163 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_ufloat);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _r_ufloat;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 305 */
l_lr_39: ;/* line 305 */
LABEL(l_lr_39);
  sim_icache_fetch(165 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) -1); /* line 307 */
} /* line 307 */
  sim_icache_fetch(166 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_63, reg_r0_63, (unsigned int) -4); /* line 309 */
} /* line 309 */
  sim_icache_fetch(167 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_62, reg_r0_62, (unsigned int) -1); /* line 311 */
} /* line 311 */
  sim_icache_fetch(168 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 313 */
} /* line 313 */
  sim_icache_fetch(169 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, reg_r0_3); /* line 315 */
} /* line 315 */
  sim_icache_fetch(170 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L6X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L6X3;
} /* line 317 */
l_L7X3: ;/* line 320 */
LABEL(l_L7X3);
  sim_icache_fetch(171 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 120),0,4)); /* line 321 */
} /* line 321 */
  sim_icache_fetch(172 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 112),0,4)); /* line 323 */
} /* line 323 */
  sim_icache_fetch(173 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 108),0,4)); /* line 325 */
} /* line 325 */
  sim_icache_fetch(174 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 4200); /* line 327 */
} /* line 327 */
  sim_icache_fetch(176 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 1050); /* line 329 */
} /* line 329 */
  sim_icache_fetch(178 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 331 */
} /* line 331 */
  sim_icache_fetch(179 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 116),0,4)); /* line 333 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 334 */
   ADD_CYCLES(1);
} /* line 334 */
  sim_icache_fetch(181 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L4X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L4X3;
} /* line 336 */
l_L5X3: ;/* line 339 */
LABEL(l_L5X3);
  sim_icache_fetch(182 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 340 */
} /* line 340 */
  sim_icache_fetch(183 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, (unsigned int) t); /* line 342 */
} /* line 342 */
  sim_icache_fetch(185 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, (unsigned int) y1); /* line 344 */
} /* line 344 */
  sim_icache_fetch(187 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_4); /* line 346 */
} /* line 346 */
  sim_icache_fetch(188 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_4); /* line 348 */
} /* line 348 */
  sim_icache_fetch(189 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) y2); /* line 350 */
} /* line 350 */
  sim_icache_fetch(191 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 352 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 353 */
   ADD_CYCLES(1);
} /* line 353 */
  sim_icache_fetch(193 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 354 */
l_L8X3: ;/* line 357 */
LABEL(l_L8X3);
  sim_icache_fetch(194 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 358 */
} /* line 358 */
  sim_icache_fetch(195 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_3); /* line 360 */
} /* line 360 */
  sim_icache_fetch(196 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 362 */
  sim_icache_fetch(197 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, reg_r0_4); /* line 364 */
} /* line 364 */
  sim_icache_fetch(198 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, 0); /* line 366 */
} /* line 366 */
  sim_icache_fetch(199 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_62, reg_r0_2); /* line 368 */
} /* line 368 */
  sim_icache_fetch(200 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, reg_r0_3); /* line 370 */
} /* line 370 */
l_L10X3: ;/* line 373 */
LABEL(l_L10X3);
  sim_icache_fetch(201 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_58); /* line 374 */
} /* line 374 */
  sim_icache_fetch(202 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 376 */
} /* line 376 */
  sim_icache_fetch(203 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_59); /* line 378 */
} /* line 378 */
  sim_icache_fetch(204 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_2,0,4)); /* line 380 */
} /* line 380 */
  sim_icache_fetch(205 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_60, 0); /* line 382 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 383 */
   ADD_CYCLES(1);
} /* line 383 */
  sim_icache_fetch(207 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 385 */
		 /* line 386 */
  sim_icache_fetch(208 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 388 */
l_lr_45: ;/* line 388 */
LABEL(l_lr_45);
  sim_icache_fetch(210 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1065353216); /* line 390 */
} /* line 390 */
		 /* line 391 */
  sim_icache_fetch(212 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 393 */
l_lr_47: ;/* line 393 */
LABEL(l_lr_47);
  sim_icache_fetch(214 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_61); /* line 395 */
} /* line 395 */
  sim_icache_fetch(215 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 397 */
} /* line 397 */
  sim_icache_fetch(216 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 399 */
} /* line 399 */
  sim_icache_fetch(217 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_2,0,4), reg_r0_3); /* line 402 */
} /* line 402 */
  sim_icache_fetch(218 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L10X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L10X3;
} /* line 404 */
l_L11X3: ;/* line 407 */
LABEL(l_L11X3);
  sim_icache_fetch(219 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 4200); /* line 408 */
} /* line 408 */
  sim_icache_fetch(221 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_61, reg_r0_61, reg_r0_4); /* line 410 */
} /* line 410 */
  sim_icache_fetch(222 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_59, reg_r0_59, reg_r0_4); /* line 412 */
} /* line 412 */
  sim_icache_fetch(223 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, reg_r0_4); /* line 414 */
} /* line 414 */
  sim_icache_fetch(224 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_62, (unsigned int) 1); /* line 416 */
} /* line 416 */
  sim_icache_fetch(225 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_63); /* line 419 */
} /* line 419 */
  sim_icache_fetch(226 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L8X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L8X3;
} /* line 421 */
l_L9X3: ;/* line 424 */
LABEL(l_L9X3);
  sim_icache_fetch(227 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 96),0,4), reg_r0_3); /* line 425 */
} /* line 425 */
  sim_icache_fetch(228 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, 0, reg_r0_3); /* line 427 */
} /* line 427 */
  sim_icache_fetch(229 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_3); /* line 429 */
} /* line 429 */
  sim_icache_fetch(230 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, (unsigned int) y1); /* line 431 */
} /* line 431 */
  sim_icache_fetch(232 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_62, (unsigned int) t); /* line 433 */
} /* line 433 */
  sim_icache_fetch(234 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 435 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 436 */
   ADD_CYCLES(1);
} /* line 436 */
  sim_icache_fetch(236 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 437 */
l_L12X3: ;/* line 440 */
LABEL(l_L12X3);
  sim_icache_fetch(237 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 124),0,4), reg_r0_2); /* line 441 */
} /* line 441 */
  sim_icache_fetch(238 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 128),0,4), reg_r0_4); /* line 443 */
} /* line 443 */
  sim_icache_fetch(239 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 445 */
} /* line 445 */
  sim_icache_fetch(240 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_4); /* line 447 */
} /* line 447 */
  sim_icache_fetch(241 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 449 */
  sim_icache_fetch(242 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, reg_r0_4); /* line 451 */
} /* line 451 */
  sim_icache_fetch(243 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, 0); /* line 453 */
} /* line 453 */
  sim_icache_fetch(244 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, 0); /* line 455 */
} /* line 455 */
  sim_icache_fetch(245 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, 0); /* line 457 */
} /* line 457 */
  sim_icache_fetch(246 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, 0); /* line 459 */
} /* line 459 */
l_L14X3: ;/* line 462 */
LABEL(l_L14X3);
  sim_icache_fetch(247 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_57, 0); /* line 463 */
} /* line 463 */
  sim_icache_fetch(248 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 465 */
} /* line 465 */
  sim_icache_fetch(250 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L15X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 467 */
  sim_icache_fetch(251 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_58); /* line 469 */
} /* line 469 */
		 /* line 470 */
  sim_icache_fetch(252 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 472 */
l_lr_53: ;/* line 472 */
LABEL(l_lr_53);
  sim_icache_fetch(254 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 474 */
} /* line 474 */
  sim_icache_fetch(255 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, reg_r0_59); /* line 476 */
} /* line 476 */
  sim_icache_fetch(256 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 478 */
} /* line 478 */
  sim_icache_fetch(258 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 480 */
} /* line 480 */
		 /* line 481 */
  sim_icache_fetch(259 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 483 */
l_lr_55: ;/* line 483 */
LABEL(l_lr_55);
  sim_icache_fetch(261 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 64),0,4), reg_r0_3); /* line 485 */
} /* line 485 */
  sim_icache_fetch(262 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1038202178); /* line 487 */
} /* line 487 */
  sim_icache_fetch(264 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_60); /* line 489 */
} /* line 489 */
		 /* line 490 */
  sim_icache_fetch(265 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 492 */
l_lr_57: ;/* line 492 */
LABEL(l_lr_57);
  sim_icache_fetch(267 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 68),0,4), reg_r0_3); /* line 494 */
} /* line 494 */
  sim_icache_fetch(268 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH3ADD(reg_r0_2, reg_r0_61, reg_r0_62); /* line 496 */
} /* line 496 */
  sim_icache_fetch(269 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld(reg_r0_2,0,4)); /* line 498 */
} /* line 498 */
  sim_icache_fetch(270 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1103022629); /* line 500 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 501 */
   ADD_CYCLES(1);
} /* line 501 */
  sim_icache_fetch(273 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_60); /* line 503 */
} /* line 503 */
		 /* line 504 */
  sim_icache_fetch(274 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 506 */
l_lr_59: ;/* line 506 */
LABEL(l_lr_59);
  sim_icache_fetch(276 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 72),0,4), reg_r0_3); /* line 508 */
} /* line 508 */
  sim_icache_fetch(277 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 510 */
} /* line 510 */
  sim_icache_fetch(278 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 64),0,4)); /* line 512 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 513 */
   ADD_CYCLES(1);
} /* line 513 */
		 /* line 514 */
  sim_icache_fetch(280 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 516 */
l_lr_61: ;/* line 516 */
LABEL(l_lr_61);
  sim_icache_fetch(282 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 518 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 519 */
   ADD_CYCLES(1);
} /* line 519 */
		 /* line 520 */
  sim_icache_fetch(284 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 522 */
l_lr_63: ;/* line 522 */
LABEL(l_lr_63);
  sim_icache_fetch(286 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 72),0,4)); /* line 524 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 525 */
   ADD_CYCLES(1);
} /* line 525 */
		 /* line 526 */
  sim_icache_fetch(288 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 528 */
l_lr_65: ;/* line 528 */
LABEL(l_lr_65);
  sim_icache_fetch(290 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH3ADD(reg_r0_2, reg_r0_61, reg_r0_63); /* line 530 */
} /* line 530 */
  sim_icache_fetch(291 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 525); /* line 532 */
} /* line 532 */
  sim_icache_fetch(293 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 534 */
} /* line 534 */
  sim_icache_fetch(294 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, reg_r0_3); /* line 536 */
} /* line 536 */
  sim_icache_fetch(295 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_2,0,4), reg_r0_3); /* line 539 */
} /* line 539 */
  sim_icache_fetch(296 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L14X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L14X3;
} /* line 541 */
l_L15X3: ;/* line 544 */
LABEL(l_L15X3);
  sim_icache_fetch(297 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_63, reg_r0_63, (unsigned int) 4); /* line 545 */
} /* line 545 */
  sim_icache_fetch(298 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_62, reg_r0_62, (unsigned int) 4); /* line 547 */
} /* line 547 */
  sim_icache_fetch(299 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 124),0,4)); /* line 549 */
} /* line 549 */
  sim_icache_fetch(300 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 551 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 552 */
   ADD_CYCLES(1);
} /* line 552 */
  sim_icache_fetch(302 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 555 */
} /* line 555 */
  sim_icache_fetch(303 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L12X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L12X3;
} /* line 557 */
l_L13X3: ;/* line 560 */
LABEL(l_L13X3);
  sim_icache_fetch(304 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 561 */
} /* line 561 */
  sim_icache_fetch(305 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) t); /* line 563 */
} /* line 563 */
  sim_icache_fetch(307 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 76),0,4), reg_r0_4); /* line 565 */
} /* line 565 */
  sim_icache_fetch(308 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, 0, reg_r0_3); /* line 567 */
} /* line 567 */
  sim_icache_fetch(309 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_3); /* line 569 */
} /* line 569 */
  sim_icache_fetch(310 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, (unsigned int) y2); /* line 571 */
} /* line 571 */
  sim_icache_fetch(312 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 573 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 574 */
   ADD_CYCLES(2);
} /* line 574 */
  sim_icache_fetch(314 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_4, (unsigned int) -1); /* line 576 */
} /* line 576 */
l_L16X3: ;/* line 579 */
LABEL(l_L16X3);
  sim_icache_fetch(315 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 132),0,4), reg_r0_2); /* line 580 */
} /* line 580 */
  sim_icache_fetch(316 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 136),0,4), reg_r0_5); /* line 582 */
} /* line 582 */
  sim_icache_fetch(317 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 584 */
} /* line 584 */
  sim_icache_fetch(318 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULLU(reg_r0_62, reg_r0_5, (unsigned int) 525); /* line 586 */
} /* line 586 */
  sim_icache_fetch(320 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 588 */
  sim_icache_fetch(321 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, 0); /* line 590 */
} /* line 590 */
  sim_icache_fetch(322 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, 0); /* line 592 */
} /* line 592 */
  sim_icache_fetch(323 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, 0); /* line 594 */
} /* line 594 */
  sim_icache_fetch(324 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, 0); /* line 596 */
} /* line 596 */
  sim_icache_fetch(325 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, reg_r0_5); /* line 598 */
} /* line 598 */
l_L18X3: ;/* line 601 */
LABEL(l_L18X3);
  sim_icache_fetch(326 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_57, 0); /* line 602 */
} /* line 602 */
  sim_icache_fetch(327 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 604 */
} /* line 604 */
  sim_icache_fetch(329 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 606 */
  sim_icache_fetch(330 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_58); /* line 608 */
} /* line 608 */
		 /* line 609 */
  sim_icache_fetch(331 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 611 */
l_lr_71: ;/* line 611 */
LABEL(l_lr_71);
  sim_icache_fetch(333 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 80),0,4), reg_r0_3); /* line 613 */
} /* line 613 */
  sim_icache_fetch(334 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, reg_r0_59); /* line 615 */
} /* line 615 */
  sim_icache_fetch(335 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 617 */
} /* line 617 */
  sim_icache_fetch(337 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 619 */
} /* line 619 */
		 /* line 620 */
  sim_icache_fetch(338 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 622 */
l_lr_73: ;/* line 622 */
LABEL(l_lr_73);
  sim_icache_fetch(340 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 84),0,4), reg_r0_3); /* line 624 */
} /* line 624 */
  sim_icache_fetch(341 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1038770187); /* line 626 */
} /* line 626 */
  sim_icache_fetch(343 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_60); /* line 628 */
} /* line 628 */
		 /* line 629 */
  sim_icache_fetch(344 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 631 */
l_lr_75: ;/* line 631 */
LABEL(l_lr_75);
  sim_icache_fetch(346 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 88),0,4), reg_r0_3); /* line 633 */
} /* line 633 */
  sim_icache_fetch(347 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, reg_r0_61); /* line 635 */
} /* line 635 */
  sim_icache_fetch(348 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1103358174); /* line 637 */
} /* line 637 */
  sim_icache_fetch(350 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_61); /* line 639 */
} /* line 639 */
		 /* line 640 */
  sim_icache_fetch(351 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 642 */
l_lr_77: ;/* line 642 */
LABEL(l_lr_77);
  sim_icache_fetch(353 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 92),0,4), reg_r0_3); /* line 644 */
} /* line 644 */
  sim_icache_fetch(354 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 80),0,4)); /* line 646 */
} /* line 646 */
  sim_icache_fetch(355 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 84),0,4)); /* line 648 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 649 */
   ADD_CYCLES(1);
} /* line 649 */
		 /* line 650 */
  sim_icache_fetch(357 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 652 */
l_lr_79: ;/* line 652 */
LABEL(l_lr_79);
  sim_icache_fetch(359 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 88),0,4)); /* line 654 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 655 */
   ADD_CYCLES(1);
} /* line 655 */
		 /* line 656 */
  sim_icache_fetch(361 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 658 */
l_lr_81: ;/* line 658 */
LABEL(l_lr_81);
  sim_icache_fetch(363 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 92),0,4)); /* line 660 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 661 */
   ADD_CYCLES(1);
} /* line 661 */
		 /* line 662 */
  sim_icache_fetch(365 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 664 */
l_lr_83: ;/* line 664 */
LABEL(l_lr_83);
  sim_icache_fetch(367 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH3ADD(reg_r0_4, reg_r0_62, reg_r0_63); /* line 666 */
} /* line 666 */
  sim_icache_fetch(368 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 76),0,4)); /* line 668 */
} /* line 668 */
  sim_icache_fetch(369 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) -1); /* line 670 */
} /* line 670 */
  sim_icache_fetch(370 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, reg_r0_3); /* line 672 */
} /* line 672 */
  sim_icache_fetch(371 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH3ADD(reg_r0_5, reg_r0_62, reg_r0_2); /* line 674 */
} /* line 674 */
  sim_icache_fetch(372 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld(reg_r0_5,0,4)); /* line 676 */
} /* line 676 */
  sim_icache_fetch(373 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_62, reg_r0_62, (unsigned int) -525); /* line 678 */
} /* line 678 */
  sim_icache_fetch(375 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_4,0,4), reg_r0_3); /* line 681 */
} /* line 681 */
  sim_icache_fetch(376 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L18X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L18X3;
} /* line 683 */
l_L19X3: ;/* line 686 */
LABEL(l_L19X3);
  sim_icache_fetch(377 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 76),0,4)); /* line 687 */
} /* line 687 */
  sim_icache_fetch(378 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_63, reg_r0_63, (unsigned int) 4); /* line 689 */
} /* line 689 */
  sim_icache_fetch(379 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 132),0,4)); /* line 691 */
} /* line 691 */
  sim_icache_fetch(380 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, (unsigned int) 4); /* line 693 */
} /* line 693 */
  sim_icache_fetch(381 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 76),0,4), reg_r0_3); /* line 695 */
} /* line 695 */
  sim_icache_fetch(382 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 697 */
} /* line 697 */
  sim_icache_fetch(383 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 136),0,4)); /* line 699 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 700 */
   ADD_CYCLES(1);
} /* line 700 */
  sim_icache_fetch(385 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L16X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L16X3;
} /* line 702 */
l_L17X3: ;/* line 705 */
LABEL(l_L17X3);
  sim_icache_fetch(386 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 706 */
} /* line 706 */
  sim_icache_fetch(387 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, (unsigned int) out); /* line 708 */
} /* line 708 */
  sim_icache_fetch(389 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, (unsigned int) y1); /* line 710 */
} /* line 710 */
  sim_icache_fetch(391 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_4); /* line 712 */
} /* line 712 */
  sim_icache_fetch(392 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_4); /* line 714 */
} /* line 714 */
  sim_icache_fetch(393 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) y2); /* line 716 */
} /* line 716 */
  sim_icache_fetch(395 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 718 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 719 */
   ADD_CYCLES(1);
} /* line 719 */
  sim_icache_fetch(397 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 720 */
l_L20X3: ;/* line 723 */
LABEL(l_L20X3);
  sim_icache_fetch(398 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 724 */
} /* line 724 */
  sim_icache_fetch(399 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_3); /* line 726 */
} /* line 726 */
  sim_icache_fetch(400 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L21X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 728 */
  sim_icache_fetch(401 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, reg_r0_4); /* line 730 */
} /* line 730 */
  sim_icache_fetch(402 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, 0); /* line 732 */
} /* line 732 */
  sim_icache_fetch(403 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_62, reg_r0_2); /* line 734 */
} /* line 734 */
  sim_icache_fetch(404 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, reg_r0_3); /* line 736 */
} /* line 736 */
l_L22X3: ;/* line 739 */
LABEL(l_L22X3);
  sim_icache_fetch(405 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_58); /* line 740 */
} /* line 740 */
  sim_icache_fetch(406 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 742 */
} /* line 742 */
  sim_icache_fetch(407 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_5, reg_r0_57, reg_r0_59); /* line 744 */
} /* line 744 */
  sim_icache_fetch(408 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_5,0,4)); /* line 746 */
} /* line 746 */
  sim_icache_fetch(409 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_60, 0); /* line 748 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 749 */
   ADD_CYCLES(1);
} /* line 749 */
  sim_icache_fetch(411 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L23X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 751 */
		 /* line 752 */
  sim_icache_fetch(412 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 754 */
l_lr_89: ;/* line 754 */
LABEL(l_lr_89);
  sim_icache_fetch(414 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1065353216); /* line 756 */
} /* line 756 */
		 /* line 757 */
  sim_icache_fetch(416 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 759 */
l_lr_91: ;/* line 759 */
LABEL(l_lr_91);
		 /* line 760 */
  sim_icache_fetch(418 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_ufix);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _r_ufix;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 762 */
l_lr_93: ;/* line 762 */
LABEL(l_lr_93);
  sim_icache_fetch(420 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_57, reg_r0_61); /* line 764 */
} /* line 764 */
  sim_icache_fetch(421 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_4, reg_r0_3); /* line 766 */
} /* line 766 */
  sim_icache_fetch(422 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_4, (unsigned int) 25); /* line 768 */
} /* line 768 */
  sim_icache_fetch(423 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_57, reg_r0_61); /* line 770 */
} /* line 770 */
  sim_icache_fetch(424 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 772 */
} /* line 772 */
  sim_icache_fetch(425 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L24X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 774 */
  sim_icache_fetch(426 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 776 */
} /* line 776 */
  sim_icache_fetch(427 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 778 */
} /* line 778 */
  sim_icache_fetch(428 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_5,0,1), 0); /* line 781 */
} /* line 781 */
  sim_icache_fetch(429 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L22X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L22X3;
} /* line 783 */
l_L24X3: ;/* line 786 */
LABEL(l_L24X3);
  sim_icache_fetch(430 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_57, reg_r0_61); /* line 787 */
} /* line 787 */
  sim_icache_fetch(431 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 789 */
} /* line 789 */
  sim_icache_fetch(432 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 791 */
} /* line 791 */
  sim_icache_fetch(433 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 793 */
} /* line 793 */
  sim_icache_fetch(434 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 796 */
} /* line 796 */
  sim_icache_fetch(435 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L22X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L22X3;
} /* line 798 */
l_L23X3: ;/* line 801 */
LABEL(l_L23X3);
  sim_icache_fetch(436 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 1050); /* line 802 */
} /* line 802 */
  sim_icache_fetch(438 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_59, reg_r0_59, (unsigned int) 4200); /* line 804 */
} /* line 804 */
  sim_icache_fetch(440 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 4200); /* line 806 */
} /* line 806 */
  sim_icache_fetch(442 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_62, (unsigned int) 1); /* line 808 */
} /* line 808 */
  sim_icache_fetch(443 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_63); /* line 811 */
} /* line 811 */
  sim_icache_fetch(444 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L20X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L20X3;
} /* line 813 */
l_L21X3: ;/* line 816 */
LABEL(l_L21X3);
  sim_icache_fetch(445 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 817 */
} /* line 817 */
  sim_icache_fetch(446 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 164),0,4)); /* line 819 */
} /* line 819 */
  sim_icache_fetch(447 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 160),0,4)); /* line 821 */
} /* line 821 */
  sim_icache_fetch(448 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 156),0,4)); /* line 823 */
} /* line 823 */
  sim_icache_fetch(449 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 152),0,4)); /* line 825 */
} /* line 825 */
  sim_icache_fetch(450 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 148),0,4)); /* line 827 */
} /* line 827 */
  sim_icache_fetch(451 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 144),0,4)); /* line 829 */
} /* line 829 */
  sim_icache_fetch(452 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 140),0,4)); /* line 831 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 832 */
   ADD_CYCLES(1);
} /* line 832 */
  sim_icache_fetch(454 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_float);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 192; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 835 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 101: goto l_L0X3;
    case 102: goto l_L2X3;
    case 104: goto l_lr_3;
    case 106: goto l_lr_5;
    case 108: goto l_lr_7;
    case 110: goto l_lr_9;
    case 112: goto l_lr_11;
    case 114: goto l_lr_13;
    case 116: goto l_lr_15;
    case 118: goto l_lr_17;
    case 120: goto l_lr_19;
    case 121: goto l_L3X3;
    case 122: goto l_L1X3;
    case 123: goto l_L4X3;
    case 124: goto l_L6X3;
    case 126: goto l_lr_25;
    case 128: goto l_lr_27;
    case 130: goto l_lr_29;
    case 132: goto l_lr_31;
    case 134: goto l_lr_33;
    case 136: goto l_lr_35;
    case 138: goto l_lr_37;
    case 140: goto l_lr_39;
    case 141: goto l_L7X3;
    case 142: goto l_L5X3;
    case 143: goto l_L8X3;
    case 144: goto l_L10X3;
    case 146: goto l_lr_45;
    case 148: goto l_lr_47;
    case 149: goto l_L11X3;
    case 150: goto l_L9X3;
    case 151: goto l_L12X3;
    case 152: goto l_L14X3;
    case 154: goto l_lr_53;
    case 156: goto l_lr_55;
    case 158: goto l_lr_57;
    case 160: goto l_lr_59;
    case 162: goto l_lr_61;
    case 164: goto l_lr_63;
    case 166: goto l_lr_65;
    case 167: goto l_L15X3;
    case 168: goto l_L13X3;
    case 169: goto l_L16X3;
    case 170: goto l_L18X3;
    case 172: goto l_lr_71;
    case 174: goto l_lr_73;
    case 176: goto l_lr_75;
    case 178: goto l_lr_77;
    case 180: goto l_lr_79;
    case 182: goto l_lr_81;
    case 184: goto l_lr_83;
    case 185: goto l_L19X3;
    case 186: goto l_L17X3;
    case 187: goto l_L20X3;
    case 188: goto l_L22X3;
    case 190: goto l_lr_89;
    case 192: goto l_lr_91;
    case 194: goto l_lr_93;
    case 195: goto l_L24X3;
    case 196: goto l_L23X3;
    case 197: goto l_L21X3;
    case 198:
      reg_l0_0 = t_client_rpc;
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern  deriche_fused( unsigned int arg0, unsigned int arg1 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   ENTRY(deriche_fused);
  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (223 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(455 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 853 */
  sim_icache_fetch(456 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 855 */
} /* line 855 */
  sim_icache_fetch(457 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, ((unsigned int) qy2 + (unsigned int) -4)); /* line 857 */
} /* line 857 */
  sim_icache_fetch(459 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_27, reg_r0_3); /* line 859 */
} /* line 859 */
  sim_icache_fetch(460 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_2); /* line 861 */
} /* line 861 */
  sim_icache_fetch(461 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_17, reg_r0_4, (unsigned int) -1); /* line 863 */
} /* line 863 */
  sim_icache_fetch(462 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, ((unsigned int) in + (unsigned int) -1)); /* line 865 */
} /* line 865 */
  sim_icache_fetch(464 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, (unsigned int) in); /* line 867 */
} /* line 867 */
  sim_icache_fetch(466 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, (unsigned int) qy1); /* line 869 */
} /* line 869 */
  sim_icache_fetch(468 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_4); /* line 871 */
} /* line 871 */
l_L25X3: ;/* line 874 */
LABEL(l_L25X3);
  sim_icache_fetch(469 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 875 */
} /* line 875 */
  sim_icache_fetch(470 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_22, (unsigned int) 1, reg_r0_15); /* line 877 */
} /* line 877 */
  sim_icache_fetch(471 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 879 */
  sim_icache_fetch(472 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_22); /* line 881 */
} /* line 881 */
  sim_icache_fetch(473 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_16, reg_r0_17); /* line 883 */
} /* line 883 */
  sim_icache_fetch(474 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_13, reg_r0_17, reg_r0_19); /* line 885 */
} /* line 885 */
  sim_icache_fetch(475 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, 0); /* line 887 */
} /* line 887 */
  sim_icache_fetch(476 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, 0); /* line 889 */
} /* line 889 */
  sim_icache_fetch(477 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, 0); /* line 891 */
} /* line 891 */
  sim_icache_fetch(478 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, 0); /* line 893 */
} /* line 893 */
  sim_icache_fetch(479 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_20); /* line 895 */
} /* line 895 */
  sim_icache_fetch(480 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 897 */
} /* line 897 */
  sim_icache_fetch(481 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 899 */
} /* line 899 */
  sim_icache_fetch(482 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_21); /* line 901 */
} /* line 901 */
  sim_icache_fetch(483 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, 0); /* line 903 */
} /* line 903 */
  sim_icache_fetch(484 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, reg_r0_16); /* line 905 */
} /* line 905 */
  sim_icache_fetch(485 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_25, reg_r0_20); /* line 907 */
} /* line 907 */
  sim_icache_fetch(486 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_3); /* line 909 */
} /* line 909 */
  sim_icache_fetch(487 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_26, reg_r0_21); /* line 911 */
} /* line 911 */
  sim_icache_fetch(488 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, reg_r0_15); /* line 913 */
} /* line 913 */
  sim_icache_fetch(489 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_23, reg_r0_17); /* line 915 */
} /* line 915 */
  sim_icache_fetch(490 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_24, reg_r0_19); /* line 917 */
} /* line 917 */
l_L27X3: ;/* line 920 */
LABEL(l_L27X3);
  sim_icache_fetch(491 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 921 */
} /* line 921 */
  sim_icache_fetch(492 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_4, (unsigned int) 215); /* line 923 */
} /* line 923 */
  sim_icache_fetch(493 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 925 */
} /* line 925 */
  sim_icache_fetch(494 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_16, reg_r0_3, (unsigned int) -48); /* line 927 */
} /* line 927 */
  sim_icache_fetch(495 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 929 */
} /* line 929 */
  sim_icache_fetch(496 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_16, reg_r0_16, reg_r0_15); /* line 931 */
} /* line 931 */
  sim_icache_fetch(497 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 933 */
} /* line 933 */
  sim_icache_fetch(498 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 935 */
} /* line 935 */
  sim_icache_fetch(499 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 937 */
} /* line 937 */
  sim_icache_fetch(500 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_5); /* line 939 */
} /* line 939 */
  sim_icache_fetch(501 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_16); /* line 941 */
} /* line 941 */
  sim_icache_fetch(502 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 943 */
  sim_icache_fetch(503 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) -155); /* line 945 */
} /* line 945 */
  sim_icache_fetch(504 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_10, (unsigned int) -47); /* line 947 */
} /* line 947 */
  sim_icache_fetch(505 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 949 */
} /* line 949 */
  sim_icache_fetch(506 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_9); /* line 951 */
} /* line 951 */
  sim_icache_fetch(507 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_16, reg_r0_11, (unsigned int) 215); /* line 953 */
} /* line 953 */
  sim_icache_fetch(508 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_12, (unsigned int) -48); /* line 955 */
} /* line 955 */
  sim_icache_fetch(509 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 957 */
} /* line 957 */
  sim_icache_fetch(510 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_16); /* line 959 */
} /* line 959 */
  sim_icache_fetch(511 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_12); /* line 961 */
} /* line 961 */
  sim_icache_fetch(512 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_16, mem_trace_ld((reg_r0_14 + (unsigned int) 1),0,1)); /* line 963 */
} /* line 963 */
  sim_icache_fetch(513 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, 0); /* line 965 */
} /* line 965 */
  sim_icache_fetch(514 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_17, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 967 */
} /* line 967 */
  sim_icache_fetch(515 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_18, reg_r0_6, (unsigned int) 215); /* line 969 */
} /* line 969 */
  sim_icache_fetch(516 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 971 */
} /* line 971 */
  sim_icache_fetch(517 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_19, reg_r0_17, (unsigned int) -48); /* line 973 */
} /* line 973 */
  sim_icache_fetch(518 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 975 */
} /* line 975 */
  sim_icache_fetch(519 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_19, reg_r0_19, reg_r0_18); /* line 977 */
} /* line 977 */
  sim_icache_fetch(520 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 979 */
} /* line 979 */
  sim_icache_fetch(521 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 981 */
} /* line 981 */
  sim_icache_fetch(522 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_11, (unsigned int) -155); /* line 983 */
} /* line 983 */
  sim_icache_fetch(523 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 985 */
} /* line 985 */
  sim_icache_fetch(524 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_3, reg_r0_19); /* line 987 */
} /* line 987 */
  sim_icache_fetch(525 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 989 */
} /* line 989 */
  sim_icache_fetch(526 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_16, (unsigned int) -47); /* line 991 */
} /* line 991 */
  sim_icache_fetch(527 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_18, reg_r0_15, (unsigned int) 215); /* line 993 */
} /* line 993 */
  sim_icache_fetch(528 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 995 */
} /* line 995 */
  sim_icache_fetch(529 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 997 */
} /* line 997 */
  sim_icache_fetch(530 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 999 */
} /* line 999 */
  sim_icache_fetch(531 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_19, mem_trace_ld(reg_r0_14,0,1)); /* line 1001 */
} /* line 1001 */
  sim_icache_fetch(532 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_18); /* line 1003 */
} /* line 1003 */
  sim_icache_fetch(533 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_3, reg_r0_10); /* line 1005 */
} /* line 1005 */
  sim_icache_fetch(534 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_15); /* line 1007 */
} /* line 1007 */
  sim_icache_fetch(535 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_16); /* line 1009 */
} /* line 1009 */
  sim_icache_fetch(536 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_6); /* line 1011 */
} /* line 1011 */
  sim_icache_fetch(537 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 2); /* line 1013 */
} /* line 1013 */
  sim_icache_fetch(538 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, (unsigned int) -2); /* line 1015 */
} /* line 1015 */
  sim_icache_fetch(539 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 2); /* line 1017 */
} /* line 1017 */
  sim_icache_fetch(540 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_6); /* line 1019 */
} /* line 1019 */
  sim_icache_fetch(541 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_17); /* line 1021 */
} /* line 1021 */
  sim_icache_fetch(542 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_19); /* line 1023 */
} /* line 1023 */
  sim_icache_fetch(543 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_13 + (unsigned int) 4),0,4), reg_r0_15); /* line 1025 */
} /* line 1025 */
  sim_icache_fetch(544 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1027 */
  sim_icache_fetch(545 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_4); /* line 1029 */
} /* line 1029 */
  sim_icache_fetch(546 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 1031 */
} /* line 1031 */
  sim_icache_fetch(547 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_13,0,4), reg_r0_11); /* line 1033 */
} /* line 1033 */
  sim_icache_fetch(548 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, (unsigned int) -8); /* line 1036 */
} /* line 1036 */
  sim_icache_fetch(549 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L27X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L27X3;
} /* line 1038 */
l_L28X3: ;/* line 1041 */
LABEL(l_L28X3);
  sim_icache_fetch(550 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_19, reg_r0_24, (unsigned int) 4200); /* line 1042 */
} /* line 1042 */
  sim_icache_fetch(552 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_16, reg_r0_22, (unsigned int) 1050); /* line 1044 */
} /* line 1044 */
  sim_icache_fetch(554 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_20); /* line 1046 */
} /* line 1046 */
  sim_icache_fetch(555 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_21); /* line 1048 */
} /* line 1048 */
  sim_icache_fetch(556 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_21, reg_r0_26, (unsigned int) 1050); /* line 1050 */
} /* line 1050 */
  sim_icache_fetch(558 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_20, reg_r0_25, (unsigned int) 4200); /* line 1052 */
} /* line 1052 */
  sim_icache_fetch(560 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, (unsigned int) 1); /* line 1054 */
} /* line 1054 */
  sim_icache_fetch(561 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_23); /* line 1057 */
} /* line 1057 */
  sim_icache_fetch(562 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L25X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L25X3;
} /* line 1059 */
l_L26X3: ;/* line 1062 */
LABEL(l_L26X3);
  sim_icache_fetch(563 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_27); /* line 1063 */
} /* line 1063 */
  sim_icache_fetch(564 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_2); /* line 1065 */
} /* line 1065 */
  sim_icache_fetch(565 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) qy2); /* line 1067 */
} /* line 1067 */
  sim_icache_fetch(567 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, (unsigned int) qy1); /* line 1069 */
} /* line 1069 */
  sim_icache_fetch(569 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, (unsigned int) qt); /* line 1071 */
} /* line 1071 */
  sim_icache_fetch(571 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_15); /* line 1073 */
} /* line 1073 */
l_L29X3: ;/* line 1076 */
LABEL(l_L29X3);
  sim_icache_fetch(572 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 1077 */
} /* line 1077 */
  sim_icache_fetch(573 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_11, (unsigned int) 3, reg_r0_7); /* line 1079 */
} /* line 1079 */
  sim_icache_fetch(574 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L30X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1081 */
  sim_icache_fetch(575 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_11); /* line 1083 */
} /* line 1083 */
  sim_icache_fetch(576 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_8); /* line 1085 */
} /* line 1085 */
  sim_icache_fetch(577 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_9); /* line 1087 */
} /* line 1087 */
  sim_icache_fetch(578 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_10); /* line 1089 */
} /* line 1089 */
  sim_icache_fetch(579 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, reg_r0_3); /* line 1091 */
} /* line 1091 */
  sim_icache_fetch(580 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_7); /* line 1093 */
} /* line 1093 */
  sim_icache_fetch(581 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_8); /* line 1095 */
} /* line 1095 */
  sim_icache_fetch(582 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_9); /* line 1097 */
} /* line 1097 */
  sim_icache_fetch(583 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_10); /* line 1099 */
} /* line 1099 */
l_L31X3: ;/* line 1102 */
LABEL(l_L31X3);
  sim_icache_fetch(584 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 1103 */
} /* line 1103 */
  sim_icache_fetch(585 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld(reg_r0_4,0,4)); /* line 1105 */
} /* line 1105 */
  sim_icache_fetch(586 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 1107 */
} /* line 1107 */
  sim_icache_fetch(587 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 1109 */
} /* line 1109 */
  sim_icache_fetch(588 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_7); /* line 1111 */
} /* line 1111 */
  sim_icache_fetch(589 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 1113 */
} /* line 1113 */
  sim_icache_fetch(590 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 1115 */
} /* line 1115 */
  sim_icache_fetch(591 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1117 */
  sim_icache_fetch(592 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 1119 */
} /* line 1119 */
  sim_icache_fetch(593 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 1121 */
} /* line 1121 */
  sim_icache_fetch(594 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 1123 */
} /* line 1123 */
  sim_icache_fetch(595 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 1125 */
} /* line 1125 */
  sim_icache_fetch(596 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, reg_r0_8); /* line 1127 */
} /* line 1127 */
  sim_icache_fetch(597 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 1129 */
} /* line 1129 */
  sim_icache_fetch(598 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 1131 */
} /* line 1131 */
  sim_icache_fetch(599 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 1133 */
} /* line 1133 */
  sim_icache_fetch(600 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_5, 0); /* line 1135 */
} /* line 1135 */
  sim_icache_fetch(601 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 1137 */
} /* line 1137 */
  sim_icache_fetch(602 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_8); /* line 1139 */
} /* line 1139 */
  sim_icache_fetch(603 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1141 */
} /* line 1141 */
  sim_icache_fetch(604 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1143 */
} /* line 1143 */
  sim_icache_fetch(605 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 1145 */
} /* line 1145 */
  sim_icache_fetch(606 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 1147 */
} /* line 1147 */
  sim_icache_fetch(607 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1149 */
} /* line 1149 */
  sim_icache_fetch(608 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_8); /* line 1151 */
} /* line 1151 */
  sim_icache_fetch(609 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1153 */
} /* line 1153 */
  sim_icache_fetch(610 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1155 */
} /* line 1155 */
  sim_icache_fetch(611 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 1157 */
} /* line 1157 */
  sim_icache_fetch(612 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_6,0,4), reg_r0_3); /* line 1159 */
} /* line 1159 */
  sim_icache_fetch(613 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1161 */
  sim_icache_fetch(614 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 4),0,4), reg_r0_7); /* line 1163 */
} /* line 1163 */
  sim_icache_fetch(615 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1165 */
  sim_icache_fetch(616 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 8),0,4), reg_r0_9); /* line 1167 */
} /* line 1167 */
  sim_icache_fetch(617 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1169 */
  sim_icache_fetch(618 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 12),0,4), reg_r0_10); /* line 1171 */
} /* line 1171 */
  sim_icache_fetch(619 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 1174 */
} /* line 1174 */
  sim_icache_fetch(620 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L31X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L31X3;
} /* line 1176 */
l_L32X3: ;/* line 1179 */
LABEL(l_L32X3);
  sim_icache_fetch(621 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, (unsigned int) 4200); /* line 1180 */
} /* line 1180 */
  sim_icache_fetch(623 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_15, reg_r0_2); /* line 1182 */
} /* line 1182 */
  sim_icache_fetch(624 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_14, reg_r0_2); /* line 1184 */
} /* line 1184 */
  sim_icache_fetch(625 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_13, reg_r0_2); /* line 1186 */
} /* line 1186 */
  sim_icache_fetch(626 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 1188 */
} /* line 1188 */
  sim_icache_fetch(627 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_12); /* line 1191 */
} /* line 1191 */
  sim_icache_fetch(628 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L29X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L29X3;
} /* line 1193 */
l_L30X3: ;/* line 1196 */
LABEL(l_L30X3);
  sim_icache_fetch(629 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_7); /* line 1197 */
} /* line 1197 */
  sim_icache_fetch(630 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_2); /* line 1199 */
} /* line 1199 */
  sim_icache_fetch(631 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, (unsigned int) qt); /* line 1201 */
} /* line 1201 */
  sim_icache_fetch(633 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, (unsigned int) qy1); /* line 1203 */
} /* line 1203 */
  sim_icache_fetch(635 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, ((unsigned int) qy2 + (unsigned int) -4200)); /* line 1205 */
} /* line 1205 */
  sim_icache_fetch(637 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, ((unsigned int) qt + (unsigned int) -4200)); /* line 1207 */
} /* line 1207 */
  sim_icache_fetch(639 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_27, (unsigned int) -1); /* line 1209 */
} /* line 1209 */
  sim_icache_fetch(640 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_27); /* line 1211 */
} /* line 1211 */
  sim_icache_fetch(641 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_25, reg_r0_7); /* line 1213 */
} /* line 1213 */
l_L33X3: ;/* line 1216 */
LABEL(l_L33X3);
  sim_icache_fetch(642 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 1217 */
} /* line 1217 */
  sim_icache_fetch(643 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULLU(reg_r0_21, reg_r0_15, (unsigned int) 4200); /* line 1219 */
} /* line 1219 */
  sim_icache_fetch(645 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L34X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1221 */
  sim_icache_fetch(646 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_16, reg_r0_21); /* line 1223 */
} /* line 1223 */
  sim_icache_fetch(647 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_17, reg_r0_21); /* line 1225 */
} /* line 1225 */
  sim_icache_fetch(648 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_21, (unsigned int) 1, reg_r0_18); /* line 1227 */
} /* line 1227 */
  sim_icache_fetch(649 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_21); /* line 1229 */
} /* line 1229 */
  sim_icache_fetch(650 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, 0); /* line 1231 */
} /* line 1231 */
  sim_icache_fetch(651 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, 0); /* line 1233 */
} /* line 1233 */
  sim_icache_fetch(652 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, 0); /* line 1235 */
} /* line 1235 */
  sim_icache_fetch(653 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, 0); /* line 1237 */
} /* line 1237 */
  sim_icache_fetch(654 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_19); /* line 1239 */
} /* line 1239 */
  sim_icache_fetch(655 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_20); /* line 1241 */
} /* line 1241 */
  sim_icache_fetch(656 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, 0); /* line 1243 */
} /* line 1243 */
  sim_icache_fetch(657 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 1245 */
} /* line 1245 */
  sim_icache_fetch(658 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 1247 */
} /* line 1247 */
  sim_icache_fetch(659 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, reg_r0_17); /* line 1249 */
} /* line 1249 */
  sim_icache_fetch(660 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, reg_r0_18); /* line 1251 */
} /* line 1251 */
  sim_icache_fetch(661 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_3); /* line 1253 */
} /* line 1253 */
  sim_icache_fetch(662 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_23, reg_r0_19); /* line 1255 */
} /* line 1255 */
  sim_icache_fetch(663 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_15); /* line 1257 */
} /* line 1257 */
  sim_icache_fetch(664 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_24, reg_r0_20); /* line 1259 */
} /* line 1259 */
  sim_icache_fetch(665 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_16); /* line 1261 */
} /* line 1261 */
l_L35X3: ;/* line 1264 */
LABEL(l_L35X3);
  sim_icache_fetch(666 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 1265 */
} /* line 1265 */
  sim_icache_fetch(667 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1267 */
} /* line 1267 */
  sim_icache_fetch(668 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_5, (unsigned int) 215); /* line 1269 */
} /* line 1269 */
  sim_icache_fetch(669 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_16, reg_r0_3, (unsigned int) -48); /* line 1271 */
} /* line 1271 */
  sim_icache_fetch(670 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 1273 */
} /* line 1273 */
  sim_icache_fetch(671 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_16); /* line 1275 */
} /* line 1275 */
  sim_icache_fetch(672 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_6); /* line 1277 */
} /* line 1277 */
  sim_icache_fetch(673 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_15); /* line 1279 */
} /* line 1279 */
  sim_icache_fetch(674 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1281 */
} /* line 1281 */
  sim_icache_fetch(675 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 1283 */
} /* line 1283 */
  sim_icache_fetch(676 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) -155); /* line 1285 */
} /* line 1285 */
  sim_icache_fetch(677 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L36X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1287 */
  sim_icache_fetch(678 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_10, (unsigned int) -47); /* line 1289 */
} /* line 1289 */
  sim_icache_fetch(679 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_16, reg_r0_11, (unsigned int) 215); /* line 1291 */
} /* line 1291 */
  sim_icache_fetch(680 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_15); /* line 1293 */
} /* line 1293 */
  sim_icache_fetch(681 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_12, (unsigned int) 29); /* line 1295 */
} /* line 1295 */
  sim_icache_fetch(682 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_15, mem_trace_ld((reg_r0_14 + (unsigned int) 4200),0,4)); /* line 1297 */
} /* line 1297 */
  sim_icache_fetch(684 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_16, reg_r0_16, reg_r0_12); /* line 1299 */
} /* line 1299 */
  sim_icache_fetch(685 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_16); /* line 1301 */
} /* line 1301 */
  sim_icache_fetch(686 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1303 */
} /* line 1303 */
  sim_icache_fetch(687 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, 0); /* line 1305 */
} /* line 1305 */
  sim_icache_fetch(688 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 1307 */
} /* line 1307 */
  sim_icache_fetch(690 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1309 */
} /* line 1309 */
  sim_icache_fetch(691 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_16, reg_r0_4, (unsigned int) 215); /* line 1311 */
} /* line 1311 */
  sim_icache_fetch(692 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_17, reg_r0_6, (unsigned int) -48); /* line 1313 */
} /* line 1313 */
  sim_icache_fetch(693 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 1315 */
} /* line 1315 */
  sim_icache_fetch(694 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_17); /* line 1317 */
} /* line 1317 */
  sim_icache_fetch(695 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_16, reg_r0_16, reg_r0_3); /* line 1319 */
} /* line 1319 */
  sim_icache_fetch(696 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_16); /* line 1321 */
} /* line 1321 */
  sim_icache_fetch(697 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1323 */
} /* line 1323 */
  sim_icache_fetch(698 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_11, (unsigned int) -155); /* line 1325 */
} /* line 1325 */
  sim_icache_fetch(699 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_15, (unsigned int) -47); /* line 1327 */
} /* line 1327 */
  sim_icache_fetch(700 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_16, reg_r0_9, (unsigned int) 215); /* line 1329 */
} /* line 1329 */
  sim_icache_fetch(701 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 1331 */
} /* line 1331 */
  sim_icache_fetch(702 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 1333 */
} /* line 1333 */
  sim_icache_fetch(703 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_14,0,4)); /* line 1335 */
} /* line 1335 */
  sim_icache_fetch(704 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_16, reg_r0_16, reg_r0_10); /* line 1337 */
} /* line 1337 */
  sim_icache_fetch(705 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_16); /* line 1339 */
} /* line 1339 */
  sim_icache_fetch(706 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1341 */
} /* line 1341 */
  sim_icache_fetch(707 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_15); /* line 1343 */
} /* line 1343 */
  sim_icache_fetch(708 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_9); /* line 1345 */
} /* line 1345 */
  sim_icache_fetch(709 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_4); /* line 1347 */
} /* line 1347 */
  sim_icache_fetch(710 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, (unsigned int) -8400); /* line 1349 */
} /* line 1349 */
  sim_icache_fetch(712 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 8400); /* line 1351 */
} /* line 1351 */
  sim_icache_fetch(714 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 2); /* line 1353 */
} /* line 1353 */
  sim_icache_fetch(715 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 1355 */
} /* line 1355 */
  sim_icache_fetch(716 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_16); /* line 1357 */
} /* line 1357 */
  sim_icache_fetch(717 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_13 + (unsigned int) 4200),0,4), reg_r0_9); /* line 1359 */
} /* line 1359 */
  sim_icache_fetch(719 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L36X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1361 */
  sim_icache_fetch(720 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_15); /* line 1363 */
} /* line 1363 */
  sim_icache_fetch(721 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_3); /* line 1365 */
} /* line 1365 */
  sim_icache_fetch(722 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_5); /* line 1367 */
} /* line 1367 */
  sim_icache_fetch(724 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 8400); /* line 1369 */
} /* line 1369 */
  sim_icache_fetch(726 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_13,0,4), reg_r0_11); /* line 1371 */
} /* line 1371 */
  sim_icache_fetch(727 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, (unsigned int) -8400); /* line 1374 */
} /* line 1374 */
  sim_icache_fetch(729 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L35X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L35X3;
} /* line 1376 */
l_L36X3: ;/* line 1379 */
LABEL(l_L36X3);
  sim_icache_fetch(730 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_17, reg_r0_21, (unsigned int) 4); /* line 1380 */
} /* line 1380 */
  sim_icache_fetch(731 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_20); /* line 1382 */
} /* line 1382 */
  sim_icache_fetch(732 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_20, reg_r0_24, (unsigned int) 4); /* line 1384 */
} /* line 1384 */
  sim_icache_fetch(733 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_19); /* line 1386 */
} /* line 1386 */
  sim_icache_fetch(734 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_19, reg_r0_23, (unsigned int) 4); /* line 1388 */
} /* line 1388 */
  sim_icache_fetch(735 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_16, reg_r0_16, (unsigned int) 4); /* line 1390 */
} /* line 1390 */
  sim_icache_fetch(736 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_18, (unsigned int) 1); /* line 1392 */
} /* line 1392 */
  sim_icache_fetch(737 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_22); /* line 1395 */
} /* line 1395 */
  sim_icache_fetch(738 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L33X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L33X3;
} /* line 1397 */
l_L34X3: ;/* line 1400 */
LABEL(l_L34X3);
  sim_icache_fetch(739 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_18, 0, reg_r0_18); /* line 1401 */
} /* line 1401 */
  sim_icache_fetch(740 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_18); /* line 1403 */
} /* line 1403 */
  sim_icache_fetch(741 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, (unsigned int) qy2); /* line 1405 */
} /* line 1405 */
  sim_icache_fetch(743 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) qy1); /* line 1407 */
} /* line 1407 */
  sim_icache_fetch(745 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, (unsigned int) out); /* line 1409 */
} /* line 1409 */
  sim_icache_fetch(747 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_25); /* line 1411 */
} /* line 1411 */
l_L37X3: ;/* line 1414 */
LABEL(l_L37X3);
  sim_icache_fetch(748 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 1415 */
} /* line 1415 */
  sim_icache_fetch(749 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_12, (unsigned int) 3, reg_r0_8); /* line 1417 */
} /* line 1417 */
  sim_icache_fetch(750 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1419 */
  sim_icache_fetch(751 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_12); /* line 1421 */
} /* line 1421 */
  sim_icache_fetch(752 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_9); /* line 1423 */
} /* line 1423 */
  sim_icache_fetch(753 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_9); /* line 1425 */
} /* line 1425 */
  sim_icache_fetch(754 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_10); /* line 1427 */
} /* line 1427 */
  sim_icache_fetch(755 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_11); /* line 1429 */
} /* line 1429 */
  sim_icache_fetch(756 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_3); /* line 1431 */
} /* line 1431 */
  sim_icache_fetch(757 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_8); /* line 1433 */
} /* line 1433 */
  sim_icache_fetch(758 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_9); /* line 1435 */
} /* line 1435 */
  sim_icache_fetch(759 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_10); /* line 1437 */
} /* line 1437 */
  sim_icache_fetch(760 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_11); /* line 1439 */
} /* line 1439 */
l_L39X3: ;/* line 1442 */
LABEL(l_L39X3);
  sim_icache_fetch(761 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 1443 */
} /* line 1443 */
  sim_icache_fetch(762 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_4,0,4)); /* line 1445 */
} /* line 1445 */
  sim_icache_fetch(763 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 1447 */
} /* line 1447 */
  sim_icache_fetch(764 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 1449 */
} /* line 1449 */
  sim_icache_fetch(765 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_8); /* line 1451 */
} /* line 1451 */
  sim_icache_fetch(766 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 1453 */
} /* line 1453 */
  sim_icache_fetch(767 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 1455 */
} /* line 1455 */
  sim_icache_fetch(768 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L40X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1457 */
  sim_icache_fetch(769 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_8, reg_r0_3); /* line 1459 */
} /* line 1459 */
  sim_icache_fetch(770 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_8, (unsigned int) 25); /* line 1461 */
} /* line 1461 */
  sim_icache_fetch(771 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 1463 */
} /* line 1463 */
  sim_icache_fetch(772 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 1465 */
} /* line 1465 */
  sim_icache_fetch(773 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_5, (unsigned int) 1); /* line 1467 */
} /* line 1467 */
  sim_icache_fetch(774 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 1469 */
} /* line 1469 */
  sim_icache_fetch(775 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_8); /* line 1471 */
} /* line 1471 */
  sim_icache_fetch(776 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1473 */
} /* line 1473 */
  sim_icache_fetch(777 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 1475 */
} /* line 1475 */
  sim_icache_fetch(778 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_8, reg_r0_9); /* line 1477 */
} /* line 1477 */
  sim_icache_fetch(779 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_3, reg_r0_8, (unsigned int) 25); /* line 1479 */
} /* line 1479 */
  sim_icache_fetch(780 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 1481 */
} /* line 1481 */
  sim_icache_fetch(781 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_4, reg_r0_5, 0); /* line 1483 */
} /* line 1483 */
  sim_icache_fetch(782 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 1485 */
} /* line 1485 */
  sim_icache_fetch(783 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 1487 */
} /* line 1487 */
  sim_icache_fetch(784 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1489 */
} /* line 1489 */
  sim_icache_fetch(785 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 1491 */
} /* line 1491 */
  sim_icache_fetch(786 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_11, reg_r0_10); /* line 1493 */
} /* line 1493 */
  sim_icache_fetch(787 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_5, reg_r0_11, (unsigned int) 25); /* line 1495 */
} /* line 1495 */
  sim_icache_fetch(788 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 1497 */
} /* line 1497 */
  sim_icache_fetch(789 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_6,0,1), reg_r0_3); /* line 1499 */
} /* line 1499 */
  sim_icache_fetch(790 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L41X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1501 */
  sim_icache_fetch(791 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, reg_r0_12); /* line 1503 */
} /* line 1503 */
  sim_icache_fetch(792 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 1505 */
} /* line 1505 */
  sim_icache_fetch(793 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 1507 */
} /* line 1507 */
  sim_icache_fetch(794 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_3, reg_r0_8); /* line 1509 */
} /* line 1509 */
  sim_icache_fetch(795 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 1511 */
} /* line 1511 */
  sim_icache_fetch(796 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_6,0,1), 0); /* line 1513 */
} /* line 1513 */
l_L42X3: ;/* line 1515 */
LABEL(l_L42X3);
  sim_icache_fetch(797 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L40X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1516 */
  sim_icache_fetch(798 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), reg_r0_9); /* line 1518 */
} /* line 1518 */
  sim_icache_fetch(799 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L43X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1520 */
  sim_icache_fetch(800 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), 0); /* line 1522 */
} /* line 1522 */
l_L44X3: ;/* line 1524 */
LABEL(l_L44X3);
  sim_icache_fetch(801 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L40X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1525 */
  sim_icache_fetch(802 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), reg_r0_10); /* line 1527 */
} /* line 1527 */
  sim_icache_fetch(803 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_5) {    BRANCHF(reg_b0_5);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L45X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1529 */
  sim_icache_fetch(804 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), 0); /* line 1531 */
} /* line 1531 */
l_L46X3: ;/* line 1533 */
LABEL(l_L46X3);
  sim_icache_fetch(805 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_4) {    BRANCHF(reg_b0_4);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L40X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1534 */
  sim_icache_fetch(806 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), reg_r0_8); /* line 1536 */
} /* line 1536 */
  sim_icache_fetch(807 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L47X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1538 */
  sim_icache_fetch(808 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 1540 */
} /* line 1540 */
  sim_icache_fetch(809 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1542 */
} /* line 1542 */
  sim_icache_fetch(810 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1544 */
} /* line 1544 */
  sim_icache_fetch(811 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 1546 */
} /* line 1546 */
  sim_icache_fetch(812 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), 0); /* line 1548 */
} /* line 1548 */
l_L48X3: ;/* line 1550 */
LABEL(l_L48X3);
  sim_icache_fetch(813 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 4); /* line 1552 */
} /* line 1552 */
  sim_icache_fetch(814 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L39X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L39X3;
} /* line 1554 */
l_L47X3: ;/* line 1557 */
LABEL(l_L47X3);
  sim_icache_fetch(815 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 1558 */
} /* line 1558 */
  sim_icache_fetch(816 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 1560 */
} /* line 1560 */
  sim_icache_fetch(817 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1562 */
} /* line 1562 */
  sim_icache_fetch(818 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 1564 */
} /* line 1564 */
  sim_icache_fetch(819 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 3),0,1), reg_r0_3); /* line 1566 */
} /* line 1566 */
  sim_icache_fetch(820 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1569 */
} /* line 1569 */
  sim_icache_fetch(821 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L48X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L48X3;
} /* line 1571 */
l_L40X3: ;/* line 1574 */
LABEL(l_L40X3);
  sim_icache_fetch(822 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4200); /* line 1575 */
} /* line 1575 */
  sim_icache_fetch(824 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 4200); /* line 1577 */
} /* line 1577 */
  sim_icache_fetch(826 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_15, (unsigned int) 1050); /* line 1579 */
} /* line 1579 */
  sim_icache_fetch(828 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 1581 */
} /* line 1581 */
  sim_icache_fetch(829 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_14); /* line 1584 */
} /* line 1584 */
  sim_icache_fetch(830 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L37X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L37X3;
} /* line 1586 */
l_L45X3: ;/* line 1589 */
LABEL(l_L45X3);
  sim_icache_fetch(831 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 1590 */
} /* line 1590 */
  sim_icache_fetch(832 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 2),0,1), reg_r0_3); /* line 1593 */
} /* line 1593 */
  sim_icache_fetch(833 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L46X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L46X3;
} /* line 1595 */
l_L43X3: ;/* line 1598 */
LABEL(l_L43X3);
  sim_icache_fetch(834 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 1599 */
} /* line 1599 */
  sim_icache_fetch(835 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 1),0,1), reg_r0_3); /* line 1602 */
} /* line 1602 */
  sim_icache_fetch(836 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L44X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L44X3;
} /* line 1604 */
l_L41X3: ;/* line 1607 */
LABEL(l_L41X3);
  sim_icache_fetch(837 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 1608 */
} /* line 1608 */
  sim_icache_fetch(838 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, reg_r0_12); /* line 1610 */
} /* line 1610 */
  sim_icache_fetch(839 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 1612 */
} /* line 1612 */
  sim_icache_fetch(840 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 1614 */
} /* line 1614 */
  sim_icache_fetch(841 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_11, reg_r0_8); /* line 1616 */
} /* line 1616 */
  sim_icache_fetch(842 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_11, (unsigned int) 25); /* line 1618 */
} /* line 1618 */
  sim_icache_fetch(843 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_7,0,1), reg_r0_3); /* line 1621 */
} /* line 1621 */
  sim_icache_fetch(844 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L42X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L42X3;
} /* line 1623 */
l_L38X3: ;/* line 1626 */
LABEL(l_L38X3);
  sim_icache_fetch(845 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_fused);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1628 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 199: goto l_L25X3;
    case 200: goto l_L27X3;
    case 201: goto l_L28X3;
    case 202: goto l_L26X3;
    case 203: goto l_L29X3;
    case 204: goto l_L31X3;
    case 205: goto l_L32X3;
    case 206: goto l_L30X3;
    case 207: goto l_L33X3;
    case 208: goto l_L35X3;
    case 209: goto l_L36X3;
    case 210: goto l_L34X3;
    case 211: goto l_L37X3;
    case 212: goto l_L39X3;
    case 213: goto l_L42X3;
    case 214: goto l_L44X3;
    case 215: goto l_L46X3;
    case 216: goto l_L48X3;
    case 217: goto l_L47X3;
    case 218: goto l_L40X3;
    case 219: goto l_L45X3;
    case 220: goto l_L43X3;
    case 221: goto l_L41X3;
    case 222: goto l_L38X3;
    case 223:
      reg_l0_0 = t_client_rpc;
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern  deriche_slow( unsigned int arg0, unsigned int arg1 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   ENTRY(deriche_slow);
  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (260 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(846 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 1643 */
  sim_icache_fetch(847 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 1645 */
} /* line 1645 */
  sim_icache_fetch(848 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, (unsigned int) in); /* line 1647 */
} /* line 1647 */
  sim_icache_fetch(850 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_3); /* line 1649 */
} /* line 1649 */
  sim_icache_fetch(851 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_2); /* line 1651 */
} /* line 1651 */
  sim_icache_fetch(852 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) qy1); /* line 1653 */
} /* line 1653 */
  sim_icache_fetch(854 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_4); /* line 1655 */
} /* line 1655 */
l_L49X3: ;/* line 1658 */
LABEL(l_L49X3);
  sim_icache_fetch(855 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 1659 */
} /* line 1659 */
  sim_icache_fetch(856 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_12, (unsigned int) 3, reg_r0_9); /* line 1661 */
} /* line 1661 */
  sim_icache_fetch(857 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1663 */
  sim_icache_fetch(858 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_12); /* line 1665 */
} /* line 1665 */
  sim_icache_fetch(859 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_10); /* line 1667 */
} /* line 1667 */
  sim_icache_fetch(860 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 1669 */
} /* line 1669 */
  sim_icache_fetch(861 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 1671 */
} /* line 1671 */
  sim_icache_fetch(862 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_11); /* line 1673 */
} /* line 1673 */
  sim_icache_fetch(863 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, 0); /* line 1675 */
} /* line 1675 */
  sim_icache_fetch(864 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_3); /* line 1677 */
} /* line 1677 */
  sim_icache_fetch(865 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_9); /* line 1679 */
} /* line 1679 */
  sim_icache_fetch(866 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_10); /* line 1681 */
} /* line 1681 */
  sim_icache_fetch(867 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_11); /* line 1683 */
} /* line 1683 */
l_L51X3: ;/* line 1686 */
LABEL(l_L51X3);
  sim_icache_fetch(868 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 1687 */
} /* line 1687 */
  sim_icache_fetch(869 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_4, (unsigned int) 215); /* line 1689 */
} /* line 1689 */
  sim_icache_fetch(870 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1691 */
} /* line 1691 */
  sim_icache_fetch(871 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_3, (unsigned int) -48); /* line 1693 */
} /* line 1693 */
  sim_icache_fetch(872 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1695 */
} /* line 1695 */
  sim_icache_fetch(873 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_9); /* line 1697 */
} /* line 1697 */
  sim_icache_fetch(874 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1699 */
} /* line 1699 */
  sim_icache_fetch(875 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 1701 */
} /* line 1701 */
  sim_icache_fetch(876 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 3); /* line 1703 */
} /* line 1703 */
  sim_icache_fetch(877 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_5); /* line 1705 */
} /* line 1705 */
  sim_icache_fetch(878 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 1707 */
} /* line 1707 */
  sim_icache_fetch(879 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1709 */
  sim_icache_fetch(880 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 2); /* line 1711 */
} /* line 1711 */
  sim_icache_fetch(881 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 1713 */
} /* line 1713 */
  sim_icache_fetch(882 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_6, (unsigned int) 215); /* line 1715 */
} /* line 1715 */
  sim_icache_fetch(883 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1717 */
} /* line 1717 */
  sim_icache_fetch(884 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_9, (unsigned int) -48); /* line 1719 */
} /* line 1719 */
  sim_icache_fetch(885 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1721 */
} /* line 1721 */
  sim_icache_fetch(886 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 1723 */
} /* line 1723 */
  sim_icache_fetch(887 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1725 */
} /* line 1725 */
  sim_icache_fetch(888 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 1727 */
} /* line 1727 */
  sim_icache_fetch(889 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_7, (unsigned int) 1); /* line 1729 */
} /* line 1729 */
  sim_icache_fetch(890 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 1731 */
} /* line 1731 */
  sim_icache_fetch(891 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 1733 */
} /* line 1733 */
  sim_icache_fetch(892 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 1735 */
} /* line 1735 */
  sim_icache_fetch(893 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_3, (unsigned int) 215); /* line 1737 */
} /* line 1737 */
  sim_icache_fetch(894 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_6, (unsigned int) -155); /* line 1739 */
} /* line 1739 */
  sim_icache_fetch(895 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_10, (unsigned int) -48); /* line 1741 */
} /* line 1741 */
  sim_icache_fetch(896 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1743 */
} /* line 1743 */
  sim_icache_fetch(897 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, reg_r0_11); /* line 1745 */
} /* line 1745 */
  sim_icache_fetch(898 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1747 */
} /* line 1747 */
  sim_icache_fetch(899 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 28); /* line 1749 */
} /* line 1749 */
  sim_icache_fetch(900 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_7, 0); /* line 1751 */
} /* line 1751 */
  sim_icache_fetch(901 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_12); /* line 1753 */
} /* line 1753 */
  sim_icache_fetch(902 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_13); /* line 1755 */
} /* line 1755 */
  sim_icache_fetch(903 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_11, mem_trace_ld((reg_r0_2 + (unsigned int) 3),0,1)); /* line 1757 */
} /* line 1757 */
  sim_icache_fetch(904 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_9, (unsigned int) 215); /* line 1759 */
} /* line 1759 */
  sim_icache_fetch(905 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -155); /* line 1761 */
} /* line 1761 */
  sim_icache_fetch(906 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) -48); /* line 1763 */
} /* line 1763 */
  sim_icache_fetch(907 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1765 */
} /* line 1765 */
  sim_icache_fetch(908 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_12); /* line 1767 */
} /* line 1767 */
  sim_icache_fetch(909 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1769 */
} /* line 1769 */
  sim_icache_fetch(910 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 28); /* line 1771 */
} /* line 1771 */
  sim_icache_fetch(911 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_9); /* line 1773 */
} /* line 1773 */
  sim_icache_fetch(912 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_13); /* line 1775 */
} /* line 1775 */
  sim_icache_fetch(913 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_10, reg_r0_14); /* line 1777 */
} /* line 1777 */
  sim_icache_fetch(914 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 1779 */
} /* line 1779 */
  sim_icache_fetch(915 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1781 */
} /* line 1781 */
  sim_icache_fetch(916 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_6); /* line 1783 */
} /* line 1783 */
  sim_icache_fetch(917 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1785 */
  sim_icache_fetch(918 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_11); /* line 1787 */
} /* line 1787 */
  sim_icache_fetch(919 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_3); /* line 1789 */
} /* line 1789 */
  sim_icache_fetch(920 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1791 */
  sim_icache_fetch(921 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_9); /* line 1793 */
} /* line 1793 */
  sim_icache_fetch(922 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1795 */
  sim_icache_fetch(923 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 1797 */
} /* line 1797 */
  sim_icache_fetch(924 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 1800 */
} /* line 1800 */
  sim_icache_fetch(925 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L51X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L51X3;
} /* line 1802 */
l_L52X3: ;/* line 1805 */
LABEL(l_L52X3);
  sim_icache_fetch(926 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_18, (unsigned int) 1050); /* line 1806 */
} /* line 1806 */
  sim_icache_fetch(928 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_17, (unsigned int) 4200); /* line 1808 */
} /* line 1808 */
  sim_icache_fetch(930 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_15, (unsigned int) 1); /* line 1810 */
} /* line 1810 */
  sim_icache_fetch(931 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_16); /* line 1813 */
} /* line 1813 */
  sim_icache_fetch(932 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L49X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L49X3;
} /* line 1815 */
l_L50X3: ;/* line 1818 */
LABEL(l_L50X3);
  sim_icache_fetch(933 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_19); /* line 1819 */
} /* line 1819 */
  sim_icache_fetch(934 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_2); /* line 1821 */
} /* line 1821 */
  sim_icache_fetch(935 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, ((unsigned int) qy2 + (unsigned int) -12)); /* line 1823 */
} /* line 1823 */
  sim_icache_fetch(937 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_9, (unsigned int) -1); /* line 1825 */
} /* line 1825 */
  sim_icache_fetch(938 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, ((unsigned int) in + (unsigned int) -3)); /* line 1827 */
} /* line 1827 */
  sim_icache_fetch(940 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_19); /* line 1829 */
} /* line 1829 */
  sim_icache_fetch(941 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, reg_r0_9); /* line 1831 */
} /* line 1831 */
l_L53X3: ;/* line 1834 */
LABEL(l_L53X3);
  sim_icache_fetch(942 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_10, 0); /* line 1835 */
} /* line 1835 */
  sim_icache_fetch(943 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_11, reg_r0_12); /* line 1837 */
} /* line 1837 */
  sim_icache_fetch(944 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L54X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1839 */
  sim_icache_fetch(945 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_7, reg_r0_12, reg_r0_13); /* line 1841 */
} /* line 1841 */
  sim_icache_fetch(946 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 1843 */
} /* line 1843 */
  sim_icache_fetch(947 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 1845 */
} /* line 1845 */
  sim_icache_fetch(948 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 1847 */
} /* line 1847 */
  sim_icache_fetch(949 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 1849 */
} /* line 1849 */
  sim_icache_fetch(950 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_12); /* line 1851 */
} /* line 1851 */
  sim_icache_fetch(951 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_10); /* line 1853 */
} /* line 1853 */
  sim_icache_fetch(952 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_11); /* line 1855 */
} /* line 1855 */
  sim_icache_fetch(953 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_12); /* line 1857 */
} /* line 1857 */
  sim_icache_fetch(954 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_13); /* line 1859 */
} /* line 1859 */
l_L55X3: ;/* line 1862 */
LABEL(l_L55X3);
  sim_icache_fetch(955 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 1863 */
} /* line 1863 */
  sim_icache_fetch(956 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_3, (unsigned int) -47); /* line 1865 */
} /* line 1865 */
  sim_icache_fetch(957 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1867 */
} /* line 1867 */
  sim_icache_fetch(958 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_2); /* line 1869 */
} /* line 1869 */
  sim_icache_fetch(959 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 1871 */
} /* line 1871 */
  sim_icache_fetch(960 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -48); /* line 1873 */
} /* line 1873 */
  sim_icache_fetch(961 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1875 */
} /* line 1875 */
  sim_icache_fetch(962 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 1877 */
} /* line 1877 */
  sim_icache_fetch(963 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_5); /* line 1879 */
} /* line 1879 */
  sim_icache_fetch(964 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, 0); /* line 1881 */
} /* line 1881 */
  sim_icache_fetch(965 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 3),0,1)); /* line 1883 */
} /* line 1883 */
  sim_icache_fetch(966 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L56X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1885 */
  sim_icache_fetch(967 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 1); /* line 1887 */
} /* line 1887 */
  sim_icache_fetch(968 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1889 */
} /* line 1889 */
  sim_icache_fetch(969 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_10, (unsigned int) -47); /* line 1891 */
} /* line 1891 */
  sim_icache_fetch(970 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1893 */
} /* line 1893 */
  sim_icache_fetch(971 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_4); /* line 1895 */
} /* line 1895 */
  sim_icache_fetch(972 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_9, (unsigned int) 215); /* line 1897 */
} /* line 1897 */
  sim_icache_fetch(973 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 1899 */
} /* line 1899 */
  sim_icache_fetch(974 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1901 */
} /* line 1901 */
  sim_icache_fetch(975 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_12); /* line 1903 */
} /* line 1903 */
  sim_icache_fetch(976 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 1905 */
} /* line 1905 */
  sim_icache_fetch(977 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_12, mem_trace_ld((reg_r0_8 + (unsigned int) 2),0,1)); /* line 1907 */
} /* line 1907 */
  sim_icache_fetch(978 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_6, (unsigned int) 2); /* line 1909 */
} /* line 1909 */
  sim_icache_fetch(979 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_9, (unsigned int) -155); /* line 1911 */
} /* line 1911 */
  sim_icache_fetch(980 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_12, (unsigned int) -47); /* line 1913 */
} /* line 1913 */
  sim_icache_fetch(981 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1915 */
} /* line 1915 */
  sim_icache_fetch(982 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_13); /* line 1917 */
} /* line 1917 */
  sim_icache_fetch(983 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_11, (unsigned int) 215); /* line 1919 */
} /* line 1919 */
  sim_icache_fetch(984 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 1921 */
} /* line 1921 */
  sim_icache_fetch(985 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1923 */
} /* line 1923 */
  sim_icache_fetch(986 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_13); /* line 1925 */
} /* line 1925 */
  sim_icache_fetch(987 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 1927 */
} /* line 1927 */
  sim_icache_fetch(988 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 1),0,1)); /* line 1929 */
} /* line 1929 */
  sim_icache_fetch(989 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_2, reg_r0_6, (unsigned int) 3); /* line 1931 */
} /* line 1931 */
  sim_icache_fetch(990 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_11, (unsigned int) -155); /* line 1933 */
} /* line 1933 */
  sim_icache_fetch(991 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_10, (unsigned int) -47); /* line 1935 */
} /* line 1935 */
  sim_icache_fetch(992 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1937 */
} /* line 1937 */
  sim_icache_fetch(993 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_13); /* line 1939 */
} /* line 1939 */
  sim_icache_fetch(994 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_14, (unsigned int) 215); /* line 1941 */
} /* line 1941 */
  sim_icache_fetch(995 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_12, (unsigned int) -48); /* line 1943 */
} /* line 1943 */
  sim_icache_fetch(996 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1945 */
} /* line 1945 */
  sim_icache_fetch(997 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_13); /* line 1947 */
} /* line 1947 */
  sim_icache_fetch(998 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_15, reg_r0_12); /* line 1949 */
} /* line 1949 */
  sim_icache_fetch(999 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_8,0,1)); /* line 1951 */
} /* line 1951 */
  sim_icache_fetch(1000 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) -4); /* line 1953 */
} /* line 1953 */
  sim_icache_fetch(1001 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_10); /* line 1955 */
} /* line 1955 */
  sim_icache_fetch(1002 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_14); /* line 1957 */
} /* line 1957 */
  sim_icache_fetch(1003 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -4); /* line 1959 */
} /* line 1959 */
  sim_icache_fetch(1004 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 12),0,4), reg_r0_9); /* line 1961 */
} /* line 1961 */
  sim_icache_fetch(1005 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L57X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1963 */
  sim_icache_fetch(1006 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 8),0,4), reg_r0_11); /* line 1965 */
} /* line 1965 */
  sim_icache_fetch(1007 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L58X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1967 */
  sim_icache_fetch(1008 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 4),0,4), reg_r0_14); /* line 1969 */
} /* line 1969 */
  sim_icache_fetch(1009 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L59X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1971 */
  sim_icache_fetch(1010 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_7,0,4), reg_r0_4); /* line 1973 */
} /* line 1973 */
  sim_icache_fetch(1011 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -16); /* line 1976 */
} /* line 1976 */
  sim_icache_fetch(1012 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L55X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L55X3;
} /* line 1978 */
l_L59X3: ;/* line 1981 */
LABEL(l_L59X3);
  sim_icache_fetch(1013 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_19, (unsigned int) 4200); /* line 1983 */
} /* line 1983 */
  sim_icache_fetch(1015 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L60X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L60X3;
} /* line 1985 */
l_L58X3: ;/* line 1988 */
LABEL(l_L58X3);
  sim_icache_fetch(1016 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_19, (unsigned int) 4200); /* line 1990 */
} /* line 1990 */
  sim_icache_fetch(1018 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L60X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L60X3;
} /* line 1992 */
l_L57X3: ;/* line 1995 */
LABEL(l_L57X3);
  sim_icache_fetch(1019 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_19, (unsigned int) 4200); /* line 1997 */
} /* line 1997 */
  sim_icache_fetch(1021 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L60X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L60X3;
} /* line 1999 */
l_L56X3: ;/* line 2002 */
LABEL(l_L56X3);
  sim_icache_fetch(1022 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_19, (unsigned int) 4200); /* line 2003 */
} /* line 2003 */
l_L60X3: ;/* line 2005 */
LABEL(l_L60X3);
  sim_icache_fetch(1024 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 1050); /* line 2006 */
} /* line 2006 */
  sim_icache_fetch(1026 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 1); /* line 2008 */
} /* line 2008 */
  sim_icache_fetch(1027 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_18); /* line 2011 */
} /* line 2011 */
  sim_icache_fetch(1028 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L53X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L53X3;
} /* line 2013 */
l_L54X3: ;/* line 2016 */
LABEL(l_L54X3);
  sim_icache_fetch(1029 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_20); /* line 2017 */
} /* line 2017 */
  sim_icache_fetch(1030 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_2); /* line 2019 */
} /* line 2019 */
  sim_icache_fetch(1031 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) qy2); /* line 2021 */
} /* line 2021 */
  sim_icache_fetch(1033 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, (unsigned int) qy1); /* line 2023 */
} /* line 2023 */
  sim_icache_fetch(1035 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, (unsigned int) qt); /* line 2025 */
} /* line 2025 */
  sim_icache_fetch(1037 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_21); /* line 2027 */
} /* line 2027 */
l_L61X3: ;/* line 2030 */
LABEL(l_L61X3);
  sim_icache_fetch(1038 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2031 */
} /* line 2031 */
  sim_icache_fetch(1039 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_11, (unsigned int) 3, reg_r0_9); /* line 2033 */
} /* line 2033 */
  sim_icache_fetch(1040 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2035 */
  sim_icache_fetch(1041 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_11); /* line 2037 */
} /* line 2037 */
  sim_icache_fetch(1042 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_7); /* line 2039 */
} /* line 2039 */
  sim_icache_fetch(1043 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_8); /* line 2041 */
} /* line 2041 */
  sim_icache_fetch(1044 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_10); /* line 2043 */
} /* line 2043 */
  sim_icache_fetch(1045 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, reg_r0_3); /* line 2045 */
} /* line 2045 */
  sim_icache_fetch(1046 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_9); /* line 2047 */
} /* line 2047 */
  sim_icache_fetch(1047 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_7); /* line 2049 */
} /* line 2049 */
  sim_icache_fetch(1048 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_8); /* line 2051 */
} /* line 2051 */
  sim_icache_fetch(1049 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_10); /* line 2053 */
} /* line 2053 */
l_L63X3: ;/* line 2056 */
LABEL(l_L63X3);
  sim_icache_fetch(1050 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2057 */
} /* line 2057 */
  sim_icache_fetch(1051 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld(reg_r0_4,0,4)); /* line 2059 */
} /* line 2059 */
  sim_icache_fetch(1052 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 2061 */
} /* line 2061 */
  sim_icache_fetch(1053 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2063 */
} /* line 2063 */
  sim_icache_fetch(1054 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_7); /* line 2065 */
} /* line 2065 */
  sim_icache_fetch(1055 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2067 */
} /* line 2067 */
  sim_icache_fetch(1056 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2069 */
} /* line 2069 */
  sim_icache_fetch(1057 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2071 */
  sim_icache_fetch(1058 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 2073 */
} /* line 2073 */
  sim_icache_fetch(1059 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 2075 */
} /* line 2075 */
  sim_icache_fetch(1060 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2077 */
} /* line 2077 */
  sim_icache_fetch(1061 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 2079 */
} /* line 2079 */
  sim_icache_fetch(1062 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, reg_r0_8); /* line 2081 */
} /* line 2081 */
  sim_icache_fetch(1063 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 2083 */
} /* line 2083 */
  sim_icache_fetch(1064 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 2085 */
} /* line 2085 */
  sim_icache_fetch(1065 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 2087 */
} /* line 2087 */
  sim_icache_fetch(1066 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_5, 0); /* line 2089 */
} /* line 2089 */
  sim_icache_fetch(1067 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 2091 */
} /* line 2091 */
  sim_icache_fetch(1068 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_8); /* line 2093 */
} /* line 2093 */
  sim_icache_fetch(1069 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2095 */
} /* line 2095 */
  sim_icache_fetch(1070 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2097 */
} /* line 2097 */
  sim_icache_fetch(1071 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 2099 */
} /* line 2099 */
  sim_icache_fetch(1072 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 2101 */
} /* line 2101 */
  sim_icache_fetch(1073 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 2103 */
} /* line 2103 */
  sim_icache_fetch(1074 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_8); /* line 2105 */
} /* line 2105 */
  sim_icache_fetch(1075 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2107 */
} /* line 2107 */
  sim_icache_fetch(1076 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2109 */
} /* line 2109 */
  sim_icache_fetch(1077 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2111 */
} /* line 2111 */
  sim_icache_fetch(1078 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_6,0,4), reg_r0_3); /* line 2113 */
} /* line 2113 */
  sim_icache_fetch(1079 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2115 */
  sim_icache_fetch(1080 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 4),0,4), reg_r0_7); /* line 2117 */
} /* line 2117 */
  sim_icache_fetch(1081 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2119 */
  sim_icache_fetch(1082 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 8),0,4), reg_r0_9); /* line 2121 */
} /* line 2121 */
  sim_icache_fetch(1083 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2123 */
  sim_icache_fetch(1084 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 12),0,4), reg_r0_10); /* line 2125 */
} /* line 2125 */
  sim_icache_fetch(1085 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 2128 */
} /* line 2128 */
  sim_icache_fetch(1086 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L63X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L63X3;
} /* line 2130 */
l_L64X3: ;/* line 2133 */
LABEL(l_L64X3);
  sim_icache_fetch(1087 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2134 */
} /* line 2134 */
  sim_icache_fetch(1089 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_15, reg_r0_2); /* line 2136 */
} /* line 2136 */
  sim_icache_fetch(1090 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_14, reg_r0_2); /* line 2138 */
} /* line 2138 */
  sim_icache_fetch(1091 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_13, reg_r0_2); /* line 2140 */
} /* line 2140 */
  sim_icache_fetch(1092 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 2142 */
} /* line 2142 */
  sim_icache_fetch(1093 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_12); /* line 2145 */
} /* line 2145 */
  sim_icache_fetch(1094 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L61X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L61X3;
} /* line 2147 */
l_L62X3: ;/* line 2150 */
LABEL(l_L62X3);
  sim_icache_fetch(1095 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_9); /* line 2151 */
} /* line 2151 */
  sim_icache_fetch(1096 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_2); /* line 2153 */
} /* line 2153 */
  sim_icache_fetch(1097 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, (unsigned int) qt); /* line 2155 */
} /* line 2155 */
  sim_icache_fetch(1099 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, (unsigned int) qy1); /* line 2157 */
} /* line 2157 */
  sim_icache_fetch(1101 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_20); /* line 2159 */
} /* line 2159 */
  sim_icache_fetch(1102 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_9); /* line 2161 */
} /* line 2161 */
l_L65X3: ;/* line 2164 */
LABEL(l_L65X3);
  sim_icache_fetch(1103 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2165 */
} /* line 2165 */
  sim_icache_fetch(1104 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_13, (unsigned int) 3, reg_r0_10); /* line 2167 */
} /* line 2167 */
  sim_icache_fetch(1105 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2169 */
  sim_icache_fetch(1106 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_13); /* line 2171 */
} /* line 2171 */
  sim_icache_fetch(1107 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_11); /* line 2173 */
} /* line 2173 */
  sim_icache_fetch(1108 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_12); /* line 2175 */
} /* line 2175 */
  sim_icache_fetch(1109 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, 0); /* line 2177 */
} /* line 2177 */
  sim_icache_fetch(1110 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 2179 */
} /* line 2179 */
  sim_icache_fetch(1111 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 2181 */
} /* line 2181 */
  sim_icache_fetch(1112 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_3); /* line 2183 */
} /* line 2183 */
  sim_icache_fetch(1113 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_10); /* line 2185 */
} /* line 2185 */
  sim_icache_fetch(1114 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_11); /* line 2187 */
} /* line 2187 */
  sim_icache_fetch(1115 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_12); /* line 2189 */
} /* line 2189 */
l_L67X3: ;/* line 2192 */
LABEL(l_L67X3);
  sim_icache_fetch(1116 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2193 */
} /* line 2193 */
  sim_icache_fetch(1117 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2195 */
} /* line 2195 */
  sim_icache_fetch(1118 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_5, (unsigned int) 215); /* line 2197 */
} /* line 2197 */
  sim_icache_fetch(1119 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_3, (unsigned int) -48); /* line 2199 */
} /* line 2199 */
  sim_icache_fetch(1120 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 2201 */
} /* line 2201 */
  sim_icache_fetch(1121 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_10); /* line 2203 */
} /* line 2203 */
  sim_icache_fetch(1122 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_6); /* line 2205 */
} /* line 2205 */
  sim_icache_fetch(1123 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_9); /* line 2207 */
} /* line 2207 */
  sim_icache_fetch(1124 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2209 */
} /* line 2209 */
  sim_icache_fetch(1125 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 3); /* line 2211 */
} /* line 2211 */
  sim_icache_fetch(1126 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2213 */
} /* line 2213 */
  sim_icache_fetch(1127 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2215 */
  sim_icache_fetch(1128 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 2217 */
} /* line 2217 */
  sim_icache_fetch(1130 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2219 */
} /* line 2219 */
  sim_icache_fetch(1131 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 2221 */
} /* line 2221 */
  sim_icache_fetch(1132 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_9, (unsigned int) -48); /* line 2223 */
} /* line 2223 */
  sim_icache_fetch(1133 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2225 */
} /* line 2225 */
  sim_icache_fetch(1134 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 2227 */
} /* line 2227 */
  sim_icache_fetch(1135 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_3); /* line 2229 */
} /* line 2229 */
  sim_icache_fetch(1136 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 2231 */
} /* line 2231 */
  sim_icache_fetch(1137 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2233 */
} /* line 2233 */
  sim_icache_fetch(1138 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2235 */
} /* line 2235 */
  sim_icache_fetch(1139 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 8400),0,4)); /* line 2237 */
} /* line 2237 */
  sim_icache_fetch(1141 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) -155); /* line 2239 */
} /* line 2239 */
  sim_icache_fetch(1142 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_5, (unsigned int) 215); /* line 2241 */
} /* line 2241 */
  sim_icache_fetch(1143 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_3, (unsigned int) -48); /* line 2243 */
} /* line 2243 */
  sim_icache_fetch(1144 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 28); /* line 2245 */
} /* line 2245 */
  sim_icache_fetch(1145 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_12); /* line 2247 */
} /* line 2247 */
  sim_icache_fetch(1146 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_9); /* line 2249 */
} /* line 2249 */
  sim_icache_fetch(1147 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 2251 */
} /* line 2251 */
  sim_icache_fetch(1148 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2253 */
} /* line 2253 */
  sim_icache_fetch(1149 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_7, 0); /* line 2255 */
} /* line 2255 */
  sim_icache_fetch(1150 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 12600),0,4)); /* line 2257 */
} /* line 2257 */
  sim_icache_fetch(1152 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_5, (unsigned int) -155); /* line 2259 */
} /* line 2259 */
  sim_icache_fetch(1153 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_10, (unsigned int) 215); /* line 2261 */
} /* line 2261 */
  sim_icache_fetch(1154 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_6, (unsigned int) -48); /* line 2263 */
} /* line 2263 */
  sim_icache_fetch(1155 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2265 */
} /* line 2265 */
  sim_icache_fetch(1156 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_12); /* line 2267 */
} /* line 2267 */
  sim_icache_fetch(1157 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 2269 */
} /* line 2269 */
  sim_icache_fetch(1158 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_11); /* line 2271 */
} /* line 2271 */
  sim_icache_fetch(1159 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2273 */
} /* line 2273 */
  sim_icache_fetch(1160 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 2275 */
} /* line 2275 */
  sim_icache_fetch(1161 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2277 */
  sim_icache_fetch(1162 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_10); /* line 2279 */
} /* line 2279 */
  sim_icache_fetch(1163 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16800); /* line 2281 */
} /* line 2281 */
  sim_icache_fetch(1165 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 2283 */
} /* line 2283 */
  sim_icache_fetch(1166 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_5); /* line 2285 */
} /* line 2285 */
  sim_icache_fetch(1168 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2287 */
  sim_icache_fetch(1169 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_9); /* line 2289 */
} /* line 2289 */
  sim_icache_fetch(1170 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_10); /* line 2291 */
} /* line 2291 */
  sim_icache_fetch(1172 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2293 */
  sim_icache_fetch(1173 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_9); /* line 2295 */
} /* line 2295 */
  sim_icache_fetch(1175 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 16800); /* line 2298 */
} /* line 2298 */
  sim_icache_fetch(1177 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L67X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L67X3;
} /* line 2300 */
l_L68X3: ;/* line 2303 */
LABEL(l_L68X3);
  sim_icache_fetch(1178 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 2304 */
} /* line 2304 */
  sim_icache_fetch(1179 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_15, (unsigned int) 4); /* line 2306 */
} /* line 2306 */
  sim_icache_fetch(1180 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 2308 */
} /* line 2308 */
  sim_icache_fetch(1181 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_14); /* line 2311 */
} /* line 2311 */
  sim_icache_fetch(1182 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L65X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L65X3;
} /* line 2313 */
l_L66X3: ;/* line 2316 */
LABEL(l_L66X3);
  sim_icache_fetch(1183 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_17); /* line 2317 */
} /* line 2317 */
  sim_icache_fetch(1184 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, ((unsigned int) qy2 + (unsigned int) -12600)); /* line 2319 */
} /* line 2319 */
  sim_icache_fetch(1186 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_10); /* line 2321 */
} /* line 2321 */
  sim_icache_fetch(1187 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_2); /* line 2323 */
} /* line 2323 */
  sim_icache_fetch(1188 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, ((unsigned int) qt + (unsigned int) -12600)); /* line 2325 */
} /* line 2325 */
  sim_icache_fetch(1190 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_20, (unsigned int) -1); /* line 2327 */
} /* line 2327 */
  sim_icache_fetch(1191 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_17); /* line 2329 */
} /* line 2329 */
l_L69X3: ;/* line 2332 */
LABEL(l_L69X3);
  sim_icache_fetch(1192 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_10, 0); /* line 2333 */
} /* line 2333 */
  sim_icache_fetch(1193 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULLU(reg_r0_14, reg_r0_11, (unsigned int) 4200); /* line 2335 */
} /* line 2335 */
  sim_icache_fetch(1195 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2337 */
  sim_icache_fetch(1196 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_12, reg_r0_14); /* line 2339 */
} /* line 2339 */
  sim_icache_fetch(1197 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_13, reg_r0_14); /* line 2341 */
} /* line 2341 */
  sim_icache_fetch(1198 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 2343 */
} /* line 2343 */
  sim_icache_fetch(1199 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 2345 */
} /* line 2345 */
  sim_icache_fetch(1200 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 2347 */
} /* line 2347 */
  sim_icache_fetch(1201 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 2349 */
} /* line 2349 */
  sim_icache_fetch(1202 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_11); /* line 2351 */
} /* line 2351 */
  sim_icache_fetch(1203 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_10); /* line 2353 */
} /* line 2353 */
  sim_icache_fetch(1204 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_11); /* line 2355 */
} /* line 2355 */
  sim_icache_fetch(1205 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_12); /* line 2357 */
} /* line 2357 */
  sim_icache_fetch(1206 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_13); /* line 2359 */
} /* line 2359 */
l_L71X3: ;/* line 2362 */
LABEL(l_L71X3);
  sim_icache_fetch(1207 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2363 */
} /* line 2363 */
  sim_icache_fetch(1208 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_3, (unsigned int) -47); /* line 2365 */
} /* line 2365 */
  sim_icache_fetch(1209 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 2367 */
} /* line 2367 */
  sim_icache_fetch(1210 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2369 */
} /* line 2369 */
  sim_icache_fetch(1211 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 29); /* line 2371 */
} /* line 2371 */
  sim_icache_fetch(1212 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, 0); /* line 2373 */
} /* line 2373 */
  sim_icache_fetch(1213 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_5); /* line 2375 */
} /* line 2375 */
  sim_icache_fetch(1214 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 2377 */
} /* line 2377 */
  sim_icache_fetch(1215 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2379 */
} /* line 2379 */
  sim_icache_fetch(1216 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2381 */
  sim_icache_fetch(1217 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_9, mem_trace_ld((reg_r0_8 + (unsigned int) 12600),0,4)); /* line 2383 */
} /* line 2383 */
  sim_icache_fetch(1219 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 1); /* line 2385 */
} /* line 2385 */
  sim_icache_fetch(1220 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2387 */
} /* line 2387 */
  sim_icache_fetch(1221 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_9, (unsigned int) -47); /* line 2389 */
} /* line 2389 */
  sim_icache_fetch(1222 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 2391 */
} /* line 2391 */
  sim_icache_fetch(1223 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_10); /* line 2393 */
} /* line 2393 */
  sim_icache_fetch(1224 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 2395 */
} /* line 2395 */
  sim_icache_fetch(1225 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 8400),0,4)); /* line 2397 */
} /* line 2397 */
  sim_icache_fetch(1227 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 2399 */
} /* line 2399 */
  sim_icache_fetch(1228 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_11); /* line 2401 */
} /* line 2401 */
  sim_icache_fetch(1229 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2403 */
} /* line 2403 */
  sim_icache_fetch(1230 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_6, (unsigned int) 2); /* line 2405 */
} /* line 2405 */
  sim_icache_fetch(1231 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 2407 */
} /* line 2407 */
  sim_icache_fetch(1232 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 2409 */
} /* line 2409 */
  sim_icache_fetch(1233 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_4, (unsigned int) 215); /* line 2411 */
} /* line 2411 */
  sim_icache_fetch(1234 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 2413 */
} /* line 2413 */
  sim_icache_fetch(1235 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 29); /* line 2415 */
} /* line 2415 */
  sim_icache_fetch(1236 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_8 + (unsigned int) 4200),0,4)); /* line 2417 */
} /* line 2417 */
  sim_icache_fetch(1238 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, reg_r0_9); /* line 2419 */
} /* line 2419 */
  sim_icache_fetch(1239 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 2421 */
} /* line 2421 */
  sim_icache_fetch(1240 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2423 */
} /* line 2423 */
  sim_icache_fetch(1241 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_2, reg_r0_6, (unsigned int) 3); /* line 2425 */
} /* line 2425 */
  sim_icache_fetch(1242 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_4, (unsigned int) -155); /* line 2427 */
} /* line 2427 */
  sim_icache_fetch(1243 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 2429 */
} /* line 2429 */
  sim_icache_fetch(1244 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 2431 */
} /* line 2431 */
  sim_icache_fetch(1245 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_13); /* line 2433 */
} /* line 2433 */
  sim_icache_fetch(1246 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 2435 */
} /* line 2435 */
  sim_icache_fetch(1247 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_8,0,4)); /* line 2437 */
} /* line 2437 */
  sim_icache_fetch(1248 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 2439 */
} /* line 2439 */
  sim_icache_fetch(1249 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_14); /* line 2441 */
} /* line 2441 */
  sim_icache_fetch(1250 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2443 */
} /* line 2443 */
  sim_icache_fetch(1251 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 12600),0,4), reg_r0_2); /* line 2445 */
} /* line 2445 */
  sim_icache_fetch(1253 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2447 */
  sim_icache_fetch(1254 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_11); /* line 2449 */
} /* line 2449 */
  sim_icache_fetch(1255 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_12); /* line 2451 */
} /* line 2451 */
  sim_icache_fetch(1256 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) -4); /* line 2453 */
} /* line 2453 */
  sim_icache_fetch(1257 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16800); /* line 2455 */
} /* line 2455 */
  sim_icache_fetch(1259 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 8400),0,4), reg_r0_4); /* line 2457 */
} /* line 2457 */
  sim_icache_fetch(1261 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2459 */
  sim_icache_fetch(1262 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_9); /* line 2461 */
} /* line 2461 */
  sim_icache_fetch(1263 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 4200),0,4), reg_r0_11); /* line 2463 */
} /* line 2463 */
  sim_icache_fetch(1265 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2465 */
  sim_icache_fetch(1266 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_7,0,4), reg_r0_9); /* line 2467 */
} /* line 2467 */
  sim_icache_fetch(1267 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -16800); /* line 2470 */
} /* line 2470 */
  sim_icache_fetch(1269 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L71X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L71X3;
} /* line 2472 */
l_L72X3: ;/* line 2475 */
LABEL(l_L72X3);
  sim_icache_fetch(1270 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 2476 */
} /* line 2476 */
  sim_icache_fetch(1271 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 2478 */
} /* line 2478 */
  sim_icache_fetch(1272 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1); /* line 2480 */
} /* line 2480 */
  sim_icache_fetch(1273 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, reg_r0_16); /* line 2483 */
} /* line 2483 */
  sim_icache_fetch(1274 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L69X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L69X3;
} /* line 2485 */
l_L70X3: ;/* line 2488 */
LABEL(l_L70X3);
  sim_icache_fetch(1275 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_20, 0, reg_r0_20); /* line 2489 */
} /* line 2489 */
  sim_icache_fetch(1276 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_20); /* line 2491 */
} /* line 2491 */
  sim_icache_fetch(1277 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, (unsigned int) qy2); /* line 2493 */
} /* line 2493 */
  sim_icache_fetch(1279 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) qy1); /* line 2495 */
} /* line 2495 */
  sim_icache_fetch(1281 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, (unsigned int) out); /* line 2497 */
} /* line 2497 */
  sim_icache_fetch(1283 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_19); /* line 2499 */
} /* line 2499 */
l_L73X3: ;/* line 2502 */
LABEL(l_L73X3);
  sim_icache_fetch(1284 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2503 */
} /* line 2503 */
  sim_icache_fetch(1285 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_12, (unsigned int) 3, reg_r0_9); /* line 2505 */
} /* line 2505 */
  sim_icache_fetch(1286 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2507 */
  sim_icache_fetch(1287 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_12); /* line 2509 */
} /* line 2509 */
  sim_icache_fetch(1288 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_8); /* line 2511 */
} /* line 2511 */
  sim_icache_fetch(1289 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_8); /* line 2513 */
} /* line 2513 */
  sim_icache_fetch(1290 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_10); /* line 2515 */
} /* line 2515 */
  sim_icache_fetch(1291 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_11); /* line 2517 */
} /* line 2517 */
  sim_icache_fetch(1292 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_3); /* line 2519 */
} /* line 2519 */
  sim_icache_fetch(1293 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_9); /* line 2521 */
} /* line 2521 */
  sim_icache_fetch(1294 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_8); /* line 2523 */
} /* line 2523 */
  sim_icache_fetch(1295 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_10); /* line 2525 */
} /* line 2525 */
  sim_icache_fetch(1296 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_11); /* line 2527 */
} /* line 2527 */
l_L75X3: ;/* line 2530 */
LABEL(l_L75X3);
  sim_icache_fetch(1297 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2531 */
} /* line 2531 */
  sim_icache_fetch(1298 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_4,0,4)); /* line 2533 */
} /* line 2533 */
  sim_icache_fetch(1299 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 2535 */
} /* line 2535 */
  sim_icache_fetch(1300 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2537 */
} /* line 2537 */
  sim_icache_fetch(1301 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_8); /* line 2539 */
} /* line 2539 */
  sim_icache_fetch(1302 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2541 */
} /* line 2541 */
  sim_icache_fetch(1303 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 2543 */
} /* line 2543 */
  sim_icache_fetch(1304 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2545 */
  sim_icache_fetch(1305 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_8, reg_r0_3); /* line 2547 */
} /* line 2547 */
  sim_icache_fetch(1306 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_8, (unsigned int) 25); /* line 2549 */
} /* line 2549 */
  sim_icache_fetch(1307 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 2551 */
} /* line 2551 */
  sim_icache_fetch(1308 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 2553 */
} /* line 2553 */
  sim_icache_fetch(1309 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_5, (unsigned int) 1); /* line 2555 */
} /* line 2555 */
  sim_icache_fetch(1310 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 2557 */
} /* line 2557 */
  sim_icache_fetch(1311 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_8); /* line 2559 */
} /* line 2559 */
  sim_icache_fetch(1312 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2561 */
} /* line 2561 */
  sim_icache_fetch(1313 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 2563 */
} /* line 2563 */
  sim_icache_fetch(1314 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_8, reg_r0_9); /* line 2565 */
} /* line 2565 */
  sim_icache_fetch(1315 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_3, reg_r0_8, (unsigned int) 25); /* line 2567 */
} /* line 2567 */
  sim_icache_fetch(1316 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 2569 */
} /* line 2569 */
  sim_icache_fetch(1317 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_4, reg_r0_5, 0); /* line 2571 */
} /* line 2571 */
  sim_icache_fetch(1318 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 2573 */
} /* line 2573 */
  sim_icache_fetch(1319 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 2575 */
} /* line 2575 */
  sim_icache_fetch(1320 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2577 */
} /* line 2577 */
  sim_icache_fetch(1321 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 2579 */
} /* line 2579 */
  sim_icache_fetch(1322 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_11, reg_r0_10); /* line 2581 */
} /* line 2581 */
  sim_icache_fetch(1323 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_5, reg_r0_11, (unsigned int) 25); /* line 2583 */
} /* line 2583 */
  sim_icache_fetch(1324 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 2585 */
} /* line 2585 */
  sim_icache_fetch(1325 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_6,0,1), reg_r0_3); /* line 2587 */
} /* line 2587 */
  sim_icache_fetch(1326 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2589 */
  sim_icache_fetch(1327 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, reg_r0_12); /* line 2591 */
} /* line 2591 */
  sim_icache_fetch(1328 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 2593 */
} /* line 2593 */
  sim_icache_fetch(1329 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 2595 */
} /* line 2595 */
  sim_icache_fetch(1330 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_3, reg_r0_8); /* line 2597 */
} /* line 2597 */
  sim_icache_fetch(1331 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 2599 */
} /* line 2599 */
  sim_icache_fetch(1332 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_6,0,1), 0); /* line 2601 */
} /* line 2601 */
l_L78X3: ;/* line 2603 */
LABEL(l_L78X3);
  sim_icache_fetch(1333 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2604 */
  sim_icache_fetch(1334 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), reg_r0_9); /* line 2606 */
} /* line 2606 */
  sim_icache_fetch(1335 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2608 */
  sim_icache_fetch(1336 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), 0); /* line 2610 */
} /* line 2610 */
l_L80X3: ;/* line 2612 */
LABEL(l_L80X3);
  sim_icache_fetch(1337 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2613 */
  sim_icache_fetch(1338 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), reg_r0_10); /* line 2615 */
} /* line 2615 */
  sim_icache_fetch(1339 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_5) {    BRANCHF(reg_b0_5);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2617 */
  sim_icache_fetch(1340 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), 0); /* line 2619 */
} /* line 2619 */
l_L82X3: ;/* line 2621 */
LABEL(l_L82X3);
  sim_icache_fetch(1341 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_4) {    BRANCHF(reg_b0_4);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2622 */
  sim_icache_fetch(1342 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), reg_r0_8); /* line 2624 */
} /* line 2624 */
  sim_icache_fetch(1343 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L83X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2626 */
  sim_icache_fetch(1344 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 2628 */
} /* line 2628 */
  sim_icache_fetch(1345 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 2630 */
} /* line 2630 */
  sim_icache_fetch(1346 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 2632 */
} /* line 2632 */
  sim_icache_fetch(1347 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2634 */
} /* line 2634 */
  sim_icache_fetch(1348 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), 0); /* line 2636 */
} /* line 2636 */
l_L84X3: ;/* line 2638 */
LABEL(l_L84X3);
  sim_icache_fetch(1349 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 4); /* line 2640 */
} /* line 2640 */
  sim_icache_fetch(1350 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L75X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L75X3;
} /* line 2642 */
l_L83X3: ;/* line 2645 */
LABEL(l_L83X3);
  sim_icache_fetch(1351 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 2646 */
} /* line 2646 */
  sim_icache_fetch(1352 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2648 */
} /* line 2648 */
  sim_icache_fetch(1353 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 2650 */
} /* line 2650 */
  sim_icache_fetch(1354 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 2652 */
} /* line 2652 */
  sim_icache_fetch(1355 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 3),0,1), reg_r0_3); /* line 2654 */
} /* line 2654 */
  sim_icache_fetch(1356 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 2657 */
} /* line 2657 */
  sim_icache_fetch(1357 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L84X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L84X3;
} /* line 2659 */
l_L76X3: ;/* line 2662 */
LABEL(l_L76X3);
  sim_icache_fetch(1358 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4200); /* line 2663 */
} /* line 2663 */
  sim_icache_fetch(1360 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 4200); /* line 2665 */
} /* line 2665 */
  sim_icache_fetch(1362 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_15, (unsigned int) 1050); /* line 2667 */
} /* line 2667 */
  sim_icache_fetch(1364 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 2669 */
} /* line 2669 */
  sim_icache_fetch(1365 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_14); /* line 2672 */
} /* line 2672 */
  sim_icache_fetch(1366 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L73X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L73X3;
} /* line 2674 */
l_L81X3: ;/* line 2677 */
LABEL(l_L81X3);
  sim_icache_fetch(1367 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 2678 */
} /* line 2678 */
  sim_icache_fetch(1368 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 2),0,1), reg_r0_3); /* line 2681 */
} /* line 2681 */
  sim_icache_fetch(1369 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L82X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L82X3;
} /* line 2683 */
l_L79X3: ;/* line 2686 */
LABEL(l_L79X3);
  sim_icache_fetch(1370 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 2687 */
} /* line 2687 */
  sim_icache_fetch(1371 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 1),0,1), reg_r0_3); /* line 2690 */
} /* line 2690 */
  sim_icache_fetch(1372 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L80X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L80X3;
} /* line 2692 */
l_L77X3: ;/* line 2695 */
LABEL(l_L77X3);
  sim_icache_fetch(1373 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 2696 */
} /* line 2696 */
  sim_icache_fetch(1374 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, reg_r0_12); /* line 2698 */
} /* line 2698 */
  sim_icache_fetch(1375 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 2700 */
} /* line 2700 */
  sim_icache_fetch(1376 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 2702 */
} /* line 2702 */
  sim_icache_fetch(1377 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_11, reg_r0_8); /* line 2704 */
} /* line 2704 */
  sim_icache_fetch(1378 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_11, (unsigned int) 25); /* line 2706 */
} /* line 2706 */
  sim_icache_fetch(1379 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_7,0,1), reg_r0_3); /* line 2709 */
} /* line 2709 */
  sim_icache_fetch(1380 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L78X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L78X3;
} /* line 2711 */
l_L74X3: ;/* line 2714 */
LABEL(l_L74X3);
  sim_icache_fetch(1381 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_slow);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2716 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 224: goto l_L49X3;
    case 225: goto l_L51X3;
    case 226: goto l_L52X3;
    case 227: goto l_L50X3;
    case 228: goto l_L53X3;
    case 229: goto l_L55X3;
    case 230: goto l_L59X3;
    case 231: goto l_L58X3;
    case 232: goto l_L57X3;
    case 233: goto l_L56X3;
    case 234: goto l_L60X3;
    case 235: goto l_L54X3;
    case 236: goto l_L61X3;
    case 237: goto l_L63X3;
    case 238: goto l_L64X3;
    case 239: goto l_L62X3;
    case 240: goto l_L65X3;
    case 241: goto l_L67X3;
    case 242: goto l_L68X3;
    case 243: goto l_L66X3;
    case 244: goto l_L69X3;
    case 245: goto l_L71X3;
    case 246: goto l_L72X3;
    case 247: goto l_L70X3;
    case 248: goto l_L73X3;
    case 249: goto l_L75X3;
    case 250: goto l_L78X3;
    case 251: goto l_L80X3;
    case 252: goto l_L82X3;
    case 253: goto l_L84X3;
    case 254: goto l_L83X3;
    case 255: goto l_L76X3;
    case 256: goto l_L81X3;
    case 257: goto l_L79X3;
    case 258: goto l_L77X3;
    case 259: goto l_L74X3;
    case 260:
      reg_l0_0 = t_client_rpc;
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"deriche.s", 1392, 0, 0, 0, 2};


/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/matthias/vex-3.43 -I../include/ -ms -mas_g -mas_t -O2 -fmm=./risc.mm -DVEX -o edge_detect -lvexsimd" */

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

unsigned int s_at[787500];
unsigned int s_by2[750];
unsigned int s_by1[750];
unsigned int s_ay2[525];
unsigned int s_ay1[525];
unsigned int at[1575000];
unsigned int ay2[1050];
unsigned int ay1[1050];
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
extern  deriche_slow( unsigned int, unsigned int );
extern  deriche_fused( unsigned int, unsigned int );
extern  deriche_array( unsigned int, unsigned int );
extern  deriche_short( unsigned int, unsigned int );
extern  deriche_simd( unsigned int, unsigned int );
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
extern unsigned int reg_r0_28;
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
  reg_l0_0 = (235 << 5);
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
   MOV(reg_r0_11, (unsigned int) in); /* line 857 */
} /* line 857 */
  sim_icache_fetch(459 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_3); /* line 859 */
} /* line 859 */
  sim_icache_fetch(460 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_2); /* line 861 */
} /* line 861 */
  sim_icache_fetch(461 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) qy1); /* line 863 */
} /* line 863 */
  sim_icache_fetch(463 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_4); /* line 865 */
} /* line 865 */
l_L25X3: ;/* line 868 */
LABEL(l_L25X3);
  sim_icache_fetch(464 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 869 */
} /* line 869 */
  sim_icache_fetch(465 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_12, (unsigned int) 3, reg_r0_9); /* line 871 */
} /* line 871 */
  sim_icache_fetch(466 + t_thisfile.offset, 1);
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
} /* line 873 */
  sim_icache_fetch(467 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_12); /* line 875 */
} /* line 875 */
  sim_icache_fetch(468 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_10); /* line 877 */
} /* line 877 */
  sim_icache_fetch(469 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 879 */
} /* line 879 */
  sim_icache_fetch(470 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 881 */
} /* line 881 */
  sim_icache_fetch(471 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_11); /* line 883 */
} /* line 883 */
  sim_icache_fetch(472 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, 0); /* line 885 */
} /* line 885 */
  sim_icache_fetch(473 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_3); /* line 887 */
} /* line 887 */
  sim_icache_fetch(474 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_9); /* line 889 */
} /* line 889 */
  sim_icache_fetch(475 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_10); /* line 891 */
} /* line 891 */
  sim_icache_fetch(476 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_11); /* line 893 */
} /* line 893 */
l_L27X3: ;/* line 896 */
LABEL(l_L27X3);
  sim_icache_fetch(477 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 897 */
} /* line 897 */
  sim_icache_fetch(478 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_4, (unsigned int) 215); /* line 899 */
} /* line 899 */
  sim_icache_fetch(479 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 901 */
} /* line 901 */
  sim_icache_fetch(480 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_3, (unsigned int) -48); /* line 903 */
} /* line 903 */
  sim_icache_fetch(481 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 905 */
} /* line 905 */
  sim_icache_fetch(482 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_9); /* line 907 */
} /* line 907 */
  sim_icache_fetch(483 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 909 */
} /* line 909 */
  sim_icache_fetch(484 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 911 */
} /* line 911 */
  sim_icache_fetch(485 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 3); /* line 913 */
} /* line 913 */
  sim_icache_fetch(486 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_5); /* line 915 */
} /* line 915 */
  sim_icache_fetch(487 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 917 */
} /* line 917 */
  sim_icache_fetch(488 + t_thisfile.offset, 1);
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
} /* line 919 */
  sim_icache_fetch(489 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 2); /* line 921 */
} /* line 921 */
  sim_icache_fetch(490 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 923 */
} /* line 923 */
  sim_icache_fetch(491 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_6, (unsigned int) 215); /* line 925 */
} /* line 925 */
  sim_icache_fetch(492 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 927 */
} /* line 927 */
  sim_icache_fetch(493 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_9, (unsigned int) -48); /* line 929 */
} /* line 929 */
  sim_icache_fetch(494 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 931 */
} /* line 931 */
  sim_icache_fetch(495 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 933 */
} /* line 933 */
  sim_icache_fetch(496 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 935 */
} /* line 935 */
  sim_icache_fetch(497 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 937 */
} /* line 937 */
  sim_icache_fetch(498 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_7, (unsigned int) 1); /* line 939 */
} /* line 939 */
  sim_icache_fetch(499 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 941 */
} /* line 941 */
  sim_icache_fetch(500 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 943 */
} /* line 943 */
  sim_icache_fetch(501 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 945 */
} /* line 945 */
  sim_icache_fetch(502 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_3, (unsigned int) 215); /* line 947 */
} /* line 947 */
  sim_icache_fetch(503 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_6, (unsigned int) -155); /* line 949 */
} /* line 949 */
  sim_icache_fetch(504 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_10, (unsigned int) -48); /* line 951 */
} /* line 951 */
  sim_icache_fetch(505 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 953 */
} /* line 953 */
  sim_icache_fetch(506 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, reg_r0_11); /* line 955 */
} /* line 955 */
  sim_icache_fetch(507 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 957 */
} /* line 957 */
  sim_icache_fetch(508 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 28); /* line 959 */
} /* line 959 */
  sim_icache_fetch(509 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_7, 0); /* line 961 */
} /* line 961 */
  sim_icache_fetch(510 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_12); /* line 963 */
} /* line 963 */
  sim_icache_fetch(511 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_13); /* line 965 */
} /* line 965 */
  sim_icache_fetch(512 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_11, mem_trace_ld((reg_r0_2 + (unsigned int) 3),0,1)); /* line 967 */
} /* line 967 */
  sim_icache_fetch(513 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_9, (unsigned int) 215); /* line 969 */
} /* line 969 */
  sim_icache_fetch(514 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -155); /* line 971 */
} /* line 971 */
  sim_icache_fetch(515 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) -48); /* line 973 */
} /* line 973 */
  sim_icache_fetch(516 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 975 */
} /* line 975 */
  sim_icache_fetch(517 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_12); /* line 977 */
} /* line 977 */
  sim_icache_fetch(518 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 979 */
} /* line 979 */
  sim_icache_fetch(519 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 28); /* line 981 */
} /* line 981 */
  sim_icache_fetch(520 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_9); /* line 983 */
} /* line 983 */
  sim_icache_fetch(521 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_13); /* line 985 */
} /* line 985 */
  sim_icache_fetch(522 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_10, reg_r0_14); /* line 987 */
} /* line 987 */
  sim_icache_fetch(523 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 989 */
} /* line 989 */
  sim_icache_fetch(524 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 991 */
} /* line 991 */
  sim_icache_fetch(525 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_6); /* line 993 */
} /* line 993 */
  sim_icache_fetch(526 + t_thisfile.offset, 1);
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
} /* line 995 */
  sim_icache_fetch(527 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_11); /* line 997 */
} /* line 997 */
  sim_icache_fetch(528 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_3); /* line 999 */
} /* line 999 */
  sim_icache_fetch(529 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1001 */
  sim_icache_fetch(530 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_9); /* line 1003 */
} /* line 1003 */
  sim_icache_fetch(531 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1005 */
  sim_icache_fetch(532 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 1007 */
} /* line 1007 */
  sim_icache_fetch(533 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 1010 */
} /* line 1010 */
  sim_icache_fetch(534 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L27X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L27X3;
} /* line 1012 */
l_L28X3: ;/* line 1015 */
LABEL(l_L28X3);
  sim_icache_fetch(535 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_18, (unsigned int) 1050); /* line 1016 */
} /* line 1016 */
  sim_icache_fetch(537 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_17, (unsigned int) 4200); /* line 1018 */
} /* line 1018 */
  sim_icache_fetch(539 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_15, (unsigned int) 1); /* line 1020 */
} /* line 1020 */
  sim_icache_fetch(540 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_16); /* line 1023 */
} /* line 1023 */
  sim_icache_fetch(541 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L25X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L25X3;
} /* line 1025 */
l_L26X3: ;/* line 1028 */
LABEL(l_L26X3);
  sim_icache_fetch(542 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_19); /* line 1029 */
} /* line 1029 */
  sim_icache_fetch(543 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_2); /* line 1031 */
} /* line 1031 */
  sim_icache_fetch(544 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, ((unsigned int) qy2 + (unsigned int) -12)); /* line 1033 */
} /* line 1033 */
  sim_icache_fetch(546 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_9, (unsigned int) -1); /* line 1035 */
} /* line 1035 */
  sim_icache_fetch(547 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, ((unsigned int) in + (unsigned int) -3)); /* line 1037 */
} /* line 1037 */
  sim_icache_fetch(549 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_19); /* line 1039 */
} /* line 1039 */
  sim_icache_fetch(550 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, reg_r0_9); /* line 1041 */
} /* line 1041 */
l_L29X3: ;/* line 1044 */
LABEL(l_L29X3);
  sim_icache_fetch(551 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_10, 0); /* line 1045 */
} /* line 1045 */
  sim_icache_fetch(552 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_11, reg_r0_12); /* line 1047 */
} /* line 1047 */
  sim_icache_fetch(553 + t_thisfile.offset, 1);
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
} /* line 1049 */
  sim_icache_fetch(554 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_7, reg_r0_12, reg_r0_13); /* line 1051 */
} /* line 1051 */
  sim_icache_fetch(555 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 1053 */
} /* line 1053 */
  sim_icache_fetch(556 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 1055 */
} /* line 1055 */
  sim_icache_fetch(557 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 1057 */
} /* line 1057 */
  sim_icache_fetch(558 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 1059 */
} /* line 1059 */
  sim_icache_fetch(559 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_12); /* line 1061 */
} /* line 1061 */
  sim_icache_fetch(560 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_10); /* line 1063 */
} /* line 1063 */
  sim_icache_fetch(561 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_11); /* line 1065 */
} /* line 1065 */
  sim_icache_fetch(562 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_12); /* line 1067 */
} /* line 1067 */
  sim_icache_fetch(563 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_13); /* line 1069 */
} /* line 1069 */
l_L31X3: ;/* line 1072 */
LABEL(l_L31X3);
  sim_icache_fetch(564 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 1073 */
} /* line 1073 */
  sim_icache_fetch(565 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_3, (unsigned int) -47); /* line 1075 */
} /* line 1075 */
  sim_icache_fetch(566 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1077 */
} /* line 1077 */
  sim_icache_fetch(567 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_2); /* line 1079 */
} /* line 1079 */
  sim_icache_fetch(568 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 1081 */
} /* line 1081 */
  sim_icache_fetch(569 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -48); /* line 1083 */
} /* line 1083 */
  sim_icache_fetch(570 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1085 */
} /* line 1085 */
  sim_icache_fetch(571 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 1087 */
} /* line 1087 */
  sim_icache_fetch(572 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_5); /* line 1089 */
} /* line 1089 */
  sim_icache_fetch(573 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, 0); /* line 1091 */
} /* line 1091 */
  sim_icache_fetch(574 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 3),0,1)); /* line 1093 */
} /* line 1093 */
  sim_icache_fetch(575 + t_thisfile.offset, 1);
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
} /* line 1095 */
  sim_icache_fetch(576 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 1); /* line 1097 */
} /* line 1097 */
  sim_icache_fetch(577 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1099 */
} /* line 1099 */
  sim_icache_fetch(578 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_10, (unsigned int) -47); /* line 1101 */
} /* line 1101 */
  sim_icache_fetch(579 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1103 */
} /* line 1103 */
  sim_icache_fetch(580 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_4); /* line 1105 */
} /* line 1105 */
  sim_icache_fetch(581 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_9, (unsigned int) 215); /* line 1107 */
} /* line 1107 */
  sim_icache_fetch(582 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 1109 */
} /* line 1109 */
  sim_icache_fetch(583 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1111 */
} /* line 1111 */
  sim_icache_fetch(584 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_12); /* line 1113 */
} /* line 1113 */
  sim_icache_fetch(585 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 1115 */
} /* line 1115 */
  sim_icache_fetch(586 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_12, mem_trace_ld((reg_r0_8 + (unsigned int) 2),0,1)); /* line 1117 */
} /* line 1117 */
  sim_icache_fetch(587 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_6, (unsigned int) 2); /* line 1119 */
} /* line 1119 */
  sim_icache_fetch(588 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_9, (unsigned int) -155); /* line 1121 */
} /* line 1121 */
  sim_icache_fetch(589 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_12, (unsigned int) -47); /* line 1123 */
} /* line 1123 */
  sim_icache_fetch(590 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1125 */
} /* line 1125 */
  sim_icache_fetch(591 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_13); /* line 1127 */
} /* line 1127 */
  sim_icache_fetch(592 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_11, (unsigned int) 215); /* line 1129 */
} /* line 1129 */
  sim_icache_fetch(593 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 1131 */
} /* line 1131 */
  sim_icache_fetch(594 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1133 */
} /* line 1133 */
  sim_icache_fetch(595 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_13); /* line 1135 */
} /* line 1135 */
  sim_icache_fetch(596 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 1137 */
} /* line 1137 */
  sim_icache_fetch(597 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 1),0,1)); /* line 1139 */
} /* line 1139 */
  sim_icache_fetch(598 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_2, reg_r0_6, (unsigned int) 3); /* line 1141 */
} /* line 1141 */
  sim_icache_fetch(599 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_11, (unsigned int) -155); /* line 1143 */
} /* line 1143 */
  sim_icache_fetch(600 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_10, (unsigned int) -47); /* line 1145 */
} /* line 1145 */
  sim_icache_fetch(601 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1147 */
} /* line 1147 */
  sim_icache_fetch(602 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_13); /* line 1149 */
} /* line 1149 */
  sim_icache_fetch(603 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_14, (unsigned int) 215); /* line 1151 */
} /* line 1151 */
  sim_icache_fetch(604 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_12, (unsigned int) -48); /* line 1153 */
} /* line 1153 */
  sim_icache_fetch(605 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1155 */
} /* line 1155 */
  sim_icache_fetch(606 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_13); /* line 1157 */
} /* line 1157 */
  sim_icache_fetch(607 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_15, reg_r0_12); /* line 1159 */
} /* line 1159 */
  sim_icache_fetch(608 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_8,0,1)); /* line 1161 */
} /* line 1161 */
  sim_icache_fetch(609 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) -4); /* line 1163 */
} /* line 1163 */
  sim_icache_fetch(610 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_10); /* line 1165 */
} /* line 1165 */
  sim_icache_fetch(611 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_14); /* line 1167 */
} /* line 1167 */
  sim_icache_fetch(612 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -4); /* line 1169 */
} /* line 1169 */
  sim_icache_fetch(613 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 12),0,4), reg_r0_9); /* line 1171 */
} /* line 1171 */
  sim_icache_fetch(614 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L33X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1173 */
  sim_icache_fetch(615 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 8),0,4), reg_r0_11); /* line 1175 */
} /* line 1175 */
  sim_icache_fetch(616 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L34X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1177 */
  sim_icache_fetch(617 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 4),0,4), reg_r0_14); /* line 1179 */
} /* line 1179 */
  sim_icache_fetch(618 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L35X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1181 */
  sim_icache_fetch(619 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_7,0,4), reg_r0_4); /* line 1183 */
} /* line 1183 */
  sim_icache_fetch(620 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -16); /* line 1186 */
} /* line 1186 */
  sim_icache_fetch(621 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L31X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L31X3;
} /* line 1188 */
l_L35X3: ;/* line 1191 */
LABEL(l_L35X3);
  sim_icache_fetch(622 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_19, (unsigned int) 4200); /* line 1193 */
} /* line 1193 */
  sim_icache_fetch(624 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L36X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L36X3;
} /* line 1195 */
l_L34X3: ;/* line 1198 */
LABEL(l_L34X3);
  sim_icache_fetch(625 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_19, (unsigned int) 4200); /* line 1200 */
} /* line 1200 */
  sim_icache_fetch(627 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L36X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L36X3;
} /* line 1202 */
l_L33X3: ;/* line 1205 */
LABEL(l_L33X3);
  sim_icache_fetch(628 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_19, (unsigned int) 4200); /* line 1207 */
} /* line 1207 */
  sim_icache_fetch(630 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L36X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L36X3;
} /* line 1209 */
l_L32X3: ;/* line 1212 */
LABEL(l_L32X3);
  sim_icache_fetch(631 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_19, (unsigned int) 4200); /* line 1213 */
} /* line 1213 */
l_L36X3: ;/* line 1215 */
LABEL(l_L36X3);
  sim_icache_fetch(633 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 1050); /* line 1216 */
} /* line 1216 */
  sim_icache_fetch(635 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 1); /* line 1218 */
} /* line 1218 */
  sim_icache_fetch(636 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_18); /* line 1221 */
} /* line 1221 */
  sim_icache_fetch(637 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L29X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L29X3;
} /* line 1223 */
l_L30X3: ;/* line 1226 */
LABEL(l_L30X3);
  sim_icache_fetch(638 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_20); /* line 1227 */
} /* line 1227 */
  sim_icache_fetch(639 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_2); /* line 1229 */
} /* line 1229 */
  sim_icache_fetch(640 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) qy2); /* line 1231 */
} /* line 1231 */
  sim_icache_fetch(642 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, (unsigned int) qy1); /* line 1233 */
} /* line 1233 */
  sim_icache_fetch(644 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, (unsigned int) qt); /* line 1235 */
} /* line 1235 */
  sim_icache_fetch(646 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_21); /* line 1237 */
} /* line 1237 */
l_L37X3: ;/* line 1240 */
LABEL(l_L37X3);
  sim_icache_fetch(647 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 1241 */
} /* line 1241 */
  sim_icache_fetch(648 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_11, (unsigned int) 3, reg_r0_9); /* line 1243 */
} /* line 1243 */
  sim_icache_fetch(649 + t_thisfile.offset, 1);
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
} /* line 1245 */
  sim_icache_fetch(650 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_11); /* line 1247 */
} /* line 1247 */
  sim_icache_fetch(651 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_7); /* line 1249 */
} /* line 1249 */
  sim_icache_fetch(652 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_8); /* line 1251 */
} /* line 1251 */
  sim_icache_fetch(653 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_10); /* line 1253 */
} /* line 1253 */
  sim_icache_fetch(654 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, reg_r0_3); /* line 1255 */
} /* line 1255 */
  sim_icache_fetch(655 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_9); /* line 1257 */
} /* line 1257 */
  sim_icache_fetch(656 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_7); /* line 1259 */
} /* line 1259 */
  sim_icache_fetch(657 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_8); /* line 1261 */
} /* line 1261 */
  sim_icache_fetch(658 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_10); /* line 1263 */
} /* line 1263 */
l_L39X3: ;/* line 1266 */
LABEL(l_L39X3);
  sim_icache_fetch(659 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 1267 */
} /* line 1267 */
  sim_icache_fetch(660 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld(reg_r0_4,0,4)); /* line 1269 */
} /* line 1269 */
  sim_icache_fetch(661 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 1271 */
} /* line 1271 */
  sim_icache_fetch(662 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 1273 */
} /* line 1273 */
  sim_icache_fetch(663 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_7); /* line 1275 */
} /* line 1275 */
  sim_icache_fetch(664 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 1277 */
} /* line 1277 */
  sim_icache_fetch(665 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 1279 */
} /* line 1279 */
  sim_icache_fetch(666 + t_thisfile.offset, 1);
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
} /* line 1281 */
  sim_icache_fetch(667 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 1283 */
} /* line 1283 */
  sim_icache_fetch(668 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 1285 */
} /* line 1285 */
  sim_icache_fetch(669 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 1287 */
} /* line 1287 */
  sim_icache_fetch(670 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 1289 */
} /* line 1289 */
  sim_icache_fetch(671 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, reg_r0_8); /* line 1291 */
} /* line 1291 */
  sim_icache_fetch(672 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 1293 */
} /* line 1293 */
  sim_icache_fetch(673 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 1295 */
} /* line 1295 */
  sim_icache_fetch(674 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 1297 */
} /* line 1297 */
  sim_icache_fetch(675 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_5, 0); /* line 1299 */
} /* line 1299 */
  sim_icache_fetch(676 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 1301 */
} /* line 1301 */
  sim_icache_fetch(677 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_8); /* line 1303 */
} /* line 1303 */
  sim_icache_fetch(678 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1305 */
} /* line 1305 */
  sim_icache_fetch(679 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1307 */
} /* line 1307 */
  sim_icache_fetch(680 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 1309 */
} /* line 1309 */
  sim_icache_fetch(681 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 1311 */
} /* line 1311 */
  sim_icache_fetch(682 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1313 */
} /* line 1313 */
  sim_icache_fetch(683 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_8); /* line 1315 */
} /* line 1315 */
  sim_icache_fetch(684 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1317 */
} /* line 1317 */
  sim_icache_fetch(685 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1319 */
} /* line 1319 */
  sim_icache_fetch(686 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 1321 */
} /* line 1321 */
  sim_icache_fetch(687 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_6,0,4), reg_r0_3); /* line 1323 */
} /* line 1323 */
  sim_icache_fetch(688 + t_thisfile.offset, 1);
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
} /* line 1325 */
  sim_icache_fetch(689 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 4),0,4), reg_r0_7); /* line 1327 */
} /* line 1327 */
  sim_icache_fetch(690 + t_thisfile.offset, 1);
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
} /* line 1329 */
  sim_icache_fetch(691 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 8),0,4), reg_r0_9); /* line 1331 */
} /* line 1331 */
  sim_icache_fetch(692 + t_thisfile.offset, 1);
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
} /* line 1333 */
  sim_icache_fetch(693 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 12),0,4), reg_r0_10); /* line 1335 */
} /* line 1335 */
  sim_icache_fetch(694 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 1338 */
} /* line 1338 */
  sim_icache_fetch(695 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L39X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L39X3;
} /* line 1340 */
l_L40X3: ;/* line 1343 */
LABEL(l_L40X3);
  sim_icache_fetch(696 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, (unsigned int) 4200); /* line 1344 */
} /* line 1344 */
  sim_icache_fetch(698 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_15, reg_r0_2); /* line 1346 */
} /* line 1346 */
  sim_icache_fetch(699 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_14, reg_r0_2); /* line 1348 */
} /* line 1348 */
  sim_icache_fetch(700 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_13, reg_r0_2); /* line 1350 */
} /* line 1350 */
  sim_icache_fetch(701 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 1352 */
} /* line 1352 */
  sim_icache_fetch(702 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_12); /* line 1355 */
} /* line 1355 */
  sim_icache_fetch(703 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L37X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L37X3;
} /* line 1357 */
l_L38X3: ;/* line 1360 */
LABEL(l_L38X3);
  sim_icache_fetch(704 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_9); /* line 1361 */
} /* line 1361 */
  sim_icache_fetch(705 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_2); /* line 1363 */
} /* line 1363 */
  sim_icache_fetch(706 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, (unsigned int) qt); /* line 1365 */
} /* line 1365 */
  sim_icache_fetch(708 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, (unsigned int) qy1); /* line 1367 */
} /* line 1367 */
  sim_icache_fetch(710 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_20); /* line 1369 */
} /* line 1369 */
  sim_icache_fetch(711 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_9); /* line 1371 */
} /* line 1371 */
l_L41X3: ;/* line 1374 */
LABEL(l_L41X3);
  sim_icache_fetch(712 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 1375 */
} /* line 1375 */
  sim_icache_fetch(713 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_13, (unsigned int) 3, reg_r0_10); /* line 1377 */
} /* line 1377 */
  sim_icache_fetch(714 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L42X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1379 */
  sim_icache_fetch(715 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_13); /* line 1381 */
} /* line 1381 */
  sim_icache_fetch(716 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_11); /* line 1383 */
} /* line 1383 */
  sim_icache_fetch(717 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_12); /* line 1385 */
} /* line 1385 */
  sim_icache_fetch(718 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, 0); /* line 1387 */
} /* line 1387 */
  sim_icache_fetch(719 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 1389 */
} /* line 1389 */
  sim_icache_fetch(720 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 1391 */
} /* line 1391 */
  sim_icache_fetch(721 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_3); /* line 1393 */
} /* line 1393 */
  sim_icache_fetch(722 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_10); /* line 1395 */
} /* line 1395 */
  sim_icache_fetch(723 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_11); /* line 1397 */
} /* line 1397 */
  sim_icache_fetch(724 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_12); /* line 1399 */
} /* line 1399 */
l_L43X3: ;/* line 1402 */
LABEL(l_L43X3);
  sim_icache_fetch(725 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 1403 */
} /* line 1403 */
  sim_icache_fetch(726 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1405 */
} /* line 1405 */
  sim_icache_fetch(727 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_5, (unsigned int) 215); /* line 1407 */
} /* line 1407 */
  sim_icache_fetch(728 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_3, (unsigned int) -48); /* line 1409 */
} /* line 1409 */
  sim_icache_fetch(729 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 1411 */
} /* line 1411 */
  sim_icache_fetch(730 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_10); /* line 1413 */
} /* line 1413 */
  sim_icache_fetch(731 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_6); /* line 1415 */
} /* line 1415 */
  sim_icache_fetch(732 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_9); /* line 1417 */
} /* line 1417 */
  sim_icache_fetch(733 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1419 */
} /* line 1419 */
  sim_icache_fetch(734 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 3); /* line 1421 */
} /* line 1421 */
  sim_icache_fetch(735 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 1423 */
} /* line 1423 */
  sim_icache_fetch(736 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L44X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1425 */
  sim_icache_fetch(737 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 1427 */
} /* line 1427 */
  sim_icache_fetch(739 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1429 */
} /* line 1429 */
  sim_icache_fetch(740 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 1431 */
} /* line 1431 */
  sim_icache_fetch(741 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_9, (unsigned int) -48); /* line 1433 */
} /* line 1433 */
  sim_icache_fetch(742 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 1435 */
} /* line 1435 */
  sim_icache_fetch(743 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 1437 */
} /* line 1437 */
  sim_icache_fetch(744 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_3); /* line 1439 */
} /* line 1439 */
  sim_icache_fetch(745 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 1441 */
} /* line 1441 */
  sim_icache_fetch(746 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1443 */
} /* line 1443 */
  sim_icache_fetch(747 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 1445 */
} /* line 1445 */
  sim_icache_fetch(748 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 8400),0,4)); /* line 1447 */
} /* line 1447 */
  sim_icache_fetch(750 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) -155); /* line 1449 */
} /* line 1449 */
  sim_icache_fetch(751 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_5, (unsigned int) 215); /* line 1451 */
} /* line 1451 */
  sim_icache_fetch(752 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_3, (unsigned int) -48); /* line 1453 */
} /* line 1453 */
  sim_icache_fetch(753 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 28); /* line 1455 */
} /* line 1455 */
  sim_icache_fetch(754 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_12); /* line 1457 */
} /* line 1457 */
  sim_icache_fetch(755 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_9); /* line 1459 */
} /* line 1459 */
  sim_icache_fetch(756 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 1461 */
} /* line 1461 */
  sim_icache_fetch(757 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1463 */
} /* line 1463 */
  sim_icache_fetch(758 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_7, 0); /* line 1465 */
} /* line 1465 */
  sim_icache_fetch(759 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 12600),0,4)); /* line 1467 */
} /* line 1467 */
  sim_icache_fetch(761 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_5, (unsigned int) -155); /* line 1469 */
} /* line 1469 */
  sim_icache_fetch(762 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_10, (unsigned int) 215); /* line 1471 */
} /* line 1471 */
  sim_icache_fetch(763 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_6, (unsigned int) -48); /* line 1473 */
} /* line 1473 */
  sim_icache_fetch(764 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 1475 */
} /* line 1475 */
  sim_icache_fetch(765 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_12); /* line 1477 */
} /* line 1477 */
  sim_icache_fetch(766 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 1479 */
} /* line 1479 */
  sim_icache_fetch(767 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_11); /* line 1481 */
} /* line 1481 */
  sim_icache_fetch(768 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1483 */
} /* line 1483 */
  sim_icache_fetch(769 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 1485 */
} /* line 1485 */
  sim_icache_fetch(770 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L44X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1487 */
  sim_icache_fetch(771 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_10); /* line 1489 */
} /* line 1489 */
  sim_icache_fetch(772 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16800); /* line 1491 */
} /* line 1491 */
  sim_icache_fetch(774 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1493 */
} /* line 1493 */
  sim_icache_fetch(775 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_5); /* line 1495 */
} /* line 1495 */
  sim_icache_fetch(777 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L44X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1497 */
  sim_icache_fetch(778 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_9); /* line 1499 */
} /* line 1499 */
  sim_icache_fetch(779 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_10); /* line 1501 */
} /* line 1501 */
  sim_icache_fetch(781 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L44X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1503 */
  sim_icache_fetch(782 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_9); /* line 1505 */
} /* line 1505 */
  sim_icache_fetch(784 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 16800); /* line 1508 */
} /* line 1508 */
  sim_icache_fetch(786 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L43X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L43X3;
} /* line 1510 */
l_L44X3: ;/* line 1513 */
LABEL(l_L44X3);
  sim_icache_fetch(787 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 1514 */
} /* line 1514 */
  sim_icache_fetch(788 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_15, (unsigned int) 4); /* line 1516 */
} /* line 1516 */
  sim_icache_fetch(789 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 1518 */
} /* line 1518 */
  sim_icache_fetch(790 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_14); /* line 1521 */
} /* line 1521 */
  sim_icache_fetch(791 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L41X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L41X3;
} /* line 1523 */
l_L42X3: ;/* line 1526 */
LABEL(l_L42X3);
  sim_icache_fetch(792 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_17); /* line 1527 */
} /* line 1527 */
  sim_icache_fetch(793 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, ((unsigned int) qy2 + (unsigned int) -12600)); /* line 1529 */
} /* line 1529 */
  sim_icache_fetch(795 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_10); /* line 1531 */
} /* line 1531 */
  sim_icache_fetch(796 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_2); /* line 1533 */
} /* line 1533 */
  sim_icache_fetch(797 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, ((unsigned int) qt + (unsigned int) -12600)); /* line 1535 */
} /* line 1535 */
  sim_icache_fetch(799 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_20, (unsigned int) -1); /* line 1537 */
} /* line 1537 */
  sim_icache_fetch(800 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_17); /* line 1539 */
} /* line 1539 */
l_L45X3: ;/* line 1542 */
LABEL(l_L45X3);
  sim_icache_fetch(801 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_10, 0); /* line 1543 */
} /* line 1543 */
  sim_icache_fetch(802 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULLU(reg_r0_14, reg_r0_11, (unsigned int) 4200); /* line 1545 */
} /* line 1545 */
  sim_icache_fetch(804 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L46X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1547 */
  sim_icache_fetch(805 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_12, reg_r0_14); /* line 1549 */
} /* line 1549 */
  sim_icache_fetch(806 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_13, reg_r0_14); /* line 1551 */
} /* line 1551 */
  sim_icache_fetch(807 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 1553 */
} /* line 1553 */
  sim_icache_fetch(808 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 1555 */
} /* line 1555 */
  sim_icache_fetch(809 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 1557 */
} /* line 1557 */
  sim_icache_fetch(810 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 1559 */
} /* line 1559 */
  sim_icache_fetch(811 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_11); /* line 1561 */
} /* line 1561 */
  sim_icache_fetch(812 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_10); /* line 1563 */
} /* line 1563 */
  sim_icache_fetch(813 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_11); /* line 1565 */
} /* line 1565 */
  sim_icache_fetch(814 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_12); /* line 1567 */
} /* line 1567 */
  sim_icache_fetch(815 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_13); /* line 1569 */
} /* line 1569 */
l_L47X3: ;/* line 1572 */
LABEL(l_L47X3);
  sim_icache_fetch(816 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 1573 */
} /* line 1573 */
  sim_icache_fetch(817 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_3, (unsigned int) -47); /* line 1575 */
} /* line 1575 */
  sim_icache_fetch(818 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 1577 */
} /* line 1577 */
  sim_icache_fetch(819 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_9); /* line 1579 */
} /* line 1579 */
  sim_icache_fetch(820 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 29); /* line 1581 */
} /* line 1581 */
  sim_icache_fetch(821 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, 0); /* line 1583 */
} /* line 1583 */
  sim_icache_fetch(822 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_5); /* line 1585 */
} /* line 1585 */
  sim_icache_fetch(823 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 1587 */
} /* line 1587 */
  sim_icache_fetch(824 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1589 */
} /* line 1589 */
  sim_icache_fetch(825 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1591 */
  sim_icache_fetch(826 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_9, mem_trace_ld((reg_r0_8 + (unsigned int) 12600),0,4)); /* line 1593 */
} /* line 1593 */
  sim_icache_fetch(828 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 1); /* line 1595 */
} /* line 1595 */
  sim_icache_fetch(829 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1597 */
} /* line 1597 */
  sim_icache_fetch(830 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_9, (unsigned int) -47); /* line 1599 */
} /* line 1599 */
  sim_icache_fetch(831 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 1601 */
} /* line 1601 */
  sim_icache_fetch(832 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_10); /* line 1603 */
} /* line 1603 */
  sim_icache_fetch(833 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 1605 */
} /* line 1605 */
  sim_icache_fetch(834 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 8400),0,4)); /* line 1607 */
} /* line 1607 */
  sim_icache_fetch(836 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 1609 */
} /* line 1609 */
  sim_icache_fetch(837 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_11); /* line 1611 */
} /* line 1611 */
  sim_icache_fetch(838 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1613 */
} /* line 1613 */
  sim_icache_fetch(839 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_6, (unsigned int) 2); /* line 1615 */
} /* line 1615 */
  sim_icache_fetch(840 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 1617 */
} /* line 1617 */
  sim_icache_fetch(841 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 1619 */
} /* line 1619 */
  sim_icache_fetch(842 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_4, (unsigned int) 215); /* line 1621 */
} /* line 1621 */
  sim_icache_fetch(843 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 1623 */
} /* line 1623 */
  sim_icache_fetch(844 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 29); /* line 1625 */
} /* line 1625 */
  sim_icache_fetch(845 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_8 + (unsigned int) 4200),0,4)); /* line 1627 */
} /* line 1627 */
  sim_icache_fetch(847 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, reg_r0_9); /* line 1629 */
} /* line 1629 */
  sim_icache_fetch(848 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 1631 */
} /* line 1631 */
  sim_icache_fetch(849 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1633 */
} /* line 1633 */
  sim_icache_fetch(850 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_2, reg_r0_6, (unsigned int) 3); /* line 1635 */
} /* line 1635 */
  sim_icache_fetch(851 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_4, (unsigned int) -155); /* line 1637 */
} /* line 1637 */
  sim_icache_fetch(852 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 1639 */
} /* line 1639 */
  sim_icache_fetch(853 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 1641 */
} /* line 1641 */
  sim_icache_fetch(854 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_13); /* line 1643 */
} /* line 1643 */
  sim_icache_fetch(855 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 1645 */
} /* line 1645 */
  sim_icache_fetch(856 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_8,0,4)); /* line 1647 */
} /* line 1647 */
  sim_icache_fetch(857 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 1649 */
} /* line 1649 */
  sim_icache_fetch(858 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_14); /* line 1651 */
} /* line 1651 */
  sim_icache_fetch(859 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1653 */
} /* line 1653 */
  sim_icache_fetch(860 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 12600),0,4), reg_r0_2); /* line 1655 */
} /* line 1655 */
  sim_icache_fetch(862 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1657 */
  sim_icache_fetch(863 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_11); /* line 1659 */
} /* line 1659 */
  sim_icache_fetch(864 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_12); /* line 1661 */
} /* line 1661 */
  sim_icache_fetch(865 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) -4); /* line 1663 */
} /* line 1663 */
  sim_icache_fetch(866 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16800); /* line 1665 */
} /* line 1665 */
  sim_icache_fetch(868 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 8400),0,4), reg_r0_4); /* line 1667 */
} /* line 1667 */
  sim_icache_fetch(870 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1669 */
  sim_icache_fetch(871 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_9); /* line 1671 */
} /* line 1671 */
  sim_icache_fetch(872 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 4200),0,4), reg_r0_11); /* line 1673 */
} /* line 1673 */
  sim_icache_fetch(874 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1675 */
  sim_icache_fetch(875 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_7,0,4), reg_r0_9); /* line 1677 */
} /* line 1677 */
  sim_icache_fetch(876 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -16800); /* line 1680 */
} /* line 1680 */
  sim_icache_fetch(878 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L47X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L47X3;
} /* line 1682 */
l_L48X3: ;/* line 1685 */
LABEL(l_L48X3);
  sim_icache_fetch(879 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 1686 */
} /* line 1686 */
  sim_icache_fetch(880 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 1688 */
} /* line 1688 */
  sim_icache_fetch(881 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1); /* line 1690 */
} /* line 1690 */
  sim_icache_fetch(882 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, reg_r0_16); /* line 1693 */
} /* line 1693 */
  sim_icache_fetch(883 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L45X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L45X3;
} /* line 1695 */
l_L46X3: ;/* line 1698 */
LABEL(l_L46X3);
  sim_icache_fetch(884 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_20, 0, reg_r0_20); /* line 1699 */
} /* line 1699 */
  sim_icache_fetch(885 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_20); /* line 1701 */
} /* line 1701 */
  sim_icache_fetch(886 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, (unsigned int) qy2); /* line 1703 */
} /* line 1703 */
  sim_icache_fetch(888 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) qy1); /* line 1705 */
} /* line 1705 */
  sim_icache_fetch(890 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, (unsigned int) out); /* line 1707 */
} /* line 1707 */
  sim_icache_fetch(892 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_19); /* line 1709 */
} /* line 1709 */
l_L49X3: ;/* line 1712 */
LABEL(l_L49X3);
  sim_icache_fetch(893 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 1713 */
} /* line 1713 */
  sim_icache_fetch(894 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_12, (unsigned int) 3, reg_r0_9); /* line 1715 */
} /* line 1715 */
  sim_icache_fetch(895 + t_thisfile.offset, 1);
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
} /* line 1717 */
  sim_icache_fetch(896 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_12); /* line 1719 */
} /* line 1719 */
  sim_icache_fetch(897 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_8); /* line 1721 */
} /* line 1721 */
  sim_icache_fetch(898 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_8); /* line 1723 */
} /* line 1723 */
  sim_icache_fetch(899 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_10); /* line 1725 */
} /* line 1725 */
  sim_icache_fetch(900 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_11); /* line 1727 */
} /* line 1727 */
  sim_icache_fetch(901 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_3); /* line 1729 */
} /* line 1729 */
  sim_icache_fetch(902 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_9); /* line 1731 */
} /* line 1731 */
  sim_icache_fetch(903 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_8); /* line 1733 */
} /* line 1733 */
  sim_icache_fetch(904 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_10); /* line 1735 */
} /* line 1735 */
  sim_icache_fetch(905 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_11); /* line 1737 */
} /* line 1737 */
l_L51X3: ;/* line 1740 */
LABEL(l_L51X3);
  sim_icache_fetch(906 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 1741 */
} /* line 1741 */
  sim_icache_fetch(907 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_4,0,4)); /* line 1743 */
} /* line 1743 */
  sim_icache_fetch(908 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 1745 */
} /* line 1745 */
  sim_icache_fetch(909 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 1747 */
} /* line 1747 */
  sim_icache_fetch(910 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_8); /* line 1749 */
} /* line 1749 */
  sim_icache_fetch(911 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 1751 */
} /* line 1751 */
  sim_icache_fetch(912 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 1753 */
} /* line 1753 */
  sim_icache_fetch(913 + t_thisfile.offset, 1);
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
} /* line 1755 */
  sim_icache_fetch(914 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_8, reg_r0_3); /* line 1757 */
} /* line 1757 */
  sim_icache_fetch(915 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_8, (unsigned int) 25); /* line 1759 */
} /* line 1759 */
  sim_icache_fetch(916 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 1761 */
} /* line 1761 */
  sim_icache_fetch(917 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 1763 */
} /* line 1763 */
  sim_icache_fetch(918 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_5, (unsigned int) 1); /* line 1765 */
} /* line 1765 */
  sim_icache_fetch(919 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 1767 */
} /* line 1767 */
  sim_icache_fetch(920 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_8); /* line 1769 */
} /* line 1769 */
  sim_icache_fetch(921 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1771 */
} /* line 1771 */
  sim_icache_fetch(922 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 1773 */
} /* line 1773 */
  sim_icache_fetch(923 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_8, reg_r0_9); /* line 1775 */
} /* line 1775 */
  sim_icache_fetch(924 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_3, reg_r0_8, (unsigned int) 25); /* line 1777 */
} /* line 1777 */
  sim_icache_fetch(925 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 1779 */
} /* line 1779 */
  sim_icache_fetch(926 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_4, reg_r0_5, 0); /* line 1781 */
} /* line 1781 */
  sim_icache_fetch(927 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 1783 */
} /* line 1783 */
  sim_icache_fetch(928 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 1785 */
} /* line 1785 */
  sim_icache_fetch(929 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1787 */
} /* line 1787 */
  sim_icache_fetch(930 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 1789 */
} /* line 1789 */
  sim_icache_fetch(931 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_11, reg_r0_10); /* line 1791 */
} /* line 1791 */
  sim_icache_fetch(932 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_5, reg_r0_11, (unsigned int) 25); /* line 1793 */
} /* line 1793 */
  sim_icache_fetch(933 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 1795 */
} /* line 1795 */
  sim_icache_fetch(934 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_6,0,1), reg_r0_3); /* line 1797 */
} /* line 1797 */
  sim_icache_fetch(935 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L53X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1799 */
  sim_icache_fetch(936 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, reg_r0_12); /* line 1801 */
} /* line 1801 */
  sim_icache_fetch(937 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 1803 */
} /* line 1803 */
  sim_icache_fetch(938 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 1805 */
} /* line 1805 */
  sim_icache_fetch(939 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_3, reg_r0_8); /* line 1807 */
} /* line 1807 */
  sim_icache_fetch(940 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 1809 */
} /* line 1809 */
  sim_icache_fetch(941 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_6,0,1), 0); /* line 1811 */
} /* line 1811 */
l_L54X3: ;/* line 1813 */
LABEL(l_L54X3);
  sim_icache_fetch(942 + t_thisfile.offset, 1);
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
} /* line 1814 */
  sim_icache_fetch(943 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), reg_r0_9); /* line 1816 */
} /* line 1816 */
  sim_icache_fetch(944 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L55X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1818 */
  sim_icache_fetch(945 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), 0); /* line 1820 */
} /* line 1820 */
l_L56X3: ;/* line 1822 */
LABEL(l_L56X3);
  sim_icache_fetch(946 + t_thisfile.offset, 1);
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
} /* line 1823 */
  sim_icache_fetch(947 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), reg_r0_10); /* line 1825 */
} /* line 1825 */
  sim_icache_fetch(948 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_5) {    BRANCHF(reg_b0_5);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L57X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1827 */
  sim_icache_fetch(949 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), 0); /* line 1829 */
} /* line 1829 */
l_L58X3: ;/* line 1831 */
LABEL(l_L58X3);
  sim_icache_fetch(950 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_4) {    BRANCHF(reg_b0_4);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1832 */
  sim_icache_fetch(951 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), reg_r0_8); /* line 1834 */
} /* line 1834 */
  sim_icache_fetch(952 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L59X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1836 */
  sim_icache_fetch(953 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 1838 */
} /* line 1838 */
  sim_icache_fetch(954 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1840 */
} /* line 1840 */
  sim_icache_fetch(955 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1842 */
} /* line 1842 */
  sim_icache_fetch(956 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 1844 */
} /* line 1844 */
  sim_icache_fetch(957 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), 0); /* line 1846 */
} /* line 1846 */
l_L60X3: ;/* line 1848 */
LABEL(l_L60X3);
  sim_icache_fetch(958 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 4); /* line 1850 */
} /* line 1850 */
  sim_icache_fetch(959 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L51X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L51X3;
} /* line 1852 */
l_L59X3: ;/* line 1855 */
LABEL(l_L59X3);
  sim_icache_fetch(960 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 1856 */
} /* line 1856 */
  sim_icache_fetch(961 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 1858 */
} /* line 1858 */
  sim_icache_fetch(962 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1860 */
} /* line 1860 */
  sim_icache_fetch(963 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 1862 */
} /* line 1862 */
  sim_icache_fetch(964 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 3),0,1), reg_r0_3); /* line 1864 */
} /* line 1864 */
  sim_icache_fetch(965 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1867 */
} /* line 1867 */
  sim_icache_fetch(966 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L60X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L60X3;
} /* line 1869 */
l_L52X3: ;/* line 1872 */
LABEL(l_L52X3);
  sim_icache_fetch(967 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4200); /* line 1873 */
} /* line 1873 */
  sim_icache_fetch(969 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 4200); /* line 1875 */
} /* line 1875 */
  sim_icache_fetch(971 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_15, (unsigned int) 1050); /* line 1877 */
} /* line 1877 */
  sim_icache_fetch(973 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 1879 */
} /* line 1879 */
  sim_icache_fetch(974 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_14); /* line 1882 */
} /* line 1882 */
  sim_icache_fetch(975 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L49X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L49X3;
} /* line 1884 */
l_L57X3: ;/* line 1887 */
LABEL(l_L57X3);
  sim_icache_fetch(976 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 1888 */
} /* line 1888 */
  sim_icache_fetch(977 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 2),0,1), reg_r0_3); /* line 1891 */
} /* line 1891 */
  sim_icache_fetch(978 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L58X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L58X3;
} /* line 1893 */
l_L55X3: ;/* line 1896 */
LABEL(l_L55X3);
  sim_icache_fetch(979 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 1897 */
} /* line 1897 */
  sim_icache_fetch(980 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 1),0,1), reg_r0_3); /* line 1900 */
} /* line 1900 */
  sim_icache_fetch(981 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L56X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L56X3;
} /* line 1902 */
l_L53X3: ;/* line 1905 */
LABEL(l_L53X3);
  sim_icache_fetch(982 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 1906 */
} /* line 1906 */
  sim_icache_fetch(983 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, reg_r0_12); /* line 1908 */
} /* line 1908 */
  sim_icache_fetch(984 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 1910 */
} /* line 1910 */
  sim_icache_fetch(985 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 1912 */
} /* line 1912 */
  sim_icache_fetch(986 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_11, reg_r0_8); /* line 1914 */
} /* line 1914 */
  sim_icache_fetch(987 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_11, (unsigned int) 25); /* line 1916 */
} /* line 1916 */
  sim_icache_fetch(988 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_7,0,1), reg_r0_3); /* line 1919 */
} /* line 1919 */
  sim_icache_fetch(989 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L54X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L54X3;
} /* line 1921 */
l_L50X3: ;/* line 1924 */
LABEL(l_L50X3);
  sim_icache_fetch(990 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_slow);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1926 */
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
    case 205: goto l_L35X3;
    case 206: goto l_L34X3;
    case 207: goto l_L33X3;
    case 208: goto l_L32X3;
    case 209: goto l_L36X3;
    case 210: goto l_L30X3;
    case 211: goto l_L37X3;
    case 212: goto l_L39X3;
    case 213: goto l_L40X3;
    case 214: goto l_L38X3;
    case 215: goto l_L41X3;
    case 216: goto l_L43X3;
    case 217: goto l_L44X3;
    case 218: goto l_L42X3;
    case 219: goto l_L45X3;
    case 220: goto l_L47X3;
    case 221: goto l_L48X3;
    case 222: goto l_L46X3;
    case 223: goto l_L49X3;
    case 224: goto l_L51X3;
    case 225: goto l_L54X3;
    case 226: goto l_L56X3;
    case 227: goto l_L58X3;
    case 228: goto l_L60X3;
    case 229: goto l_L59X3;
    case 230: goto l_L52X3;
    case 231: goto l_L57X3;
    case 232: goto l_L55X3;
    case 233: goto l_L53X3;
    case 234: goto l_L50X3;
    case 235:
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
  reg_l0_0 = (256 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(991 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 1941 */
  sim_icache_fetch(992 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 1943 */
} /* line 1943 */
  sim_icache_fetch(993 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_2); /* line 1945 */
} /* line 1945 */
  sim_icache_fetch(994 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_27, (unsigned int) in); /* line 1947 */
} /* line 1947 */
  sim_icache_fetch(996 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_26, (unsigned int) qy1); /* line 1949 */
} /* line 1949 */
  sim_icache_fetch(998 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_25, (unsigned int) qy2); /* line 1951 */
} /* line 1951 */
  sim_icache_fetch(1000 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_24, (unsigned int) qt); /* line 1953 */
} /* line 1953 */
  sim_icache_fetch(1002 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, ((unsigned int) qy2 + (unsigned int) -12)); /* line 1955 */
} /* line 1955 */
  sim_icache_fetch(1004 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_4, (unsigned int) -1); /* line 1957 */
} /* line 1957 */
  sim_icache_fetch(1005 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 1959 */
} /* line 1959 */
  sim_icache_fetch(1007 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_28, reg_r0_3); /* line 1961 */
} /* line 1961 */
  sim_icache_fetch(1008 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_23, reg_r0_4); /* line 1963 */
} /* line 1963 */
l_L61X3: ;/* line 1966 */
LABEL(l_L61X3);
  sim_icache_fetch(1009 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 1967 */
} /* line 1967 */
  sim_icache_fetch(1010 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_10, reg_r0_11); /* line 1969 */
} /* line 1969 */
  sim_icache_fetch(1011 + t_thisfile.offset, 1);
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
} /* line 1971 */
  sim_icache_fetch(1012 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_7, reg_r0_11, reg_r0_12); /* line 1973 */
} /* line 1973 */
  sim_icache_fetch(1013 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 1975 */
} /* line 1975 */
  sim_icache_fetch(1014 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 1977 */
} /* line 1977 */
  sim_icache_fetch(1015 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 1979 */
} /* line 1979 */
  sim_icache_fetch(1016 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 1981 */
} /* line 1981 */
  sim_icache_fetch(1017 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, 0); /* line 1983 */
} /* line 1983 */
  sim_icache_fetch(1018 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, 0); /* line 1985 */
} /* line 1985 */
  sim_icache_fetch(1019 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, 0); /* line 1987 */
} /* line 1987 */
  sim_icache_fetch(1020 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_11); /* line 1989 */
} /* line 1989 */
  sim_icache_fetch(1021 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_9); /* line 1991 */
} /* line 1991 */
  sim_icache_fetch(1022 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_10); /* line 1993 */
} /* line 1993 */
  sim_icache_fetch(1023 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_11); /* line 1995 */
} /* line 1995 */
  sim_icache_fetch(1024 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_12); /* line 1997 */
} /* line 1997 */
l_L63X3: ;/* line 2000 */
LABEL(l_L63X3);
  sim_icache_fetch(1025 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2001 */
} /* line 2001 */
  sim_icache_fetch(1026 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_3, (unsigned int) -47); /* line 2003 */
} /* line 2003 */
  sim_icache_fetch(1027 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2005 */
} /* line 2005 */
  sim_icache_fetch(1028 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_2); /* line 2007 */
} /* line 2007 */
  sim_icache_fetch(1029 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 2009 */
} /* line 2009 */
  sim_icache_fetch(1030 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -48); /* line 2011 */
} /* line 2011 */
  sim_icache_fetch(1031 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2013 */
} /* line 2013 */
  sim_icache_fetch(1032 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 2015 */
} /* line 2015 */
  sim_icache_fetch(1033 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_5); /* line 2017 */
} /* line 2017 */
  sim_icache_fetch(1034 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, 0); /* line 2019 */
} /* line 2019 */
  sim_icache_fetch(1035 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 3),0,1)); /* line 2021 */
} /* line 2021 */
  sim_icache_fetch(1036 + t_thisfile.offset, 1);
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
} /* line 2023 */
  sim_icache_fetch(1037 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 1); /* line 2025 */
} /* line 2025 */
  sim_icache_fetch(1038 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2027 */
} /* line 2027 */
  sim_icache_fetch(1039 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_10, (unsigned int) -47); /* line 2029 */
} /* line 2029 */
  sim_icache_fetch(1040 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2031 */
} /* line 2031 */
  sim_icache_fetch(1041 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_4); /* line 2033 */
} /* line 2033 */
  sim_icache_fetch(1042 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_9, (unsigned int) 215); /* line 2035 */
} /* line 2035 */
  sim_icache_fetch(1043 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 2037 */
} /* line 2037 */
  sim_icache_fetch(1044 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2039 */
} /* line 2039 */
  sim_icache_fetch(1045 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_12); /* line 2041 */
} /* line 2041 */
  sim_icache_fetch(1046 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 2043 */
} /* line 2043 */
  sim_icache_fetch(1047 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_12, mem_trace_ld((reg_r0_8 + (unsigned int) 2),0,1)); /* line 2045 */
} /* line 2045 */
  sim_icache_fetch(1048 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_6, (unsigned int) 2); /* line 2047 */
} /* line 2047 */
  sim_icache_fetch(1049 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_9, (unsigned int) -155); /* line 2049 */
} /* line 2049 */
  sim_icache_fetch(1050 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_12, (unsigned int) -47); /* line 2051 */
} /* line 2051 */
  sim_icache_fetch(1051 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2053 */
} /* line 2053 */
  sim_icache_fetch(1052 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_13); /* line 2055 */
} /* line 2055 */
  sim_icache_fetch(1053 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_11, (unsigned int) 215); /* line 2057 */
} /* line 2057 */
  sim_icache_fetch(1054 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 2059 */
} /* line 2059 */
  sim_icache_fetch(1055 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2061 */
} /* line 2061 */
  sim_icache_fetch(1056 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_13); /* line 2063 */
} /* line 2063 */
  sim_icache_fetch(1057 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 2065 */
} /* line 2065 */
  sim_icache_fetch(1058 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 1),0,1)); /* line 2067 */
} /* line 2067 */
  sim_icache_fetch(1059 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_2, reg_r0_6, (unsigned int) 3); /* line 2069 */
} /* line 2069 */
  sim_icache_fetch(1060 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_11, (unsigned int) -155); /* line 2071 */
} /* line 2071 */
  sim_icache_fetch(1061 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_10, (unsigned int) -47); /* line 2073 */
} /* line 2073 */
  sim_icache_fetch(1062 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2075 */
} /* line 2075 */
  sim_icache_fetch(1063 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_13); /* line 2077 */
} /* line 2077 */
  sim_icache_fetch(1064 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_14, (unsigned int) 215); /* line 2079 */
} /* line 2079 */
  sim_icache_fetch(1065 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_12, (unsigned int) -48); /* line 2081 */
} /* line 2081 */
  sim_icache_fetch(1066 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2083 */
} /* line 2083 */
  sim_icache_fetch(1067 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_13); /* line 2085 */
} /* line 2085 */
  sim_icache_fetch(1068 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_15, reg_r0_12); /* line 2087 */
} /* line 2087 */
  sim_icache_fetch(1069 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_8,0,1)); /* line 2089 */
} /* line 2089 */
  sim_icache_fetch(1070 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_14); /* line 2091 */
} /* line 2091 */
  sim_icache_fetch(1071 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_10); /* line 2093 */
} /* line 2093 */
  sim_icache_fetch(1072 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) -4); /* line 2095 */
} /* line 2095 */
  sim_icache_fetch(1073 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -4); /* line 2097 */
} /* line 2097 */
  sim_icache_fetch(1074 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 12),0,4), reg_r0_9); /* line 2099 */
} /* line 2099 */
  sim_icache_fetch(1075 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L65X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2101 */
  sim_icache_fetch(1076 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 8),0,4), reg_r0_11); /* line 2103 */
} /* line 2103 */
  sim_icache_fetch(1077 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2105 */
  sim_icache_fetch(1078 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 4),0,4), reg_r0_14); /* line 2107 */
} /* line 2107 */
  sim_icache_fetch(1079 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L67X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2109 */
  sim_icache_fetch(1080 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_7,0,4), reg_r0_4); /* line 2111 */
} /* line 2111 */
  sim_icache_fetch(1081 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -16); /* line 2114 */
} /* line 2114 */
  sim_icache_fetch(1082 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L63X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L63X3;
} /* line 2116 */
l_L67X3: ;/* line 2119 */
LABEL(l_L67X3);
  sim_icache_fetch(1083 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_23); /* line 2121 */
} /* line 2121 */
  sim_icache_fetch(1084 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L68X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L68X3;
} /* line 2123 */
l_L69X3: ;/* line 2126 */
LABEL(l_L69X3);
  sim_icache_fetch(1085 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 2127 */
} /* line 2127 */
  sim_icache_fetch(1086 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_4, (unsigned int) 215); /* line 2129 */
} /* line 2129 */
  sim_icache_fetch(1087 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2131 */
} /* line 2131 */
  sim_icache_fetch(1088 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_3, (unsigned int) -48); /* line 2133 */
} /* line 2133 */
  sim_icache_fetch(1089 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2135 */
} /* line 2135 */
  sim_icache_fetch(1090 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_11); /* line 2137 */
} /* line 2137 */
  sim_icache_fetch(1091 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2139 */
} /* line 2139 */
  sim_icache_fetch(1092 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 2141 */
} /* line 2141 */
  sim_icache_fetch(1093 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_11, mem_trace_ld(reg_r0_7,0,4)); /* line 2143 */
} /* line 2143 */
  sim_icache_fetch(1094 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_5); /* line 2145 */
} /* line 2145 */
  sim_icache_fetch(1095 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_12); /* line 2147 */
} /* line 2147 */
  sim_icache_fetch(1096 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_6, reg_r0_11); /* line 2149 */
} /* line 2149 */
  sim_icache_fetch(1097 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2151 */
} /* line 2151 */
  sim_icache_fetch(1098 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2153 */
} /* line 2153 */
  sim_icache_fetch(1099 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 2); /* line 2155 */
} /* line 2155 */
  sim_icache_fetch(1100 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 1); /* line 2157 */
} /* line 2157 */
  sim_icache_fetch(1101 + t_thisfile.offset, 1);
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
} /* line 2159 */
  sim_icache_fetch(1102 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_12, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 2161 */
} /* line 2161 */
  sim_icache_fetch(1103 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_6, (unsigned int) 215); /* line 2163 */
} /* line 2163 */
  sim_icache_fetch(1104 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2165 */
} /* line 2165 */
  sim_icache_fetch(1105 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_12, (unsigned int) -48); /* line 2167 */
} /* line 2167 */
  sim_icache_fetch(1106 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2169 */
} /* line 2169 */
  sim_icache_fetch(1107 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_13); /* line 2171 */
} /* line 2171 */
  sim_icache_fetch(1108 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2173 */
} /* line 2173 */
  sim_icache_fetch(1109 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2175 */
} /* line 2175 */
  sim_icache_fetch(1110 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_13, mem_trace_ld((reg_r0_7 + (unsigned int) 4),0,4)); /* line 2177 */
} /* line 2177 */
  sim_icache_fetch(1111 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 2179 */
} /* line 2179 */
  sim_icache_fetch(1112 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_14); /* line 2181 */
} /* line 2181 */
  sim_icache_fetch(1113 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_3, reg_r0_13); /* line 2183 */
} /* line 2183 */
  sim_icache_fetch(1114 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2185 */
} /* line 2185 */
  sim_icache_fetch(1115 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2187 */
} /* line 2187 */
  sim_icache_fetch(1116 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_8, 0); /* line 2189 */
} /* line 2189 */
  sim_icache_fetch(1117 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 2191 */
} /* line 2191 */
  sim_icache_fetch(1118 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_3, (unsigned int) 215); /* line 2193 */
} /* line 2193 */
  sim_icache_fetch(1119 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_16, reg_r0_6, (unsigned int) -155); /* line 2195 */
} /* line 2195 */
  sim_icache_fetch(1120 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_17, reg_r0_14, (unsigned int) -48); /* line 2197 */
} /* line 2197 */
  sim_icache_fetch(1121 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2199 */
} /* line 2199 */
  sim_icache_fetch(1122 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_17, reg_r0_17, reg_r0_15); /* line 2201 */
} /* line 2201 */
  sim_icache_fetch(1123 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 2203 */
} /* line 2203 */
  sim_icache_fetch(1124 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_12, (unsigned int) 28); /* line 2205 */
} /* line 2205 */
  sim_icache_fetch(1125 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_15, mem_trace_ld((reg_r0_7 + (unsigned int) 8),0,4)); /* line 2207 */
} /* line 2207 */
  sim_icache_fetch(1126 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_16); /* line 2209 */
} /* line 2209 */
  sim_icache_fetch(1127 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_12, reg_r0_17); /* line 2211 */
} /* line 2211 */
  sim_icache_fetch(1128 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_4, reg_r0_15); /* line 2213 */
} /* line 2213 */
  sim_icache_fetch(1129 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2215 */
} /* line 2215 */
  sim_icache_fetch(1130 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2217 */
} /* line 2217 */
  sim_icache_fetch(1131 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_3); /* line 2219 */
} /* line 2219 */
  sim_icache_fetch(1132 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 3); /* line 2221 */
} /* line 2221 */
  sim_icache_fetch(1133 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 12); /* line 2223 */
} /* line 2223 */
  sim_icache_fetch(1134 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 3); /* line 2225 */
} /* line 2225 */
  sim_icache_fetch(1135 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_6); /* line 2227 */
} /* line 2227 */
  sim_icache_fetch(1136 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_14); /* line 2229 */
} /* line 2229 */
  sim_icache_fetch(1137 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_9,0,4), reg_r0_11); /* line 2231 */
} /* line 2231 */
  sim_icache_fetch(1138 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2233 */
  sim_icache_fetch(1139 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4),0,4), reg_r0_3); /* line 2235 */
} /* line 2235 */
  sim_icache_fetch(1140 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 4),0,4), reg_r0_13); /* line 2237 */
} /* line 2237 */
  sim_icache_fetch(1141 + t_thisfile.offset, 1);
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
} /* line 2239 */
  sim_icache_fetch(1142 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 8),0,4), reg_r0_4); /* line 2241 */
} /* line 2241 */
  sim_icache_fetch(1143 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 12); /* line 2243 */
} /* line 2243 */
  sim_icache_fetch(1144 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 8),0,4), reg_r0_15); /* line 2245 */
} /* line 2245 */
  sim_icache_fetch(1145 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 12); /* line 2248 */
} /* line 2248 */
  sim_icache_fetch(1146 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L69X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L69X3;
} /* line 2250 */
l_L70X3: ;/* line 2253 */
LABEL(l_L70X3);
  sim_icache_fetch(1147 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_27, reg_r0_27, (unsigned int) 1050); /* line 2254 */
} /* line 2254 */
  sim_icache_fetch(1149 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2256 */
} /* line 2256 */
  sim_icache_fetch(1151 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_26, reg_r0_26, reg_r0_2); /* line 2258 */
} /* line 2258 */
  sim_icache_fetch(1152 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_25, reg_r0_25, reg_r0_2); /* line 2260 */
} /* line 2260 */
  sim_icache_fetch(1153 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_24, reg_r0_24, reg_r0_2); /* line 2262 */
} /* line 2262 */
  sim_icache_fetch(1154 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_19, reg_r0_2); /* line 2264 */
} /* line 2264 */
  sim_icache_fetch(1155 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_20, (unsigned int) 1050); /* line 2266 */
} /* line 2266 */
  sim_icache_fetch(1157 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_21, (unsigned int) 1); /* line 2268 */
} /* line 2268 */
  sim_icache_fetch(1158 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, reg_r0_18); /* line 2271 */
} /* line 2271 */
  sim_icache_fetch(1159 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L61X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L61X3;
} /* line 2273 */
l_L66X3: ;/* line 2276 */
LABEL(l_L66X3);
  sim_icache_fetch(1160 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_23); /* line 2278 */
} /* line 2278 */
  sim_icache_fetch(1161 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L68X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L68X3;
} /* line 2280 */
l_L65X3: ;/* line 2283 */
LABEL(l_L65X3);
  sim_icache_fetch(1162 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_23); /* line 2285 */
} /* line 2285 */
  sim_icache_fetch(1163 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L68X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L68X3;
} /* line 2287 */
l_L64X3: ;/* line 2290 */
LABEL(l_L64X3);
  sim_icache_fetch(1164 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_23); /* line 2291 */
} /* line 2291 */
l_L68X3: ;/* line 2293 */
LABEL(l_L68X3);
  sim_icache_fetch(1165 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_3); /* line 2294 */
} /* line 2294 */
  sim_icache_fetch(1166 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_24); /* line 2296 */
} /* line 2296 */
  sim_icache_fetch(1167 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_25); /* line 2298 */
} /* line 2298 */
  sim_icache_fetch(1168 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_26); /* line 2300 */
} /* line 2300 */
  sim_icache_fetch(1169 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_27); /* line 2302 */
} /* line 2302 */
  sim_icache_fetch(1170 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_20); /* line 2304 */
} /* line 2304 */
  sim_icache_fetch(1171 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_21); /* line 2306 */
} /* line 2306 */
  sim_icache_fetch(1172 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_22); /* line 2308 */
} /* line 2308 */
  sim_icache_fetch(1173 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_17); /* line 2310 */
} /* line 2310 */
  sim_icache_fetch(1174 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, reg_r0_16); /* line 2313 */
} /* line 2313 */
  sim_icache_fetch(1175 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L69X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L69X3;
} /* line 2315 */
l_L62X3: ;/* line 2318 */
LABEL(l_L62X3);
  sim_icache_fetch(1176 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_23, 0, reg_r0_23); /* line 2319 */
} /* line 2319 */
  sim_icache_fetch(1177 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_23); /* line 2321 */
} /* line 2321 */
  sim_icache_fetch(1178 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_26, (unsigned int) qt); /* line 2323 */
} /* line 2323 */
  sim_icache_fetch(1180 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_25, (unsigned int) qy1); /* line 2325 */
} /* line 2325 */
  sim_icache_fetch(1182 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_24, (unsigned int) qy2); /* line 2327 */
} /* line 2327 */
  sim_icache_fetch(1184 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_23, (unsigned int) out); /* line 2329 */
} /* line 2329 */
  sim_icache_fetch(1186 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, ((unsigned int) qy2 + (unsigned int) -12600)); /* line 2331 */
} /* line 2331 */
  sim_icache_fetch(1188 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, ((unsigned int) qt + (unsigned int) -12600)); /* line 2333 */
} /* line 2333 */
  sim_icache_fetch(1190 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_28, (unsigned int) -1); /* line 2335 */
} /* line 2335 */
  sim_icache_fetch(1191 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, reg_r0_28); /* line 2337 */
} /* line 2337 */
l_L71X3: ;/* line 2340 */
LABEL(l_L71X3);
  sim_icache_fetch(1192 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 2341 */
} /* line 2341 */
  sim_icache_fetch(1193 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULLU(reg_r0_13, reg_r0_10, (unsigned int) 4200); /* line 2343 */
} /* line 2343 */
  sim_icache_fetch(1195 + t_thisfile.offset, 1);
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
} /* line 2345 */
  sim_icache_fetch(1196 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_11, reg_r0_13); /* line 2347 */
} /* line 2347 */
  sim_icache_fetch(1197 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_12, reg_r0_13); /* line 2349 */
} /* line 2349 */
  sim_icache_fetch(1198 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 2351 */
} /* line 2351 */
  sim_icache_fetch(1199 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 2353 */
} /* line 2353 */
  sim_icache_fetch(1200 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 2355 */
} /* line 2355 */
  sim_icache_fetch(1201 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 2357 */
} /* line 2357 */
  sim_icache_fetch(1202 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, 0); /* line 2359 */
} /* line 2359 */
  sim_icache_fetch(1203 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, 0); /* line 2361 */
} /* line 2361 */
  sim_icache_fetch(1204 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, 0); /* line 2363 */
} /* line 2363 */
  sim_icache_fetch(1205 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_10); /* line 2365 */
} /* line 2365 */
  sim_icache_fetch(1206 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_9); /* line 2367 */
} /* line 2367 */
  sim_icache_fetch(1207 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_10); /* line 2369 */
} /* line 2369 */
  sim_icache_fetch(1208 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_11); /* line 2371 */
} /* line 2371 */
  sim_icache_fetch(1209 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_12); /* line 2373 */
} /* line 2373 */
l_L73X3: ;/* line 2376 */
LABEL(l_L73X3);
  sim_icache_fetch(1210 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2377 */
} /* line 2377 */
  sim_icache_fetch(1211 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_3, (unsigned int) -47); /* line 2379 */
} /* line 2379 */
  sim_icache_fetch(1212 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 2381 */
} /* line 2381 */
  sim_icache_fetch(1213 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2383 */
} /* line 2383 */
  sim_icache_fetch(1214 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 29); /* line 2385 */
} /* line 2385 */
  sim_icache_fetch(1215 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, 0); /* line 2387 */
} /* line 2387 */
  sim_icache_fetch(1216 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_5); /* line 2389 */
} /* line 2389 */
  sim_icache_fetch(1217 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 2391 */
} /* line 2391 */
  sim_icache_fetch(1218 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2393 */
} /* line 2393 */
  sim_icache_fetch(1219 + t_thisfile.offset, 1);
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
} /* line 2395 */
  sim_icache_fetch(1220 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_9, mem_trace_ld((reg_r0_8 + (unsigned int) 12600),0,4)); /* line 2397 */
} /* line 2397 */
  sim_icache_fetch(1222 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 1); /* line 2399 */
} /* line 2399 */
  sim_icache_fetch(1223 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2401 */
} /* line 2401 */
  sim_icache_fetch(1224 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_9, (unsigned int) -47); /* line 2403 */
} /* line 2403 */
  sim_icache_fetch(1225 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 2405 */
} /* line 2405 */
  sim_icache_fetch(1226 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_10); /* line 2407 */
} /* line 2407 */
  sim_icache_fetch(1227 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 2409 */
} /* line 2409 */
  sim_icache_fetch(1228 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 8400),0,4)); /* line 2411 */
} /* line 2411 */
  sim_icache_fetch(1230 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 2413 */
} /* line 2413 */
  sim_icache_fetch(1231 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_11); /* line 2415 */
} /* line 2415 */
  sim_icache_fetch(1232 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2417 */
} /* line 2417 */
  sim_icache_fetch(1233 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_6, (unsigned int) 2); /* line 2419 */
} /* line 2419 */
  sim_icache_fetch(1234 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 2421 */
} /* line 2421 */
  sim_icache_fetch(1235 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 2423 */
} /* line 2423 */
  sim_icache_fetch(1236 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_4, (unsigned int) 215); /* line 2425 */
} /* line 2425 */
  sim_icache_fetch(1237 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 2427 */
} /* line 2427 */
  sim_icache_fetch(1238 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 29); /* line 2429 */
} /* line 2429 */
  sim_icache_fetch(1239 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_8 + (unsigned int) 4200),0,4)); /* line 2431 */
} /* line 2431 */
  sim_icache_fetch(1241 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, reg_r0_9); /* line 2433 */
} /* line 2433 */
  sim_icache_fetch(1242 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 2435 */
} /* line 2435 */
  sim_icache_fetch(1243 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2437 */
} /* line 2437 */
  sim_icache_fetch(1244 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_2, reg_r0_6, (unsigned int) 3); /* line 2439 */
} /* line 2439 */
  sim_icache_fetch(1245 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_4, (unsigned int) -155); /* line 2441 */
} /* line 2441 */
  sim_icache_fetch(1246 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 2443 */
} /* line 2443 */
  sim_icache_fetch(1247 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 2445 */
} /* line 2445 */
  sim_icache_fetch(1248 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_13); /* line 2447 */
} /* line 2447 */
  sim_icache_fetch(1249 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 2449 */
} /* line 2449 */
  sim_icache_fetch(1250 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_8,0,4)); /* line 2451 */
} /* line 2451 */
  sim_icache_fetch(1251 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 2453 */
} /* line 2453 */
  sim_icache_fetch(1252 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_14); /* line 2455 */
} /* line 2455 */
  sim_icache_fetch(1253 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2457 */
} /* line 2457 */
  sim_icache_fetch(1254 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) -4); /* line 2459 */
} /* line 2459 */
  sim_icache_fetch(1255 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 12600),0,4), reg_r0_2); /* line 2461 */
} /* line 2461 */
  sim_icache_fetch(1257 + t_thisfile.offset, 1);
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
} /* line 2463 */
  sim_icache_fetch(1258 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_11); /* line 2465 */
} /* line 2465 */
  sim_icache_fetch(1259 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_12); /* line 2467 */
} /* line 2467 */
  sim_icache_fetch(1260 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16800); /* line 2469 */
} /* line 2469 */
  sim_icache_fetch(1262 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 8400),0,4), reg_r0_4); /* line 2471 */
} /* line 2471 */
  sim_icache_fetch(1264 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2473 */
  sim_icache_fetch(1265 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_9); /* line 2475 */
} /* line 2475 */
  sim_icache_fetch(1266 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 4200),0,4), reg_r0_11); /* line 2477 */
} /* line 2477 */
  sim_icache_fetch(1268 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2479 */
  sim_icache_fetch(1269 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_7,0,4), reg_r0_9); /* line 2481 */
} /* line 2481 */
  sim_icache_fetch(1270 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -16800); /* line 2484 */
} /* line 2484 */
  sim_icache_fetch(1272 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L73X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L73X3;
} /* line 2486 */
l_L74X3: ;/* line 2489 */
LABEL(l_L74X3);
  sim_icache_fetch(1273 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_22); /* line 2490 */
} /* line 2490 */
  sim_icache_fetch(1274 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_3); /* line 2492 */
} /* line 2492 */
  sim_icache_fetch(1275 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_23); /* line 2494 */
} /* line 2494 */
  sim_icache_fetch(1276 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_24); /* line 2496 */
} /* line 2496 */
  sim_icache_fetch(1277 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_25); /* line 2498 */
} /* line 2498 */
  sim_icache_fetch(1278 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_26); /* line 2500 */
} /* line 2500 */
  sim_icache_fetch(1279 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_20); /* line 2502 */
} /* line 2502 */
  sim_icache_fetch(1280 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_19); /* line 2504 */
} /* line 2504 */
  sim_icache_fetch(1281 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_21); /* line 2506 */
} /* line 2506 */
  sim_icache_fetch(1282 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, (unsigned int) 8400); /* line 2508 */
} /* line 2508 */
  sim_icache_fetch(1284 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_17); /* line 2510 */
} /* line 2510 */
  sim_icache_fetch(1285 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_16); /* line 2512 */
} /* line 2512 */
  sim_icache_fetch(1286 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_15); /* line 2514 */
} /* line 2514 */
l_L75X3: ;/* line 2517 */
LABEL(l_L75X3);
  sim_icache_fetch(1287 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2518 */
} /* line 2518 */
  sim_icache_fetch(1288 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2520 */
} /* line 2520 */
  sim_icache_fetch(1289 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_5, (unsigned int) 215); /* line 2522 */
} /* line 2522 */
  sim_icache_fetch(1290 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -48); /* line 2524 */
} /* line 2524 */
  sim_icache_fetch(1291 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 2526 */
} /* line 2526 */
  sim_icache_fetch(1292 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 2528 */
} /* line 2528 */
  sim_icache_fetch(1293 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_6); /* line 2530 */
} /* line 2530 */
  sim_icache_fetch(1294 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_12); /* line 2532 */
} /* line 2532 */
  sim_icache_fetch(1295 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2534 */
} /* line 2534 */
  sim_icache_fetch(1296 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_12, mem_trace_ld(reg_r0_7,0,4)); /* line 2536 */
} /* line 2536 */
  sim_icache_fetch(1297 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 2538 */
} /* line 2538 */
  sim_icache_fetch(1298 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_8, 0); /* line 2540 */
} /* line 2540 */
  sim_icache_fetch(1299 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_4, reg_r0_12); /* line 2542 */
} /* line 2542 */
  sim_icache_fetch(1300 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2544 */
} /* line 2544 */
  sim_icache_fetch(1301 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 2546 */
} /* line 2546 */
  sim_icache_fetch(1302 + t_thisfile.offset, 1);
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
} /* line 2548 */
  sim_icache_fetch(1303 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_13, reg_r0_12); /* line 2550 */
} /* line 2550 */
  sim_icache_fetch(1304 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_13, (unsigned int) 25); /* line 2552 */
} /* line 2552 */
  sim_icache_fetch(1305 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 2554 */
} /* line 2554 */
  sim_icache_fetch(1307 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_5, (unsigned int) -155); /* line 2556 */
} /* line 2556 */
  sim_icache_fetch(1308 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_4, (unsigned int) 215); /* line 2558 */
} /* line 2558 */
  sim_icache_fetch(1309 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_6, (unsigned int) -48); /* line 2560 */
} /* line 2560 */
  sim_icache_fetch(1310 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_16, reg_r0_3, (unsigned int) 28); /* line 2562 */
} /* line 2562 */
  sim_icache_fetch(1311 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 2564 */
} /* line 2564 */
  sim_icache_fetch(1312 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_16); /* line 2566 */
} /* line 2566 */
  sim_icache_fetch(1313 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, reg_r0_14); /* line 2568 */
} /* line 2568 */
  sim_icache_fetch(1314 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_14, mem_trace_ld((reg_r0_7 + (unsigned int) 4200),0,4)); /* line 2570 */
} /* line 2570 */
  sim_icache_fetch(1316 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_4); /* line 2572 */
} /* line 2572 */
  sim_icache_fetch(1317 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_12); /* line 2574 */
} /* line 2574 */
  sim_icache_fetch(1318 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_4); /* line 2576 */
} /* line 2576 */
  sim_icache_fetch(1319 + t_thisfile.offset, 1);
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
} /* line 2578 */
  sim_icache_fetch(1320 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_13, (unsigned int) 8); /* line 2580 */
} /* line 2580 */
  sim_icache_fetch(1321 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_5, reg_r0_14); /* line 2582 */
} /* line 2582 */
  sim_icache_fetch(1322 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 2584 */
} /* line 2584 */
  sim_icache_fetch(1323 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 2586 */
} /* line 2586 */
  sim_icache_fetch(1324 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_3, reg_r0_14); /* line 2588 */
} /* line 2588 */
  sim_icache_fetch(1325 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 2590 */
} /* line 2590 */
  sim_icache_fetch(1326 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_15); /* line 2592 */
} /* line 2592 */
  sim_icache_fetch(1327 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), 0); /* line 2594 */
} /* line 2594 */
l_L78X3: ;/* line 2596 */
LABEL(l_L78X3);
  sim_icache_fetch(1328 + t_thisfile.offset, 1);
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
} /* line 2597 */
  sim_icache_fetch(1329 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4200),0,4), reg_r0_5); /* line 2599 */
} /* line 2599 */
  sim_icache_fetch(1331 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_14); /* line 2601 */
} /* line 2601 */
  sim_icache_fetch(1333 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2603 */
  sim_icache_fetch(1334 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_11); /* line 2605 */
} /* line 2605 */
  sim_icache_fetch(1335 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 2607 */
} /* line 2607 */
  sim_icache_fetch(1336 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, reg_r0_11); /* line 2609 */
} /* line 2609 */
  sim_icache_fetch(1337 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 2611 */
} /* line 2611 */
  sim_icache_fetch(1338 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), 0); /* line 2613 */
} /* line 2613 */
l_L80X3: ;/* line 2615 */
LABEL(l_L80X3);
  sim_icache_fetch(1340 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 2100); /* line 2617 */
} /* line 2617 */
  sim_icache_fetch(1342 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L75X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L75X3;
} /* line 2619 */
l_L79X3: ;/* line 2622 */
LABEL(l_L79X3);
  sim_icache_fetch(1343 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 2623 */
} /* line 2623 */
  sim_icache_fetch(1344 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 2625 */
} /* line 2625 */
  sim_icache_fetch(1345 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, reg_r0_11); /* line 2627 */
} /* line 2627 */
  sim_icache_fetch(1346 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 2629 */
} /* line 2629 */
  sim_icache_fetch(1347 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_11); /* line 2631 */
} /* line 2631 */
  sim_icache_fetch(1348 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_3); /* line 2634 */
} /* line 2634 */
  sim_icache_fetch(1350 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L80X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L80X3;
} /* line 2636 */
l_L76X3: ;/* line 2639 */
LABEL(l_L76X3);
  sim_icache_fetch(1351 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_26, reg_r0_26, (unsigned int) 4); /* line 2640 */
} /* line 2640 */
  sim_icache_fetch(1352 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 4); /* line 2642 */
} /* line 2642 */
  sim_icache_fetch(1353 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_24, reg_r0_24, (unsigned int) 4); /* line 2644 */
} /* line 2644 */
  sim_icache_fetch(1354 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 1); /* line 2646 */
} /* line 2646 */
  sim_icache_fetch(1355 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 4); /* line 2648 */
} /* line 2648 */
  sim_icache_fetch(1356 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_19, (unsigned int) 4); /* line 2650 */
} /* line 2650 */
  sim_icache_fetch(1357 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_20, (unsigned int) 1); /* line 2652 */
} /* line 2652 */
  sim_icache_fetch(1358 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_17); /* line 2655 */
} /* line 2655 */
  sim_icache_fetch(1359 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L71X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L71X3;
} /* line 2657 */
l_L77X3: ;/* line 2660 */
LABEL(l_L77X3);
  sim_icache_fetch(1360 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 2661 */
} /* line 2661 */
  sim_icache_fetch(1361 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_13, (unsigned int) 8); /* line 2663 */
} /* line 2663 */
  sim_icache_fetch(1362 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_5, reg_r0_14); /* line 2665 */
} /* line 2665 */
  sim_icache_fetch(1363 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 2667 */
} /* line 2667 */
  sim_icache_fetch(1364 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 16); /* line 2669 */
} /* line 2669 */
  sim_icache_fetch(1365 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_12, reg_r0_14); /* line 2671 */
} /* line 2671 */
  sim_icache_fetch(1366 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_12, (unsigned int) 25); /* line 2673 */
} /* line 2673 */
  sim_icache_fetch(1367 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_15); /* line 2675 */
} /* line 2675 */
  sim_icache_fetch(1368 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_3); /* line 2678 */
} /* line 2678 */
  sim_icache_fetch(1369 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L78X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L78X3;
} /* line 2680 */
l_L72X3: ;/* line 2683 */
LABEL(l_L72X3);
  sim_icache_fetch(1370 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_fused);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2685 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 236: goto l_L61X3;
    case 237: goto l_L63X3;
    case 238: goto l_L67X3;
    case 239: goto l_L69X3;
    case 240: goto l_L70X3;
    case 241: goto l_L66X3;
    case 242: goto l_L65X3;
    case 243: goto l_L64X3;
    case 244: goto l_L68X3;
    case 245: goto l_L62X3;
    case 246: goto l_L71X3;
    case 247: goto l_L73X3;
    case 248: goto l_L74X3;
    case 249: goto l_L75X3;
    case 250: goto l_L78X3;
    case 251: goto l_L80X3;
    case 252: goto l_L79X3;
    case 253: goto l_L76X3;
    case 254: goto l_L77X3;
    case 255: goto l_L72X3;
    case 256:
      reg_l0_0 = t_client_rpc;
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern  deriche_array( unsigned int arg0, unsigned int arg1 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   ENTRY(deriche_array);
  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (277 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1371 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 2700 */
  sim_icache_fetch(1372 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 2702 */
} /* line 2702 */
  sim_icache_fetch(1373 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_2); /* line 2704 */
} /* line 2704 */
  sim_icache_fetch(1374 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_24, (unsigned int) in); /* line 2706 */
} /* line 2706 */
  sim_icache_fetch(1376 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_23, (unsigned int) at); /* line 2708 */
} /* line 2708 */
  sim_icache_fetch(1378 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_4, (unsigned int) -1); /* line 2710 */
} /* line 2710 */
  sim_icache_fetch(1379 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 2712 */
} /* line 2712 */
  sim_icache_fetch(1381 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_25, reg_r0_3); /* line 2714 */
} /* line 2714 */
  sim_icache_fetch(1382 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_4); /* line 2716 */
} /* line 2716 */
l_L81X3: ;/* line 2719 */
LABEL(l_L81X3);
  sim_icache_fetch(1383 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 2720 */
} /* line 2720 */
  sim_icache_fetch(1384 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_10, reg_r0_11); /* line 2722 */
} /* line 2722 */
  sim_icache_fetch(1385 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L82X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2724 */
  sim_icache_fetch(1386 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_7, reg_r0_13, ((unsigned int) ay2 + (unsigned int) -16)); /* line 2726 */
} /* line 2726 */
  sim_icache_fetch(1388 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 2728 */
} /* line 2728 */
  sim_icache_fetch(1389 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 2730 */
} /* line 2730 */
  sim_icache_fetch(1390 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 2732 */
} /* line 2732 */
  sim_icache_fetch(1391 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 2734 */
} /* line 2734 */
  sim_icache_fetch(1392 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, 0); /* line 2736 */
} /* line 2736 */
  sim_icache_fetch(1393 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, 0); /* line 2738 */
} /* line 2738 */
  sim_icache_fetch(1394 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, 0); /* line 2740 */
} /* line 2740 */
  sim_icache_fetch(1395 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_11); /* line 2742 */
} /* line 2742 */
  sim_icache_fetch(1396 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_9); /* line 2744 */
} /* line 2744 */
  sim_icache_fetch(1397 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_10); /* line 2746 */
} /* line 2746 */
  sim_icache_fetch(1398 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_11); /* line 2748 */
} /* line 2748 */
  sim_icache_fetch(1399 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_13); /* line 2750 */
} /* line 2750 */
l_L83X3: ;/* line 2753 */
LABEL(l_L83X3);
  sim_icache_fetch(1400 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2754 */
} /* line 2754 */
  sim_icache_fetch(1401 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_3, (unsigned int) -47); /* line 2756 */
} /* line 2756 */
  sim_icache_fetch(1402 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2758 */
} /* line 2758 */
  sim_icache_fetch(1403 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_2); /* line 2760 */
} /* line 2760 */
  sim_icache_fetch(1404 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 2762 */
} /* line 2762 */
  sim_icache_fetch(1405 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -48); /* line 2764 */
} /* line 2764 */
  sim_icache_fetch(1406 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2766 */
} /* line 2766 */
  sim_icache_fetch(1407 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 2768 */
} /* line 2768 */
  sim_icache_fetch(1408 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_5); /* line 2770 */
} /* line 2770 */
  sim_icache_fetch(1409 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, 0); /* line 2772 */
} /* line 2772 */
  sim_icache_fetch(1410 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 3),0,1)); /* line 2774 */
} /* line 2774 */
  sim_icache_fetch(1411 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L84X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2776 */
  sim_icache_fetch(1412 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 1); /* line 2778 */
} /* line 2778 */
  sim_icache_fetch(1413 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2780 */
} /* line 2780 */
  sim_icache_fetch(1414 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_10, (unsigned int) -47); /* line 2782 */
} /* line 2782 */
  sim_icache_fetch(1415 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2784 */
} /* line 2784 */
  sim_icache_fetch(1416 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_4); /* line 2786 */
} /* line 2786 */
  sim_icache_fetch(1417 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_9, (unsigned int) 215); /* line 2788 */
} /* line 2788 */
  sim_icache_fetch(1418 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 2790 */
} /* line 2790 */
  sim_icache_fetch(1419 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2792 */
} /* line 2792 */
  sim_icache_fetch(1420 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_12); /* line 2794 */
} /* line 2794 */
  sim_icache_fetch(1421 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 2796 */
} /* line 2796 */
  sim_icache_fetch(1422 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_12, mem_trace_ld((reg_r0_8 + (unsigned int) 2),0,1)); /* line 2798 */
} /* line 2798 */
  sim_icache_fetch(1423 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_6, (unsigned int) 2); /* line 2800 */
} /* line 2800 */
  sim_icache_fetch(1424 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_9, (unsigned int) -155); /* line 2802 */
} /* line 2802 */
  sim_icache_fetch(1425 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_12, (unsigned int) -47); /* line 2804 */
} /* line 2804 */
  sim_icache_fetch(1426 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2806 */
} /* line 2806 */
  sim_icache_fetch(1427 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_13); /* line 2808 */
} /* line 2808 */
  sim_icache_fetch(1428 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_11, (unsigned int) 215); /* line 2810 */
} /* line 2810 */
  sim_icache_fetch(1429 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 2812 */
} /* line 2812 */
  sim_icache_fetch(1430 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2814 */
} /* line 2814 */
  sim_icache_fetch(1431 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_13); /* line 2816 */
} /* line 2816 */
  sim_icache_fetch(1432 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 2818 */
} /* line 2818 */
  sim_icache_fetch(1433 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 1),0,1)); /* line 2820 */
} /* line 2820 */
  sim_icache_fetch(1434 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_2, reg_r0_6, (unsigned int) 3); /* line 2822 */
} /* line 2822 */
  sim_icache_fetch(1435 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_11, (unsigned int) -155); /* line 2824 */
} /* line 2824 */
  sim_icache_fetch(1436 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_10, (unsigned int) -47); /* line 2826 */
} /* line 2826 */
  sim_icache_fetch(1437 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2828 */
} /* line 2828 */
  sim_icache_fetch(1438 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_13); /* line 2830 */
} /* line 2830 */
  sim_icache_fetch(1439 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_14, (unsigned int) 215); /* line 2832 */
} /* line 2832 */
  sim_icache_fetch(1440 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_12, (unsigned int) -48); /* line 2834 */
} /* line 2834 */
  sim_icache_fetch(1441 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2836 */
} /* line 2836 */
  sim_icache_fetch(1442 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_13); /* line 2838 */
} /* line 2838 */
  sim_icache_fetch(1443 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_15, reg_r0_12); /* line 2840 */
} /* line 2840 */
  sim_icache_fetch(1444 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_8,0,1)); /* line 2842 */
} /* line 2842 */
  sim_icache_fetch(1445 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_14); /* line 2844 */
} /* line 2844 */
  sim_icache_fetch(1446 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_10); /* line 2846 */
} /* line 2846 */
  sim_icache_fetch(1447 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) -4); /* line 2848 */
} /* line 2848 */
  sim_icache_fetch(1448 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -4); /* line 2850 */
} /* line 2850 */
  sim_icache_fetch(1449 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 12),0,4), reg_r0_9); /* line 2852 */
} /* line 2852 */
  sim_icache_fetch(1450 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L85X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2854 */
  sim_icache_fetch(1451 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 8),0,4), reg_r0_11); /* line 2856 */
} /* line 2856 */
  sim_icache_fetch(1452 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2858 */
  sim_icache_fetch(1453 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 4),0,4), reg_r0_14); /* line 2860 */
} /* line 2860 */
  sim_icache_fetch(1454 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L87X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2862 */
  sim_icache_fetch(1455 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_7,0,4), reg_r0_4); /* line 2864 */
} /* line 2864 */
  sim_icache_fetch(1456 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -16); /* line 2867 */
} /* line 2867 */
  sim_icache_fetch(1457 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L83X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L83X3;
} /* line 2869 */
l_L87X3: ;/* line 2872 */
LABEL(l_L87X3);
  sim_icache_fetch(1458 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_19); /* line 2874 */
} /* line 2874 */
  sim_icache_fetch(1459 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L88X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L88X3;
} /* line 2876 */
l_L89X3: ;/* line 2879 */
LABEL(l_L89X3);
  sim_icache_fetch(1460 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 2880 */
} /* line 2880 */
  sim_icache_fetch(1461 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_4, (unsigned int) 215); /* line 2882 */
} /* line 2882 */
  sim_icache_fetch(1462 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2884 */
} /* line 2884 */
  sim_icache_fetch(1463 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_3, (unsigned int) -48); /* line 2886 */
} /* line 2886 */
  sim_icache_fetch(1464 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2888 */
} /* line 2888 */
  sim_icache_fetch(1465 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_11); /* line 2890 */
} /* line 2890 */
  sim_icache_fetch(1466 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2892 */
} /* line 2892 */
  sim_icache_fetch(1467 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 2894 */
} /* line 2894 */
  sim_icache_fetch(1468 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_11, mem_trace_ld(reg_r0_7,0,4)); /* line 2896 */
} /* line 2896 */
  sim_icache_fetch(1469 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_5); /* line 2898 */
} /* line 2898 */
  sim_icache_fetch(1470 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_12); /* line 2900 */
} /* line 2900 */
  sim_icache_fetch(1471 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_6, reg_r0_11); /* line 2902 */
} /* line 2902 */
  sim_icache_fetch(1472 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2904 */
} /* line 2904 */
  sim_icache_fetch(1473 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2906 */
} /* line 2906 */
  sim_icache_fetch(1474 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 2); /* line 2908 */
} /* line 2908 */
  sim_icache_fetch(1475 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 1); /* line 2910 */
} /* line 2910 */
  sim_icache_fetch(1476 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2912 */
  sim_icache_fetch(1477 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_12, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 2914 */
} /* line 2914 */
  sim_icache_fetch(1478 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_6, (unsigned int) 215); /* line 2916 */
} /* line 2916 */
  sim_icache_fetch(1479 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2918 */
} /* line 2918 */
  sim_icache_fetch(1480 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_12, (unsigned int) -48); /* line 2920 */
} /* line 2920 */
  sim_icache_fetch(1481 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2922 */
} /* line 2922 */
  sim_icache_fetch(1482 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_13); /* line 2924 */
} /* line 2924 */
  sim_icache_fetch(1483 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2926 */
} /* line 2926 */
  sim_icache_fetch(1484 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2928 */
} /* line 2928 */
  sim_icache_fetch(1485 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_13, mem_trace_ld((reg_r0_7 + (unsigned int) 4),0,4)); /* line 2930 */
} /* line 2930 */
  sim_icache_fetch(1486 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 2932 */
} /* line 2932 */
  sim_icache_fetch(1487 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_14); /* line 2934 */
} /* line 2934 */
  sim_icache_fetch(1488 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_3, reg_r0_13); /* line 2936 */
} /* line 2936 */
  sim_icache_fetch(1489 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2938 */
} /* line 2938 */
  sim_icache_fetch(1490 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2940 */
} /* line 2940 */
  sim_icache_fetch(1491 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_8, 0); /* line 2942 */
} /* line 2942 */
  sim_icache_fetch(1492 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 2944 */
} /* line 2944 */
  sim_icache_fetch(1493 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_3, (unsigned int) 215); /* line 2946 */
} /* line 2946 */
  sim_icache_fetch(1494 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_16, reg_r0_6, (unsigned int) -155); /* line 2948 */
} /* line 2948 */
  sim_icache_fetch(1495 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_17, reg_r0_14, (unsigned int) -48); /* line 2950 */
} /* line 2950 */
  sim_icache_fetch(1496 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2952 */
} /* line 2952 */
  sim_icache_fetch(1497 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_17, reg_r0_17, reg_r0_15); /* line 2954 */
} /* line 2954 */
  sim_icache_fetch(1498 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 2956 */
} /* line 2956 */
  sim_icache_fetch(1499 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_12, (unsigned int) 28); /* line 2958 */
} /* line 2958 */
  sim_icache_fetch(1500 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_15, mem_trace_ld((reg_r0_7 + (unsigned int) 8),0,4)); /* line 2960 */
} /* line 2960 */
  sim_icache_fetch(1501 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_16); /* line 2962 */
} /* line 2962 */
  sim_icache_fetch(1502 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_12, reg_r0_17); /* line 2964 */
} /* line 2964 */
  sim_icache_fetch(1503 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_4, reg_r0_15); /* line 2966 */
} /* line 2966 */
  sim_icache_fetch(1504 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2968 */
} /* line 2968 */
  sim_icache_fetch(1505 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2970 */
} /* line 2970 */
  sim_icache_fetch(1506 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_3); /* line 2972 */
} /* line 2972 */
  sim_icache_fetch(1507 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 3); /* line 2974 */
} /* line 2974 */
  sim_icache_fetch(1508 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 12); /* line 2976 */
} /* line 2976 */
  sim_icache_fetch(1509 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 3); /* line 2978 */
} /* line 2978 */
  sim_icache_fetch(1510 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_6); /* line 2980 */
} /* line 2980 */
  sim_icache_fetch(1511 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_14); /* line 2982 */
} /* line 2982 */
  sim_icache_fetch(1512 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_9,0,4), reg_r0_11); /* line 2984 */
} /* line 2984 */
  sim_icache_fetch(1513 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2986 */
  sim_icache_fetch(1514 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4),0,4), reg_r0_3); /* line 2988 */
} /* line 2988 */
  sim_icache_fetch(1515 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 4),0,4), reg_r0_13); /* line 2990 */
} /* line 2990 */
  sim_icache_fetch(1516 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2992 */
  sim_icache_fetch(1517 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 8),0,4), reg_r0_4); /* line 2994 */
} /* line 2994 */
  sim_icache_fetch(1518 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 12); /* line 2996 */
} /* line 2996 */
  sim_icache_fetch(1519 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 8),0,4), reg_r0_15); /* line 2998 */
} /* line 2998 */
  sim_icache_fetch(1520 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 12); /* line 3001 */
} /* line 3001 */
  sim_icache_fetch(1521 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L89X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L89X3;
} /* line 3003 */
l_L90X3: ;/* line 3006 */
LABEL(l_L90X3);
  sim_icache_fetch(1522 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_24, reg_r0_24, (unsigned int) 1050); /* line 3007 */
} /* line 3007 */
  sim_icache_fetch(1524 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 4200); /* line 3009 */
} /* line 3009 */
  sim_icache_fetch(1526 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_19, (unsigned int) 1050); /* line 3011 */
} /* line 3011 */
  sim_icache_fetch(1528 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_20, (unsigned int) 1); /* line 3013 */
} /* line 3013 */
  sim_icache_fetch(1529 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_21); /* line 3015 */
} /* line 3015 */
  sim_icache_fetch(1530 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, reg_r0_18); /* line 3018 */
} /* line 3018 */
  sim_icache_fetch(1531 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L81X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L81X3;
} /* line 3020 */
l_L86X3: ;/* line 3023 */
LABEL(l_L86X3);
  sim_icache_fetch(1532 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_19); /* line 3025 */
} /* line 3025 */
  sim_icache_fetch(1533 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L88X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L88X3;
} /* line 3027 */
l_L85X3: ;/* line 3030 */
LABEL(l_L85X3);
  sim_icache_fetch(1534 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_19); /* line 3032 */
} /* line 3032 */
  sim_icache_fetch(1535 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L88X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L88X3;
} /* line 3034 */
l_L84X3: ;/* line 3037 */
LABEL(l_L84X3);
  sim_icache_fetch(1536 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_19); /* line 3038 */
} /* line 3038 */
l_L88X3: ;/* line 3040 */
LABEL(l_L88X3);
  sim_icache_fetch(1537 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_3); /* line 3041 */
} /* line 3041 */
  sim_icache_fetch(1538 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_23); /* line 3043 */
} /* line 3043 */
  sim_icache_fetch(1539 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, (unsigned int) ay2); /* line 3045 */
} /* line 3045 */
  sim_icache_fetch(1541 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) ay1); /* line 3047 */
} /* line 3047 */
  sim_icache_fetch(1543 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_24); /* line 3049 */
} /* line 3049 */
  sim_icache_fetch(1544 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_20); /* line 3051 */
} /* line 3051 */
  sim_icache_fetch(1545 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_21); /* line 3053 */
} /* line 3053 */
  sim_icache_fetch(1546 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_22); /* line 3055 */
} /* line 3055 */
  sim_icache_fetch(1547 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_16); /* line 3057 */
} /* line 3057 */
  sim_icache_fetch(1548 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, reg_r0_19); /* line 3059 */
} /* line 3059 */
  sim_icache_fetch(1549 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_17); /* line 3062 */
} /* line 3062 */
  sim_icache_fetch(1550 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L89X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L89X3;
} /* line 3064 */
l_L82X3: ;/* line 3067 */
LABEL(l_L82X3);
  sim_icache_fetch(1551 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_13, 0, reg_r0_13); /* line 3068 */
} /* line 3068 */
  sim_icache_fetch(1552 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_13); /* line 3070 */
} /* line 3070 */
  sim_icache_fetch(1553 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_23, (unsigned int) at); /* line 3072 */
} /* line 3072 */
  sim_icache_fetch(1555 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, (unsigned int) out); /* line 3074 */
} /* line 3074 */
  sim_icache_fetch(1557 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, ((unsigned int) at + (unsigned int) -12600)); /* line 3076 */
} /* line 3076 */
  sim_icache_fetch(1559 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_25, (unsigned int) -1); /* line 3078 */
} /* line 3078 */
  sim_icache_fetch(1560 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_25); /* line 3080 */
} /* line 3080 */
l_L91X3: ;/* line 3083 */
LABEL(l_L91X3);
  sim_icache_fetch(1561 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 3084 */
} /* line 3084 */
  sim_icache_fetch(1562 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULLU(reg_r0_13, reg_r0_10, (unsigned int) 4200); /* line 3086 */
} /* line 3086 */
  sim_icache_fetch(1564 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L92X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3088 */
  sim_icache_fetch(1565 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_11, reg_r0_13); /* line 3090 */
} /* line 3090 */
  sim_icache_fetch(1566 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_7, reg_r0_12, ((unsigned int) ay2 + (unsigned int) -16)); /* line 3092 */
} /* line 3092 */
  sim_icache_fetch(1568 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 3094 */
} /* line 3094 */
  sim_icache_fetch(1569 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 3096 */
} /* line 3096 */
  sim_icache_fetch(1570 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 3098 */
} /* line 3098 */
  sim_icache_fetch(1571 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 3100 */
} /* line 3100 */
  sim_icache_fetch(1572 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, 0); /* line 3102 */
} /* line 3102 */
  sim_icache_fetch(1573 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, 0); /* line 3104 */
} /* line 3104 */
  sim_icache_fetch(1574 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, 0); /* line 3106 */
} /* line 3106 */
  sim_icache_fetch(1575 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_10); /* line 3108 */
} /* line 3108 */
  sim_icache_fetch(1576 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_9); /* line 3110 */
} /* line 3110 */
  sim_icache_fetch(1577 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_10); /* line 3112 */
} /* line 3112 */
  sim_icache_fetch(1578 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_11); /* line 3114 */
} /* line 3114 */
  sim_icache_fetch(1579 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_12); /* line 3116 */
} /* line 3116 */
l_L93X3: ;/* line 3119 */
LABEL(l_L93X3);
  sim_icache_fetch(1580 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 3120 */
} /* line 3120 */
  sim_icache_fetch(1581 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_3, (unsigned int) -47); /* line 3122 */
} /* line 3122 */
  sim_icache_fetch(1582 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 3124 */
} /* line 3124 */
  sim_icache_fetch(1583 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_9); /* line 3126 */
} /* line 3126 */
  sim_icache_fetch(1584 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 29); /* line 3128 */
} /* line 3128 */
  sim_icache_fetch(1585 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, 0); /* line 3130 */
} /* line 3130 */
  sim_icache_fetch(1586 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_5); /* line 3132 */
} /* line 3132 */
  sim_icache_fetch(1587 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 3134 */
} /* line 3134 */
  sim_icache_fetch(1588 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 3136 */
} /* line 3136 */
  sim_icache_fetch(1589 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3138 */
  sim_icache_fetch(1590 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_9, mem_trace_ld((reg_r0_8 + (unsigned int) 12600),0,4)); /* line 3140 */
} /* line 3140 */
  sim_icache_fetch(1592 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 1); /* line 3142 */
} /* line 3142 */
  sim_icache_fetch(1593 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 3144 */
} /* line 3144 */
  sim_icache_fetch(1594 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_9, (unsigned int) -47); /* line 3146 */
} /* line 3146 */
  sim_icache_fetch(1595 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 3148 */
} /* line 3148 */
  sim_icache_fetch(1596 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_10); /* line 3150 */
} /* line 3150 */
  sim_icache_fetch(1597 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 3152 */
} /* line 3152 */
  sim_icache_fetch(1598 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 8400),0,4)); /* line 3154 */
} /* line 3154 */
  sim_icache_fetch(1600 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 3156 */
} /* line 3156 */
  sim_icache_fetch(1601 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_11); /* line 3158 */
} /* line 3158 */
  sim_icache_fetch(1602 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 3160 */
} /* line 3160 */
  sim_icache_fetch(1603 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_6, (unsigned int) 2); /* line 3162 */
} /* line 3162 */
  sim_icache_fetch(1604 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 3164 */
} /* line 3164 */
  sim_icache_fetch(1605 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 3166 */
} /* line 3166 */
  sim_icache_fetch(1606 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_4, (unsigned int) 215); /* line 3168 */
} /* line 3168 */
  sim_icache_fetch(1607 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 3170 */
} /* line 3170 */
  sim_icache_fetch(1608 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 29); /* line 3172 */
} /* line 3172 */
  sim_icache_fetch(1609 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_8 + (unsigned int) 4200),0,4)); /* line 3174 */
} /* line 3174 */
  sim_icache_fetch(1611 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, reg_r0_9); /* line 3176 */
} /* line 3176 */
  sim_icache_fetch(1612 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 3178 */
} /* line 3178 */
  sim_icache_fetch(1613 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 3180 */
} /* line 3180 */
  sim_icache_fetch(1614 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_2, reg_r0_6, (unsigned int) 3); /* line 3182 */
} /* line 3182 */
  sim_icache_fetch(1615 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_4, (unsigned int) -155); /* line 3184 */
} /* line 3184 */
  sim_icache_fetch(1616 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 3186 */
} /* line 3186 */
  sim_icache_fetch(1617 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 3188 */
} /* line 3188 */
  sim_icache_fetch(1618 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_13); /* line 3190 */
} /* line 3190 */
  sim_icache_fetch(1619 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 3192 */
} /* line 3192 */
  sim_icache_fetch(1620 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_8,0,4)); /* line 3194 */
} /* line 3194 */
  sim_icache_fetch(1621 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 3196 */
} /* line 3196 */
  sim_icache_fetch(1622 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_14); /* line 3198 */
} /* line 3198 */
  sim_icache_fetch(1623 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 3200 */
} /* line 3200 */
  sim_icache_fetch(1624 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_12); /* line 3202 */
} /* line 3202 */
  sim_icache_fetch(1625 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) -4); /* line 3204 */
} /* line 3204 */
  sim_icache_fetch(1626 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 12),0,4), reg_r0_2); /* line 3206 */
} /* line 3206 */
  sim_icache_fetch(1627 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3208 */
  sim_icache_fetch(1628 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_11); /* line 3210 */
} /* line 3210 */
  sim_icache_fetch(1629 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16800); /* line 3212 */
} /* line 3212 */
  sim_icache_fetch(1631 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 8),0,4), reg_r0_4); /* line 3214 */
} /* line 3214 */
  sim_icache_fetch(1632 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3216 */
  sim_icache_fetch(1633 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_9); /* line 3218 */
} /* line 3218 */
  sim_icache_fetch(1634 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 4),0,4), reg_r0_11); /* line 3220 */
} /* line 3220 */
  sim_icache_fetch(1635 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3222 */
  sim_icache_fetch(1636 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_7,0,4), reg_r0_9); /* line 3224 */
} /* line 3224 */
  sim_icache_fetch(1637 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -16); /* line 3227 */
} /* line 3227 */
  sim_icache_fetch(1638 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L93X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L93X3;
} /* line 3229 */
l_L94X3: ;/* line 3232 */
LABEL(l_L94X3);
  sim_icache_fetch(1639 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 3233 */
} /* line 3233 */
  sim_icache_fetch(1640 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_3); /* line 3235 */
} /* line 3235 */
  sim_icache_fetch(1641 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_22); /* line 3237 */
} /* line 3237 */
  sim_icache_fetch(1642 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, (unsigned int) ay2); /* line 3239 */
} /* line 3239 */
  sim_icache_fetch(1644 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) ay1); /* line 3241 */
} /* line 3241 */
  sim_icache_fetch(1646 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_23); /* line 3243 */
} /* line 3243 */
  sim_icache_fetch(1647 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_20); /* line 3245 */
} /* line 3245 */
  sim_icache_fetch(1648 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_19); /* line 3247 */
} /* line 3247 */
  sim_icache_fetch(1649 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_21); /* line 3249 */
} /* line 3249 */
  sim_icache_fetch(1650 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_18); /* line 3251 */
} /* line 3251 */
  sim_icache_fetch(1651 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_15); /* line 3253 */
} /* line 3253 */
l_L95X3: ;/* line 3256 */
LABEL(l_L95X3);
  sim_icache_fetch(1652 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 3257 */
} /* line 3257 */
  sim_icache_fetch(1653 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 3259 */
} /* line 3259 */
  sim_icache_fetch(1654 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_5, (unsigned int) 215); /* line 3261 */
} /* line 3261 */
  sim_icache_fetch(1655 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_3, (unsigned int) -48); /* line 3263 */
} /* line 3263 */
  sim_icache_fetch(1656 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 3265 */
} /* line 3265 */
  sim_icache_fetch(1657 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_12); /* line 3267 */
} /* line 3267 */
  sim_icache_fetch(1658 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_6); /* line 3269 */
} /* line 3269 */
  sim_icache_fetch(1659 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_11); /* line 3271 */
} /* line 3271 */
  sim_icache_fetch(1660 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 3273 */
} /* line 3273 */
  sim_icache_fetch(1661 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_11, mem_trace_ld(reg_r0_7,0,4)); /* line 3275 */
} /* line 3275 */
  sim_icache_fetch(1662 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 3277 */
} /* line 3277 */
  sim_icache_fetch(1663 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_8, 0); /* line 3279 */
} /* line 3279 */
  sim_icache_fetch(1664 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_4, reg_r0_11); /* line 3281 */
} /* line 3281 */
  sim_icache_fetch(1665 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 3283 */
} /* line 3283 */
  sim_icache_fetch(1666 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 3285 */
} /* line 3285 */
  sim_icache_fetch(1667 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3287 */
  sim_icache_fetch(1668 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_12, reg_r0_11); /* line 3289 */
} /* line 3289 */
  sim_icache_fetch(1669 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_12, (unsigned int) 25); /* line 3291 */
} /* line 3291 */
  sim_icache_fetch(1670 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 3293 */
} /* line 3293 */
  sim_icache_fetch(1672 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_5, (unsigned int) -155); /* line 3295 */
} /* line 3295 */
  sim_icache_fetch(1673 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_4, (unsigned int) 215); /* line 3297 */
} /* line 3297 */
  sim_icache_fetch(1674 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_6, (unsigned int) -48); /* line 3299 */
} /* line 3299 */
  sim_icache_fetch(1675 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_3, (unsigned int) 28); /* line 3301 */
} /* line 3301 */
  sim_icache_fetch(1676 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_14); /* line 3303 */
} /* line 3303 */
  sim_icache_fetch(1677 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 3305 */
} /* line 3305 */
  sim_icache_fetch(1678 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_13); /* line 3307 */
} /* line 3307 */
  sim_icache_fetch(1679 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_13, mem_trace_ld((reg_r0_7 + (unsigned int) 4),0,4)); /* line 3309 */
} /* line 3309 */
  sim_icache_fetch(1680 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_4); /* line 3311 */
} /* line 3311 */
  sim_icache_fetch(1681 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_11); /* line 3313 */
} /* line 3313 */
  sim_icache_fetch(1682 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_4); /* line 3315 */
} /* line 3315 */
  sim_icache_fetch(1683 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3317 */
  sim_icache_fetch(1684 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_12, (unsigned int) 8); /* line 3319 */
} /* line 3319 */
  sim_icache_fetch(1685 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_5, reg_r0_13); /* line 3321 */
} /* line 3321 */
  sim_icache_fetch(1686 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 3323 */
} /* line 3323 */
  sim_icache_fetch(1687 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 3325 */
} /* line 3325 */
  sim_icache_fetch(1688 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_3, reg_r0_13); /* line 3327 */
} /* line 3327 */
  sim_icache_fetch(1689 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 3329 */
} /* line 3329 */
  sim_icache_fetch(1690 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_14); /* line 3331 */
} /* line 3331 */
  sim_icache_fetch(1691 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), 0); /* line 3333 */
} /* line 3333 */
l_L98X3: ;/* line 3335 */
LABEL(l_L98X3);
  sim_icache_fetch(1692 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3336 */
  sim_icache_fetch(1693 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4),0,4), reg_r0_5); /* line 3338 */
} /* line 3338 */
  sim_icache_fetch(1694 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_13); /* line 3340 */
} /* line 3340 */
  sim_icache_fetch(1696 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3342 */
  sim_icache_fetch(1697 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 8400); /* line 3344 */
} /* line 3344 */
  sim_icache_fetch(1699 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 3346 */
} /* line 3346 */
  sim_icache_fetch(1700 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 3348 */
} /* line 3348 */
  sim_icache_fetch(1701 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 3350 */
} /* line 3350 */
  sim_icache_fetch(1702 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), 0); /* line 3352 */
} /* line 3352 */
l_L100X3: ;/* line 3354 */
LABEL(l_L100X3);
  sim_icache_fetch(1704 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 2100); /* line 3356 */
} /* line 3356 */
  sim_icache_fetch(1706 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L95X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L95X3;
} /* line 3358 */
l_L99X3: ;/* line 3361 */
LABEL(l_L99X3);
  sim_icache_fetch(1707 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 3362 */
} /* line 3362 */
  sim_icache_fetch(1708 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 3364 */
} /* line 3364 */
  sim_icache_fetch(1709 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 3366 */
} /* line 3366 */
  sim_icache_fetch(1710 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 3368 */
} /* line 3368 */
  sim_icache_fetch(1711 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 8400); /* line 3370 */
} /* line 3370 */
  sim_icache_fetch(1713 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_3); /* line 3373 */
} /* line 3373 */
  sim_icache_fetch(1715 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L100X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L100X3;
} /* line 3375 */
l_L96X3: ;/* line 3378 */
LABEL(l_L96X3);
  sim_icache_fetch(1716 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 4); /* line 3379 */
} /* line 3379 */
  sim_icache_fetch(1717 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_22, reg_r0_22, (unsigned int) 1); /* line 3381 */
} /* line 3381 */
  sim_icache_fetch(1718 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4); /* line 3383 */
} /* line 3383 */
  sim_icache_fetch(1719 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_18, (unsigned int) 1); /* line 3385 */
} /* line 3385 */
  sim_icache_fetch(1720 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_16); /* line 3387 */
} /* line 3387 */
  sim_icache_fetch(1721 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_19); /* line 3390 */
} /* line 3390 */
  sim_icache_fetch(1722 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L91X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L91X3;
} /* line 3392 */
l_L97X3: ;/* line 3395 */
LABEL(l_L97X3);
  sim_icache_fetch(1723 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 3396 */
} /* line 3396 */
  sim_icache_fetch(1724 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_12, (unsigned int) 8); /* line 3398 */
} /* line 3398 */
  sim_icache_fetch(1725 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_5, reg_r0_13); /* line 3400 */
} /* line 3400 */
  sim_icache_fetch(1726 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 3402 */
} /* line 3402 */
  sim_icache_fetch(1727 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 3404 */
} /* line 3404 */
  sim_icache_fetch(1728 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_11, reg_r0_13); /* line 3406 */
} /* line 3406 */
  sim_icache_fetch(1729 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_11, (unsigned int) 25); /* line 3408 */
} /* line 3408 */
  sim_icache_fetch(1730 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_14); /* line 3410 */
} /* line 3410 */
  sim_icache_fetch(1731 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_3); /* line 3413 */
} /* line 3413 */
  sim_icache_fetch(1732 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L98X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L98X3;
} /* line 3415 */
l_L92X3: ;/* line 3418 */
LABEL(l_L92X3);
  sim_icache_fetch(1733 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_array);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3420 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 257: goto l_L81X3;
    case 258: goto l_L83X3;
    case 259: goto l_L87X3;
    case 260: goto l_L89X3;
    case 261: goto l_L90X3;
    case 262: goto l_L86X3;
    case 263: goto l_L85X3;
    case 264: goto l_L84X3;
    case 265: goto l_L88X3;
    case 266: goto l_L82X3;
    case 267: goto l_L91X3;
    case 268: goto l_L93X3;
    case 269: goto l_L94X3;
    case 270: goto l_L95X3;
    case 271: goto l_L98X3;
    case 272: goto l_L100X3;
    case 273: goto l_L99X3;
    case 274: goto l_L96X3;
    case 275: goto l_L97X3;
    case 276: goto l_L92X3;
    case 277:
      reg_l0_0 = t_client_rpc;
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern  deriche_short( unsigned int arg0, unsigned int arg1 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   ENTRY(deriche_short);
  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (297 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1734 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 3435 */
  sim_icache_fetch(1735 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 3437 */
} /* line 3437 */
  sim_icache_fetch(1736 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_2); /* line 3439 */
} /* line 3439 */
  sim_icache_fetch(1737 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_24, (unsigned int) in); /* line 3441 */
} /* line 3441 */
  sim_icache_fetch(1739 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_23, (unsigned int) s_at); /* line 3443 */
} /* line 3443 */
  sim_icache_fetch(1741 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_4, (unsigned int) -1); /* line 3445 */
} /* line 3445 */
  sim_icache_fetch(1742 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -2)); /* line 3447 */
} /* line 3447 */
  sim_icache_fetch(1744 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_25, reg_r0_3); /* line 3449 */
} /* line 3449 */
  sim_icache_fetch(1745 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_4); /* line 3451 */
} /* line 3451 */
l_L101X3: ;/* line 3454 */
LABEL(l_L101X3);
  sim_icache_fetch(1746 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 3455 */
} /* line 3455 */
  sim_icache_fetch(1747 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_10, reg_r0_11); /* line 3457 */
} /* line 3457 */
  sim_icache_fetch(1748 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3459 */
  sim_icache_fetch(1749 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH1ADD(reg_r0_7, reg_r0_12, ((unsigned int) s_ay2 + (unsigned int) -6)); /* line 3461 */
} /* line 3461 */
  sim_icache_fetch(1751 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 3463 */
} /* line 3463 */
  sim_icache_fetch(1752 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 3465 */
} /* line 3465 */
  sim_icache_fetch(1753 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 3467 */
} /* line 3467 */
  sim_icache_fetch(1754 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 3469 */
} /* line 3469 */
  sim_icache_fetch(1755 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, 0); /* line 3471 */
} /* line 3471 */
  sim_icache_fetch(1756 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, 0); /* line 3473 */
} /* line 3473 */
  sim_icache_fetch(1757 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, 0); /* line 3475 */
} /* line 3475 */
  sim_icache_fetch(1758 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_11); /* line 3477 */
} /* line 3477 */
  sim_icache_fetch(1759 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_9); /* line 3479 */
} /* line 3479 */
  sim_icache_fetch(1760 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_10); /* line 3481 */
} /* line 3481 */
  sim_icache_fetch(1761 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_11); /* line 3483 */
} /* line 3483 */
  sim_icache_fetch(1762 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_12); /* line 3485 */
} /* line 3485 */
l_L103X3: ;/* line 3488 */
LABEL(l_L103X3);
  sim_icache_fetch(1763 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -77); /* line 3489 */
} /* line 3489 */
  sim_icache_fetch(1764 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_3, (unsigned int) -23); /* line 3491 */
} /* line 3491 */
  sim_icache_fetch(1765 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3493 */
} /* line 3493 */
  sim_icache_fetch(1766 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_2, reg_r0_2); /* line 3495 */
} /* line 3495 */
  sim_icache_fetch(1767 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_9, reg_r0_9); /* line 3497 */
} /* line 3497 */
  sim_icache_fetch(1768 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_2); /* line 3499 */
} /* line 3499 */
  sim_icache_fetch(1769 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 107); /* line 3501 */
} /* line 3501 */
  sim_icache_fetch(1770 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -24); /* line 3503 */
} /* line 3503 */
  sim_icache_fetch(1771 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 7); /* line 3505 */
} /* line 3505 */
  sim_icache_fetch(1772 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_10, reg_r0_10); /* line 3507 */
} /* line 3507 */
  sim_icache_fetch(1773 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_5, reg_r0_5); /* line 3509 */
} /* line 3509 */
  sim_icache_fetch(1774 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 3511 */
} /* line 3511 */
  sim_icache_fetch(1775 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_5); /* line 3513 */
} /* line 3513 */
  sim_icache_fetch(1776 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_10, reg_r0_9); /* line 3515 */
} /* line 3515 */
  sim_icache_fetch(1777 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, 0); /* line 3517 */
} /* line 3517 */
  sim_icache_fetch(1778 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_11, mem_trace_ld((reg_r0_8 + (unsigned int) 2),0,1)); /* line 3519 */
} /* line 3519 */
  sim_icache_fetch(1779 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3521 */
  sim_icache_fetch(1780 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 1); /* line 3523 */
} /* line 3523 */
  sim_icache_fetch(1781 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -77); /* line 3525 */
} /* line 3525 */
  sim_icache_fetch(1782 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_11, (unsigned int) -23); /* line 3527 */
} /* line 3527 */
  sim_icache_fetch(1783 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 3529 */
} /* line 3529 */
  sim_icache_fetch(1784 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_4, reg_r0_4); /* line 3531 */
} /* line 3531 */
  sim_icache_fetch(1785 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_12, reg_r0_12); /* line 3533 */
} /* line 3533 */
  sim_icache_fetch(1786 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_4); /* line 3535 */
} /* line 3535 */
  sim_icache_fetch(1787 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_10, (unsigned int) 107); /* line 3537 */
} /* line 3537 */
  sim_icache_fetch(1788 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -24); /* line 3539 */
} /* line 3539 */
  sim_icache_fetch(1789 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 7); /* line 3541 */
} /* line 3541 */
  sim_icache_fetch(1790 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_13, reg_r0_13); /* line 3543 */
} /* line 3543 */
  sim_icache_fetch(1791 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_3, reg_r0_3); /* line 3545 */
} /* line 3545 */
  sim_icache_fetch(1792 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_13); /* line 3547 */
} /* line 3547 */
  sim_icache_fetch(1793 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 3549 */
} /* line 3549 */
  sim_icache_fetch(1794 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_13, reg_r0_12); /* line 3551 */
} /* line 3551 */
  sim_icache_fetch(1795 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_8 + (unsigned int) 1),0,1)); /* line 3553 */
} /* line 3553 */
  sim_icache_fetch(1796 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_6, (unsigned int) 2); /* line 3555 */
} /* line 3555 */
  sim_icache_fetch(1797 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -77); /* line 3557 */
} /* line 3557 */
  sim_icache_fetch(1798 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_14, (unsigned int) -23); /* line 3559 */
} /* line 3559 */
  sim_icache_fetch(1799 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 7); /* line 3561 */
} /* line 3561 */
  sim_icache_fetch(1800 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_10, reg_r0_10); /* line 3563 */
} /* line 3563 */
  sim_icache_fetch(1801 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_15, reg_r0_15); /* line 3565 */
} /* line 3565 */
  sim_icache_fetch(1802 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_10); /* line 3567 */
} /* line 3567 */
  sim_icache_fetch(1803 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_13, (unsigned int) 107); /* line 3569 */
} /* line 3569 */
  sim_icache_fetch(1804 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_11, (unsigned int) -24); /* line 3571 */
} /* line 3571 */
  sim_icache_fetch(1805 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 7); /* line 3573 */
} /* line 3573 */
  sim_icache_fetch(1806 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_10, reg_r0_10); /* line 3575 */
} /* line 3575 */
  sim_icache_fetch(1807 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_11, reg_r0_11); /* line 3577 */
} /* line 3577 */
  sim_icache_fetch(1808 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 3579 */
} /* line 3579 */
  sim_icache_fetch(1809 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_11); /* line 3581 */
} /* line 3581 */
  sim_icache_fetch(1810 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_4, reg_r0_15); /* line 3583 */
} /* line 3583 */
  sim_icache_fetch(1811 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_8,0,1)); /* line 3585 */
} /* line 3585 */
  sim_icache_fetch(1812 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_13); /* line 3587 */
} /* line 3587 */
  sim_icache_fetch(1813 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_14); /* line 3589 */
} /* line 3589 */
  sim_icache_fetch(1814 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) -3); /* line 3591 */
} /* line 3591 */
  sim_icache_fetch(1815 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -3); /* line 3593 */
} /* line 3593 */
  sim_icache_fetch(1816 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_7 + (unsigned int) 4),0,2), reg_r0_9); /* line 3595 */
} /* line 3595 */
  sim_icache_fetch(1817 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3597 */
  sim_icache_fetch(1818 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_7 + (unsigned int) 2),0,2), reg_r0_12); /* line 3599 */
} /* line 3599 */
  sim_icache_fetch(1819 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3601 */
  sim_icache_fetch(1820 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st(reg_r0_7,0,2), reg_r0_15); /* line 3603 */
} /* line 3603 */
  sim_icache_fetch(1821 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -6); /* line 3606 */
} /* line 3606 */
  sim_icache_fetch(1822 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L103X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L103X3;
} /* line 3608 */
l_L106X3: ;/* line 3611 */
LABEL(l_L106X3);
  sim_icache_fetch(1823 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_19); /* line 3613 */
} /* line 3613 */
  sim_icache_fetch(1824 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L107X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L107X3;
} /* line 3615 */
l_L108X3: ;/* line 3618 */
LABEL(l_L108X3);
  sim_icache_fetch(1825 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 3619 */
} /* line 3619 */
  sim_icache_fetch(1826 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_4, (unsigned int) 107); /* line 3621 */
} /* line 3621 */
  sim_icache_fetch(1827 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -77); /* line 3623 */
} /* line 3623 */
  sim_icache_fetch(1828 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_3, (unsigned int) -24); /* line 3625 */
} /* line 3625 */
  sim_icache_fetch(1829 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 7); /* line 3627 */
} /* line 3627 */
  sim_icache_fetch(1830 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_12, reg_r0_12); /* line 3629 */
} /* line 3629 */
  sim_icache_fetch(1831 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_11, reg_r0_11); /* line 3631 */
} /* line 3631 */
  sim_icache_fetch(1832 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_11); /* line 3633 */
} /* line 3633 */
  sim_icache_fetch(1833 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 3635 */
} /* line 3635 */
  sim_icache_fetch(1834 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_5, reg_r0_5); /* line 3637 */
} /* line 3637 */
  sim_icache_fetch(1835 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 14); /* line 3639 */
} /* line 3639 */
  sim_icache_fetch(1836 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_11, mem_trace_ld(reg_r0_7,0,2)); /* line 3641 */
} /* line 3641 */
  sim_icache_fetch(1837 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_6, reg_r0_6); /* line 3643 */
} /* line 3643 */
  sim_icache_fetch(1838 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_5); /* line 3645 */
} /* line 3645 */
  sim_icache_fetch(1839 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_12); /* line 3647 */
} /* line 3647 */
  sim_icache_fetch(1840 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_12, reg_r0_6); /* line 3649 */
} /* line 3649 */
  sim_icache_fetch(1841 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_12, reg_r0_11); /* line 3651 */
} /* line 3651 */
  sim_icache_fetch(1842 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_11, reg_r0_11, (unsigned int) 7); /* line 3653 */
} /* line 3653 */
  sim_icache_fetch(1843 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 7); /* line 3655 */
} /* line 3655 */
  sim_icache_fetch(1844 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 3657 */
} /* line 3657 */
  sim_icache_fetch(1845 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_8, 0); /* line 3659 */
} /* line 3659 */
  sim_icache_fetch(1846 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3661 */
  sim_icache_fetch(1847 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 3663 */
} /* line 3663 */
  sim_icache_fetch(1848 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_12, (unsigned int) 107); /* line 3665 */
} /* line 3665 */
  sim_icache_fetch(1849 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -77); /* line 3667 */
} /* line 3667 */
  sim_icache_fetch(1850 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_13, (unsigned int) -24); /* line 3669 */
} /* line 3669 */
  sim_icache_fetch(1851 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 3671 */
} /* line 3671 */
  sim_icache_fetch(1852 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_15, reg_r0_15); /* line 3673 */
} /* line 3673 */
  sim_icache_fetch(1853 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_14, reg_r0_14); /* line 3675 */
} /* line 3675 */
  sim_icache_fetch(1854 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_14); /* line 3677 */
} /* line 3677 */
  sim_icache_fetch(1855 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 3679 */
} /* line 3679 */
  sim_icache_fetch(1856 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_4, reg_r0_4); /* line 3681 */
} /* line 3681 */
  sim_icache_fetch(1857 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 14); /* line 3683 */
} /* line 3683 */
  sim_icache_fetch(1858 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_14, mem_trace_ld((reg_r0_7 + (unsigned int) 2),0,2)); /* line 3685 */
} /* line 3685 */
  sim_icache_fetch(1859 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_3, reg_r0_3); /* line 3687 */
} /* line 3687 */
  sim_icache_fetch(1860 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 3689 */
} /* line 3689 */
  sim_icache_fetch(1861 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_15); /* line 3691 */
} /* line 3691 */
  sim_icache_fetch(1862 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_4, reg_r0_3); /* line 3693 */
} /* line 3693 */
  sim_icache_fetch(1863 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_4, reg_r0_14); /* line 3695 */
} /* line 3695 */
  sim_icache_fetch(1864 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 3697 */
} /* line 3697 */
  sim_icache_fetch(1865 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 3699 */
} /* line 3699 */
  sim_icache_fetch(1866 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_12); /* line 3701 */
} /* line 3701 */
  sim_icache_fetch(1867 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 2); /* line 3703 */
} /* line 3703 */
  sim_icache_fetch(1868 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 3705 */
} /* line 3705 */
  sim_icache_fetch(1869 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 3707 */
} /* line 3707 */
  sim_icache_fetch(1870 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st(reg_r0_10,0,2), reg_r0_6); /* line 3709 */
} /* line 3709 */
  sim_icache_fetch(1871 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_13); /* line 3711 */
} /* line 3711 */
  sim_icache_fetch(1872 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st(reg_r0_9,0,2), reg_r0_11); /* line 3713 */
} /* line 3713 */
  sim_icache_fetch(1873 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3715 */
  sim_icache_fetch(1874 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_10 + (unsigned int) 2),0,2), reg_r0_3); /* line 3717 */
} /* line 3717 */
  sim_icache_fetch(1875 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 3719 */
} /* line 3719 */
  sim_icache_fetch(1876 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_9 + (unsigned int) 2),0,2), reg_r0_14); /* line 3721 */
} /* line 3721 */
  sim_icache_fetch(1877 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 4); /* line 3724 */
} /* line 3724 */
  sim_icache_fetch(1878 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L108X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L108X3;
} /* line 3726 */
l_L109X3: ;/* line 3729 */
LABEL(l_L109X3);
  sim_icache_fetch(1879 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_24, reg_r0_24, (unsigned int) 1050); /* line 3730 */
} /* line 3730 */
  sim_icache_fetch(1881 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 2100); /* line 3732 */
} /* line 3732 */
  sim_icache_fetch(1883 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_17, (unsigned int) 1050); /* line 3734 */
} /* line 3734 */
  sim_icache_fetch(1885 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_16, (unsigned int) 1); /* line 3736 */
} /* line 3736 */
  sim_icache_fetch(1886 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_19); /* line 3738 */
} /* line 3738 */
  sim_icache_fetch(1887 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, reg_r0_18); /* line 3741 */
} /* line 3741 */
  sim_icache_fetch(1888 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L101X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L101X3;
} /* line 3743 */
l_L105X3: ;/* line 3746 */
LABEL(l_L105X3);
  sim_icache_fetch(1889 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_19); /* line 3748 */
} /* line 3748 */
  sim_icache_fetch(1890 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L107X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L107X3;
} /* line 3750 */
l_L104X3: ;/* line 3753 */
LABEL(l_L104X3);
  sim_icache_fetch(1891 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_19); /* line 3754 */
} /* line 3754 */
l_L107X3: ;/* line 3756 */
LABEL(l_L107X3);
  sim_icache_fetch(1892 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_3); /* line 3757 */
} /* line 3757 */
  sim_icache_fetch(1893 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_23); /* line 3759 */
} /* line 3759 */
  sim_icache_fetch(1894 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, (unsigned int) s_ay2); /* line 3761 */
} /* line 3761 */
  sim_icache_fetch(1896 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) s_ay1); /* line 3763 */
} /* line 3763 */
  sim_icache_fetch(1898 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_24); /* line 3765 */
} /* line 3765 */
  sim_icache_fetch(1899 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_20); /* line 3767 */
} /* line 3767 */
  sim_icache_fetch(1900 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_21); /* line 3769 */
} /* line 3769 */
  sim_icache_fetch(1901 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_22); /* line 3772 */
} /* line 3772 */
  sim_icache_fetch(1902 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L108X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L108X3;
} /* line 3774 */
l_L102X3: ;/* line 3777 */
LABEL(l_L102X3);
  sim_icache_fetch(1903 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_12, 0, reg_r0_12); /* line 3778 */
} /* line 3778 */
  sim_icache_fetch(1904 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_12); /* line 3780 */
} /* line 3780 */
  sim_icache_fetch(1905 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_23, (unsigned int) s_at); /* line 3782 */
} /* line 3782 */
  sim_icache_fetch(1907 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, (unsigned int) out); /* line 3784 */
} /* line 3784 */
  sim_icache_fetch(1909 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, ((unsigned int) s_at + (unsigned int) -4200)); /* line 3786 */
} /* line 3786 */
  sim_icache_fetch(1911 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_25, (unsigned int) -1); /* line 3788 */
} /* line 3788 */
  sim_icache_fetch(1912 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_25); /* line 3790 */
} /* line 3790 */
l_L110X3: ;/* line 3793 */
LABEL(l_L110X3);
  sim_icache_fetch(1913 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 3794 */
} /* line 3794 */
  sim_icache_fetch(1914 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULLU(reg_r0_13, reg_r0_10, (unsigned int) 2100); /* line 3796 */
} /* line 3796 */
  sim_icache_fetch(1916 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3798 */
  sim_icache_fetch(1917 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_11, reg_r0_13); /* line 3800 */
} /* line 3800 */
  sim_icache_fetch(1918 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH1ADD(reg_r0_7, reg_r0_12, ((unsigned int) s_by2 + (unsigned int) -6)); /* line 3802 */
} /* line 3802 */
  sim_icache_fetch(1920 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 3804 */
} /* line 3804 */
  sim_icache_fetch(1921 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 3806 */
} /* line 3806 */
  sim_icache_fetch(1922 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 3808 */
} /* line 3808 */
  sim_icache_fetch(1923 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 3810 */
} /* line 3810 */
  sim_icache_fetch(1924 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, 0); /* line 3812 */
} /* line 3812 */
  sim_icache_fetch(1925 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, 0); /* line 3814 */
} /* line 3814 */
  sim_icache_fetch(1926 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, 0); /* line 3816 */
} /* line 3816 */
  sim_icache_fetch(1927 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_10); /* line 3818 */
} /* line 3818 */
  sim_icache_fetch(1928 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_9); /* line 3820 */
} /* line 3820 */
  sim_icache_fetch(1929 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_10); /* line 3822 */
} /* line 3822 */
  sim_icache_fetch(1930 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_11); /* line 3824 */
} /* line 3824 */
  sim_icache_fetch(1931 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_12); /* line 3826 */
} /* line 3826 */
l_L112X3: ;/* line 3829 */
LABEL(l_L112X3);
  sim_icache_fetch(1932 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -77); /* line 3830 */
} /* line 3830 */
  sim_icache_fetch(1933 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_3, (unsigned int) -23); /* line 3832 */
} /* line 3832 */
  sim_icache_fetch(1934 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 107); /* line 3834 */
} /* line 3834 */
  sim_icache_fetch(1935 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_9); /* line 3836 */
} /* line 3836 */
  sim_icache_fetch(1936 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 3838 */
} /* line 3838 */
  sim_icache_fetch(1937 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, 0); /* line 3840 */
} /* line 3840 */
  sim_icache_fetch(1938 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_5); /* line 3842 */
} /* line 3842 */
  sim_icache_fetch(1939 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 3844 */
} /* line 3844 */
  sim_icache_fetch(1940 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 3846 */
} /* line 3846 */
  sim_icache_fetch(1941 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_9, reg_r0_2); /* line 3848 */
} /* line 3848 */
  sim_icache_fetch(1942 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3850 */
  sim_icache_fetch(1943 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDH(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 4200),0,2)); /* line 3852 */
} /* line 3852 */
  sim_icache_fetch(1945 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 1); /* line 3854 */
} /* line 3854 */
  sim_icache_fetch(1946 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -77); /* line 3856 */
} /* line 3856 */
  sim_icache_fetch(1947 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_10, (unsigned int) -23); /* line 3858 */
} /* line 3858 */
  sim_icache_fetch(1948 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_9, (unsigned int) 107); /* line 3860 */
} /* line 3860 */
  sim_icache_fetch(1949 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_11); /* line 3862 */
} /* line 3862 */
  sim_icache_fetch(1950 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 14); /* line 3864 */
} /* line 3864 */
  sim_icache_fetch(1951 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_11, mem_trace_ld((reg_r0_8 + (unsigned int) 2100),0,2)); /* line 3866 */
} /* line 3866 */
  sim_icache_fetch(1953 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 3868 */
} /* line 3868 */
  sim_icache_fetch(1954 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_12); /* line 3870 */
} /* line 3870 */
  sim_icache_fetch(1955 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 3872 */
} /* line 3872 */
  sim_icache_fetch(1956 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_12, reg_r0_4); /* line 3874 */
} /* line 3874 */
  sim_icache_fetch(1957 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_6, (unsigned int) 2); /* line 3876 */
} /* line 3876 */
  sim_icache_fetch(1958 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) -77); /* line 3878 */
} /* line 3878 */
  sim_icache_fetch(1959 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_11, (unsigned int) -23); /* line 3880 */
} /* line 3880 */
  sim_icache_fetch(1960 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_12, (unsigned int) 107); /* line 3882 */
} /* line 3882 */
  sim_icache_fetch(1961 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_13); /* line 3884 */
} /* line 3884 */
  sim_icache_fetch(1962 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 14); /* line 3886 */
} /* line 3886 */
  sim_icache_fetch(1963 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_3, mem_trace_ld(reg_r0_8,0,2)); /* line 3888 */
} /* line 3888 */
  sim_icache_fetch(1964 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 3890 */
} /* line 3890 */
  sim_icache_fetch(1965 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_14); /* line 3892 */
} /* line 3892 */
  sim_icache_fetch(1966 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 7); /* line 3894 */
} /* line 3894 */
  sim_icache_fetch(1967 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_11); /* line 3896 */
} /* line 3896 */
  sim_icache_fetch(1968 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) -3); /* line 3898 */
} /* line 3898 */
  sim_icache_fetch(1969 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_7 + (unsigned int) 4),0,2), reg_r0_2); /* line 3900 */
} /* line 3900 */
  sim_icache_fetch(1970 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3902 */
  sim_icache_fetch(1971 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_7 + (unsigned int) 2),0,2), reg_r0_4); /* line 3904 */
} /* line 3904 */
  sim_icache_fetch(1972 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3906 */
  sim_icache_fetch(1973 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_4, reg_r0_9); /* line 3908 */
} /* line 3908 */
  sim_icache_fetch(1974 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_12); /* line 3910 */
} /* line 3910 */
  sim_icache_fetch(1975 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -6300); /* line 3912 */
} /* line 3912 */
  sim_icache_fetch(1977 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st(reg_r0_7,0,2), reg_r0_9); /* line 3914 */
} /* line 3914 */
  sim_icache_fetch(1978 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -6); /* line 3917 */
} /* line 3917 */
  sim_icache_fetch(1979 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L112X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L112X3;
} /* line 3919 */
l_L113X3: ;/* line 3922 */
LABEL(l_L113X3);
  sim_icache_fetch(1980 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 3923 */
} /* line 3923 */
  sim_icache_fetch(1981 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_3); /* line 3925 */
} /* line 3925 */
  sim_icache_fetch(1982 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_22); /* line 3927 */
} /* line 3927 */
  sim_icache_fetch(1983 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, (unsigned int) s_by2); /* line 3929 */
} /* line 3929 */
  sim_icache_fetch(1985 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) s_by1); /* line 3931 */
} /* line 3931 */
  sim_icache_fetch(1987 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_23); /* line 3933 */
} /* line 3933 */
  sim_icache_fetch(1988 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_20); /* line 3935 */
} /* line 3935 */
  sim_icache_fetch(1989 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_19); /* line 3937 */
} /* line 3937 */
  sim_icache_fetch(1990 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_21); /* line 3939 */
} /* line 3939 */
  sim_icache_fetch(1991 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, (unsigned int) 2100); /* line 3941 */
} /* line 3941 */
  sim_icache_fetch(1993 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_17); /* line 3943 */
} /* line 3943 */
  sim_icache_fetch(1994 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, reg_r0_18); /* line 3945 */
} /* line 3945 */
  sim_icache_fetch(1995 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_16); /* line 3947 */
} /* line 3947 */
  sim_icache_fetch(1996 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_15); /* line 3949 */
} /* line 3949 */
l_L114X3: ;/* line 3952 */
LABEL(l_L114X3);
  sim_icache_fetch(1997 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_3, mem_trace_ld(reg_r0_2,0,2)); /* line 3953 */
} /* line 3953 */
  sim_icache_fetch(1998 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -77); /* line 3955 */
} /* line 3955 */
  sim_icache_fetch(1999 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_5, (unsigned int) 107); /* line 3957 */
} /* line 3957 */
  sim_icache_fetch(2000 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -24); /* line 3959 */
} /* line 3959 */
  sim_icache_fetch(2001 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 14); /* line 3961 */
} /* line 3961 */
  sim_icache_fetch(2002 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 3963 */
} /* line 3963 */
  sim_icache_fetch(2003 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_6); /* line 3965 */
} /* line 3965 */
  sim_icache_fetch(2004 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_12); /* line 3967 */
} /* line 3967 */
  sim_icache_fetch(2005 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 3969 */
} /* line 3969 */
  sim_icache_fetch(2006 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_12, reg_r0_4); /* line 3971 */
} /* line 3971 */
  sim_icache_fetch(2007 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_13, mem_trace_ld(reg_r0_7,0,2)); /* line 3973 */
} /* line 3973 */
  sim_icache_fetch(2008 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 3975 */
} /* line 3975 */
  sim_icache_fetch(2009 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_8, 0); /* line 3977 */
} /* line 3977 */
  sim_icache_fetch(2010 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_12, reg_r0_13); /* line 3979 */
} /* line 3979 */
  sim_icache_fetch(2011 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 7); /* line 3981 */
} /* line 3981 */
  sim_icache_fetch(2012 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 14); /* line 3983 */
} /* line 3983 */
  sim_icache_fetch(2013 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3985 */
  sim_icache_fetch(2014 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_14, reg_r0_13); /* line 3987 */
} /* line 3987 */
  sim_icache_fetch(2015 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_14, (unsigned int) 25); /* line 3989 */
} /* line 3989 */
  sim_icache_fetch(2016 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 2100),0,2)); /* line 3991 */
} /* line 3991 */
  sim_icache_fetch(2018 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -77); /* line 3993 */
} /* line 3993 */
  sim_icache_fetch(2019 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_12, (unsigned int) 107); /* line 3995 */
} /* line 3995 */
  sim_icache_fetch(2020 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_16, reg_r0_6, (unsigned int) -24); /* line 3997 */
} /* line 3997 */
  sim_icache_fetch(2021 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_17, reg_r0_3, (unsigned int) 14); /* line 3999 */
} /* line 3999 */
  sim_icache_fetch(2022 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_16); /* line 4001 */
} /* line 4001 */
  sim_icache_fetch(2023 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_17); /* line 4003 */
} /* line 4003 */
  sim_icache_fetch(2024 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_15); /* line 4005 */
} /* line 4005 */
  sim_icache_fetch(2025 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 4007 */
} /* line 4007 */
  sim_icache_fetch(2026 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_15, mem_trace_ld((reg_r0_7 + (unsigned int) 2),0,2)); /* line 4009 */
} /* line 4009 */
  sim_icache_fetch(2027 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st(reg_r0_10,0,2), reg_r0_4); /* line 4011 */
} /* line 4011 */
  sim_icache_fetch(2028 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_12); /* line 4013 */
} /* line 4013 */
  sim_icache_fetch(2029 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_13); /* line 4015 */
} /* line 4015 */
  sim_icache_fetch(2030 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4017 */
  sim_icache_fetch(2031 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_5, reg_r0_14); /* line 4019 */
} /* line 4019 */
  sim_icache_fetch(2032 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_5, reg_r0_15); /* line 4021 */
} /* line 4021 */
  sim_icache_fetch(2033 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_15, reg_r0_15, (unsigned int) 7); /* line 4023 */
} /* line 4023 */
  sim_icache_fetch(2034 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 14); /* line 4025 */
} /* line 4025 */
  sim_icache_fetch(2035 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_3, reg_r0_15); /* line 4027 */
} /* line 4027 */
  sim_icache_fetch(2036 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 4029 */
} /* line 4029 */
  sim_icache_fetch(2037 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), 0); /* line 4031 */
} /* line 4031 */
l_L117X3: ;/* line 4033 */
LABEL(l_L117X3);
  sim_icache_fetch(2038 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4034 */
  sim_icache_fetch(2039 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_10 + (unsigned int) 2),0,2), reg_r0_14); /* line 4036 */
} /* line 4036 */
  sim_icache_fetch(2040 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_15); /* line 4038 */
} /* line 4038 */
  sim_icache_fetch(2042 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4040 */
  sim_icache_fetch(2043 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4200); /* line 4042 */
} /* line 4042 */
  sim_icache_fetch(2045 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 4044 */
} /* line 4044 */
  sim_icache_fetch(2046 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 4046 */
} /* line 4046 */
  sim_icache_fetch(2047 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 4048 */
} /* line 4048 */
  sim_icache_fetch(2048 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), 0); /* line 4050 */
} /* line 4050 */
l_L119X3: ;/* line 4052 */
LABEL(l_L119X3);
  sim_icache_fetch(2050 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_11); /* line 4054 */
} /* line 4054 */
  sim_icache_fetch(2051 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L114X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L114X3;
} /* line 4056 */
l_L118X3: ;/* line 4059 */
LABEL(l_L118X3);
  sim_icache_fetch(2052 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 4060 */
} /* line 4060 */
  sim_icache_fetch(2053 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 4062 */
} /* line 4062 */
  sim_icache_fetch(2054 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 4064 */
} /* line 4064 */
  sim_icache_fetch(2055 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 4066 */
} /* line 4066 */
  sim_icache_fetch(2056 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4200); /* line 4068 */
} /* line 4068 */
  sim_icache_fetch(2058 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_3); /* line 4071 */
} /* line 4071 */
  sim_icache_fetch(2060 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L119X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L119X3;
} /* line 4073 */
l_L115X3: ;/* line 4076 */
LABEL(l_L115X3);
  sim_icache_fetch(2061 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 2); /* line 4077 */
} /* line 4077 */
  sim_icache_fetch(2062 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_22, reg_r0_22, (unsigned int) 1); /* line 4079 */
} /* line 4079 */
  sim_icache_fetch(2063 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_19, (unsigned int) 2); /* line 4081 */
} /* line 4081 */
  sim_icache_fetch(2064 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_20, (unsigned int) 1); /* line 4083 */
} /* line 4083 */
  sim_icache_fetch(2065 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_18); /* line 4085 */
} /* line 4085 */
  sim_icache_fetch(2066 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_21); /* line 4088 */
} /* line 4088 */
  sim_icache_fetch(2067 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L110X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L110X3;
} /* line 4090 */
l_L116X3: ;/* line 4093 */
LABEL(l_L116X3);
  sim_icache_fetch(2068 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 4094 */
} /* line 4094 */
  sim_icache_fetch(2069 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_5, reg_r0_14); /* line 4096 */
} /* line 4096 */
  sim_icache_fetch(2070 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_5, reg_r0_15); /* line 4098 */
} /* line 4098 */
  sim_icache_fetch(2071 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_15, reg_r0_15, (unsigned int) 7); /* line 4100 */
} /* line 4100 */
  sim_icache_fetch(2072 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 14); /* line 4102 */
} /* line 4102 */
  sim_icache_fetch(2073 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_12, reg_r0_15); /* line 4104 */
} /* line 4104 */
  sim_icache_fetch(2074 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_12, (unsigned int) 25); /* line 4106 */
} /* line 4106 */
  sim_icache_fetch(2075 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_3); /* line 4109 */
} /* line 4109 */
  sim_icache_fetch(2076 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L117X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L117X3;
} /* line 4111 */
l_L111X3: ;/* line 4114 */
LABEL(l_L111X3);
  sim_icache_fetch(2077 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_short);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4116 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 278: goto l_L101X3;
    case 279: goto l_L103X3;
    case 280: goto l_L106X3;
    case 281: goto l_L108X3;
    case 282: goto l_L109X3;
    case 283: goto l_L105X3;
    case 284: goto l_L104X3;
    case 285: goto l_L107X3;
    case 286: goto l_L102X3;
    case 287: goto l_L110X3;
    case 288: goto l_L112X3;
    case 289: goto l_L113X3;
    case 290: goto l_L114X3;
    case 291: goto l_L117X3;
    case 292: goto l_L119X3;
    case 293: goto l_L118X3;
    case 294: goto l_L115X3;
    case 295: goto l_L116X3;
    case 296: goto l_L111X3;
    case 297:
      reg_l0_0 = t_client_rpc;
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern  deriche_simd( unsigned int arg0, unsigned int arg1 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   ENTRY(deriche_simd);
  sim_check_stack(reg_r0_1, 0); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (314 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(2078 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 4132 */
  sim_icache_fetch(2079 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 4134 */
} /* line 4134 */
  sim_icache_fetch(2080 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, reg_r0_2); /* line 4136 */
} /* line 4136 */
  sim_icache_fetch(2081 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, (unsigned int) -23); /* line 4138 */
} /* line 4138 */
  sim_icache_fetch(2082 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(6,reg_r0_2,(unsigned int) 14);
   }
 /* line 4140 */
} /* line 4140 */
  sim_icache_fetch(2083 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, (unsigned int) -24); /* line 4142 */
} /* line 4142 */
  sim_icache_fetch(2084 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_27 = (unsigned int) sim_asm_op1(6,reg_r0_6,(unsigned int) 14);
   }
 /* line 4144 */
} /* line 4144 */
  sim_icache_fetch(2085 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_7 = (unsigned int) sim_asm_op1(6,reg_r0_2,(unsigned int) -24);
   }
 /* line 4146 */
} /* line 4146 */
  sim_icache_fetch(2086 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, (unsigned int) 107); /* line 4148 */
} /* line 4148 */
  sim_icache_fetch(2087 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_26, (unsigned int) in); /* line 4150 */
} /* line 4150 */
  sim_icache_fetch(2089 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_4); /* line 4152 */
} /* line 4152 */
  sim_icache_fetch(2090 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_4 = (unsigned int) sim_asm_op1(6,reg_r0_2,(unsigned int) -77);
   }
 /* line 4154 */
} /* line 4154 */
  sim_icache_fetch(2091 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_25, (unsigned int) s_at); /* line 4156 */
} /* line 4156 */
  sim_icache_fetch(2093 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_14, (unsigned int) -1); /* line 4158 */
} /* line 4158 */
  sim_icache_fetch(2094 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, ((unsigned int) in + (unsigned int) -2)); /* line 4160 */
} /* line 4160 */
  sim_icache_fetch(2096 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_28, reg_r0_3); /* line 4162 */
} /* line 4162 */
l_L120X3: ;/* line 4165 */
LABEL(l_L120X3);
  sim_icache_fetch(2097 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_11, 0); /* line 4166 */
} /* line 4166 */
  sim_icache_fetch(2098 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_12, reg_r0_13); /* line 4168 */
} /* line 4168 */
  sim_icache_fetch(2099 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4170 */
  sim_icache_fetch(2100 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH1ADD(reg_r0_9, reg_r0_14, ((unsigned int) s_ay2 + (unsigned int) -6)); /* line 4172 */
} /* line 4172 */
  sim_icache_fetch(2102 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 4174 */
} /* line 4174 */
  sim_icache_fetch(2103 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 4176 */
} /* line 4176 */
  sim_icache_fetch(2104 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, 0); /* line 4178 */
} /* line 4178 */
  sim_icache_fetch(2105 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 4180 */
} /* line 4180 */
  sim_icache_fetch(2106 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, 0); /* line 4182 */
} /* line 4182 */
  sim_icache_fetch(2107 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_23, 0); /* line 4184 */
} /* line 4184 */
  sim_icache_fetch(2108 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_24, 0); /* line 4186 */
} /* line 4186 */
  sim_icache_fetch(2109 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_13); /* line 4188 */
} /* line 4188 */
  sim_icache_fetch(2110 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_11); /* line 4190 */
} /* line 4190 */
  sim_icache_fetch(2111 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_12); /* line 4192 */
} /* line 4192 */
  sim_icache_fetch(2112 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_13); /* line 4194 */
} /* line 4194 */
  sim_icache_fetch(2113 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, reg_r0_14); /* line 4196 */
} /* line 4196 */
l_L122X3: ;/* line 4199 */
LABEL(l_L122X3);
  sim_icache_fetch(2114 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4200 */
} /* line 4200 */
  sim_icache_fetch(2115 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 7); /* line 4202 */
} /* line 4202 */
  sim_icache_fetch(2116 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_3 = (unsigned int) sim_asm_op1(6,reg_r0_2,reg_r0_3);
   }
 /* line 4204 */
} /* line 4204 */
  sim_icache_fetch(2117 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_3 = (unsigned int) sim_asm_op1(65,reg_r0_4,reg_r0_3);
   }
 /* line 4206 */
} /* line 4206 */
  sim_icache_fetch(2118 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_6 = (unsigned int) sim_asm_op1(6,reg_r0_5,reg_r0_6);
   }
 /* line 4208 */
} /* line 4208 */
  sim_icache_fetch(2119 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_6 = (unsigned int) sim_asm_op1(65,reg_r0_7,reg_r0_6);
   }
 /* line 4210 */
} /* line 4210 */
  sim_icache_fetch(2120 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_8, 0); /* line 4212 */
} /* line 4212 */
  sim_icache_fetch(2121 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_6 = (unsigned int) sim_asm_op1(1,reg_r0_6,reg_r0_3);
   }
 /* line 4214 */
} /* line 4214 */
  sim_icache_fetch(2122 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_11 = (unsigned int) sim_asm_op1(7,reg_r0_6,0);
   }
 /* line 4216 */
} /* line 4216 */
  sim_icache_fetch(2123 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_6 = (unsigned int) sim_asm_op1(7,reg_r0_6,(unsigned int) 1);
   }
 /* line 4218 */
} /* line 4218 */
  sim_icache_fetch(2124 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_6); /* line 4220 */
} /* line 4220 */
  sim_icache_fetch(2125 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_12, reg_r0_11); /* line 4222 */
} /* line 4222 */
  sim_icache_fetch(2126 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4224 */
  sim_icache_fetch(2127 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_13, mem_trace_ld((reg_r0_10 + (unsigned int) 2),0,1)); /* line 4226 */
} /* line 4226 */
  sim_icache_fetch(2128 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 4228 */
} /* line 4228 */
  sim_icache_fetch(2129 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 7); /* line 4230 */
} /* line 4230 */
  sim_icache_fetch(2130 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_2 = (unsigned int) sim_asm_op1(6,reg_r0_12,reg_r0_2);
   }
 /* line 4232 */
} /* line 4232 */
  sim_icache_fetch(2131 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_2 = (unsigned int) sim_asm_op1(65,reg_r0_4,reg_r0_2);
   }
 /* line 4234 */
} /* line 4234 */
  sim_icache_fetch(2132 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(6,reg_r0_13,reg_r0_5);
   }
 /* line 4236 */
} /* line 4236 */
  sim_icache_fetch(2133 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(65,reg_r0_7,reg_r0_5);
   }
 /* line 4238 */
} /* line 4238 */
  sim_icache_fetch(2134 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_10 + (unsigned int) 1),0,1)); /* line 4240 */
} /* line 4240 */
  sim_icache_fetch(2135 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(1,reg_r0_5,reg_r0_2);
   }
 /* line 4242 */
} /* line 4242 */
  sim_icache_fetch(2136 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_15 = (unsigned int) sim_asm_op1(7,reg_r0_5,0);
   }
 /* line 4244 */
} /* line 4244 */
  sim_icache_fetch(2137 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(7,reg_r0_5,(unsigned int) 1);
   }
 /* line 4246 */
} /* line 4246 */
  sim_icache_fetch(2138 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_5); /* line 4248 */
} /* line 4248 */
  sim_icache_fetch(2139 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_16, reg_r0_15); /* line 4250 */
} /* line 4250 */
  sim_icache_fetch(2140 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_8, (unsigned int) 2); /* line 4252 */
} /* line 4252 */
  sim_icache_fetch(2141 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_17, reg_r0_16, (unsigned int) 7); /* line 4254 */
} /* line 4254 */
  sim_icache_fetch(2142 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_17 = (unsigned int) sim_asm_op1(6,reg_r0_17,reg_r0_12);
   }
 /* line 4256 */
} /* line 4256 */
  sim_icache_fetch(2143 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_17 = (unsigned int) sim_asm_op1(65,reg_r0_4,reg_r0_17);
   }
 /* line 4258 */
} /* line 4258 */
  sim_icache_fetch(2144 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_13 = (unsigned int) sim_asm_op1(6,reg_r0_14,reg_r0_13);
   }
 /* line 4260 */
} /* line 4260 */
  sim_icache_fetch(2145 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_13 = (unsigned int) sim_asm_op1(65,reg_r0_7,reg_r0_13);
   }
 /* line 4262 */
} /* line 4262 */
  sim_icache_fetch(2146 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_5, mem_trace_ld(reg_r0_10,0,1)); /* line 4264 */
} /* line 4264 */
  sim_icache_fetch(2147 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_13 = (unsigned int) sim_asm_op1(1,reg_r0_13,reg_r0_17);
   }
 /* line 4266 */
} /* line 4266 */
  sim_icache_fetch(2148 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_12 = (unsigned int) sim_asm_op1(7,reg_r0_13,0);
   }
 /* line 4268 */
} /* line 4268 */
  sim_icache_fetch(2149 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_13 = (unsigned int) sim_asm_op1(7,reg_r0_13,(unsigned int) 1);
   }
 /* line 4270 */
} /* line 4270 */
  sim_icache_fetch(2150 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_13); /* line 4272 */
} /* line 4272 */
  sim_icache_fetch(2151 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_2, reg_r0_12); /* line 4274 */
} /* line 4274 */
  sim_icache_fetch(2152 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_16); /* line 4276 */
} /* line 4276 */
  sim_icache_fetch(2153 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_14); /* line 4278 */
} /* line 4278 */
  sim_icache_fetch(2154 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -3); /* line 4280 */
} /* line 4280 */
  sim_icache_fetch(2155 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) -3); /* line 4282 */
} /* line 4282 */
  sim_icache_fetch(2156 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_9 + (unsigned int) 4),0,2), reg_r0_11); /* line 4284 */
} /* line 4284 */
  sim_icache_fetch(2157 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4286 */
  sim_icache_fetch(2158 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_9 + (unsigned int) 2),0,2), reg_r0_15); /* line 4288 */
} /* line 4288 */
  sim_icache_fetch(2159 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4290 */
  sim_icache_fetch(2160 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st(reg_r0_9,0,2), reg_r0_12); /* line 4292 */
} /* line 4292 */
  sim_icache_fetch(2161 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -6); /* line 4295 */
} /* line 4295 */
  sim_icache_fetch(2162 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L122X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L122X3;
} /* line 4297 */
l_L123X3: ;/* line 4300 */
LABEL(l_L123X3);
  sim_icache_fetch(2163 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_21); /* line 4301 */
} /* line 4301 */
  sim_icache_fetch(2164 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, reg_r0_3); /* line 4303 */
} /* line 4303 */
  sim_icache_fetch(2165 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_25); /* line 4305 */
} /* line 4305 */
  sim_icache_fetch(2166 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) s_ay2); /* line 4307 */
} /* line 4307 */
  sim_icache_fetch(2168 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, (unsigned int) s_ay1); /* line 4309 */
} /* line 4309 */
  sim_icache_fetch(2170 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_26); /* line 4311 */
} /* line 4311 */
  sim_icache_fetch(2171 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_22); /* line 4313 */
} /* line 4313 */
  sim_icache_fetch(2172 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_23); /* line 4315 */
} /* line 4315 */
  sim_icache_fetch(2173 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_24); /* line 4317 */
} /* line 4317 */
  sim_icache_fetch(2174 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, reg_r0_21); /* line 4319 */
} /* line 4319 */
  sim_icache_fetch(2175 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, reg_r0_18); /* line 4321 */
} /* line 4321 */
  sim_icache_fetch(2176 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_27); /* line 4323 */
} /* line 4323 */
l_L124X3: ;/* line 4326 */
LABEL(l_L124X3);
  sim_icache_fetch(2177 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 4327 */
} /* line 4327 */
  sim_icache_fetch(2178 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 7); /* line 4329 */
} /* line 4329 */
  sim_icache_fetch(2179 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 7); /* line 4331 */
} /* line 4331 */
  sim_icache_fetch(2180 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(6,reg_r0_3,reg_r0_5);
   }
 /* line 4333 */
} /* line 4333 */
  sim_icache_fetch(2181 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(65,reg_r0_6,reg_r0_5);
   }
 /* line 4335 */
} /* line 4335 */
  sim_icache_fetch(2182 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_9 = (unsigned int) sim_asm_op1(6,reg_r0_8,reg_r0_9);
   }
 /* line 4337 */
} /* line 4337 */
  sim_icache_fetch(2183 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_9 = (unsigned int) sim_asm_op1(65,reg_r0_4,reg_r0_9);
   }
 /* line 4339 */
} /* line 4339 */
  sim_icache_fetch(2184 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_14, mem_trace_ld(reg_r0_10,0,2)); /* line 4341 */
} /* line 4341 */
  sim_icache_fetch(2185 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(1,reg_r0_5,reg_r0_9);
   }
 /* line 4343 */
} /* line 4343 */
  sim_icache_fetch(2186 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_15 = (unsigned int) sim_asm_op1(7,reg_r0_5,0);
   }
 /* line 4345 */
} /* line 4345 */
  sim_icache_fetch(2187 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(7,reg_r0_5,(unsigned int) 1);
   }
 /* line 4347 */
} /* line 4347 */
  sim_icache_fetch(2188 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_5); /* line 4349 */
} /* line 4349 */
  sim_icache_fetch(2189 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_16, reg_r0_15); /* line 4351 */
} /* line 4351 */
  sim_icache_fetch(2190 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_16, reg_r0_14); /* line 4353 */
} /* line 4353 */
  sim_icache_fetch(2191 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 4355 */
} /* line 4355 */
  sim_icache_fetch(2192 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 4357 */
} /* line 4357 */
  sim_icache_fetch(2193 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_11, (unsigned int) 1); /* line 4359 */
} /* line 4359 */
  sim_icache_fetch(2194 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_11, 0); /* line 4361 */
} /* line 4361 */
  sim_icache_fetch(2195 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4363 */
  sim_icache_fetch(2196 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_5, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 4365 */
} /* line 4365 */
  sim_icache_fetch(2197 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_17, reg_r0_16, (unsigned int) 7); /* line 4367 */
} /* line 4367 */
  sim_icache_fetch(2198 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_17 = (unsigned int) sim_asm_op1(6,reg_r0_17,reg_r0_8);
   }
 /* line 4369 */
} /* line 4369 */
  sim_icache_fetch(2199 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_3 = (unsigned int) sim_asm_op1(6,reg_r0_5,reg_r0_3);
   }
 /* line 4371 */
} /* line 4371 */
  sim_icache_fetch(2200 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_3 = (unsigned int) sim_asm_op1(65,reg_r0_6,reg_r0_3);
   }
 /* line 4373 */
} /* line 4373 */
  sim_icache_fetch(2201 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_17 = (unsigned int) sim_asm_op1(65,reg_r0_4,reg_r0_17);
   }
 /* line 4375 */
} /* line 4375 */
  sim_icache_fetch(2202 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_18, mem_trace_ld((reg_r0_10 + (unsigned int) 2),0,2)); /* line 4377 */
} /* line 4377 */
  sim_icache_fetch(2203 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_3 = (unsigned int) sim_asm_op1(1,reg_r0_3,reg_r0_17);
   }
 /* line 4379 */
} /* line 4379 */
  sim_icache_fetch(2204 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_17 = (unsigned int) sim_asm_op1(7,reg_r0_3,0);
   }
 /* line 4381 */
} /* line 4381 */
  sim_icache_fetch(2205 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_3 = (unsigned int) sim_asm_op1(7,reg_r0_3,(unsigned int) 1);
   }
 /* line 4383 */
} /* line 4383 */
  sim_icache_fetch(2206 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_17, reg_r0_17, reg_r0_3); /* line 4385 */
} /* line 4385 */
  sim_icache_fetch(2207 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_8, reg_r0_17); /* line 4387 */
} /* line 4387 */
  sim_icache_fetch(2208 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_18, reg_r0_8, reg_r0_18); /* line 4389 */
} /* line 4389 */
  sim_icache_fetch(2209 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_18, reg_r0_18, (unsigned int) 7); /* line 4391 */
} /* line 4391 */
  sim_icache_fetch(2210 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_18, reg_r0_18, (unsigned int) 7); /* line 4393 */
} /* line 4393 */
  sim_icache_fetch(2211 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_16); /* line 4395 */
} /* line 4395 */
  sim_icache_fetch(2212 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 2); /* line 4397 */
} /* line 4397 */
  sim_icache_fetch(2213 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 4399 */
} /* line 4399 */
  sim_icache_fetch(2214 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, (unsigned int) 2); /* line 4401 */
} /* line 4401 */
  sim_icache_fetch(2215 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st(reg_r0_12,0,2), reg_r0_14); /* line 4403 */
} /* line 4403 */
  sim_icache_fetch(2216 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st(reg_r0_13,0,2), reg_r0_15); /* line 4405 */
} /* line 4405 */
  sim_icache_fetch(2217 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4407 */
  sim_icache_fetch(2218 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_13 + (unsigned int) 2),0,2), reg_r0_17); /* line 4409 */
} /* line 4409 */
  sim_icache_fetch(2219 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, (unsigned int) 4); /* line 4411 */
} /* line 4411 */
  sim_icache_fetch(2220 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_12 + (unsigned int) 2),0,2), reg_r0_18); /* line 4413 */
} /* line 4413 */
  sim_icache_fetch(2221 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, (unsigned int) 4); /* line 4416 */
} /* line 4416 */
  sim_icache_fetch(2222 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L124X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L124X3;
} /* line 4418 */
l_L125X3: ;/* line 4421 */
LABEL(l_L125X3);
  sim_icache_fetch(2223 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_26, reg_r0_26, (unsigned int) 1050); /* line 4422 */
} /* line 4422 */
  sim_icache_fetch(2225 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 2100); /* line 4424 */
} /* line 4424 */
  sim_icache_fetch(2227 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 1050); /* line 4426 */
} /* line 4426 */
  sim_icache_fetch(2229 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_21, (unsigned int) 1); /* line 4428 */
} /* line 4428 */
  sim_icache_fetch(2230 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_22); /* line 4430 */
} /* line 4430 */
  sim_icache_fetch(2231 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_20); /* line 4432 */
} /* line 4432 */
  sim_icache_fetch(2232 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_27, reg_r0_6); /* line 4435 */
} /* line 4435 */
  sim_icache_fetch(2233 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L120X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L120X3;
} /* line 4437 */
l_L121X3: ;/* line 4440 */
LABEL(l_L121X3);
  sim_icache_fetch(2234 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_14, 0, reg_r0_14); /* line 4441 */
} /* line 4441 */
  sim_icache_fetch(2235 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_14); /* line 4443 */
} /* line 4443 */
  sim_icache_fetch(2236 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_23, (unsigned int) s_at); /* line 4445 */
} /* line 4445 */
  sim_icache_fetch(2238 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, (unsigned int) out); /* line 4447 */
} /* line 4447 */
  sim_icache_fetch(2240 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, ((unsigned int) s_at + (unsigned int) -4200)); /* line 4449 */
} /* line 4449 */
  sim_icache_fetch(2242 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_28, (unsigned int) -1); /* line 4451 */
} /* line 4451 */
  sim_icache_fetch(2243 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_28); /* line 4453 */
} /* line 4453 */
l_L126X3: ;/* line 4456 */
LABEL(l_L126X3);
  sim_icache_fetch(2244 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 4457 */
} /* line 4457 */
  sim_icache_fetch(2245 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULLU(reg_r0_13, reg_r0_10, (unsigned int) 2100); /* line 4459 */
} /* line 4459 */
  sim_icache_fetch(2247 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4461 */
  sim_icache_fetch(2248 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_11, reg_r0_13); /* line 4463 */
} /* line 4463 */
  sim_icache_fetch(2249 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH1ADD(reg_r0_7, reg_r0_12, ((unsigned int) s_by2 + (unsigned int) -6)); /* line 4465 */
} /* line 4465 */
  sim_icache_fetch(2251 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 4467 */
} /* line 4467 */
  sim_icache_fetch(2252 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 4469 */
} /* line 4469 */
  sim_icache_fetch(2253 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 4471 */
} /* line 4471 */
  sim_icache_fetch(2254 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 4473 */
} /* line 4473 */
  sim_icache_fetch(2255 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, 0); /* line 4475 */
} /* line 4475 */
  sim_icache_fetch(2256 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, 0); /* line 4477 */
} /* line 4477 */
  sim_icache_fetch(2257 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, 0); /* line 4479 */
} /* line 4479 */
  sim_icache_fetch(2258 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_10); /* line 4481 */
} /* line 4481 */
  sim_icache_fetch(2259 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_9); /* line 4483 */
} /* line 4483 */
  sim_icache_fetch(2260 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_10); /* line 4485 */
} /* line 4485 */
  sim_icache_fetch(2261 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_11); /* line 4487 */
} /* line 4487 */
  sim_icache_fetch(2262 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_12); /* line 4489 */
} /* line 4489 */
l_L128X3: ;/* line 4492 */
LABEL(l_L128X3);
  sim_icache_fetch(2263 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -77); /* line 4493 */
} /* line 4493 */
  sim_icache_fetch(2264 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_3, (unsigned int) -23); /* line 4495 */
} /* line 4495 */
  sim_icache_fetch(2265 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 107); /* line 4497 */
} /* line 4497 */
  sim_icache_fetch(2266 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_9); /* line 4499 */
} /* line 4499 */
  sim_icache_fetch(2267 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 14); /* line 4501 */
} /* line 4501 */
  sim_icache_fetch(2268 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, 0); /* line 4503 */
} /* line 4503 */
  sim_icache_fetch(2269 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_5); /* line 4505 */
} /* line 4505 */
  sim_icache_fetch(2270 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 4507 */
} /* line 4507 */
  sim_icache_fetch(2271 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 4509 */
} /* line 4509 */
  sim_icache_fetch(2272 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_9, reg_r0_2); /* line 4511 */
} /* line 4511 */
  sim_icache_fetch(2273 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4513 */
  sim_icache_fetch(2274 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDH(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 4200),0,2)); /* line 4515 */
} /* line 4515 */
  sim_icache_fetch(2276 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 1); /* line 4517 */
} /* line 4517 */
  sim_icache_fetch(2277 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -77); /* line 4519 */
} /* line 4519 */
  sim_icache_fetch(2278 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_10, (unsigned int) -23); /* line 4521 */
} /* line 4521 */
  sim_icache_fetch(2279 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_9, (unsigned int) 107); /* line 4523 */
} /* line 4523 */
  sim_icache_fetch(2280 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_11); /* line 4525 */
} /* line 4525 */
  sim_icache_fetch(2281 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 14); /* line 4527 */
} /* line 4527 */
  sim_icache_fetch(2282 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_11, mem_trace_ld((reg_r0_8 + (unsigned int) 2100),0,2)); /* line 4529 */
} /* line 4529 */
  sim_icache_fetch(2284 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 4531 */
} /* line 4531 */
  sim_icache_fetch(2285 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_12); /* line 4533 */
} /* line 4533 */
  sim_icache_fetch(2286 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 4535 */
} /* line 4535 */
  sim_icache_fetch(2287 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_12, reg_r0_4); /* line 4537 */
} /* line 4537 */
  sim_icache_fetch(2288 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_6, (unsigned int) 2); /* line 4539 */
} /* line 4539 */
  sim_icache_fetch(2289 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) -77); /* line 4541 */
} /* line 4541 */
  sim_icache_fetch(2290 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_11, (unsigned int) -23); /* line 4543 */
} /* line 4543 */
  sim_icache_fetch(2291 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_12, (unsigned int) 107); /* line 4545 */
} /* line 4545 */
  sim_icache_fetch(2292 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_13); /* line 4547 */
} /* line 4547 */
  sim_icache_fetch(2293 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 14); /* line 4549 */
} /* line 4549 */
  sim_icache_fetch(2294 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_3, mem_trace_ld(reg_r0_8,0,2)); /* line 4551 */
} /* line 4551 */
  sim_icache_fetch(2295 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 4553 */
} /* line 4553 */
  sim_icache_fetch(2296 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_14); /* line 4555 */
} /* line 4555 */
  sim_icache_fetch(2297 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 7); /* line 4557 */
} /* line 4557 */
  sim_icache_fetch(2298 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_11); /* line 4559 */
} /* line 4559 */
  sim_icache_fetch(2299 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_7 + (unsigned int) 4),0,2), reg_r0_2); /* line 4561 */
} /* line 4561 */
  sim_icache_fetch(2300 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4563 */
  sim_icache_fetch(2301 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_7 + (unsigned int) 2),0,2), reg_r0_4); /* line 4565 */
} /* line 4565 */
  sim_icache_fetch(2302 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4567 */
  sim_icache_fetch(2303 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_4, reg_r0_9); /* line 4569 */
} /* line 4569 */
  sim_icache_fetch(2304 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_12); /* line 4571 */
} /* line 4571 */
  sim_icache_fetch(2305 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) -3); /* line 4573 */
} /* line 4573 */
  sim_icache_fetch(2306 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -6300); /* line 4575 */
} /* line 4575 */
  sim_icache_fetch(2308 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st(reg_r0_7,0,2), reg_r0_9); /* line 4577 */
} /* line 4577 */
  sim_icache_fetch(2309 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -6); /* line 4580 */
} /* line 4580 */
  sim_icache_fetch(2310 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L128X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L128X3;
} /* line 4582 */
l_L129X3: ;/* line 4585 */
LABEL(l_L129X3);
  sim_icache_fetch(2311 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 4586 */
} /* line 4586 */
  sim_icache_fetch(2312 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_3); /* line 4588 */
} /* line 4588 */
  sim_icache_fetch(2313 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_22); /* line 4590 */
} /* line 4590 */
  sim_icache_fetch(2314 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, (unsigned int) s_by2); /* line 4592 */
} /* line 4592 */
  sim_icache_fetch(2316 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) s_by1); /* line 4594 */
} /* line 4594 */
  sim_icache_fetch(2318 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_23); /* line 4596 */
} /* line 4596 */
  sim_icache_fetch(2319 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_20); /* line 4598 */
} /* line 4598 */
  sim_icache_fetch(2320 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_19); /* line 4600 */
} /* line 4600 */
  sim_icache_fetch(2321 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_21); /* line 4602 */
} /* line 4602 */
  sim_icache_fetch(2322 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, (unsigned int) 2100); /* line 4604 */
} /* line 4604 */
  sim_icache_fetch(2324 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_17); /* line 4606 */
} /* line 4606 */
  sim_icache_fetch(2325 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, reg_r0_18); /* line 4608 */
} /* line 4608 */
  sim_icache_fetch(2326 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_16); /* line 4610 */
} /* line 4610 */
  sim_icache_fetch(2327 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_15); /* line 4612 */
} /* line 4612 */
l_L130X3: ;/* line 4615 */
LABEL(l_L130X3);
  sim_icache_fetch(2328 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_3, mem_trace_ld(reg_r0_2,0,2)); /* line 4616 */
} /* line 4616 */
  sim_icache_fetch(2329 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -77); /* line 4618 */
} /* line 4618 */
  sim_icache_fetch(2330 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_5, (unsigned int) 107); /* line 4620 */
} /* line 4620 */
  sim_icache_fetch(2331 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -24); /* line 4622 */
} /* line 4622 */
  sim_icache_fetch(2332 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 14); /* line 4624 */
} /* line 4624 */
  sim_icache_fetch(2333 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 4626 */
} /* line 4626 */
  sim_icache_fetch(2334 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_6); /* line 4628 */
} /* line 4628 */
  sim_icache_fetch(2335 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_12); /* line 4630 */
} /* line 4630 */
  sim_icache_fetch(2336 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 4632 */
} /* line 4632 */
  sim_icache_fetch(2337 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_12, reg_r0_4); /* line 4634 */
} /* line 4634 */
  sim_icache_fetch(2338 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_13, mem_trace_ld(reg_r0_7,0,2)); /* line 4636 */
} /* line 4636 */
  sim_icache_fetch(2339 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 4638 */
} /* line 4638 */
  sim_icache_fetch(2340 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_8, 0); /* line 4640 */
} /* line 4640 */
  sim_icache_fetch(2341 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_12, reg_r0_13); /* line 4642 */
} /* line 4642 */
  sim_icache_fetch(2342 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 7); /* line 4644 */
} /* line 4644 */
  sim_icache_fetch(2343 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 14); /* line 4646 */
} /* line 4646 */
  sim_icache_fetch(2344 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4648 */
  sim_icache_fetch(2345 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_14, reg_r0_13); /* line 4650 */
} /* line 4650 */
  sim_icache_fetch(2346 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_14, (unsigned int) 25); /* line 4652 */
} /* line 4652 */
  sim_icache_fetch(2347 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 2100),0,2)); /* line 4654 */
} /* line 4654 */
  sim_icache_fetch(2349 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -77); /* line 4656 */
} /* line 4656 */
  sim_icache_fetch(2350 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_12, (unsigned int) 107); /* line 4658 */
} /* line 4658 */
  sim_icache_fetch(2351 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_16, reg_r0_6, (unsigned int) -24); /* line 4660 */
} /* line 4660 */
  sim_icache_fetch(2352 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_17, reg_r0_3, (unsigned int) 14); /* line 4662 */
} /* line 4662 */
  sim_icache_fetch(2353 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_16); /* line 4664 */
} /* line 4664 */
  sim_icache_fetch(2354 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_17); /* line 4666 */
} /* line 4666 */
  sim_icache_fetch(2355 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_15); /* line 4668 */
} /* line 4668 */
  sim_icache_fetch(2356 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 4670 */
} /* line 4670 */
  sim_icache_fetch(2357 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_15, mem_trace_ld((reg_r0_7 + (unsigned int) 2),0,2)); /* line 4672 */
} /* line 4672 */
  sim_icache_fetch(2358 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st(reg_r0_10,0,2), reg_r0_4); /* line 4674 */
} /* line 4674 */
  sim_icache_fetch(2359 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_12); /* line 4676 */
} /* line 4676 */
  sim_icache_fetch(2360 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_13); /* line 4678 */
} /* line 4678 */
  sim_icache_fetch(2361 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4680 */
  sim_icache_fetch(2362 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_5, reg_r0_14); /* line 4682 */
} /* line 4682 */
  sim_icache_fetch(2363 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_5, reg_r0_15); /* line 4684 */
} /* line 4684 */
  sim_icache_fetch(2364 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_15, reg_r0_15, (unsigned int) 7); /* line 4686 */
} /* line 4686 */
  sim_icache_fetch(2365 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 14); /* line 4688 */
} /* line 4688 */
  sim_icache_fetch(2366 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_3, reg_r0_15); /* line 4690 */
} /* line 4690 */
  sim_icache_fetch(2367 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 4692 */
} /* line 4692 */
  sim_icache_fetch(2368 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), 0); /* line 4694 */
} /* line 4694 */
l_L133X3: ;/* line 4696 */
LABEL(l_L133X3);
  sim_icache_fetch(2369 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4697 */
  sim_icache_fetch(2370 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st((reg_r0_10 + (unsigned int) 2),0,2), reg_r0_14); /* line 4699 */
} /* line 4699 */
  sim_icache_fetch(2371 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_15); /* line 4701 */
} /* line 4701 */
  sim_icache_fetch(2373 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 4703 */
  sim_icache_fetch(2374 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4200); /* line 4705 */
} /* line 4705 */
  sim_icache_fetch(2376 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 4707 */
} /* line 4707 */
  sim_icache_fetch(2377 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 4709 */
} /* line 4709 */
  sim_icache_fetch(2378 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 4711 */
} /* line 4711 */
  sim_icache_fetch(2379 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), 0); /* line 4713 */
} /* line 4713 */
l_L135X3: ;/* line 4715 */
LABEL(l_L135X3);
  sim_icache_fetch(2381 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_11); /* line 4717 */
} /* line 4717 */
  sim_icache_fetch(2382 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L130X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L130X3;
} /* line 4719 */
l_L134X3: ;/* line 4722 */
LABEL(l_L134X3);
  sim_icache_fetch(2383 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 4723 */
} /* line 4723 */
  sim_icache_fetch(2384 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 4725 */
} /* line 4725 */
  sim_icache_fetch(2385 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 4727 */
} /* line 4727 */
  sim_icache_fetch(2386 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 4729 */
} /* line 4729 */
  sim_icache_fetch(2387 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4200); /* line 4731 */
} /* line 4731 */
  sim_icache_fetch(2389 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_3); /* line 4734 */
} /* line 4734 */
  sim_icache_fetch(2391 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L135X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L135X3;
} /* line 4736 */
l_L131X3: ;/* line 4739 */
LABEL(l_L131X3);
  sim_icache_fetch(2392 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 2); /* line 4740 */
} /* line 4740 */
  sim_icache_fetch(2393 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_22, reg_r0_22, (unsigned int) 1); /* line 4742 */
} /* line 4742 */
  sim_icache_fetch(2394 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_19, (unsigned int) 2); /* line 4744 */
} /* line 4744 */
  sim_icache_fetch(2395 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_20, (unsigned int) 1); /* line 4746 */
} /* line 4746 */
  sim_icache_fetch(2396 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_18); /* line 4748 */
} /* line 4748 */
  sim_icache_fetch(2397 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_21); /* line 4751 */
} /* line 4751 */
  sim_icache_fetch(2398 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L126X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L126X3;
} /* line 4753 */
l_L132X3: ;/* line 4756 */
LABEL(l_L132X3);
  sim_icache_fetch(2399 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 4757 */
} /* line 4757 */
  sim_icache_fetch(2400 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SXTH(reg_r0_5, reg_r0_14); /* line 4759 */
} /* line 4759 */
  sim_icache_fetch(2401 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_5, reg_r0_15); /* line 4761 */
} /* line 4761 */
  sim_icache_fetch(2402 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_15, reg_r0_15, (unsigned int) 7); /* line 4763 */
} /* line 4763 */
  sim_icache_fetch(2403 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 14); /* line 4765 */
} /* line 4765 */
  sim_icache_fetch(2404 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_12, reg_r0_15); /* line 4767 */
} /* line 4767 */
  sim_icache_fetch(2405 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_12, (unsigned int) 25); /* line 4769 */
} /* line 4769 */
  sim_icache_fetch(2406 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_3); /* line 4772 */
} /* line 4772 */
  sim_icache_fetch(2407 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L133X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L133X3;
} /* line 4774 */
l_L127X3: ;/* line 4777 */
LABEL(l_L127X3);
  sim_icache_fetch(2408 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_simd);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 4779 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 298: goto l_L120X3;
    case 299: goto l_L122X3;
    case 300: goto l_L123X3;
    case 301: goto l_L124X3;
    case 302: goto l_L125X3;
    case 303: goto l_L121X3;
    case 304: goto l_L126X3;
    case 305: goto l_L128X3;
    case 306: goto l_L129X3;
    case 307: goto l_L130X3;
    case 308: goto l_L133X3;
    case 309: goto l_L135X3;
    case 310: goto l_L134X3;
    case 311: goto l_L131X3;
    case 312: goto l_L132X3;
    case 313: goto l_L127X3;
    case 314:
      reg_l0_0 = t_client_rpc;
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"deriche.s", 2416, 0, 0, 0, 2};


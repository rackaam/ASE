/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/matthias/vex-3.43 -I../include/ -ms -mas_g -mas_t -O2 -fmm=./vliw2.mm -DVEX -o edge_detect -lvexsimd" */

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
unsigned int at[1575000];
unsigned int by2[1500];
unsigned int by1[1500];
unsigned int ay2[1050];
unsigned int ay1[1050];
unsigned int s_at[787500];
unsigned int s_by2[750];
unsigned int s_by1[750];
unsigned int s_ay2[525];
unsigned int s_ay1[525];
unsigned int t[1575000];
unsigned int y2[1575000];
unsigned int y1[1575000];

/*********************************
            ENTRY SYMBOLS
*********************************/

extern  deriche_float( unsigned int, unsigned int );
extern  deriche_simd( unsigned int, unsigned int );
extern  deriche_short( unsigned int, unsigned int );
extern  deriche_array( unsigned int, unsigned int );
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
extern unsigned int reg_r0_28;
extern unsigned int reg_r0_29;
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

  sim_icache_fetch(0 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_1, reg_r0_1, (unsigned int) -192); /* line 19 */
   SUB(reg_r0_6, 0, reg_r0_3); /* line 20 */
} /* line 20 */
  sim_icache_fetch(2 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_6); /* line 22 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 23 */
} /* line 23 */
  sim_icache_fetch(4 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, (unsigned int) in); /* line 25 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 140),0,4), reg_r0_57); /* line 26 */
} /* line 26 */
  sim_icache_fetch(7 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 144),0,4), reg_r0_58); /* line 28 */
   MOV(reg_r0_6, reg_r0_4); /* line 29 */
} /* line 29 */
  sim_icache_fetch(9 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) y1); /* line 31 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 148),0,4), reg_r0_59); /* line 32 */
} /* line 32 */
  sim_icache_fetch(12 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 152),0,4), reg_r0_60); /* line 34 */
} /* line 34 */
  sim_icache_fetch(13 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 156),0,4), reg_r0_61); /* line 36 */
} /* line 36 */
  sim_icache_fetch(14 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 160),0,4), reg_r0_62); /* line 38 */
} /* line 38 */
  sim_icache_fetch(15 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 164),0,4), reg_r0_63); /* line 40 */
} /* line 40 */
  sim_icache_fetch(16 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 128),0,4), reg_r0_3); /* line 42 */
} /* line 42 */
  sim_icache_fetch(17 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_6); /* line 44 */
} /* line 44 */
l_L0X3: ;/* line 47 */
LABEL(l_L0X3);
  sim_icache_fetch(18 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 48 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 96),0,4), reg_r0_3); /* line 49 */
} /* line 49 */
  sim_icache_fetch(20 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, 0, reg_r0_3); /* line 51 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 100),0,4), reg_r0_4); /* line 52 */
} /* line 52 */
  sim_icache_fetch(22 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 104),0,4), reg_r0_5); /* line 54 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 55 */
  sim_icache_fetch(24 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, reg_r0_3); /* line 57 */
   MOV(reg_r0_62, reg_r0_4); /* line 58 */
} /* line 58 */
  sim_icache_fetch(26 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, 0); /* line 60 */
   MOV(reg_r0_61, reg_r0_5); /* line 61 */
} /* line 61 */
  sim_icache_fetch(28 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_59, 0); /* line 63 */
   MOV(reg_r0_58, 0); /* line 64 */
} /* line 64 */
  sim_icache_fetch(30 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, reg_r0_2); /* line 66 */
} /* line 66 */
l_L2X3: ;/* line 69 */
LABEL(l_L2X3);
  sim_icache_fetch(31 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_57, 0); /* line 70 */
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 71 */
} /* line 71 */
  sim_icache_fetch(34 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_58); /* line 73 */
} /* line 73 */
  sim_icache_fetch(35 + t_thisfile.offset, 1);
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
} /* line 75 */
		 /* line 76 */
  sim_icache_fetch(36 + t_thisfile.offset, 2);
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
} /* line 78 */
l_lr_3: ;/* line 78 */
LABEL(l_lr_3);
  sim_icache_fetch(38 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_58, reg_r0_59); /* line 80 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_3); /* line 81 */
} /* line 81 */
  sim_icache_fetch(40 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 83 */
   MOV(reg_r0_3, reg_r0_59); /* line 84 */
} /* line 84 */
		 /* line 85 */
  sim_icache_fetch(43 + t_thisfile.offset, 2);
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
} /* line 87 */
l_lr_5: ;/* line 87 */
LABEL(l_lr_5);
  sim_icache_fetch(45 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1038202178); /* line 89 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_3); /* line 90 */
} /* line 90 */
		 /* line 91 */
  sim_icache_fetch(48 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_60); /* line 94 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 94 */
l_lr_7: ;/* line 94 */
LABEL(l_lr_7);
  sim_icache_fetch(51 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 48),0,4), reg_r0_3); /* line 96 */
} /* line 96 */
  sim_icache_fetch(52 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_59, mem_trace_ld(reg_r0_61,0,1)); /* line 98 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 99 */
   ADD_CYCLES(2);
} /* line 99 */
		 /* line 100 */
  sim_icache_fetch(54 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 103 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_ilfloat);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _r_ilfloat;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 103 */
l_lr_9: ;/* line 103 */
LABEL(l_lr_9);
		 /* line 104 */
  sim_icache_fetch(57 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) -1103022629); /* line 107 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 107 */
l_lr_11: ;/* line 107 */
LABEL(l_lr_11);
  sim_icache_fetch(61 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 52),0,4), reg_r0_3); /* line 109 */
} /* line 109 */
  sim_icache_fetch(62 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 111 */
} /* line 111 */
  sim_icache_fetch(63 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 113 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 114 */
   ADD_CYCLES(1);
} /* line 114 */
		 /* line 115 */
  sim_icache_fetch(65 + t_thisfile.offset, 2);
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
} /* line 117 */
l_lr_13: ;/* line 117 */
LABEL(l_lr_13);
  sim_icache_fetch(67 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 119 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 120 */
   ADD_CYCLES(1);
} /* line 120 */
		 /* line 121 */
  sim_icache_fetch(69 + t_thisfile.offset, 2);
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
} /* line 123 */
l_lr_15: ;/* line 123 */
LABEL(l_lr_15);
  sim_icache_fetch(71 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 125 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 126 */
   ADD_CYCLES(1);
} /* line 126 */
		 /* line 127 */
  sim_icache_fetch(73 + t_thisfile.offset, 2);
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
} /* line 129 */
l_lr_17: ;/* line 129 */
LABEL(l_lr_17);
  sim_icache_fetch(75 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 56),0,4), reg_r0_3); /* line 131 */
} /* line 131 */
  sim_icache_fetch(76 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_62,0,4), reg_r0_3); /* line 133 */
   MOV(reg_r0_3, reg_r0_59); /* line 134 */
} /* line 134 */
		 /* line 135 */
  sim_icache_fetch(78 + t_thisfile.offset, 2);
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
} /* line 137 */
l_lr_19: ;/* line 137 */
LABEL(l_lr_19);
  sim_icache_fetch(80 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_62, reg_r0_62, (unsigned int) 4); /* line 139 */
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 1); /* line 140 */
} /* line 140 */
  sim_icache_fetch(82 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 142 */
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 143 */
} /* line 143 */
  sim_icache_fetch(84 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, reg_r0_3); /* line 145 */
} /* line 145 */
  sim_icache_fetch(85 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L2X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L2X3;
} /* line 147 */
l_L3X3: ;/* line 150 */
LABEL(l_L3X3);
  sim_icache_fetch(86 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_63, (unsigned int) 1); /* line 151 */
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 104),0,4)); /* line 152 */
} /* line 152 */
  sim_icache_fetch(88 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 100),0,4)); /* line 154 */
} /* line 154 */
  sim_icache_fetch(89 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 156 */
} /* line 156 */
  sim_icache_fetch(90 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 1050); /* line 158 */
} /* line 158 */
  sim_icache_fetch(92 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 4200); /* line 160 */
   GOTO(l_L0X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L0X3;
} /* line 161 */
l_L1X3: ;/* line 164 */
LABEL(l_L1X3);
  sim_icache_fetch(95 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, (unsigned int) y2); /* line 165 */
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 166 */
} /* line 166 */
  sim_icache_fetch(98 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) in); /* line 168 */
   LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 169 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 170 */
   ADD_CYCLES(1);
} /* line 170 */
  sim_icache_fetch(102 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, 0, reg_r0_3); /* line 172 */
} /* line 172 */
  sim_icache_fetch(103 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_7, (unsigned int) -1); /* line 174 */
   MOV(reg_r0_2, reg_r0_3); /* line 175 */
} /* line 175 */
l_L4X3: ;/* line 178 */
LABEL(l_L4X3);
  sim_icache_fetch(105 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 179 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 108),0,4), reg_r0_2); /* line 180 */
} /* line 180 */
  sim_icache_fetch(107 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_62, reg_r0_4, reg_r0_5); /* line 182 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 112),0,4), reg_r0_4); /* line 183 */
} /* line 183 */
  sim_icache_fetch(109 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 116),0,4), reg_r0_5); /* line 185 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 186 */
  sim_icache_fetch(111 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SH2ADD(reg_r0_63, reg_r0_5, reg_r0_6); /* line 188 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 120),0,4), reg_r0_6); /* line 189 */
} /* line 189 */
  sim_icache_fetch(113 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_61, 0); /* line 191 */
   MOV(reg_r0_60, 0); /* line 192 */
} /* line 192 */
  sim_icache_fetch(115 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_59, 0); /* line 194 */
   MOV(reg_r0_58, 0); /* line 195 */
} /* line 195 */
  sim_icache_fetch(117 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, reg_r0_5); /* line 197 */
} /* line 197 */
l_L6X3: ;/* line 200 */
LABEL(l_L6X3);
  sim_icache_fetch(118 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_57, 0); /* line 201 */
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 202 */
} /* line 202 */
  sim_icache_fetch(121 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_58); /* line 204 */
} /* line 204 */
  sim_icache_fetch(122 + t_thisfile.offset, 1);
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
} /* line 206 */
		 /* line 207 */
  sim_icache_fetch(123 + t_thisfile.offset, 2);
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
} /* line 209 */
l_lr_25: ;/* line 209 */
LABEL(l_lr_25);
  sim_icache_fetch(125 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_58, reg_r0_59); /* line 211 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_3); /* line 212 */
} /* line 212 */
  sim_icache_fetch(127 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 214 */
   MOV(reg_r0_3, reg_r0_59); /* line 215 */
} /* line 215 */
		 /* line 216 */
  sim_icache_fetch(130 + t_thisfile.offset, 2);
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
} /* line 218 */
l_lr_27: ;/* line 218 */
LABEL(l_lr_27);
  sim_icache_fetch(132 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) -1103022629); /* line 220 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_3); /* line 221 */
} /* line 221 */
		 /* line 222 */
  sim_icache_fetch(135 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_60); /* line 225 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 225 */
l_lr_29: ;/* line 225 */
LABEL(l_lr_29);
  sim_icache_fetch(138 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, reg_r0_61); /* line 227 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_3); /* line 228 */
} /* line 228 */
  sim_icache_fetch(140 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) -1103358174); /* line 230 */
   MOV(reg_r0_3, reg_r0_61); /* line 231 */
} /* line 231 */
		 /* line 232 */
  sim_icache_fetch(143 + t_thisfile.offset, 2);
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
} /* line 234 */
l_lr_31: ;/* line 234 */
LABEL(l_lr_31);
  sim_icache_fetch(145 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 236 */
} /* line 236 */
  sim_icache_fetch(146 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 238 */
} /* line 238 */
  sim_icache_fetch(147 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 240 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 241 */
   ADD_CYCLES(1);
} /* line 241 */
		 /* line 242 */
  sim_icache_fetch(149 + t_thisfile.offset, 2);
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
} /* line 244 */
l_lr_33: ;/* line 244 */
LABEL(l_lr_33);
  sim_icache_fetch(151 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 246 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 247 */
   ADD_CYCLES(1);
} /* line 247 */
		 /* line 248 */
  sim_icache_fetch(153 + t_thisfile.offset, 2);
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
} /* line 250 */
l_lr_35: ;/* line 250 */
LABEL(l_lr_35);
  sim_icache_fetch(155 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 252 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 253 */
   ADD_CYCLES(1);
} /* line 253 */
		 /* line 254 */
  sim_icache_fetch(157 + t_thisfile.offset, 2);
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
} /* line 256 */
l_lr_37: ;/* line 256 */
LABEL(l_lr_37);
  sim_icache_fetch(159 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_3); /* line 258 */
} /* line 258 */
  sim_icache_fetch(160 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_2, mem_trace_ld(reg_r0_62,0,1)); /* line 260 */
} /* line 260 */
  sim_icache_fetch(161 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_63,0,4), reg_r0_3); /* line 262 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 263 */
   ADD_CYCLES(1);
} /* line 263 */
		 /* line 264 */
  sim_icache_fetch(163 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_2); /* line 267 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_ufloat);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _r_ufloat;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 267 */
l_lr_39: ;/* line 267 */
LABEL(l_lr_39);
  sim_icache_fetch(166 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_63, reg_r0_63, (unsigned int) -4); /* line 269 */
   ADD(reg_r0_57, reg_r0_57, (unsigned int) -1); /* line 270 */
} /* line 270 */
  sim_icache_fetch(168 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_62, reg_r0_62, (unsigned int) -1); /* line 272 */
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 273 */
} /* line 273 */
  sim_icache_fetch(170 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, reg_r0_3); /* line 275 */
} /* line 275 */
  sim_icache_fetch(171 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L6X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L6X3;
} /* line 277 */
l_L7X3: ;/* line 280 */
LABEL(l_L7X3);
  sim_icache_fetch(172 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 120),0,4)); /* line 281 */
} /* line 281 */
  sim_icache_fetch(173 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 112),0,4)); /* line 283 */
} /* line 283 */
  sim_icache_fetch(174 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 108),0,4)); /* line 285 */
} /* line 285 */
  sim_icache_fetch(175 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 4200); /* line 287 */
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 116),0,4)); /* line 288 */
} /* line 288 */
  sim_icache_fetch(178 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 1050); /* line 290 */
} /* line 290 */
  sim_icache_fetch(180 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 292 */
   GOTO(l_L4X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L4X3;
} /* line 293 */
l_L5X3: ;/* line 296 */
LABEL(l_L5X3);
  sim_icache_fetch(182 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_61, (unsigned int) t); /* line 297 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 298 */
} /* line 298 */
  sim_icache_fetch(185 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_58, (unsigned int) y2); /* line 300 */
   MOV(reg_r0_59, (unsigned int) y1); /* line 301 */
} /* line 301 */
  sim_icache_fetch(189 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 303 */
} /* line 303 */
  sim_icache_fetch(190 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_4); /* line 305 */
} /* line 305 */
  sim_icache_fetch(191 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_4); /* line 307 */
} /* line 307 */
l_L8X3: ;/* line 310 */
LABEL(l_L8X3);
  sim_icache_fetch(192 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 311 */
   SUB(reg_r0_4, 0, reg_r0_3); /* line 312 */
} /* line 312 */
  sim_icache_fetch(194 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, 0); /* line 314 */
   MOV(reg_r0_60, reg_r0_4); /* line 315 */
} /* line 315 */
  sim_icache_fetch(196 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_62, reg_r0_2); /* line 317 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L9X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 318 */
  sim_icache_fetch(198 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, reg_r0_3); /* line 320 */
} /* line 320 */
l_L10X3: ;/* line 323 */
LABEL(l_L10X3);
  sim_icache_fetch(199 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_58); /* line 324 */
   SH2ADD(reg_r0_5, reg_r0_57, reg_r0_59); /* line 325 */
} /* line 325 */
  sim_icache_fetch(201 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_60, 0); /* line 327 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 328 */
} /* line 328 */
  sim_icache_fetch(203 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_5,0,4)); /* line 330 */
} /* line 330 */
  sim_icache_fetch(204 + t_thisfile.offset, 1);
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
} /* line 332 */
		 /* line 333 */
  sim_icache_fetch(205 + t_thisfile.offset, 2);
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
} /* line 335 */
l_lr_45: ;/* line 335 */
LABEL(l_lr_45);
		 /* line 336 */
  sim_icache_fetch(207 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1065353216); /* line 339 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 339 */
l_lr_47: ;/* line 339 */
LABEL(l_lr_47);
  sim_icache_fetch(211 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_61); /* line 341 */
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 342 */
} /* line 342 */
  sim_icache_fetch(213 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_2,0,4), reg_r0_3); /* line 344 */
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 346 */
} /* line 346 */
  sim_icache_fetch(215 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L10X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L10X3;
} /* line 348 */
l_L11X3: ;/* line 351 */
LABEL(l_L11X3);
  sim_icache_fetch(216 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_62, (unsigned int) 1); /* line 352 */
   MOV(reg_r0_5, (unsigned int) 4200); /* line 353 */
} /* line 353 */
  sim_icache_fetch(219 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_59, reg_r0_59, reg_r0_5); /* line 355 */
   ADD(reg_r0_61, reg_r0_61, reg_r0_5); /* line 356 */
} /* line 356 */
  sim_icache_fetch(221 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_58, reg_r0_58, reg_r0_5); /* line 358 */
   MOV(reg_r0_3, reg_r0_63); /* line 360 */
} /* line 360 */
  sim_icache_fetch(223 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L8X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L8X3;
} /* line 362 */
l_L9X3: ;/* line 365 */
LABEL(l_L9X3);
  sim_icache_fetch(224 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_5, 0, reg_r0_3); /* line 366 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 96),0,4), reg_r0_3); /* line 367 */
} /* line 367 */
  sim_icache_fetch(226 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_5); /* line 369 */
   MOV(reg_r0_63, (unsigned int) y1); /* line 370 */
} /* line 370 */
  sim_icache_fetch(229 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_62, (unsigned int) t); /* line 372 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 373 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 374 */
   ADD_CYCLES(1);
} /* line 374 */
  sim_icache_fetch(233 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 375 */
l_L12X3: ;/* line 378 */
LABEL(l_L12X3);
  sim_icache_fetch(234 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 379 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 124),0,4), reg_r0_2); /* line 380 */
} /* line 380 */
  sim_icache_fetch(236 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_4); /* line 382 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 128),0,4), reg_r0_4); /* line 383 */
} /* line 383 */
  sim_icache_fetch(238 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, reg_r0_2); /* line 385 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 386 */
  sim_icache_fetch(240 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, 0); /* line 388 */
   MOV(reg_r0_61, 0); /* line 389 */
} /* line 389 */
  sim_icache_fetch(242 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_59, 0); /* line 391 */
   MOV(reg_r0_58, 0); /* line 392 */
} /* line 392 */
l_L14X3: ;/* line 395 */
LABEL(l_L14X3);
  sim_icache_fetch(244 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_57, 0); /* line 396 */
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 397 */
} /* line 397 */
  sim_icache_fetch(247 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_58); /* line 399 */
} /* line 399 */
  sim_icache_fetch(248 + t_thisfile.offset, 1);
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
} /* line 401 */
		 /* line 402 */
  sim_icache_fetch(249 + t_thisfile.offset, 2);
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
} /* line 404 */
l_lr_53: ;/* line 404 */
LABEL(l_lr_53);
  sim_icache_fetch(251 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_58, reg_r0_59); /* line 406 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 407 */
} /* line 407 */
  sim_icache_fetch(253 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 409 */
   MOV(reg_r0_3, reg_r0_59); /* line 410 */
} /* line 410 */
		 /* line 411 */
  sim_icache_fetch(256 + t_thisfile.offset, 2);
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
} /* line 413 */
l_lr_55: ;/* line 413 */
LABEL(l_lr_55);
  sim_icache_fetch(258 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1038202178); /* line 415 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 64),0,4), reg_r0_3); /* line 416 */
} /* line 416 */
		 /* line 417 */
  sim_icache_fetch(261 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_60); /* line 420 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 420 */
l_lr_57: ;/* line 420 */
LABEL(l_lr_57);
  sim_icache_fetch(264 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SH3ADD(reg_r0_2, reg_r0_61, reg_r0_62); /* line 422 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 68),0,4), reg_r0_3); /* line 423 */
} /* line 423 */
  sim_icache_fetch(266 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_60, mem_trace_ld(reg_r0_2,0,4)); /* line 425 */
   MOV(reg_r0_4, (unsigned int) -1103022629); /* line 426 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 427 */
   ADD_CYCLES(2);
} /* line 427 */
		 /* line 428 */
  sim_icache_fetch(270 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_60); /* line 431 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 431 */
l_lr_59: ;/* line 431 */
LABEL(l_lr_59);
  sim_icache_fetch(273 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 72),0,4), reg_r0_3); /* line 433 */
} /* line 433 */
  sim_icache_fetch(274 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 435 */
} /* line 435 */
  sim_icache_fetch(275 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 64),0,4)); /* line 437 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 438 */
   ADD_CYCLES(1);
} /* line 438 */
		 /* line 439 */
  sim_icache_fetch(277 + t_thisfile.offset, 2);
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
} /* line 441 */
l_lr_61: ;/* line 441 */
LABEL(l_lr_61);
  sim_icache_fetch(279 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 443 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 444 */
   ADD_CYCLES(1);
} /* line 444 */
		 /* line 445 */
  sim_icache_fetch(281 + t_thisfile.offset, 2);
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
} /* line 447 */
l_lr_63: ;/* line 447 */
LABEL(l_lr_63);
  sim_icache_fetch(283 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 72),0,4)); /* line 449 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 450 */
   ADD_CYCLES(1);
} /* line 450 */
		 /* line 451 */
  sim_icache_fetch(285 + t_thisfile.offset, 2);
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
} /* line 453 */
l_lr_65: ;/* line 453 */
LABEL(l_lr_65);
  sim_icache_fetch(287 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SH3ADD(reg_r0_2, reg_r0_61, reg_r0_63); /* line 455 */
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 525); /* line 456 */
} /* line 456 */
  sim_icache_fetch(290 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 458 */
   MOV(reg_r0_59, reg_r0_3); /* line 459 */
} /* line 459 */
  sim_icache_fetch(292 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_2,0,4), reg_r0_3); /* line 461 */
   GOTO(l_L14X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L14X3;
} /* line 462 */
l_L15X3: ;/* line 465 */
LABEL(l_L15X3);
  sim_icache_fetch(294 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_62, reg_r0_62, (unsigned int) 4); /* line 466 */
   ADD(reg_r0_63, reg_r0_63, (unsigned int) 4); /* line 467 */
} /* line 467 */
  sim_icache_fetch(296 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 124),0,4)); /* line 469 */
} /* line 469 */
  sim_icache_fetch(297 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 471 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 472 */
   ADD_CYCLES(1);
} /* line 472 */
  sim_icache_fetch(299 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 474 */
   GOTO(l_L12X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L12X3;
} /* line 475 */
l_L13X3: ;/* line 478 */
LABEL(l_L13X3);
  sim_icache_fetch(301 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) t); /* line 479 */
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 480 */
} /* line 480 */
  sim_icache_fetch(304 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_63, (unsigned int) y2); /* line 482 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 76),0,4), reg_r0_4); /* line 483 */
} /* line 483 */
  sim_icache_fetch(307 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 485 */
} /* line 485 */
  sim_icache_fetch(308 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, 0, reg_r0_3); /* line 487 */
} /* line 487 */
  sim_icache_fetch(309 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_3); /* line 489 */
} /* line 489 */
  sim_icache_fetch(310 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_4, (unsigned int) -1); /* line 491 */
} /* line 491 */
l_L16X3: ;/* line 494 */
LABEL(l_L16X3);
  sim_icache_fetch(311 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 495 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 132),0,4), reg_r0_2); /* line 496 */
} /* line 496 */
  sim_icache_fetch(313 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULLU(reg_r0_62, reg_r0_5, (unsigned int) 525); /* line 498 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 136),0,4), reg_r0_5); /* line 499 */
} /* line 499 */
  sim_icache_fetch(316 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_61, 0); /* line 501 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 502 */
  sim_icache_fetch(318 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, 0); /* line 504 */
   MOV(reg_r0_59, 0); /* line 505 */
} /* line 505 */
  sim_icache_fetch(320 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_58, 0); /* line 507 */
   MOV(reg_r0_57, reg_r0_5); /* line 508 */
} /* line 508 */
l_L18X3: ;/* line 511 */
LABEL(l_L18X3);
  sim_icache_fetch(322 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_57, 0); /* line 512 */
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 513 */
} /* line 513 */
  sim_icache_fetch(325 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_58); /* line 515 */
} /* line 515 */
  sim_icache_fetch(326 + t_thisfile.offset, 1);
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
} /* line 517 */
		 /* line 518 */
  sim_icache_fetch(327 + t_thisfile.offset, 2);
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
} /* line 520 */
l_lr_71: ;/* line 520 */
LABEL(l_lr_71);
  sim_icache_fetch(329 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_58, reg_r0_59); /* line 522 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 80),0,4), reg_r0_3); /* line 523 */
} /* line 523 */
  sim_icache_fetch(331 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 525 */
   MOV(reg_r0_3, reg_r0_59); /* line 526 */
} /* line 526 */
		 /* line 527 */
  sim_icache_fetch(334 + t_thisfile.offset, 2);
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
} /* line 529 */
l_lr_73: ;/* line 529 */
LABEL(l_lr_73);
  sim_icache_fetch(336 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1038770187); /* line 531 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 84),0,4), reg_r0_3); /* line 532 */
} /* line 532 */
		 /* line 533 */
  sim_icache_fetch(339 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_60); /* line 536 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 536 */
l_lr_75: ;/* line 536 */
LABEL(l_lr_75);
  sim_icache_fetch(342 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, reg_r0_61); /* line 538 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 88),0,4), reg_r0_3); /* line 539 */
} /* line 539 */
  sim_icache_fetch(344 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) -1103358174); /* line 541 */
   MOV(reg_r0_3, reg_r0_61); /* line 542 */
} /* line 542 */
		 /* line 543 */
  sim_icache_fetch(347 + t_thisfile.offset, 2);
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
} /* line 545 */
l_lr_77: ;/* line 545 */
LABEL(l_lr_77);
  sim_icache_fetch(349 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 92),0,4), reg_r0_3); /* line 547 */
} /* line 547 */
  sim_icache_fetch(350 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 80),0,4)); /* line 549 */
} /* line 549 */
  sim_icache_fetch(351 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 84),0,4)); /* line 551 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 552 */
   ADD_CYCLES(1);
} /* line 552 */
		 /* line 553 */
  sim_icache_fetch(353 + t_thisfile.offset, 2);
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
} /* line 555 */
l_lr_79: ;/* line 555 */
LABEL(l_lr_79);
  sim_icache_fetch(355 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 88),0,4)); /* line 557 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 558 */
   ADD_CYCLES(1);
} /* line 558 */
		 /* line 559 */
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
} /* line 561 */
l_lr_81: ;/* line 561 */
LABEL(l_lr_81);
  sim_icache_fetch(359 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 92),0,4)); /* line 563 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 564 */
   ADD_CYCLES(1);
} /* line 564 */
		 /* line 565 */
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
} /* line 567 */
l_lr_83: ;/* line 567 */
LABEL(l_lr_83);
  sim_icache_fetch(363 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SH3ADD(reg_r0_4, reg_r0_62, reg_r0_63); /* line 569 */
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 76),0,4)); /* line 570 */
} /* line 570 */
  sim_icache_fetch(365 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) -1); /* line 572 */
   MOV(reg_r0_59, reg_r0_3); /* line 573 */
} /* line 573 */
  sim_icache_fetch(367 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_4,0,4), reg_r0_3); /* line 575 */
} /* line 575 */
  sim_icache_fetch(368 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SH3ADD(reg_r0_3, reg_r0_62, reg_r0_2); /* line 577 */
   ADD(reg_r0_62, reg_r0_62, (unsigned int) -525); /* line 578 */
} /* line 578 */
  sim_icache_fetch(371 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld(reg_r0_3,0,4)); /* line 580 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 581 */
   ADD_CYCLES(1);
} /* line 581 */
  sim_icache_fetch(373 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L18X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L18X3;
} /* line 583 */
l_L19X3: ;/* line 586 */
LABEL(l_L19X3);
  sim_icache_fetch(374 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_63, reg_r0_63, (unsigned int) 4); /* line 587 */
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 76),0,4)); /* line 588 */
} /* line 588 */
  sim_icache_fetch(376 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 132),0,4)); /* line 590 */
} /* line 590 */
  sim_icache_fetch(377 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 136),0,4)); /* line 592 */
} /* line 592 */
  sim_icache_fetch(378 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, (unsigned int) 4); /* line 594 */
} /* line 594 */
  sim_icache_fetch(379 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 596 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 76),0,4), reg_r0_3); /* line 598 */
} /* line 598 */
  sim_icache_fetch(381 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L16X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L16X3;
} /* line 600 */
l_L17X3: ;/* line 603 */
LABEL(l_L17X3);
  sim_icache_fetch(382 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_61, (unsigned int) out); /* line 604 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 605 */
} /* line 605 */
  sim_icache_fetch(385 + t_thisfile.offset, 5);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_58, (unsigned int) y2); /* line 607 */
   MOV(reg_r0_59, (unsigned int) y1); /* line 608 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 609 */
   ADD_CYCLES(1);
} /* line 609 */
  sim_icache_fetch(390 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_4); /* line 611 */
} /* line 611 */
  sim_icache_fetch(391 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_4); /* line 613 */
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 614 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 615 */
   ADD_CYCLES(1);
} /* line 615 */
  sim_icache_fetch(394 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 616 */
l_L20X3: ;/* line 619 */
LABEL(l_L20X3);
  sim_icache_fetch(395 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 620 */
   SUB(reg_r0_4, 0, reg_r0_3); /* line 621 */
} /* line 621 */
  sim_icache_fetch(397 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, 0); /* line 623 */
   MOV(reg_r0_60, reg_r0_4); /* line 624 */
} /* line 624 */
  sim_icache_fetch(399 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_62, reg_r0_2); /* line 626 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L21X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 627 */
  sim_icache_fetch(401 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, reg_r0_3); /* line 629 */
} /* line 629 */
l_L22X3: ;/* line 632 */
LABEL(l_L22X3);
  sim_icache_fetch(402 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_58); /* line 633 */
   SH2ADD(reg_r0_5, reg_r0_57, reg_r0_59); /* line 634 */
} /* line 634 */
  sim_icache_fetch(404 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_60, 0); /* line 636 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 637 */
} /* line 637 */
  sim_icache_fetch(406 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_5,0,4)); /* line 639 */
} /* line 639 */
  sim_icache_fetch(407 + t_thisfile.offset, 1);
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
} /* line 641 */
		 /* line 642 */
  sim_icache_fetch(408 + t_thisfile.offset, 2);
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
} /* line 644 */
l_lr_89: ;/* line 644 */
LABEL(l_lr_89);
		 /* line 645 */
  sim_icache_fetch(410 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1065353216); /* line 648 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 648 */
l_lr_91: ;/* line 648 */
LABEL(l_lr_91);
		 /* line 649 */
  sim_icache_fetch(414 + t_thisfile.offset, 2);
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
} /* line 651 */
l_lr_93: ;/* line 651 */
LABEL(l_lr_93);
  sim_icache_fetch(416 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_4, reg_r0_3); /* line 653 */
   ADD(reg_r0_2, reg_r0_57, reg_r0_61); /* line 654 */
} /* line 654 */
  sim_icache_fetch(418 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_0, reg_r0_4, (unsigned int) 25); /* line 656 */
   ADD(reg_r0_5, reg_r0_57, reg_r0_61); /* line 657 */
} /* line 657 */
  sim_icache_fetch(420 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 659 */
} /* line 659 */
  sim_icache_fetch(421 + t_thisfile.offset, 1);
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
} /* line 661 */
  sim_icache_fetch(422 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 663 */
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 664 */
} /* line 664 */
  sim_icache_fetch(424 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_5,0,1), 0); /* line 666 */
   GOTO(l_L22X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L22X3;
} /* line 667 */
l_L24X3: ;/* line 670 */
LABEL(l_L24X3);
  sim_icache_fetch(426 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_57, reg_r0_61); /* line 671 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 672 */
} /* line 672 */
  sim_icache_fetch(428 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 674 */
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 675 */
} /* line 675 */
  sim_icache_fetch(430 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 677 */
   GOTO(l_L22X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L22X3;
} /* line 678 */
l_L23X3: ;/* line 681 */
LABEL(l_L23X3);
  sim_icache_fetch(432 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_59, reg_r0_59, (unsigned int) 4200); /* line 682 */
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 1050); /* line 683 */
} /* line 683 */
  sim_icache_fetch(436 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_62, (unsigned int) 1); /* line 685 */
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 4200); /* line 686 */
} /* line 686 */
  sim_icache_fetch(439 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_63); /* line 688 */
   GOTO(l_L20X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L20X3;
} /* line 689 */
l_L21X3: ;/* line 692 */
LABEL(l_L21X3);
  sim_icache_fetch(441 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 693 */
} /* line 693 */
  sim_icache_fetch(442 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 164),0,4)); /* line 695 */
} /* line 695 */
  sim_icache_fetch(443 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 160),0,4)); /* line 697 */
} /* line 697 */
  sim_icache_fetch(444 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 156),0,4)); /* line 699 */
} /* line 699 */
  sim_icache_fetch(445 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 152),0,4)); /* line 701 */
} /* line 701 */
  sim_icache_fetch(446 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 148),0,4)); /* line 703 */
} /* line 703 */
  sim_icache_fetch(447 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 144),0,4)); /* line 705 */
} /* line 705 */
  sim_icache_fetch(448 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 140),0,4)); /* line 707 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 708 */
   ADD_CYCLES(1);
} /* line 708 */
  sim_icache_fetch(450 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_float);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 192; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 711 */
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
  reg_l0_0 = (222 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(451 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 731 */
} /* line 731 */
  sim_icache_fetch(452 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, reg_r0_2); /* line 733 */
   MOV(reg_r0_2, (unsigned int) -23); /* line 734 */
} /* line 734 */
  sim_icache_fetch(454 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(6,reg_r0_2,(unsigned int) 14);
   }
 /* line 736 */
   MOV(reg_r0_6, (unsigned int) -24); /* line 737 */
} /* line 737 */
  sim_icache_fetch(456 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_27 = (unsigned int) sim_asm_op1(6,reg_r0_6,(unsigned int) 14);
   }
 /* line 739 */
   {
    reg_r0_7 = (unsigned int) sim_asm_op1(6,reg_r0_2,(unsigned int) -24);
   }
 /* line 740 */
} /* line 740 */
  sim_icache_fetch(458 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_26, (unsigned int) in); /* line 742 */
   MOV(reg_r0_2, (unsigned int) 107); /* line 743 */
} /* line 743 */
  sim_icache_fetch(461 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_25, (unsigned int) s_at); /* line 745 */
   MOV(reg_r0_14, reg_r0_4); /* line 746 */
} /* line 746 */
  sim_icache_fetch(464 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_4 = (unsigned int) sim_asm_op1(6,reg_r0_2,(unsigned int) -77);
   }
 /* line 748 */
   ADD(reg_r0_13, reg_r0_14, (unsigned int) -1); /* line 749 */
} /* line 749 */
  sim_icache_fetch(466 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_12, ((unsigned int) in + (unsigned int) -2)); /* line 751 */
   MOV(reg_r0_28, reg_r0_3); /* line 752 */
} /* line 752 */
l_L25X3: ;/* line 755 */
LABEL(l_L25X3);
  sim_icache_fetch(469 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_11, 0); /* line 756 */
   ADD(reg_r0_10, reg_r0_12, reg_r0_13); /* line 757 */
} /* line 757 */
  sim_icache_fetch(471 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 759 */
   SH1ADD(reg_r0_9, reg_r0_14, ((unsigned int) s_ay2 + (unsigned int) -6)); /* line 760 */
} /* line 760 */
  sim_icache_fetch(474 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 762 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 763 */
  sim_icache_fetch(476 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 765 */
   MOV(reg_r0_6, 0); /* line 766 */
} /* line 766 */
  sim_icache_fetch(478 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_23, 0); /* line 768 */
   MOV(reg_r0_22, 0); /* line 769 */
} /* line 769 */
  sim_icache_fetch(480 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_24, 0); /* line 771 */
   MOV(reg_r0_8, reg_r0_13); /* line 772 */
} /* line 772 */
  sim_icache_fetch(482 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_18, reg_r0_11); /* line 774 */
   MOV(reg_r0_19, reg_r0_12); /* line 775 */
} /* line 775 */
  sim_icache_fetch(484 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_20, reg_r0_13); /* line 777 */
   MOV(reg_r0_21, reg_r0_14); /* line 778 */
} /* line 778 */
l_L27X3: ;/* line 781 */
LABEL(l_L27X3);
  sim_icache_fetch(486 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 782 */
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 7); /* line 783 */
} /* line 783 */
  sim_icache_fetch(488 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_6 = (unsigned int) sim_asm_op1(6,reg_r0_5,reg_r0_6);
   }
 /* line 785 */
   {
    reg_r0_3 = (unsigned int) sim_asm_op1(6,reg_r0_2,reg_r0_3);
   }
 /* line 786 */
} /* line 786 */
  sim_icache_fetch(490 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_6 = (unsigned int) sim_asm_op1(65,reg_r0_7,reg_r0_6);
   }
 /* line 788 */
   {
    reg_r0_3 = (unsigned int) sim_asm_op1(65,reg_r0_4,reg_r0_3);
   }
 /* line 789 */
} /* line 789 */
  sim_icache_fetch(492 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_8, 0); /* line 791 */
   LDBUs(reg_r0_11, mem_trace_ld((reg_r0_10 + (unsigned int) 2),0,1)); /* line 792 */
} /* line 792 */
  sim_icache_fetch(494 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_6 = (unsigned int) sim_asm_op1(1,reg_r0_6,reg_r0_3);
   }
 /* line 794 */
   CMPGE(reg_b0_1, reg_r0_8, (unsigned int) 1); /* line 795 */
} /* line 795 */
  sim_icache_fetch(496 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_12 = (unsigned int) sim_asm_op1(7,reg_r0_6,0);
   }
 /* line 797 */
   {
    reg_r0_6 = (unsigned int) sim_asm_op1(7,reg_r0_6,(unsigned int) 1);
   }
 /* line 798 */
} /* line 798 */
  sim_icache_fetch(498 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_6); /* line 800 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 801 */
  sim_icache_fetch(500 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_13, reg_r0_12); /* line 803 */
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(6,reg_r0_11,reg_r0_5);
   }
 /* line 804 */
} /* line 804 */
  sim_icache_fetch(502 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 7); /* line 806 */
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(65,reg_r0_7,reg_r0_5);
   }
 /* line 807 */
} /* line 807 */
  sim_icache_fetch(504 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_2 = (unsigned int) sim_asm_op1(6,reg_r0_13,reg_r0_2);
   }
 /* line 809 */
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_10 + (unsigned int) 1),0,1)); /* line 810 */
} /* line 810 */
  sim_icache_fetch(506 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_2 = (unsigned int) sim_asm_op1(65,reg_r0_4,reg_r0_2);
   }
 /* line 812 */
   CMPGE(reg_b0_0, reg_r0_8, (unsigned int) 2); /* line 813 */
} /* line 813 */
  sim_icache_fetch(508 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_15, mem_trace_ld(reg_r0_10,0,1)); /* line 815 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -3); /* line 816 */
} /* line 816 */
  sim_icache_fetch(510 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(1,reg_r0_5,reg_r0_2);
   }
 /* line 818 */
   {
    reg_r0_11 = (unsigned int) sim_asm_op1(6,reg_r0_14,reg_r0_11);
   }
 /* line 819 */
} /* line 819 */
  sim_icache_fetch(512 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_16 = (unsigned int) sim_asm_op1(7,reg_r0_5,0);
   }
 /* line 821 */
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(7,reg_r0_5,(unsigned int) 1);
   }
 /* line 822 */
} /* line 822 */
  sim_icache_fetch(514 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_16, reg_r0_16, reg_r0_5); /* line 824 */
   {
    reg_r0_11 = (unsigned int) sim_asm_op1(65,reg_r0_7,reg_r0_11);
   }
 /* line 825 */
} /* line 825 */
  sim_icache_fetch(516 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_17, reg_r0_16); /* line 827 */
   MOV(reg_r0_6, reg_r0_14); /* line 828 */
} /* line 828 */
  sim_icache_fetch(518 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_17); /* line 830 */
   SHR(reg_r0_14, reg_r0_17, (unsigned int) 7); /* line 831 */
} /* line 831 */
  sim_icache_fetch(520 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_14 = (unsigned int) sim_asm_op1(6,reg_r0_14,reg_r0_13);
   }
 /* line 833 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) -3); /* line 834 */
} /* line 834 */
  sim_icache_fetch(522 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_14 = (unsigned int) sim_asm_op1(65,reg_r0_4,reg_r0_14);
   }
 /* line 836 */
   MOV(reg_r0_5, reg_r0_15); /* line 837 */
} /* line 837 */
  sim_icache_fetch(524 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_9 + (unsigned int) 4),0,2), reg_r0_12); /* line 839 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 840 */
  sim_icache_fetch(526 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_9 + (unsigned int) 2),0,2), reg_r0_16); /* line 842 */
   {
    reg_r0_11 = (unsigned int) sim_asm_op1(1,reg_r0_11,reg_r0_14);
   }
 /* line 843 */
} /* line 843 */
  sim_icache_fetch(528 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_12 = (unsigned int) sim_asm_op1(7,reg_r0_11,0);
   }
 /* line 845 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 846 */
  sim_icache_fetch(530 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   {
    reg_r0_11 = (unsigned int) sim_asm_op1(7,reg_r0_11,(unsigned int) 1);
   }
 /* line 848 */
} /* line 848 */
  sim_icache_fetch(531 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_11); /* line 850 */
} /* line 850 */
  sim_icache_fetch(532 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_2, reg_r0_12); /* line 852 */
   STH(mem_trace_st(reg_r0_9,0,2), reg_r0_12); /* line 853 */
} /* line 853 */
  sim_icache_fetch(534 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -6); /* line 855 */
   GOTO(l_L27X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L27X3;
} /* line 856 */
l_L28X3: ;/* line 859 */
LABEL(l_L28X3);
  sim_icache_fetch(536 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_21); /* line 860 */
   MOV(reg_r0_12, reg_r0_25); /* line 861 */
} /* line 861 */
  sim_icache_fetch(538 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, reg_r0_3); /* line 863 */
   MOV(reg_r0_10, (unsigned int) s_ay2); /* line 864 */
} /* line 864 */
  sim_icache_fetch(541 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_13, (unsigned int) s_ay1); /* line 866 */
   MOV(reg_r0_2, reg_r0_26); /* line 867 */
} /* line 867 */
  sim_icache_fetch(544 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_22); /* line 869 */
   MOV(reg_r0_8, reg_r0_23); /* line 870 */
} /* line 870 */
  sim_icache_fetch(546 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_22, reg_r0_18); /* line 872 */
   MOV(reg_r0_9, reg_r0_24); /* line 873 */
} /* line 873 */
  sim_icache_fetch(548 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_23, reg_r0_21); /* line 875 */
} /* line 875 */
  sim_icache_fetch(549 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, reg_r0_19); /* line 877 */
   MOV(reg_r0_6, reg_r0_27); /* line 878 */
} /* line 878 */
l_L29X3: ;/* line 881 */
LABEL(l_L29X3);
  sim_icache_fetch(551 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 882 */
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 7); /* line 883 */
} /* line 883 */
  sim_icache_fetch(553 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 7); /* line 885 */
   LDHs(reg_r0_14, mem_trace_ld(reg_r0_10,0,2)); /* line 886 */
} /* line 886 */
  sim_icache_fetch(555 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_11, (unsigned int) 1); /* line 888 */
   {
    reg_r0_9 = (unsigned int) sim_asm_op1(6,reg_r0_8,reg_r0_9);
   }
 /* line 889 */
} /* line 889 */
  sim_icache_fetch(557 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(6,reg_r0_3,reg_r0_5);
   }
 /* line 891 */
   {
    reg_r0_9 = (unsigned int) sim_asm_op1(65,reg_r0_4,reg_r0_9);
   }
 /* line 892 */
} /* line 892 */
  sim_icache_fetch(559 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(65,reg_r0_6,reg_r0_5);
   }
 /* line 894 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L30X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 895 */
  sim_icache_fetch(561 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_11, 0); /* line 897 */
   LDBUs(reg_r0_15, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 898 */
} /* line 898 */
  sim_icache_fetch(563 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(1,reg_r0_5,reg_r0_9);
   }
 /* line 900 */
   LDHs(reg_r0_16, mem_trace_ld((reg_r0_10 + (unsigned int) 2),0,2)); /* line 901 */
} /* line 901 */
  sim_icache_fetch(565 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_17 = (unsigned int) sim_asm_op1(7,reg_r0_5,0);
   }
 /* line 903 */
   {
    reg_r0_5 = (unsigned int) sim_asm_op1(7,reg_r0_5,(unsigned int) 1);
   }
 /* line 904 */
} /* line 904 */
  sim_icache_fetch(567 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_17, reg_r0_17, reg_r0_5); /* line 906 */
   {
    reg_r0_3 = (unsigned int) sim_asm_op1(6,reg_r0_15,reg_r0_3);
   }
 /* line 907 */
} /* line 907 */
  sim_icache_fetch(569 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_18, reg_r0_17); /* line 909 */
   {
    reg_r0_3 = (unsigned int) sim_asm_op1(65,reg_r0_6,reg_r0_3);
   }
 /* line 910 */
} /* line 910 */
  sim_icache_fetch(571 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_18, reg_r0_14); /* line 912 */
   SHR(reg_r0_19, reg_r0_18, (unsigned int) 7); /* line 913 */
} /* line 913 */
  sim_icache_fetch(573 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 915 */
   {
    reg_r0_19 = (unsigned int) sim_asm_op1(6,reg_r0_19,reg_r0_8);
   }
 /* line 916 */
} /* line 916 */
  sim_icache_fetch(575 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 918 */
   {
    reg_r0_19 = (unsigned int) sim_asm_op1(65,reg_r0_4,reg_r0_19);
   }
 /* line 919 */
} /* line 919 */
  sim_icache_fetch(577 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_18); /* line 921 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 2); /* line 922 */
} /* line 922 */
  sim_icache_fetch(579 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_3 = (unsigned int) sim_asm_op1(1,reg_r0_3,reg_r0_19);
   }
 /* line 924 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 925 */
} /* line 925 */
  sim_icache_fetch(581 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   {
    reg_r0_18 = (unsigned int) sim_asm_op1(7,reg_r0_3,0);
   }
 /* line 927 */
   {
    reg_r0_3 = (unsigned int) sim_asm_op1(7,reg_r0_3,(unsigned int) 1);
   }
 /* line 928 */
} /* line 928 */
  sim_icache_fetch(583 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_18, reg_r0_18, reg_r0_3); /* line 930 */
   ADD(reg_r0_11, reg_r0_11, (unsigned int) 2); /* line 931 */
} /* line 931 */
  sim_icache_fetch(585 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_8, reg_r0_18); /* line 933 */
   MOV(reg_r0_5, reg_r0_15); /* line 934 */
} /* line 934 */
  sim_icache_fetch(587 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st(reg_r0_12,0,2), reg_r0_14); /* line 936 */
   ADD(reg_r0_16, reg_r0_8, reg_r0_16); /* line 937 */
} /* line 937 */
  sim_icache_fetch(589 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st(reg_r0_13,0,2), reg_r0_17); /* line 939 */
   SHL(reg_r0_16, reg_r0_16, (unsigned int) 7); /* line 940 */
} /* line 940 */
  sim_icache_fetch(591 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 7); /* line 942 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L31X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 943 */
  sim_icache_fetch(593 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_13 + (unsigned int) 2),0,2), reg_r0_18); /* line 945 */
   ADD(reg_r0_13, reg_r0_13, (unsigned int) 4); /* line 946 */
} /* line 946 */
  sim_icache_fetch(595 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_12 + (unsigned int) 2),0,2), reg_r0_16); /* line 948 */
   ADD(reg_r0_12, reg_r0_12, (unsigned int) 4); /* line 950 */
} /* line 950 */
  sim_icache_fetch(597 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L29X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L29X3;
} /* line 952 */
l_L31X3: ;/* line 955 */
LABEL(l_L31X3);
  sim_icache_fetch(598 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 2100); /* line 956 */
   ADD(reg_r0_26, reg_r0_26, (unsigned int) 1050); /* line 958 */
} /* line 958 */
  sim_icache_fetch(602 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L32X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L32X3;
} /* line 960 */
l_L30X3: ;/* line 963 */
LABEL(l_L30X3);
  sim_icache_fetch(603 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 2100); /* line 964 */
   ADD(reg_r0_26, reg_r0_26, (unsigned int) 1050); /* line 965 */
} /* line 965 */
l_L32X3: ;/* line 967 */
LABEL(l_L32X3);
  sim_icache_fetch(607 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_22, (unsigned int) 1); /* line 968 */
   ADD(reg_r0_12, reg_r0_21, (unsigned int) 1050); /* line 969 */
} /* line 969 */
  sim_icache_fetch(610 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_14, reg_r0_23); /* line 971 */
   MOV(reg_r0_13, reg_r0_20); /* line 972 */
} /* line 972 */
  sim_icache_fetch(612 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_27, reg_r0_6); /* line 974 */
   GOTO(l_L25X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L25X3;
} /* line 975 */
l_L26X3: ;/* line 978 */
LABEL(l_L26X3);
  sim_icache_fetch(614 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_14, 0, reg_r0_14); /* line 979 */
   MOV(reg_r0_22, (unsigned int) s_at); /* line 980 */
} /* line 980 */
  sim_icache_fetch(617 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_14); /* line 982 */
   MOV(reg_r0_21, (unsigned int) out); /* line 983 */
} /* line 983 */
  sim_icache_fetch(620 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_28, (unsigned int) -1); /* line 985 */
   MOV(reg_r0_12, ((unsigned int) s_at + (unsigned int) -4200)); /* line 986 */
} /* line 986 */
  sim_icache_fetch(623 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_28); /* line 988 */
} /* line 988 */
l_L33X3: ;/* line 991 */
LABEL(l_L33X3);
  sim_icache_fetch(624 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 992 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 2100); /* line 993 */
} /* line 993 */
  sim_icache_fetch(627 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 995 */
   SH1ADD(reg_r0_8, reg_r0_13, ((unsigned int) s_by2 + (unsigned int) -6)); /* line 996 */
} /* line 996 */
  sim_icache_fetch(630 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 998 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L34X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 999 */
  sim_icache_fetch(632 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, 0); /* line 1001 */
   MOV(reg_r0_5, 0); /* line 1002 */
} /* line 1002 */
  sim_icache_fetch(634 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_18, 0); /* line 1004 */
   MOV(reg_r0_2, 0); /* line 1005 */
} /* line 1005 */
  sim_icache_fetch(636 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_20, 0); /* line 1007 */
   MOV(reg_r0_19, 0); /* line 1008 */
} /* line 1008 */
  sim_icache_fetch(638 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_10); /* line 1010 */
   MOV(reg_r0_14, reg_r0_4); /* line 1011 */
} /* line 1011 */
  sim_icache_fetch(640 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_15, reg_r0_10); /* line 1013 */
   MOV(reg_r0_16, reg_r0_12); /* line 1014 */
} /* line 1014 */
  sim_icache_fetch(642 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_13); /* line 1016 */
} /* line 1016 */
l_L35X3: ;/* line 1019 */
LABEL(l_L35X3);
  sim_icache_fetch(643 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -77); /* line 1020 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -23); /* line 1021 */
} /* line 1021 */
  sim_icache_fetch(645 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 107); /* line 1023 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 14); /* line 1024 */
} /* line 1024 */
  sim_icache_fetch(647 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1026 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 1027 */
} /* line 1027 */
  sim_icache_fetch(649 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 1029 */
   LDHs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,2)); /* line 1030 */
} /* line 1030 */
  sim_icache_fetch(652 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 1032 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L36X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1033 */
  sim_icache_fetch(654 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 1035 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 1036 */
} /* line 1036 */
  sim_icache_fetch(656 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_10, reg_r0_2); /* line 1038 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -77); /* line 1039 */
} /* line 1039 */
  sim_icache_fetch(658 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) 107); /* line 1041 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) -23); /* line 1042 */
} /* line 1042 */
  sim_icache_fetch(660 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 14); /* line 1044 */
   LDHs(reg_r0_13, mem_trace_ld((reg_r0_9 + (unsigned int) 2100),0,2)); /* line 1045 */
} /* line 1045 */
  sim_icache_fetch(663 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 1047 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 1048 */
} /* line 1048 */
  sim_icache_fetch(665 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 1050 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -77); /* line 1051 */
} /* line 1051 */
  sim_icache_fetch(667 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_12); /* line 1053 */
   MULL(reg_r0_11, reg_r0_13, (unsigned int) -23); /* line 1054 */
} /* line 1054 */
  sim_icache_fetch(669 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 1056 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 1057 */
} /* line 1057 */
  sim_icache_fetch(671 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_12, reg_r0_5); /* line 1059 */
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 1060 */
} /* line 1060 */
  sim_icache_fetch(673 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_12, (unsigned int) 107); /* line 1062 */
   LDHs(reg_r0_3, mem_trace_ld(reg_r0_9,0,2)); /* line 1063 */
} /* line 1063 */
  sim_icache_fetch(675 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,2), reg_r0_2); /* line 1065 */
   MOV(reg_r0_6, reg_r0_13); /* line 1066 */
} /* line 1066 */
  sim_icache_fetch(677 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_4); /* line 1068 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L37X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1069 */
  sim_icache_fetch(679 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_12); /* line 1071 */
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 1072 */
} /* line 1072 */
  sim_icache_fetch(681 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 7); /* line 1074 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -3); /* line 1075 */
} /* line 1075 */
  sim_icache_fetch(683 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_8 + (unsigned int) 2),0,2), reg_r0_5); /* line 1077 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1078 */
  sim_icache_fetch(685 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_5, reg_r0_10); /* line 1080 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -6300); /* line 1081 */
} /* line 1081 */
  sim_icache_fetch(688 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st(reg_r0_8,0,2), reg_r0_10); /* line 1083 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -6); /* line 1085 */
} /* line 1085 */
  sim_icache_fetch(690 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L35X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L35X3;
} /* line 1087 */
l_L38X3: ;/* line 1090 */
LABEL(l_L38X3);
  sim_icache_fetch(691 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_17); /* line 1091 */
   MOV(reg_r0_9, reg_r0_21); /* line 1093 */
} /* line 1093 */
  sim_icache_fetch(693 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L39X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L39X3;
} /* line 1095 */
l_L40X3: ;/* line 1098 */
LABEL(l_L40X3);
  sim_icache_fetch(694 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -77); /* line 1099 */
   LDHs(reg_r0_3, mem_trace_ld(reg_r0_2,0,2)); /* line 1100 */
} /* line 1100 */
  sim_icache_fetch(696 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_5, (unsigned int) 107); /* line 1102 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 14); /* line 1103 */
} /* line 1103 */
  sim_icache_fetch(698 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 1105 */
   LDHs(reg_r0_13, mem_trace_ld(reg_r0_7,0,2)); /* line 1106 */
} /* line 1106 */
  sim_icache_fetch(700 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_3, (unsigned int) -24); /* line 1108 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_6); /* line 1109 */
} /* line 1109 */
  sim_icache_fetch(702 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, 0); /* line 1111 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L41X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1112 */
  sim_icache_fetch(704 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 1114 */
   LDHs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 2100),0,2)); /* line 1115 */
} /* line 1115 */
  sim_icache_fetch(707 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_12); /* line 1117 */
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -77); /* line 1118 */
} /* line 1118 */
  sim_icache_fetch(709 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 1120 */
   MULL(reg_r0_12, reg_r0_3, (unsigned int) 14); /* line 1121 */
} /* line 1121 */
  sim_icache_fetch(711 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_15, reg_r0_4); /* line 1123 */
   MULL(reg_r0_16, reg_r0_6, (unsigned int) -24); /* line 1124 */
} /* line 1124 */
  sim_icache_fetch(713 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_15, reg_r0_13); /* line 1126 */
   MULL(reg_r0_17, reg_r0_15, (unsigned int) 107); /* line 1127 */
} /* line 1127 */
  sim_icache_fetch(715 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 7); /* line 1129 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_16); /* line 1130 */
} /* line 1130 */
  sim_icache_fetch(717 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 14); /* line 1132 */
   ADD(reg_r0_17, reg_r0_17, reg_r0_12); /* line 1133 */
} /* line 1133 */
  sim_icache_fetch(719 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_12, reg_r0_13); /* line 1135 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_17); /* line 1136 */
} /* line 1136 */
  sim_icache_fetch(721 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_1, reg_r0_12, (unsigned int) 25); /* line 1138 */
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 1139 */
} /* line 1139 */
  sim_icache_fetch(723 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_16, mem_trace_ld((reg_r0_7 + (unsigned int) 2),0,2)); /* line 1141 */
} /* line 1141 */
  sim_icache_fetch(724 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st(reg_r0_10,0,2), reg_r0_4); /* line 1143 */
} /* line 1143 */
  sim_icache_fetch(725 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_13); /* line 1145 */
   MOV(reg_r0_4, reg_r0_15); /* line 1146 */
} /* line 1146 */
  sim_icache_fetch(727 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L42X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1148 */
  sim_icache_fetch(728 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), 0); /* line 1150 */
   SXTH(reg_r0_5, reg_r0_14); /* line 1151 */
} /* line 1151 */
l_L43X3: ;/* line 1153 */
LABEL(l_L43X3);
  sim_icache_fetch(730 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_16, reg_r0_5, reg_r0_16); /* line 1154 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L44X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1155 */
  sim_icache_fetch(732 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_10 + (unsigned int) 2),0,2), reg_r0_14); /* line 1157 */
   SHL(reg_r0_16, reg_r0_16, (unsigned int) 7); /* line 1158 */
} /* line 1158 */
  sim_icache_fetch(734 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 14); /* line 1160 */
} /* line 1160 */
  sim_icache_fetch(735 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_16); /* line 1162 */
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_16); /* line 1163 */
} /* line 1163 */
  sim_icache_fetch(738 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 1165 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1166 */
   ADD_CYCLES(1);
} /* line 1166 */
  sim_icache_fetch(740 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L45X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1168 */
  sim_icache_fetch(741 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 1170 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4200); /* line 1171 */
} /* line 1171 */
  sim_icache_fetch(744 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 1173 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1174 */
} /* line 1174 */
  sim_icache_fetch(746 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), 0); /* line 1176 */
} /* line 1176 */
l_L46X3: ;/* line 1178 */
LABEL(l_L46X3);
  sim_icache_fetch(748 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_9, reg_r0_11); /* line 1179 */
   GOTO(l_L40X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L40X3;
} /* line 1180 */
l_L45X3: ;/* line 1183 */
LABEL(l_L45X3);
  sim_icache_fetch(750 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 1184 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1185 */
} /* line 1185 */
  sim_icache_fetch(752 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1187 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 1188 */
} /* line 1188 */
  sim_icache_fetch(754 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_3); /* line 1190 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4200); /* line 1192 */
} /* line 1192 */
  sim_icache_fetch(758 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L46X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L46X3;
} /* line 1194 */
l_L44X3: ;/* line 1197 */
LABEL(l_L44X3);
  sim_icache_fetch(759 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 2); /* line 1198 */
   MOV(reg_r0_2, reg_r0_22); /* line 1200 */
} /* line 1200 */
  sim_icache_fetch(761 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L47X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L47X3;
} /* line 1202 */
l_L42X3: ;/* line 1205 */
LABEL(l_L42X3);
  sim_icache_fetch(762 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_5, reg_r0_14); /* line 1206 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1207 */
} /* line 1207 */
  sim_icache_fetch(764 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_3); /* line 1209 */
   GOTO(l_L43X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L43X3;
} /* line 1210 */
l_L41X3: ;/* line 1213 */
LABEL(l_L41X3);
  sim_icache_fetch(766 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 2); /* line 1214 */
   MOV(reg_r0_2, reg_r0_22); /* line 1215 */
} /* line 1215 */
l_L47X3: ;/* line 1217 */
LABEL(l_L47X3);
  sim_icache_fetch(768 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_20, (unsigned int) 1); /* line 1218 */
   ADD(reg_r0_22, reg_r0_23, (unsigned int) 2); /* line 1219 */
} /* line 1219 */
  sim_icache_fetch(770 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, reg_r0_18); /* line 1221 */
   MOV(reg_r0_13, reg_r0_21); /* line 1222 */
} /* line 1222 */
  sim_icache_fetch(772 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_21, reg_r0_2, (unsigned int) 1); /* line 1224 */
   GOTO(l_L33X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L33X3;
} /* line 1225 */
l_L37X3: ;/* line 1228 */
LABEL(l_L37X3);
  sim_icache_fetch(774 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_17); /* line 1229 */
   MOV(reg_r0_9, reg_r0_21); /* line 1231 */
} /* line 1231 */
  sim_icache_fetch(776 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L39X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L39X3;
} /* line 1233 */
l_L36X3: ;/* line 1236 */
LABEL(l_L36X3);
  sim_icache_fetch(777 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_17); /* line 1237 */
   MOV(reg_r0_9, reg_r0_21); /* line 1238 */
} /* line 1238 */
l_L39X3: ;/* line 1240 */
LABEL(l_L39X3);
  sim_icache_fetch(779 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_3); /* line 1241 */
   MOV(reg_r0_7, (unsigned int) s_by2); /* line 1242 */
} /* line 1242 */
  sim_icache_fetch(782 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, (unsigned int) s_by1); /* line 1244 */
   MOV(reg_r0_2, reg_r0_22); /* line 1245 */
} /* line 1245 */
  sim_icache_fetch(785 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_19); /* line 1247 */
   MOV(reg_r0_5, reg_r0_18); /* line 1248 */
} /* line 1248 */
  sim_icache_fetch(787 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_20); /* line 1250 */
   MOV(reg_r0_11, (unsigned int) 2100); /* line 1251 */
} /* line 1251 */
  sim_icache_fetch(790 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_18, reg_r0_15); /* line 1253 */
   MOV(reg_r0_19, reg_r0_16); /* line 1254 */
} /* line 1254 */
  sim_icache_fetch(792 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_20, reg_r0_14); /* line 1256 */
   MOV(reg_r0_23, reg_r0_22); /* line 1257 */
} /* line 1257 */
  sim_icache_fetch(794 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, reg_r0_21); /* line 1259 */
} /* line 1259 */
  sim_icache_fetch(795 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, reg_r0_17); /* line 1261 */
   GOTO(l_L40X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L40X3;
} /* line 1262 */
l_L34X3: ;/* line 1265 */
LABEL(l_L34X3);
  sim_icache_fetch(797 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_simd);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1267 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 199: goto l_L25X3;
    case 200: goto l_L27X3;
    case 201: goto l_L28X3;
    case 202: goto l_L29X3;
    case 203: goto l_L31X3;
    case 204: goto l_L30X3;
    case 205: goto l_L32X3;
    case 206: goto l_L26X3;
    case 207: goto l_L33X3;
    case 208: goto l_L35X3;
    case 209: goto l_L38X3;
    case 210: goto l_L40X3;
    case 211: goto l_L43X3;
    case 212: goto l_L46X3;
    case 213: goto l_L45X3;
    case 214: goto l_L44X3;
    case 215: goto l_L42X3;
    case 216: goto l_L41X3;
    case 217: goto l_L47X3;
    case 218: goto l_L37X3;
    case 219: goto l_L36X3;
    case 220: goto l_L39X3;
    case 221: goto l_L34X3;
    case 222:
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
  reg_l0_0 = (247 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(798 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 1283 */
} /* line 1283 */
  sim_icache_fetch(799 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_24, (unsigned int) s_at); /* line 1285 */
   MOV(reg_r0_25, (unsigned int) in); /* line 1286 */
} /* line 1286 */
  sim_icache_fetch(803 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_4 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_2); /* line 1288 */
   MOV(reg_r0_12, t__i32_0); /* line 1289 */
} /* line 1289 */
  sim_icache_fetch(805 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_12, (unsigned int) -1); /* line 1291 */
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -2)); /* line 1292 */
} /* line 1292 */
  sim_icache_fetch(808 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_26, reg_r0_3); /* line 1294 */
} /* line 1294 */
l_L48X3: ;/* line 1297 */
LABEL(l_L48X3);
  sim_icache_fetch(809 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 1298 */
   ADD(reg_r0_9, reg_r0_10, reg_r0_11); /* line 1299 */
} /* line 1299 */
  sim_icache_fetch(811 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 1301 */
   SH1ADD(reg_r0_8, reg_r0_12, ((unsigned int) s_ay2 + (unsigned int) -6)); /* line 1302 */
} /* line 1302 */
  sim_icache_fetch(814 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 1304 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1305 */
  sim_icache_fetch(816 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 1307 */
   MOV(reg_r0_6, 0); /* line 1308 */
} /* line 1308 */
  sim_icache_fetch(818 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_22, 0); /* line 1310 */
   MOV(reg_r0_21, 0); /* line 1311 */
} /* line 1311 */
  sim_icache_fetch(820 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_23, 0); /* line 1313 */
   MOV(reg_r0_7, reg_r0_11); /* line 1314 */
} /* line 1314 */
  sim_icache_fetch(822 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_4); /* line 1316 */
   MOV(reg_r0_18, reg_r0_10); /* line 1317 */
} /* line 1317 */
  sim_icache_fetch(824 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, reg_r0_11); /* line 1319 */
   MOV(reg_r0_20, reg_r0_12); /* line 1320 */
} /* line 1320 */
l_L50X3: ;/* line 1323 */
LABEL(l_L50X3);
  sim_icache_fetch(826 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -23); /* line 1324 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -77); /* line 1325 */
} /* line 1325 */
  sim_icache_fetch(828 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -24); /* line 1327 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 107); /* line 1328 */
} /* line 1328 */
  sim_icache_fetch(830 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_4, reg_r0_4); /* line 1330 */
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 1331 */
} /* line 1331 */
  sim_icache_fetch(832 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 7); /* line 1333 */
   SXTH(reg_r0_2, reg_r0_2); /* line 1334 */
} /* line 1334 */
  sim_icache_fetch(834 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_10, reg_r0_10); /* line 1336 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_2); /* line 1337 */
} /* line 1337 */
  sim_icache_fetch(836 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1339 */
   SXTH(reg_r0_6, reg_r0_6); /* line 1340 */
} /* line 1340 */
  sim_icache_fetch(838 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 1342 */
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 2),0,1)); /* line 1343 */
} /* line 1343 */
  sim_icache_fetch(840 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 1345 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L51X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1346 */
  sim_icache_fetch(842 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_11, reg_r0_4); /* line 1348 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 1349 */
} /* line 1349 */
  sim_icache_fetch(844 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -23); /* line 1351 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -77); /* line 1352 */
} /* line 1352 */
  sim_icache_fetch(846 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -24); /* line 1354 */
   MULL(reg_r0_13, reg_r0_11, (unsigned int) 107); /* line 1355 */
} /* line 1355 */
  sim_icache_fetch(848 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_12, reg_r0_12); /* line 1357 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 1358 */
} /* line 1358 */
  sim_icache_fetch(850 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 7); /* line 1360 */
   SXTH(reg_r0_5, reg_r0_5); /* line 1361 */
} /* line 1361 */
  sim_icache_fetch(852 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_13, reg_r0_13); /* line 1363 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_5); /* line 1364 */
} /* line 1364 */
  sim_icache_fetch(854 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_3, reg_r0_3); /* line 1366 */
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_9 + (unsigned int) 1),0,1)); /* line 1367 */
} /* line 1367 */
  sim_icache_fetch(856 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_13); /* line 1369 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 1370 */
} /* line 1370 */
  sim_icache_fetch(858 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 1372 */
   MULL(reg_r0_11, reg_r0_11, (unsigned int) -77); /* line 1373 */
} /* line 1373 */
  sim_icache_fetch(860 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_13, reg_r0_12); /* line 1375 */
   MULL(reg_r0_15, reg_r0_14, (unsigned int) -23); /* line 1376 */
} /* line 1376 */
  sim_icache_fetch(862 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_16, reg_r0_13, (unsigned int) 107); /* line 1378 */
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 7); /* line 1379 */
} /* line 1379 */
  sim_icache_fetch(864 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_15, reg_r0_15); /* line 1381 */
   SXTH(reg_r0_11, reg_r0_11); /* line 1382 */
} /* line 1382 */
  sim_icache_fetch(866 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 7); /* line 1384 */
   ADD(reg_r0_15, reg_r0_15, reg_r0_11); /* line 1385 */
} /* line 1385 */
  sim_icache_fetch(868 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -24); /* line 1387 */
   SXTH(reg_r0_16, reg_r0_16); /* line 1388 */
} /* line 1388 */
  sim_icache_fetch(870 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_13); /* line 1390 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_9,0,1)); /* line 1391 */
} /* line 1391 */
  sim_icache_fetch(872 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_14); /* line 1393 */
   SXTH(reg_r0_10, reg_r0_10); /* line 1394 */
} /* line 1394 */
  sim_icache_fetch(874 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_16); /* line 1396 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -3); /* line 1397 */
} /* line 1397 */
  sim_icache_fetch(876 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_15, reg_r0_15, reg_r0_10); /* line 1399 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -3); /* line 1400 */
} /* line 1400 */
  sim_icache_fetch(878 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,2), reg_r0_4); /* line 1402 */
   SXTH(reg_r0_5, reg_r0_15); /* line 1403 */
} /* line 1403 */
  sim_icache_fetch(880 + t_thisfile.offset, 1);
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
} /* line 1405 */
  sim_icache_fetch(881 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_8 + (unsigned int) 2),0,2), reg_r0_12); /* line 1407 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L53X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1408 */
  sim_icache_fetch(883 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st(reg_r0_8,0,2), reg_r0_15); /* line 1410 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -6); /* line 1412 */
} /* line 1412 */
  sim_icache_fetch(885 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L50X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L50X3;
} /* line 1414 */
l_L53X3: ;/* line 1417 */
LABEL(l_L53X3);
  sim_icache_fetch(886 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_20); /* line 1418 */
   MOV(reg_r0_8, (unsigned int) s_ay2); /* line 1420 */
} /* line 1420 */
  sim_icache_fetch(889 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L54X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L54X3;
} /* line 1422 */
l_L55X3: ;/* line 1425 */
LABEL(l_L55X3);
  sim_icache_fetch(890 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 1426 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 107); /* line 1427 */
} /* line 1427 */
  sim_icache_fetch(892 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 14); /* line 1429 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -77); /* line 1430 */
} /* line 1430 */
  sim_icache_fetch(894 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 1432 */
   LDHs(reg_r0_12, mem_trace_ld(reg_r0_8,0,2)); /* line 1433 */
} /* line 1433 */
  sim_icache_fetch(896 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -24); /* line 1435 */
   SXTH(reg_r0_5, reg_r0_5); /* line 1436 */
} /* line 1436 */
  sim_icache_fetch(898 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_7, reg_r0_7); /* line 1438 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 7); /* line 1439 */
} /* line 1439 */
  sim_icache_fetch(900 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_13, reg_r0_13); /* line 1441 */
   SXTH(reg_r0_6, reg_r0_6); /* line 1442 */
} /* line 1442 */
  sim_icache_fetch(902 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 1444 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_5); /* line 1445 */
} /* line 1445 */
  sim_icache_fetch(904 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_9, (unsigned int) 1); /* line 1447 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_13); /* line 1448 */
} /* line 1448 */
  sim_icache_fetch(906 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_5, reg_r0_7); /* line 1450 */
   CMPLT(reg_b0_1, reg_r0_9, 0); /* line 1451 */
} /* line 1451 */
  sim_icache_fetch(908 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_5, reg_r0_12); /* line 1453 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L56X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1454 */
  sim_icache_fetch(910 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 7); /* line 1456 */
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 1457 */
} /* line 1457 */
  sim_icache_fetch(912 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 7); /* line 1459 */
   MULL(reg_r0_14, reg_r0_5, (unsigned int) 107); /* line 1460 */
} /* line 1460 */
  sim_icache_fetch(914 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 14); /* line 1462 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -77); /* line 1463 */
} /* line 1463 */
  sim_icache_fetch(916 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_15, reg_r0_13, (unsigned int) -24); /* line 1465 */
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 1466 */
} /* line 1466 */
  sim_icache_fetch(918 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_14, reg_r0_14); /* line 1468 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 1469 */
} /* line 1469 */
  sim_icache_fetch(920 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_15, reg_r0_15); /* line 1471 */
   SXTH(reg_r0_4, reg_r0_4); /* line 1472 */
} /* line 1472 */
  sim_icache_fetch(922 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_3, reg_r0_3); /* line 1474 */
   ADD(reg_r0_15, reg_r0_15, reg_r0_14); /* line 1475 */
} /* line 1475 */
  sim_icache_fetch(924 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 1477 */
   LDHs(reg_r0_14, mem_trace_ld((reg_r0_8 + (unsigned int) 2),0,2)); /* line 1478 */
} /* line 1478 */
  sim_icache_fetch(926 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_5); /* line 1480 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_15); /* line 1481 */
} /* line 1481 */
  sim_icache_fetch(928 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_4, reg_r0_3); /* line 1483 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 2); /* line 1484 */
} /* line 1484 */
  sim_icache_fetch(930 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_4, reg_r0_14); /* line 1486 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 4); /* line 1487 */
} /* line 1487 */
  sim_icache_fetch(932 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 1489 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 2); /* line 1490 */
} /* line 1490 */
  sim_icache_fetch(934 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st(reg_r0_11,0,2), reg_r0_7); /* line 1492 */
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 1493 */
} /* line 1493 */
  sim_icache_fetch(936 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st(reg_r0_10,0,2), reg_r0_12); /* line 1495 */
   MOV(reg_r0_7, reg_r0_13); /* line 1496 */
} /* line 1496 */
  sim_icache_fetch(938 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L56X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1498 */
  sim_icache_fetch(939 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_11 + (unsigned int) 2),0,2), reg_r0_3); /* line 1500 */
   ADD(reg_r0_11, reg_r0_11, (unsigned int) 4); /* line 1501 */
} /* line 1501 */
  sim_icache_fetch(941 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_10 + (unsigned int) 2),0,2), reg_r0_14); /* line 1503 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 1505 */
} /* line 1505 */
  sim_icache_fetch(943 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L55X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L55X3;
} /* line 1507 */
l_L56X3: ;/* line 1510 */
LABEL(l_L56X3);
  sim_icache_fetch(944 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_24, reg_r0_24, (unsigned int) 2100); /* line 1511 */
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 1050); /* line 1512 */
} /* line 1512 */
  sim_icache_fetch(948 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_17, (unsigned int) 1); /* line 1514 */
   ADD(reg_r0_10, reg_r0_18, (unsigned int) 1050); /* line 1515 */
} /* line 1515 */
  sim_icache_fetch(951 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_12, reg_r0_20); /* line 1517 */
   MOV(reg_r0_11, reg_r0_19); /* line 1519 */
} /* line 1519 */
  sim_icache_fetch(953 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L48X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L48X3;
} /* line 1521 */
l_L52X3: ;/* line 1524 */
LABEL(l_L52X3);
  sim_icache_fetch(954 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_20); /* line 1525 */
   MOV(reg_r0_8, (unsigned int) s_ay2); /* line 1527 */
} /* line 1527 */
  sim_icache_fetch(957 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L54X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L54X3;
} /* line 1529 */
l_L51X3: ;/* line 1532 */
LABEL(l_L51X3);
  sim_icache_fetch(958 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_20); /* line 1533 */
   MOV(reg_r0_8, (unsigned int) s_ay2); /* line 1534 */
} /* line 1534 */
l_L54X3: ;/* line 1536 */
LABEL(l_L54X3);
  sim_icache_fetch(961 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_3); /* line 1537 */
   MOV(reg_r0_10, reg_r0_24); /* line 1538 */
} /* line 1538 */
  sim_icache_fetch(963 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, (unsigned int) s_ay1); /* line 1540 */
   MOV(reg_r0_2, reg_r0_25); /* line 1541 */
} /* line 1541 */
  sim_icache_fetch(966 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_21); /* line 1543 */
   MOV(reg_r0_4, reg_r0_22); /* line 1544 */
} /* line 1544 */
  sim_icache_fetch(968 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_23); /* line 1546 */
   GOTO(l_L55X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L55X3;
} /* line 1547 */
l_L49X3: ;/* line 1550 */
LABEL(l_L49X3);
  sim_icache_fetch(970 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_12, 0, reg_r0_12); /* line 1551 */
   MOV(reg_r0_22, (unsigned int) s_at); /* line 1552 */
} /* line 1552 */
  sim_icache_fetch(973 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_12); /* line 1554 */
   MOV(reg_r0_21, (unsigned int) out); /* line 1555 */
} /* line 1555 */
  sim_icache_fetch(976 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_26, (unsigned int) -1); /* line 1557 */
   MOV(reg_r0_12, ((unsigned int) s_at + (unsigned int) -4200)); /* line 1558 */
} /* line 1558 */
  sim_icache_fetch(979 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_26); /* line 1560 */
} /* line 1560 */
l_L57X3: ;/* line 1563 */
LABEL(l_L57X3);
  sim_icache_fetch(980 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 1564 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 2100); /* line 1565 */
} /* line 1565 */
  sim_icache_fetch(983 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 1567 */
   SH1ADD(reg_r0_8, reg_r0_13, ((unsigned int) s_by2 + (unsigned int) -6)); /* line 1568 */
} /* line 1568 */
  sim_icache_fetch(986 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 1570 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L58X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1571 */
  sim_icache_fetch(988 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, 0); /* line 1573 */
   MOV(reg_r0_5, 0); /* line 1574 */
} /* line 1574 */
  sim_icache_fetch(990 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_18, 0); /* line 1576 */
   MOV(reg_r0_2, 0); /* line 1577 */
} /* line 1577 */
  sim_icache_fetch(992 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_20, 0); /* line 1579 */
   MOV(reg_r0_19, 0); /* line 1580 */
} /* line 1580 */
  sim_icache_fetch(994 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_10); /* line 1582 */
   MOV(reg_r0_14, reg_r0_4); /* line 1583 */
} /* line 1583 */
  sim_icache_fetch(996 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_15, reg_r0_10); /* line 1585 */
   MOV(reg_r0_16, reg_r0_12); /* line 1586 */
} /* line 1586 */
  sim_icache_fetch(998 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_13); /* line 1588 */
} /* line 1588 */
l_L59X3: ;/* line 1591 */
LABEL(l_L59X3);
  sim_icache_fetch(999 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -77); /* line 1592 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -23); /* line 1593 */
} /* line 1593 */
  sim_icache_fetch(1001 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 107); /* line 1595 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 14); /* line 1596 */
} /* line 1596 */
  sim_icache_fetch(1003 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1598 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 1599 */
} /* line 1599 */
  sim_icache_fetch(1005 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 1601 */
   LDHs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,2)); /* line 1602 */
} /* line 1602 */
  sim_icache_fetch(1008 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 1604 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L60X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1605 */
  sim_icache_fetch(1010 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 1607 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 1608 */
} /* line 1608 */
  sim_icache_fetch(1012 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_10, reg_r0_2); /* line 1610 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -77); /* line 1611 */
} /* line 1611 */
  sim_icache_fetch(1014 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) 107); /* line 1613 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) -23); /* line 1614 */
} /* line 1614 */
  sim_icache_fetch(1016 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 14); /* line 1616 */
   LDHs(reg_r0_13, mem_trace_ld((reg_r0_9 + (unsigned int) 2100),0,2)); /* line 1617 */
} /* line 1617 */
  sim_icache_fetch(1019 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 1619 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 1620 */
} /* line 1620 */
  sim_icache_fetch(1021 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 1622 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -77); /* line 1623 */
} /* line 1623 */
  sim_icache_fetch(1023 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_12); /* line 1625 */
   MULL(reg_r0_11, reg_r0_13, (unsigned int) -23); /* line 1626 */
} /* line 1626 */
  sim_icache_fetch(1025 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 1628 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 1629 */
} /* line 1629 */
  sim_icache_fetch(1027 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_12, reg_r0_5); /* line 1631 */
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 1632 */
} /* line 1632 */
  sim_icache_fetch(1029 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_12, (unsigned int) 107); /* line 1634 */
   LDHs(reg_r0_3, mem_trace_ld(reg_r0_9,0,2)); /* line 1635 */
} /* line 1635 */
  sim_icache_fetch(1031 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_13); /* line 1637 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -3); /* line 1638 */
} /* line 1638 */
  sim_icache_fetch(1033 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,2), reg_r0_2); /* line 1640 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_4); /* line 1641 */
} /* line 1641 */
  sim_icache_fetch(1035 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 1643 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1644 */
  sim_icache_fetch(1037 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_12); /* line 1646 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 7); /* line 1647 */
} /* line 1647 */
  sim_icache_fetch(1039 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_8 + (unsigned int) 2),0,2), reg_r0_5); /* line 1649 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1650 */
  sim_icache_fetch(1041 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_5, reg_r0_10); /* line 1652 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -6300); /* line 1653 */
} /* line 1653 */
  sim_icache_fetch(1044 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st(reg_r0_8,0,2), reg_r0_10); /* line 1655 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -6); /* line 1657 */
} /* line 1657 */
  sim_icache_fetch(1046 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L59X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L59X3;
} /* line 1659 */
l_L62X3: ;/* line 1662 */
LABEL(l_L62X3);
  sim_icache_fetch(1047 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_17); /* line 1663 */
   MOV(reg_r0_9, reg_r0_21); /* line 1665 */
} /* line 1665 */
  sim_icache_fetch(1049 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L63X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L63X3;
} /* line 1667 */
l_L64X3: ;/* line 1670 */
LABEL(l_L64X3);
  sim_icache_fetch(1050 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -77); /* line 1671 */
   LDHs(reg_r0_3, mem_trace_ld(reg_r0_2,0,2)); /* line 1672 */
} /* line 1672 */
  sim_icache_fetch(1052 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_5, (unsigned int) 107); /* line 1674 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 14); /* line 1675 */
} /* line 1675 */
  sim_icache_fetch(1054 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 1677 */
   LDHs(reg_r0_13, mem_trace_ld(reg_r0_7,0,2)); /* line 1678 */
} /* line 1678 */
  sim_icache_fetch(1056 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_3, (unsigned int) -24); /* line 1680 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_6); /* line 1681 */
} /* line 1681 */
  sim_icache_fetch(1058 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, 0); /* line 1683 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L65X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1684 */
  sim_icache_fetch(1060 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 1686 */
   LDHs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 2100),0,2)); /* line 1687 */
} /* line 1687 */
  sim_icache_fetch(1063 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_12); /* line 1689 */
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -77); /* line 1690 */
} /* line 1690 */
  sim_icache_fetch(1065 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 1692 */
   MULL(reg_r0_12, reg_r0_3, (unsigned int) 14); /* line 1693 */
} /* line 1693 */
  sim_icache_fetch(1067 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_15, reg_r0_4); /* line 1695 */
   MULL(reg_r0_16, reg_r0_6, (unsigned int) -24); /* line 1696 */
} /* line 1696 */
  sim_icache_fetch(1069 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_15, reg_r0_13); /* line 1698 */
   MULL(reg_r0_17, reg_r0_15, (unsigned int) 107); /* line 1699 */
} /* line 1699 */
  sim_icache_fetch(1071 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 7); /* line 1701 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_16); /* line 1702 */
} /* line 1702 */
  sim_icache_fetch(1073 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 14); /* line 1704 */
   ADD(reg_r0_17, reg_r0_17, reg_r0_12); /* line 1705 */
} /* line 1705 */
  sim_icache_fetch(1075 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_12, reg_r0_13); /* line 1707 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_17); /* line 1708 */
} /* line 1708 */
  sim_icache_fetch(1077 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_1, reg_r0_12, (unsigned int) 25); /* line 1710 */
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 1711 */
} /* line 1711 */
  sim_icache_fetch(1079 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_16, mem_trace_ld((reg_r0_7 + (unsigned int) 2),0,2)); /* line 1713 */
} /* line 1713 */
  sim_icache_fetch(1080 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st(reg_r0_10,0,2), reg_r0_4); /* line 1715 */
} /* line 1715 */
  sim_icache_fetch(1081 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_13); /* line 1717 */
   MOV(reg_r0_4, reg_r0_15); /* line 1718 */
} /* line 1718 */
  sim_icache_fetch(1083 + t_thisfile.offset, 1);
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
} /* line 1720 */
  sim_icache_fetch(1084 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), 0); /* line 1722 */
   SXTH(reg_r0_5, reg_r0_14); /* line 1723 */
} /* line 1723 */
l_L67X3: ;/* line 1725 */
LABEL(l_L67X3);
  sim_icache_fetch(1086 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_16, reg_r0_5, reg_r0_16); /* line 1726 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L68X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1727 */
  sim_icache_fetch(1088 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_10 + (unsigned int) 2),0,2), reg_r0_14); /* line 1729 */
   SHL(reg_r0_16, reg_r0_16, (unsigned int) 7); /* line 1730 */
} /* line 1730 */
  sim_icache_fetch(1090 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 14); /* line 1732 */
} /* line 1732 */
  sim_icache_fetch(1091 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_16); /* line 1734 */
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_16); /* line 1735 */
} /* line 1735 */
  sim_icache_fetch(1094 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 1737 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1738 */
   ADD_CYCLES(1);
} /* line 1738 */
  sim_icache_fetch(1096 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L69X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1740 */
  sim_icache_fetch(1097 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 1742 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4200); /* line 1743 */
} /* line 1743 */
  sim_icache_fetch(1100 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 1745 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1746 */
} /* line 1746 */
  sim_icache_fetch(1102 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), 0); /* line 1748 */
} /* line 1748 */
l_L70X3: ;/* line 1750 */
LABEL(l_L70X3);
  sim_icache_fetch(1104 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_9, reg_r0_11); /* line 1751 */
   GOTO(l_L64X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L64X3;
} /* line 1752 */
l_L69X3: ;/* line 1755 */
LABEL(l_L69X3);
  sim_icache_fetch(1106 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 1756 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1757 */
} /* line 1757 */
  sim_icache_fetch(1108 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1759 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 1760 */
} /* line 1760 */
  sim_icache_fetch(1110 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_3); /* line 1762 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4200); /* line 1764 */
} /* line 1764 */
  sim_icache_fetch(1114 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L70X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L70X3;
} /* line 1766 */
l_L68X3: ;/* line 1769 */
LABEL(l_L68X3);
  sim_icache_fetch(1115 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 2); /* line 1770 */
   MOV(reg_r0_2, reg_r0_22); /* line 1772 */
} /* line 1772 */
  sim_icache_fetch(1117 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L71X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L71X3;
} /* line 1774 */
l_L66X3: ;/* line 1777 */
LABEL(l_L66X3);
  sim_icache_fetch(1118 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_5, reg_r0_14); /* line 1778 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1779 */
} /* line 1779 */
  sim_icache_fetch(1120 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_3); /* line 1781 */
   GOTO(l_L67X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L67X3;
} /* line 1782 */
l_L65X3: ;/* line 1785 */
LABEL(l_L65X3);
  sim_icache_fetch(1122 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 2); /* line 1786 */
   MOV(reg_r0_2, reg_r0_22); /* line 1787 */
} /* line 1787 */
l_L71X3: ;/* line 1789 */
LABEL(l_L71X3);
  sim_icache_fetch(1124 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_20, (unsigned int) 1); /* line 1790 */
   ADD(reg_r0_22, reg_r0_23, (unsigned int) 2); /* line 1791 */
} /* line 1791 */
  sim_icache_fetch(1126 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, reg_r0_18); /* line 1793 */
   MOV(reg_r0_13, reg_r0_21); /* line 1794 */
} /* line 1794 */
  sim_icache_fetch(1128 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_21, reg_r0_2, (unsigned int) 1); /* line 1796 */
   GOTO(l_L57X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L57X3;
} /* line 1797 */
l_L61X3: ;/* line 1800 */
LABEL(l_L61X3);
  sim_icache_fetch(1130 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_17); /* line 1801 */
   MOV(reg_r0_9, reg_r0_21); /* line 1803 */
} /* line 1803 */
  sim_icache_fetch(1132 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L63X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L63X3;
} /* line 1805 */
l_L60X3: ;/* line 1808 */
LABEL(l_L60X3);
  sim_icache_fetch(1133 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_17); /* line 1809 */
   MOV(reg_r0_9, reg_r0_21); /* line 1810 */
} /* line 1810 */
l_L63X3: ;/* line 1812 */
LABEL(l_L63X3);
  sim_icache_fetch(1135 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_3); /* line 1813 */
   MOV(reg_r0_7, (unsigned int) s_by2); /* line 1814 */
} /* line 1814 */
  sim_icache_fetch(1138 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, (unsigned int) s_by1); /* line 1816 */
   MOV(reg_r0_2, reg_r0_22); /* line 1817 */
} /* line 1817 */
  sim_icache_fetch(1141 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_19); /* line 1819 */
   MOV(reg_r0_5, reg_r0_18); /* line 1820 */
} /* line 1820 */
  sim_icache_fetch(1143 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_20); /* line 1822 */
   MOV(reg_r0_11, (unsigned int) 2100); /* line 1823 */
} /* line 1823 */
  sim_icache_fetch(1146 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_18, reg_r0_15); /* line 1825 */
   MOV(reg_r0_19, reg_r0_16); /* line 1826 */
} /* line 1826 */
  sim_icache_fetch(1148 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_20, reg_r0_14); /* line 1828 */
   MOV(reg_r0_23, reg_r0_22); /* line 1829 */
} /* line 1829 */
  sim_icache_fetch(1150 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, reg_r0_21); /* line 1831 */
} /* line 1831 */
  sim_icache_fetch(1151 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, reg_r0_17); /* line 1833 */
   GOTO(l_L64X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L64X3;
} /* line 1834 */
l_L58X3: ;/* line 1837 */
LABEL(l_L58X3);
  sim_icache_fetch(1153 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_short);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1839 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 223: goto l_L48X3;
    case 224: goto l_L50X3;
    case 225: goto l_L53X3;
    case 226: goto l_L55X3;
    case 227: goto l_L56X3;
    case 228: goto l_L52X3;
    case 229: goto l_L51X3;
    case 230: goto l_L54X3;
    case 231: goto l_L49X3;
    case 232: goto l_L57X3;
    case 233: goto l_L59X3;
    case 234: goto l_L62X3;
    case 235: goto l_L64X3;
    case 236: goto l_L67X3;
    case 237: goto l_L70X3;
    case 238: goto l_L69X3;
    case 239: goto l_L68X3;
    case 240: goto l_L66X3;
    case 241: goto l_L65X3;
    case 242: goto l_L71X3;
    case 243: goto l_L61X3;
    case 244: goto l_L60X3;
    case 245: goto l_L63X3;
    case 246: goto l_L58X3;
    case 247:
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
  reg_l0_0 = (270 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1154 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 1855 */
} /* line 1855 */
  sim_icache_fetch(1155 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_24, (unsigned int) at); /* line 1857 */
   MOV(reg_r0_25, (unsigned int) in); /* line 1858 */
} /* line 1858 */
  sim_icache_fetch(1159 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_4 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_2); /* line 1860 */
   MOV(reg_r0_12, t__i32_0); /* line 1861 */
} /* line 1861 */
  sim_icache_fetch(1161 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_12, (unsigned int) -1); /* line 1863 */
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 1864 */
} /* line 1864 */
  sim_icache_fetch(1164 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_26, reg_r0_3); /* line 1866 */
} /* line 1866 */
l_L72X3: ;/* line 1869 */
LABEL(l_L72X3);
  sim_icache_fetch(1165 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 1870 */
   ADD(reg_r0_9, reg_r0_10, reg_r0_11); /* line 1871 */
} /* line 1871 */
  sim_icache_fetch(1167 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 1873 */
   SH2ADD(reg_r0_8, reg_r0_12, ((unsigned int) ay2 + (unsigned int) -16)); /* line 1874 */
} /* line 1874 */
  sim_icache_fetch(1170 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 1876 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L73X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1877 */
  sim_icache_fetch(1172 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 1879 */
   MOV(reg_r0_6, 0); /* line 1880 */
} /* line 1880 */
  sim_icache_fetch(1174 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_22, 0); /* line 1882 */
   MOV(reg_r0_21, 0); /* line 1883 */
} /* line 1883 */
  sim_icache_fetch(1176 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_23, 0); /* line 1885 */
   MOV(reg_r0_7, reg_r0_11); /* line 1886 */
} /* line 1886 */
  sim_icache_fetch(1178 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_4); /* line 1888 */
   MOV(reg_r0_18, reg_r0_10); /* line 1889 */
} /* line 1889 */
  sim_icache_fetch(1180 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, reg_r0_11); /* line 1891 */
   MOV(reg_r0_20, reg_r0_12); /* line 1892 */
} /* line 1892 */
l_L74X3: ;/* line 1895 */
LABEL(l_L74X3);
  sim_icache_fetch(1182 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 1896 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 1897 */
} /* line 1897 */
  sim_icache_fetch(1184 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -48); /* line 1899 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 1900 */
} /* line 1900 */
  sim_icache_fetch(1186 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1902 */
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1903 */
} /* line 1903 */
  sim_icache_fetch(1188 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1905 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_2); /* line 1906 */
} /* line 1906 */
  sim_icache_fetch(1190 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 1908 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1909 */
  sim_icache_fetch(1192 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 1911 */
   LDBU(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 3),0,1)); /* line 1912 */
} /* line 1912 */
  sim_icache_fetch(1194 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 1914 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1915 */
} /* line 1915 */
  sim_icache_fetch(1196 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 1917 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) 215); /* line 1918 */
} /* line 1918 */
  sim_icache_fetch(1198 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 1920 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1921 */
} /* line 1921 */
  sim_icache_fetch(1200 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1923 */
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_9 + (unsigned int) 2),0,1)); /* line 1924 */
} /* line 1924 */
  sim_icache_fetch(1202 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_5); /* line 1926 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 1927 */
} /* line 1927 */
  sim_icache_fetch(1204 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 1929 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 1930 */
} /* line 1930 */
  sim_icache_fetch(1206 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_13, (unsigned int) -47); /* line 1932 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) -155); /* line 1933 */
} /* line 1933 */
  sim_icache_fetch(1208 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 1935 */
   MULL(reg_r0_15, reg_r0_12, (unsigned int) 215); /* line 1936 */
} /* line 1936 */
  sim_icache_fetch(1210 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1938 */
   LDBUs(reg_r0_16, mem_trace_ld((reg_r0_9 + (unsigned int) 1),0,1)); /* line 1939 */
} /* line 1939 */
  sim_icache_fetch(1212 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1941 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_11); /* line 1942 */
} /* line 1942 */
  sim_icache_fetch(1214 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_15); /* line 1944 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 1945 */
} /* line 1945 */
  sim_icache_fetch(1216 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 1947 */
   MULL(reg_r0_10, reg_r0_12, (unsigned int) -155); /* line 1948 */
} /* line 1948 */
  sim_icache_fetch(1218 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_16, (unsigned int) -47); /* line 1950 */
   MULL(reg_r0_15, reg_r0_14, (unsigned int) 215); /* line 1951 */
} /* line 1951 */
  sim_icache_fetch(1220 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_13, (unsigned int) -48); /* line 1953 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1954 */
} /* line 1954 */
  sim_icache_fetch(1222 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1956 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 1957 */
} /* line 1957 */
  sim_icache_fetch(1224 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 1959 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_9,0,1)); /* line 1960 */
} /* line 1960 */
  sim_icache_fetch(1226 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_14); /* line 1962 */
   ADD(reg_r0_5, reg_r0_11, reg_r0_13); /* line 1963 */
} /* line 1963 */
  sim_icache_fetch(1228 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_16); /* line 1965 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 1966 */
} /* line 1966 */
  sim_icache_fetch(1230 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 1968 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -4); /* line 1969 */
} /* line 1969 */
  sim_icache_fetch(1232 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1971 */
  sim_icache_fetch(1233 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_12); /* line 1973 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1974 */
  sim_icache_fetch(1235 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_14); /* line 1976 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1977 */
  sim_icache_fetch(1237 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_5); /* line 1979 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 1981 */
} /* line 1981 */
  sim_icache_fetch(1239 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L74X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L74X3;
} /* line 1983 */
l_L75X3: ;/* line 1986 */
LABEL(l_L75X3);
  sim_icache_fetch(1240 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_20); /* line 1987 */
   MOV(reg_r0_10, reg_r0_24); /* line 1988 */
} /* line 1988 */
  sim_icache_fetch(1242 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_3); /* line 1990 */
   MOV(reg_r0_8, (unsigned int) ay2); /* line 1991 */
} /* line 1991 */
  sim_icache_fetch(1245 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, (unsigned int) ay1); /* line 1993 */
   MOV(reg_r0_2, reg_r0_25); /* line 1994 */
} /* line 1994 */
  sim_icache_fetch(1248 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_21); /* line 1996 */
   MOV(reg_r0_4, reg_r0_22); /* line 1997 */
} /* line 1997 */
  sim_icache_fetch(1250 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_23); /* line 1999 */
   MOV(reg_r0_21, reg_r0_20); /* line 2000 */
} /* line 2000 */
  sim_icache_fetch(1252 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_17); /* line 2002 */
} /* line 2002 */
l_L76X3: ;/* line 2005 */
LABEL(l_L76X3);
  sim_icache_fetch(1253 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 2006 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 215); /* line 2007 */
} /* line 2007 */
  sim_icache_fetch(1255 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 2009 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -155); /* line 2010 */
} /* line 2010 */
  sim_icache_fetch(1257 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2012 */
   LDWs(reg_r0_12, mem_trace_ld(reg_r0_8,0,4)); /* line 2013 */
} /* line 2013 */
  sim_icache_fetch(1259 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -48); /* line 2015 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 8); /* line 2016 */
} /* line 2016 */
  sim_icache_fetch(1261 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_9, (unsigned int) 2); /* line 2018 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 2019 */
} /* line 2019 */
  sim_icache_fetch(1263 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_5); /* line 2021 */
   CMPLT(reg_b0_1, reg_r0_9, (unsigned int) 1); /* line 2022 */
} /* line 2022 */
  sim_icache_fetch(1265 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_13); /* line 2024 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2025 */
  sim_icache_fetch(1267 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_7, reg_r0_12); /* line 2027 */
   LDBUs(reg_r0_5, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 2028 */
} /* line 2028 */
  sim_icache_fetch(1269 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2030 */
   MULL(reg_r0_13, reg_r0_7, (unsigned int) 215); /* line 2031 */
} /* line 2031 */
  sim_icache_fetch(1271 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2033 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2034 */
} /* line 2034 */
  sim_icache_fetch(1273 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -48); /* line 2036 */
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2037 */
} /* line 2037 */
  sim_icache_fetch(1275 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2039 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2040 */
} /* line 2040 */
  sim_icache_fetch(1277 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_13); /* line 2042 */
   LDWs(reg_r0_13, mem_trace_ld((reg_r0_8 + (unsigned int) 4),0,4)); /* line 2043 */
} /* line 2043 */
  sim_icache_fetch(1279 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 2045 */
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 2046 */
} /* line 2046 */
  sim_icache_fetch(1281 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_14); /* line 2048 */
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 2049 */
} /* line 2049 */
  sim_icache_fetch(1283 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_3, reg_r0_13); /* line 2051 */
   MULL(reg_r0_15, reg_r0_3, (unsigned int) 215); /* line 2052 */
} /* line 2052 */
  sim_icache_fetch(1285 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2054 */
   MULL(reg_r0_16, reg_r0_7, (unsigned int) -155); /* line 2055 */
} /* line 2055 */
  sim_icache_fetch(1287 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2057 */
   MULL(reg_r0_17, reg_r0_14, (unsigned int) -48); /* line 2058 */
} /* line 2058 */
  sim_icache_fetch(1289 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2060 */
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 2061 */
} /* line 2061 */
  sim_icache_fetch(1291 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 28); /* line 2063 */
   ADD(reg_r0_17, reg_r0_17, reg_r0_15); /* line 2064 */
} /* line 2064 */
  sim_icache_fetch(1293 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_3); /* line 2066 */
   LDWs(reg_r0_15, mem_trace_ld((reg_r0_8 + (unsigned int) 8),0,4)); /* line 2067 */
} /* line 2067 */
  sim_icache_fetch(1295 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_16); /* line 2069 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 3); /* line 2070 */
} /* line 2070 */
  sim_icache_fetch(1297 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_5, reg_r0_17); /* line 2072 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 12); /* line 2073 */
} /* line 2073 */
  sim_icache_fetch(1299 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_15, reg_r0_4, reg_r0_15); /* line 2075 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 3); /* line 2076 */
} /* line 2076 */
  sim_icache_fetch(1301 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_11,0,4), reg_r0_7); /* line 2078 */
   SHL(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2079 */
} /* line 2079 */
  sim_icache_fetch(1303 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2081 */
   MOV(reg_r0_7, reg_r0_14); /* line 2082 */
} /* line 2082 */
  sim_icache_fetch(1305 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_12); /* line 2084 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2085 */
  sim_icache_fetch(1307 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 4),0,4), reg_r0_3); /* line 2087 */
} /* line 2087 */
  sim_icache_fetch(1308 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4),0,4), reg_r0_13); /* line 2089 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2090 */
  sim_icache_fetch(1310 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 8),0,4), reg_r0_4); /* line 2092 */
   ADD(reg_r0_11, reg_r0_11, (unsigned int) 12); /* line 2093 */
} /* line 2093 */
  sim_icache_fetch(1312 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 8),0,4), reg_r0_15); /* line 2095 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 12); /* line 2097 */
} /* line 2097 */
  sim_icache_fetch(1314 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L76X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L76X3;
} /* line 2099 */
l_L77X3: ;/* line 2102 */
LABEL(l_L77X3);
  sim_icache_fetch(1315 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_24, reg_r0_24, (unsigned int) 4200); /* line 2103 */
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 1050); /* line 2104 */
} /* line 2104 */
  sim_icache_fetch(1319 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_20, (unsigned int) 1); /* line 2106 */
   ADD(reg_r0_10, reg_r0_18, (unsigned int) 1050); /* line 2107 */
} /* line 2107 */
  sim_icache_fetch(1322 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_12, reg_r0_21); /* line 2109 */
   MOV(reg_r0_11, reg_r0_19); /* line 2111 */
} /* line 2111 */
  sim_icache_fetch(1324 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L72X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L72X3;
} /* line 2113 */
l_L73X3: ;/* line 2116 */
LABEL(l_L73X3);
  sim_icache_fetch(1325 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_12, 0, reg_r0_12); /* line 2117 */
   MOV(reg_r0_23, (unsigned int) at); /* line 2118 */
} /* line 2118 */
  sim_icache_fetch(1328 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_12); /* line 2120 */
   MOV(reg_r0_22, (unsigned int) out); /* line 2121 */
} /* line 2121 */
  sim_icache_fetch(1331 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_26, (unsigned int) -1); /* line 2123 */
   MOV(reg_r0_12, ((unsigned int) at + (unsigned int) -12600)); /* line 2124 */
} /* line 2124 */
  sim_icache_fetch(1334 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_26); /* line 2126 */
} /* line 2126 */
l_L78X3: ;/* line 2129 */
LABEL(l_L78X3);
  sim_icache_fetch(1335 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 2130 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 4200); /* line 2131 */
} /* line 2131 */
  sim_icache_fetch(1338 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 2133 */
   SH2ADD(reg_r0_8, reg_r0_13, ((unsigned int) by2 + (unsigned int) -16)); /* line 2134 */
} /* line 2134 */
  sim_icache_fetch(1341 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 2136 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2137 */
  sim_icache_fetch(1343 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, 0); /* line 2139 */
   MOV(reg_r0_5, 0); /* line 2140 */
} /* line 2140 */
  sim_icache_fetch(1345 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, 0); /* line 2142 */
   MOV(reg_r0_2, 0); /* line 2143 */
} /* line 2143 */
  sim_icache_fetch(1347 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, 0); /* line 2145 */
   MOV(reg_r0_20, 0); /* line 2146 */
} /* line 2146 */
  sim_icache_fetch(1349 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_10); /* line 2148 */
   MOV(reg_r0_15, reg_r0_4); /* line 2149 */
} /* line 2149 */
  sim_icache_fetch(1351 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_16, reg_r0_10); /* line 2151 */
   MOV(reg_r0_17, reg_r0_12); /* line 2152 */
} /* line 2152 */
  sim_icache_fetch(1353 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_13); /* line 2154 */
} /* line 2154 */
l_L80X3: ;/* line 2157 */
LABEL(l_L80X3);
  sim_icache_fetch(1354 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2158 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 2159 */
} /* line 2159 */
  sim_icache_fetch(1356 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 2161 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 29); /* line 2162 */
} /* line 2162 */
  sim_icache_fetch(1358 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2164 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2165 */
} /* line 2165 */
  sim_icache_fetch(1360 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 2167 */
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 12600),0,4)); /* line 2168 */
} /* line 2168 */
  sim_icache_fetch(1363 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 2170 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2171 */
  sim_icache_fetch(1365 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2173 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2174 */
} /* line 2174 */
  sim_icache_fetch(1367 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2176 */
   MULL(reg_r0_10, reg_r0_4, (unsigned int) -47); /* line 2177 */
} /* line 2177 */
  sim_icache_fetch(1369 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 2179 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 2180 */
} /* line 2180 */
  sim_icache_fetch(1371 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 2182 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 8400),0,4)); /* line 2183 */
} /* line 2183 */
  sim_icache_fetch(1374 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 2185 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2186 */
} /* line 2186 */
  sim_icache_fetch(1376 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 2188 */
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 2189 */
} /* line 2189 */
  sim_icache_fetch(1378 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2191 */
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 2192 */
} /* line 2192 */
  sim_icache_fetch(1380 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_5, (unsigned int) 215); /* line 2194 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 29); /* line 2195 */
} /* line 2195 */
  sim_icache_fetch(1382 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 2197 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,4)); /* line 2198 */
} /* line 2198 */
  sim_icache_fetch(1385 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_4); /* line 2200 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2201 */
} /* line 2201 */
  sim_icache_fetch(1387 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 2203 */
   MULL(reg_r0_4, reg_r0_5, (unsigned int) -155); /* line 2204 */
} /* line 2204 */
  sim_icache_fetch(1389 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2206 */
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 2207 */
} /* line 2207 */
  sim_icache_fetch(1391 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 2209 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 2210 */
} /* line 2210 */
  sim_icache_fetch(1393 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 2212 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_9,0,4)); /* line 2213 */
} /* line 2213 */
  sim_icache_fetch(1395 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_12); /* line 2215 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 2216 */
} /* line 2216 */
  sim_icache_fetch(1397 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 2218 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 2219 */
} /* line 2219 */
  sim_icache_fetch(1399 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_2); /* line 2221 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2222 */
} /* line 2222 */
  sim_icache_fetch(1401 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_11); /* line 2224 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L82X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2225 */
  sim_icache_fetch(1403 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_5); /* line 2227 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -16800); /* line 2228 */
} /* line 2228 */
  sim_icache_fetch(1406 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_4); /* line 2230 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L83X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2231 */
  sim_icache_fetch(1408 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_11); /* line 2233 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L84X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2234 */
  sim_icache_fetch(1410 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 2236 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 2238 */
} /* line 2238 */
  sim_icache_fetch(1412 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L80X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L80X3;
} /* line 2240 */
l_L84X3: ;/* line 2243 */
LABEL(l_L84X3);
  sim_icache_fetch(1413 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 2244 */
   MOV(reg_r0_9, reg_r0_22); /* line 2246 */
} /* line 2246 */
  sim_icache_fetch(1415 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L85X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L85X3;
} /* line 2248 */
l_L86X3: ;/* line 2251 */
LABEL(l_L86X3);
  sim_icache_fetch(1416 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2252 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2253 */
} /* line 2253 */
  sim_icache_fetch(1418 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_5, (unsigned int) 215); /* line 2255 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 2256 */
} /* line 2256 */
  sim_icache_fetch(1420 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 2258 */
   LDWs(reg_r0_12, mem_trace_ld(reg_r0_7,0,4)); /* line 2259 */
} /* line 2259 */
  sim_icache_fetch(1422 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -48); /* line 2261 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_6); /* line 2262 */
} /* line 2262 */
  sim_icache_fetch(1424 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, 0); /* line 2264 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L87X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2265 */
  sim_icache_fetch(1426 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 2267 */
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 2268 */
} /* line 2268 */
  sim_icache_fetch(1429 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_11); /* line 2270 */
   MULL(reg_r0_13, reg_r0_5, (unsigned int) -155); /* line 2271 */
} /* line 2271 */
  sim_icache_fetch(1431 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2273 */
   MULL(reg_r0_11, reg_r0_3, (unsigned int) 28); /* line 2274 */
} /* line 2274 */
  sim_icache_fetch(1433 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_4, reg_r0_12); /* line 2276 */
   MULL(reg_r0_14, reg_r0_6, (unsigned int) -48); /* line 2277 */
} /* line 2277 */
  sim_icache_fetch(1435 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2279 */
   MULL(reg_r0_15, reg_r0_4, (unsigned int) 215); /* line 2280 */
} /* line 2280 */
  sim_icache_fetch(1437 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 2282 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_14); /* line 2283 */
} /* line 2283 */
  sim_icache_fetch(1439 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_14, reg_r0_12); /* line 2285 */
   ADD(reg_r0_15, reg_r0_15, reg_r0_11); /* line 2286 */
} /* line 2286 */
  sim_icache_fetch(1441 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_1, reg_r0_14, (unsigned int) 25); /* line 2288 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 2289 */
} /* line 2289 */
  sim_icache_fetch(1443 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_15, reg_r0_4); /* line 2291 */
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_7 + (unsigned int) 4),0,4)); /* line 2292 */
} /* line 2292 */
  sim_icache_fetch(1445 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_12); /* line 2294 */
} /* line 2294 */
  sim_icache_fetch(1446 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_4); /* line 2296 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L88X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2297 */
  sim_icache_fetch(1448 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_13, (unsigned int) 8); /* line 2299 */
   MOV(reg_r0_4, reg_r0_15); /* line 2300 */
} /* line 2300 */
  sim_icache_fetch(1450 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), 0); /* line 2302 */
   ADD(reg_r0_11, reg_r0_5, reg_r0_11); /* line 2303 */
} /* line 2303 */
l_L89X3: ;/* line 2305 */
LABEL(l_L89X3);
  sim_icache_fetch(1452 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2306 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2307 */
  sim_icache_fetch(1454 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4),0,4), reg_r0_5); /* line 2309 */
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 2310 */
} /* line 2310 */
  sim_icache_fetch(1456 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_11); /* line 2312 */
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_11); /* line 2313 */
} /* line 2313 */
  sim_icache_fetch(1459 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 2315 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 2316 */
   ADD_CYCLES(1);
} /* line 2316 */
  sim_icache_fetch(1461 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L91X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2318 */
  sim_icache_fetch(1462 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2320 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 8400); /* line 2321 */
} /* line 2321 */
  sim_icache_fetch(1465 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 2323 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 2324 */
} /* line 2324 */
  sim_icache_fetch(1467 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), 0); /* line 2326 */
} /* line 2326 */
l_L92X3: ;/* line 2328 */
LABEL(l_L92X3);
  sim_icache_fetch(1469 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 2100); /* line 2329 */
   GOTO(l_L86X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L86X3;
} /* line 2330 */
l_L91X3: ;/* line 2333 */
LABEL(l_L91X3);
  sim_icache_fetch(1472 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 2334 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 2335 */
} /* line 2335 */
  sim_icache_fetch(1474 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 2337 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2338 */
} /* line 2338 */
  sim_icache_fetch(1476 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_3); /* line 2340 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 8400); /* line 2342 */
} /* line 2342 */
  sim_icache_fetch(1480 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L92X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L92X3;
} /* line 2344 */
l_L90X3: ;/* line 2347 */
LABEL(l_L90X3);
  sim_icache_fetch(1481 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_22, reg_r0_22, (unsigned int) 1); /* line 2348 */
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 4); /* line 2350 */
} /* line 2350 */
  sim_icache_fetch(1483 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L93X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L93X3;
} /* line 2352 */
l_L88X3: ;/* line 2355 */
LABEL(l_L88X3);
  sim_icache_fetch(1484 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_13, (unsigned int) 8); /* line 2356 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 2357 */
} /* line 2357 */
  sim_icache_fetch(1486 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_5, reg_r0_11); /* line 2359 */
   MOV(reg_r0_4, reg_r0_15); /* line 2360 */
} /* line 2360 */
  sim_icache_fetch(1488 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_3); /* line 2362 */
   GOTO(l_L89X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L89X3;
} /* line 2363 */
l_L87X3: ;/* line 2366 */
LABEL(l_L87X3);
  sim_icache_fetch(1490 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_22, reg_r0_22, (unsigned int) 1); /* line 2367 */
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 4); /* line 2368 */
} /* line 2368 */
l_L93X3: ;/* line 2370 */
LABEL(l_L93X3);
  sim_icache_fetch(1492 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_18, (unsigned int) 1); /* line 2371 */
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 2372 */
} /* line 2372 */
  sim_icache_fetch(1494 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, reg_r0_16); /* line 2374 */
   MOV(reg_r0_13, reg_r0_19); /* line 2376 */
} /* line 2376 */
  sim_icache_fetch(1496 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L78X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L78X3;
} /* line 2378 */
l_L83X3: ;/* line 2381 */
LABEL(l_L83X3);
  sim_icache_fetch(1497 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 2382 */
   MOV(reg_r0_9, reg_r0_22); /* line 2384 */
} /* line 2384 */
  sim_icache_fetch(1499 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L85X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L85X3;
} /* line 2386 */
l_L82X3: ;/* line 2389 */
LABEL(l_L82X3);
  sim_icache_fetch(1500 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 2390 */
   MOV(reg_r0_9, reg_r0_22); /* line 2392 */
} /* line 2392 */
  sim_icache_fetch(1502 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L85X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L85X3;
} /* line 2394 */
l_L81X3: ;/* line 2397 */
LABEL(l_L81X3);
  sim_icache_fetch(1503 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 2398 */
   MOV(reg_r0_9, reg_r0_22); /* line 2399 */
} /* line 2399 */
l_L85X3: ;/* line 2401 */
LABEL(l_L85X3);
  sim_icache_fetch(1505 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_3); /* line 2402 */
   MOV(reg_r0_7, (unsigned int) by2); /* line 2403 */
} /* line 2403 */
  sim_icache_fetch(1508 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, (unsigned int) by1); /* line 2405 */
   MOV(reg_r0_2, reg_r0_23); /* line 2406 */
} /* line 2406 */
  sim_icache_fetch(1511 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_20); /* line 2408 */
   MOV(reg_r0_5, reg_r0_19); /* line 2409 */
} /* line 2409 */
  sim_icache_fetch(1513 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_21); /* line 2411 */
   MOV(reg_r0_19, reg_r0_18); /* line 2412 */
} /* line 2412 */
  sim_icache_fetch(1515 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_18, reg_r0_15); /* line 2414 */
   GOTO(l_L86X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L86X3;
} /* line 2415 */
l_L79X3: ;/* line 2418 */
LABEL(l_L79X3);
  sim_icache_fetch(1517 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_array);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2420 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 248: goto l_L72X3;
    case 249: goto l_L74X3;
    case 250: goto l_L75X3;
    case 251: goto l_L76X3;
    case 252: goto l_L77X3;
    case 253: goto l_L73X3;
    case 254: goto l_L78X3;
    case 255: goto l_L80X3;
    case 256: goto l_L84X3;
    case 257: goto l_L86X3;
    case 258: goto l_L89X3;
    case 259: goto l_L92X3;
    case 260: goto l_L91X3;
    case 261: goto l_L90X3;
    case 262: goto l_L88X3;
    case 263: goto l_L87X3;
    case 264: goto l_L93X3;
    case 265: goto l_L83X3;
    case 266: goto l_L82X3;
    case 267: goto l_L81X3;
    case 268: goto l_L85X3;
    case 269: goto l_L79X3;
    case 270:
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
  reg_l0_0 = (293 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1518 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 2436 */
} /* line 2436 */
  sim_icache_fetch(1519 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_27, (unsigned int) qy1); /* line 2438 */
   MOV(reg_r0_28, (unsigned int) in); /* line 2439 */
} /* line 2439 */
  sim_icache_fetch(1523 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_4 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_2); /* line 2441 */
   MOV(reg_r0_24, t__i32_0); /* line 2442 */
} /* line 2442 */
  sim_icache_fetch(1525 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_25, (unsigned int) qt); /* line 2444 */
   MOV(reg_r0_26, (unsigned int) qy2); /* line 2445 */
} /* line 2445 */
  sim_icache_fetch(1529 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_24, (unsigned int) -1); /* line 2447 */
   MOV(reg_r0_12, ((unsigned int) qy2 + (unsigned int) -12)); /* line 2448 */
} /* line 2448 */
  sim_icache_fetch(1532 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 2450 */
   MOV(reg_r0_29, reg_r0_3); /* line 2451 */
} /* line 2451 */
l_L94X3: ;/* line 2454 */
LABEL(l_L94X3);
  sim_icache_fetch(1535 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 2455 */
   ADD(reg_r0_9, reg_r0_10, reg_r0_11); /* line 2456 */
} /* line 2456 */
  sim_icache_fetch(1537 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 2458 */
   SH2ADD(reg_r0_8, reg_r0_11, reg_r0_12); /* line 2459 */
} /* line 2459 */
  sim_icache_fetch(1539 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 2461 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2462 */
  sim_icache_fetch(1541 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 2464 */
   MOV(reg_r0_6, 0); /* line 2465 */
} /* line 2465 */
  sim_icache_fetch(1543 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_22, 0); /* line 2467 */
   MOV(reg_r0_21, 0); /* line 2468 */
} /* line 2468 */
  sim_icache_fetch(1545 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_23, 0); /* line 2470 */
   MOV(reg_r0_7, reg_r0_11); /* line 2471 */
} /* line 2471 */
  sim_icache_fetch(1547 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_4); /* line 2473 */
   MOV(reg_r0_18, reg_r0_10); /* line 2474 */
} /* line 2474 */
  sim_icache_fetch(1549 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, reg_r0_11); /* line 2476 */
   MOV(reg_r0_20, reg_r0_12); /* line 2477 */
} /* line 2477 */
l_L96X3: ;/* line 2480 */
LABEL(l_L96X3);
  sim_icache_fetch(1551 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 2481 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2482 */
} /* line 2482 */
  sim_icache_fetch(1553 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -48); /* line 2484 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 2485 */
} /* line 2485 */
  sim_icache_fetch(1555 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2487 */
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2488 */
} /* line 2488 */
  sim_icache_fetch(1557 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2490 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_2); /* line 2491 */
} /* line 2491 */
  sim_icache_fetch(1559 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 2493 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2494 */
  sim_icache_fetch(1561 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2496 */
   LDBU(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 3),0,1)); /* line 2497 */
} /* line 2497 */
  sim_icache_fetch(1563 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2499 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2500 */
} /* line 2500 */
  sim_icache_fetch(1565 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 2502 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) 215); /* line 2503 */
} /* line 2503 */
  sim_icache_fetch(1567 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 2505 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2506 */
} /* line 2506 */
  sim_icache_fetch(1569 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2508 */
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_9 + (unsigned int) 2),0,1)); /* line 2509 */
} /* line 2509 */
  sim_icache_fetch(1571 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_5); /* line 2511 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2512 */
} /* line 2512 */
  sim_icache_fetch(1573 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 2514 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2515 */
} /* line 2515 */
  sim_icache_fetch(1575 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_13, (unsigned int) -47); /* line 2517 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) -155); /* line 2518 */
} /* line 2518 */
  sim_icache_fetch(1577 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 2520 */
   MULL(reg_r0_15, reg_r0_12, (unsigned int) 215); /* line 2521 */
} /* line 2521 */
  sim_icache_fetch(1579 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2523 */
   LDBUs(reg_r0_16, mem_trace_ld((reg_r0_9 + (unsigned int) 1),0,1)); /* line 2524 */
} /* line 2524 */
  sim_icache_fetch(1581 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2526 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_11); /* line 2527 */
} /* line 2527 */
  sim_icache_fetch(1583 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_15); /* line 2529 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2530 */
} /* line 2530 */
  sim_icache_fetch(1585 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 2532 */
   MULL(reg_r0_10, reg_r0_12, (unsigned int) -155); /* line 2533 */
} /* line 2533 */
  sim_icache_fetch(1587 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_16, (unsigned int) -47); /* line 2535 */
   MULL(reg_r0_15, reg_r0_14, (unsigned int) 215); /* line 2536 */
} /* line 2536 */
  sim_icache_fetch(1589 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_13, (unsigned int) -48); /* line 2538 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2539 */
} /* line 2539 */
  sim_icache_fetch(1591 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2541 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 2542 */
} /* line 2542 */
  sim_icache_fetch(1593 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 2544 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_9,0,1)); /* line 2545 */
} /* line 2545 */
  sim_icache_fetch(1595 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_14); /* line 2547 */
   ADD(reg_r0_5, reg_r0_11, reg_r0_13); /* line 2548 */
} /* line 2548 */
  sim_icache_fetch(1597 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_16); /* line 2550 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 2551 */
} /* line 2551 */
  sim_icache_fetch(1599 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 2553 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -4); /* line 2554 */
} /* line 2554 */
  sim_icache_fetch(1601 + t_thisfile.offset, 1);
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
} /* line 2556 */
  sim_icache_fetch(1602 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_12); /* line 2558 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2559 */
  sim_icache_fetch(1604 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_14); /* line 2561 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2562 */
  sim_icache_fetch(1606 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_5); /* line 2564 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 2566 */
} /* line 2566 */
  sim_icache_fetch(1608 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L96X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L96X3;
} /* line 2568 */
l_L97X3: ;/* line 2571 */
LABEL(l_L97X3);
  sim_icache_fetch(1609 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_24); /* line 2572 */
   MOV(reg_r0_10, reg_r0_25); /* line 2573 */
} /* line 2573 */
  sim_icache_fetch(1611 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_3); /* line 2575 */
   MOV(reg_r0_8, reg_r0_26); /* line 2576 */
} /* line 2576 */
  sim_icache_fetch(1613 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, reg_r0_27); /* line 2578 */
   MOV(reg_r0_2, reg_r0_28); /* line 2579 */
} /* line 2579 */
  sim_icache_fetch(1615 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_21); /* line 2581 */
   MOV(reg_r0_4, reg_r0_22); /* line 2582 */
} /* line 2582 */
  sim_icache_fetch(1617 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, reg_r0_17); /* line 2584 */
   MOV(reg_r0_6, reg_r0_23); /* line 2585 */
} /* line 2585 */
l_L98X3: ;/* line 2588 */
LABEL(l_L98X3);
  sim_icache_fetch(1619 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 2589 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 215); /* line 2590 */
} /* line 2590 */
  sim_icache_fetch(1621 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 2592 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -155); /* line 2593 */
} /* line 2593 */
  sim_icache_fetch(1623 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2595 */
   LDWs(reg_r0_12, mem_trace_ld(reg_r0_8,0,4)); /* line 2596 */
} /* line 2596 */
  sim_icache_fetch(1625 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -48); /* line 2598 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 8); /* line 2599 */
} /* line 2599 */
  sim_icache_fetch(1627 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_9, (unsigned int) 2); /* line 2601 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 2602 */
} /* line 2602 */
  sim_icache_fetch(1629 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_5); /* line 2604 */
   CMPLT(reg_b0_1, reg_r0_9, (unsigned int) 1); /* line 2605 */
} /* line 2605 */
  sim_icache_fetch(1631 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_13); /* line 2607 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2608 */
  sim_icache_fetch(1633 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_7, reg_r0_12); /* line 2610 */
   LDBUs(reg_r0_5, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 2611 */
} /* line 2611 */
  sim_icache_fetch(1635 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2613 */
   MULL(reg_r0_13, reg_r0_7, (unsigned int) 215); /* line 2614 */
} /* line 2614 */
  sim_icache_fetch(1637 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2616 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2617 */
} /* line 2617 */
  sim_icache_fetch(1639 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -48); /* line 2619 */
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2620 */
} /* line 2620 */
  sim_icache_fetch(1641 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2622 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2623 */
} /* line 2623 */
  sim_icache_fetch(1643 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_13); /* line 2625 */
   LDWs(reg_r0_13, mem_trace_ld((reg_r0_8 + (unsigned int) 4),0,4)); /* line 2626 */
} /* line 2626 */
  sim_icache_fetch(1645 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 2628 */
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 2629 */
} /* line 2629 */
  sim_icache_fetch(1647 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_14); /* line 2631 */
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 2632 */
} /* line 2632 */
  sim_icache_fetch(1649 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_3, reg_r0_13); /* line 2634 */
   MULL(reg_r0_15, reg_r0_3, (unsigned int) 215); /* line 2635 */
} /* line 2635 */
  sim_icache_fetch(1651 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2637 */
   MULL(reg_r0_16, reg_r0_7, (unsigned int) -155); /* line 2638 */
} /* line 2638 */
  sim_icache_fetch(1653 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2640 */
   MULL(reg_r0_17, reg_r0_14, (unsigned int) -48); /* line 2641 */
} /* line 2641 */
  sim_icache_fetch(1655 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2643 */
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 2644 */
} /* line 2644 */
  sim_icache_fetch(1657 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 28); /* line 2646 */
   ADD(reg_r0_17, reg_r0_17, reg_r0_15); /* line 2647 */
} /* line 2647 */
  sim_icache_fetch(1659 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_3); /* line 2649 */
   LDWs(reg_r0_15, mem_trace_ld((reg_r0_8 + (unsigned int) 8),0,4)); /* line 2650 */
} /* line 2650 */
  sim_icache_fetch(1661 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_16); /* line 2652 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 3); /* line 2653 */
} /* line 2653 */
  sim_icache_fetch(1663 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_5, reg_r0_17); /* line 2655 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 12); /* line 2656 */
} /* line 2656 */
  sim_icache_fetch(1665 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_15, reg_r0_4, reg_r0_15); /* line 2658 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 3); /* line 2659 */
} /* line 2659 */
  sim_icache_fetch(1667 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_11,0,4), reg_r0_7); /* line 2661 */
   SHL(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2662 */
} /* line 2662 */
  sim_icache_fetch(1669 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2664 */
   MOV(reg_r0_7, reg_r0_14); /* line 2665 */
} /* line 2665 */
  sim_icache_fetch(1671 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_12); /* line 2667 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2668 */
  sim_icache_fetch(1673 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 4),0,4), reg_r0_3); /* line 2670 */
} /* line 2670 */
  sim_icache_fetch(1674 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4),0,4), reg_r0_13); /* line 2672 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2673 */
  sim_icache_fetch(1676 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 8),0,4), reg_r0_4); /* line 2675 */
   ADD(reg_r0_11, reg_r0_11, (unsigned int) 12); /* line 2676 */
} /* line 2676 */
  sim_icache_fetch(1678 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 8),0,4), reg_r0_15); /* line 2678 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 12); /* line 2680 */
} /* line 2680 */
  sim_icache_fetch(1680 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L98X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L98X3;
} /* line 2682 */
l_L99X3: ;/* line 2685 */
LABEL(l_L99X3);
  sim_icache_fetch(1681 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_28, reg_r0_28, (unsigned int) 1050); /* line 2686 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2687 */
} /* line 2687 */
  sim_icache_fetch(1685 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_26, reg_r0_26, reg_r0_2); /* line 2689 */
   ADD(reg_r0_27, reg_r0_27, reg_r0_2); /* line 2690 */
} /* line 2690 */
  sim_icache_fetch(1687 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_25, reg_r0_25, reg_r0_2); /* line 2692 */
   ADD(reg_r0_12, reg_r0_20, reg_r0_2); /* line 2693 */
} /* line 2693 */
  sim_icache_fetch(1689 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 2695 */
   ADD(reg_r0_10, reg_r0_18, (unsigned int) 1050); /* line 2696 */
} /* line 2696 */
  sim_icache_fetch(1692 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, reg_r0_19); /* line 2698 */
   GOTO(l_L94X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L94X3;
} /* line 2699 */
l_L95X3: ;/* line 2702 */
LABEL(l_L95X3);
  sim_icache_fetch(1694 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_24, 0, reg_r0_24); /* line 2703 */
   MOV(reg_r0_26, (unsigned int) qt); /* line 2704 */
} /* line 2704 */
  sim_icache_fetch(1697 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_24); /* line 2706 */
   MOV(reg_r0_25, (unsigned int) qy1); /* line 2707 */
} /* line 2707 */
  sim_icache_fetch(1700 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_23, (unsigned int) out); /* line 2709 */
   MOV(reg_r0_24, (unsigned int) qy2); /* line 2710 */
} /* line 2710 */
  sim_icache_fetch(1704 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_13, ((unsigned int) qy2 + (unsigned int) -12600)); /* line 2712 */
   MOV(reg_r0_12, ((unsigned int) qt + (unsigned int) -12600)); /* line 2713 */
} /* line 2713 */
  sim_icache_fetch(1708 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_29, (unsigned int) -1); /* line 2715 */
   MOV(reg_r0_22, reg_r0_29); /* line 2716 */
} /* line 2716 */
l_L100X3: ;/* line 2719 */
LABEL(l_L100X3);
  sim_icache_fetch(1710 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 2720 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 4200); /* line 2721 */
} /* line 2721 */
  sim_icache_fetch(1713 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 2723 */
   MOV(reg_r0_6, 0); /* line 2724 */
} /* line 2724 */
  sim_icache_fetch(1715 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 2726 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2727 */
  sim_icache_fetch(1717 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 2729 */
   ADD(reg_r0_8, reg_r0_13, reg_r0_11); /* line 2730 */
} /* line 2730 */
  sim_icache_fetch(1719 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, 0); /* line 2732 */
   MOV(reg_r0_2, 0); /* line 2733 */
} /* line 2733 */
  sim_icache_fetch(1721 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, 0); /* line 2735 */
   MOV(reg_r0_20, 0); /* line 2736 */
} /* line 2736 */
  sim_icache_fetch(1723 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_10); /* line 2738 */
   MOV(reg_r0_15, reg_r0_4); /* line 2739 */
} /* line 2739 */
  sim_icache_fetch(1725 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_16, reg_r0_10); /* line 2741 */
   MOV(reg_r0_17, reg_r0_12); /* line 2742 */
} /* line 2742 */
  sim_icache_fetch(1727 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_13); /* line 2744 */
} /* line 2744 */
l_L102X3: ;/* line 2747 */
LABEL(l_L102X3);
  sim_icache_fetch(1728 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2748 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 2749 */
} /* line 2749 */
  sim_icache_fetch(1730 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 2751 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 29); /* line 2752 */
} /* line 2752 */
  sim_icache_fetch(1732 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2754 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2755 */
} /* line 2755 */
  sim_icache_fetch(1734 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 2757 */
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 12600),0,4)); /* line 2758 */
} /* line 2758 */
  sim_icache_fetch(1737 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 2760 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2761 */
  sim_icache_fetch(1739 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2763 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2764 */
} /* line 2764 */
  sim_icache_fetch(1741 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2766 */
   MULL(reg_r0_10, reg_r0_4, (unsigned int) -47); /* line 2767 */
} /* line 2767 */
  sim_icache_fetch(1743 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 2769 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 2770 */
} /* line 2770 */
  sim_icache_fetch(1745 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 2772 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 8400),0,4)); /* line 2773 */
} /* line 2773 */
  sim_icache_fetch(1748 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 2775 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2776 */
} /* line 2776 */
  sim_icache_fetch(1750 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 2778 */
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 2779 */
} /* line 2779 */
  sim_icache_fetch(1752 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2781 */
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 2782 */
} /* line 2782 */
  sim_icache_fetch(1754 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_5, (unsigned int) 215); /* line 2784 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 29); /* line 2785 */
} /* line 2785 */
  sim_icache_fetch(1756 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 2787 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,4)); /* line 2788 */
} /* line 2788 */
  sim_icache_fetch(1759 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_4); /* line 2790 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2791 */
} /* line 2791 */
  sim_icache_fetch(1761 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 2793 */
   MULL(reg_r0_4, reg_r0_5, (unsigned int) -155); /* line 2794 */
} /* line 2794 */
  sim_icache_fetch(1763 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2796 */
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 2797 */
} /* line 2797 */
  sim_icache_fetch(1765 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 2799 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 2800 */
} /* line 2800 */
  sim_icache_fetch(1767 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 2802 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_9,0,4)); /* line 2803 */
} /* line 2803 */
  sim_icache_fetch(1769 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 2805 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 2806 */
} /* line 2806 */
  sim_icache_fetch(1771 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_2); /* line 2808 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 2809 */
} /* line 2809 */
  sim_icache_fetch(1774 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2811 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2812 */
  sim_icache_fetch(1776 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_11); /* line 2814 */
   MOV(reg_r0_6, reg_r0_12); /* line 2815 */
} /* line 2815 */
  sim_icache_fetch(1778 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_5); /* line 2817 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -16800); /* line 2818 */
} /* line 2818 */
  sim_icache_fetch(1782 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_4); /* line 2820 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2821 */
  sim_icache_fetch(1784 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_11); /* line 2823 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2824 */
  sim_icache_fetch(1787 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 2826 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16800); /* line 2828 */
} /* line 2828 */
  sim_icache_fetch(1790 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L102X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L102X3;
} /* line 2830 */
l_L106X3: ;/* line 2833 */
LABEL(l_L106X3);
  sim_icache_fetch(1791 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_22); /* line 2834 */
   MOV(reg_r0_9, reg_r0_23); /* line 2836 */
} /* line 2836 */
  sim_icache_fetch(1793 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L107X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L107X3;
} /* line 2838 */
l_L108X3: ;/* line 2841 */
LABEL(l_L108X3);
  sim_icache_fetch(1794 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2842 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2843 */
} /* line 2843 */
  sim_icache_fetch(1796 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_5, (unsigned int) 215); /* line 2845 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 2846 */
} /* line 2846 */
  sim_icache_fetch(1798 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 2848 */
   LDWs(reg_r0_13, mem_trace_ld(reg_r0_7,0,4)); /* line 2849 */
} /* line 2849 */
  sim_icache_fetch(1800 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_3, (unsigned int) -48); /* line 2851 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_6); /* line 2852 */
} /* line 2852 */
  sim_icache_fetch(1802 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, 0); /* line 2854 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2855 */
  sim_icache_fetch(1804 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 2857 */
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 2858 */
} /* line 2858 */
  sim_icache_fetch(1807 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_12); /* line 2860 */
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -155); /* line 2861 */
} /* line 2861 */
  sim_icache_fetch(1809 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2863 */
   MULL(reg_r0_12, reg_r0_3, (unsigned int) 28); /* line 2864 */
} /* line 2864 */
  sim_icache_fetch(1811 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_4, reg_r0_13); /* line 2866 */
   MULL(reg_r0_15, reg_r0_6, (unsigned int) -48); /* line 2867 */
} /* line 2867 */
  sim_icache_fetch(1813 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2869 */
   MULL(reg_r0_16, reg_r0_4, (unsigned int) 215); /* line 2870 */
} /* line 2870 */
  sim_icache_fetch(1815 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 2872 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_15); /* line 2873 */
} /* line 2873 */
  sim_icache_fetch(1817 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_15, reg_r0_13); /* line 2875 */
   ADD(reg_r0_16, reg_r0_16, reg_r0_12); /* line 2876 */
} /* line 2876 */
  sim_icache_fetch(1819 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_1, reg_r0_15, (unsigned int) 25); /* line 2878 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_16); /* line 2879 */
} /* line 2879 */
  sim_icache_fetch(1821 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_16, reg_r0_4); /* line 2881 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_7 + (unsigned int) 4200),0,4)); /* line 2882 */
} /* line 2882 */
  sim_icache_fetch(1824 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_13); /* line 2884 */
} /* line 2884 */
  sim_icache_fetch(1825 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_4); /* line 2886 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2887 */
  sim_icache_fetch(1827 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_14, (unsigned int) 8); /* line 2889 */
   MOV(reg_r0_4, reg_r0_16); /* line 2890 */
} /* line 2890 */
  sim_icache_fetch(1829 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), 0); /* line 2892 */
   ADD(reg_r0_12, reg_r0_5, reg_r0_12); /* line 2893 */
} /* line 2893 */
l_L111X3: ;/* line 2895 */
LABEL(l_L111X3);
  sim_icache_fetch(1831 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2896 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2897 */
  sim_icache_fetch(1833 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4200),0,4), reg_r0_5); /* line 2899 */
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 2900 */
} /* line 2900 */
  sim_icache_fetch(1836 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_12); /* line 2902 */
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_12); /* line 2903 */
} /* line 2903 */
  sim_icache_fetch(1839 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 2905 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 2906 */
   ADD_CYCLES(1);
} /* line 2906 */
  sim_icache_fetch(1841 + t_thisfile.offset, 1);
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
} /* line 2908 */
  sim_icache_fetch(1842 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 2910 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_11); /* line 2911 */
} /* line 2911 */
  sim_icache_fetch(1844 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 2913 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_11); /* line 2914 */
} /* line 2914 */
  sim_icache_fetch(1846 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), 0); /* line 2916 */
} /* line 2916 */
l_L114X3: ;/* line 2918 */
LABEL(l_L114X3);
  sim_icache_fetch(1848 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 2100); /* line 2919 */
   GOTO(l_L108X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L108X3;
} /* line 2920 */
l_L113X3: ;/* line 2923 */
LABEL(l_L113X3);
  sim_icache_fetch(1851 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 2924 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 2925 */
} /* line 2925 */
  sim_icache_fetch(1853 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_11); /* line 2927 */
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 2928 */
} /* line 2928 */
  sim_icache_fetch(1855 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_3); /* line 2930 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_11); /* line 2932 */
} /* line 2932 */
  sim_icache_fetch(1858 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L114X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L114X3;
} /* line 2934 */
l_L112X3: ;/* line 2937 */
LABEL(l_L112X3);
  sim_icache_fetch(1859 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 4); /* line 2938 */
   ADD(reg_r0_26, reg_r0_26, (unsigned int) 4); /* line 2940 */
} /* line 2940 */
  sim_icache_fetch(1861 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L115X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L115X3;
} /* line 2942 */
l_L110X3: ;/* line 2945 */
LABEL(l_L110X3);
  sim_icache_fetch(1862 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_14, (unsigned int) 8); /* line 2946 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 2947 */
} /* line 2947 */
  sim_icache_fetch(1864 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_5, reg_r0_12); /* line 2949 */
   MOV(reg_r0_4, reg_r0_16); /* line 2950 */
} /* line 2950 */
  sim_icache_fetch(1866 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_3); /* line 2952 */
   GOTO(l_L111X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L111X3;
} /* line 2953 */
l_L109X3: ;/* line 2956 */
LABEL(l_L109X3);
  sim_icache_fetch(1868 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 4); /* line 2957 */
   ADD(reg_r0_26, reg_r0_26, (unsigned int) 4); /* line 2958 */
} /* line 2958 */
l_L115X3: ;/* line 2960 */
LABEL(l_L115X3);
  sim_icache_fetch(1870 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 1); /* line 2961 */
   ADD(reg_r0_24, reg_r0_24, (unsigned int) 4); /* line 2962 */
} /* line 2962 */
  sim_icache_fetch(1872 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 2964 */
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 4); /* line 2965 */
} /* line 2965 */
  sim_icache_fetch(1874 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_20, (unsigned int) 1); /* line 2967 */
   MOV(reg_r0_10, reg_r0_17); /* line 2969 */
} /* line 2969 */
  sim_icache_fetch(1876 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L100X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L100X3;
} /* line 2971 */
l_L105X3: ;/* line 2974 */
LABEL(l_L105X3);
  sim_icache_fetch(1877 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_22); /* line 2975 */
   MOV(reg_r0_9, reg_r0_23); /* line 2977 */
} /* line 2977 */
  sim_icache_fetch(1879 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L107X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L107X3;
} /* line 2979 */
l_L104X3: ;/* line 2982 */
LABEL(l_L104X3);
  sim_icache_fetch(1880 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_22); /* line 2983 */
   MOV(reg_r0_9, reg_r0_23); /* line 2985 */
} /* line 2985 */
  sim_icache_fetch(1882 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L107X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L107X3;
} /* line 2987 */
l_L103X3: ;/* line 2990 */
LABEL(l_L103X3);
  sim_icache_fetch(1883 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_22); /* line 2991 */
   MOV(reg_r0_9, reg_r0_23); /* line 2992 */
} /* line 2992 */
l_L107X3: ;/* line 2994 */
LABEL(l_L107X3);
  sim_icache_fetch(1885 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_3); /* line 2995 */
   MOV(reg_r0_7, reg_r0_24); /* line 2996 */
} /* line 2996 */
  sim_icache_fetch(1887 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, reg_r0_25); /* line 2998 */
   MOV(reg_r0_2, reg_r0_26); /* line 2999 */
} /* line 2999 */
  sim_icache_fetch(1889 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_20); /* line 3001 */
   MOV(reg_r0_5, reg_r0_19); /* line 3002 */
} /* line 3002 */
  sim_icache_fetch(1891 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_21); /* line 3004 */
   MOV(reg_r0_11, (unsigned int) 8400); /* line 3005 */
} /* line 3005 */
  sim_icache_fetch(1894 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, reg_r0_17); /* line 3007 */
   MOV(reg_r0_20, reg_r0_15); /* line 3008 */
} /* line 3008 */
  sim_icache_fetch(1896 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_16); /* line 3010 */
   GOTO(l_L108X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L108X3;
} /* line 3011 */
l_L101X3: ;/* line 3014 */
LABEL(l_L101X3);
  sim_icache_fetch(1898 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_fused);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3016 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 271: goto l_L94X3;
    case 272: goto l_L96X3;
    case 273: goto l_L97X3;
    case 274: goto l_L98X3;
    case 275: goto l_L99X3;
    case 276: goto l_L95X3;
    case 277: goto l_L100X3;
    case 278: goto l_L102X3;
    case 279: goto l_L106X3;
    case 280: goto l_L108X3;
    case 281: goto l_L111X3;
    case 282: goto l_L114X3;
    case 283: goto l_L113X3;
    case 284: goto l_L112X3;
    case 285: goto l_L110X3;
    case 286: goto l_L109X3;
    case 287: goto l_L115X3;
    case 288: goto l_L105X3;
    case 289: goto l_L104X3;
    case 290: goto l_L103X3;
    case 291: goto l_L107X3;
    case 292: goto l_L101X3;
    case 293:
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
  reg_l0_0 = (342 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1899 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 3032 */
} /* line 3032 */
  sim_icache_fetch(1900 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, (unsigned int) qy1); /* line 3034 */
   MOV(reg_r0_12, (unsigned int) in); /* line 3035 */
} /* line 3035 */
  sim_icache_fetch(1904 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_2); /* line 3037 */
   MOV(reg_r0_19, t__i32_0); /* line 3038 */
} /* line 3038 */
  sim_icache_fetch(1906 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_4); /* line 3040 */
} /* line 3040 */
l_L116X3: ;/* line 3043 */
LABEL(l_L116X3);
  sim_icache_fetch(1907 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 3044 */
   SUB(reg_r0_10, (unsigned int) 3, reg_r0_5); /* line 3045 */
} /* line 3045 */
  sim_icache_fetch(1909 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_10); /* line 3047 */
   MOV(reg_r0_9, reg_r0_11); /* line 3048 */
} /* line 3048 */
  sim_icache_fetch(1911 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, 0); /* line 3050 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3051 */
  sim_icache_fetch(1913 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, 0); /* line 3053 */
   MOV(reg_r0_2, reg_r0_12); /* line 3054 */
} /* line 3054 */
  sim_icache_fetch(1915 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, 0); /* line 3056 */
   MOV(reg_r0_15, reg_r0_3); /* line 3057 */
} /* line 3057 */
  sim_icache_fetch(1917 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_16, reg_r0_5); /* line 3059 */
   MOV(reg_r0_17, reg_r0_11); /* line 3060 */
} /* line 3060 */
  sim_icache_fetch(1919 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_12); /* line 3062 */
} /* line 3062 */
l_L118X3: ;/* line 3065 */
LABEL(l_L118X3);
  sim_icache_fetch(1920 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 3066 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 215); /* line 3067 */
} /* line 3067 */
  sim_icache_fetch(1922 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 3069 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -155); /* line 3070 */
} /* line 3070 */
  sim_icache_fetch(1924 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 3); /* line 3072 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 3073 */
} /* line 3073 */
  sim_icache_fetch(1926 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_3, (unsigned int) -48); /* line 3075 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 8); /* line 3076 */
} /* line 3076 */
  sim_icache_fetch(1928 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 3078 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3079 */
  sim_icache_fetch(1930 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_5); /* line 3081 */
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 2); /* line 3082 */
} /* line 3082 */
  sim_icache_fetch(1932 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_10); /* line 3084 */
   LDBUs(reg_r0_5, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 3085 */
} /* line 3085 */
  sim_icache_fetch(1934 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_7, (unsigned int) 215); /* line 3087 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 3088 */
} /* line 3088 */
  sim_icache_fetch(1936 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 3090 */
   CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 1); /* line 3091 */
} /* line 3091 */
  sim_icache_fetch(1938 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_5, (unsigned int) -48); /* line 3093 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 3094 */
} /* line 3094 */
  sim_icache_fetch(1940 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 3096 */
   LDBUs(reg_r0_12, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 3097 */
} /* line 3097 */
  sim_icache_fetch(1942 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 3099 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 3100 */
} /* line 3100 */
  sim_icache_fetch(1944 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 3102 */
   MULL(reg_r0_10, reg_r0_7, (unsigned int) -155); /* line 3103 */
} /* line 3103 */
  sim_icache_fetch(1946 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_12, (unsigned int) -48); /* line 3105 */
   MULL(reg_r0_13, reg_r0_3, (unsigned int) 215); /* line 3106 */
} /* line 3106 */
  sim_icache_fetch(1948 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 28); /* line 3108 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 3109 */
} /* line 3109 */
  sim_icache_fetch(1950 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 3111 */
   CMPLT(reg_b0_2, reg_r0_8, 0); /* line 3112 */
} /* line 3112 */
  sim_icache_fetch(1952 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 3114 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 3115 */
} /* line 3115 */
  sim_icache_fetch(1954 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 3117 */
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 3),0,1)); /* line 3118 */
} /* line 3118 */
  sim_icache_fetch(1956 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_5, (unsigned int) 215); /* line 3120 */
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -155); /* line 3121 */
} /* line 3121 */
  sim_icache_fetch(1958 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_12, (unsigned int) 28); /* line 3123 */
   MOV(reg_r0_6, reg_r0_5); /* line 3124 */
} /* line 3124 */
  sim_icache_fetch(1960 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_10, (unsigned int) -48); /* line 3126 */
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 3127 */
} /* line 3127 */
  sim_icache_fetch(1962 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 3129 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 3130 */
} /* line 3130 */
  sim_icache_fetch(1964 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_13); /* line 3132 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_11); /* line 3133 */
} /* line 3133 */
  sim_icache_fetch(1966 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_12, reg_r0_14); /* line 3135 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 4); /* line 3136 */
} /* line 3136 */
  sim_icache_fetch(1968 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_9,0,4), reg_r0_7); /* line 3138 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3139 */
  sim_icache_fetch(1970 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 4),0,4), reg_r0_3); /* line 3141 */
   MOV(reg_r0_7, reg_r0_10); /* line 3142 */
} /* line 3142 */
  sim_icache_fetch(1972 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3144 */
  sim_icache_fetch(1973 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 8),0,4), reg_r0_5); /* line 3146 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L119X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3147 */
  sim_icache_fetch(1975 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 12),0,4), reg_r0_4); /* line 3149 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 3151 */
} /* line 3151 */
  sim_icache_fetch(1977 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L118X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L118X3;
} /* line 3153 */
l_L119X3: ;/* line 3156 */
LABEL(l_L119X3);
  sim_icache_fetch(1978 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4200); /* line 3157 */
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 1050); /* line 3158 */
} /* line 3158 */
  sim_icache_fetch(1982 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_15, (unsigned int) 1); /* line 3160 */
   MOV(reg_r0_5, reg_r0_16); /* line 3162 */
} /* line 3162 */
  sim_icache_fetch(1984 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L116X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L116X3;
} /* line 3164 */
l_L117X3: ;/* line 3167 */
LABEL(l_L117X3);
  sim_icache_fetch(1985 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_19); /* line 3168 */
   MOV(reg_r0_12, ((unsigned int) qy2 + (unsigned int) -12)); /* line 3169 */
} /* line 3169 */
  sim_icache_fetch(1988 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_5, (unsigned int) -1); /* line 3171 */
   MOV(reg_r0_4, reg_r0_2); /* line 3172 */
} /* line 3172 */
  sim_icache_fetch(1990 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 3174 */
   MOV(reg_r0_21, reg_r0_19); /* line 3175 */
} /* line 3175 */
  sim_icache_fetch(1993 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, reg_r0_5); /* line 3177 */
} /* line 3177 */
l_L120X3: ;/* line 3180 */
LABEL(l_L120X3);
  sim_icache_fetch(1994 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 3181 */
   ADD(reg_r0_9, reg_r0_10, reg_r0_11); /* line 3182 */
} /* line 3182 */
  sim_icache_fetch(1996 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 3184 */
   SH2ADD(reg_r0_8, reg_r0_11, reg_r0_12); /* line 3185 */
} /* line 3185 */
  sim_icache_fetch(1998 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 3187 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3188 */
  sim_icache_fetch(2000 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 3190 */
   MOV(reg_r0_6, 0); /* line 3191 */
} /* line 3191 */
  sim_icache_fetch(2002 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_11); /* line 3193 */
   MOV(reg_r0_17, reg_r0_4); /* line 3194 */
} /* line 3194 */
  sim_icache_fetch(2004 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_18, reg_r0_10); /* line 3196 */
   MOV(reg_r0_19, reg_r0_11); /* line 3197 */
} /* line 3197 */
  sim_icache_fetch(2006 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_12); /* line 3199 */
} /* line 3199 */
l_L122X3: ;/* line 3202 */
LABEL(l_L122X3);
  sim_icache_fetch(2007 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 3203 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 3204 */
} /* line 3204 */
  sim_icache_fetch(2009 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -48); /* line 3206 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 3207 */
} /* line 3207 */
  sim_icache_fetch(2011 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 3209 */
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 3210 */
} /* line 3210 */
  sim_icache_fetch(2013 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 3212 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_2); /* line 3213 */
} /* line 3213 */
  sim_icache_fetch(2015 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 3215 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3216 */
  sim_icache_fetch(2017 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 3218 */
   LDBU(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 3),0,1)); /* line 3219 */
} /* line 3219 */
  sim_icache_fetch(2019 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 3221 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 3222 */
} /* line 3222 */
  sim_icache_fetch(2021 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 3224 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) 215); /* line 3225 */
} /* line 3225 */
  sim_icache_fetch(2023 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 3227 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 3228 */
} /* line 3228 */
  sim_icache_fetch(2025 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 3230 */
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_9 + (unsigned int) 2),0,1)); /* line 3231 */
} /* line 3231 */
  sim_icache_fetch(2027 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_5); /* line 3233 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 3234 */
} /* line 3234 */
  sim_icache_fetch(2029 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 3236 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 3237 */
} /* line 3237 */
  sim_icache_fetch(2031 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_13, (unsigned int) -47); /* line 3239 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) -155); /* line 3240 */
} /* line 3240 */
  sim_icache_fetch(2033 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 3242 */
   MULL(reg_r0_15, reg_r0_12, (unsigned int) 215); /* line 3243 */
} /* line 3243 */
  sim_icache_fetch(2035 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 3245 */
   LDBUs(reg_r0_16, mem_trace_ld((reg_r0_9 + (unsigned int) 1),0,1)); /* line 3246 */
} /* line 3246 */
  sim_icache_fetch(2037 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 3248 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_11); /* line 3249 */
} /* line 3249 */
  sim_icache_fetch(2039 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_15); /* line 3251 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 3252 */
} /* line 3252 */
  sim_icache_fetch(2041 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 3254 */
   MULL(reg_r0_10, reg_r0_12, (unsigned int) -155); /* line 3255 */
} /* line 3255 */
  sim_icache_fetch(2043 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_16, (unsigned int) -47); /* line 3257 */
   MULL(reg_r0_15, reg_r0_14, (unsigned int) 215); /* line 3258 */
} /* line 3258 */
  sim_icache_fetch(2045 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_13, (unsigned int) -48); /* line 3260 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 3261 */
} /* line 3261 */
  sim_icache_fetch(2047 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 3263 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 3264 */
} /* line 3264 */
  sim_icache_fetch(2049 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 3266 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_9,0,1)); /* line 3267 */
} /* line 3267 */
  sim_icache_fetch(2051 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_11, reg_r0_13); /* line 3269 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 3270 */
} /* line 3270 */
  sim_icache_fetch(2053 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_16); /* line 3272 */
   MOV(reg_r0_2, reg_r0_14); /* line 3273 */
} /* line 3273 */
  sim_icache_fetch(2055 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 3275 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -4); /* line 3276 */
} /* line 3276 */
  sim_icache_fetch(2057 + t_thisfile.offset, 1);
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
} /* line 3278 */
  sim_icache_fetch(2058 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_12); /* line 3280 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3281 */
  sim_icache_fetch(2060 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_14); /* line 3283 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3284 */
  sim_icache_fetch(2062 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_5); /* line 3286 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 3288 */
} /* line 3288 */
  sim_icache_fetch(2064 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L122X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L122X3;
} /* line 3290 */
l_L123X3: ;/* line 3293 */
LABEL(l_L123X3);
  sim_icache_fetch(2065 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_18, (unsigned int) 1050); /* line 3294 */
   ADD(reg_r0_12, reg_r0_20, (unsigned int) 4200); /* line 3295 */
} /* line 3295 */
  sim_icache_fetch(2069 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_17, (unsigned int) 1); /* line 3297 */
   MOV(reg_r0_11, reg_r0_19); /* line 3299 */
} /* line 3299 */
  sim_icache_fetch(2071 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L120X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L120X3;
} /* line 3301 */
l_L121X3: ;/* line 3304 */
LABEL(l_L121X3);
  sim_icache_fetch(2072 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_21); /* line 3305 */
   MOV(reg_r0_11, (unsigned int) qy2); /* line 3306 */
} /* line 3306 */
  sim_icache_fetch(2075 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_2); /* line 3308 */
   MOV(reg_r0_10, (unsigned int) qy1); /* line 3309 */
} /* line 3309 */
  sim_icache_fetch(2078 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, (unsigned int) qt); /* line 3311 */
   MOV(reg_r0_16, reg_r0_21); /* line 3312 */
} /* line 3312 */
  sim_icache_fetch(2081 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_22); /* line 3314 */
} /* line 3314 */
l_L124X3: ;/* line 3317 */
LABEL(l_L124X3);
  sim_icache_fetch(2082 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 3318 */
   SUB(reg_r0_8, (unsigned int) 3, reg_r0_7); /* line 3319 */
} /* line 3319 */
  sim_icache_fetch(2084 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_8); /* line 3321 */
   MOV(reg_r0_6, reg_r0_9); /* line 3322 */
} /* line 3322 */
  sim_icache_fetch(2086 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_10); /* line 3324 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3325 */
  sim_icache_fetch(2088 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_11); /* line 3327 */
   MOV(reg_r0_12, reg_r0_7); /* line 3328 */
} /* line 3328 */
  sim_icache_fetch(2090 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_11 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, reg_r0_3); /* line 3330 */
   MOV(reg_r0_15, t__i32_0); /* line 3331 */
} /* line 3331 */
  sim_icache_fetch(2092 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_13, reg_r0_9); /* line 3333 */
   MOV(reg_r0_14, reg_r0_10); /* line 3334 */
} /* line 3334 */
l_L126X3: ;/* line 3337 */
LABEL(l_L126X3);
  sim_icache_fetch(2094 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 3338 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 3339 */
} /* line 3339 */
  sim_icache_fetch(2096 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_7, mem_trace_ld(reg_r0_4,0,4)); /* line 3341 */
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 3342 */
} /* line 3342 */
  sim_icache_fetch(2098 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 3344 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3345 */
  sim_icache_fetch(2100 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 3347 */
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 3348 */
} /* line 3348 */
  sim_icache_fetch(2102 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_7); /* line 3350 */
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 3351 */
} /* line 3351 */
  sim_icache_fetch(2104 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 3353 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 3354 */
} /* line 3354 */
  sim_icache_fetch(2106 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 3356 */
   ADD(reg_r0_8, reg_r0_8, reg_r0_9); /* line 3357 */
} /* line 3357 */
  sim_icache_fetch(2108 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 3359 */
   CMPLT(reg_b0_2, reg_r0_5, 0); /* line 3360 */
} /* line 3360 */
  sim_icache_fetch(2110 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 3362 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_10); /* line 3363 */
} /* line 3363 */
  sim_icache_fetch(2112 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 3365 */
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 3366 */
} /* line 3366 */
  sim_icache_fetch(2114 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 3368 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 3369 */
} /* line 3369 */
  sim_icache_fetch(2116 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 3371 */
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 3372 */
} /* line 3372 */
  sim_icache_fetch(2118 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_6,0,4), reg_r0_3); /* line 3374 */
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 3375 */
} /* line 3375 */
  sim_icache_fetch(2120 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_9, reg_r0_10); /* line 3377 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3378 */
  sim_icache_fetch(2122 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 4),0,4), reg_r0_8); /* line 3380 */
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 3381 */
} /* line 3381 */
  sim_icache_fetch(2124 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 3383 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3384 */
  sim_icache_fetch(2126 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 8),0,4), reg_r0_7); /* line 3386 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3387 */
  sim_icache_fetch(2128 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 12),0,4), reg_r0_9); /* line 3389 */
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 3391 */
} /* line 3391 */
  sim_icache_fetch(2130 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L126X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L126X3;
} /* line 3393 */
l_L130X3: ;/* line 3396 */
LABEL(l_L130X3);
  sim_icache_fetch(2131 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 3397 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 3398 */
} /* line 3398 */
  sim_icache_fetch(2134 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_14, reg_r0_2); /* line 3400 */
   ADD(reg_r0_11, reg_r0_15, reg_r0_2); /* line 3402 */
} /* line 3402 */
  sim_icache_fetch(2136 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L131X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L131X3;
} /* line 3404 */
l_L129X3: ;/* line 3407 */
LABEL(l_L129X3);
  sim_icache_fetch(2137 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 3408 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 3409 */
} /* line 3409 */
  sim_icache_fetch(2140 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_14, reg_r0_2); /* line 3411 */
   ADD(reg_r0_11, reg_r0_15, reg_r0_2); /* line 3413 */
} /* line 3413 */
  sim_icache_fetch(2142 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L131X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L131X3;
} /* line 3415 */
l_L128X3: ;/* line 3418 */
LABEL(l_L128X3);
  sim_icache_fetch(2143 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 3419 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 3420 */
} /* line 3420 */
  sim_icache_fetch(2146 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_14, reg_r0_2); /* line 3422 */
   ADD(reg_r0_11, reg_r0_15, reg_r0_2); /* line 3424 */
} /* line 3424 */
  sim_icache_fetch(2148 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L131X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L131X3;
} /* line 3426 */
l_L127X3: ;/* line 3429 */
LABEL(l_L127X3);
  sim_icache_fetch(2149 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 3430 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 3431 */
} /* line 3431 */
  sim_icache_fetch(2152 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_14, reg_r0_2); /* line 3433 */
   ADD(reg_r0_11, reg_r0_15, reg_r0_2); /* line 3434 */
} /* line 3434 */
l_L131X3: ;/* line 3436 */
LABEL(l_L131X3);
  sim_icache_fetch(2154 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_13, reg_r0_2); /* line 3437 */
   MOV(reg_r0_7, reg_r0_12); /* line 3439 */
} /* line 3439 */
  sim_icache_fetch(2156 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L124X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L124X3;
} /* line 3441 */
l_L125X3: ;/* line 3444 */
LABEL(l_L125X3);
  sim_icache_fetch(2157 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_7); /* line 3445 */
   MOV(reg_r0_12, (unsigned int) qt); /* line 3446 */
} /* line 3446 */
  sim_icache_fetch(2160 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_2); /* line 3448 */
   MOV(reg_r0_11, (unsigned int) qy1); /* line 3449 */
} /* line 3449 */
  sim_icache_fetch(2163 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_7); /* line 3451 */
   MOV(reg_r0_9, reg_r0_16); /* line 3452 */
} /* line 3452 */
l_L132X3: ;/* line 3455 */
LABEL(l_L132X3);
  sim_icache_fetch(2165 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 3456 */
   SUB(reg_r0_10, (unsigned int) 3, reg_r0_9); /* line 3457 */
} /* line 3457 */
  sim_icache_fetch(2167 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_10); /* line 3459 */
   MOV(reg_r0_8, reg_r0_11); /* line 3460 */
} /* line 3460 */
  sim_icache_fetch(2169 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_12); /* line 3462 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3463 */
  sim_icache_fetch(2171 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, 0); /* line 3465 */
   MOV(reg_r0_5, 0); /* line 3466 */
} /* line 3466 */
  sim_icache_fetch(2173 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, 0); /* line 3468 */
   MOV(reg_r0_13, reg_r0_3); /* line 3469 */
} /* line 3469 */
  sim_icache_fetch(2175 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_14, reg_r0_9); /* line 3471 */
   MOV(reg_r0_15, reg_r0_11); /* line 3472 */
} /* line 3472 */
  sim_icache_fetch(2177 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_12); /* line 3474 */
} /* line 3474 */
l_L134X3: ;/* line 3477 */
LABEL(l_L134X3);
  sim_icache_fetch(2178 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 3478 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 3479 */
} /* line 3479 */
  sim_icache_fetch(2180 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_9, reg_r0_5, (unsigned int) 215); /* line 3481 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 3482 */
} /* line 3482 */
  sim_icache_fetch(2182 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 3); /* line 3484 */
   CMPLT(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 3485 */
} /* line 3485 */
  sim_icache_fetch(2184 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_3, (unsigned int) -48); /* line 3487 */
   ADD(reg_r0_9, reg_r0_9, reg_r0_6); /* line 3488 */
} /* line 3488 */
  sim_icache_fetch(2186 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 3490 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3491 */
  sim_icache_fetch(2189 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_10); /* line 3493 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 3494 */
} /* line 3494 */
  sim_icache_fetch(2191 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_9); /* line 3496 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 3497 */
} /* line 3497 */
  sim_icache_fetch(2193 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 3499 */
   MULL(reg_r0_9, reg_r0_11, (unsigned int) -48); /* line 3500 */
} /* line 3500 */
  sim_icache_fetch(2195 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 3502 */
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 3503 */
} /* line 3503 */
  sim_icache_fetch(2197 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_9); /* line 3505 */
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 8400),0,4)); /* line 3506 */
} /* line 3506 */
  sim_icache_fetch(2200 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_3); /* line 3508 */
   MULL(reg_r0_3, reg_r0_4, (unsigned int) -155); /* line 3509 */
} /* line 3509 */
  sim_icache_fetch(2202 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 3511 */
   MULL(reg_r0_11, reg_r0_11, (unsigned int) 28); /* line 3512 */
} /* line 3512 */
  sim_icache_fetch(2204 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 3514 */
   MULL(reg_r0_10, reg_r0_9, (unsigned int) -48); /* line 3515 */
} /* line 3515 */
  sim_icache_fetch(2206 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_5, (unsigned int) 215); /* line 3517 */
   CMPLT(reg_b0_2, reg_r0_7, 0); /* line 3518 */
} /* line 3518 */
  sim_icache_fetch(2208 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_10); /* line 3520 */
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 12600),0,4)); /* line 3521 */
} /* line 3521 */
  sim_icache_fetch(2211 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_11); /* line 3523 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) -155); /* line 3524 */
} /* line 3524 */
  sim_icache_fetch(2213 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_12); /* line 3526 */
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 28); /* line 3527 */
} /* line 3527 */
  sim_icache_fetch(2215 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 3529 */
   MULL(reg_r0_11, reg_r0_6, (unsigned int) -48); /* line 3530 */
} /* line 3530 */
  sim_icache_fetch(2217 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 3532 */
   MULL(reg_r0_12, reg_r0_3, (unsigned int) 215); /* line 3533 */
} /* line 3533 */
  sim_icache_fetch(2219 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 3535 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3536 */
  sim_icache_fetch(2221 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_3); /* line 3538 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_9); /* line 3539 */
} /* line 3539 */
  sim_icache_fetch(2223 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_12); /* line 3541 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16800); /* line 3542 */
} /* line 3542 */
  sim_icache_fetch(2226 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 3544 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 3545 */
} /* line 3545 */
  sim_icache_fetch(2228 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_5); /* line 3547 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3548 */
  sim_icache_fetch(2231 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_3); /* line 3550 */
   MOV(reg_r0_5, reg_r0_10); /* line 3551 */
} /* line 3551 */
  sim_icache_fetch(2234 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3553 */
  sim_icache_fetch(2235 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_10); /* line 3555 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 16800); /* line 3557 */
} /* line 3557 */
  sim_icache_fetch(2239 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L134X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L134X3;
} /* line 3559 */
l_L138X3: ;/* line 3562 */
LABEL(l_L138X3);
  sim_icache_fetch(2240 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3563 */
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 3564 */
} /* line 3564 */
  sim_icache_fetch(2242 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_14); /* line 3566 */
   GOTO(l_L139X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L139X3;
} /* line 3567 */
l_L137X3: ;/* line 3570 */
LABEL(l_L137X3);
  sim_icache_fetch(2244 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3571 */
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 3572 */
} /* line 3572 */
  sim_icache_fetch(2246 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_14); /* line 3574 */
   GOTO(l_L139X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L139X3;
} /* line 3575 */
l_L136X3: ;/* line 3578 */
LABEL(l_L136X3);
  sim_icache_fetch(2248 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3579 */
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 3580 */
} /* line 3580 */
  sim_icache_fetch(2250 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_14); /* line 3582 */
   GOTO(l_L139X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L139X3;
} /* line 3583 */
l_L135X3: ;/* line 3586 */
LABEL(l_L135X3);
  sim_icache_fetch(2252 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3587 */
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 3588 */
} /* line 3588 */
  sim_icache_fetch(2254 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_14); /* line 3590 */
} /* line 3590 */
l_L139X3: ;/* line 3592 */
LABEL(l_L139X3);
  sim_icache_fetch(2255 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_15, (unsigned int) 4); /* line 3593 */
   GOTO(l_L132X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L132X3;
} /* line 3594 */
l_L133X3: ;/* line 3597 */
LABEL(l_L133X3);
  sim_icache_fetch(2257 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_17); /* line 3598 */
   MOV(reg_r0_13, ((unsigned int) qy2 + (unsigned int) -12600)); /* line 3599 */
} /* line 3599 */
  sim_icache_fetch(2260 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_2); /* line 3601 */
   MOV(reg_r0_12, ((unsigned int) qt + (unsigned int) -12600)); /* line 3602 */
} /* line 3602 */
  sim_icache_fetch(2263 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_9, (unsigned int) -1); /* line 3604 */
   MOV(reg_r0_19, reg_r0_17); /* line 3605 */
} /* line 3605 */
  sim_icache_fetch(2265 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_9); /* line 3607 */
} /* line 3607 */
l_L140X3: ;/* line 3610 */
LABEL(l_L140X3);
  sim_icache_fetch(2266 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 3611 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 4200); /* line 3612 */
} /* line 3612 */
  sim_icache_fetch(2269 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 3614 */
   MOV(reg_r0_6, 0); /* line 3615 */
} /* line 3615 */
  sim_icache_fetch(2271 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 3617 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L141X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3618 */
  sim_icache_fetch(2273 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 3620 */
   ADD(reg_r0_8, reg_r0_13, reg_r0_11); /* line 3621 */
} /* line 3621 */
  sim_icache_fetch(2275 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 3623 */
   MOV(reg_r0_7, reg_r0_10); /* line 3624 */
} /* line 3624 */
  sim_icache_fetch(2277 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_15, reg_r0_4); /* line 3626 */
   MOV(reg_r0_16, reg_r0_10); /* line 3627 */
} /* line 3627 */
  sim_icache_fetch(2279 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_12); /* line 3629 */
   MOV(reg_r0_18, reg_r0_13); /* line 3630 */
} /* line 3630 */
l_L142X3: ;/* line 3633 */
LABEL(l_L142X3);
  sim_icache_fetch(2281 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 3634 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 3635 */
} /* line 3635 */
  sim_icache_fetch(2283 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 3637 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 29); /* line 3638 */
} /* line 3638 */
  sim_icache_fetch(2285 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 3640 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3641 */
} /* line 3641 */
  sim_icache_fetch(2287 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 3643 */
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 12600),0,4)); /* line 3644 */
} /* line 3644 */
  sim_icache_fetch(2290 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 3646 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L143X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3647 */
  sim_icache_fetch(2292 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 3649 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 3650 */
} /* line 3650 */
  sim_icache_fetch(2294 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 3652 */
   MULL(reg_r0_10, reg_r0_4, (unsigned int) -47); /* line 3653 */
} /* line 3653 */
  sim_icache_fetch(2296 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 3655 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 3656 */
} /* line 3656 */
  sim_icache_fetch(2298 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 3658 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 8400),0,4)); /* line 3659 */
} /* line 3659 */
  sim_icache_fetch(2301 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 3661 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 3662 */
} /* line 3662 */
  sim_icache_fetch(2303 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 3664 */
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 3665 */
} /* line 3665 */
  sim_icache_fetch(2305 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 3667 */
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 3668 */
} /* line 3668 */
  sim_icache_fetch(2307 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_5, (unsigned int) 215); /* line 3670 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 29); /* line 3671 */
} /* line 3671 */
  sim_icache_fetch(2309 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 3673 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,4)); /* line 3674 */
} /* line 3674 */
  sim_icache_fetch(2312 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_4); /* line 3676 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 3677 */
} /* line 3677 */
  sim_icache_fetch(2314 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 3679 */
   MULL(reg_r0_4, reg_r0_5, (unsigned int) -155); /* line 3680 */
} /* line 3680 */
  sim_icache_fetch(2316 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 3682 */
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 3683 */
} /* line 3683 */
  sim_icache_fetch(2318 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 3685 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 3686 */
} /* line 3686 */
  sim_icache_fetch(2320 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 3688 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_9,0,4)); /* line 3689 */
} /* line 3689 */
  sim_icache_fetch(2322 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_2); /* line 3691 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 3692 */
} /* line 3692 */
  sim_icache_fetch(2325 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 3694 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L144X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3695 */
  sim_icache_fetch(2327 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_11); /* line 3697 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 3698 */
} /* line 3698 */
  sim_icache_fetch(2329 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_12); /* line 3700 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 3701 */
} /* line 3701 */
  sim_icache_fetch(2331 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_5); /* line 3703 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -16800); /* line 3704 */
} /* line 3704 */
  sim_icache_fetch(2335 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_4); /* line 3706 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L145X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3707 */
  sim_icache_fetch(2337 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_11); /* line 3709 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L146X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3710 */
  sim_icache_fetch(2340 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 3712 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16800); /* line 3714 */
} /* line 3714 */
  sim_icache_fetch(2343 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L142X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L142X3;
} /* line 3716 */
l_L146X3: ;/* line 3719 */
LABEL(l_L146X3);
  sim_icache_fetch(2344 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 3720 */
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 3722 */
} /* line 3722 */
  sim_icache_fetch(2346 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L147X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L147X3;
} /* line 3724 */
l_L145X3: ;/* line 3727 */
LABEL(l_L145X3);
  sim_icache_fetch(2347 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 3728 */
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 3730 */
} /* line 3730 */
  sim_icache_fetch(2349 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L147X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L147X3;
} /* line 3732 */
l_L144X3: ;/* line 3735 */
LABEL(l_L144X3);
  sim_icache_fetch(2350 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 3736 */
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 3738 */
} /* line 3738 */
  sim_icache_fetch(2352 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L147X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L147X3;
} /* line 3740 */
l_L143X3: ;/* line 3743 */
LABEL(l_L143X3);
  sim_icache_fetch(2353 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 3744 */
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 3745 */
} /* line 3745 */
l_L147X3: ;/* line 3747 */
LABEL(l_L147X3);
  sim_icache_fetch(2355 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_15, (unsigned int) 1); /* line 3748 */
   MOV(reg_r0_10, reg_r0_16); /* line 3750 */
} /* line 3750 */
  sim_icache_fetch(2357 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L140X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L140X3;
} /* line 3752 */
l_L141X3: ;/* line 3755 */
LABEL(l_L141X3);
  sim_icache_fetch(2358 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_20, 0, reg_r0_20); /* line 3756 */
   MOV(reg_r0_12, (unsigned int) qy2); /* line 3757 */
} /* line 3757 */
  sim_icache_fetch(2361 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_20); /* line 3759 */
   MOV(reg_r0_11, (unsigned int) qy1); /* line 3760 */
} /* line 3760 */
  sim_icache_fetch(2364 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, (unsigned int) out); /* line 3762 */
   MOV(reg_r0_8, reg_r0_19); /* line 3763 */
} /* line 3763 */
l_L148X3: ;/* line 3766 */
LABEL(l_L148X3);
  sim_icache_fetch(2367 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 3767 */
   SUB(reg_r0_9, (unsigned int) 3, reg_r0_8); /* line 3768 */
} /* line 3768 */
  sim_icache_fetch(2369 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_9); /* line 3770 */
   MOV(reg_r0_7, reg_r0_10); /* line 3771 */
} /* line 3771 */
  sim_icache_fetch(2371 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_10); /* line 3773 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L149X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3774 */
  sim_icache_fetch(2373 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_11); /* line 3776 */
   MOV(reg_r0_2, reg_r0_12); /* line 3777 */
} /* line 3777 */
  sim_icache_fetch(2375 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_13, reg_r0_3); /* line 3779 */
   MOV(reg_r0_14, reg_r0_8); /* line 3780 */
} /* line 3780 */
  sim_icache_fetch(2377 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_15, reg_r0_10); /* line 3782 */
   MOV(reg_r0_16, reg_r0_11); /* line 3783 */
} /* line 3783 */
  sim_icache_fetch(2379 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_12); /* line 3785 */
} /* line 3785 */
l_L150X3: ;/* line 3788 */
LABEL(l_L150X3);
  sim_icache_fetch(2380 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 3789 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 3790 */
} /* line 3790 */
  sim_icache_fetch(2382 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_4,0,4)); /* line 3792 */
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 3793 */
} /* line 3793 */
  sim_icache_fetch(2384 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 3795 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L151X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3796 */
  sim_icache_fetch(2386 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 3798 */
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 3799 */
} /* line 3799 */
  sim_icache_fetch(2388 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_8); /* line 3801 */
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 3802 */
} /* line 3802 */
  sim_icache_fetch(2390 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 3804 */
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 3805 */
} /* line 3805 */
  sim_icache_fetch(2392 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3807 */
   ADD(reg_r0_9, reg_r0_9, reg_r0_10); /* line 3808 */
} /* line 3808 */
  sim_icache_fetch(2394 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_10, reg_r0_3); /* line 3810 */
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 3811 */
} /* line 3811 */
  sim_icache_fetch(2396 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_2, reg_r0_10, (unsigned int) 25); /* line 3813 */
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 3814 */
} /* line 3814 */
  sim_icache_fetch(2398 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_12, reg_r0_9); /* line 3816 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_8); /* line 3817 */
} /* line 3817 */
  sim_icache_fetch(2400 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_3, reg_r0_12, (unsigned int) 25); /* line 3819 */
   SHL(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 3820 */
} /* line 3820 */
  sim_icache_fetch(2402 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 3822 */
   CMPLT(reg_b0_4, reg_r0_5, 0); /* line 3823 */
} /* line 3823 */
  sim_icache_fetch(2404 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_8, reg_r0_11); /* line 3825 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 3826 */
} /* line 3826 */
  sim_icache_fetch(2406 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_5, reg_r0_8, (unsigned int) 25); /* line 3828 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 3829 */
} /* line 3829 */
  sim_icache_fetch(2408 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_6,0,1), reg_r0_3); /* line 3831 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L152X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3832 */
  sim_icache_fetch(2410 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_6,0,1), 0); /* line 3834 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3835 */
l_L154X3: ;/* line 3837 */
LABEL(l_L154X3);
  sim_icache_fetch(2412 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), reg_r0_9); /* line 3838 */
   ADD(reg_r0_10, reg_r0_10, reg_r0_12); /* line 3839 */
} /* line 3839 */
  sim_icache_fetch(2414 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 3841 */
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L155X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3842 */
  sim_icache_fetch(2416 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), 0); /* line 3844 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 3845 */
} /* line 3845 */
l_L156X3: ;/* line 3847 */
LABEL(l_L156X3);
  sim_icache_fetch(2418 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_10); /* line 3848 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L157X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3849 */
  sim_icache_fetch(2420 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), reg_r0_11); /* line 3851 */
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 3852 */
} /* line 3852 */
  sim_icache_fetch(2422 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_5) {    BRANCHF(reg_b0_5);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L158X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3854 */
  sim_icache_fetch(2423 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), 0); /* line 3856 */
   if (!reg_b0_4) {    BRANCHF(reg_b0_4);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3857 */
l_L160X3: ;/* line 3859 */
LABEL(l_L160X3);
  sim_icache_fetch(2425 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), reg_r0_10); /* line 3860 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L161X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3861 */
  sim_icache_fetch(2427 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 3863 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 3864 */
} /* line 3864 */
  sim_icache_fetch(2429 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 3866 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 3867 */
} /* line 3867 */
  sim_icache_fetch(2431 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), 0); /* line 3869 */
} /* line 3869 */
l_L162X3: ;/* line 3871 */
LABEL(l_L162X3);
  sim_icache_fetch(2432 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 4); /* line 3872 */
   GOTO(l_L150X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L150X3;
} /* line 3873 */
l_L161X3: ;/* line 3876 */
LABEL(l_L161X3);
  sim_icache_fetch(2434 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 3877 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 3878 */
} /* line 3878 */
  sim_icache_fetch(2436 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 3880 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 3881 */
} /* line 3881 */
  sim_icache_fetch(2438 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 3),0,1), reg_r0_3); /* line 3883 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 3885 */
} /* line 3885 */
  sim_icache_fetch(2440 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L162X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L162X3;
} /* line 3887 */
l_L159X3: ;/* line 3890 */
LABEL(l_L159X3);
  sim_icache_fetch(2441 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3891 */
   ADD(reg_r0_11, reg_r0_16, (unsigned int) 4200); /* line 3892 */
} /* line 3892 */
  sim_icache_fetch(2444 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4200); /* line 3894 */
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1050); /* line 3896 */
} /* line 3896 */
  sim_icache_fetch(2448 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L163X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L163X3;
} /* line 3898 */
l_L158X3: ;/* line 3901 */
LABEL(l_L158X3);
  sim_icache_fetch(2449 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 3902 */
} /* line 3902 */
  sim_icache_fetch(2450 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 2),0,1), reg_r0_3); /* line 3904 */
   if (!reg_b0_4) {    BRANCHF(reg_b0_4);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L159X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3906 */
  sim_icache_fetch(2452 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L160X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L160X3;
} /* line 3908 */
l_L157X3: ;/* line 3911 */
LABEL(l_L157X3);
  sim_icache_fetch(2453 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3912 */
   ADD(reg_r0_11, reg_r0_16, (unsigned int) 4200); /* line 3913 */
} /* line 3913 */
  sim_icache_fetch(2456 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4200); /* line 3915 */
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1050); /* line 3917 */
} /* line 3917 */
  sim_icache_fetch(2460 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L163X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L163X3;
} /* line 3919 */
l_L155X3: ;/* line 3922 */
LABEL(l_L155X3);
  sim_icache_fetch(2461 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 3923 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 3924 */
} /* line 3924 */
  sim_icache_fetch(2463 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 1),0,1), reg_r0_3); /* line 3926 */
   GOTO(l_L156X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L156X3;
} /* line 3927 */
l_L153X3: ;/* line 3930 */
LABEL(l_L153X3);
  sim_icache_fetch(2465 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3931 */
   ADD(reg_r0_11, reg_r0_16, (unsigned int) 4200); /* line 3932 */
} /* line 3932 */
  sim_icache_fetch(2468 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4200); /* line 3934 */
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1050); /* line 3936 */
} /* line 3936 */
  sim_icache_fetch(2472 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L163X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L163X3;
} /* line 3938 */
l_L152X3: ;/* line 3941 */
LABEL(l_L152X3);
  sim_icache_fetch(2473 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 3942 */
} /* line 3942 */
  sim_icache_fetch(2474 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_7,0,1), reg_r0_3); /* line 3944 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L153X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3946 */
  sim_icache_fetch(2476 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L154X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L154X3;
} /* line 3948 */
l_L151X3: ;/* line 3951 */
LABEL(l_L151X3);
  sim_icache_fetch(2477 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_16, (unsigned int) 4200); /* line 3952 */
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4200); /* line 3953 */
} /* line 3953 */
  sim_icache_fetch(2481 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3955 */
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1050); /* line 3956 */
} /* line 3956 */
l_L163X3: ;/* line 3958 */
LABEL(l_L163X3);
  sim_icache_fetch(2484 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_14); /* line 3959 */
   GOTO(l_L148X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L148X3;
} /* line 3960 */
l_L149X3: ;/* line 3963 */
LABEL(l_L149X3);
  sim_icache_fetch(2486 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_slow);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3965 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 294: goto l_L116X3;
    case 295: goto l_L118X3;
    case 296: goto l_L119X3;
    case 297: goto l_L117X3;
    case 298: goto l_L120X3;
    case 299: goto l_L122X3;
    case 300: goto l_L123X3;
    case 301: goto l_L121X3;
    case 302: goto l_L124X3;
    case 303: goto l_L126X3;
    case 304: goto l_L130X3;
    case 305: goto l_L129X3;
    case 306: goto l_L128X3;
    case 307: goto l_L127X3;
    case 308: goto l_L131X3;
    case 309: goto l_L125X3;
    case 310: goto l_L132X3;
    case 311: goto l_L134X3;
    case 312: goto l_L138X3;
    case 313: goto l_L137X3;
    case 314: goto l_L136X3;
    case 315: goto l_L135X3;
    case 316: goto l_L139X3;
    case 317: goto l_L133X3;
    case 318: goto l_L140X3;
    case 319: goto l_L142X3;
    case 320: goto l_L146X3;
    case 321: goto l_L145X3;
    case 322: goto l_L144X3;
    case 323: goto l_L143X3;
    case 324: goto l_L147X3;
    case 325: goto l_L141X3;
    case 326: goto l_L148X3;
    case 327: goto l_L150X3;
    case 328: goto l_L154X3;
    case 329: goto l_L156X3;
    case 330: goto l_L160X3;
    case 331: goto l_L162X3;
    case 332: goto l_L161X3;
    case 333: goto l_L159X3;
    case 334: goto l_L158X3;
    case 335: goto l_L157X3;
    case 336: goto l_L155X3;
    case 337: goto l_L153X3;
    case 338: goto l_L152X3;
    case 339: goto l_L151X3;
    case 340: goto l_L163X3;
    case 341: goto l_L149X3;
    case 342:
      reg_l0_0 = t_client_rpc;
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"deriche.s", 2496, 0, 0, 0, 2};


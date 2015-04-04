/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/matthias/vex-3.43 -I../include/ -ms -mas_g -mas_t -O2 -fmm=./vliw2.mm -DVEX -o edge_detect" */

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
unsigned int t[1575000];
unsigned int y2[1575000];
unsigned int y1[1575000];

/*********************************
            ENTRY SYMBOLS
*********************************/

extern  deriche_float( unsigned int, unsigned int );
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
  reg_l0_0 = (221 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(451 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 730 */
} /* line 730 */
  sim_icache_fetch(452 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_24, (unsigned int) at); /* line 732 */
   MOV(reg_r0_25, (unsigned int) in); /* line 733 */
} /* line 733 */
  sim_icache_fetch(456 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_4 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_2); /* line 735 */
   MOV(reg_r0_12, t__i32_0); /* line 736 */
} /* line 736 */
  sim_icache_fetch(458 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_12, (unsigned int) -1); /* line 738 */
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 739 */
} /* line 739 */
  sim_icache_fetch(461 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_26, reg_r0_3); /* line 741 */
} /* line 741 */
l_L25X3: ;/* line 744 */
LABEL(l_L25X3);
  sim_icache_fetch(462 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 745 */
   ADD(reg_r0_9, reg_r0_10, reg_r0_11); /* line 746 */
} /* line 746 */
  sim_icache_fetch(464 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 748 */
   SH2ADD(reg_r0_8, reg_r0_12, ((unsigned int) ay2 + (unsigned int) -16)); /* line 749 */
} /* line 749 */
  sim_icache_fetch(467 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 751 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 752 */
  sim_icache_fetch(469 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 754 */
   MOV(reg_r0_6, 0); /* line 755 */
} /* line 755 */
  sim_icache_fetch(471 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_22, 0); /* line 757 */
   MOV(reg_r0_21, 0); /* line 758 */
} /* line 758 */
  sim_icache_fetch(473 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_23, 0); /* line 760 */
   MOV(reg_r0_7, reg_r0_11); /* line 761 */
} /* line 761 */
  sim_icache_fetch(475 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_4); /* line 763 */
   MOV(reg_r0_18, reg_r0_10); /* line 764 */
} /* line 764 */
  sim_icache_fetch(477 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, reg_r0_11); /* line 766 */
   MOV(reg_r0_20, reg_r0_12); /* line 767 */
} /* line 767 */
l_L27X3: ;/* line 770 */
LABEL(l_L27X3);
  sim_icache_fetch(479 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 771 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 772 */
} /* line 772 */
  sim_icache_fetch(481 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -48); /* line 774 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 775 */
} /* line 775 */
  sim_icache_fetch(483 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 777 */
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 778 */
} /* line 778 */
  sim_icache_fetch(485 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 780 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_2); /* line 781 */
} /* line 781 */
  sim_icache_fetch(487 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 783 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 784 */
  sim_icache_fetch(489 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 786 */
   LDBU(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 3),0,1)); /* line 787 */
} /* line 787 */
  sim_icache_fetch(491 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 789 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 790 */
} /* line 790 */
  sim_icache_fetch(493 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 792 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) 215); /* line 793 */
} /* line 793 */
  sim_icache_fetch(495 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 795 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 796 */
} /* line 796 */
  sim_icache_fetch(497 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 798 */
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_9 + (unsigned int) 2),0,1)); /* line 799 */
} /* line 799 */
  sim_icache_fetch(499 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_5); /* line 801 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 802 */
} /* line 802 */
  sim_icache_fetch(501 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 804 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 805 */
} /* line 805 */
  sim_icache_fetch(503 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_13, (unsigned int) -47); /* line 807 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) -155); /* line 808 */
} /* line 808 */
  sim_icache_fetch(505 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 810 */
   MULL(reg_r0_15, reg_r0_12, (unsigned int) 215); /* line 811 */
} /* line 811 */
  sim_icache_fetch(507 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 813 */
   LDBUs(reg_r0_16, mem_trace_ld((reg_r0_9 + (unsigned int) 1),0,1)); /* line 814 */
} /* line 814 */
  sim_icache_fetch(509 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 816 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_11); /* line 817 */
} /* line 817 */
  sim_icache_fetch(511 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_15); /* line 819 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 820 */
} /* line 820 */
  sim_icache_fetch(513 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 822 */
   MULL(reg_r0_10, reg_r0_12, (unsigned int) -155); /* line 823 */
} /* line 823 */
  sim_icache_fetch(515 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_16, (unsigned int) -47); /* line 825 */
   MULL(reg_r0_15, reg_r0_14, (unsigned int) 215); /* line 826 */
} /* line 826 */
  sim_icache_fetch(517 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_13, (unsigned int) -48); /* line 828 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 829 */
} /* line 829 */
  sim_icache_fetch(519 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 831 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 832 */
} /* line 832 */
  sim_icache_fetch(521 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 834 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_9,0,1)); /* line 835 */
} /* line 835 */
  sim_icache_fetch(523 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_14); /* line 837 */
   ADD(reg_r0_5, reg_r0_11, reg_r0_13); /* line 838 */
} /* line 838 */
  sim_icache_fetch(525 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_16); /* line 840 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 841 */
} /* line 841 */
  sim_icache_fetch(527 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 843 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -4); /* line 844 */
} /* line 844 */
  sim_icache_fetch(529 + t_thisfile.offset, 1);
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
} /* line 846 */
  sim_icache_fetch(530 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_12); /* line 848 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 849 */
  sim_icache_fetch(532 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_14); /* line 851 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 852 */
  sim_icache_fetch(534 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_5); /* line 854 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 856 */
} /* line 856 */
  sim_icache_fetch(536 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L27X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L27X3;
} /* line 858 */
l_L28X3: ;/* line 861 */
LABEL(l_L28X3);
  sim_icache_fetch(537 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_20); /* line 862 */
   MOV(reg_r0_10, reg_r0_24); /* line 863 */
} /* line 863 */
  sim_icache_fetch(539 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_3); /* line 865 */
   MOV(reg_r0_8, (unsigned int) ay2); /* line 866 */
} /* line 866 */
  sim_icache_fetch(542 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, (unsigned int) ay1); /* line 868 */
   MOV(reg_r0_2, reg_r0_25); /* line 869 */
} /* line 869 */
  sim_icache_fetch(545 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_21); /* line 871 */
   MOV(reg_r0_4, reg_r0_22); /* line 872 */
} /* line 872 */
  sim_icache_fetch(547 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_23); /* line 874 */
   MOV(reg_r0_21, reg_r0_20); /* line 875 */
} /* line 875 */
  sim_icache_fetch(549 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_17); /* line 877 */
} /* line 877 */
l_L29X3: ;/* line 880 */
LABEL(l_L29X3);
  sim_icache_fetch(550 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 881 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 215); /* line 882 */
} /* line 882 */
  sim_icache_fetch(552 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 884 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -155); /* line 885 */
} /* line 885 */
  sim_icache_fetch(554 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 887 */
   LDWs(reg_r0_12, mem_trace_ld(reg_r0_8,0,4)); /* line 888 */
} /* line 888 */
  sim_icache_fetch(556 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -48); /* line 890 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 8); /* line 891 */
} /* line 891 */
  sim_icache_fetch(558 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_9, (unsigned int) 2); /* line 893 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 894 */
} /* line 894 */
  sim_icache_fetch(560 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_5); /* line 896 */
   CMPLT(reg_b0_1, reg_r0_9, (unsigned int) 1); /* line 897 */
} /* line 897 */
  sim_icache_fetch(562 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_13); /* line 899 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L30X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 900 */
  sim_icache_fetch(564 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_7, reg_r0_12); /* line 902 */
   LDBUs(reg_r0_5, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 903 */
} /* line 903 */
  sim_icache_fetch(566 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 905 */
   MULL(reg_r0_13, reg_r0_7, (unsigned int) 215); /* line 906 */
} /* line 906 */
  sim_icache_fetch(568 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 908 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 909 */
} /* line 909 */
  sim_icache_fetch(570 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -48); /* line 911 */
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 912 */
} /* line 912 */
  sim_icache_fetch(572 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 914 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 915 */
} /* line 915 */
  sim_icache_fetch(574 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_13); /* line 917 */
   LDWs(reg_r0_13, mem_trace_ld((reg_r0_8 + (unsigned int) 4),0,4)); /* line 918 */
} /* line 918 */
  sim_icache_fetch(576 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 920 */
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 921 */
} /* line 921 */
  sim_icache_fetch(578 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_14); /* line 923 */
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 924 */
} /* line 924 */
  sim_icache_fetch(580 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_3, reg_r0_13); /* line 926 */
   MULL(reg_r0_15, reg_r0_3, (unsigned int) 215); /* line 927 */
} /* line 927 */
  sim_icache_fetch(582 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 929 */
   MULL(reg_r0_16, reg_r0_7, (unsigned int) -155); /* line 930 */
} /* line 930 */
  sim_icache_fetch(584 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 932 */
   MULL(reg_r0_17, reg_r0_14, (unsigned int) -48); /* line 933 */
} /* line 933 */
  sim_icache_fetch(586 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 935 */
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 936 */
} /* line 936 */
  sim_icache_fetch(588 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 28); /* line 938 */
   ADD(reg_r0_17, reg_r0_17, reg_r0_15); /* line 939 */
} /* line 939 */
  sim_icache_fetch(590 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_3); /* line 941 */
   LDWs(reg_r0_15, mem_trace_ld((reg_r0_8 + (unsigned int) 8),0,4)); /* line 942 */
} /* line 942 */
  sim_icache_fetch(592 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_16); /* line 944 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 3); /* line 945 */
} /* line 945 */
  sim_icache_fetch(594 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_5, reg_r0_17); /* line 947 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 12); /* line 948 */
} /* line 948 */
  sim_icache_fetch(596 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_15, reg_r0_4, reg_r0_15); /* line 950 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 3); /* line 951 */
} /* line 951 */
  sim_icache_fetch(598 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_11,0,4), reg_r0_7); /* line 953 */
   SHL(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 954 */
} /* line 954 */
  sim_icache_fetch(600 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 956 */
   MOV(reg_r0_7, reg_r0_14); /* line 957 */
} /* line 957 */
  sim_icache_fetch(602 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_12); /* line 959 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L30X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 960 */
  sim_icache_fetch(604 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 4),0,4), reg_r0_3); /* line 962 */
} /* line 962 */
  sim_icache_fetch(605 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4),0,4), reg_r0_13); /* line 964 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L30X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 965 */
  sim_icache_fetch(607 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 8),0,4), reg_r0_4); /* line 967 */
   ADD(reg_r0_11, reg_r0_11, (unsigned int) 12); /* line 968 */
} /* line 968 */
  sim_icache_fetch(609 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 8),0,4), reg_r0_15); /* line 970 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 12); /* line 972 */
} /* line 972 */
  sim_icache_fetch(611 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L29X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L29X3;
} /* line 974 */
l_L30X3: ;/* line 977 */
LABEL(l_L30X3);
  sim_icache_fetch(612 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_24, reg_r0_24, (unsigned int) 4200); /* line 978 */
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 1050); /* line 979 */
} /* line 979 */
  sim_icache_fetch(616 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_20, (unsigned int) 1); /* line 981 */
   ADD(reg_r0_10, reg_r0_18, (unsigned int) 1050); /* line 982 */
} /* line 982 */
  sim_icache_fetch(619 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_12, reg_r0_21); /* line 984 */
   MOV(reg_r0_11, reg_r0_19); /* line 986 */
} /* line 986 */
  sim_icache_fetch(621 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L25X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L25X3;
} /* line 988 */
l_L26X3: ;/* line 991 */
LABEL(l_L26X3);
  sim_icache_fetch(622 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_12, 0, reg_r0_12); /* line 992 */
   MOV(reg_r0_23, (unsigned int) at); /* line 993 */
} /* line 993 */
  sim_icache_fetch(625 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_12); /* line 995 */
   MOV(reg_r0_22, (unsigned int) out); /* line 996 */
} /* line 996 */
  sim_icache_fetch(628 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_26, (unsigned int) -1); /* line 998 */
   MOV(reg_r0_12, ((unsigned int) at + (unsigned int) -12600)); /* line 999 */
} /* line 999 */
  sim_icache_fetch(631 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_26); /* line 1001 */
} /* line 1001 */
l_L31X3: ;/* line 1004 */
LABEL(l_L31X3);
  sim_icache_fetch(632 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 1005 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 4200); /* line 1006 */
} /* line 1006 */
  sim_icache_fetch(635 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 1008 */
   SH2ADD(reg_r0_8, reg_r0_13, ((unsigned int) by2 + (unsigned int) -16)); /* line 1009 */
} /* line 1009 */
  sim_icache_fetch(638 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 1011 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1012 */
  sim_icache_fetch(640 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, 0); /* line 1014 */
   MOV(reg_r0_5, 0); /* line 1015 */
} /* line 1015 */
  sim_icache_fetch(642 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, 0); /* line 1017 */
   MOV(reg_r0_2, 0); /* line 1018 */
} /* line 1018 */
  sim_icache_fetch(644 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, 0); /* line 1020 */
   MOV(reg_r0_20, 0); /* line 1021 */
} /* line 1021 */
  sim_icache_fetch(646 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_10); /* line 1023 */
   MOV(reg_r0_15, reg_r0_4); /* line 1024 */
} /* line 1024 */
  sim_icache_fetch(648 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_16, reg_r0_10); /* line 1026 */
   MOV(reg_r0_17, reg_r0_12); /* line 1027 */
} /* line 1027 */
  sim_icache_fetch(650 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_13); /* line 1029 */
} /* line 1029 */
l_L33X3: ;/* line 1032 */
LABEL(l_L33X3);
  sim_icache_fetch(651 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 1033 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 1034 */
} /* line 1034 */
  sim_icache_fetch(653 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 1036 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 29); /* line 1037 */
} /* line 1037 */
  sim_icache_fetch(655 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1039 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 1040 */
} /* line 1040 */
  sim_icache_fetch(657 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 1042 */
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 12600),0,4)); /* line 1043 */
} /* line 1043 */
  sim_icache_fetch(660 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 1045 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L34X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1046 */
  sim_icache_fetch(662 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1048 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 1049 */
} /* line 1049 */
  sim_icache_fetch(664 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1051 */
   MULL(reg_r0_10, reg_r0_4, (unsigned int) -47); /* line 1052 */
} /* line 1052 */
  sim_icache_fetch(666 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 1054 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 1055 */
} /* line 1055 */
  sim_icache_fetch(668 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 1057 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 8400),0,4)); /* line 1058 */
} /* line 1058 */
  sim_icache_fetch(671 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 1060 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 1061 */
} /* line 1061 */
  sim_icache_fetch(673 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 1063 */
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 1064 */
} /* line 1064 */
  sim_icache_fetch(675 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1066 */
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 1067 */
} /* line 1067 */
  sim_icache_fetch(677 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_5, (unsigned int) 215); /* line 1069 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 29); /* line 1070 */
} /* line 1070 */
  sim_icache_fetch(679 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 1072 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,4)); /* line 1073 */
} /* line 1073 */
  sim_icache_fetch(682 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_4); /* line 1075 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 1076 */
} /* line 1076 */
  sim_icache_fetch(684 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 1078 */
   MULL(reg_r0_4, reg_r0_5, (unsigned int) -155); /* line 1079 */
} /* line 1079 */
  sim_icache_fetch(686 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1081 */
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 1082 */
} /* line 1082 */
  sim_icache_fetch(688 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 1084 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 1085 */
} /* line 1085 */
  sim_icache_fetch(690 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 1087 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_9,0,4)); /* line 1088 */
} /* line 1088 */
  sim_icache_fetch(692 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_12); /* line 1090 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 1091 */
} /* line 1091 */
  sim_icache_fetch(694 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 1093 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 1094 */
} /* line 1094 */
  sim_icache_fetch(696 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_2); /* line 1096 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1097 */
} /* line 1097 */
  sim_icache_fetch(698 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_11); /* line 1099 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L35X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1100 */
  sim_icache_fetch(700 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_5); /* line 1102 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -16800); /* line 1103 */
} /* line 1103 */
  sim_icache_fetch(703 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_4); /* line 1105 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L36X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1106 */
  sim_icache_fetch(705 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_11); /* line 1108 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L37X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1109 */
  sim_icache_fetch(707 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 1111 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 1113 */
} /* line 1113 */
  sim_icache_fetch(709 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L33X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L33X3;
} /* line 1115 */
l_L37X3: ;/* line 1118 */
LABEL(l_L37X3);
  sim_icache_fetch(710 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 1119 */
   MOV(reg_r0_9, reg_r0_22); /* line 1121 */
} /* line 1121 */
  sim_icache_fetch(712 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L38X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L38X3;
} /* line 1123 */
l_L39X3: ;/* line 1126 */
LABEL(l_L39X3);
  sim_icache_fetch(713 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1127 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 1128 */
} /* line 1128 */
  sim_icache_fetch(715 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_5, (unsigned int) 215); /* line 1130 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 1131 */
} /* line 1131 */
  sim_icache_fetch(717 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 1133 */
   LDWs(reg_r0_12, mem_trace_ld(reg_r0_7,0,4)); /* line 1134 */
} /* line 1134 */
  sim_icache_fetch(719 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -48); /* line 1136 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_6); /* line 1137 */
} /* line 1137 */
  sim_icache_fetch(721 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, 0); /* line 1139 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L40X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1140 */
  sim_icache_fetch(723 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 1142 */
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 1143 */
} /* line 1143 */
  sim_icache_fetch(726 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_11); /* line 1145 */
   MULL(reg_r0_13, reg_r0_5, (unsigned int) -155); /* line 1146 */
} /* line 1146 */
  sim_icache_fetch(728 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1148 */
   MULL(reg_r0_11, reg_r0_3, (unsigned int) 28); /* line 1149 */
} /* line 1149 */
  sim_icache_fetch(730 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_4, reg_r0_12); /* line 1151 */
   MULL(reg_r0_14, reg_r0_6, (unsigned int) -48); /* line 1152 */
} /* line 1152 */
  sim_icache_fetch(732 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1154 */
   MULL(reg_r0_15, reg_r0_4, (unsigned int) 215); /* line 1155 */
} /* line 1155 */
  sim_icache_fetch(734 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 1157 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_14); /* line 1158 */
} /* line 1158 */
  sim_icache_fetch(736 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_14, reg_r0_12); /* line 1160 */
   ADD(reg_r0_15, reg_r0_15, reg_r0_11); /* line 1161 */
} /* line 1161 */
  sim_icache_fetch(738 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_1, reg_r0_14, (unsigned int) 25); /* line 1163 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 1164 */
} /* line 1164 */
  sim_icache_fetch(740 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_15, reg_r0_4); /* line 1166 */
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_7 + (unsigned int) 4),0,4)); /* line 1167 */
} /* line 1167 */
  sim_icache_fetch(742 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_12); /* line 1169 */
} /* line 1169 */
  sim_icache_fetch(743 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_4); /* line 1171 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L41X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1172 */
  sim_icache_fetch(745 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_13, (unsigned int) 8); /* line 1174 */
   MOV(reg_r0_4, reg_r0_15); /* line 1175 */
} /* line 1175 */
  sim_icache_fetch(747 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), 0); /* line 1177 */
   ADD(reg_r0_11, reg_r0_5, reg_r0_11); /* line 1178 */
} /* line 1178 */
l_L42X3: ;/* line 1180 */
LABEL(l_L42X3);
  sim_icache_fetch(749 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1181 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L43X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1182 */
  sim_icache_fetch(751 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4),0,4), reg_r0_5); /* line 1184 */
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 1185 */
} /* line 1185 */
  sim_icache_fetch(753 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_11); /* line 1187 */
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_11); /* line 1188 */
} /* line 1188 */
  sim_icache_fetch(756 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 1190 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1191 */
   ADD_CYCLES(1);
} /* line 1191 */
  sim_icache_fetch(758 + t_thisfile.offset, 1);
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
} /* line 1193 */
  sim_icache_fetch(759 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1195 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 8400); /* line 1196 */
} /* line 1196 */
  sim_icache_fetch(762 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 1198 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 1199 */
} /* line 1199 */
  sim_icache_fetch(764 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), 0); /* line 1201 */
} /* line 1201 */
l_L45X3: ;/* line 1203 */
LABEL(l_L45X3);
  sim_icache_fetch(766 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 2100); /* line 1204 */
   GOTO(l_L39X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L39X3;
} /* line 1205 */
l_L44X3: ;/* line 1208 */
LABEL(l_L44X3);
  sim_icache_fetch(769 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 1209 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1210 */
} /* line 1210 */
  sim_icache_fetch(771 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 1212 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1213 */
} /* line 1213 */
  sim_icache_fetch(773 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_3); /* line 1215 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 8400); /* line 1217 */
} /* line 1217 */
  sim_icache_fetch(777 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L45X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L45X3;
} /* line 1219 */
l_L43X3: ;/* line 1222 */
LABEL(l_L43X3);
  sim_icache_fetch(778 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_22, reg_r0_22, (unsigned int) 1); /* line 1223 */
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 4); /* line 1225 */
} /* line 1225 */
  sim_icache_fetch(780 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L46X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L46X3;
} /* line 1227 */
l_L41X3: ;/* line 1230 */
LABEL(l_L41X3);
  sim_icache_fetch(781 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_13, (unsigned int) 8); /* line 1231 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1232 */
} /* line 1232 */
  sim_icache_fetch(783 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_5, reg_r0_11); /* line 1234 */
   MOV(reg_r0_4, reg_r0_15); /* line 1235 */
} /* line 1235 */
  sim_icache_fetch(785 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_3); /* line 1237 */
   GOTO(l_L42X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L42X3;
} /* line 1238 */
l_L40X3: ;/* line 1241 */
LABEL(l_L40X3);
  sim_icache_fetch(787 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_22, reg_r0_22, (unsigned int) 1); /* line 1242 */
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 4); /* line 1243 */
} /* line 1243 */
l_L46X3: ;/* line 1245 */
LABEL(l_L46X3);
  sim_icache_fetch(789 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_18, (unsigned int) 1); /* line 1246 */
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 1247 */
} /* line 1247 */
  sim_icache_fetch(791 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, reg_r0_16); /* line 1249 */
   MOV(reg_r0_13, reg_r0_19); /* line 1251 */
} /* line 1251 */
  sim_icache_fetch(793 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L31X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L31X3;
} /* line 1253 */
l_L36X3: ;/* line 1256 */
LABEL(l_L36X3);
  sim_icache_fetch(794 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 1257 */
   MOV(reg_r0_9, reg_r0_22); /* line 1259 */
} /* line 1259 */
  sim_icache_fetch(796 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L38X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L38X3;
} /* line 1261 */
l_L35X3: ;/* line 1264 */
LABEL(l_L35X3);
  sim_icache_fetch(797 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 1265 */
   MOV(reg_r0_9, reg_r0_22); /* line 1267 */
} /* line 1267 */
  sim_icache_fetch(799 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L38X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L38X3;
} /* line 1269 */
l_L34X3: ;/* line 1272 */
LABEL(l_L34X3);
  sim_icache_fetch(800 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 1273 */
   MOV(reg_r0_9, reg_r0_22); /* line 1274 */
} /* line 1274 */
l_L38X3: ;/* line 1276 */
LABEL(l_L38X3);
  sim_icache_fetch(802 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_3); /* line 1277 */
   MOV(reg_r0_7, (unsigned int) by2); /* line 1278 */
} /* line 1278 */
  sim_icache_fetch(805 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, (unsigned int) by1); /* line 1280 */
   MOV(reg_r0_2, reg_r0_23); /* line 1281 */
} /* line 1281 */
  sim_icache_fetch(808 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_20); /* line 1283 */
   MOV(reg_r0_5, reg_r0_19); /* line 1284 */
} /* line 1284 */
  sim_icache_fetch(810 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_21); /* line 1286 */
   MOV(reg_r0_19, reg_r0_18); /* line 1287 */
} /* line 1287 */
  sim_icache_fetch(812 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_18, reg_r0_15); /* line 1289 */
   GOTO(l_L39X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L39X3;
} /* line 1290 */
l_L32X3: ;/* line 1293 */
LABEL(l_L32X3);
  sim_icache_fetch(814 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_array);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1295 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 199: goto l_L25X3;
    case 200: goto l_L27X3;
    case 201: goto l_L28X3;
    case 202: goto l_L29X3;
    case 203: goto l_L30X3;
    case 204: goto l_L26X3;
    case 205: goto l_L31X3;
    case 206: goto l_L33X3;
    case 207: goto l_L37X3;
    case 208: goto l_L39X3;
    case 209: goto l_L42X3;
    case 210: goto l_L45X3;
    case 211: goto l_L44X3;
    case 212: goto l_L43X3;
    case 213: goto l_L41X3;
    case 214: goto l_L40X3;
    case 215: goto l_L46X3;
    case 216: goto l_L36X3;
    case 217: goto l_L35X3;
    case 218: goto l_L34X3;
    case 219: goto l_L38X3;
    case 220: goto l_L32X3;
    case 221:
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
  reg_l0_0 = (244 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(815 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 1311 */
} /* line 1311 */
  sim_icache_fetch(816 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_27, (unsigned int) qy1); /* line 1313 */
   MOV(reg_r0_28, (unsigned int) in); /* line 1314 */
} /* line 1314 */
  sim_icache_fetch(820 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_4 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_2); /* line 1316 */
   MOV(reg_r0_24, t__i32_0); /* line 1317 */
} /* line 1317 */
  sim_icache_fetch(822 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_25, (unsigned int) qt); /* line 1319 */
   MOV(reg_r0_26, (unsigned int) qy2); /* line 1320 */
} /* line 1320 */
  sim_icache_fetch(826 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_24, (unsigned int) -1); /* line 1322 */
   MOV(reg_r0_12, ((unsigned int) qy2 + (unsigned int) -12)); /* line 1323 */
} /* line 1323 */
  sim_icache_fetch(829 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 1325 */
   MOV(reg_r0_29, reg_r0_3); /* line 1326 */
} /* line 1326 */
l_L47X3: ;/* line 1329 */
LABEL(l_L47X3);
  sim_icache_fetch(832 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 1330 */
   ADD(reg_r0_9, reg_r0_10, reg_r0_11); /* line 1331 */
} /* line 1331 */
  sim_icache_fetch(834 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 1333 */
   SH2ADD(reg_r0_8, reg_r0_11, reg_r0_12); /* line 1334 */
} /* line 1334 */
  sim_icache_fetch(836 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 1336 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1337 */
  sim_icache_fetch(838 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 1339 */
   MOV(reg_r0_6, 0); /* line 1340 */
} /* line 1340 */
  sim_icache_fetch(840 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_22, 0); /* line 1342 */
   MOV(reg_r0_21, 0); /* line 1343 */
} /* line 1343 */
  sim_icache_fetch(842 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_23, 0); /* line 1345 */
   MOV(reg_r0_7, reg_r0_11); /* line 1346 */
} /* line 1346 */
  sim_icache_fetch(844 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_4); /* line 1348 */
   MOV(reg_r0_18, reg_r0_10); /* line 1349 */
} /* line 1349 */
  sim_icache_fetch(846 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, reg_r0_11); /* line 1351 */
   MOV(reg_r0_20, reg_r0_12); /* line 1352 */
} /* line 1352 */
l_L49X3: ;/* line 1355 */
LABEL(l_L49X3);
  sim_icache_fetch(848 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 1356 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 1357 */
} /* line 1357 */
  sim_icache_fetch(850 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -48); /* line 1359 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 1360 */
} /* line 1360 */
  sim_icache_fetch(852 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1362 */
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1363 */
} /* line 1363 */
  sim_icache_fetch(854 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1365 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_2); /* line 1366 */
} /* line 1366 */
  sim_icache_fetch(856 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 1368 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1369 */
  sim_icache_fetch(858 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 1371 */
   LDBU(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 3),0,1)); /* line 1372 */
} /* line 1372 */
  sim_icache_fetch(860 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 1374 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1375 */
} /* line 1375 */
  sim_icache_fetch(862 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 1377 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) 215); /* line 1378 */
} /* line 1378 */
  sim_icache_fetch(864 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 1380 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1381 */
} /* line 1381 */
  sim_icache_fetch(866 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1383 */
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_9 + (unsigned int) 2),0,1)); /* line 1384 */
} /* line 1384 */
  sim_icache_fetch(868 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_5); /* line 1386 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 1387 */
} /* line 1387 */
  sim_icache_fetch(870 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 1389 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 1390 */
} /* line 1390 */
  sim_icache_fetch(872 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_13, (unsigned int) -47); /* line 1392 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) -155); /* line 1393 */
} /* line 1393 */
  sim_icache_fetch(874 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 1395 */
   MULL(reg_r0_15, reg_r0_12, (unsigned int) 215); /* line 1396 */
} /* line 1396 */
  sim_icache_fetch(876 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1398 */
   LDBUs(reg_r0_16, mem_trace_ld((reg_r0_9 + (unsigned int) 1),0,1)); /* line 1399 */
} /* line 1399 */
  sim_icache_fetch(878 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1401 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_11); /* line 1402 */
} /* line 1402 */
  sim_icache_fetch(880 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_15); /* line 1404 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 1405 */
} /* line 1405 */
  sim_icache_fetch(882 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 1407 */
   MULL(reg_r0_10, reg_r0_12, (unsigned int) -155); /* line 1408 */
} /* line 1408 */
  sim_icache_fetch(884 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_16, (unsigned int) -47); /* line 1410 */
   MULL(reg_r0_15, reg_r0_14, (unsigned int) 215); /* line 1411 */
} /* line 1411 */
  sim_icache_fetch(886 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_13, (unsigned int) -48); /* line 1413 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1414 */
} /* line 1414 */
  sim_icache_fetch(888 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1416 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 1417 */
} /* line 1417 */
  sim_icache_fetch(890 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 1419 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_9,0,1)); /* line 1420 */
} /* line 1420 */
  sim_icache_fetch(892 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_14); /* line 1422 */
   ADD(reg_r0_5, reg_r0_11, reg_r0_13); /* line 1423 */
} /* line 1423 */
  sim_icache_fetch(894 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_16); /* line 1425 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 1426 */
} /* line 1426 */
  sim_icache_fetch(896 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 1428 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -4); /* line 1429 */
} /* line 1429 */
  sim_icache_fetch(898 + t_thisfile.offset, 1);
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
} /* line 1431 */
  sim_icache_fetch(899 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_12); /* line 1433 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1434 */
  sim_icache_fetch(901 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_14); /* line 1436 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1437 */
  sim_icache_fetch(903 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_5); /* line 1439 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 1441 */
} /* line 1441 */
  sim_icache_fetch(905 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L49X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L49X3;
} /* line 1443 */
l_L50X3: ;/* line 1446 */
LABEL(l_L50X3);
  sim_icache_fetch(906 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_24); /* line 1447 */
   MOV(reg_r0_10, reg_r0_25); /* line 1448 */
} /* line 1448 */
  sim_icache_fetch(908 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_3); /* line 1450 */
   MOV(reg_r0_8, reg_r0_26); /* line 1451 */
} /* line 1451 */
  sim_icache_fetch(910 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, reg_r0_27); /* line 1453 */
   MOV(reg_r0_2, reg_r0_28); /* line 1454 */
} /* line 1454 */
  sim_icache_fetch(912 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_21); /* line 1456 */
   MOV(reg_r0_4, reg_r0_22); /* line 1457 */
} /* line 1457 */
  sim_icache_fetch(914 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, reg_r0_17); /* line 1459 */
   MOV(reg_r0_6, reg_r0_23); /* line 1460 */
} /* line 1460 */
l_L51X3: ;/* line 1463 */
LABEL(l_L51X3);
  sim_icache_fetch(916 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 1464 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 215); /* line 1465 */
} /* line 1465 */
  sim_icache_fetch(918 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 1467 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -155); /* line 1468 */
} /* line 1468 */
  sim_icache_fetch(920 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1470 */
   LDWs(reg_r0_12, mem_trace_ld(reg_r0_8,0,4)); /* line 1471 */
} /* line 1471 */
  sim_icache_fetch(922 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -48); /* line 1473 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 8); /* line 1474 */
} /* line 1474 */
  sim_icache_fetch(924 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_9, (unsigned int) 2); /* line 1476 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 1477 */
} /* line 1477 */
  sim_icache_fetch(926 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_5); /* line 1479 */
   CMPLT(reg_b0_1, reg_r0_9, (unsigned int) 1); /* line 1480 */
} /* line 1480 */
  sim_icache_fetch(928 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_13); /* line 1482 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1483 */
  sim_icache_fetch(930 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_7, reg_r0_12); /* line 1485 */
   LDBUs(reg_r0_5, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 1486 */
} /* line 1486 */
  sim_icache_fetch(932 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1488 */
   MULL(reg_r0_13, reg_r0_7, (unsigned int) 215); /* line 1489 */
} /* line 1489 */
  sim_icache_fetch(934 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1491 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1492 */
} /* line 1492 */
  sim_icache_fetch(936 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -48); /* line 1494 */
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1495 */
} /* line 1495 */
  sim_icache_fetch(938 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 1497 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1498 */
} /* line 1498 */
  sim_icache_fetch(940 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_13); /* line 1500 */
   LDWs(reg_r0_13, mem_trace_ld((reg_r0_8 + (unsigned int) 4),0,4)); /* line 1501 */
} /* line 1501 */
  sim_icache_fetch(942 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 1503 */
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 1504 */
} /* line 1504 */
  sim_icache_fetch(944 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_14); /* line 1506 */
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 1507 */
} /* line 1507 */
  sim_icache_fetch(946 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_3, reg_r0_13); /* line 1509 */
   MULL(reg_r0_15, reg_r0_3, (unsigned int) 215); /* line 1510 */
} /* line 1510 */
  sim_icache_fetch(948 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1512 */
   MULL(reg_r0_16, reg_r0_7, (unsigned int) -155); /* line 1513 */
} /* line 1513 */
  sim_icache_fetch(950 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1515 */
   MULL(reg_r0_17, reg_r0_14, (unsigned int) -48); /* line 1516 */
} /* line 1516 */
  sim_icache_fetch(952 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1518 */
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 1519 */
} /* line 1519 */
  sim_icache_fetch(954 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 28); /* line 1521 */
   ADD(reg_r0_17, reg_r0_17, reg_r0_15); /* line 1522 */
} /* line 1522 */
  sim_icache_fetch(956 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_3); /* line 1524 */
   LDWs(reg_r0_15, mem_trace_ld((reg_r0_8 + (unsigned int) 8),0,4)); /* line 1525 */
} /* line 1525 */
  sim_icache_fetch(958 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_16); /* line 1527 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 3); /* line 1528 */
} /* line 1528 */
  sim_icache_fetch(960 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_5, reg_r0_17); /* line 1530 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 12); /* line 1531 */
} /* line 1531 */
  sim_icache_fetch(962 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_15, reg_r0_4, reg_r0_15); /* line 1533 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 3); /* line 1534 */
} /* line 1534 */
  sim_icache_fetch(964 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_11,0,4), reg_r0_7); /* line 1536 */
   SHL(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1537 */
} /* line 1537 */
  sim_icache_fetch(966 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1539 */
   MOV(reg_r0_7, reg_r0_14); /* line 1540 */
} /* line 1540 */
  sim_icache_fetch(968 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_12); /* line 1542 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1543 */
  sim_icache_fetch(970 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 4),0,4), reg_r0_3); /* line 1545 */
} /* line 1545 */
  sim_icache_fetch(971 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4),0,4), reg_r0_13); /* line 1547 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1548 */
  sim_icache_fetch(973 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 8),0,4), reg_r0_4); /* line 1550 */
   ADD(reg_r0_11, reg_r0_11, (unsigned int) 12); /* line 1551 */
} /* line 1551 */
  sim_icache_fetch(975 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 8),0,4), reg_r0_15); /* line 1553 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 12); /* line 1555 */
} /* line 1555 */
  sim_icache_fetch(977 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L51X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L51X3;
} /* line 1557 */
l_L52X3: ;/* line 1560 */
LABEL(l_L52X3);
  sim_icache_fetch(978 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_28, reg_r0_28, (unsigned int) 1050); /* line 1561 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 1562 */
} /* line 1562 */
  sim_icache_fetch(982 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_26, reg_r0_26, reg_r0_2); /* line 1564 */
   ADD(reg_r0_27, reg_r0_27, reg_r0_2); /* line 1565 */
} /* line 1565 */
  sim_icache_fetch(984 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_25, reg_r0_25, reg_r0_2); /* line 1567 */
   ADD(reg_r0_12, reg_r0_20, reg_r0_2); /* line 1568 */
} /* line 1568 */
  sim_icache_fetch(986 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 1570 */
   ADD(reg_r0_10, reg_r0_18, (unsigned int) 1050); /* line 1571 */
} /* line 1571 */
  sim_icache_fetch(989 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, reg_r0_19); /* line 1573 */
   GOTO(l_L47X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L47X3;
} /* line 1574 */
l_L48X3: ;/* line 1577 */
LABEL(l_L48X3);
  sim_icache_fetch(991 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_24, 0, reg_r0_24); /* line 1578 */
   MOV(reg_r0_26, (unsigned int) qt); /* line 1579 */
} /* line 1579 */
  sim_icache_fetch(994 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_24); /* line 1581 */
   MOV(reg_r0_25, (unsigned int) qy1); /* line 1582 */
} /* line 1582 */
  sim_icache_fetch(997 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_23, (unsigned int) out); /* line 1584 */
   MOV(reg_r0_24, (unsigned int) qy2); /* line 1585 */
} /* line 1585 */
  sim_icache_fetch(1001 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_13, ((unsigned int) qy2 + (unsigned int) -12600)); /* line 1587 */
   MOV(reg_r0_12, ((unsigned int) qt + (unsigned int) -12600)); /* line 1588 */
} /* line 1588 */
  sim_icache_fetch(1005 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_29, (unsigned int) -1); /* line 1590 */
   MOV(reg_r0_22, reg_r0_29); /* line 1591 */
} /* line 1591 */
l_L53X3: ;/* line 1594 */
LABEL(l_L53X3);
  sim_icache_fetch(1007 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 1595 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 4200); /* line 1596 */
} /* line 1596 */
  sim_icache_fetch(1010 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 1598 */
   MOV(reg_r0_6, 0); /* line 1599 */
} /* line 1599 */
  sim_icache_fetch(1012 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 1601 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L54X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1602 */
  sim_icache_fetch(1014 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 1604 */
   ADD(reg_r0_8, reg_r0_13, reg_r0_11); /* line 1605 */
} /* line 1605 */
  sim_icache_fetch(1016 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, 0); /* line 1607 */
   MOV(reg_r0_2, 0); /* line 1608 */
} /* line 1608 */
  sim_icache_fetch(1018 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, 0); /* line 1610 */
   MOV(reg_r0_20, 0); /* line 1611 */
} /* line 1611 */
  sim_icache_fetch(1020 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_10); /* line 1613 */
   MOV(reg_r0_15, reg_r0_4); /* line 1614 */
} /* line 1614 */
  sim_icache_fetch(1022 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_16, reg_r0_10); /* line 1616 */
   MOV(reg_r0_17, reg_r0_12); /* line 1617 */
} /* line 1617 */
  sim_icache_fetch(1024 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_13); /* line 1619 */
} /* line 1619 */
l_L55X3: ;/* line 1622 */
LABEL(l_L55X3);
  sim_icache_fetch(1025 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 1623 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 1624 */
} /* line 1624 */
  sim_icache_fetch(1027 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 1626 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 29); /* line 1627 */
} /* line 1627 */
  sim_icache_fetch(1029 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1629 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 1630 */
} /* line 1630 */
  sim_icache_fetch(1031 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 1632 */
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 12600),0,4)); /* line 1633 */
} /* line 1633 */
  sim_icache_fetch(1034 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 1635 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L56X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1636 */
  sim_icache_fetch(1036 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1638 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 1639 */
} /* line 1639 */
  sim_icache_fetch(1038 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1641 */
   MULL(reg_r0_10, reg_r0_4, (unsigned int) -47); /* line 1642 */
} /* line 1642 */
  sim_icache_fetch(1040 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 1644 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 1645 */
} /* line 1645 */
  sim_icache_fetch(1042 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 1647 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 8400),0,4)); /* line 1648 */
} /* line 1648 */
  sim_icache_fetch(1045 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 1650 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 1651 */
} /* line 1651 */
  sim_icache_fetch(1047 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 1653 */
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 1654 */
} /* line 1654 */
  sim_icache_fetch(1049 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1656 */
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 1657 */
} /* line 1657 */
  sim_icache_fetch(1051 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_5, (unsigned int) 215); /* line 1659 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 29); /* line 1660 */
} /* line 1660 */
  sim_icache_fetch(1053 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 1662 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,4)); /* line 1663 */
} /* line 1663 */
  sim_icache_fetch(1056 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_4); /* line 1665 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 1666 */
} /* line 1666 */
  sim_icache_fetch(1058 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 1668 */
   MULL(reg_r0_4, reg_r0_5, (unsigned int) -155); /* line 1669 */
} /* line 1669 */
  sim_icache_fetch(1060 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1671 */
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 1672 */
} /* line 1672 */
  sim_icache_fetch(1062 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 1674 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 1675 */
} /* line 1675 */
  sim_icache_fetch(1064 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 1677 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_9,0,4)); /* line 1678 */
} /* line 1678 */
  sim_icache_fetch(1066 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 1680 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 1681 */
} /* line 1681 */
  sim_icache_fetch(1068 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_2); /* line 1683 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 1684 */
} /* line 1684 */
  sim_icache_fetch(1071 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1686 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L57X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1687 */
  sim_icache_fetch(1073 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_11); /* line 1689 */
   MOV(reg_r0_6, reg_r0_12); /* line 1690 */
} /* line 1690 */
  sim_icache_fetch(1075 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_5); /* line 1692 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -16800); /* line 1693 */
} /* line 1693 */
  sim_icache_fetch(1079 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_4); /* line 1695 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L58X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1696 */
  sim_icache_fetch(1081 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_11); /* line 1698 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L59X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1699 */
  sim_icache_fetch(1084 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 1701 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16800); /* line 1703 */
} /* line 1703 */
  sim_icache_fetch(1087 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L55X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L55X3;
} /* line 1705 */
l_L59X3: ;/* line 1708 */
LABEL(l_L59X3);
  sim_icache_fetch(1088 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_22); /* line 1709 */
   MOV(reg_r0_9, reg_r0_23); /* line 1711 */
} /* line 1711 */
  sim_icache_fetch(1090 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L60X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L60X3;
} /* line 1713 */
l_L61X3: ;/* line 1716 */
LABEL(l_L61X3);
  sim_icache_fetch(1091 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1717 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 1718 */
} /* line 1718 */
  sim_icache_fetch(1093 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_5, (unsigned int) 215); /* line 1720 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 1721 */
} /* line 1721 */
  sim_icache_fetch(1095 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 1723 */
   LDWs(reg_r0_13, mem_trace_ld(reg_r0_7,0,4)); /* line 1724 */
} /* line 1724 */
  sim_icache_fetch(1097 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_3, (unsigned int) -48); /* line 1726 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_6); /* line 1727 */
} /* line 1727 */
  sim_icache_fetch(1099 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, 0); /* line 1729 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1730 */
  sim_icache_fetch(1101 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 1732 */
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 1733 */
} /* line 1733 */
  sim_icache_fetch(1104 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_12); /* line 1735 */
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -155); /* line 1736 */
} /* line 1736 */
  sim_icache_fetch(1106 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1738 */
   MULL(reg_r0_12, reg_r0_3, (unsigned int) 28); /* line 1739 */
} /* line 1739 */
  sim_icache_fetch(1108 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_4, reg_r0_13); /* line 1741 */
   MULL(reg_r0_15, reg_r0_6, (unsigned int) -48); /* line 1742 */
} /* line 1742 */
  sim_icache_fetch(1110 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1744 */
   MULL(reg_r0_16, reg_r0_4, (unsigned int) 215); /* line 1745 */
} /* line 1745 */
  sim_icache_fetch(1112 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 1747 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_15); /* line 1748 */
} /* line 1748 */
  sim_icache_fetch(1114 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_15, reg_r0_13); /* line 1750 */
   ADD(reg_r0_16, reg_r0_16, reg_r0_12); /* line 1751 */
} /* line 1751 */
  sim_icache_fetch(1116 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_1, reg_r0_15, (unsigned int) 25); /* line 1753 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_16); /* line 1754 */
} /* line 1754 */
  sim_icache_fetch(1118 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_16, reg_r0_4); /* line 1756 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_7 + (unsigned int) 4200),0,4)); /* line 1757 */
} /* line 1757 */
  sim_icache_fetch(1121 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_13); /* line 1759 */
} /* line 1759 */
  sim_icache_fetch(1122 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_4); /* line 1761 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L63X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1762 */
  sim_icache_fetch(1124 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_14, (unsigned int) 8); /* line 1764 */
   MOV(reg_r0_4, reg_r0_16); /* line 1765 */
} /* line 1765 */
  sim_icache_fetch(1126 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), 0); /* line 1767 */
   ADD(reg_r0_12, reg_r0_5, reg_r0_12); /* line 1768 */
} /* line 1768 */
l_L64X3: ;/* line 1770 */
LABEL(l_L64X3);
  sim_icache_fetch(1128 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1771 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L65X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1772 */
  sim_icache_fetch(1130 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4200),0,4), reg_r0_5); /* line 1774 */
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 1775 */
} /* line 1775 */
  sim_icache_fetch(1133 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_12); /* line 1777 */
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_12); /* line 1778 */
} /* line 1778 */
  sim_icache_fetch(1136 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 1780 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1781 */
   ADD_CYCLES(1);
} /* line 1781 */
  sim_icache_fetch(1138 + t_thisfile.offset, 1);
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
} /* line 1783 */
  sim_icache_fetch(1139 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 1785 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_11); /* line 1786 */
} /* line 1786 */
  sim_icache_fetch(1141 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 1788 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_11); /* line 1789 */
} /* line 1789 */
  sim_icache_fetch(1143 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), 0); /* line 1791 */
} /* line 1791 */
l_L67X3: ;/* line 1793 */
LABEL(l_L67X3);
  sim_icache_fetch(1145 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 2100); /* line 1794 */
   GOTO(l_L61X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L61X3;
} /* line 1795 */
l_L66X3: ;/* line 1798 */
LABEL(l_L66X3);
  sim_icache_fetch(1148 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 1799 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1800 */
} /* line 1800 */
  sim_icache_fetch(1150 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_11); /* line 1802 */
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 1803 */
} /* line 1803 */
  sim_icache_fetch(1152 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_3); /* line 1805 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_11); /* line 1807 */
} /* line 1807 */
  sim_icache_fetch(1155 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L67X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L67X3;
} /* line 1809 */
l_L65X3: ;/* line 1812 */
LABEL(l_L65X3);
  sim_icache_fetch(1156 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 4); /* line 1813 */
   ADD(reg_r0_26, reg_r0_26, (unsigned int) 4); /* line 1815 */
} /* line 1815 */
  sim_icache_fetch(1158 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L68X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L68X3;
} /* line 1817 */
l_L63X3: ;/* line 1820 */
LABEL(l_L63X3);
  sim_icache_fetch(1159 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_14, (unsigned int) 8); /* line 1821 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1822 */
} /* line 1822 */
  sim_icache_fetch(1161 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_5, reg_r0_12); /* line 1824 */
   MOV(reg_r0_4, reg_r0_16); /* line 1825 */
} /* line 1825 */
  sim_icache_fetch(1163 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_3); /* line 1827 */
   GOTO(l_L64X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L64X3;
} /* line 1828 */
l_L62X3: ;/* line 1831 */
LABEL(l_L62X3);
  sim_icache_fetch(1165 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 4); /* line 1832 */
   ADD(reg_r0_26, reg_r0_26, (unsigned int) 4); /* line 1833 */
} /* line 1833 */
l_L68X3: ;/* line 1835 */
LABEL(l_L68X3);
  sim_icache_fetch(1167 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 1); /* line 1836 */
   ADD(reg_r0_24, reg_r0_24, (unsigned int) 4); /* line 1837 */
} /* line 1837 */
  sim_icache_fetch(1169 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 1839 */
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 4); /* line 1840 */
} /* line 1840 */
  sim_icache_fetch(1171 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_20, (unsigned int) 1); /* line 1842 */
   MOV(reg_r0_10, reg_r0_17); /* line 1844 */
} /* line 1844 */
  sim_icache_fetch(1173 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L53X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L53X3;
} /* line 1846 */
l_L58X3: ;/* line 1849 */
LABEL(l_L58X3);
  sim_icache_fetch(1174 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_22); /* line 1850 */
   MOV(reg_r0_9, reg_r0_23); /* line 1852 */
} /* line 1852 */
  sim_icache_fetch(1176 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L60X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L60X3;
} /* line 1854 */
l_L57X3: ;/* line 1857 */
LABEL(l_L57X3);
  sim_icache_fetch(1177 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_22); /* line 1858 */
   MOV(reg_r0_9, reg_r0_23); /* line 1860 */
} /* line 1860 */
  sim_icache_fetch(1179 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L60X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L60X3;
} /* line 1862 */
l_L56X3: ;/* line 1865 */
LABEL(l_L56X3);
  sim_icache_fetch(1180 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_22); /* line 1866 */
   MOV(reg_r0_9, reg_r0_23); /* line 1867 */
} /* line 1867 */
l_L60X3: ;/* line 1869 */
LABEL(l_L60X3);
  sim_icache_fetch(1182 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_3); /* line 1870 */
   MOV(reg_r0_7, reg_r0_24); /* line 1871 */
} /* line 1871 */
  sim_icache_fetch(1184 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, reg_r0_25); /* line 1873 */
   MOV(reg_r0_2, reg_r0_26); /* line 1874 */
} /* line 1874 */
  sim_icache_fetch(1186 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_20); /* line 1876 */
   MOV(reg_r0_5, reg_r0_19); /* line 1877 */
} /* line 1877 */
  sim_icache_fetch(1188 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_21); /* line 1879 */
   MOV(reg_r0_11, (unsigned int) 8400); /* line 1880 */
} /* line 1880 */
  sim_icache_fetch(1191 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, reg_r0_17); /* line 1882 */
   MOV(reg_r0_20, reg_r0_15); /* line 1883 */
} /* line 1883 */
  sim_icache_fetch(1193 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_16); /* line 1885 */
   GOTO(l_L61X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L61X3;
} /* line 1886 */
l_L54X3: ;/* line 1889 */
LABEL(l_L54X3);
  sim_icache_fetch(1195 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_fused);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1891 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 222: goto l_L47X3;
    case 223: goto l_L49X3;
    case 224: goto l_L50X3;
    case 225: goto l_L51X3;
    case 226: goto l_L52X3;
    case 227: goto l_L48X3;
    case 228: goto l_L53X3;
    case 229: goto l_L55X3;
    case 230: goto l_L59X3;
    case 231: goto l_L61X3;
    case 232: goto l_L64X3;
    case 233: goto l_L67X3;
    case 234: goto l_L66X3;
    case 235: goto l_L65X3;
    case 236: goto l_L63X3;
    case 237: goto l_L62X3;
    case 238: goto l_L68X3;
    case 239: goto l_L58X3;
    case 240: goto l_L57X3;
    case 241: goto l_L56X3;
    case 242: goto l_L60X3;
    case 243: goto l_L54X3;
    case 244:
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
  reg_l0_0 = (293 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1196 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 1907 */
} /* line 1907 */
  sim_icache_fetch(1197 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, (unsigned int) qy1); /* line 1909 */
   MOV(reg_r0_12, (unsigned int) in); /* line 1910 */
} /* line 1910 */
  sim_icache_fetch(1201 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_2); /* line 1912 */
   MOV(reg_r0_19, t__i32_0); /* line 1913 */
} /* line 1913 */
  sim_icache_fetch(1203 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_4); /* line 1915 */
} /* line 1915 */
l_L69X3: ;/* line 1918 */
LABEL(l_L69X3);
  sim_icache_fetch(1204 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 1919 */
   SUB(reg_r0_10, (unsigned int) 3, reg_r0_5); /* line 1920 */
} /* line 1920 */
  sim_icache_fetch(1206 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_10); /* line 1922 */
   MOV(reg_r0_9, reg_r0_11); /* line 1923 */
} /* line 1923 */
  sim_icache_fetch(1208 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, 0); /* line 1925 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1926 */
  sim_icache_fetch(1210 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, 0); /* line 1928 */
   MOV(reg_r0_2, reg_r0_12); /* line 1929 */
} /* line 1929 */
  sim_icache_fetch(1212 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, 0); /* line 1931 */
   MOV(reg_r0_15, reg_r0_3); /* line 1932 */
} /* line 1932 */
  sim_icache_fetch(1214 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_16, reg_r0_5); /* line 1934 */
   MOV(reg_r0_17, reg_r0_11); /* line 1935 */
} /* line 1935 */
  sim_icache_fetch(1216 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_12); /* line 1937 */
} /* line 1937 */
l_L71X3: ;/* line 1940 */
LABEL(l_L71X3);
  sim_icache_fetch(1217 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 1941 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 215); /* line 1942 */
} /* line 1942 */
  sim_icache_fetch(1219 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 1944 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -155); /* line 1945 */
} /* line 1945 */
  sim_icache_fetch(1221 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 3); /* line 1947 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1948 */
} /* line 1948 */
  sim_icache_fetch(1223 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_3, (unsigned int) -48); /* line 1950 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 8); /* line 1951 */
} /* line 1951 */
  sim_icache_fetch(1225 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 1953 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1954 */
  sim_icache_fetch(1227 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_5); /* line 1956 */
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 2); /* line 1957 */
} /* line 1957 */
  sim_icache_fetch(1229 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_10); /* line 1959 */
   LDBUs(reg_r0_5, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 1960 */
} /* line 1960 */
  sim_icache_fetch(1231 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_7, (unsigned int) 215); /* line 1962 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1963 */
} /* line 1963 */
  sim_icache_fetch(1233 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 1965 */
   CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 1); /* line 1966 */
} /* line 1966 */
  sim_icache_fetch(1235 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_5, (unsigned int) -48); /* line 1968 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1969 */
} /* line 1969 */
  sim_icache_fetch(1237 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1971 */
   LDBUs(reg_r0_12, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 1972 */
} /* line 1972 */
  sim_icache_fetch(1239 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 1974 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 1975 */
} /* line 1975 */
  sim_icache_fetch(1241 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 1977 */
   MULL(reg_r0_10, reg_r0_7, (unsigned int) -155); /* line 1978 */
} /* line 1978 */
  sim_icache_fetch(1243 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_12, (unsigned int) -48); /* line 1980 */
   MULL(reg_r0_13, reg_r0_3, (unsigned int) 215); /* line 1981 */
} /* line 1981 */
  sim_icache_fetch(1245 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 28); /* line 1983 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1984 */
} /* line 1984 */
  sim_icache_fetch(1247 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1986 */
   CMPLT(reg_b0_2, reg_r0_8, 0); /* line 1987 */
} /* line 1987 */
  sim_icache_fetch(1249 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 1989 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 1990 */
} /* line 1990 */
  sim_icache_fetch(1251 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 1992 */
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 3),0,1)); /* line 1993 */
} /* line 1993 */
  sim_icache_fetch(1253 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_5, (unsigned int) 215); /* line 1995 */
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -155); /* line 1996 */
} /* line 1996 */
  sim_icache_fetch(1255 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_12, (unsigned int) 28); /* line 1998 */
   MOV(reg_r0_6, reg_r0_5); /* line 1999 */
} /* line 1999 */
  sim_icache_fetch(1257 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_10, (unsigned int) -48); /* line 2001 */
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2002 */
} /* line 2002 */
  sim_icache_fetch(1259 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2004 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 2005 */
} /* line 2005 */
  sim_icache_fetch(1261 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_13); /* line 2007 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_11); /* line 2008 */
} /* line 2008 */
  sim_icache_fetch(1263 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_12, reg_r0_14); /* line 2010 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 4); /* line 2011 */
} /* line 2011 */
  sim_icache_fetch(1265 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_9,0,4), reg_r0_7); /* line 2013 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2014 */
  sim_icache_fetch(1267 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 4),0,4), reg_r0_3); /* line 2016 */
   MOV(reg_r0_7, reg_r0_10); /* line 2017 */
} /* line 2017 */
  sim_icache_fetch(1269 + t_thisfile.offset, 1);
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
} /* line 2019 */
  sim_icache_fetch(1270 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 8),0,4), reg_r0_5); /* line 2021 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2022 */
  sim_icache_fetch(1272 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 12),0,4), reg_r0_4); /* line 2024 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 2026 */
} /* line 2026 */
  sim_icache_fetch(1274 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L71X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L71X3;
} /* line 2028 */
l_L72X3: ;/* line 2031 */
LABEL(l_L72X3);
  sim_icache_fetch(1275 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4200); /* line 2032 */
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 1050); /* line 2033 */
} /* line 2033 */
  sim_icache_fetch(1279 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_15, (unsigned int) 1); /* line 2035 */
   MOV(reg_r0_5, reg_r0_16); /* line 2037 */
} /* line 2037 */
  sim_icache_fetch(1281 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L69X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L69X3;
} /* line 2039 */
l_L70X3: ;/* line 2042 */
LABEL(l_L70X3);
  sim_icache_fetch(1282 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_19); /* line 2043 */
   MOV(reg_r0_12, ((unsigned int) qy2 + (unsigned int) -12)); /* line 2044 */
} /* line 2044 */
  sim_icache_fetch(1285 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_5, (unsigned int) -1); /* line 2046 */
   MOV(reg_r0_4, reg_r0_2); /* line 2047 */
} /* line 2047 */
  sim_icache_fetch(1287 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 2049 */
   MOV(reg_r0_21, reg_r0_19); /* line 2050 */
} /* line 2050 */
  sim_icache_fetch(1290 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, reg_r0_5); /* line 2052 */
} /* line 2052 */
l_L73X3: ;/* line 2055 */
LABEL(l_L73X3);
  sim_icache_fetch(1291 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 2056 */
   ADD(reg_r0_9, reg_r0_10, reg_r0_11); /* line 2057 */
} /* line 2057 */
  sim_icache_fetch(1293 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 2059 */
   SH2ADD(reg_r0_8, reg_r0_11, reg_r0_12); /* line 2060 */
} /* line 2060 */
  sim_icache_fetch(1295 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 2062 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2063 */
  sim_icache_fetch(1297 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 2065 */
   MOV(reg_r0_6, 0); /* line 2066 */
} /* line 2066 */
  sim_icache_fetch(1299 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_11); /* line 2068 */
   MOV(reg_r0_17, reg_r0_4); /* line 2069 */
} /* line 2069 */
  sim_icache_fetch(1301 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_18, reg_r0_10); /* line 2071 */
   MOV(reg_r0_19, reg_r0_11); /* line 2072 */
} /* line 2072 */
  sim_icache_fetch(1303 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_12); /* line 2074 */
} /* line 2074 */
l_L75X3: ;/* line 2077 */
LABEL(l_L75X3);
  sim_icache_fetch(1304 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 2078 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2079 */
} /* line 2079 */
  sim_icache_fetch(1306 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -48); /* line 2081 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 2082 */
} /* line 2082 */
  sim_icache_fetch(1308 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2084 */
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2085 */
} /* line 2085 */
  sim_icache_fetch(1310 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2087 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_2); /* line 2088 */
} /* line 2088 */
  sim_icache_fetch(1312 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 2090 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2091 */
  sim_icache_fetch(1314 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2093 */
   LDBU(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 3),0,1)); /* line 2094 */
} /* line 2094 */
  sim_icache_fetch(1316 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2096 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2097 */
} /* line 2097 */
  sim_icache_fetch(1318 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 2099 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) 215); /* line 2100 */
} /* line 2100 */
  sim_icache_fetch(1320 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 2102 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2103 */
} /* line 2103 */
  sim_icache_fetch(1322 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2105 */
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_9 + (unsigned int) 2),0,1)); /* line 2106 */
} /* line 2106 */
  sim_icache_fetch(1324 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_5); /* line 2108 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2109 */
} /* line 2109 */
  sim_icache_fetch(1326 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 2111 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2112 */
} /* line 2112 */
  sim_icache_fetch(1328 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_13, (unsigned int) -47); /* line 2114 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) -155); /* line 2115 */
} /* line 2115 */
  sim_icache_fetch(1330 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 2117 */
   MULL(reg_r0_15, reg_r0_12, (unsigned int) 215); /* line 2118 */
} /* line 2118 */
  sim_icache_fetch(1332 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2120 */
   LDBUs(reg_r0_16, mem_trace_ld((reg_r0_9 + (unsigned int) 1),0,1)); /* line 2121 */
} /* line 2121 */
  sim_icache_fetch(1334 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2123 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_11); /* line 2124 */
} /* line 2124 */
  sim_icache_fetch(1336 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_15); /* line 2126 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2127 */
} /* line 2127 */
  sim_icache_fetch(1338 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 2129 */
   MULL(reg_r0_10, reg_r0_12, (unsigned int) -155); /* line 2130 */
} /* line 2130 */
  sim_icache_fetch(1340 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_16, (unsigned int) -47); /* line 2132 */
   MULL(reg_r0_15, reg_r0_14, (unsigned int) 215); /* line 2133 */
} /* line 2133 */
  sim_icache_fetch(1342 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_13, (unsigned int) -48); /* line 2135 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2136 */
} /* line 2136 */
  sim_icache_fetch(1344 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2138 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 2139 */
} /* line 2139 */
  sim_icache_fetch(1346 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 2141 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_9,0,1)); /* line 2142 */
} /* line 2142 */
  sim_icache_fetch(1348 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_11, reg_r0_13); /* line 2144 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 2145 */
} /* line 2145 */
  sim_icache_fetch(1350 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_16); /* line 2147 */
   MOV(reg_r0_2, reg_r0_14); /* line 2148 */
} /* line 2148 */
  sim_icache_fetch(1352 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 2150 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -4); /* line 2151 */
} /* line 2151 */
  sim_icache_fetch(1354 + t_thisfile.offset, 1);
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
} /* line 2153 */
  sim_icache_fetch(1355 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_12); /* line 2155 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2156 */
  sim_icache_fetch(1357 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_14); /* line 2158 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2159 */
  sim_icache_fetch(1359 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_5); /* line 2161 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 2163 */
} /* line 2163 */
  sim_icache_fetch(1361 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L75X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L75X3;
} /* line 2165 */
l_L76X3: ;/* line 2168 */
LABEL(l_L76X3);
  sim_icache_fetch(1362 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_18, (unsigned int) 1050); /* line 2169 */
   ADD(reg_r0_12, reg_r0_20, (unsigned int) 4200); /* line 2170 */
} /* line 2170 */
  sim_icache_fetch(1366 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_17, (unsigned int) 1); /* line 2172 */
   MOV(reg_r0_11, reg_r0_19); /* line 2174 */
} /* line 2174 */
  sim_icache_fetch(1368 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L73X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L73X3;
} /* line 2176 */
l_L74X3: ;/* line 2179 */
LABEL(l_L74X3);
  sim_icache_fetch(1369 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_21); /* line 2180 */
   MOV(reg_r0_11, (unsigned int) qy2); /* line 2181 */
} /* line 2181 */
  sim_icache_fetch(1372 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_2); /* line 2183 */
   MOV(reg_r0_10, (unsigned int) qy1); /* line 2184 */
} /* line 2184 */
  sim_icache_fetch(1375 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, (unsigned int) qt); /* line 2186 */
   MOV(reg_r0_16, reg_r0_21); /* line 2187 */
} /* line 2187 */
  sim_icache_fetch(1378 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_22); /* line 2189 */
} /* line 2189 */
l_L77X3: ;/* line 2192 */
LABEL(l_L77X3);
  sim_icache_fetch(1379 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2193 */
   SUB(reg_r0_8, (unsigned int) 3, reg_r0_7); /* line 2194 */
} /* line 2194 */
  sim_icache_fetch(1381 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_8); /* line 2196 */
   MOV(reg_r0_6, reg_r0_9); /* line 2197 */
} /* line 2197 */
  sim_icache_fetch(1383 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_10); /* line 2199 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2200 */
  sim_icache_fetch(1385 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_11); /* line 2202 */
   MOV(reg_r0_12, reg_r0_7); /* line 2203 */
} /* line 2203 */
  sim_icache_fetch(1387 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_11 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, reg_r0_3); /* line 2205 */
   MOV(reg_r0_15, t__i32_0); /* line 2206 */
} /* line 2206 */
  sim_icache_fetch(1389 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_13, reg_r0_9); /* line 2208 */
   MOV(reg_r0_14, reg_r0_10); /* line 2209 */
} /* line 2209 */
l_L79X3: ;/* line 2212 */
LABEL(l_L79X3);
  sim_icache_fetch(1391 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 2213 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2214 */
} /* line 2214 */
  sim_icache_fetch(1393 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_7, mem_trace_ld(reg_r0_4,0,4)); /* line 2216 */
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2217 */
} /* line 2217 */
  sim_icache_fetch(1395 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 2219 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2220 */
  sim_icache_fetch(1397 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 2222 */
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2223 */
} /* line 2223 */
  sim_icache_fetch(1399 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_7); /* line 2225 */
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 2226 */
} /* line 2226 */
  sim_icache_fetch(1401 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2228 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 2229 */
} /* line 2229 */
  sim_icache_fetch(1403 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2231 */
   ADD(reg_r0_8, reg_r0_8, reg_r0_9); /* line 2232 */
} /* line 2232 */
  sim_icache_fetch(1405 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 2234 */
   CMPLT(reg_b0_2, reg_r0_5, 0); /* line 2235 */
} /* line 2235 */
  sim_icache_fetch(1407 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 2237 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_10); /* line 2238 */
} /* line 2238 */
  sim_icache_fetch(1409 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 2240 */
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 2241 */
} /* line 2241 */
  sim_icache_fetch(1411 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 2243 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 2244 */
} /* line 2244 */
  sim_icache_fetch(1413 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 2246 */
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 2247 */
} /* line 2247 */
  sim_icache_fetch(1415 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_6,0,4), reg_r0_3); /* line 2249 */
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2250 */
} /* line 2250 */
  sim_icache_fetch(1417 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2252 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2253 */
  sim_icache_fetch(1419 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 4),0,4), reg_r0_8); /* line 2255 */
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2256 */
} /* line 2256 */
  sim_icache_fetch(1421 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2258 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L82X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2259 */
  sim_icache_fetch(1423 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 8),0,4), reg_r0_7); /* line 2261 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L83X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2262 */
  sim_icache_fetch(1425 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 12),0,4), reg_r0_9); /* line 2264 */
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 2266 */
} /* line 2266 */
  sim_icache_fetch(1427 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L79X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L79X3;
} /* line 2268 */
l_L83X3: ;/* line 2271 */
LABEL(l_L83X3);
  sim_icache_fetch(1428 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 2272 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2273 */
} /* line 2273 */
  sim_icache_fetch(1431 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_14, reg_r0_2); /* line 2275 */
   ADD(reg_r0_11, reg_r0_15, reg_r0_2); /* line 2277 */
} /* line 2277 */
  sim_icache_fetch(1433 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L84X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L84X3;
} /* line 2279 */
l_L82X3: ;/* line 2282 */
LABEL(l_L82X3);
  sim_icache_fetch(1434 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 2283 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2284 */
} /* line 2284 */
  sim_icache_fetch(1437 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_14, reg_r0_2); /* line 2286 */
   ADD(reg_r0_11, reg_r0_15, reg_r0_2); /* line 2288 */
} /* line 2288 */
  sim_icache_fetch(1439 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L84X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L84X3;
} /* line 2290 */
l_L81X3: ;/* line 2293 */
LABEL(l_L81X3);
  sim_icache_fetch(1440 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 2294 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2295 */
} /* line 2295 */
  sim_icache_fetch(1443 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_14, reg_r0_2); /* line 2297 */
   ADD(reg_r0_11, reg_r0_15, reg_r0_2); /* line 2299 */
} /* line 2299 */
  sim_icache_fetch(1445 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L84X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L84X3;
} /* line 2301 */
l_L80X3: ;/* line 2304 */
LABEL(l_L80X3);
  sim_icache_fetch(1446 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 2305 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2306 */
} /* line 2306 */
  sim_icache_fetch(1449 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_14, reg_r0_2); /* line 2308 */
   ADD(reg_r0_11, reg_r0_15, reg_r0_2); /* line 2309 */
} /* line 2309 */
l_L84X3: ;/* line 2311 */
LABEL(l_L84X3);
  sim_icache_fetch(1451 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_13, reg_r0_2); /* line 2312 */
   MOV(reg_r0_7, reg_r0_12); /* line 2314 */
} /* line 2314 */
  sim_icache_fetch(1453 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L77X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L77X3;
} /* line 2316 */
l_L78X3: ;/* line 2319 */
LABEL(l_L78X3);
  sim_icache_fetch(1454 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_7); /* line 2320 */
   MOV(reg_r0_12, (unsigned int) qt); /* line 2321 */
} /* line 2321 */
  sim_icache_fetch(1457 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_2); /* line 2323 */
   MOV(reg_r0_11, (unsigned int) qy1); /* line 2324 */
} /* line 2324 */
  sim_icache_fetch(1460 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_7); /* line 2326 */
   MOV(reg_r0_9, reg_r0_16); /* line 2327 */
} /* line 2327 */
l_L85X3: ;/* line 2330 */
LABEL(l_L85X3);
  sim_icache_fetch(1462 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2331 */
   SUB(reg_r0_10, (unsigned int) 3, reg_r0_9); /* line 2332 */
} /* line 2332 */
  sim_icache_fetch(1464 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_10); /* line 2334 */
   MOV(reg_r0_8, reg_r0_11); /* line 2335 */
} /* line 2335 */
  sim_icache_fetch(1466 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_12); /* line 2337 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2338 */
  sim_icache_fetch(1468 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, 0); /* line 2340 */
   MOV(reg_r0_5, 0); /* line 2341 */
} /* line 2341 */
  sim_icache_fetch(1470 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, 0); /* line 2343 */
   MOV(reg_r0_13, reg_r0_3); /* line 2344 */
} /* line 2344 */
  sim_icache_fetch(1472 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_14, reg_r0_9); /* line 2346 */
   MOV(reg_r0_15, reg_r0_11); /* line 2347 */
} /* line 2347 */
  sim_icache_fetch(1474 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_12); /* line 2349 */
} /* line 2349 */
l_L87X3: ;/* line 2352 */
LABEL(l_L87X3);
  sim_icache_fetch(1475 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2353 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2354 */
} /* line 2354 */
  sim_icache_fetch(1477 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_9, reg_r0_5, (unsigned int) 215); /* line 2356 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 2357 */
} /* line 2357 */
  sim_icache_fetch(1479 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 3); /* line 2359 */
   CMPLT(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2360 */
} /* line 2360 */
  sim_icache_fetch(1481 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_3, (unsigned int) -48); /* line 2362 */
   ADD(reg_r0_9, reg_r0_9, reg_r0_6); /* line 2363 */
} /* line 2363 */
  sim_icache_fetch(1483 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 2365 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L88X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2366 */
  sim_icache_fetch(1486 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_10); /* line 2368 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2369 */
} /* line 2369 */
  sim_icache_fetch(1488 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_9); /* line 2371 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2372 */
} /* line 2372 */
  sim_icache_fetch(1490 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2374 */
   MULL(reg_r0_9, reg_r0_11, (unsigned int) -48); /* line 2375 */
} /* line 2375 */
  sim_icache_fetch(1492 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 2377 */
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2378 */
} /* line 2378 */
  sim_icache_fetch(1494 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_9); /* line 2380 */
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 8400),0,4)); /* line 2381 */
} /* line 2381 */
  sim_icache_fetch(1497 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_3); /* line 2383 */
   MULL(reg_r0_3, reg_r0_4, (unsigned int) -155); /* line 2384 */
} /* line 2384 */
  sim_icache_fetch(1499 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 2386 */
   MULL(reg_r0_11, reg_r0_11, (unsigned int) 28); /* line 2387 */
} /* line 2387 */
  sim_icache_fetch(1501 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2389 */
   MULL(reg_r0_10, reg_r0_9, (unsigned int) -48); /* line 2390 */
} /* line 2390 */
  sim_icache_fetch(1503 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_5, (unsigned int) 215); /* line 2392 */
   CMPLT(reg_b0_2, reg_r0_7, 0); /* line 2393 */
} /* line 2393 */
  sim_icache_fetch(1505 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_10); /* line 2395 */
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 12600),0,4)); /* line 2396 */
} /* line 2396 */
  sim_icache_fetch(1508 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_11); /* line 2398 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) -155); /* line 2399 */
} /* line 2399 */
  sim_icache_fetch(1510 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_12); /* line 2401 */
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 28); /* line 2402 */
} /* line 2402 */
  sim_icache_fetch(1512 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2404 */
   MULL(reg_r0_11, reg_r0_6, (unsigned int) -48); /* line 2405 */
} /* line 2405 */
  sim_icache_fetch(1514 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 2407 */
   MULL(reg_r0_12, reg_r0_3, (unsigned int) 215); /* line 2408 */
} /* line 2408 */
  sim_icache_fetch(1516 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 2410 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L89X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2411 */
  sim_icache_fetch(1518 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_3); /* line 2413 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_9); /* line 2414 */
} /* line 2414 */
  sim_icache_fetch(1520 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_12); /* line 2416 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16800); /* line 2417 */
} /* line 2417 */
  sim_icache_fetch(1523 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2419 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 2420 */
} /* line 2420 */
  sim_icache_fetch(1525 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_5); /* line 2422 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2423 */
  sim_icache_fetch(1528 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_3); /* line 2425 */
   MOV(reg_r0_5, reg_r0_10); /* line 2426 */
} /* line 2426 */
  sim_icache_fetch(1531 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L91X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2428 */
  sim_icache_fetch(1532 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_10); /* line 2430 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 16800); /* line 2432 */
} /* line 2432 */
  sim_icache_fetch(1536 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L87X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L87X3;
} /* line 2434 */
l_L91X3: ;/* line 2437 */
LABEL(l_L91X3);
  sim_icache_fetch(1537 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 2438 */
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 2439 */
} /* line 2439 */
  sim_icache_fetch(1539 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_14); /* line 2441 */
   GOTO(l_L92X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L92X3;
} /* line 2442 */
l_L90X3: ;/* line 2445 */
LABEL(l_L90X3);
  sim_icache_fetch(1541 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 2446 */
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 2447 */
} /* line 2447 */
  sim_icache_fetch(1543 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_14); /* line 2449 */
   GOTO(l_L92X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L92X3;
} /* line 2450 */
l_L89X3: ;/* line 2453 */
LABEL(l_L89X3);
  sim_icache_fetch(1545 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 2454 */
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 2455 */
} /* line 2455 */
  sim_icache_fetch(1547 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_14); /* line 2457 */
   GOTO(l_L92X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L92X3;
} /* line 2458 */
l_L88X3: ;/* line 2461 */
LABEL(l_L88X3);
  sim_icache_fetch(1549 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 2462 */
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 2463 */
} /* line 2463 */
  sim_icache_fetch(1551 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_14); /* line 2465 */
} /* line 2465 */
l_L92X3: ;/* line 2467 */
LABEL(l_L92X3);
  sim_icache_fetch(1552 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_15, (unsigned int) 4); /* line 2468 */
   GOTO(l_L85X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L85X3;
} /* line 2469 */
l_L86X3: ;/* line 2472 */
LABEL(l_L86X3);
  sim_icache_fetch(1554 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_17); /* line 2473 */
   MOV(reg_r0_13, ((unsigned int) qy2 + (unsigned int) -12600)); /* line 2474 */
} /* line 2474 */
  sim_icache_fetch(1557 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_2); /* line 2476 */
   MOV(reg_r0_12, ((unsigned int) qt + (unsigned int) -12600)); /* line 2477 */
} /* line 2477 */
  sim_icache_fetch(1560 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_9, (unsigned int) -1); /* line 2479 */
   MOV(reg_r0_19, reg_r0_17); /* line 2480 */
} /* line 2480 */
  sim_icache_fetch(1562 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_9); /* line 2482 */
} /* line 2482 */
l_L93X3: ;/* line 2485 */
LABEL(l_L93X3);
  sim_icache_fetch(1563 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 2486 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 4200); /* line 2487 */
} /* line 2487 */
  sim_icache_fetch(1566 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 2489 */
   MOV(reg_r0_6, 0); /* line 2490 */
} /* line 2490 */
  sim_icache_fetch(1568 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 2492 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2493 */
  sim_icache_fetch(1570 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 2495 */
   ADD(reg_r0_8, reg_r0_13, reg_r0_11); /* line 2496 */
} /* line 2496 */
  sim_icache_fetch(1572 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 2498 */
   MOV(reg_r0_7, reg_r0_10); /* line 2499 */
} /* line 2499 */
  sim_icache_fetch(1574 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_15, reg_r0_4); /* line 2501 */
   MOV(reg_r0_16, reg_r0_10); /* line 2502 */
} /* line 2502 */
  sim_icache_fetch(1576 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_12); /* line 2504 */
   MOV(reg_r0_18, reg_r0_13); /* line 2505 */
} /* line 2505 */
l_L95X3: ;/* line 2508 */
LABEL(l_L95X3);
  sim_icache_fetch(1578 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2509 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 2510 */
} /* line 2510 */
  sim_icache_fetch(1580 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 2512 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 29); /* line 2513 */
} /* line 2513 */
  sim_icache_fetch(1582 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2515 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2516 */
} /* line 2516 */
  sim_icache_fetch(1584 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 2518 */
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 12600),0,4)); /* line 2519 */
} /* line 2519 */
  sim_icache_fetch(1587 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 2521 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2522 */
  sim_icache_fetch(1589 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2524 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2525 */
} /* line 2525 */
  sim_icache_fetch(1591 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2527 */
   MULL(reg_r0_10, reg_r0_4, (unsigned int) -47); /* line 2528 */
} /* line 2528 */
  sim_icache_fetch(1593 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 2530 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 2531 */
} /* line 2531 */
  sim_icache_fetch(1595 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 2533 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 8400),0,4)); /* line 2534 */
} /* line 2534 */
  sim_icache_fetch(1598 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 2536 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2537 */
} /* line 2537 */
  sim_icache_fetch(1600 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 2539 */
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 2540 */
} /* line 2540 */
  sim_icache_fetch(1602 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2542 */
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 2543 */
} /* line 2543 */
  sim_icache_fetch(1604 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_5, (unsigned int) 215); /* line 2545 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 29); /* line 2546 */
} /* line 2546 */
  sim_icache_fetch(1606 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 2548 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,4)); /* line 2549 */
} /* line 2549 */
  sim_icache_fetch(1609 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_4); /* line 2551 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2552 */
} /* line 2552 */
  sim_icache_fetch(1611 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 2554 */
   MULL(reg_r0_4, reg_r0_5, (unsigned int) -155); /* line 2555 */
} /* line 2555 */
  sim_icache_fetch(1613 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2557 */
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 2558 */
} /* line 2558 */
  sim_icache_fetch(1615 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 2560 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 2561 */
} /* line 2561 */
  sim_icache_fetch(1617 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 2563 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_9,0,4)); /* line 2564 */
} /* line 2564 */
  sim_icache_fetch(1619 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_2); /* line 2566 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 2567 */
} /* line 2567 */
  sim_icache_fetch(1622 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 2569 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L97X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2570 */
  sim_icache_fetch(1624 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_11); /* line 2572 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2573 */
} /* line 2573 */
  sim_icache_fetch(1626 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_12); /* line 2575 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 2576 */
} /* line 2576 */
  sim_icache_fetch(1628 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_5); /* line 2578 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -16800); /* line 2579 */
} /* line 2579 */
  sim_icache_fetch(1632 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_4); /* line 2581 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2582 */
  sim_icache_fetch(1634 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_11); /* line 2584 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L99X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2585 */
  sim_icache_fetch(1637 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 2587 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16800); /* line 2589 */
} /* line 2589 */
  sim_icache_fetch(1640 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L95X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L95X3;
} /* line 2591 */
l_L99X3: ;/* line 2594 */
LABEL(l_L99X3);
  sim_icache_fetch(1641 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 2595 */
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 2597 */
} /* line 2597 */
  sim_icache_fetch(1643 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L100X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L100X3;
} /* line 2599 */
l_L98X3: ;/* line 2602 */
LABEL(l_L98X3);
  sim_icache_fetch(1644 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 2603 */
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 2605 */
} /* line 2605 */
  sim_icache_fetch(1646 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L100X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L100X3;
} /* line 2607 */
l_L97X3: ;/* line 2610 */
LABEL(l_L97X3);
  sim_icache_fetch(1647 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 2611 */
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 2613 */
} /* line 2613 */
  sim_icache_fetch(1649 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L100X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L100X3;
} /* line 2615 */
l_L96X3: ;/* line 2618 */
LABEL(l_L96X3);
  sim_icache_fetch(1650 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 2619 */
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 2620 */
} /* line 2620 */
l_L100X3: ;/* line 2622 */
LABEL(l_L100X3);
  sim_icache_fetch(1652 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_15, (unsigned int) 1); /* line 2623 */
   MOV(reg_r0_10, reg_r0_16); /* line 2625 */
} /* line 2625 */
  sim_icache_fetch(1654 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L93X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L93X3;
} /* line 2627 */
l_L94X3: ;/* line 2630 */
LABEL(l_L94X3);
  sim_icache_fetch(1655 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_20, 0, reg_r0_20); /* line 2631 */
   MOV(reg_r0_12, (unsigned int) qy2); /* line 2632 */
} /* line 2632 */
  sim_icache_fetch(1658 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_20); /* line 2634 */
   MOV(reg_r0_11, (unsigned int) qy1); /* line 2635 */
} /* line 2635 */
  sim_icache_fetch(1661 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, (unsigned int) out); /* line 2637 */
   MOV(reg_r0_8, reg_r0_19); /* line 2638 */
} /* line 2638 */
l_L101X3: ;/* line 2641 */
LABEL(l_L101X3);
  sim_icache_fetch(1664 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2642 */
   SUB(reg_r0_9, (unsigned int) 3, reg_r0_8); /* line 2643 */
} /* line 2643 */
  sim_icache_fetch(1666 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_9); /* line 2645 */
   MOV(reg_r0_7, reg_r0_10); /* line 2646 */
} /* line 2646 */
  sim_icache_fetch(1668 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_10); /* line 2648 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2649 */
  sim_icache_fetch(1670 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_11); /* line 2651 */
   MOV(reg_r0_2, reg_r0_12); /* line 2652 */
} /* line 2652 */
  sim_icache_fetch(1672 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_13, reg_r0_3); /* line 2654 */
   MOV(reg_r0_14, reg_r0_8); /* line 2655 */
} /* line 2655 */
  sim_icache_fetch(1674 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_15, reg_r0_10); /* line 2657 */
   MOV(reg_r0_16, reg_r0_11); /* line 2658 */
} /* line 2658 */
  sim_icache_fetch(1676 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_12); /* line 2660 */
} /* line 2660 */
l_L103X3: ;/* line 2663 */
LABEL(l_L103X3);
  sim_icache_fetch(1677 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 2664 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2665 */
} /* line 2665 */
  sim_icache_fetch(1679 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_4,0,4)); /* line 2667 */
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2668 */
} /* line 2668 */
  sim_icache_fetch(1681 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 2670 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2671 */
  sim_icache_fetch(1683 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 2673 */
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2674 */
} /* line 2674 */
  sim_icache_fetch(1685 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_8); /* line 2676 */
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 2677 */
} /* line 2677 */
  sim_icache_fetch(1687 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2679 */
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 2680 */
} /* line 2680 */
  sim_icache_fetch(1689 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 2682 */
   ADD(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2683 */
} /* line 2683 */
  sim_icache_fetch(1691 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_10, reg_r0_3); /* line 2685 */
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2686 */
} /* line 2686 */
  sim_icache_fetch(1693 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_2, reg_r0_10, (unsigned int) 25); /* line 2688 */
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 2689 */
} /* line 2689 */
  sim_icache_fetch(1695 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_12, reg_r0_9); /* line 2691 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_8); /* line 2692 */
} /* line 2692 */
  sim_icache_fetch(1697 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_3, reg_r0_12, (unsigned int) 25); /* line 2694 */
   SHL(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2695 */
} /* line 2695 */
  sim_icache_fetch(1699 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 2697 */
   CMPLT(reg_b0_4, reg_r0_5, 0); /* line 2698 */
} /* line 2698 */
  sim_icache_fetch(1701 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_8, reg_r0_11); /* line 2700 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 2701 */
} /* line 2701 */
  sim_icache_fetch(1703 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_5, reg_r0_8, (unsigned int) 25); /* line 2703 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 2704 */
} /* line 2704 */
  sim_icache_fetch(1705 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_6,0,1), reg_r0_3); /* line 2706 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2707 */
  sim_icache_fetch(1707 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_6,0,1), 0); /* line 2709 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2710 */
l_L107X3: ;/* line 2712 */
LABEL(l_L107X3);
  sim_icache_fetch(1709 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), reg_r0_9); /* line 2713 */
   ADD(reg_r0_10, reg_r0_10, reg_r0_12); /* line 2714 */
} /* line 2714 */
  sim_icache_fetch(1711 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2716 */
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2717 */
  sim_icache_fetch(1713 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), 0); /* line 2719 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 2720 */
} /* line 2720 */
l_L109X3: ;/* line 2722 */
LABEL(l_L109X3);
  sim_icache_fetch(1715 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_10); /* line 2723 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2724 */
  sim_icache_fetch(1717 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), reg_r0_11); /* line 2726 */
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 2727 */
} /* line 2727 */
  sim_icache_fetch(1719 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_5) {    BRANCHF(reg_b0_5);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2729 */
  sim_icache_fetch(1720 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), 0); /* line 2731 */
   if (!reg_b0_4) {    BRANCHF(reg_b0_4);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2732 */
l_L113X3: ;/* line 2734 */
LABEL(l_L113X3);
  sim_icache_fetch(1722 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), reg_r0_10); /* line 2735 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2736 */
  sim_icache_fetch(1724 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 2738 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 2739 */
} /* line 2739 */
  sim_icache_fetch(1726 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2741 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 2742 */
} /* line 2742 */
  sim_icache_fetch(1728 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), 0); /* line 2744 */
} /* line 2744 */
l_L115X3: ;/* line 2746 */
LABEL(l_L115X3);
  sim_icache_fetch(1729 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 4); /* line 2747 */
   GOTO(l_L103X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L103X3;
} /* line 2748 */
l_L114X3: ;/* line 2751 */
LABEL(l_L114X3);
  sim_icache_fetch(1731 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2752 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 2753 */
} /* line 2753 */
  sim_icache_fetch(1733 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 2755 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 2756 */
} /* line 2756 */
  sim_icache_fetch(1735 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 3),0,1), reg_r0_3); /* line 2758 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 2760 */
} /* line 2760 */
  sim_icache_fetch(1737 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L115X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L115X3;
} /* line 2762 */
l_L112X3: ;/* line 2765 */
LABEL(l_L112X3);
  sim_icache_fetch(1738 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 2766 */
   ADD(reg_r0_11, reg_r0_16, (unsigned int) 4200); /* line 2767 */
} /* line 2767 */
  sim_icache_fetch(1741 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4200); /* line 2769 */
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1050); /* line 2771 */
} /* line 2771 */
  sim_icache_fetch(1745 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L116X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L116X3;
} /* line 2773 */
l_L111X3: ;/* line 2776 */
LABEL(l_L111X3);
  sim_icache_fetch(1746 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 2777 */
} /* line 2777 */
  sim_icache_fetch(1747 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 2),0,1), reg_r0_3); /* line 2779 */
   if (!reg_b0_4) {    BRANCHF(reg_b0_4);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2781 */
  sim_icache_fetch(1749 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L113X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L113X3;
} /* line 2783 */
l_L110X3: ;/* line 2786 */
LABEL(l_L110X3);
  sim_icache_fetch(1750 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 2787 */
   ADD(reg_r0_11, reg_r0_16, (unsigned int) 4200); /* line 2788 */
} /* line 2788 */
  sim_icache_fetch(1753 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4200); /* line 2790 */
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1050); /* line 2792 */
} /* line 2792 */
  sim_icache_fetch(1757 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L116X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L116X3;
} /* line 2794 */
l_L108X3: ;/* line 2797 */
LABEL(l_L108X3);
  sim_icache_fetch(1758 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 2798 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 2799 */
} /* line 2799 */
  sim_icache_fetch(1760 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 1),0,1), reg_r0_3); /* line 2801 */
   GOTO(l_L109X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L109X3;
} /* line 2802 */
l_L106X3: ;/* line 2805 */
LABEL(l_L106X3);
  sim_icache_fetch(1762 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 2806 */
   ADD(reg_r0_11, reg_r0_16, (unsigned int) 4200); /* line 2807 */
} /* line 2807 */
  sim_icache_fetch(1765 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4200); /* line 2809 */
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1050); /* line 2811 */
} /* line 2811 */
  sim_icache_fetch(1769 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L116X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L116X3;
} /* line 2813 */
l_L105X3: ;/* line 2816 */
LABEL(l_L105X3);
  sim_icache_fetch(1770 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 2817 */
} /* line 2817 */
  sim_icache_fetch(1771 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_7,0,1), reg_r0_3); /* line 2819 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2821 */
  sim_icache_fetch(1773 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L107X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L107X3;
} /* line 2823 */
l_L104X3: ;/* line 2826 */
LABEL(l_L104X3);
  sim_icache_fetch(1774 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_16, (unsigned int) 4200); /* line 2827 */
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4200); /* line 2828 */
} /* line 2828 */
  sim_icache_fetch(1778 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 2830 */
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1050); /* line 2831 */
} /* line 2831 */
l_L116X3: ;/* line 2833 */
LABEL(l_L116X3);
  sim_icache_fetch(1781 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_14); /* line 2834 */
   GOTO(l_L101X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L101X3;
} /* line 2835 */
l_L102X3: ;/* line 2838 */
LABEL(l_L102X3);
  sim_icache_fetch(1783 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_slow);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2840 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 245: goto l_L69X3;
    case 246: goto l_L71X3;
    case 247: goto l_L72X3;
    case 248: goto l_L70X3;
    case 249: goto l_L73X3;
    case 250: goto l_L75X3;
    case 251: goto l_L76X3;
    case 252: goto l_L74X3;
    case 253: goto l_L77X3;
    case 254: goto l_L79X3;
    case 255: goto l_L83X3;
    case 256: goto l_L82X3;
    case 257: goto l_L81X3;
    case 258: goto l_L80X3;
    case 259: goto l_L84X3;
    case 260: goto l_L78X3;
    case 261: goto l_L85X3;
    case 262: goto l_L87X3;
    case 263: goto l_L91X3;
    case 264: goto l_L90X3;
    case 265: goto l_L89X3;
    case 266: goto l_L88X3;
    case 267: goto l_L92X3;
    case 268: goto l_L86X3;
    case 269: goto l_L93X3;
    case 270: goto l_L95X3;
    case 271: goto l_L99X3;
    case 272: goto l_L98X3;
    case 273: goto l_L97X3;
    case 274: goto l_L96X3;
    case 275: goto l_L100X3;
    case 276: goto l_L94X3;
    case 277: goto l_L101X3;
    case 278: goto l_L103X3;
    case 279: goto l_L107X3;
    case 280: goto l_L109X3;
    case 281: goto l_L113X3;
    case 282: goto l_L115X3;
    case 283: goto l_L114X3;
    case 284: goto l_L112X3;
    case 285: goto l_L111X3;
    case 286: goto l_L110X3;
    case 287: goto l_L108X3;
    case 288: goto l_L106X3;
    case 289: goto l_L105X3;
    case 290: goto l_L104X3;
    case 291: goto l_L116X3;
    case 292: goto l_L102X3;
    case 293:
      reg_l0_0 = t_client_rpc;
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"deriche.s", 1792, 0, 0, 0, 2};


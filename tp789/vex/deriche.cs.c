/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /home/matthias/vex-3.43 -I../include/ -ms -mas_g -mas_t -O2 -fmm=./vliw4.mm -DVEX -o edge_detect" */

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
unsigned int ay2[1575000];
unsigned int ay1[1575000];
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
extern unsigned int reg_r0_30;
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
   SUB(reg_r0_7, 0, reg_r0_3); /* line 20 */
} /* line 20 */
  sim_icache_fetch(2 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_2, reg_r0_7); /* line 22 */
   MOV(reg_r0_6, (unsigned int) in); /* line 23 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 24 */
} /* line 24 */
  sim_icache_fetch(6 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, (unsigned int) y1); /* line 26 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 140),0,4), reg_r0_57); /* line 27 */
} /* line 27 */
  sim_icache_fetch(9 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 144),0,4), reg_r0_58); /* line 29 */
} /* line 29 */
  sim_icache_fetch(10 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 148),0,4), reg_r0_59); /* line 31 */
} /* line 31 */
  sim_icache_fetch(11 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 152),0,4), reg_r0_60); /* line 33 */
} /* line 33 */
  sim_icache_fetch(12 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 156),0,4), reg_r0_61); /* line 35 */
} /* line 35 */
  sim_icache_fetch(13 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 160),0,4), reg_r0_62); /* line 37 */
} /* line 37 */
  sim_icache_fetch(14 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 164),0,4), reg_r0_63); /* line 39 */
} /* line 39 */
  sim_icache_fetch(15 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 128),0,4), reg_r0_3); /* line 41 */
} /* line 41 */
  sim_icache_fetch(16 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_4); /* line 43 */
} /* line 43 */
l_L0X3: ;/* line 46 */
LABEL(l_L0X3);
  sim_icache_fetch(17 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 47 */
   SUB(reg_r0_4, 0, reg_r0_3); /* line 48 */
   MOV(reg_r0_62, reg_r0_5); /* line 49 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 96),0,4), reg_r0_3); /* line 50 */
} /* line 50 */
  sim_icache_fetch(21 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_60, 0); /* line 52 */
   MOV(reg_r0_57, reg_r0_4); /* line 53 */
   MOV(reg_r0_61, reg_r0_6); /* line 54 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 100),0,4), reg_r0_5); /* line 55 */
} /* line 55 */
  sim_icache_fetch(25 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_59, 0); /* line 57 */
   MOV(reg_r0_58, 0); /* line 58 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 104),0,4), reg_r0_6); /* line 59 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L1X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 60 */
  sim_icache_fetch(29 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, reg_r0_2); /* line 62 */
} /* line 62 */
l_L2X3: ;/* line 65 */
LABEL(l_L2X3);
  sim_icache_fetch(30 + t_thisfile.offset, 5);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPLT(reg_b0_0, reg_r0_57, 0); /* line 66 */
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 67 */
   MOV(reg_r0_3, reg_r0_58); /* line 68 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 69 */
   ADD_CYCLES(1);
} /* line 69 */
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
} /* line 71 */
		 /* line 72 */
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
} /* line 74 */
l_lr_3: ;/* line 74 */
LABEL(l_lr_3);
  sim_icache_fetch(38 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_58, reg_r0_59); /* line 76 */
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 77 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_3); /* line 78 */
} /* line 78 */
		 /* line 79 */
  sim_icache_fetch(42 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 82 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 82 */
l_lr_5: ;/* line 82 */
LABEL(l_lr_5);
  sim_icache_fetch(45 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1038202178); /* line 84 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_3); /* line 85 */
} /* line 85 */
		 /* line 86 */
  sim_icache_fetch(48 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_60); /* line 89 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 89 */
l_lr_7: ;/* line 89 */
LABEL(l_lr_7);
  sim_icache_fetch(51 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 48),0,4), reg_r0_3); /* line 91 */
} /* line 91 */
  sim_icache_fetch(52 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_59, mem_trace_ld(reg_r0_61,0,1)); /* line 93 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 94 */
   ADD_CYCLES(2);
} /* line 94 */
		 /* line 95 */
  sim_icache_fetch(54 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 98 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_ilfloat);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _r_ilfloat;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 98 */
l_lr_9: ;/* line 98 */
LABEL(l_lr_9);
		 /* line 99 */
  sim_icache_fetch(57 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) -1103022629); /* line 102 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 102 */
l_lr_11: ;/* line 102 */
LABEL(l_lr_11);
  sim_icache_fetch(61 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 52),0,4), reg_r0_3); /* line 104 */
} /* line 104 */
  sim_icache_fetch(62 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 106 */
} /* line 106 */
  sim_icache_fetch(63 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 108 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 109 */
   ADD_CYCLES(1);
} /* line 109 */
		 /* line 110 */
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
} /* line 112 */
l_lr_13: ;/* line 112 */
LABEL(l_lr_13);
  sim_icache_fetch(67 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 114 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 115 */
   ADD_CYCLES(1);
} /* line 115 */
		 /* line 116 */
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
} /* line 118 */
l_lr_15: ;/* line 118 */
LABEL(l_lr_15);
  sim_icache_fetch(71 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 120 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 121 */
   ADD_CYCLES(1);
} /* line 121 */
		 /* line 122 */
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
} /* line 124 */
l_lr_17: ;/* line 124 */
LABEL(l_lr_17);
  sim_icache_fetch(75 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 56),0,4), reg_r0_3); /* line 126 */
} /* line 126 */
		 /* line 127 */
  sim_icache_fetch(76 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st(reg_r0_62,0,4), reg_r0_3); /* line 129 */
   MOV(reg_r0_3, reg_r0_59); /* line 131 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_ufloat);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _r_ufloat;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 131 */
l_lr_19: ;/* line 131 */
LABEL(l_lr_19);
  sim_icache_fetch(80 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 133 */
   ADD(reg_r0_62, reg_r0_62, (unsigned int) 4); /* line 134 */
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 1); /* line 135 */
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 136 */
} /* line 136 */
  sim_icache_fetch(84 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, reg_r0_3); /* line 138 */
} /* line 138 */
  sim_icache_fetch(85 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L2X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L2X3;
} /* line 140 */
l_L3X3: ;/* line 143 */
LABEL(l_L3X3);
  sim_icache_fetch(86 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_63, (unsigned int) 1); /* line 144 */
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 104),0,4)); /* line 145 */
} /* line 145 */
  sim_icache_fetch(88 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 100),0,4)); /* line 147 */
} /* line 147 */
  sim_icache_fetch(89 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 149 */
} /* line 149 */
  sim_icache_fetch(90 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 1050); /* line 151 */
} /* line 151 */
  sim_icache_fetch(92 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4200); /* line 153 */
   GOTO(l_L0X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L0X3;
} /* line 154 */
l_L1X3: ;/* line 157 */
LABEL(l_L1X3);
  sim_icache_fetch(95 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, (unsigned int) y2); /* line 158 */
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 159 */
} /* line 159 */
  sim_icache_fetch(98 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) in); /* line 161 */
   LDW(reg_r0_7, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 162 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 163 */
   ADD_CYCLES(1);
} /* line 163 */
  sim_icache_fetch(102 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, 0, reg_r0_3); /* line 165 */
} /* line 165 */
  sim_icache_fetch(103 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_7, (unsigned int) -1); /* line 167 */
   MOV(reg_r0_2, reg_r0_3); /* line 168 */
} /* line 168 */
l_L4X3: ;/* line 171 */
LABEL(l_L4X3);
  sim_icache_fetch(105 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 172 */
   ADD(reg_r0_62, reg_r0_4, reg_r0_5); /* line 173 */
   SH2ADD(reg_r0_63, reg_r0_5, reg_r0_6); /* line 174 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 108),0,4), reg_r0_2); /* line 175 */
} /* line 175 */
  sim_icache_fetch(109 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_59, 0); /* line 177 */
   MOV(reg_r0_61, 0); /* line 178 */
   MOV(reg_r0_60, 0); /* line 179 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 112),0,4), reg_r0_4); /* line 180 */
} /* line 180 */
  sim_icache_fetch(113 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_58, 0); /* line 182 */
   MOV(reg_r0_57, reg_r0_5); /* line 183 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 116),0,4), reg_r0_5); /* line 184 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 185 */
  sim_icache_fetch(117 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 120),0,4), reg_r0_6); /* line 187 */
} /* line 187 */
l_L6X3: ;/* line 190 */
LABEL(l_L6X3);
  sim_icache_fetch(118 + t_thisfile.offset, 5);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPGE(reg_b0_0, reg_r0_57, 0); /* line 191 */
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 192 */
   MOV(reg_r0_3, reg_r0_58); /* line 193 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 194 */
   ADD_CYCLES(1);
} /* line 194 */
  sim_icache_fetch(123 + t_thisfile.offset, 1);
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
} /* line 196 */
		 /* line 197 */
  sim_icache_fetch(124 + t_thisfile.offset, 2);
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
} /* line 199 */
l_lr_25: ;/* line 199 */
LABEL(l_lr_25);
  sim_icache_fetch(126 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_58, reg_r0_59); /* line 201 */
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 202 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_3); /* line 203 */
} /* line 203 */
		 /* line 204 */
  sim_icache_fetch(130 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 207 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 207 */
l_lr_27: ;/* line 207 */
LABEL(l_lr_27);
  sim_icache_fetch(133 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) -1103022629); /* line 209 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_3); /* line 210 */
} /* line 210 */
		 /* line 211 */
  sim_icache_fetch(136 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_60); /* line 214 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 214 */
l_lr_29: ;/* line 214 */
LABEL(l_lr_29);
  sim_icache_fetch(139 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_60, reg_r0_61); /* line 216 */
   MOV(reg_r0_4, (unsigned int) -1103358174); /* line 217 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_3); /* line 218 */
} /* line 218 */
		 /* line 219 */
  sim_icache_fetch(143 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_61); /* line 222 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 222 */
l_lr_31: ;/* line 222 */
LABEL(l_lr_31);
  sim_icache_fetch(146 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 224 */
} /* line 224 */
  sim_icache_fetch(147 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 226 */
} /* line 226 */
  sim_icache_fetch(148 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 228 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 229 */
   ADD_CYCLES(1);
} /* line 229 */
		 /* line 230 */
  sim_icache_fetch(150 + t_thisfile.offset, 2);
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
} /* line 232 */
l_lr_33: ;/* line 232 */
LABEL(l_lr_33);
  sim_icache_fetch(152 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 234 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 235 */
   ADD_CYCLES(1);
} /* line 235 */
		 /* line 236 */
  sim_icache_fetch(154 + t_thisfile.offset, 2);
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
} /* line 238 */
l_lr_35: ;/* line 238 */
LABEL(l_lr_35);
  sim_icache_fetch(156 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 240 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 241 */
   ADD_CYCLES(1);
} /* line 241 */
		 /* line 242 */
  sim_icache_fetch(158 + t_thisfile.offset, 2);
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
l_lr_37: ;/* line 244 */
LABEL(l_lr_37);
  sim_icache_fetch(160 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_3); /* line 246 */
} /* line 246 */
  sim_icache_fetch(161 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_2, mem_trace_ld(reg_r0_62,0,1)); /* line 248 */
} /* line 248 */
  sim_icache_fetch(162 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_63,0,4), reg_r0_3); /* line 250 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 251 */
   ADD_CYCLES(1);
} /* line 251 */
		 /* line 252 */
  sim_icache_fetch(164 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_2); /* line 255 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_ufloat);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _r_ufloat;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 255 */
l_lr_39: ;/* line 255 */
LABEL(l_lr_39);
  sim_icache_fetch(167 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_63, reg_r0_63, (unsigned int) -4); /* line 257 */
   ADD(reg_r0_62, reg_r0_62, (unsigned int) -1); /* line 258 */
   ADD(reg_r0_57, reg_r0_57, (unsigned int) -1); /* line 259 */
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 260 */
} /* line 260 */
  sim_icache_fetch(171 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, reg_r0_3); /* line 262 */
} /* line 262 */
  sim_icache_fetch(172 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L6X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L6X3;
} /* line 264 */
l_L7X3: ;/* line 267 */
LABEL(l_L7X3);
  sim_icache_fetch(173 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 120),0,4)); /* line 268 */
} /* line 268 */
  sim_icache_fetch(174 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 112),0,4)); /* line 270 */
} /* line 270 */
  sim_icache_fetch(175 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 108),0,4)); /* line 272 */
} /* line 272 */
  sim_icache_fetch(176 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 4200); /* line 274 */
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 116),0,4)); /* line 275 */
} /* line 275 */
  sim_icache_fetch(179 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 1050); /* line 277 */
} /* line 277 */
  sim_icache_fetch(181 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 279 */
   GOTO(l_L4X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L4X3;
} /* line 280 */
l_L5X3: ;/* line 283 */
LABEL(l_L5X3);
  sim_icache_fetch(183 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_61, (unsigned int) t); /* line 284 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 285 */
} /* line 285 */
  sim_icache_fetch(186 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_58, (unsigned int) y2); /* line 287 */
   MOV(reg_r0_59, (unsigned int) y1); /* line 288 */
} /* line 288 */
  sim_icache_fetch(190 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 290 */
} /* line 290 */
  sim_icache_fetch(191 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_4); /* line 292 */
} /* line 292 */
  sim_icache_fetch(192 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_4); /* line 294 */
} /* line 294 */
l_L8X3: ;/* line 297 */
LABEL(l_L8X3);
  sim_icache_fetch(193 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 298 */
   MOV(reg_r0_57, 0); /* line 299 */
   SUB(reg_r0_4, 0, reg_r0_3); /* line 300 */
   MOV(reg_r0_62, reg_r0_2); /* line 301 */
} /* line 301 */
  sim_icache_fetch(197 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, reg_r0_4); /* line 303 */
   MOV(reg_r0_63, reg_r0_3); /* line 304 */
} /* line 304 */
  sim_icache_fetch(199 + t_thisfile.offset, 1);
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
} /* line 306 */
l_L10X3: ;/* line 309 */
LABEL(l_L10X3);
  sim_icache_fetch(200 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPLT(reg_b0_0, reg_r0_60, 0); /* line 310 */
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_58); /* line 311 */
   SH2ADD(reg_r0_5, reg_r0_57, reg_r0_59); /* line 312 */
} /* line 312 */
  sim_icache_fetch(203 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 314 */
} /* line 314 */
  sim_icache_fetch(204 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_5,0,4)); /* line 316 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L11X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 317 */
  sim_icache_fetch(206 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 318 */
		 /* line 319 */
  sim_icache_fetch(207 + t_thisfile.offset, 2);
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
} /* line 321 */
l_lr_45: ;/* line 321 */
LABEL(l_lr_45);
		 /* line 322 */
  sim_icache_fetch(209 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1065353216); /* line 325 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 325 */
l_lr_47: ;/* line 325 */
LABEL(l_lr_47);
  sim_icache_fetch(213 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_61); /* line 327 */
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 328 */
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 329 */
} /* line 329 */
  sim_icache_fetch(216 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_2,0,4), reg_r0_3); /* line 331 */
   GOTO(l_L10X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L10X3;
} /* line 332 */
l_L11X3: ;/* line 335 */
LABEL(l_L11X3);
  sim_icache_fetch(218 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_62, (unsigned int) 1); /* line 336 */
   MOV(reg_r0_5, (unsigned int) 4200); /* line 337 */
} /* line 337 */
  sim_icache_fetch(221 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_58, reg_r0_58, reg_r0_5); /* line 339 */
   ADD(reg_r0_59, reg_r0_59, reg_r0_5); /* line 340 */
   ADD(reg_r0_61, reg_r0_61, reg_r0_5); /* line 341 */
   MOV(reg_r0_3, reg_r0_63); /* line 343 */
} /* line 343 */
  sim_icache_fetch(225 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L8X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L8X3;
} /* line 345 */
l_L9X3: ;/* line 348 */
LABEL(l_L9X3);
  sim_icache_fetch(226 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SUB(reg_r0_3, 0, reg_r0_63); /* line 349 */
   MOV(reg_r0_62, (unsigned int) t); /* line 350 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 96),0,4), reg_r0_63); /* line 351 */
} /* line 351 */
  sim_icache_fetch(230 + t_thisfile.offset, 5);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_2, reg_r0_3); /* line 353 */
   MOV(reg_r0_63, (unsigned int) y1); /* line 354 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 355 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 356 */
   ADD_CYCLES(1);
} /* line 356 */
  sim_icache_fetch(235 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 357 */
l_L12X3: ;/* line 360 */
LABEL(l_L12X3);
  sim_icache_fetch(236 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 361 */
   SUB(reg_r0_5, 0, reg_r0_4); /* line 362 */
   MOV(reg_r0_61, 0); /* line 363 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 124),0,4), reg_r0_2); /* line 364 */
} /* line 364 */
  sim_icache_fetch(240 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_60, 0); /* line 366 */
   MOV(reg_r0_59, 0); /* line 367 */
   MOV(reg_r0_57, reg_r0_5); /* line 368 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 128),0,4), reg_r0_4); /* line 369 */
} /* line 369 */
  sim_icache_fetch(244 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_58, 0); /* line 371 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L13X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 372 */
l_L14X3: ;/* line 375 */
LABEL(l_L14X3);
  sim_icache_fetch(246 + t_thisfile.offset, 5);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPLT(reg_b0_0, reg_r0_57, 0); /* line 376 */
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 377 */
   MOV(reg_r0_3, reg_r0_58); /* line 378 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 379 */
   ADD_CYCLES(1);
} /* line 379 */
  sim_icache_fetch(251 + t_thisfile.offset, 1);
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
} /* line 381 */
		 /* line 382 */
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
} /* line 384 */
l_lr_53: ;/* line 384 */
LABEL(l_lr_53);
  sim_icache_fetch(254 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_58, reg_r0_59); /* line 386 */
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 387 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 388 */
} /* line 388 */
		 /* line 389 */
  sim_icache_fetch(258 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 392 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 392 */
l_lr_55: ;/* line 392 */
LABEL(l_lr_55);
  sim_icache_fetch(261 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1038202178); /* line 394 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 64),0,4), reg_r0_3); /* line 395 */
} /* line 395 */
		 /* line 396 */
  sim_icache_fetch(264 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_60); /* line 399 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 399 */
l_lr_57: ;/* line 399 */
LABEL(l_lr_57);
  sim_icache_fetch(267 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SH3ADD(reg_r0_2, reg_r0_61, reg_r0_62); /* line 401 */
   MOV(reg_r0_4, (unsigned int) -1103022629); /* line 402 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 68),0,4), reg_r0_3); /* line 403 */
} /* line 403 */
  sim_icache_fetch(271 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld(reg_r0_2,0,4)); /* line 405 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 406 */
   ADD_CYCLES(2);
} /* line 406 */
		 /* line 407 */
  sim_icache_fetch(273 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_60); /* line 410 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 410 */
l_lr_59: ;/* line 410 */
LABEL(l_lr_59);
  sim_icache_fetch(276 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 72),0,4), reg_r0_3); /* line 412 */
} /* line 412 */
  sim_icache_fetch(277 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 414 */
} /* line 414 */
  sim_icache_fetch(278 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 64),0,4)); /* line 416 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 417 */
   ADD_CYCLES(1);
} /* line 417 */
		 /* line 418 */
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
} /* line 420 */
l_lr_61: ;/* line 420 */
LABEL(l_lr_61);
  sim_icache_fetch(282 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 422 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 423 */
   ADD_CYCLES(1);
} /* line 423 */
		 /* line 424 */
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
} /* line 426 */
l_lr_63: ;/* line 426 */
LABEL(l_lr_63);
  sim_icache_fetch(286 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 72),0,4)); /* line 428 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 429 */
   ADD_CYCLES(1);
} /* line 429 */
		 /* line 430 */
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
} /* line 432 */
l_lr_65: ;/* line 432 */
LABEL(l_lr_65);
  sim_icache_fetch(290 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SH3ADD(reg_r0_2, reg_r0_61, reg_r0_63); /* line 434 */
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 435 */
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 525); /* line 436 */
} /* line 436 */
  sim_icache_fetch(294 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st(reg_r0_2,0,4), reg_r0_3); /* line 438 */
   MOV(reg_r0_59, reg_r0_3); /* line 439 */
   GOTO(l_L14X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L14X3;
} /* line 440 */
l_L15X3: ;/* line 443 */
LABEL(l_L15X3);
  sim_icache_fetch(297 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_62, reg_r0_62, (unsigned int) 4); /* line 444 */
   ADD(reg_r0_63, reg_r0_63, (unsigned int) 4); /* line 445 */
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 124),0,4)); /* line 446 */
} /* line 446 */
  sim_icache_fetch(300 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 448 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 449 */
   ADD_CYCLES(1);
} /* line 449 */
  sim_icache_fetch(302 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 451 */
   GOTO(l_L12X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L12X3;
} /* line 452 */
l_L13X3: ;/* line 455 */
LABEL(l_L13X3);
  sim_icache_fetch(304 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) t); /* line 456 */
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 457 */
} /* line 457 */
  sim_icache_fetch(307 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_63, (unsigned int) y2); /* line 459 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 76),0,4), reg_r0_4); /* line 460 */
} /* line 460 */
  sim_icache_fetch(310 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 462 */
} /* line 462 */
  sim_icache_fetch(311 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, 0, reg_r0_3); /* line 464 */
} /* line 464 */
  sim_icache_fetch(312 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_3); /* line 466 */
} /* line 466 */
  sim_icache_fetch(313 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_4, (unsigned int) -1); /* line 468 */
} /* line 468 */
l_L16X3: ;/* line 471 */
LABEL(l_L16X3);
  sim_icache_fetch(314 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 472 */
   MULLU(reg_r0_62, reg_r0_5, (unsigned int) 525); /* line 473 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 132),0,4), reg_r0_2); /* line 474 */
} /* line 474 */
  sim_icache_fetch(318 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_61, 0); /* line 476 */
   MOV(reg_r0_60, 0); /* line 477 */
   MOV(reg_r0_59, 0); /* line 478 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 136),0,4), reg_r0_5); /* line 479 */
} /* line 479 */
  sim_icache_fetch(322 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_58, 0); /* line 481 */
   MOV(reg_r0_57, reg_r0_5); /* line 482 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 483 */
l_L18X3: ;/* line 486 */
LABEL(l_L18X3);
  sim_icache_fetch(325 + t_thisfile.offset, 5);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPGE(reg_b0_0, reg_r0_57, 0); /* line 487 */
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 488 */
   MOV(reg_r0_3, reg_r0_58); /* line 489 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 490 */
   ADD_CYCLES(1);
} /* line 490 */
  sim_icache_fetch(330 + t_thisfile.offset, 1);
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
} /* line 492 */
		 /* line 493 */
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
} /* line 495 */
l_lr_71: ;/* line 495 */
LABEL(l_lr_71);
  sim_icache_fetch(333 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_58, reg_r0_59); /* line 497 */
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 498 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 80),0,4), reg_r0_3); /* line 499 */
} /* line 499 */
		 /* line 500 */
  sim_icache_fetch(337 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 503 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 503 */
l_lr_73: ;/* line 503 */
LABEL(l_lr_73);
  sim_icache_fetch(340 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1038770187); /* line 505 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 84),0,4), reg_r0_3); /* line 506 */
} /* line 506 */
		 /* line 507 */
  sim_icache_fetch(343 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_60); /* line 510 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 510 */
l_lr_75: ;/* line 510 */
LABEL(l_lr_75);
  sim_icache_fetch(346 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_60, reg_r0_61); /* line 512 */
   MOV(reg_r0_4, (unsigned int) -1103358174); /* line 513 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 88),0,4), reg_r0_3); /* line 514 */
} /* line 514 */
		 /* line 515 */
  sim_icache_fetch(350 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_61); /* line 518 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 518 */
l_lr_77: ;/* line 518 */
LABEL(l_lr_77);
  sim_icache_fetch(353 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 92),0,4), reg_r0_3); /* line 520 */
} /* line 520 */
  sim_icache_fetch(354 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 80),0,4)); /* line 522 */
} /* line 522 */
  sim_icache_fetch(355 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 84),0,4)); /* line 524 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 525 */
   ADD_CYCLES(1);
} /* line 525 */
		 /* line 526 */
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
} /* line 528 */
l_lr_79: ;/* line 528 */
LABEL(l_lr_79);
  sim_icache_fetch(359 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 88),0,4)); /* line 530 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 531 */
   ADD_CYCLES(1);
} /* line 531 */
		 /* line 532 */
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
} /* line 534 */
l_lr_81: ;/* line 534 */
LABEL(l_lr_81);
  sim_icache_fetch(363 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 92),0,4)); /* line 536 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 537 */
   ADD_CYCLES(1);
} /* line 537 */
		 /* line 538 */
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
} /* line 540 */
l_lr_83: ;/* line 540 */
LABEL(l_lr_83);
  sim_icache_fetch(367 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SH3ADD(reg_r0_4, reg_r0_62, reg_r0_63); /* line 542 */
   ADD(reg_r0_57, reg_r0_57, (unsigned int) -1); /* line 543 */
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 76),0,4)); /* line 544 */
   MOV(reg_r0_59, reg_r0_3); /* line 545 */
} /* line 545 */
  sim_icache_fetch(371 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_4,0,4), reg_r0_3); /* line 547 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 548 */
   ADD_CYCLES(1);
} /* line 548 */
  sim_icache_fetch(373 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SH3ADD(reg_r0_3, reg_r0_62, reg_r0_2); /* line 550 */
   ADD(reg_r0_62, reg_r0_62, (unsigned int) -525); /* line 551 */
} /* line 551 */
  sim_icache_fetch(376 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld(reg_r0_3,0,4)); /* line 553 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 554 */
   ADD_CYCLES(1);
} /* line 554 */
  sim_icache_fetch(378 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L18X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L18X3;
} /* line 556 */
l_L19X3: ;/* line 559 */
LABEL(l_L19X3);
  sim_icache_fetch(379 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_63, reg_r0_63, (unsigned int) 4); /* line 560 */
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 76),0,4)); /* line 561 */
} /* line 561 */
  sim_icache_fetch(381 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 132),0,4)); /* line 563 */
} /* line 563 */
  sim_icache_fetch(382 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 136),0,4)); /* line 565 */
} /* line 565 */
  sim_icache_fetch(383 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, (unsigned int) 4); /* line 567 */
} /* line 567 */
  sim_icache_fetch(384 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 569 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 76),0,4), reg_r0_3); /* line 570 */
   GOTO(l_L16X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L16X3;
} /* line 571 */
l_L17X3: ;/* line 574 */
LABEL(l_L17X3);
  sim_icache_fetch(387 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_61, (unsigned int) out); /* line 575 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 576 */
} /* line 576 */
  sim_icache_fetch(390 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_58, (unsigned int) y2); /* line 578 */
   MOV(reg_r0_59, (unsigned int) y1); /* line 579 */
} /* line 579 */
  sim_icache_fetch(394 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 581 */
} /* line 581 */
  sim_icache_fetch(395 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_4); /* line 583 */
} /* line 583 */
  sim_icache_fetch(396 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_4); /* line 585 */
} /* line 585 */
l_L20X3: ;/* line 588 */
LABEL(l_L20X3);
  sim_icache_fetch(397 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 589 */
   MOV(reg_r0_57, 0); /* line 590 */
   SUB(reg_r0_4, 0, reg_r0_3); /* line 591 */
   MOV(reg_r0_62, reg_r0_2); /* line 592 */
} /* line 592 */
  sim_icache_fetch(401 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, reg_r0_4); /* line 594 */
   MOV(reg_r0_63, reg_r0_3); /* line 595 */
} /* line 595 */
  sim_icache_fetch(403 + t_thisfile.offset, 1);
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
} /* line 597 */
l_L22X3: ;/* line 600 */
LABEL(l_L22X3);
  sim_icache_fetch(404 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPLT(reg_b0_0, reg_r0_60, 0); /* line 601 */
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_58); /* line 602 */
   SH2ADD(reg_r0_5, reg_r0_57, reg_r0_59); /* line 603 */
} /* line 603 */
  sim_icache_fetch(407 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 605 */
} /* line 605 */
  sim_icache_fetch(408 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_5,0,4)); /* line 607 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L23X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 608 */
  sim_icache_fetch(410 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 609 */
		 /* line 610 */
  sim_icache_fetch(411 + t_thisfile.offset, 2);
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
} /* line 612 */
l_lr_89: ;/* line 612 */
LABEL(l_lr_89);
		 /* line 613 */
  sim_icache_fetch(413 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 1065353216); /* line 616 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (198 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 616 */
l_lr_91: ;/* line 616 */
LABEL(l_lr_91);
		 /* line 617 */
  sim_icache_fetch(417 + t_thisfile.offset, 2);
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
} /* line 619 */
l_lr_93: ;/* line 619 */
LABEL(l_lr_93);
  sim_icache_fetch(419 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ZXTB(reg_r0_4, reg_r0_3); /* line 621 */
   ADD(reg_r0_2, reg_r0_57, reg_r0_61); /* line 622 */
   ADD(reg_r0_5, reg_r0_57, reg_r0_61); /* line 623 */
} /* line 623 */
  sim_icache_fetch(422 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 625 */
   CMPGT(reg_b0_0, reg_r0_4, (unsigned int) 25); /* line 626 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 627 */
   ADD_CYCLES(1);
} /* line 627 */
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
} /* line 629 */
  sim_icache_fetch(426 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STB(mem_trace_st(reg_r0_5,0,1), 0); /* line 631 */
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 632 */
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 633 */
   GOTO(l_L22X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L22X3;
} /* line 634 */
l_L24X3: ;/* line 637 */
LABEL(l_L24X3);
  sim_icache_fetch(430 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_2, reg_r0_57, reg_r0_61); /* line 638 */
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 639 */
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 640 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 641 */
} /* line 641 */
  sim_icache_fetch(434 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 643 */
   GOTO(l_L22X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L22X3;
} /* line 644 */
l_L23X3: ;/* line 647 */
LABEL(l_L23X3);
  sim_icache_fetch(436 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_59, reg_r0_59, (unsigned int) 4200); /* line 648 */
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 1050); /* line 649 */
} /* line 649 */
  sim_icache_fetch(440 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_2, reg_r0_62, (unsigned int) 1); /* line 651 */
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 4200); /* line 652 */
   MOV(reg_r0_3, reg_r0_63); /* line 654 */
} /* line 654 */
  sim_icache_fetch(444 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L20X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L20X3;
} /* line 656 */
l_L21X3: ;/* line 659 */
LABEL(l_L21X3);
  sim_icache_fetch(445 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 660 */
} /* line 660 */
  sim_icache_fetch(446 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 164),0,4)); /* line 662 */
} /* line 662 */
  sim_icache_fetch(447 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 160),0,4)); /* line 664 */
} /* line 664 */
  sim_icache_fetch(448 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 156),0,4)); /* line 666 */
} /* line 666 */
  sim_icache_fetch(449 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 152),0,4)); /* line 668 */
} /* line 668 */
  sim_icache_fetch(450 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 148),0,4)); /* line 670 */
} /* line 670 */
  sim_icache_fetch(451 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 144),0,4)); /* line 672 */
} /* line 672 */
  sim_icache_fetch(452 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 140),0,4)); /* line 674 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 675 */
   ADD_CYCLES(1);
} /* line 675 */
  sim_icache_fetch(454 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_float);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 192; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 678 */
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
  reg_l0_0 = (235 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(455 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 697 */
   ADD(reg_r0_18, reg_r0_4, (unsigned int) -1); /* line 698 */
} /* line 698 */
  sim_icache_fetch(457 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, ((unsigned int) in + (unsigned int) -1)); /* line 700 */
   MOV(reg_r0_20, ((unsigned int) ay2 + (unsigned int) -4)); /* line 701 */
} /* line 701 */
  sim_icache_fetch(461 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_3, reg_r0_2); /* line 703 */
   MOV(reg_r0_22, (unsigned int) in); /* line 704 */
   MOV(reg_r0_30, t__i32_0); /* line 705 */
} /* line 705 */
  sim_icache_fetch(465 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, (unsigned int) ay1); /* line 707 */
   MOV(reg_r0_5, reg_r0_4); /* line 708 */
} /* line 708 */
l_L25X3: ;/* line 711 */
LABEL(l_L25X3);
  sim_icache_fetch(468 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 712 */
   SUB(reg_r0_16, (unsigned int) 1, reg_r0_5); /* line 713 */
   ADD(reg_r0_15, reg_r0_17, reg_r0_18); /* line 714 */
   SH2ADD(reg_r0_14, reg_r0_18, reg_r0_20); /* line 715 */
} /* line 715 */
  sim_icache_fetch(472 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_8, reg_r0_16); /* line 717 */
   MOV(reg_r0_12, 0); /* line 718 */
   MOV(reg_r0_10, 0); /* line 719 */
   MOV(reg_r0_13, 0); /* line 720 */
} /* line 720 */
  sim_icache_fetch(476 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_6, 0); /* line 722 */
   MOV(reg_r0_11, 0); /* line 723 */
   MOV(reg_r0_9, reg_r0_21); /* line 724 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L26X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 725 */
  sim_icache_fetch(480 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_4, 0); /* line 727 */
   MOV(reg_r0_7, 0); /* line 728 */
   MOV(reg_r0_2, reg_r0_22); /* line 729 */
   MOV(reg_r0_23, reg_r0_3); /* line 730 */
} /* line 730 */
  sim_icache_fetch(484 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_24, reg_r0_5); /* line 732 */
   MOV(reg_r0_25, reg_r0_17); /* line 733 */
   MOV(reg_r0_26, reg_r0_18); /* line 734 */
   MOV(reg_r0_27, reg_r0_20); /* line 735 */
} /* line 735 */
  sim_icache_fetch(488 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_28, reg_r0_21); /* line 737 */
   MOV(reg_r0_29, reg_r0_22); /* line 738 */
} /* line 738 */
l_L27X3: ;/* line 741 */
LABEL(l_L27X3);
  sim_icache_fetch(490 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 742 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 743 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 215); /* line 744 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -155); /* line 745 */
} /* line 745 */
  sim_icache_fetch(494 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 747 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -155); /* line 748 */
   LDBUs(reg_r0_16, mem_trace_ld((reg_r0_15 + (unsigned int) 1),0,1)); /* line 749 */
   CMPLT(reg_b0_1, reg_r0_8, 0); /* line 750 */
} /* line 750 */
  sim_icache_fetch(498 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 752 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 8); /* line 753 */
   MULL(reg_r0_17, reg_r0_11, (unsigned int) -47); /* line 754 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 755 */
  sim_icache_fetch(502 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_18, reg_r0_3, (unsigned int) -48); /* line 757 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 758 */
   MULL(reg_r0_19, reg_r0_12, (unsigned int) 215); /* line 759 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 760 */
} /* line 760 */
  sim_icache_fetch(506 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_13, reg_r0_13, (unsigned int) -48); /* line 762 */
   ADD(reg_r0_17, reg_r0_17, reg_r0_10); /* line 763 */
   LDBUs(reg_r0_20, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 764 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 765 */
} /* line 765 */
  sim_icache_fetch(510 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_18, reg_r0_18, reg_r0_5); /* line 767 */
   SHR(reg_r0_19, reg_r0_19, (unsigned int) 8); /* line 768 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 769 */
   MULL(reg_r0_12, reg_r0_12, (unsigned int) -155); /* line 770 */
} /* line 770 */
  sim_icache_fetch(514 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_7, reg_r0_7, reg_r0_18); /* line 772 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_19); /* line 773 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 774 */
   MULL(reg_r0_5, reg_r0_16, (unsigned int) -47); /* line 775 */
} /* line 775 */
  sim_icache_fetch(518 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_17, reg_r0_17, reg_r0_13); /* line 777 */
   MULL(reg_r0_18, reg_r0_20, (unsigned int) -48); /* line 778 */
   MULL(reg_r0_19, reg_r0_7, (unsigned int) 215); /* line 779 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 780 */
} /* line 780 */
  sim_icache_fetch(522 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_11, reg_r0_11, (unsigned int) -48); /* line 782 */
   MULL(reg_r0_21, reg_r0_17, (unsigned int) 215); /* line 783 */
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 784 */
   LDBUs(reg_r0_22, mem_trace_ld(reg_r0_15,0,1)); /* line 785 */
} /* line 785 */
  sim_icache_fetch(526 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_19, reg_r0_19, (unsigned int) 8); /* line 787 */
   MOV(reg_r0_13, reg_r0_16); /* line 788 */
   MOV(reg_r0_10, reg_r0_17); /* line 789 */
   ADD(reg_r0_5, reg_r0_5, reg_r0_12); /* line 790 */
} /* line 790 */
  sim_icache_fetch(530 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_6, reg_r0_7); /* line 792 */
   ADD(reg_r0_18, reg_r0_18, reg_r0_19); /* line 793 */
   SHR(reg_r0_21, reg_r0_21, (unsigned int) 8); /* line 794 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 2); /* line 795 */
} /* line 795 */
  sim_icache_fetch(534 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_4, reg_r0_3, reg_r0_18); /* line 797 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_21); /* line 798 */
   ADD(reg_r0_15, reg_r0_15, (unsigned int) -2); /* line 799 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 800 */
} /* line 800 */
  sim_icache_fetch(538 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st(reg_r0_9,0,4), reg_r0_7); /* line 802 */
   ADD(reg_r0_12, reg_r0_5, reg_r0_11); /* line 803 */
   MOV(reg_r0_11, reg_r0_22); /* line 804 */
} /* line 804 */
  sim_icache_fetch(541 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_14 + (unsigned int) 4),0,4), reg_r0_17); /* line 806 */
   MOV(reg_r0_7, reg_r0_20); /* line 807 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L29X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 808 */
  sim_icache_fetch(544 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 4),0,4), reg_r0_4); /* line 810 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 811 */
} /* line 811 */
  sim_icache_fetch(546 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st(reg_r0_14,0,4), reg_r0_12); /* line 813 */
   ADD(reg_r0_14, reg_r0_14, (unsigned int) -8); /* line 814 */
   GOTO(l_L27X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L27X3;
} /* line 815 */
l_L29X3: ;/* line 818 */
LABEL(l_L29X3);
  sim_icache_fetch(549 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_22, reg_r0_29, (unsigned int) 1050); /* line 819 */
   ADD(reg_r0_20, reg_r0_27, (unsigned int) 6000); /* line 821 */
} /* line 821 */
  sim_icache_fetch(553 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L30X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L30X3;
} /* line 823 */
l_L28X3: ;/* line 826 */
LABEL(l_L28X3);
  sim_icache_fetch(554 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_22, reg_r0_29, (unsigned int) 1050); /* line 827 */
   ADD(reg_r0_20, reg_r0_27, (unsigned int) 6000); /* line 828 */
} /* line 828 */
l_L30X3: ;/* line 830 */
LABEL(l_L30X3);
  sim_icache_fetch(558 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_17, reg_r0_25, (unsigned int) 1050); /* line 831 */
   ADD(reg_r0_21, reg_r0_28, (unsigned int) 6000); /* line 832 */
} /* line 832 */
  sim_icache_fetch(562 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_3, reg_r0_23, (unsigned int) 1); /* line 834 */
   MOV(reg_r0_5, reg_r0_24); /* line 835 */
   MOV(reg_r0_18, reg_r0_26); /* line 836 */
   GOTO(l_L25X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L25X3;
} /* line 837 */
l_L26X3: ;/* line 840 */
LABEL(l_L26X3);
  sim_icache_fetch(566 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SUB(reg_r0_2, 0, reg_r0_30); /* line 841 */
   MOV(reg_r0_11, (unsigned int) ay2); /* line 842 */
   MOV(reg_r0_19, reg_r0_30); /* line 843 */
} /* line 843 */
  sim_icache_fetch(570 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_3, reg_r0_2); /* line 845 */
   MOV(reg_r0_10, (unsigned int) ay1); /* line 846 */
   MOV(reg_r0_7, reg_r0_5); /* line 847 */
} /* line 847 */
  sim_icache_fetch(574 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, (unsigned int) at); /* line 849 */
} /* line 849 */
l_L31X3: ;/* line 852 */
LABEL(l_L31X3);
  sim_icache_fetch(576 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 853 */
   SUB(reg_r0_8, (unsigned int) 3, reg_r0_7); /* line 854 */
   MOV(reg_r0_6, reg_r0_9); /* line 855 */
   MOV(reg_r0_4, reg_r0_10); /* line 856 */
} /* line 856 */
  sim_icache_fetch(580 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_5, reg_r0_8); /* line 858 */
   MOV(reg_r0_2, reg_r0_11); /* line 859 */
   MOV(reg_r0_12, reg_r0_3); /* line 860 */
   MOV(reg_r0_13, reg_r0_7); /* line 861 */
} /* line 861 */
  sim_icache_fetch(584 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_14, reg_r0_9); /* line 863 */
   MOV(reg_r0_15, reg_r0_10); /* line 864 */
   MOV(reg_r0_16, reg_r0_11); /* line 865 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L32X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 866 */
l_L33X3: ;/* line 869 */
LABEL(l_L33X3);
  sim_icache_fetch(588 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 870 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 871 */
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 872 */
   CMPLT(reg_b0_2, reg_r0_5, (unsigned int) 1); /* line 873 */
} /* line 873 */
  sim_icache_fetch(592 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   LDWs(reg_r0_7, mem_trace_ld(reg_r0_4,0,4)); /* line 875 */
   CMPLT(reg_b0_3, reg_r0_5, 0); /* line 876 */
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 877 */
} /* line 877 */
  sim_icache_fetch(595 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 879 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L34X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 880 */
  sim_icache_fetch(597 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 882 */
} /* line 882 */
  sim_icache_fetch(598 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_7); /* line 884 */
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 885 */
} /* line 885 */
  sim_icache_fetch(600 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 887 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 888 */
} /* line 888 */
  sim_icache_fetch(602 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 890 */
   ADD(reg_r0_8, reg_r0_8, reg_r0_9); /* line 891 */
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 892 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 893 */
} /* line 893 */
  sim_icache_fetch(606 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SHL(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 895 */
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 896 */
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 897 */
} /* line 897 */
  sim_icache_fetch(609 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st(reg_r0_6,0,4), reg_r0_3); /* line 899 */
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 900 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_10); /* line 901 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L35X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 902 */
  sim_icache_fetch(613 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 4),0,4), reg_r0_8); /* line 904 */
   SHL(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 905 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L36X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 906 */
  sim_icache_fetch(616 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 908 */
   ADD(reg_r0_9, reg_r0_9, reg_r0_11); /* line 909 */
} /* line 909 */
  sim_icache_fetch(618 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 8),0,4), reg_r0_7); /* line 911 */
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 912 */
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L37X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 913 */
  sim_icache_fetch(621 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 915 */
} /* line 915 */
  sim_icache_fetch(622 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 12),0,4), reg_r0_9); /* line 917 */
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 918 */
   GOTO(l_L33X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L33X3;
} /* line 919 */
l_L37X3: ;/* line 922 */
LABEL(l_L37X3);
  sim_icache_fetch(625 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_12, (unsigned int) 1); /* line 923 */
   MOV(reg_r0_7, reg_r0_13); /* line 924 */
   MOV(reg_r0_2, (unsigned int) 6000); /* line 925 */
} /* line 925 */
  sim_icache_fetch(629 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_9, reg_r0_14, reg_r0_2); /* line 927 */
   ADD(reg_r0_10, reg_r0_15, reg_r0_2); /* line 928 */
   ADD(reg_r0_11, reg_r0_16, reg_r0_2); /* line 929 */
   GOTO(l_L31X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L31X3;
} /* line 930 */
l_L36X3: ;/* line 933 */
LABEL(l_L36X3);
  sim_icache_fetch(633 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_12, (unsigned int) 1); /* line 934 */
   MOV(reg_r0_7, reg_r0_13); /* line 935 */
   MOV(reg_r0_2, (unsigned int) 6000); /* line 936 */
} /* line 936 */
  sim_icache_fetch(637 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_9, reg_r0_14, reg_r0_2); /* line 938 */
   ADD(reg_r0_10, reg_r0_15, reg_r0_2); /* line 939 */
   ADD(reg_r0_11, reg_r0_16, reg_r0_2); /* line 940 */
   GOTO(l_L31X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L31X3;
} /* line 941 */
l_L35X3: ;/* line 944 */
LABEL(l_L35X3);
  sim_icache_fetch(641 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_12, (unsigned int) 1); /* line 945 */
   MOV(reg_r0_7, reg_r0_13); /* line 946 */
   MOV(reg_r0_2, (unsigned int) 6000); /* line 947 */
} /* line 947 */
  sim_icache_fetch(645 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_9, reg_r0_14, reg_r0_2); /* line 949 */
   ADD(reg_r0_10, reg_r0_15, reg_r0_2); /* line 950 */
   ADD(reg_r0_11, reg_r0_16, reg_r0_2); /* line 951 */
   GOTO(l_L31X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L31X3;
} /* line 952 */
l_L34X3: ;/* line 955 */
LABEL(l_L34X3);
  sim_icache_fetch(649 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_12, (unsigned int) 1); /* line 956 */
   MOV(reg_r0_2, (unsigned int) 6000); /* line 957 */
} /* line 957 */
  sim_icache_fetch(652 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_9, reg_r0_14, reg_r0_2); /* line 959 */
   ADD(reg_r0_10, reg_r0_15, reg_r0_2); /* line 960 */
   ADD(reg_r0_11, reg_r0_16, reg_r0_2); /* line 961 */
   MOV(reg_r0_7, reg_r0_13); /* line 963 */
} /* line 963 */
  sim_icache_fetch(656 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L31X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L31X3;
} /* line 965 */
l_L32X3: ;/* line 968 */
LABEL(l_L32X3);
  sim_icache_fetch(657 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_6, reg_r0_19, (unsigned int) -1); /* line 969 */
   SUB(reg_r0_2, 0, reg_r0_13); /* line 970 */
   MOV(reg_r0_18, ((unsigned int) ay2 + (unsigned int) -6000)); /* line 971 */
} /* line 971 */
  sim_icache_fetch(661 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_3, reg_r0_2); /* line 973 */
   MOV(reg_r0_17, ((unsigned int) at + (unsigned int) -6000)); /* line 974 */
   MOV(reg_r0_27, reg_r0_13); /* line 975 */
} /* line 975 */
  sim_icache_fetch(665 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, (unsigned int) ay1); /* line 977 */
   MOV(reg_r0_22, (unsigned int) at); /* line 978 */
} /* line 978 */
l_L38X3: ;/* line 981 */
LABEL(l_L38X3);
  sim_icache_fetch(669 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 982 */
   SUB(reg_r0_20, (unsigned int) 1, reg_r0_19); /* line 983 */
   MULLU(reg_r0_16, reg_r0_6, (unsigned int) 6000); /* line 984 */
} /* line 984 */
  sim_icache_fetch(673 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_8, reg_r0_20); /* line 986 */
   MOV(reg_r0_11, 0); /* line 987 */
   MOV(reg_r0_13, 0); /* line 988 */
   MOV(reg_r0_12, 0); /* line 989 */
} /* line 989 */
  sim_icache_fetch(677 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_10, 0); /* line 991 */
   ADD(reg_r0_15, reg_r0_17, reg_r0_16); /* line 992 */
   ADD(reg_r0_14, reg_r0_18, reg_r0_16); /* line 993 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L39X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 994 */
  sim_icache_fetch(681 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_7, 0); /* line 996 */
   MOV(reg_r0_5, 0); /* line 997 */
   MOV(reg_r0_9, reg_r0_21); /* line 998 */
   MOV(reg_r0_2, reg_r0_22); /* line 999 */
} /* line 999 */
  sim_icache_fetch(685 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_4, 0); /* line 1001 */
   MOV(reg_r0_20, reg_r0_3); /* line 1002 */
   MOV(reg_r0_23, reg_r0_18); /* line 1003 */
   MOV(reg_r0_24, reg_r0_19); /* line 1004 */
} /* line 1004 */
  sim_icache_fetch(689 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  unsigned int t__i32_1;
  t__i32_1 = reg_r0_22 ;
  t__i32_0 = reg_r0_21 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_21, reg_r0_6); /* line 1006 */
   MOV(reg_r0_22, reg_r0_17); /* line 1007 */
   MOV(reg_r0_25, t__i32_0); /* line 1008 */
   MOV(reg_r0_26, t__i32_1); /* line 1009 */
} /* line 1009 */
l_L40X3: ;/* line 1012 */
LABEL(l_L40X3);
  sim_icache_fetch(693 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 1013 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1014 */
   MULL(reg_r0_6, reg_r0_5, (unsigned int) 215); /* line 1015 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 1016 */
} /* line 1016 */
  sim_icache_fetch(697 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 1018 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -155); /* line 1019 */
   LDWs(reg_r0_16, mem_trace_ld((reg_r0_15 + (unsigned int) 6000),0,4)); /* line 1020 */
} /* line 1020 */
  sim_icache_fetch(701 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_18, reg_r0_12, (unsigned int) 215); /* line 1022 */
   MULL(reg_r0_17, reg_r0_11, (unsigned int) -47); /* line 1023 */
   CMPLT(reg_b0_0, reg_r0_8, 0); /* line 1024 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L41X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1025 */
  sim_icache_fetch(705 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_19, reg_r0_3, (unsigned int) -48); /* line 1027 */
   ADD(reg_r0_6, reg_r0_6, reg_r0_7); /* line 1028 */
   MULL(reg_r0_13, reg_r0_13, (unsigned int) 29); /* line 1029 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 1030 */
} /* line 1030 */
  sim_icache_fetch(709 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_10, reg_r0_10, reg_r0_17); /* line 1032 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1033 */
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_2 + (unsigned int) 6000),0,4)); /* line 1034 */
} /* line 1034 */
  sim_icache_fetch(713 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_4, reg_r0_4, reg_r0_19); /* line 1036 */
   ADD(reg_r0_18, reg_r0_18, reg_r0_13); /* line 1037 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 1038 */
   MULL(reg_r0_12, reg_r0_12, (unsigned int) -155); /* line 1039 */
} /* line 1039 */
  sim_icache_fetch(717 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 1041 */
   ADD(reg_r0_10, reg_r0_10, reg_r0_18); /* line 1042 */
   MULL(reg_r0_11, reg_r0_11, (unsigned int) 29); /* line 1043 */
   MULL(reg_r0_6, reg_r0_16, (unsigned int) -47); /* line 1044 */
} /* line 1044 */
  sim_icache_fetch(721 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1046 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1047 */
   MULL(reg_r0_17, reg_r0_7, (unsigned int) -48); /* line 1048 */
   LDWs(reg_r0_18, mem_trace_ld(reg_r0_15,0,4)); /* line 1049 */
} /* line 1049 */
  sim_icache_fetch(725 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_6 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_19, reg_r0_4, (unsigned int) 215); /* line 1051 */
   MULL(reg_r0_6, reg_r0_10, (unsigned int) 215); /* line 1052 */
   MOV(reg_r0_13, reg_r0_16); /* line 1053 */
   ADD(reg_r0_12, reg_r0_12, t__i32_0); /* line 1054 */
} /* line 1054 */
  sim_icache_fetch(729 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_17 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st(reg_r0_9,0,4), reg_r0_4); /* line 1056 */
   MOV(reg_r0_17, reg_r0_4); /* line 1057 */
   ADD(reg_r0_5, reg_r0_5, t__i32_0); /* line 1058 */
   MOV(reg_r0_16, reg_r0_10); /* line 1059 */
} /* line 1059 */
  sim_icache_fetch(733 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_19, reg_r0_19, reg_r0_3); /* line 1061 */
   ADD(reg_r0_6, reg_r0_6, reg_r0_11); /* line 1062 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 12000); /* line 1063 */
} /* line 1063 */
  sim_icache_fetch(737 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_5, reg_r0_5, reg_r0_19); /* line 1065 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_6); /* line 1066 */
   ADD(reg_r0_15, reg_r0_15, (unsigned int) -12000); /* line 1067 */
} /* line 1067 */
  sim_icache_fetch(741 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1069 */
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1070 */
   MOV(reg_r0_11, reg_r0_18); /* line 1071 */
   MOV(reg_r0_4, reg_r0_17); /* line 1072 */
} /* line 1072 */
  sim_icache_fetch(745 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_14 + (unsigned int) 6000),0,4), reg_r0_10); /* line 1074 */
   MOV(reg_r0_10, reg_r0_16); /* line 1075 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L42X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1076 */
  sim_icache_fetch(749 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 6000),0,4), reg_r0_5); /* line 1078 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 12000); /* line 1079 */
} /* line 1079 */
  sim_icache_fetch(753 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st(reg_r0_14,0,4), reg_r0_12); /* line 1081 */
   ADD(reg_r0_14, reg_r0_14, (unsigned int) -12000); /* line 1082 */
   GOTO(l_L40X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L40X3;
} /* line 1083 */
l_L42X3: ;/* line 1086 */
LABEL(l_L42X3);
  sim_icache_fetch(757 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_3, reg_r0_20, (unsigned int) 1); /* line 1087 */
   MOV(reg_r0_6, reg_r0_21); /* line 1088 */
   MOV(reg_r0_19, reg_r0_24); /* line 1089 */
   GOTO(l_L43X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L43X3;
} /* line 1090 */
l_L41X3: ;/* line 1093 */
LABEL(l_L41X3);
  sim_icache_fetch(761 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_20, (unsigned int) 1); /* line 1094 */
   MOV(reg_r0_19, reg_r0_24); /* line 1095 */
   MOV(reg_r0_6, reg_r0_21); /* line 1096 */
} /* line 1096 */
l_L43X3: ;/* line 1098 */
LABEL(l_L43X3);
  sim_icache_fetch(764 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_21, reg_r0_25, (unsigned int) 4); /* line 1099 */
   ADD(reg_r0_17, reg_r0_22, (unsigned int) 4); /* line 1100 */
   ADD(reg_r0_18, reg_r0_23, (unsigned int) 4); /* line 1101 */
} /* line 1101 */
  sim_icache_fetch(767 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_22, reg_r0_26, (unsigned int) 4); /* line 1103 */
   GOTO(l_L38X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L38X3;
} /* line 1104 */
l_L39X3: ;/* line 1107 */
LABEL(l_L39X3);
  sim_icache_fetch(769 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_19, 0, reg_r0_19); /* line 1108 */
   MOV(reg_r0_12, (unsigned int) ay2); /* line 1109 */
} /* line 1109 */
  sim_icache_fetch(772 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_19); /* line 1111 */
   MOV(reg_r0_11, (unsigned int) ay1); /* line 1112 */
} /* line 1112 */
  sim_icache_fetch(775 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, (unsigned int) out); /* line 1114 */
   MOV(reg_r0_8, reg_r0_27); /* line 1115 */
} /* line 1115 */
l_L44X3: ;/* line 1118 */
LABEL(l_L44X3);
  sim_icache_fetch(778 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 1119 */
   SUB(reg_r0_9, (unsigned int) 3, reg_r0_8); /* line 1120 */
   MOV(reg_r0_7, reg_r0_10); /* line 1121 */
   MOV(reg_r0_6, reg_r0_10); /* line 1122 */
} /* line 1122 */
  sim_icache_fetch(782 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_5, reg_r0_9); /* line 1124 */
   MOV(reg_r0_4, reg_r0_11); /* line 1125 */
   MOV(reg_r0_2, reg_r0_12); /* line 1126 */
   MOV(reg_r0_14, reg_r0_3); /* line 1127 */
} /* line 1127 */
  sim_icache_fetch(786 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_15, reg_r0_8); /* line 1129 */
   MOV(reg_r0_16, reg_r0_10); /* line 1130 */
   MOV(reg_r0_17, reg_r0_11); /* line 1131 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L45X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1132 */
  sim_icache_fetch(790 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_12); /* line 1134 */
} /* line 1134 */
l_L46X3: ;/* line 1137 */
LABEL(l_L46X3);
  sim_icache_fetch(791 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 1138 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 1139 */
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 1140 */
   CMPLT(reg_b0_2, reg_r0_5, (unsigned int) 1); /* line 1141 */
} /* line 1141 */
  sim_icache_fetch(795 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_4,0,4)); /* line 1143 */
   CMPLT(reg_b0_3, reg_r0_5, 0); /* line 1144 */
} /* line 1144 */
  sim_icache_fetch(797 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 1146 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L47X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1147 */
  sim_icache_fetch(799 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 1149 */
} /* line 1149 */
  sim_icache_fetch(800 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_8); /* line 1151 */
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 1152 */
} /* line 1152 */
  sim_icache_fetch(802 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 1154 */
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 1155 */
} /* line 1155 */
  sim_icache_fetch(804 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 1157 */
   ADD(reg_r0_9, reg_r0_9, reg_r0_10); /* line 1158 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 1159 */
} /* line 1159 */
  sim_icache_fetch(807 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ZXTB(reg_r0_10, reg_r0_3); /* line 1161 */
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1162 */
   LDWs(reg_r0_13, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 1163 */
} /* line 1163 */
  sim_icache_fetch(810 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STB(mem_trace_st(reg_r0_6,0,1), reg_r0_3); /* line 1165 */
   CMPGT(reg_b0_0, reg_r0_10, (unsigned int) 25); /* line 1166 */
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 1167 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_8); /* line 1168 */
} /* line 1168 */
  sim_icache_fetch(814 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_9); /* line 1170 */
   SHL(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1171 */
} /* line 1171 */
  sim_icache_fetch(816 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 1173 */
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 1174 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_13); /* line 1175 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L48X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1176 */
  sim_icache_fetch(820 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STB(mem_trace_st(reg_r0_6,0,1), 0); /* line 1178 */
   ZXTB(reg_r0_8, reg_r0_11); /* line 1179 */
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1180 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1181 */
l_L50X3: ;/* line 1183 */
LABEL(l_L50X3);
  sim_icache_fetch(824 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), reg_r0_9); /* line 1184 */
   CMPGT(reg_b0_1, reg_r0_8, (unsigned int) 25); /* line 1185 */
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 1186 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L51X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1187 */
  sim_icache_fetch(828 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), 0); /* line 1189 */
   ZXTB(reg_r0_3, reg_r0_12); /* line 1190 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1191 */
l_L53X3: ;/* line 1193 */
LABEL(l_L53X3);
  sim_icache_fetch(831 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), reg_r0_11); /* line 1194 */
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 1195 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L54X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1196 */
  sim_icache_fetch(834 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), 0); /* line 1198 */
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L55X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1199 */
l_L56X3: ;/* line 1201 */
LABEL(l_L56X3);
  sim_icache_fetch(836 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), reg_r0_12); /* line 1202 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L57X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1203 */
  sim_icache_fetch(838 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 1205 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1206 */
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1207 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 1208 */
} /* line 1208 */
  sim_icache_fetch(842 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), 0); /* line 1210 */
} /* line 1210 */
l_L58X3: ;/* line 1212 */
LABEL(l_L58X3);
  sim_icache_fetch(843 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 4); /* line 1213 */
   GOTO(l_L46X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L46X3;
} /* line 1214 */
l_L57X3: ;/* line 1217 */
LABEL(l_L57X3);
  sim_icache_fetch(845 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 1218 */
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1219 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 1220 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1221 */
} /* line 1221 */
  sim_icache_fetch(849 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 3),0,1), reg_r0_3); /* line 1223 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1224 */
   GOTO(l_L58X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L58X3;
} /* line 1225 */
l_L55X3: ;/* line 1228 */
LABEL(l_L55X3);
  sim_icache_fetch(852 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 1229 */
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 6000); /* line 1230 */
   MOV(reg_r0_8, reg_r0_15); /* line 1231 */
} /* line 1231 */
  sim_icache_fetch(856 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 6000); /* line 1233 */
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 1050); /* line 1235 */
} /* line 1235 */
  sim_icache_fetch(860 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L44X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L44X3;
} /* line 1237 */
l_L54X3: ;/* line 1240 */
LABEL(l_L54X3);
  sim_icache_fetch(861 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_8, reg_r0_12); /* line 1241 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1242 */
} /* line 1242 */
  sim_icache_fetch(863 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 2),0,1), reg_r0_3); /* line 1244 */
   CMPGT(reg_b0_0, reg_r0_8, (unsigned int) 25); /* line 1245 */
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L59X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1246 */
  sim_icache_fetch(866 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L56X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L56X3;
} /* line 1248 */
l_L59X3: ;/* line 1251 */
LABEL(l_L59X3);
  sim_icache_fetch(867 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L55X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L55X3;
} /* line 1252 */
l_L52X3: ;/* line 1255 */
LABEL(l_L52X3);
  sim_icache_fetch(868 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 1256 */
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 6000); /* line 1257 */
   MOV(reg_r0_8, reg_r0_15); /* line 1258 */
} /* line 1258 */
  sim_icache_fetch(872 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 6000); /* line 1260 */
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 1050); /* line 1262 */
} /* line 1262 */
  sim_icache_fetch(876 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L44X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L44X3;
} /* line 1264 */
l_L51X3: ;/* line 1267 */
LABEL(l_L51X3);
  sim_icache_fetch(877 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ZXTB(reg_r0_10, reg_r0_11); /* line 1268 */
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 1269 */
   MOV(reg_r0_8, (unsigned int) 255); /* line 1270 */
} /* line 1270 */
  sim_icache_fetch(880 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 1),0,1), reg_r0_8); /* line 1272 */
   CMPGT(reg_b0_1, reg_r0_10, (unsigned int) 25); /* line 1273 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L60X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1274 */
  sim_icache_fetch(883 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 1275 */
  sim_icache_fetch(884 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_13); /* line 1277 */
} /* line 1277 */
  sim_icache_fetch(885 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1279 */
} /* line 1279 */
  sim_icache_fetch(886 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_9, (unsigned int) 16); /* line 1281 */
} /* line 1281 */
  sim_icache_fetch(887 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_12); /* line 1283 */
   GOTO(l_L53X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L53X3;
} /* line 1284 */
l_L60X3: ;/* line 1287 */
LABEL(l_L60X3);
  sim_icache_fetch(889 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L52X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L52X3;
} /* line 1288 */
l_L49X3: ;/* line 1291 */
LABEL(l_L49X3);
  sim_icache_fetch(890 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 1292 */
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 6000); /* line 1293 */
   MOV(reg_r0_8, reg_r0_15); /* line 1294 */
} /* line 1294 */
  sim_icache_fetch(894 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 6000); /* line 1296 */
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 1050); /* line 1298 */
} /* line 1298 */
  sim_icache_fetch(898 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L44X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L44X3;
} /* line 1300 */
l_L48X3: ;/* line 1303 */
LABEL(l_L48X3);
  sim_icache_fetch(899 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ZXTB(reg_r0_8, reg_r0_11); /* line 1304 */
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1305 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1306 */
} /* line 1306 */
  sim_icache_fetch(902 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_7,0,1), reg_r0_3); /* line 1308 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1310 */
  sim_icache_fetch(904 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L50X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L50X3;
} /* line 1312 */
l_L47X3: ;/* line 1315 */
LABEL(l_L47X3);
  sim_icache_fetch(905 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 6000); /* line 1316 */
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 6000); /* line 1317 */
} /* line 1317 */
  sim_icache_fetch(909 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 1319 */
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 1050); /* line 1320 */
   MOV(reg_r0_8, reg_r0_15); /* line 1322 */
} /* line 1322 */
  sim_icache_fetch(913 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L44X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L44X3;
} /* line 1324 */
l_L45X3: ;/* line 1327 */
LABEL(l_L45X3);
  sim_icache_fetch(914 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_array);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1329 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 199: goto l_L25X3;
    case 200: goto l_L27X3;
    case 201: goto l_L29X3;
    case 202: goto l_L28X3;
    case 203: goto l_L30X3;
    case 204: goto l_L26X3;
    case 205: goto l_L31X3;
    case 206: goto l_L33X3;
    case 207: goto l_L37X3;
    case 208: goto l_L36X3;
    case 209: goto l_L35X3;
    case 210: goto l_L34X3;
    case 211: goto l_L32X3;
    case 212: goto l_L38X3;
    case 213: goto l_L40X3;
    case 214: goto l_L42X3;
    case 215: goto l_L41X3;
    case 216: goto l_L43X3;
    case 217: goto l_L39X3;
    case 218: goto l_L44X3;
    case 219: goto l_L46X3;
    case 220: goto l_L50X3;
    case 221: goto l_L53X3;
    case 222: goto l_L56X3;
    case 223: goto l_L58X3;
    case 224: goto l_L57X3;
    case 225: goto l_L55X3;
    case 226: goto l_L54X3;
    case 227: goto l_L59X3;
    case 228: goto l_L52X3;
    case 229: goto l_L51X3;
    case 230: goto l_L60X3;
    case 231: goto l_L49X3;
    case 232: goto l_L48X3;
    case 233: goto l_L47X3;
    case 234: goto l_L45X3;
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
  reg_l0_0 = (264 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(915 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 1345 */
   ADD(reg_r0_11, reg_r0_4, (unsigned int) -1); /* line 1346 */
} /* line 1346 */
  sim_icache_fetch(917 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_28, (unsigned int) qy1); /* line 1348 */
   MOV(reg_r0_29, (unsigned int) in); /* line 1349 */
} /* line 1349 */
  sim_icache_fetch(921 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_4 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_4, reg_r0_2); /* line 1351 */
   MOV(reg_r0_27, (unsigned int) qy2); /* line 1352 */
   MOV(reg_r0_25, t__i32_0); /* line 1353 */
} /* line 1353 */
  sim_icache_fetch(925 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_26, (unsigned int) qt); /* line 1355 */
   MOV(reg_r0_12, ((unsigned int) qy2 + (unsigned int) -12)); /* line 1356 */
} /* line 1356 */
  sim_icache_fetch(929 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 1358 */
   MOV(reg_r0_30, reg_r0_3); /* line 1359 */
} /* line 1359 */
l_L61X3: ;/* line 1362 */
LABEL(l_L61X3);
  sim_icache_fetch(932 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 1363 */
   ADD(reg_r0_9, reg_r0_10, reg_r0_11); /* line 1364 */
   MOV(reg_r0_2, 0); /* line 1365 */
   SH2ADD(reg_r0_8, reg_r0_11, reg_r0_12); /* line 1366 */
} /* line 1366 */
  sim_icache_fetch(936 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_22, 0); /* line 1368 */
   MOV(reg_r0_5, 0); /* line 1369 */
   MOV(reg_r0_3, 0); /* line 1370 */
   MOV(reg_r0_6, 0); /* line 1371 */
} /* line 1371 */
  sim_icache_fetch(940 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_23, 0); /* line 1373 */
   MOV(reg_r0_24, 0); /* line 1374 */
   MOV(reg_r0_7, reg_r0_11); /* line 1375 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1376 */
  sim_icache_fetch(944 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_18, reg_r0_4); /* line 1378 */
   MOV(reg_r0_19, reg_r0_10); /* line 1379 */
   MOV(reg_r0_20, reg_r0_11); /* line 1380 */
   MOV(reg_r0_21, reg_r0_12); /* line 1381 */
} /* line 1381 */
l_L63X3: ;/* line 1384 */
LABEL(l_L63X3);
  sim_icache_fetch(948 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1385 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 1386 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 1387 */
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 3),0,1)); /* line 1388 */
} /* line 1388 */
  sim_icache_fetch(952 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -48); /* line 1390 */
   MULL(reg_r0_11, reg_r0_5, (unsigned int) 215); /* line 1391 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 1); /* line 1392 */
   LDBUs(reg_r0_12, mem_trace_ld((reg_r0_9 + (unsigned int) 2),0,1)); /* line 1393 */
} /* line 1393 */
  sim_icache_fetch(956 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1395 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 1396 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1397 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1398 */
  sim_icache_fetch(960 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1400 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_2); /* line 1401 */
   MULL(reg_r0_13, reg_r0_10, (unsigned int) -47); /* line 1402 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 2); /* line 1403 */
} /* line 1403 */
  sim_icache_fetch(964 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_6, reg_r0_6, reg_r0_11); /* line 1405 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1406 */
   MULL(reg_r0_11, reg_r0_12, (unsigned int) -47); /* line 1407 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 1408 */
} /* line 1408 */
  sim_icache_fetch(968 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 1410 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_5); /* line 1411 */
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_9 + (unsigned int) 1),0,1)); /* line 1412 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 1413 */
} /* line 1413 */
  sim_icache_fetch(972 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_15, reg_r0_4, (unsigned int) 215); /* line 1415 */
   MULL(reg_r0_16, reg_r0_4, (unsigned int) -155); /* line 1416 */
   LDBUs(reg_r0_17, mem_trace_ld(reg_r0_9,0,1)); /* line 1417 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 1418 */
} /* line 1418 */
  sim_icache_fetch(976 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 1420 */
   MULL(reg_r0_12, reg_r0_12, (unsigned int) -48); /* line 1421 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -4); /* line 1422 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L65X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1423 */
  sim_icache_fetch(980 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1425 */
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 1426 */
   MOV(reg_r0_6, reg_r0_14); /* line 1427 */
   MULL(reg_r0_4, reg_r0_14, (unsigned int) -47); /* line 1428 */
} /* line 1428 */
  sim_icache_fetch(984 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_15); /* line 1430 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_16); /* line 1431 */
} /* line 1431 */
  sim_icache_fetch(986 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_3); /* line 1433 */
   MOV(reg_r0_3, reg_r0_17); /* line 1434 */
} /* line 1434 */
  sim_icache_fetch(988 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_13); /* line 1436 */
   MULL(reg_r0_14, reg_r0_13, (unsigned int) 215); /* line 1437 */
   MULL(reg_r0_15, reg_r0_13, (unsigned int) -155); /* line 1438 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L66X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1439 */
  sim_icache_fetch(992 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 1440 */
  sim_icache_fetch(993 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 1442 */
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1443 */
} /* line 1443 */
  sim_icache_fetch(995 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_14); /* line 1445 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_15); /* line 1446 */
} /* line 1446 */
  sim_icache_fetch(997 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 1448 */
} /* line 1448 */
  sim_icache_fetch(998 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_11); /* line 1450 */
   MOV(reg_r0_2, reg_r0_11); /* line 1451 */
   MULL(reg_r0_10, reg_r0_11, (unsigned int) 215); /* line 1452 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L67X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1453 */
  sim_icache_fetch(1002 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 1454 */
  sim_icache_fetch(1003 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1456 */
} /* line 1456 */
  sim_icache_fetch(1004 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_10); /* line 1458 */
} /* line 1458 */
  sim_icache_fetch(1005 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_4, reg_r0_12); /* line 1460 */
} /* line 1460 */
  sim_icache_fetch(1006 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_5); /* line 1462 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 1463 */
   GOTO(l_L63X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L63X3;
} /* line 1464 */
l_L67X3: ;/* line 1467 */
LABEL(l_L67X3);
  sim_icache_fetch(1009 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SUB(reg_r0_13, (unsigned int) 2, reg_r0_25); /* line 1468 */
   MOV(reg_r0_8, reg_r0_27); /* line 1469 */
   MOV(reg_r0_11, reg_r0_28); /* line 1470 */
} /* line 1470 */
  sim_icache_fetch(1012 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, reg_r0_26); /* line 1472 */
   GOTO(l_L68X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L68X3;
} /* line 1473 */
l_L69X3: ;/* line 1476 */
LABEL(l_L69X3);
  sim_icache_fetch(1014 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_9, (unsigned int) 2); /* line 1477 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 1478 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 215); /* line 1479 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -155); /* line 1480 */
} /* line 1480 */
  sim_icache_fetch(1018 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 1482 */
   LDWs(reg_r0_12, mem_trace_ld(reg_r0_8,0,4)); /* line 1483 */
   CMPLT(reg_b0_1, reg_r0_9, (unsigned int) 1); /* line 1484 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1485 */
} /* line 1485 */
  sim_icache_fetch(1022 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1487 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 8); /* line 1488 */
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 1489 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L70X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1490 */
  sim_icache_fetch(1026 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_14, reg_r0_3, (unsigned int) -48); /* line 1492 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 1493 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 1494 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1495 */
} /* line 1495 */
  sim_icache_fetch(1030 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   LDWs(reg_r0_15, mem_trace_ld((reg_r0_8 + (unsigned int) 4),0,4)); /* line 1497 */
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 1498 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 3); /* line 1499 */
} /* line 1499 */
  sim_icache_fetch(1033 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_14, reg_r0_14, reg_r0_5); /* line 1501 */
   MULL(reg_r0_5, reg_r0_13, (unsigned int) -48); /* line 1502 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 1503 */
   LDBUs(reg_r0_16, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 1504 */
} /* line 1504 */
  sim_icache_fetch(1037 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_7, reg_r0_7, reg_r0_14); /* line 1506 */
   MULL(reg_r0_13, reg_r0_13, (unsigned int) 28); /* line 1507 */
   LDWs(reg_r0_14, mem_trace_ld((reg_r0_8 + (unsigned int) 8),0,4)); /* line 1508 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 3); /* line 1509 */
} /* line 1509 */
  sim_icache_fetch(1041 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_12, reg_r0_7, reg_r0_12); /* line 1511 */
   MULL(reg_r0_17, reg_r0_7, (unsigned int) 215); /* line 1512 */
   MULL(reg_r0_18, reg_r0_7, (unsigned int) -155); /* line 1513 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 12); /* line 1514 */
} /* line 1514 */
  sim_icache_fetch(1045 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st(reg_r0_11,0,4), reg_r0_7); /* line 1516 */
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1517 */
   MULL(reg_r0_19, reg_r0_16, (unsigned int) -48); /* line 1518 */
} /* line 1518 */
  sim_icache_fetch(1048 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1520 */
   SHR(reg_r0_17, reg_r0_17, (unsigned int) 8); /* line 1521 */
   SHR(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 1522 */
   MOV(reg_r0_7, reg_r0_16); /* line 1523 */
} /* line 1523 */
  sim_icache_fetch(1052 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_12); /* line 1525 */
   ADD(reg_r0_5, reg_r0_5, reg_r0_17); /* line 1526 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_18); /* line 1527 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L71X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1528 */
  sim_icache_fetch(1056 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_5); /* line 1530 */
} /* line 1530 */
  sim_icache_fetch(1057 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 4),0,4), reg_r0_3); /* line 1532 */
   ADD(reg_r0_15, reg_r0_3, reg_r0_15); /* line 1533 */
   MOV(reg_r0_6, reg_r0_3); /* line 1534 */
   MULL(reg_r0_5, reg_r0_3, (unsigned int) 215); /* line 1535 */
} /* line 1535 */
  sim_icache_fetch(1061 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1537 */
} /* line 1537 */
  sim_icache_fetch(1062 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1539 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1540 */
} /* line 1540 */
  sim_icache_fetch(1064 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4),0,4), reg_r0_15); /* line 1542 */
   ADD(reg_r0_19, reg_r0_19, reg_r0_5); /* line 1543 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1544 */
  sim_icache_fetch(1067 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_13, reg_r0_19); /* line 1546 */
} /* line 1546 */
  sim_icache_fetch(1068 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 8),0,4), reg_r0_4); /* line 1548 */
   ADD(reg_r0_14, reg_r0_4, reg_r0_14); /* line 1549 */
   ADD(reg_r0_11, reg_r0_11, (unsigned int) 12); /* line 1550 */
} /* line 1550 */
  sim_icache_fetch(1071 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 1552 */
} /* line 1552 */
  sim_icache_fetch(1072 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 1554 */
} /* line 1554 */
  sim_icache_fetch(1073 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 8),0,4), reg_r0_14); /* line 1556 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 12); /* line 1557 */
   GOTO(l_L69X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L69X3;
} /* line 1558 */
l_L72X3: ;/* line 1561 */
LABEL(l_L72X3);
  sim_icache_fetch(1076 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_29, reg_r0_29, (unsigned int) 1050); /* line 1562 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 1563 */
} /* line 1563 */
  sim_icache_fetch(1080 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_26, reg_r0_26, reg_r0_2); /* line 1565 */
   ADD(reg_r0_12, reg_r0_21, reg_r0_2); /* line 1566 */
   ADD(reg_r0_27, reg_r0_27, reg_r0_2); /* line 1567 */
   ADD(reg_r0_28, reg_r0_28, reg_r0_2); /* line 1569 */
} /* line 1569 */
  sim_icache_fetch(1084 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L73X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L73X3;
} /* line 1571 */
l_L71X3: ;/* line 1574 */
LABEL(l_L71X3);
  sim_icache_fetch(1085 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_29, reg_r0_29, (unsigned int) 1050); /* line 1575 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 1576 */
} /* line 1576 */
  sim_icache_fetch(1089 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_26, reg_r0_26, reg_r0_2); /* line 1578 */
   ADD(reg_r0_12, reg_r0_21, reg_r0_2); /* line 1579 */
   ADD(reg_r0_27, reg_r0_27, reg_r0_2); /* line 1580 */
   ADD(reg_r0_28, reg_r0_28, reg_r0_2); /* line 1582 */
} /* line 1582 */
  sim_icache_fetch(1093 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L73X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L73X3;
} /* line 1584 */
l_L70X3: ;/* line 1587 */
LABEL(l_L70X3);
  sim_icache_fetch(1094 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_29, reg_r0_29, (unsigned int) 1050); /* line 1588 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 1589 */
} /* line 1589 */
  sim_icache_fetch(1098 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_26, reg_r0_26, reg_r0_2); /* line 1591 */
   ADD(reg_r0_12, reg_r0_21, reg_r0_2); /* line 1592 */
   ADD(reg_r0_27, reg_r0_27, reg_r0_2); /* line 1593 */
   ADD(reg_r0_28, reg_r0_28, reg_r0_2); /* line 1594 */
} /* line 1594 */
l_L73X3: ;/* line 1596 */
LABEL(l_L73X3);
  sim_icache_fetch(1102 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_4, reg_r0_23, (unsigned int) 1); /* line 1597 */
   ADD(reg_r0_10, reg_r0_22, (unsigned int) 1050); /* line 1598 */
   MOV(reg_r0_11, reg_r0_20); /* line 1600 */
} /* line 1600 */
  sim_icache_fetch(1106 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L61X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L61X3;
} /* line 1602 */
l_L66X3: ;/* line 1605 */
LABEL(l_L66X3);
  sim_icache_fetch(1107 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SUB(reg_r0_13, (unsigned int) 2, reg_r0_25); /* line 1606 */
   MOV(reg_r0_10, reg_r0_26); /* line 1607 */
   MOV(reg_r0_8, reg_r0_27); /* line 1608 */
   MOV(reg_r0_11, reg_r0_28); /* line 1610 */
} /* line 1610 */
  sim_icache_fetch(1111 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L68X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L68X3;
} /* line 1612 */
l_L65X3: ;/* line 1615 */
LABEL(l_L65X3);
  sim_icache_fetch(1112 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SUB(reg_r0_13, (unsigned int) 2, reg_r0_25); /* line 1616 */
   MOV(reg_r0_10, reg_r0_26); /* line 1617 */
   MOV(reg_r0_8, reg_r0_27); /* line 1618 */
   MOV(reg_r0_11, reg_r0_28); /* line 1620 */
} /* line 1620 */
  sim_icache_fetch(1116 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L68X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L68X3;
} /* line 1622 */
l_L64X3: ;/* line 1625 */
LABEL(l_L64X3);
  sim_icache_fetch(1117 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SUB(reg_r0_13, (unsigned int) 2, reg_r0_25); /* line 1626 */
   MOV(reg_r0_10, reg_r0_26); /* line 1627 */
   MOV(reg_r0_8, reg_r0_27); /* line 1628 */
   MOV(reg_r0_11, reg_r0_28); /* line 1629 */
} /* line 1629 */
l_L68X3: ;/* line 1631 */
LABEL(l_L68X3);
  sim_icache_fetch(1121 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_9, reg_r0_13); /* line 1632 */
   MOV(reg_r0_2, reg_r0_29); /* line 1633 */
   MOV(reg_r0_7, reg_r0_22); /* line 1634 */
   MOV(reg_r0_4, reg_r0_23); /* line 1635 */
} /* line 1635 */
  sim_icache_fetch(1125 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_22, reg_r0_19); /* line 1637 */
   MOV(reg_r0_23, reg_r0_18); /* line 1638 */
   MOV(reg_r0_6, reg_r0_24); /* line 1639 */
   GOTO(l_L69X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L69X3;
} /* line 1640 */
l_L62X3: ;/* line 1643 */
LABEL(l_L62X3);
  sim_icache_fetch(1129 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_10, reg_r0_30, (unsigned int) -1); /* line 1644 */
   SUB(reg_r0_25, 0, reg_r0_25); /* line 1645 */
   MOV(reg_r0_28, (unsigned int) qt); /* line 1646 */
} /* line 1646 */
  sim_icache_fetch(1133 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_4, reg_r0_25); /* line 1648 */
   MOV(reg_r0_27, (unsigned int) qy1); /* line 1649 */
   MOV(reg_r0_24, reg_r0_30); /* line 1650 */
} /* line 1650 */
  sim_icache_fetch(1137 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_25, (unsigned int) out); /* line 1652 */
   MOV(reg_r0_26, (unsigned int) qy2); /* line 1653 */
} /* line 1653 */
  sim_icache_fetch(1141 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_13, ((unsigned int) qy2 + (unsigned int) -12600)); /* line 1655 */
   MOV(reg_r0_12, ((unsigned int) qt + (unsigned int) -12600)); /* line 1656 */
} /* line 1656 */
l_L74X3: ;/* line 1659 */
LABEL(l_L74X3);
  sim_icache_fetch(1145 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 1660 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 4200); /* line 1661 */
   MOV(reg_r0_3, 0); /* line 1662 */
} /* line 1662 */
  sim_icache_fetch(1149 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_21, 0); /* line 1664 */
   MOV(reg_r0_6, 0); /* line 1665 */
   MOV(reg_r0_5, 0); /* line 1666 */
   MOV(reg_r0_2, 0); /* line 1667 */
} /* line 1667 */
  sim_icache_fetch(1153 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 1669 */
   MOV(reg_r0_22, 0); /* line 1670 */
   ADD(reg_r0_8, reg_r0_13, reg_r0_11); /* line 1671 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L75X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1672 */
  sim_icache_fetch(1157 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_23, 0); /* line 1674 */
   MOV(reg_r0_7, reg_r0_10); /* line 1675 */
   MOV(reg_r0_17, reg_r0_4); /* line 1676 */
   MOV(reg_r0_18, reg_r0_10); /* line 1677 */
} /* line 1677 */
  sim_icache_fetch(1161 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, reg_r0_12); /* line 1679 */
   MOV(reg_r0_20, reg_r0_13); /* line 1680 */
} /* line 1680 */
l_L76X3: ;/* line 1683 */
LABEL(l_L76X3);
  sim_icache_fetch(1163 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1684 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 1685 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 1686 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 1); /* line 1687 */
} /* line 1687 */
  sim_icache_fetch(1167 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 1689 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 29); /* line 1690 */
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_9 + (unsigned int) 12600),0,4)); /* line 1691 */
} /* line 1691 */
  sim_icache_fetch(1171 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 1693 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1694 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 1695 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1696 */
  sim_icache_fetch(1175 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 1698 */
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 8400),0,4)); /* line 1699 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 2); /* line 1700 */
} /* line 1700 */
  sim_icache_fetch(1179 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 1702 */
   MULL(reg_r0_10, reg_r0_11, (unsigned int) -47); /* line 1703 */
   MULL(reg_r0_11, reg_r0_11, (unsigned int) 29); /* line 1704 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 1705 */
} /* line 1705 */
  sim_icache_fetch(1183 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1707 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,4)); /* line 1708 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 1709 */
} /* line 1709 */
  sim_icache_fetch(1187 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_10 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_10, reg_r0_2, (unsigned int) 215); /* line 1711 */
   ADD(reg_r0_5, reg_r0_5, t__i32_0); /* line 1712 */
   MULL(reg_r0_13, reg_r0_2, (unsigned int) -155); /* line 1713 */
   LDWs(reg_r0_14, mem_trace_ld(reg_r0_9,0,4)); /* line 1714 */
} /* line 1714 */
  sim_icache_fetch(1191 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MULL(reg_r0_15, reg_r0_4, (unsigned int) -47); /* line 1716 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 29); /* line 1717 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -16800); /* line 1718 */
} /* line 1718 */
  sim_icache_fetch(1195 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_10, reg_r0_10, reg_r0_3); /* line 1720 */
   MOV(reg_r0_6, reg_r0_12); /* line 1721 */
   MULL(reg_r0_16, reg_r0_12, (unsigned int) -47); /* line 1722 */
} /* line 1722 */
  sim_icache_fetch(1198 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 1724 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 1725 */
   MOV(reg_r0_3, reg_r0_14); /* line 1726 */
} /* line 1726 */
  sim_icache_fetch(1201 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_2); /* line 1728 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1729 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1730 */
  sim_icache_fetch(1205 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_5); /* line 1732 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 1733 */
   MULL(reg_r0_12, reg_r0_5, (unsigned int) -155); /* line 1734 */
} /* line 1734 */
  sim_icache_fetch(1209 + t_thisfile.offset, 1);
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
} /* line 1736 */
  sim_icache_fetch(1210 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 1738 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_16); /* line 1739 */
} /* line 1739 */
  sim_icache_fetch(1212 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, reg_r0_10); /* line 1741 */
} /* line 1741 */
  sim_icache_fetch(1213 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1743 */
} /* line 1743 */
  sim_icache_fetch(1214 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_13); /* line 1745 */
   MOV(reg_r0_2, reg_r0_13); /* line 1746 */
   MULL(reg_r0_10, reg_r0_13, (unsigned int) 215); /* line 1747 */
} /* line 1747 */
  sim_icache_fetch(1218 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1749 */
  sim_icache_fetch(1219 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_4); /* line 1751 */
} /* line 1751 */
  sim_icache_fetch(1220 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_10); /* line 1753 */
} /* line 1753 */
  sim_icache_fetch(1221 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_12, (unsigned int) 8); /* line 1755 */
} /* line 1755 */
  sim_icache_fetch(1222 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_5); /* line 1757 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16800); /* line 1758 */
   GOTO(l_L76X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L76X3;
} /* line 1759 */
l_L80X3: ;/* line 1762 */
LABEL(l_L80X3);
  sim_icache_fetch(1226 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SUB(reg_r0_6, (unsigned int) 1, reg_r0_24); /* line 1763 */
   MOV(reg_r0_10, reg_r0_25); /* line 1764 */
   MOV(reg_r0_8, reg_r0_26); /* line 1765 */
   MOV(reg_r0_2, reg_r0_28); /* line 1767 */
} /* line 1767 */
  sim_icache_fetch(1230 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L81X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L81X3;
} /* line 1769 */
l_L82X3: ;/* line 1772 */
LABEL(l_L82X3);
  sim_icache_fetch(1231 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_9, (unsigned int) 1); /* line 1773 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1774 */
   MULL(reg_r0_6, reg_r0_5, (unsigned int) 215); /* line 1775 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 1776 */
} /* line 1776 */
  sim_icache_fetch(1235 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 1778 */
   LDWs(reg_r0_13, mem_trace_ld(reg_r0_8,0,4)); /* line 1779 */
   CMPLT(reg_b0_1, reg_r0_9, 0); /* line 1780 */
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -155); /* line 1781 */
} /* line 1781 */
  sim_icache_fetch(1239 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_15, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 1783 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L83X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1784 */
  sim_icache_fetch(1242 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MULL(reg_r0_16, reg_r0_3, (unsigned int) -48); /* line 1786 */
   ADD(reg_r0_6, reg_r0_6, reg_r0_7); /* line 1787 */
   MULL(reg_r0_17, reg_r0_3, (unsigned int) 28); /* line 1788 */
} /* line 1788 */
  sim_icache_fetch(1245 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_18, mem_trace_ld((reg_r0_8 + (unsigned int) 4200),0,4)); /* line 1790 */
} /* line 1790 */
  sim_icache_fetch(1247 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_4, reg_r0_4, reg_r0_16); /* line 1792 */
   MULL(reg_r0_19, reg_r0_15, (unsigned int) -48); /* line 1793 */
   MOV(reg_r0_7, reg_r0_15); /* line 1794 */
} /* line 1794 */
  sim_icache_fetch(1250 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 1796 */
} /* line 1796 */
  sim_icache_fetch(1251 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1798 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_19); /* line 1799 */
} /* line 1799 */
  sim_icache_fetch(1253 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st(reg_r0_11,0,4), reg_r0_4); /* line 1801 */
   ADD(reg_r0_13, reg_r0_4, reg_r0_13); /* line 1802 */
   MOV(reg_r0_15, reg_r0_4); /* line 1803 */
   MULL(reg_r0_6, reg_r0_4, (unsigned int) 215); /* line 1804 */
} /* line 1804 */
  sim_icache_fetch(1257 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1806 */
   MOV(reg_r0_16, reg_r0_4); /* line 1807 */
} /* line 1807 */
  sim_icache_fetch(1259 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 1809 */
   ADD(reg_r0_6, reg_r0_6, reg_r0_17); /* line 1810 */
   MOV(reg_r0_4, reg_r0_15); /* line 1811 */
} /* line 1811 */
  sim_icache_fetch(1262 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ZXTB(reg_r0_15, reg_r0_13); /* line 1813 */
   STB(mem_trace_st(reg_r0_10,0,1), reg_r0_13); /* line 1814 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_6); /* line 1815 */
} /* line 1815 */
  sim_icache_fetch(1265 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_15, (unsigned int) 25); /* line 1817 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1818 */
   ADD_CYCLES(1);
} /* line 1818 */
  sim_icache_fetch(1267 + t_thisfile.offset, 1);
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
} /* line 1820 */
  sim_icache_fetch(1268 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STB(mem_trace_st(reg_r0_10,0,1), 0); /* line 1822 */
   SHR(reg_r0_5, reg_r0_14, (unsigned int) 8); /* line 1823 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L85X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1824 */
l_L86X3: ;/* line 1826 */
LABEL(l_L86X3);
  sim_icache_fetch(1271 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 4200),0,4), reg_r0_5); /* line 1827 */
   ADD(reg_r0_18, reg_r0_5, reg_r0_18); /* line 1828 */
} /* line 1828 */
  sim_icache_fetch(1274 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_18, reg_r0_18, (unsigned int) 8); /* line 1830 */
} /* line 1830 */
  sim_icache_fetch(1275 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_18, reg_r0_18, (unsigned int) 16); /* line 1832 */
} /* line 1832 */
  sim_icache_fetch(1276 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_18); /* line 1834 */
   STB(mem_trace_st((reg_r0_10 + (unsigned int) 1050),0,1), reg_r0_18); /* line 1835 */
} /* line 1835 */
  sim_icache_fetch(1279 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 1837 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1838 */
   ADD_CYCLES(1);
} /* line 1838 */
  sim_icache_fetch(1281 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L87X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1840 */
  sim_icache_fetch(1282 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 2); /* line 1842 */
   ADD(reg_r0_8, reg_r0_8, reg_r0_12); /* line 1843 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 1844 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_12); /* line 1845 */
} /* line 1845 */
  sim_icache_fetch(1286 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_10 + (unsigned int) 1050),0,1), 0); /* line 1847 */
} /* line 1847 */
l_L88X3: ;/* line 1849 */
LABEL(l_L88X3);
  sim_icache_fetch(1288 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 2100); /* line 1850 */
   GOTO(l_L82X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L82X3;
} /* line 1851 */
l_L87X3: ;/* line 1854 */
LABEL(l_L87X3);
  sim_icache_fetch(1291 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 2); /* line 1855 */
   ADD(reg_r0_8, reg_r0_8, reg_r0_12); /* line 1856 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 1857 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1858 */
} /* line 1858 */
  sim_icache_fetch(1295 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STB(mem_trace_st((reg_r0_10 + (unsigned int) 1050),0,1), reg_r0_3); /* line 1860 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_12); /* line 1861 */
   GOTO(l_L88X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L88X3;
} /* line 1862 */
l_L85X3: ;/* line 1865 */
LABEL(l_L85X3);
  sim_icache_fetch(1299 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_4, reg_r0_23, (unsigned int) 1); /* line 1866 */
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 1); /* line 1867 */
   ADD(reg_r0_13, reg_r0_21, (unsigned int) 4); /* line 1868 */
   ADD(reg_r0_26, reg_r0_26, (unsigned int) 4); /* line 1869 */
} /* line 1869 */
  sim_icache_fetch(1303 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_27, reg_r0_27, (unsigned int) 4); /* line 1871 */
   ADD(reg_r0_12, reg_r0_22, (unsigned int) 4); /* line 1872 */
   ADD(reg_r0_28, reg_r0_28, (unsigned int) 4); /* line 1873 */
   MOV(reg_r0_10, reg_r0_20); /* line 1875 */
} /* line 1875 */
  sim_icache_fetch(1307 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L74X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L74X3;
} /* line 1877 */
l_L84X3: ;/* line 1880 */
LABEL(l_L84X3);
  sim_icache_fetch(1308 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_14, (unsigned int) 8); /* line 1881 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1882 */
} /* line 1882 */
  sim_icache_fetch(1310 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_10,0,1), reg_r0_3); /* line 1884 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L85X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1886 */
  sim_icache_fetch(1312 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L86X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L86X3;
} /* line 1888 */
l_L83X3: ;/* line 1891 */
LABEL(l_L83X3);
  sim_icache_fetch(1313 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 1); /* line 1892 */
   ADD(reg_r0_26, reg_r0_26, (unsigned int) 4); /* line 1893 */
   ADD(reg_r0_27, reg_r0_27, (unsigned int) 4); /* line 1894 */
   ADD(reg_r0_28, reg_r0_28, (unsigned int) 4); /* line 1895 */
} /* line 1895 */
  sim_icache_fetch(1317 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_4, reg_r0_23, (unsigned int) 1); /* line 1897 */
   ADD(reg_r0_13, reg_r0_21, (unsigned int) 4); /* line 1898 */
   ADD(reg_r0_12, reg_r0_22, (unsigned int) 4); /* line 1899 */
   MOV(reg_r0_10, reg_r0_20); /* line 1901 */
} /* line 1901 */
  sim_icache_fetch(1321 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L74X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L74X3;
} /* line 1903 */
l_L79X3: ;/* line 1906 */
LABEL(l_L79X3);
  sim_icache_fetch(1322 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SUB(reg_r0_6, (unsigned int) 1, reg_r0_24); /* line 1907 */
   MOV(reg_r0_10, reg_r0_25); /* line 1908 */
   MOV(reg_r0_8, reg_r0_26); /* line 1909 */
   MOV(reg_r0_2, reg_r0_28); /* line 1911 */
} /* line 1911 */
  sim_icache_fetch(1326 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L81X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L81X3;
} /* line 1913 */
l_L78X3: ;/* line 1916 */
LABEL(l_L78X3);
  sim_icache_fetch(1327 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SUB(reg_r0_6, (unsigned int) 1, reg_r0_24); /* line 1917 */
   MOV(reg_r0_10, reg_r0_25); /* line 1918 */
   MOV(reg_r0_8, reg_r0_26); /* line 1919 */
   MOV(reg_r0_2, reg_r0_28); /* line 1921 */
} /* line 1921 */
  sim_icache_fetch(1331 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L81X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L81X3;
} /* line 1923 */
l_L77X3: ;/* line 1926 */
LABEL(l_L77X3);
  sim_icache_fetch(1332 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SUB(reg_r0_6, (unsigned int) 1, reg_r0_24); /* line 1927 */
   MOV(reg_r0_10, reg_r0_25); /* line 1928 */
   MOV(reg_r0_8, reg_r0_26); /* line 1929 */
   MOV(reg_r0_2, reg_r0_28); /* line 1930 */
} /* line 1930 */
l_L81X3: ;/* line 1932 */
LABEL(l_L81X3);
  sim_icache_fetch(1336 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_9, reg_r0_6); /* line 1933 */
   MOV(reg_r0_11, reg_r0_27); /* line 1934 */
   MOV(reg_r0_4, reg_r0_22); /* line 1935 */
   MOV(reg_r0_5, reg_r0_21); /* line 1936 */
} /* line 1936 */
  sim_icache_fetch(1340 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_21, reg_r0_20); /* line 1938 */
   MOV(reg_r0_7, reg_r0_23); /* line 1939 */
   MOV(reg_r0_12, (unsigned int) 8400); /* line 1940 */
} /* line 1940 */
  sim_icache_fetch(1344 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_20, reg_r0_18); /* line 1942 */
   MOV(reg_r0_22, reg_r0_19); /* line 1943 */
   MOV(reg_r0_23, reg_r0_17); /* line 1944 */
   GOTO(l_L82X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L82X3;
} /* line 1945 */
l_L75X3: ;/* line 1948 */
LABEL(l_L75X3);
  sim_icache_fetch(1348 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_fused);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1950 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 236: goto l_L61X3;
    case 237: goto l_L63X3;
    case 238: goto l_L67X3;
    case 239: goto l_L69X3;
    case 240: goto l_L72X3;
    case 241: goto l_L71X3;
    case 242: goto l_L70X3;
    case 243: goto l_L73X3;
    case 244: goto l_L66X3;
    case 245: goto l_L65X3;
    case 246: goto l_L64X3;
    case 247: goto l_L68X3;
    case 248: goto l_L62X3;
    case 249: goto l_L74X3;
    case 250: goto l_L76X3;
    case 251: goto l_L80X3;
    case 252: goto l_L82X3;
    case 253: goto l_L86X3;
    case 254: goto l_L88X3;
    case 255: goto l_L87X3;
    case 256: goto l_L85X3;
    case 257: goto l_L84X3;
    case 258: goto l_L83X3;
    case 259: goto l_L79X3;
    case 260: goto l_L78X3;
    case 261: goto l_L77X3;
    case 262: goto l_L81X3;
    case 263: goto l_L75X3;
    case 264:
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
  reg_l0_0 = (319 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1349 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 1966 */
   MOV(reg_r0_5, reg_r0_4); /* line 1967 */
} /* line 1967 */
  sim_icache_fetch(1351 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, (unsigned int) qy1); /* line 1969 */
   MOV(reg_r0_12, (unsigned int) in); /* line 1970 */
} /* line 1970 */
  sim_icache_fetch(1355 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_2); /* line 1972 */
   MOV(reg_r0_20, t__i32_0); /* line 1973 */
} /* line 1973 */
  sim_icache_fetch(1357 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 1974 */
l_L89X3: ;/* line 1977 */
LABEL(l_L89X3);
  sim_icache_fetch(1358 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 1978 */
   SUB(reg_r0_10, (unsigned int) 3, reg_r0_5); /* line 1979 */
   MOV(reg_r0_6, 0); /* line 1980 */
   MOV(reg_r0_9, reg_r0_11); /* line 1981 */
} /* line 1981 */
  sim_icache_fetch(1362 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_8, reg_r0_10); /* line 1983 */
   MOV(reg_r0_4, 0); /* line 1984 */
   MOV(reg_r0_7, 0); /* line 1985 */
   MOV(reg_r0_2, reg_r0_12); /* line 1986 */
} /* line 1986 */
  sim_icache_fetch(1366 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_16, reg_r0_3); /* line 1988 */
   MOV(reg_r0_17, reg_r0_5); /* line 1989 */
   MOV(reg_r0_18, reg_r0_11); /* line 1990 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L90X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1991 */
  sim_icache_fetch(1370 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_12); /* line 1993 */
} /* line 1993 */
l_L91X3: ;/* line 1996 */
LABEL(l_L91X3);
  sim_icache_fetch(1371 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 3); /* line 1997 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 1998 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 215); /* line 1999 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -155); /* line 2000 */
} /* line 2000 */
  sim_icache_fetch(1375 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 2002 */
   CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 2); /* line 2003 */
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 2004 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2005 */
} /* line 2005 */
  sim_icache_fetch(1379 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2007 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 8); /* line 2008 */
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 2009 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L92X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2010 */
  sim_icache_fetch(1383 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_11, reg_r0_3, (unsigned int) -48); /* line 2012 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 2013 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2014 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2015 */
} /* line 2015 */
  sim_icache_fetch(1387 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -48); /* line 2017 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 28); /* line 2018 */
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 2019 */
   CMPLT(reg_b0_2, reg_r0_8, 0); /* line 2020 */
} /* line 2020 */
  sim_icache_fetch(1391 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_11, reg_r0_11, reg_r0_5); /* line 2022 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 2023 */
   LDBUs(reg_r0_5, mem_trace_ld((reg_r0_2 + (unsigned int) 3),0,1)); /* line 2024 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 2025 */
} /* line 2025 */
  sim_icache_fetch(1395 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_11); /* line 2027 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 4); /* line 2028 */
} /* line 2028 */
  sim_icache_fetch(1397 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st(reg_r0_9,0,4), reg_r0_7); /* line 2030 */
   MULL(reg_r0_11, reg_r0_7, (unsigned int) 215); /* line 2031 */
   MULL(reg_r0_14, reg_r0_13, (unsigned int) -48); /* line 2032 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L93X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2033 */
  sim_icache_fetch(1401 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) -155); /* line 2035 */
   MULL(reg_r0_15, reg_r0_5, (unsigned int) -48); /* line 2036 */
} /* line 2036 */
  sim_icache_fetch(1403 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2038 */
   MULL(reg_r0_13, reg_r0_13, (unsigned int) 28); /* line 2039 */
} /* line 2039 */
  sim_icache_fetch(1405 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_11); /* line 2041 */
   SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 2042 */
} /* line 2042 */
  sim_icache_fetch(1407 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_3, reg_r0_12); /* line 2044 */
   ADD(reg_r0_10, reg_r0_10, reg_r0_7); /* line 2045 */
   MOV(reg_r0_7, reg_r0_5); /* line 2046 */
} /* line 2046 */
  sim_icache_fetch(1410 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 4),0,4), reg_r0_3); /* line 2048 */
   MULL(reg_r0_5, reg_r0_3, (unsigned int) 215); /* line 2049 */
   MULL(reg_r0_11, reg_r0_3, (unsigned int) -155); /* line 2050 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2051 */
  sim_icache_fetch(1414 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 2052 */
  sim_icache_fetch(1415 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2054 */
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2055 */
} /* line 2055 */
  sim_icache_fetch(1417 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_5); /* line 2057 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_11); /* line 2058 */
} /* line 2058 */
  sim_icache_fetch(1419 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_14); /* line 2060 */
} /* line 2060 */
  sim_icache_fetch(1420 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 8),0,4), reg_r0_10); /* line 2062 */
   MOV(reg_r0_6, reg_r0_10); /* line 2063 */
   MULL(reg_r0_3, reg_r0_10, (unsigned int) 215); /* line 2064 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L95X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2065 */
  sim_icache_fetch(1424 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 2066 */
  sim_icache_fetch(1425 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2068 */
} /* line 2068 */
  sim_icache_fetch(1426 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_3); /* line 2070 */
} /* line 2070 */
  sim_icache_fetch(1427 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_13, reg_r0_15); /* line 2072 */
} /* line 2072 */
  sim_icache_fetch(1428 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 12),0,4), reg_r0_4); /* line 2074 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 2075 */
   GOTO(l_L91X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L91X3;
} /* line 2076 */
l_L95X3: ;/* line 2079 */
LABEL(l_L95X3);
  sim_icache_fetch(1431 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_18, (unsigned int) 4200); /* line 2080 */
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 1050); /* line 2082 */
} /* line 2082 */
  sim_icache_fetch(1435 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L96X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L96X3;
} /* line 2084 */
l_L94X3: ;/* line 2087 */
LABEL(l_L94X3);
  sim_icache_fetch(1436 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 1050); /* line 2088 */
} /* line 2088 */
  sim_icache_fetch(1438 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_18, (unsigned int) 4200); /* line 2090 */
   GOTO(l_L96X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L96X3;
} /* line 2091 */
l_L93X3: ;/* line 2094 */
LABEL(l_L93X3);
  sim_icache_fetch(1441 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 1050); /* line 2095 */
} /* line 2095 */
  sim_icache_fetch(1443 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_18, (unsigned int) 4200); /* line 2097 */
   GOTO(l_L96X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L96X3;
} /* line 2098 */
l_L92X3: ;/* line 2101 */
LABEL(l_L92X3);
  sim_icache_fetch(1446 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_18, (unsigned int) 4200); /* line 2102 */
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 1050); /* line 2103 */
} /* line 2103 */
l_L96X3: ;/* line 2105 */
LABEL(l_L96X3);
  sim_icache_fetch(1450 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_16, (unsigned int) 1); /* line 2106 */
   MOV(reg_r0_5, reg_r0_17); /* line 2107 */
   GOTO(l_L89X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L89X3;
} /* line 2108 */
l_L90X3: ;/* line 2111 */
LABEL(l_L90X3);
  sim_icache_fetch(1453 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) -1); /* line 2112 */
   SUB(reg_r0_2, 0, reg_r0_20); /* line 2113 */
   MOV(reg_r0_12, ((unsigned int) qy2 + (unsigned int) -12)); /* line 2114 */
} /* line 2114 */
  sim_icache_fetch(1457 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_4, reg_r0_2); /* line 2116 */
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 2117 */
   MOV(reg_r0_22, reg_r0_20); /* line 2118 */
} /* line 2118 */
  sim_icache_fetch(1461 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_23, reg_r0_17); /* line 2120 */
} /* line 2120 */
l_L97X3: ;/* line 2123 */
LABEL(l_L97X3);
  sim_icache_fetch(1462 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 2124 */
   ADD(reg_r0_9, reg_r0_10, reg_r0_11); /* line 2125 */
   MOV(reg_r0_2, 0); /* line 2126 */
   SH2ADD(reg_r0_8, reg_r0_11, reg_r0_12); /* line 2127 */
} /* line 2127 */
  sim_icache_fetch(1466 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_5, 0); /* line 2129 */
   MOV(reg_r0_3, 0); /* line 2130 */
   MOV(reg_r0_6, 0); /* line 2131 */
   MOV(reg_r0_7, reg_r0_11); /* line 2132 */
} /* line 2132 */
  sim_icache_fetch(1470 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_18, reg_r0_4); /* line 2134 */
   MOV(reg_r0_19, reg_r0_10); /* line 2135 */
   MOV(reg_r0_20, reg_r0_11); /* line 2136 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2137 */
  sim_icache_fetch(1474 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_21, reg_r0_12); /* line 2139 */
} /* line 2139 */
l_L99X3: ;/* line 2142 */
LABEL(l_L99X3);
  sim_icache_fetch(1475 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2143 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 2144 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2145 */
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 3),0,1)); /* line 2146 */
} /* line 2146 */
  sim_icache_fetch(1479 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -48); /* line 2148 */
   MULL(reg_r0_11, reg_r0_5, (unsigned int) 215); /* line 2149 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 1); /* line 2150 */
   LDBUs(reg_r0_12, mem_trace_ld((reg_r0_9 + (unsigned int) 2),0,1)); /* line 2151 */
} /* line 2151 */
  sim_icache_fetch(1483 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2153 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 2154 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2155 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2156 */
  sim_icache_fetch(1487 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2158 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_2); /* line 2159 */
   MULL(reg_r0_13, reg_r0_10, (unsigned int) -47); /* line 2160 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 2); /* line 2161 */
} /* line 2161 */
  sim_icache_fetch(1491 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_6, reg_r0_6, reg_r0_11); /* line 2163 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2164 */
   MULL(reg_r0_11, reg_r0_12, (unsigned int) -47); /* line 2165 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 2166 */
} /* line 2166 */
  sim_icache_fetch(1495 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2168 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_5); /* line 2169 */
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_9 + (unsigned int) 1),0,1)); /* line 2170 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2171 */
} /* line 2171 */
  sim_icache_fetch(1499 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_15, reg_r0_4, (unsigned int) 215); /* line 2173 */
   MULL(reg_r0_16, reg_r0_4, (unsigned int) -155); /* line 2174 */
   LDBUs(reg_r0_17, mem_trace_ld(reg_r0_9,0,1)); /* line 2175 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 2176 */
} /* line 2176 */
  sim_icache_fetch(1503 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 2178 */
   MULL(reg_r0_12, reg_r0_12, (unsigned int) -48); /* line 2179 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -4); /* line 2180 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L101X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2181 */
  sim_icache_fetch(1507 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2183 */
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 2184 */
   MOV(reg_r0_6, reg_r0_14); /* line 2185 */
   MULL(reg_r0_4, reg_r0_14, (unsigned int) -47); /* line 2186 */
} /* line 2186 */
  sim_icache_fetch(1511 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_15); /* line 2188 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_16); /* line 2189 */
} /* line 2189 */
  sim_icache_fetch(1513 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_3); /* line 2191 */
   MOV(reg_r0_3, reg_r0_17); /* line 2192 */
} /* line 2192 */
  sim_icache_fetch(1515 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_13); /* line 2194 */
   MULL(reg_r0_14, reg_r0_13, (unsigned int) 215); /* line 2195 */
   MULL(reg_r0_15, reg_r0_13, (unsigned int) -155); /* line 2196 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2197 */
  sim_icache_fetch(1519 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 2198 */
  sim_icache_fetch(1520 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 8); /* line 2200 */
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2201 */
} /* line 2201 */
  sim_icache_fetch(1522 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_14); /* line 2203 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_15); /* line 2204 */
} /* line 2204 */
  sim_icache_fetch(1524 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 2206 */
} /* line 2206 */
  sim_icache_fetch(1525 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_11); /* line 2208 */
   MOV(reg_r0_2, reg_r0_11); /* line 2209 */
   MULL(reg_r0_10, reg_r0_11, (unsigned int) 215); /* line 2210 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L103X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2211 */
  sim_icache_fetch(1529 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 2212 */
  sim_icache_fetch(1530 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2214 */
} /* line 2214 */
  sim_icache_fetch(1531 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_10); /* line 2216 */
} /* line 2216 */
  sim_icache_fetch(1532 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_4, reg_r0_12); /* line 2218 */
} /* line 2218 */
  sim_icache_fetch(1533 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_5); /* line 2220 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 2221 */
   GOTO(l_L99X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L99X3;
} /* line 2222 */
l_L103X3: ;/* line 2225 */
LABEL(l_L103X3);
  sim_icache_fetch(1536 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_18, (unsigned int) 1); /* line 2226 */
   MOV(reg_r0_11, reg_r0_20); /* line 2227 */
} /* line 2227 */
  sim_icache_fetch(1538 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_19, (unsigned int) 1050); /* line 2229 */
   GOTO(l_L104X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L104X3;
} /* line 2230 */
l_L102X3: ;/* line 2233 */
LABEL(l_L102X3);
  sim_icache_fetch(1541 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_4, reg_r0_18, (unsigned int) 1); /* line 2234 */
   ADD(reg_r0_10, reg_r0_19, (unsigned int) 1050); /* line 2235 */
   MOV(reg_r0_11, reg_r0_20); /* line 2237 */
} /* line 2237 */
  sim_icache_fetch(1545 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L104X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L104X3;
} /* line 2239 */
l_L101X3: ;/* line 2242 */
LABEL(l_L101X3);
  sim_icache_fetch(1546 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_4, reg_r0_18, (unsigned int) 1); /* line 2243 */
   ADD(reg_r0_10, reg_r0_19, (unsigned int) 1050); /* line 2244 */
   MOV(reg_r0_11, reg_r0_20); /* line 2246 */
} /* line 2246 */
  sim_icache_fetch(1550 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L104X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L104X3;
} /* line 2248 */
l_L100X3: ;/* line 2251 */
LABEL(l_L100X3);
  sim_icache_fetch(1551 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_4, reg_r0_18, (unsigned int) 1); /* line 2252 */
   ADD(reg_r0_10, reg_r0_19, (unsigned int) 1050); /* line 2253 */
   MOV(reg_r0_11, reg_r0_20); /* line 2254 */
} /* line 2254 */
l_L104X3: ;/* line 2256 */
LABEL(l_L104X3);
  sim_icache_fetch(1555 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_21, (unsigned int) 4200); /* line 2257 */
   GOTO(l_L97X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L97X3;
} /* line 2258 */
l_L98X3: ;/* line 2261 */
LABEL(l_L98X3);
  sim_icache_fetch(1558 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SUB(reg_r0_2, 0, reg_r0_22); /* line 2262 */
   MOV(reg_r0_11, (unsigned int) qy2); /* line 2263 */
   MOV(reg_r0_17, reg_r0_22); /* line 2264 */
} /* line 2264 */
  sim_icache_fetch(1562 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_3, reg_r0_2); /* line 2266 */
   MOV(reg_r0_10, (unsigned int) qy1); /* line 2267 */
   MOV(reg_r0_7, reg_r0_23); /* line 2268 */
} /* line 2268 */
  sim_icache_fetch(1566 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, (unsigned int) qt); /* line 2270 */
} /* line 2270 */
l_L105X3: ;/* line 2273 */
LABEL(l_L105X3);
  sim_icache_fetch(1568 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2274 */
   SUB(reg_r0_8, (unsigned int) 3, reg_r0_7); /* line 2275 */
   MOV(reg_r0_6, reg_r0_9); /* line 2276 */
   MOV(reg_r0_4, reg_r0_10); /* line 2277 */
} /* line 2277 */
  sim_icache_fetch(1572 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_5, reg_r0_8); /* line 2279 */
   MOV(reg_r0_2, reg_r0_11); /* line 2280 */
   MOV(reg_r0_12, reg_r0_3); /* line 2281 */
   MOV(reg_r0_13, reg_r0_7); /* line 2282 */
} /* line 2282 */
  sim_icache_fetch(1576 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_14, reg_r0_9); /* line 2284 */
   MOV(reg_r0_15, reg_r0_10); /* line 2285 */
   MOV(reg_r0_16, reg_r0_11); /* line 2286 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2287 */
l_L107X3: ;/* line 2290 */
LABEL(l_L107X3);
  sim_icache_fetch(1580 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 2291 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2292 */
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2293 */
   CMPLT(reg_b0_2, reg_r0_5, (unsigned int) 1); /* line 2294 */
} /* line 2294 */
  sim_icache_fetch(1584 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   LDWs(reg_r0_7, mem_trace_ld(reg_r0_4,0,4)); /* line 2296 */
   CMPLT(reg_b0_3, reg_r0_5, 0); /* line 2297 */
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2298 */
} /* line 2298 */
  sim_icache_fetch(1587 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 2300 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L108X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2301 */
  sim_icache_fetch(1589 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 2303 */
} /* line 2303 */
  sim_icache_fetch(1590 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_7); /* line 2305 */
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 2306 */
} /* line 2306 */
  sim_icache_fetch(1592 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2308 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 2309 */
} /* line 2309 */
  sim_icache_fetch(1594 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2311 */
   ADD(reg_r0_8, reg_r0_8, reg_r0_9); /* line 2312 */
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 2313 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 2314 */
} /* line 2314 */
  sim_icache_fetch(1598 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SHL(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 2316 */
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 2317 */
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 2318 */
} /* line 2318 */
  sim_icache_fetch(1601 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st(reg_r0_6,0,4), reg_r0_3); /* line 2320 */
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 2321 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_10); /* line 2322 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L109X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2323 */
  sim_icache_fetch(1605 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 4),0,4), reg_r0_8); /* line 2325 */
   SHL(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 2326 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2327 */
  sim_icache_fetch(1608 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 2329 */
   ADD(reg_r0_9, reg_r0_9, reg_r0_11); /* line 2330 */
} /* line 2330 */
  sim_icache_fetch(1610 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 8),0,4), reg_r0_7); /* line 2332 */
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2333 */
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L111X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2334 */
  sim_icache_fetch(1613 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2336 */
} /* line 2336 */
  sim_icache_fetch(1614 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 12),0,4), reg_r0_9); /* line 2338 */
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 2339 */
   GOTO(l_L107X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L107X3;
} /* line 2340 */
l_L111X3: ;/* line 2343 */
LABEL(l_L111X3);
  sim_icache_fetch(1617 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_12, (unsigned int) 1); /* line 2344 */
   MOV(reg_r0_7, reg_r0_13); /* line 2345 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2346 */
} /* line 2346 */
  sim_icache_fetch(1621 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_9, reg_r0_14, reg_r0_2); /* line 2348 */
   ADD(reg_r0_10, reg_r0_15, reg_r0_2); /* line 2349 */
   ADD(reg_r0_11, reg_r0_16, reg_r0_2); /* line 2350 */
   GOTO(l_L105X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L105X3;
} /* line 2351 */
l_L110X3: ;/* line 2354 */
LABEL(l_L110X3);
  sim_icache_fetch(1625 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_12, (unsigned int) 1); /* line 2355 */
   MOV(reg_r0_7, reg_r0_13); /* line 2356 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2357 */
} /* line 2357 */
  sim_icache_fetch(1629 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_9, reg_r0_14, reg_r0_2); /* line 2359 */
   ADD(reg_r0_10, reg_r0_15, reg_r0_2); /* line 2360 */
   ADD(reg_r0_11, reg_r0_16, reg_r0_2); /* line 2361 */
   GOTO(l_L105X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L105X3;
} /* line 2362 */
l_L109X3: ;/* line 2365 */
LABEL(l_L109X3);
  sim_icache_fetch(1633 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_12, (unsigned int) 1); /* line 2366 */
   MOV(reg_r0_7, reg_r0_13); /* line 2367 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2368 */
} /* line 2368 */
  sim_icache_fetch(1637 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_9, reg_r0_14, reg_r0_2); /* line 2370 */
   ADD(reg_r0_10, reg_r0_15, reg_r0_2); /* line 2371 */
   ADD(reg_r0_11, reg_r0_16, reg_r0_2); /* line 2372 */
   GOTO(l_L105X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L105X3;
} /* line 2373 */
l_L108X3: ;/* line 2376 */
LABEL(l_L108X3);
  sim_icache_fetch(1641 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_12, (unsigned int) 1); /* line 2377 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2378 */
} /* line 2378 */
  sim_icache_fetch(1644 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_9, reg_r0_14, reg_r0_2); /* line 2380 */
   ADD(reg_r0_10, reg_r0_15, reg_r0_2); /* line 2381 */
   ADD(reg_r0_11, reg_r0_16, reg_r0_2); /* line 2382 */
   MOV(reg_r0_7, reg_r0_13); /* line 2384 */
} /* line 2384 */
  sim_icache_fetch(1648 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L105X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L105X3;
} /* line 2386 */
l_L106X3: ;/* line 2389 */
LABEL(l_L106X3);
  sim_icache_fetch(1649 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SUB(reg_r0_2, 0, reg_r0_13); /* line 2390 */
   MOV(reg_r0_12, (unsigned int) qt); /* line 2391 */
   MOV(reg_r0_19, reg_r0_13); /* line 2392 */
} /* line 2392 */
  sim_icache_fetch(1653 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_3, reg_r0_2); /* line 2394 */
   MOV(reg_r0_11, (unsigned int) qy1); /* line 2395 */
   MOV(reg_r0_6, reg_r0_17); /* line 2396 */
} /* line 2396 */
l_L112X3: ;/* line 2399 */
LABEL(l_L112X3);
  sim_icache_fetch(1657 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2400 */
   SUB(reg_r0_10, (unsigned int) 3, reg_r0_6); /* line 2401 */
   MOV(reg_r0_9, reg_r0_11); /* line 2402 */
   MOV(reg_r0_2, reg_r0_12); /* line 2403 */
} /* line 2403 */
  sim_icache_fetch(1661 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_8, reg_r0_10); /* line 2405 */
   MOV(reg_r0_7, 0); /* line 2406 */
   MOV(reg_r0_5, 0); /* line 2407 */
   MOV(reg_r0_4, 0); /* line 2408 */
} /* line 2408 */
  sim_icache_fetch(1665 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_15, reg_r0_3); /* line 2410 */
   MOV(reg_r0_16, reg_r0_6); /* line 2411 */
   MOV(reg_r0_17, reg_r0_11); /* line 2412 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2413 */
  sim_icache_fetch(1669 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_12); /* line 2415 */
} /* line 2415 */
l_L114X3: ;/* line 2418 */
LABEL(l_L114X3);
  sim_icache_fetch(1670 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 3); /* line 2419 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2420 */
   MULL(reg_r0_6, reg_r0_5, (unsigned int) 215); /* line 2421 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2422 */
} /* line 2422 */
  sim_icache_fetch(1674 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 2424 */
   CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 2); /* line 2425 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 2426 */
} /* line 2426 */
  sim_icache_fetch(1678 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2428 */
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 2429 */
   CMPLT(reg_b0_2, reg_r0_8, 0); /* line 2430 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2431 */
  sim_icache_fetch(1682 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_11, reg_r0_3, (unsigned int) -48); /* line 2433 */
   ADD(reg_r0_6, reg_r0_6, reg_r0_7); /* line 2434 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2435 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 4); /* line 2436 */
} /* line 2436 */
  sim_icache_fetch(1686 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -48); /* line 2438 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 28); /* line 2439 */
   LDWs(reg_r0_13, mem_trace_ld((reg_r0_2 + (unsigned int) 8400),0,4)); /* line 2440 */
} /* line 2440 */
  sim_icache_fetch(1690 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_11); /* line 2442 */
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_2 + (unsigned int) 12600),0,4)); /* line 2443 */
} /* line 2443 */
  sim_icache_fetch(1693 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2445 */
   ADD(reg_r0_5, reg_r0_5, reg_r0_12); /* line 2446 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16800); /* line 2447 */
} /* line 2447 */
  sim_icache_fetch(1697 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2449 */
   MULL(reg_r0_6, reg_r0_13, (unsigned int) -48); /* line 2450 */
   MULL(reg_r0_13, reg_r0_13, (unsigned int) 28); /* line 2451 */
} /* line 2451 */
  sim_icache_fetch(1700 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STW(mem_trace_st(reg_r0_9,0,4), reg_r0_4); /* line 2453 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) 215); /* line 2454 */
   MULL(reg_r0_12, reg_r0_4, (unsigned int) -155); /* line 2455 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L116X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2456 */
  sim_icache_fetch(1704 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_7, (unsigned int) -48); /* line 2458 */
} /* line 2458 */
  sim_icache_fetch(1705 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 2460 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_6); /* line 2461 */
} /* line 2461 */
  sim_icache_fetch(1707 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 2463 */
} /* line 2463 */
  sim_icache_fetch(1708 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2465 */
} /* line 2465 */
  sim_icache_fetch(1709 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 4200),0,4), reg_r0_5); /* line 2467 */
   MULL(reg_r0_3, reg_r0_5, (unsigned int) 215); /* line 2468 */
   MULL(reg_r0_6, reg_r0_5, (unsigned int) -155); /* line 2469 */
} /* line 2469 */
  sim_icache_fetch(1713 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L117X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2471 */
  sim_icache_fetch(1714 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_10); /* line 2473 */
   ADD(reg_r0_6, reg_r0_6, reg_r0_14); /* line 2474 */
} /* line 2474 */
  sim_icache_fetch(1716 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 2476 */
} /* line 2476 */
  sim_icache_fetch(1717 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2478 */
} /* line 2478 */
  sim_icache_fetch(1718 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 8400),0,4), reg_r0_12); /* line 2480 */
   MOV(reg_r0_4, reg_r0_12); /* line 2481 */
   MULL(reg_r0_3, reg_r0_12, (unsigned int) 215); /* line 2482 */
} /* line 2482 */
  sim_icache_fetch(1722 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2484 */
  sim_icache_fetch(1723 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_13); /* line 2486 */
} /* line 2486 */
  sim_icache_fetch(1724 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_3); /* line 2488 */
} /* line 2488 */
  sim_icache_fetch(1725 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_6, (unsigned int) 8); /* line 2490 */
} /* line 2490 */
  sim_icache_fetch(1726 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 12600),0,4), reg_r0_5); /* line 2492 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 16800); /* line 2494 */
} /* line 2494 */
  sim_icache_fetch(1730 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L114X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L114X3;
} /* line 2496 */
l_L118X3: ;/* line 2499 */
LABEL(l_L118X3);
  sim_icache_fetch(1731 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_3, reg_r0_15, (unsigned int) 1); /* line 2500 */
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4); /* line 2501 */
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 4); /* line 2502 */
   MOV(reg_r0_6, reg_r0_16); /* line 2504 */
} /* line 2504 */
  sim_icache_fetch(1735 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L112X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L112X3;
} /* line 2506 */
l_L117X3: ;/* line 2509 */
LABEL(l_L117X3);
  sim_icache_fetch(1736 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_3, reg_r0_15, (unsigned int) 1); /* line 2510 */
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4); /* line 2511 */
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 4); /* line 2512 */
   MOV(reg_r0_6, reg_r0_16); /* line 2514 */
} /* line 2514 */
  sim_icache_fetch(1740 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L112X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L112X3;
} /* line 2516 */
l_L116X3: ;/* line 2519 */
LABEL(l_L116X3);
  sim_icache_fetch(1741 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_15, (unsigned int) 1); /* line 2520 */
   MOV(reg_r0_6, reg_r0_16); /* line 2521 */
} /* line 2521 */
  sim_icache_fetch(1743 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4); /* line 2523 */
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 4); /* line 2524 */
   GOTO(l_L112X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L112X3;
} /* line 2525 */
l_L115X3: ;/* line 2528 */
LABEL(l_L115X3);
  sim_icache_fetch(1746 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_3, reg_r0_15, (unsigned int) 1); /* line 2529 */
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4); /* line 2530 */
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 4); /* line 2531 */
   MOV(reg_r0_6, reg_r0_16); /* line 2533 */
} /* line 2533 */
  sim_icache_fetch(1750 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L112X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L112X3;
} /* line 2535 */
l_L113X3: ;/* line 2538 */
LABEL(l_L113X3);
  sim_icache_fetch(1751 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_10, reg_r0_16, (unsigned int) -1); /* line 2539 */
   SUB(reg_r0_2, 0, reg_r0_19); /* line 2540 */
   MOV(reg_r0_13, ((unsigned int) qy2 + (unsigned int) -12600)); /* line 2541 */
} /* line 2541 */
  sim_icache_fetch(1755 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_4, reg_r0_2); /* line 2543 */
   MOV(reg_r0_12, ((unsigned int) qt + (unsigned int) -12600)); /* line 2544 */
   MOV(reg_r0_21, reg_r0_16); /* line 2545 */
} /* line 2545 */
  sim_icache_fetch(1759 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, reg_r0_19); /* line 2547 */
} /* line 2547 */
l_L119X3: ;/* line 2550 */
LABEL(l_L119X3);
  sim_icache_fetch(1760 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 2551 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 4200); /* line 2552 */
   MOV(reg_r0_3, 0); /* line 2553 */
} /* line 2553 */
  sim_icache_fetch(1764 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_6, 0); /* line 2555 */
   MOV(reg_r0_5, 0); /* line 2556 */
   MOV(reg_r0_2, 0); /* line 2557 */
   MOV(reg_r0_7, reg_r0_10); /* line 2558 */
} /* line 2558 */
  sim_icache_fetch(1768 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 2560 */
   ADD(reg_r0_8, reg_r0_13, reg_r0_11); /* line 2561 */
   MOV(reg_r0_17, reg_r0_4); /* line 2562 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2563 */
  sim_icache_fetch(1772 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_18, reg_r0_10); /* line 2565 */
   MOV(reg_r0_19, reg_r0_12); /* line 2566 */
   MOV(reg_r0_20, reg_r0_13); /* line 2567 */
} /* line 2567 */
l_L121X3: ;/* line 2570 */
LABEL(l_L121X3);
  sim_icache_fetch(1775 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2571 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2572 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 2573 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 1); /* line 2574 */
} /* line 2574 */
  sim_icache_fetch(1779 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 2576 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 29); /* line 2577 */
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_9 + (unsigned int) 12600),0,4)); /* line 2578 */
} /* line 2578 */
  sim_icache_fetch(1783 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2580 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2581 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 2582 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2583 */
  sim_icache_fetch(1787 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 2585 */
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 8400),0,4)); /* line 2586 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 2); /* line 2587 */
} /* line 2587 */
  sim_icache_fetch(1791 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 2589 */
   MULL(reg_r0_10, reg_r0_11, (unsigned int) -47); /* line 2590 */
   MULL(reg_r0_11, reg_r0_11, (unsigned int) 29); /* line 2591 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2592 */
} /* line 2592 */
  sim_icache_fetch(1795 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2594 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,4)); /* line 2595 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 2596 */
} /* line 2596 */
  sim_icache_fetch(1799 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_10 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MULL(reg_r0_10, reg_r0_2, (unsigned int) 215); /* line 2598 */
   ADD(reg_r0_5, reg_r0_5, t__i32_0); /* line 2599 */
   MULL(reg_r0_13, reg_r0_2, (unsigned int) -155); /* line 2600 */
   LDWs(reg_r0_14, mem_trace_ld(reg_r0_9,0,4)); /* line 2601 */
} /* line 2601 */
  sim_icache_fetch(1803 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MULL(reg_r0_15, reg_r0_4, (unsigned int) -47); /* line 2603 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 29); /* line 2604 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -16800); /* line 2605 */
} /* line 2605 */
  sim_icache_fetch(1807 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_10, reg_r0_10, reg_r0_3); /* line 2607 */
   MOV(reg_r0_6, reg_r0_12); /* line 2608 */
   MULL(reg_r0_16, reg_r0_12, (unsigned int) -47); /* line 2609 */
} /* line 2609 */
  sim_icache_fetch(1810 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 2611 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 2612 */
   MOV(reg_r0_3, reg_r0_14); /* line 2613 */
} /* line 2613 */
  sim_icache_fetch(1813 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_2); /* line 2615 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2616 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2617 */
  sim_icache_fetch(1817 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_5); /* line 2619 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 2620 */
   MULL(reg_r0_12, reg_r0_5, (unsigned int) -155); /* line 2621 */
} /* line 2621 */
  sim_icache_fetch(1821 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L124X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2623 */
  sim_icache_fetch(1822 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 2625 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_16); /* line 2626 */
} /* line 2626 */
  sim_icache_fetch(1824 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, reg_r0_10); /* line 2628 */
} /* line 2628 */
  sim_icache_fetch(1825 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2630 */
} /* line 2630 */
  sim_icache_fetch(1826 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_13); /* line 2632 */
   MOV(reg_r0_2, reg_r0_13); /* line 2633 */
   MULL(reg_r0_10, reg_r0_13, (unsigned int) 215); /* line 2634 */
} /* line 2634 */
  sim_icache_fetch(1830 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L125X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2636 */
  sim_icache_fetch(1831 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_4); /* line 2638 */
} /* line 2638 */
  sim_icache_fetch(1832 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_10); /* line 2640 */
} /* line 2640 */
  sim_icache_fetch(1833 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_12, (unsigned int) 8); /* line 2642 */
} /* line 2642 */
  sim_icache_fetch(1834 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_5); /* line 2644 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16800); /* line 2645 */
   GOTO(l_L121X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L121X3;
} /* line 2646 */
l_L125X3: ;/* line 2649 */
LABEL(l_L125X3);
  sim_icache_fetch(1838 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_4, reg_r0_17, (unsigned int) 1); /* line 2650 */
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 4); /* line 2651 */
   ADD(reg_r0_13, reg_r0_20, (unsigned int) 4); /* line 2652 */
   MOV(reg_r0_10, reg_r0_18); /* line 2654 */
} /* line 2654 */
  sim_icache_fetch(1842 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L119X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L119X3;
} /* line 2656 */
l_L124X3: ;/* line 2659 */
LABEL(l_L124X3);
  sim_icache_fetch(1843 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_4, reg_r0_17, (unsigned int) 1); /* line 2660 */
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 4); /* line 2661 */
   ADD(reg_r0_13, reg_r0_20, (unsigned int) 4); /* line 2662 */
   MOV(reg_r0_10, reg_r0_18); /* line 2664 */
} /* line 2664 */
  sim_icache_fetch(1847 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L119X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L119X3;
} /* line 2666 */
l_L123X3: ;/* line 2669 */
LABEL(l_L123X3);
  sim_icache_fetch(1848 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_4, reg_r0_17, (unsigned int) 1); /* line 2670 */
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 4); /* line 2671 */
   ADD(reg_r0_13, reg_r0_20, (unsigned int) 4); /* line 2672 */
   MOV(reg_r0_10, reg_r0_18); /* line 2674 */
} /* line 2674 */
  sim_icache_fetch(1852 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L119X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L119X3;
} /* line 2676 */
l_L122X3: ;/* line 2679 */
LABEL(l_L122X3);
  sim_icache_fetch(1853 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_4, reg_r0_17, (unsigned int) 1); /* line 2680 */
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 4); /* line 2681 */
   ADD(reg_r0_13, reg_r0_20, (unsigned int) 4); /* line 2682 */
   MOV(reg_r0_10, reg_r0_18); /* line 2684 */
} /* line 2684 */
  sim_icache_fetch(1857 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L119X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L119X3;
} /* line 2686 */
l_L120X3: ;/* line 2689 */
LABEL(l_L120X3);
  sim_icache_fetch(1858 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_21, 0, reg_r0_21); /* line 2690 */
   MOV(reg_r0_12, (unsigned int) qy2); /* line 2691 */
} /* line 2691 */
  sim_icache_fetch(1861 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_21); /* line 2693 */
   MOV(reg_r0_11, (unsigned int) qy1); /* line 2694 */
} /* line 2694 */
  sim_icache_fetch(1864 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, (unsigned int) out); /* line 2696 */
   MOV(reg_r0_8, reg_r0_22); /* line 2697 */
} /* line 2697 */
l_L126X3: ;/* line 2700 */
LABEL(l_L126X3);
  sim_icache_fetch(1867 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2701 */
   SUB(reg_r0_9, (unsigned int) 3, reg_r0_8); /* line 2702 */
   MOV(reg_r0_7, reg_r0_10); /* line 2703 */
   MOV(reg_r0_6, reg_r0_10); /* line 2704 */
} /* line 2704 */
  sim_icache_fetch(1871 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_5, reg_r0_9); /* line 2706 */
   MOV(reg_r0_4, reg_r0_11); /* line 2707 */
   MOV(reg_r0_2, reg_r0_12); /* line 2708 */
   MOV(reg_r0_14, reg_r0_3); /* line 2709 */
} /* line 2709 */
  sim_icache_fetch(1875 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_15, reg_r0_8); /* line 2711 */
   MOV(reg_r0_16, reg_r0_10); /* line 2712 */
   MOV(reg_r0_17, reg_r0_11); /* line 2713 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L127X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2714 */
  sim_icache_fetch(1879 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_12); /* line 2716 */
} /* line 2716 */
l_L128X3: ;/* line 2719 */
LABEL(l_L128X3);
  sim_icache_fetch(1880 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 2720 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2721 */
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2722 */
   CMPLT(reg_b0_2, reg_r0_5, (unsigned int) 1); /* line 2723 */
} /* line 2723 */
  sim_icache_fetch(1884 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_4,0,4)); /* line 2725 */
   CMPLT(reg_b0_3, reg_r0_5, 0); /* line 2726 */
} /* line 2726 */
  sim_icache_fetch(1886 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 2728 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2729 */
  sim_icache_fetch(1888 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 2731 */
} /* line 2731 */
  sim_icache_fetch(1889 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_8); /* line 2733 */
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 2734 */
} /* line 2734 */
  sim_icache_fetch(1891 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2736 */
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 2737 */
} /* line 2737 */
  sim_icache_fetch(1893 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 2739 */
   ADD(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2740 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 2741 */
} /* line 2741 */
  sim_icache_fetch(1896 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ZXTB(reg_r0_10, reg_r0_3); /* line 2743 */
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2744 */
   LDWs(reg_r0_13, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 2745 */
} /* line 2745 */
  sim_icache_fetch(1899 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STB(mem_trace_st(reg_r0_6,0,1), reg_r0_3); /* line 2747 */
   CMPGT(reg_b0_0, reg_r0_10, (unsigned int) 25); /* line 2748 */
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 2749 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_8); /* line 2750 */
} /* line 2750 */
  sim_icache_fetch(1903 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_9); /* line 2752 */
   SHL(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2753 */
} /* line 2753 */
  sim_icache_fetch(1905 + t_thisfile.offset, 4);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 2755 */
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 2756 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_13); /* line 2757 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2758 */
  sim_icache_fetch(1909 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STB(mem_trace_st(reg_r0_6,0,1), 0); /* line 2760 */
   ZXTB(reg_r0_8, reg_r0_11); /* line 2761 */
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2762 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2763 */
l_L132X3: ;/* line 2765 */
LABEL(l_L132X3);
  sim_icache_fetch(1913 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), reg_r0_9); /* line 2766 */
   CMPGT(reg_b0_1, reg_r0_8, (unsigned int) 25); /* line 2767 */
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 2768 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L133X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2769 */
  sim_icache_fetch(1917 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), 0); /* line 2771 */
   ZXTB(reg_r0_3, reg_r0_12); /* line 2772 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2773 */
l_L135X3: ;/* line 2775 */
LABEL(l_L135X3);
  sim_icache_fetch(1920 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), reg_r0_11); /* line 2776 */
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 2777 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2778 */
  sim_icache_fetch(1923 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), 0); /* line 2780 */
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L137X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2781 */
l_L138X3: ;/* line 2783 */
LABEL(l_L138X3);
  sim_icache_fetch(1925 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), reg_r0_12); /* line 2784 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L139X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2785 */
  sim_icache_fetch(1927 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2787 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 2788 */
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 2789 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 2790 */
} /* line 2790 */
  sim_icache_fetch(1931 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), 0); /* line 2792 */
} /* line 2792 */
l_L140X3: ;/* line 2794 */
LABEL(l_L140X3);
  sim_icache_fetch(1932 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 4); /* line 2795 */
   GOTO(l_L128X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L128X3;
} /* line 2796 */
l_L139X3: ;/* line 2799 */
LABEL(l_L139X3);
  sim_icache_fetch(1934 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2800 */
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 2801 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 2802 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 2803 */
} /* line 2803 */
  sim_icache_fetch(1938 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 3),0,1), reg_r0_3); /* line 2805 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 2806 */
   GOTO(l_L140X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L140X3;
} /* line 2807 */
l_L137X3: ;/* line 2810 */
LABEL(l_L137X3);
  sim_icache_fetch(1941 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 2811 */
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4200); /* line 2812 */
   MOV(reg_r0_8, reg_r0_15); /* line 2813 */
} /* line 2813 */
  sim_icache_fetch(1945 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 4200); /* line 2815 */
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 1050); /* line 2817 */
} /* line 2817 */
  sim_icache_fetch(1949 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L126X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L126X3;
} /* line 2819 */
l_L136X3: ;/* line 2822 */
LABEL(l_L136X3);
  sim_icache_fetch(1950 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_8, reg_r0_12); /* line 2823 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 2824 */
} /* line 2824 */
  sim_icache_fetch(1952 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 2),0,1), reg_r0_3); /* line 2826 */
   CMPGT(reg_b0_0, reg_r0_8, (unsigned int) 25); /* line 2827 */
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L141X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2828 */
  sim_icache_fetch(1955 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L138X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L138X3;
} /* line 2830 */
l_L141X3: ;/* line 2833 */
LABEL(l_L141X3);
  sim_icache_fetch(1956 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L137X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L137X3;
} /* line 2834 */
l_L134X3: ;/* line 2837 */
LABEL(l_L134X3);
  sim_icache_fetch(1957 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 2838 */
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4200); /* line 2839 */
   MOV(reg_r0_8, reg_r0_15); /* line 2840 */
} /* line 2840 */
  sim_icache_fetch(1961 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 4200); /* line 2842 */
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 1050); /* line 2844 */
} /* line 2844 */
  sim_icache_fetch(1965 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L126X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L126X3;
} /* line 2846 */
l_L133X3: ;/* line 2849 */
LABEL(l_L133X3);
  sim_icache_fetch(1966 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ZXTB(reg_r0_10, reg_r0_11); /* line 2850 */
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 2851 */
   MOV(reg_r0_8, (unsigned int) 255); /* line 2852 */
} /* line 2852 */
  sim_icache_fetch(1969 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 1),0,1), reg_r0_8); /* line 2854 */
   CMPGT(reg_b0_1, reg_r0_10, (unsigned int) 25); /* line 2855 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L142X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2856 */
  sim_icache_fetch(1972 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 2857 */
  sim_icache_fetch(1973 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_13); /* line 2859 */
} /* line 2859 */
  sim_icache_fetch(1974 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2861 */
} /* line 2861 */
  sim_icache_fetch(1975 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_9, (unsigned int) 16); /* line 2863 */
} /* line 2863 */
  sim_icache_fetch(1976 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_12); /* line 2865 */
   GOTO(l_L135X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L135X3;
} /* line 2866 */
l_L142X3: ;/* line 2869 */
LABEL(l_L142X3);
  sim_icache_fetch(1978 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L134X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L134X3;
} /* line 2870 */
l_L131X3: ;/* line 2873 */
LABEL(l_L131X3);
  sim_icache_fetch(1979 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 2874 */
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4200); /* line 2875 */
   MOV(reg_r0_8, reg_r0_15); /* line 2876 */
} /* line 2876 */
  sim_icache_fetch(1983 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 4200); /* line 2878 */
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 1050); /* line 2880 */
} /* line 2880 */
  sim_icache_fetch(1987 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L126X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L126X3;
} /* line 2882 */
l_L130X3: ;/* line 2885 */
LABEL(l_L130X3);
  sim_icache_fetch(1988 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ZXTB(reg_r0_8, reg_r0_11); /* line 2886 */
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2887 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 2888 */
} /* line 2888 */
  sim_icache_fetch(1991 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_7,0,1), reg_r0_3); /* line 2890 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L131X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2892 */
  sim_icache_fetch(1993 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L132X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L132X3;
} /* line 2894 */
l_L129X3: ;/* line 2897 */
LABEL(l_L129X3);
  sim_icache_fetch(1994 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4200); /* line 2898 */
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 4200); /* line 2899 */
} /* line 2899 */
  sim_icache_fetch(1998 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_3, reg_r0_14, (unsigned int) 1); /* line 2901 */
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 1050); /* line 2902 */
   MOV(reg_r0_8, reg_r0_15); /* line 2904 */
} /* line 2904 */
  sim_icache_fetch(2002 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L126X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L126X3;
} /* line 2906 */
l_L127X3: ;/* line 2909 */
LABEL(l_L127X3);
  sim_icache_fetch(2003 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_slow);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2911 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 265: goto l_L89X3;
    case 266: goto l_L91X3;
    case 267: goto l_L95X3;
    case 268: goto l_L94X3;
    case 269: goto l_L93X3;
    case 270: goto l_L92X3;
    case 271: goto l_L96X3;
    case 272: goto l_L90X3;
    case 273: goto l_L97X3;
    case 274: goto l_L99X3;
    case 275: goto l_L103X3;
    case 276: goto l_L102X3;
    case 277: goto l_L101X3;
    case 278: goto l_L100X3;
    case 279: goto l_L104X3;
    case 280: goto l_L98X3;
    case 281: goto l_L105X3;
    case 282: goto l_L107X3;
    case 283: goto l_L111X3;
    case 284: goto l_L110X3;
    case 285: goto l_L109X3;
    case 286: goto l_L108X3;
    case 287: goto l_L106X3;
    case 288: goto l_L112X3;
    case 289: goto l_L114X3;
    case 290: goto l_L118X3;
    case 291: goto l_L117X3;
    case 292: goto l_L116X3;
    case 293: goto l_L115X3;
    case 294: goto l_L113X3;
    case 295: goto l_L119X3;
    case 296: goto l_L121X3;
    case 297: goto l_L125X3;
    case 298: goto l_L124X3;
    case 299: goto l_L123X3;
    case 300: goto l_L122X3;
    case 301: goto l_L120X3;
    case 302: goto l_L126X3;
    case 303: goto l_L128X3;
    case 304: goto l_L132X3;
    case 305: goto l_L135X3;
    case 306: goto l_L138X3;
    case 307: goto l_L140X3;
    case 308: goto l_L139X3;
    case 309: goto l_L137X3;
    case 310: goto l_L136X3;
    case 311: goto l_L141X3;
    case 312: goto l_L134X3;
    case 313: goto l_L133X3;
    case 314: goto l_L142X3;
    case 315: goto l_L131X3;
    case 316: goto l_L130X3;
    case 317: goto l_L129X3;
    case 318: goto l_L127X3;
    case 319:
      reg_l0_0 = t_client_rpc;
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"deriche.s", 2016, 0, 0, 0, 2};


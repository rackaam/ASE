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
  reg_l0_0 = (223 << 5);
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
   MOV(reg_r0_24, (unsigned int) s_at); /* line 732 */
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
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -2)); /* line 739 */
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
   SH1ADD(reg_r0_8, reg_r0_12, ((unsigned int) s_ay2 + (unsigned int) -6)); /* line 749 */
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
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -23); /* line 771 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -77); /* line 772 */
} /* line 772 */
  sim_icache_fetch(481 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -24); /* line 774 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 107); /* line 775 */
} /* line 775 */
  sim_icache_fetch(483 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_4, reg_r0_4); /* line 777 */
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 778 */
} /* line 778 */
  sim_icache_fetch(485 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 7); /* line 780 */
   SXTH(reg_r0_2, reg_r0_2); /* line 781 */
} /* line 781 */
  sim_icache_fetch(487 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_10, reg_r0_10); /* line 783 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_2); /* line 784 */
} /* line 784 */
  sim_icache_fetch(489 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 786 */
   SXTH(reg_r0_6, reg_r0_6); /* line 787 */
} /* line 787 */
  sim_icache_fetch(491 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 789 */
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 2),0,1)); /* line 790 */
} /* line 790 */
  sim_icache_fetch(493 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 792 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L28X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 793 */
  sim_icache_fetch(495 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_11, reg_r0_4); /* line 795 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 796 */
} /* line 796 */
  sim_icache_fetch(497 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -23); /* line 798 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -77); /* line 799 */
} /* line 799 */
  sim_icache_fetch(499 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -24); /* line 801 */
   MULL(reg_r0_13, reg_r0_11, (unsigned int) 107); /* line 802 */
} /* line 802 */
  sim_icache_fetch(501 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_12, reg_r0_12); /* line 804 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 805 */
} /* line 805 */
  sim_icache_fetch(503 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 7); /* line 807 */
   SXTH(reg_r0_5, reg_r0_5); /* line 808 */
} /* line 808 */
  sim_icache_fetch(505 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_13, reg_r0_13); /* line 810 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_5); /* line 811 */
} /* line 811 */
  sim_icache_fetch(507 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_3, reg_r0_3); /* line 813 */
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_9 + (unsigned int) 1),0,1)); /* line 814 */
} /* line 814 */
  sim_icache_fetch(509 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_13); /* line 816 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 817 */
} /* line 817 */
  sim_icache_fetch(511 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 819 */
   MULL(reg_r0_11, reg_r0_11, (unsigned int) -77); /* line 820 */
} /* line 820 */
  sim_icache_fetch(513 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_13, reg_r0_12); /* line 822 */
   MULL(reg_r0_15, reg_r0_14, (unsigned int) -23); /* line 823 */
} /* line 823 */
  sim_icache_fetch(515 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_16, reg_r0_13, (unsigned int) 107); /* line 825 */
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 7); /* line 826 */
} /* line 826 */
  sim_icache_fetch(517 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_15, reg_r0_15); /* line 828 */
   SXTH(reg_r0_11, reg_r0_11); /* line 829 */
} /* line 829 */
  sim_icache_fetch(519 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 7); /* line 831 */
   ADD(reg_r0_15, reg_r0_15, reg_r0_11); /* line 832 */
} /* line 832 */
  sim_icache_fetch(521 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -24); /* line 834 */
   SXTH(reg_r0_16, reg_r0_16); /* line 835 */
} /* line 835 */
  sim_icache_fetch(523 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_13); /* line 837 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_9,0,1)); /* line 838 */
} /* line 838 */
  sim_icache_fetch(525 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_14); /* line 840 */
   SXTH(reg_r0_10, reg_r0_10); /* line 841 */
} /* line 841 */
  sim_icache_fetch(527 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_16); /* line 843 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -3); /* line 844 */
} /* line 844 */
  sim_icache_fetch(529 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_15, reg_r0_15, reg_r0_10); /* line 846 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -3); /* line 847 */
} /* line 847 */
  sim_icache_fetch(531 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,2), reg_r0_4); /* line 849 */
   SXTH(reg_r0_5, reg_r0_15); /* line 850 */
} /* line 850 */
  sim_icache_fetch(533 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L29X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 852 */
  sim_icache_fetch(534 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_8 + (unsigned int) 2),0,2), reg_r0_12); /* line 854 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L30X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 855 */
  sim_icache_fetch(536 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st(reg_r0_8,0,2), reg_r0_15); /* line 857 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -6); /* line 859 */
} /* line 859 */
  sim_icache_fetch(538 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L27X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L27X3;
} /* line 861 */
l_L30X3: ;/* line 864 */
LABEL(l_L30X3);
  sim_icache_fetch(539 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_20); /* line 865 */
   MOV(reg_r0_8, (unsigned int) s_ay2); /* line 867 */
} /* line 867 */
  sim_icache_fetch(542 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L31X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L31X3;
} /* line 869 */
l_L32X3: ;/* line 872 */
LABEL(l_L32X3);
  sim_icache_fetch(543 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 873 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 107); /* line 874 */
} /* line 874 */
  sim_icache_fetch(545 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 14); /* line 876 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -77); /* line 877 */
} /* line 877 */
  sim_icache_fetch(547 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 879 */
   LDHs(reg_r0_12, mem_trace_ld(reg_r0_8,0,2)); /* line 880 */
} /* line 880 */
  sim_icache_fetch(549 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -24); /* line 882 */
   SXTH(reg_r0_5, reg_r0_5); /* line 883 */
} /* line 883 */
  sim_icache_fetch(551 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_7, reg_r0_7); /* line 885 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 7); /* line 886 */
} /* line 886 */
  sim_icache_fetch(553 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_13, reg_r0_13); /* line 888 */
   SXTH(reg_r0_6, reg_r0_6); /* line 889 */
} /* line 889 */
  sim_icache_fetch(555 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 891 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_5); /* line 892 */
} /* line 892 */
  sim_icache_fetch(557 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_9, (unsigned int) 1); /* line 894 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_13); /* line 895 */
} /* line 895 */
  sim_icache_fetch(559 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_5, reg_r0_7); /* line 897 */
   CMPLT(reg_b0_1, reg_r0_9, 0); /* line 898 */
} /* line 898 */
  sim_icache_fetch(561 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_5, reg_r0_12); /* line 900 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L33X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 901 */
  sim_icache_fetch(563 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 7); /* line 903 */
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 904 */
} /* line 904 */
  sim_icache_fetch(565 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 7); /* line 906 */
   MULL(reg_r0_14, reg_r0_5, (unsigned int) 107); /* line 907 */
} /* line 907 */
  sim_icache_fetch(567 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 14); /* line 909 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -77); /* line 910 */
} /* line 910 */
  sim_icache_fetch(569 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_15, reg_r0_13, (unsigned int) -24); /* line 912 */
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 913 */
} /* line 913 */
  sim_icache_fetch(571 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_14, reg_r0_14); /* line 915 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 916 */
} /* line 916 */
  sim_icache_fetch(573 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_15, reg_r0_15); /* line 918 */
   SXTH(reg_r0_4, reg_r0_4); /* line 919 */
} /* line 919 */
  sim_icache_fetch(575 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_3, reg_r0_3); /* line 921 */
   ADD(reg_r0_15, reg_r0_15, reg_r0_14); /* line 922 */
} /* line 922 */
  sim_icache_fetch(577 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 924 */
   LDHs(reg_r0_14, mem_trace_ld((reg_r0_8 + (unsigned int) 2),0,2)); /* line 925 */
} /* line 925 */
  sim_icache_fetch(579 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_5); /* line 927 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_15); /* line 928 */
} /* line 928 */
  sim_icache_fetch(581 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_4, reg_r0_3); /* line 930 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 2); /* line 931 */
} /* line 931 */
  sim_icache_fetch(583 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_4, reg_r0_14); /* line 933 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 4); /* line 934 */
} /* line 934 */
  sim_icache_fetch(585 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 936 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 2); /* line 937 */
} /* line 937 */
  sim_icache_fetch(587 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st(reg_r0_11,0,2), reg_r0_7); /* line 939 */
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 940 */
} /* line 940 */
  sim_icache_fetch(589 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st(reg_r0_10,0,2), reg_r0_12); /* line 942 */
   MOV(reg_r0_7, reg_r0_13); /* line 943 */
} /* line 943 */
  sim_icache_fetch(591 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L33X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 945 */
  sim_icache_fetch(592 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_11 + (unsigned int) 2),0,2), reg_r0_3); /* line 947 */
   ADD(reg_r0_11, reg_r0_11, (unsigned int) 4); /* line 948 */
} /* line 948 */
  sim_icache_fetch(594 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_10 + (unsigned int) 2),0,2), reg_r0_14); /* line 950 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 952 */
} /* line 952 */
  sim_icache_fetch(596 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L32X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L32X3;
} /* line 954 */
l_L33X3: ;/* line 957 */
LABEL(l_L33X3);
  sim_icache_fetch(597 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_24, reg_r0_24, (unsigned int) 2100); /* line 958 */
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 1050); /* line 959 */
} /* line 959 */
  sim_icache_fetch(601 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_17, (unsigned int) 1); /* line 961 */
   ADD(reg_r0_10, reg_r0_18, (unsigned int) 1050); /* line 962 */
} /* line 962 */
  sim_icache_fetch(604 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_12, reg_r0_20); /* line 964 */
   MOV(reg_r0_11, reg_r0_19); /* line 966 */
} /* line 966 */
  sim_icache_fetch(606 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L25X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L25X3;
} /* line 968 */
l_L29X3: ;/* line 971 */
LABEL(l_L29X3);
  sim_icache_fetch(607 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_20); /* line 972 */
   MOV(reg_r0_8, (unsigned int) s_ay2); /* line 974 */
} /* line 974 */
  sim_icache_fetch(610 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L31X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L31X3;
} /* line 976 */
l_L28X3: ;/* line 979 */
LABEL(l_L28X3);
  sim_icache_fetch(611 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_20); /* line 980 */
   MOV(reg_r0_8, (unsigned int) s_ay2); /* line 981 */
} /* line 981 */
l_L31X3: ;/* line 983 */
LABEL(l_L31X3);
  sim_icache_fetch(614 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_3); /* line 984 */
   MOV(reg_r0_10, reg_r0_24); /* line 985 */
} /* line 985 */
  sim_icache_fetch(616 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, (unsigned int) s_ay1); /* line 987 */
   MOV(reg_r0_2, reg_r0_25); /* line 988 */
} /* line 988 */
  sim_icache_fetch(619 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_21); /* line 990 */
   MOV(reg_r0_4, reg_r0_22); /* line 991 */
} /* line 991 */
  sim_icache_fetch(621 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_23); /* line 993 */
   GOTO(l_L32X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L32X3;
} /* line 994 */
l_L26X3: ;/* line 997 */
LABEL(l_L26X3);
  sim_icache_fetch(623 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_12, 0, reg_r0_12); /* line 998 */
   MOV(reg_r0_22, (unsigned int) s_at); /* line 999 */
} /* line 999 */
  sim_icache_fetch(626 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_12); /* line 1001 */
   MOV(reg_r0_21, (unsigned int) out); /* line 1002 */
} /* line 1002 */
  sim_icache_fetch(629 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_26, (unsigned int) -1); /* line 1004 */
   MOV(reg_r0_12, ((unsigned int) s_at + (unsigned int) -4200)); /* line 1005 */
} /* line 1005 */
  sim_icache_fetch(632 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_26); /* line 1007 */
} /* line 1007 */
l_L34X3: ;/* line 1010 */
LABEL(l_L34X3);
  sim_icache_fetch(633 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 1011 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 2100); /* line 1012 */
} /* line 1012 */
  sim_icache_fetch(636 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 1014 */
   SH1ADD(reg_r0_8, reg_r0_13, ((unsigned int) s_by2 + (unsigned int) -6)); /* line 1015 */
} /* line 1015 */
  sim_icache_fetch(639 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 1017 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L35X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1018 */
  sim_icache_fetch(641 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, 0); /* line 1020 */
   MOV(reg_r0_5, 0); /* line 1021 */
} /* line 1021 */
  sim_icache_fetch(643 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_18, 0); /* line 1023 */
   MOV(reg_r0_2, 0); /* line 1024 */
} /* line 1024 */
  sim_icache_fetch(645 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_20, 0); /* line 1026 */
   MOV(reg_r0_19, 0); /* line 1027 */
} /* line 1027 */
  sim_icache_fetch(647 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_10); /* line 1029 */
   MOV(reg_r0_14, reg_r0_4); /* line 1030 */
} /* line 1030 */
  sim_icache_fetch(649 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_15, reg_r0_10); /* line 1032 */
   MOV(reg_r0_16, reg_r0_12); /* line 1033 */
} /* line 1033 */
  sim_icache_fetch(651 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_13); /* line 1035 */
} /* line 1035 */
l_L36X3: ;/* line 1038 */
LABEL(l_L36X3);
  sim_icache_fetch(652 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -77); /* line 1039 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -23); /* line 1040 */
} /* line 1040 */
  sim_icache_fetch(654 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 107); /* line 1042 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 14); /* line 1043 */
} /* line 1043 */
  sim_icache_fetch(656 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1045 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 1046 */
} /* line 1046 */
  sim_icache_fetch(658 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 1048 */
   LDHs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,2)); /* line 1049 */
} /* line 1049 */
  sim_icache_fetch(661 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 1051 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L37X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1052 */
  sim_icache_fetch(663 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 7); /* line 1054 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 1055 */
} /* line 1055 */
  sim_icache_fetch(665 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_10, reg_r0_2); /* line 1057 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -77); /* line 1058 */
} /* line 1058 */
  sim_icache_fetch(667 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) 107); /* line 1060 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) -23); /* line 1061 */
} /* line 1061 */
  sim_icache_fetch(669 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 14); /* line 1063 */
   LDHs(reg_r0_13, mem_trace_ld((reg_r0_9 + (unsigned int) 2100),0,2)); /* line 1064 */
} /* line 1064 */
  sim_icache_fetch(672 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 1066 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 1067 */
} /* line 1067 */
  sim_icache_fetch(674 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 1069 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -77); /* line 1070 */
} /* line 1070 */
  sim_icache_fetch(676 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_12); /* line 1072 */
   MULL(reg_r0_11, reg_r0_13, (unsigned int) -23); /* line 1073 */
} /* line 1073 */
  sim_icache_fetch(678 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 7); /* line 1075 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 14); /* line 1076 */
} /* line 1076 */
  sim_icache_fetch(680 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_12, reg_r0_5); /* line 1078 */
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 1079 */
} /* line 1079 */
  sim_icache_fetch(682 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_12, (unsigned int) 107); /* line 1081 */
   LDHs(reg_r0_3, mem_trace_ld(reg_r0_9,0,2)); /* line 1082 */
} /* line 1082 */
  sim_icache_fetch(684 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_13); /* line 1084 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -3); /* line 1085 */
} /* line 1085 */
  sim_icache_fetch(686 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,2), reg_r0_2); /* line 1087 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_4); /* line 1088 */
} /* line 1088 */
  sim_icache_fetch(688 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 1090 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1091 */
  sim_icache_fetch(690 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_12); /* line 1093 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 7); /* line 1094 */
} /* line 1094 */
  sim_icache_fetch(692 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_8 + (unsigned int) 2),0,2), reg_r0_5); /* line 1096 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L39X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1097 */
  sim_icache_fetch(694 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_5, reg_r0_10); /* line 1099 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -6300); /* line 1100 */
} /* line 1100 */
  sim_icache_fetch(697 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st(reg_r0_8,0,2), reg_r0_10); /* line 1102 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -6); /* line 1104 */
} /* line 1104 */
  sim_icache_fetch(699 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L36X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L36X3;
} /* line 1106 */
l_L39X3: ;/* line 1109 */
LABEL(l_L39X3);
  sim_icache_fetch(700 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_17); /* line 1110 */
   MOV(reg_r0_9, reg_r0_21); /* line 1112 */
} /* line 1112 */
  sim_icache_fetch(702 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L40X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L40X3;
} /* line 1114 */
l_L41X3: ;/* line 1117 */
LABEL(l_L41X3);
  sim_icache_fetch(703 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -77); /* line 1118 */
   LDHs(reg_r0_3, mem_trace_ld(reg_r0_2,0,2)); /* line 1119 */
} /* line 1119 */
  sim_icache_fetch(705 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_5, (unsigned int) 107); /* line 1121 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 14); /* line 1122 */
} /* line 1122 */
  sim_icache_fetch(707 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 1124 */
   LDHs(reg_r0_13, mem_trace_ld(reg_r0_7,0,2)); /* line 1125 */
} /* line 1125 */
  sim_icache_fetch(709 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_3, (unsigned int) -24); /* line 1127 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_6); /* line 1128 */
} /* line 1128 */
  sim_icache_fetch(711 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, 0); /* line 1130 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L42X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1131 */
  sim_icache_fetch(713 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 1133 */
   LDHs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 2100),0,2)); /* line 1134 */
} /* line 1134 */
  sim_icache_fetch(716 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_12); /* line 1136 */
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -77); /* line 1137 */
} /* line 1137 */
  sim_icache_fetch(718 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 7); /* line 1139 */
   MULL(reg_r0_12, reg_r0_3, (unsigned int) 14); /* line 1140 */
} /* line 1140 */
  sim_icache_fetch(720 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_15, reg_r0_4); /* line 1142 */
   MULL(reg_r0_16, reg_r0_6, (unsigned int) -24); /* line 1143 */
} /* line 1143 */
  sim_icache_fetch(722 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_15, reg_r0_13); /* line 1145 */
   MULL(reg_r0_17, reg_r0_15, (unsigned int) 107); /* line 1146 */
} /* line 1146 */
  sim_icache_fetch(724 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 7); /* line 1148 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_16); /* line 1149 */
} /* line 1149 */
  sim_icache_fetch(726 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 14); /* line 1151 */
   ADD(reg_r0_17, reg_r0_17, reg_r0_12); /* line 1152 */
} /* line 1152 */
  sim_icache_fetch(728 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_12, reg_r0_13); /* line 1154 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_17); /* line 1155 */
} /* line 1155 */
  sim_icache_fetch(730 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_1, reg_r0_12, (unsigned int) 25); /* line 1157 */
   SHR(reg_r0_14, reg_r0_14, (unsigned int) 7); /* line 1158 */
} /* line 1158 */
  sim_icache_fetch(732 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDHs(reg_r0_16, mem_trace_ld((reg_r0_7 + (unsigned int) 2),0,2)); /* line 1160 */
} /* line 1160 */
  sim_icache_fetch(733 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STH(mem_trace_st(reg_r0_10,0,2), reg_r0_4); /* line 1162 */
} /* line 1162 */
  sim_icache_fetch(734 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_13); /* line 1164 */
   MOV(reg_r0_4, reg_r0_15); /* line 1165 */
} /* line 1165 */
  sim_icache_fetch(736 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L43X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1167 */
  sim_icache_fetch(737 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), 0); /* line 1169 */
   SXTH(reg_r0_5, reg_r0_14); /* line 1170 */
} /* line 1170 */
l_L44X3: ;/* line 1172 */
LABEL(l_L44X3);
  sim_icache_fetch(739 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_16, reg_r0_5, reg_r0_16); /* line 1173 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L45X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1174 */
  sim_icache_fetch(741 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STH(mem_trace_st((reg_r0_10 + (unsigned int) 2),0,2), reg_r0_14); /* line 1176 */
   SHL(reg_r0_16, reg_r0_16, (unsigned int) 7); /* line 1177 */
} /* line 1177 */
  sim_icache_fetch(743 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 14); /* line 1179 */
} /* line 1179 */
  sim_icache_fetch(744 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_16); /* line 1181 */
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_16); /* line 1182 */
} /* line 1182 */
  sim_icache_fetch(747 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 1184 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1185 */
   ADD_CYCLES(1);
} /* line 1185 */
  sim_icache_fetch(749 + t_thisfile.offset, 1);
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
} /* line 1187 */
  sim_icache_fetch(750 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 1189 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4200); /* line 1190 */
} /* line 1190 */
  sim_icache_fetch(753 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 1192 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1193 */
} /* line 1193 */
  sim_icache_fetch(755 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), 0); /* line 1195 */
} /* line 1195 */
l_L47X3: ;/* line 1197 */
LABEL(l_L47X3);
  sim_icache_fetch(757 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_9, reg_r0_11); /* line 1198 */
   GOTO(l_L41X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L41X3;
} /* line 1199 */
l_L46X3: ;/* line 1202 */
LABEL(l_L46X3);
  sim_icache_fetch(759 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 1203 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1204 */
} /* line 1204 */
  sim_icache_fetch(761 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1206 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 4); /* line 1207 */
} /* line 1207 */
  sim_icache_fetch(763 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_3); /* line 1209 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4200); /* line 1211 */
} /* line 1211 */
  sim_icache_fetch(767 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L47X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L47X3;
} /* line 1213 */
l_L45X3: ;/* line 1216 */
LABEL(l_L45X3);
  sim_icache_fetch(768 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 2); /* line 1217 */
   MOV(reg_r0_2, reg_r0_22); /* line 1219 */
} /* line 1219 */
  sim_icache_fetch(770 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L48X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L48X3;
} /* line 1221 */
l_L43X3: ;/* line 1224 */
LABEL(l_L43X3);
  sim_icache_fetch(771 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SXTH(reg_r0_5, reg_r0_14); /* line 1225 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1226 */
} /* line 1226 */
  sim_icache_fetch(773 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_3); /* line 1228 */
   GOTO(l_L44X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L44X3;
} /* line 1229 */
l_L42X3: ;/* line 1232 */
LABEL(l_L42X3);
  sim_icache_fetch(775 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 2); /* line 1233 */
   MOV(reg_r0_2, reg_r0_22); /* line 1234 */
} /* line 1234 */
l_L48X3: ;/* line 1236 */
LABEL(l_L48X3);
  sim_icache_fetch(777 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_20, (unsigned int) 1); /* line 1237 */
   ADD(reg_r0_22, reg_r0_23, (unsigned int) 2); /* line 1238 */
} /* line 1238 */
  sim_icache_fetch(779 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, reg_r0_18); /* line 1240 */
   MOV(reg_r0_13, reg_r0_21); /* line 1241 */
} /* line 1241 */
  sim_icache_fetch(781 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_21, reg_r0_2, (unsigned int) 1); /* line 1243 */
   GOTO(l_L34X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L34X3;
} /* line 1244 */
l_L38X3: ;/* line 1247 */
LABEL(l_L38X3);
  sim_icache_fetch(783 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_17); /* line 1248 */
   MOV(reg_r0_9, reg_r0_21); /* line 1250 */
} /* line 1250 */
  sim_icache_fetch(785 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L40X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L40X3;
} /* line 1252 */
l_L37X3: ;/* line 1255 */
LABEL(l_L37X3);
  sim_icache_fetch(786 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_17); /* line 1256 */
   MOV(reg_r0_9, reg_r0_21); /* line 1257 */
} /* line 1257 */
l_L40X3: ;/* line 1259 */
LABEL(l_L40X3);
  sim_icache_fetch(788 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_3); /* line 1260 */
   MOV(reg_r0_7, (unsigned int) s_by2); /* line 1261 */
} /* line 1261 */
  sim_icache_fetch(791 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, (unsigned int) s_by1); /* line 1263 */
   MOV(reg_r0_2, reg_r0_22); /* line 1264 */
} /* line 1264 */
  sim_icache_fetch(794 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_19); /* line 1266 */
   MOV(reg_r0_5, reg_r0_18); /* line 1267 */
} /* line 1267 */
  sim_icache_fetch(796 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_20); /* line 1269 */
   MOV(reg_r0_11, (unsigned int) 2100); /* line 1270 */
} /* line 1270 */
  sim_icache_fetch(799 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_18, reg_r0_15); /* line 1272 */
   MOV(reg_r0_19, reg_r0_16); /* line 1273 */
} /* line 1273 */
  sim_icache_fetch(801 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_20, reg_r0_14); /* line 1275 */
   MOV(reg_r0_23, reg_r0_22); /* line 1276 */
} /* line 1276 */
  sim_icache_fetch(803 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, reg_r0_21); /* line 1278 */
} /* line 1278 */
  sim_icache_fetch(804 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, reg_r0_17); /* line 1280 */
   GOTO(l_L41X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L41X3;
} /* line 1281 */
l_L35X3: ;/* line 1284 */
LABEL(l_L35X3);
  sim_icache_fetch(806 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_short);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1286 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 199: goto l_L25X3;
    case 200: goto l_L27X3;
    case 201: goto l_L30X3;
    case 202: goto l_L32X3;
    case 203: goto l_L33X3;
    case 204: goto l_L29X3;
    case 205: goto l_L28X3;
    case 206: goto l_L31X3;
    case 207: goto l_L26X3;
    case 208: goto l_L34X3;
    case 209: goto l_L36X3;
    case 210: goto l_L39X3;
    case 211: goto l_L41X3;
    case 212: goto l_L44X3;
    case 213: goto l_L47X3;
    case 214: goto l_L46X3;
    case 215: goto l_L45X3;
    case 216: goto l_L43X3;
    case 217: goto l_L42X3;
    case 218: goto l_L48X3;
    case 219: goto l_L38X3;
    case 220: goto l_L37X3;
    case 221: goto l_L40X3;
    case 222: goto l_L35X3;
    case 223:
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
  reg_l0_0 = (246 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(807 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 1302 */
} /* line 1302 */
  sim_icache_fetch(808 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_24, (unsigned int) at); /* line 1304 */
   MOV(reg_r0_25, (unsigned int) in); /* line 1305 */
} /* line 1305 */
  sim_icache_fetch(812 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_4 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_2); /* line 1307 */
   MOV(reg_r0_12, t__i32_0); /* line 1308 */
} /* line 1308 */
  sim_icache_fetch(814 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_12, (unsigned int) -1); /* line 1310 */
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 1311 */
} /* line 1311 */
  sim_icache_fetch(817 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_26, reg_r0_3); /* line 1313 */
} /* line 1313 */
l_L49X3: ;/* line 1316 */
LABEL(l_L49X3);
  sim_icache_fetch(818 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 1317 */
   ADD(reg_r0_9, reg_r0_10, reg_r0_11); /* line 1318 */
} /* line 1318 */
  sim_icache_fetch(820 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 1320 */
   SH2ADD(reg_r0_8, reg_r0_12, ((unsigned int) ay2 + (unsigned int) -16)); /* line 1321 */
} /* line 1321 */
  sim_icache_fetch(823 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 1323 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L50X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1324 */
  sim_icache_fetch(825 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 1326 */
   MOV(reg_r0_6, 0); /* line 1327 */
} /* line 1327 */
  sim_icache_fetch(827 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_22, 0); /* line 1329 */
   MOV(reg_r0_21, 0); /* line 1330 */
} /* line 1330 */
  sim_icache_fetch(829 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_23, 0); /* line 1332 */
   MOV(reg_r0_7, reg_r0_11); /* line 1333 */
} /* line 1333 */
  sim_icache_fetch(831 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_4); /* line 1335 */
   MOV(reg_r0_18, reg_r0_10); /* line 1336 */
} /* line 1336 */
  sim_icache_fetch(833 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, reg_r0_11); /* line 1338 */
   MOV(reg_r0_20, reg_r0_12); /* line 1339 */
} /* line 1339 */
l_L51X3: ;/* line 1342 */
LABEL(l_L51X3);
  sim_icache_fetch(835 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 1343 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 1344 */
} /* line 1344 */
  sim_icache_fetch(837 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -48); /* line 1346 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 1347 */
} /* line 1347 */
  sim_icache_fetch(839 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1349 */
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1350 */
} /* line 1350 */
  sim_icache_fetch(841 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1352 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_2); /* line 1353 */
} /* line 1353 */
  sim_icache_fetch(843 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 1355 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1356 */
  sim_icache_fetch(845 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 1358 */
   LDBU(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 3),0,1)); /* line 1359 */
} /* line 1359 */
  sim_icache_fetch(847 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 1361 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1362 */
} /* line 1362 */
  sim_icache_fetch(849 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 1364 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) 215); /* line 1365 */
} /* line 1365 */
  sim_icache_fetch(851 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 1367 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1368 */
} /* line 1368 */
  sim_icache_fetch(853 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1370 */
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_9 + (unsigned int) 2),0,1)); /* line 1371 */
} /* line 1371 */
  sim_icache_fetch(855 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_5); /* line 1373 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 1374 */
} /* line 1374 */
  sim_icache_fetch(857 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 1376 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 1377 */
} /* line 1377 */
  sim_icache_fetch(859 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_13, (unsigned int) -47); /* line 1379 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) -155); /* line 1380 */
} /* line 1380 */
  sim_icache_fetch(861 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 1382 */
   MULL(reg_r0_15, reg_r0_12, (unsigned int) 215); /* line 1383 */
} /* line 1383 */
  sim_icache_fetch(863 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1385 */
   LDBUs(reg_r0_16, mem_trace_ld((reg_r0_9 + (unsigned int) 1),0,1)); /* line 1386 */
} /* line 1386 */
  sim_icache_fetch(865 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1388 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_11); /* line 1389 */
} /* line 1389 */
  sim_icache_fetch(867 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_15); /* line 1391 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 1392 */
} /* line 1392 */
  sim_icache_fetch(869 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 1394 */
   MULL(reg_r0_10, reg_r0_12, (unsigned int) -155); /* line 1395 */
} /* line 1395 */
  sim_icache_fetch(871 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_16, (unsigned int) -47); /* line 1397 */
   MULL(reg_r0_15, reg_r0_14, (unsigned int) 215); /* line 1398 */
} /* line 1398 */
  sim_icache_fetch(873 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_13, (unsigned int) -48); /* line 1400 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1401 */
} /* line 1401 */
  sim_icache_fetch(875 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1403 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 1404 */
} /* line 1404 */
  sim_icache_fetch(877 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 1406 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_9,0,1)); /* line 1407 */
} /* line 1407 */
  sim_icache_fetch(879 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_14); /* line 1409 */
   ADD(reg_r0_5, reg_r0_11, reg_r0_13); /* line 1410 */
} /* line 1410 */
  sim_icache_fetch(881 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_16); /* line 1412 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 1413 */
} /* line 1413 */
  sim_icache_fetch(883 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 1415 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -4); /* line 1416 */
} /* line 1416 */
  sim_icache_fetch(885 + t_thisfile.offset, 1);
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
} /* line 1418 */
  sim_icache_fetch(886 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_12); /* line 1420 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1421 */
  sim_icache_fetch(888 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_14); /* line 1423 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L52X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1424 */
  sim_icache_fetch(890 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_5); /* line 1426 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 1428 */
} /* line 1428 */
  sim_icache_fetch(892 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L51X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L51X3;
} /* line 1430 */
l_L52X3: ;/* line 1433 */
LABEL(l_L52X3);
  sim_icache_fetch(893 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_20); /* line 1434 */
   MOV(reg_r0_10, reg_r0_24); /* line 1435 */
} /* line 1435 */
  sim_icache_fetch(895 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_3); /* line 1437 */
   MOV(reg_r0_8, (unsigned int) ay2); /* line 1438 */
} /* line 1438 */
  sim_icache_fetch(898 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, (unsigned int) ay1); /* line 1440 */
   MOV(reg_r0_2, reg_r0_25); /* line 1441 */
} /* line 1441 */
  sim_icache_fetch(901 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_21); /* line 1443 */
   MOV(reg_r0_4, reg_r0_22); /* line 1444 */
} /* line 1444 */
  sim_icache_fetch(903 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_23); /* line 1446 */
   MOV(reg_r0_21, reg_r0_20); /* line 1447 */
} /* line 1447 */
  sim_icache_fetch(905 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_17); /* line 1449 */
} /* line 1449 */
l_L53X3: ;/* line 1452 */
LABEL(l_L53X3);
  sim_icache_fetch(906 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 1453 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 215); /* line 1454 */
} /* line 1454 */
  sim_icache_fetch(908 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 1456 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -155); /* line 1457 */
} /* line 1457 */
  sim_icache_fetch(910 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1459 */
   LDWs(reg_r0_12, mem_trace_ld(reg_r0_8,0,4)); /* line 1460 */
} /* line 1460 */
  sim_icache_fetch(912 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -48); /* line 1462 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 8); /* line 1463 */
} /* line 1463 */
  sim_icache_fetch(914 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_9, (unsigned int) 2); /* line 1465 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 1466 */
} /* line 1466 */
  sim_icache_fetch(916 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_5); /* line 1468 */
   CMPLT(reg_b0_1, reg_r0_9, (unsigned int) 1); /* line 1469 */
} /* line 1469 */
  sim_icache_fetch(918 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_13); /* line 1471 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L54X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1472 */
  sim_icache_fetch(920 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_7, reg_r0_12); /* line 1474 */
   LDBUs(reg_r0_5, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 1475 */
} /* line 1475 */
  sim_icache_fetch(922 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1477 */
   MULL(reg_r0_13, reg_r0_7, (unsigned int) 215); /* line 1478 */
} /* line 1478 */
  sim_icache_fetch(924 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1480 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1481 */
} /* line 1481 */
  sim_icache_fetch(926 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -48); /* line 1483 */
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1484 */
} /* line 1484 */
  sim_icache_fetch(928 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 1486 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1487 */
} /* line 1487 */
  sim_icache_fetch(930 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_13); /* line 1489 */
   LDWs(reg_r0_13, mem_trace_ld((reg_r0_8 + (unsigned int) 4),0,4)); /* line 1490 */
} /* line 1490 */
  sim_icache_fetch(932 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 1492 */
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 1493 */
} /* line 1493 */
  sim_icache_fetch(934 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_14); /* line 1495 */
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 1496 */
} /* line 1496 */
  sim_icache_fetch(936 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_3, reg_r0_13); /* line 1498 */
   MULL(reg_r0_15, reg_r0_3, (unsigned int) 215); /* line 1499 */
} /* line 1499 */
  sim_icache_fetch(938 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1501 */
   MULL(reg_r0_16, reg_r0_7, (unsigned int) -155); /* line 1502 */
} /* line 1502 */
  sim_icache_fetch(940 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1504 */
   MULL(reg_r0_17, reg_r0_14, (unsigned int) -48); /* line 1505 */
} /* line 1505 */
  sim_icache_fetch(942 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1507 */
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 1508 */
} /* line 1508 */
  sim_icache_fetch(944 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 28); /* line 1510 */
   ADD(reg_r0_17, reg_r0_17, reg_r0_15); /* line 1511 */
} /* line 1511 */
  sim_icache_fetch(946 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_3); /* line 1513 */
   LDWs(reg_r0_15, mem_trace_ld((reg_r0_8 + (unsigned int) 8),0,4)); /* line 1514 */
} /* line 1514 */
  sim_icache_fetch(948 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_16); /* line 1516 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 3); /* line 1517 */
} /* line 1517 */
  sim_icache_fetch(950 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_5, reg_r0_17); /* line 1519 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 12); /* line 1520 */
} /* line 1520 */
  sim_icache_fetch(952 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_15, reg_r0_4, reg_r0_15); /* line 1522 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 3); /* line 1523 */
} /* line 1523 */
  sim_icache_fetch(954 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_11,0,4), reg_r0_7); /* line 1525 */
   SHL(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1526 */
} /* line 1526 */
  sim_icache_fetch(956 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1528 */
   MOV(reg_r0_7, reg_r0_14); /* line 1529 */
} /* line 1529 */
  sim_icache_fetch(958 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_12); /* line 1531 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L54X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1532 */
  sim_icache_fetch(960 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 4),0,4), reg_r0_3); /* line 1534 */
} /* line 1534 */
  sim_icache_fetch(961 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4),0,4), reg_r0_13); /* line 1536 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L54X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1537 */
  sim_icache_fetch(963 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 8),0,4), reg_r0_4); /* line 1539 */
   ADD(reg_r0_11, reg_r0_11, (unsigned int) 12); /* line 1540 */
} /* line 1540 */
  sim_icache_fetch(965 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 8),0,4), reg_r0_15); /* line 1542 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 12); /* line 1544 */
} /* line 1544 */
  sim_icache_fetch(967 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L53X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L53X3;
} /* line 1546 */
l_L54X3: ;/* line 1549 */
LABEL(l_L54X3);
  sim_icache_fetch(968 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_24, reg_r0_24, (unsigned int) 4200); /* line 1550 */
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 1050); /* line 1551 */
} /* line 1551 */
  sim_icache_fetch(972 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_20, (unsigned int) 1); /* line 1553 */
   ADD(reg_r0_10, reg_r0_18, (unsigned int) 1050); /* line 1554 */
} /* line 1554 */
  sim_icache_fetch(975 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_12, reg_r0_21); /* line 1556 */
   MOV(reg_r0_11, reg_r0_19); /* line 1558 */
} /* line 1558 */
  sim_icache_fetch(977 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L49X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L49X3;
} /* line 1560 */
l_L50X3: ;/* line 1563 */
LABEL(l_L50X3);
  sim_icache_fetch(978 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_12, 0, reg_r0_12); /* line 1564 */
   MOV(reg_r0_23, (unsigned int) at); /* line 1565 */
} /* line 1565 */
  sim_icache_fetch(981 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_12); /* line 1567 */
   MOV(reg_r0_22, (unsigned int) out); /* line 1568 */
} /* line 1568 */
  sim_icache_fetch(984 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_26, (unsigned int) -1); /* line 1570 */
   MOV(reg_r0_12, ((unsigned int) at + (unsigned int) -12600)); /* line 1571 */
} /* line 1571 */
  sim_icache_fetch(987 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_26); /* line 1573 */
} /* line 1573 */
l_L55X3: ;/* line 1576 */
LABEL(l_L55X3);
  sim_icache_fetch(988 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 1577 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 4200); /* line 1578 */
} /* line 1578 */
  sim_icache_fetch(991 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 1580 */
   SH2ADD(reg_r0_8, reg_r0_13, ((unsigned int) by2 + (unsigned int) -16)); /* line 1581 */
} /* line 1581 */
  sim_icache_fetch(994 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 1583 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L56X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1584 */
  sim_icache_fetch(996 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, 0); /* line 1586 */
   MOV(reg_r0_5, 0); /* line 1587 */
} /* line 1587 */
  sim_icache_fetch(998 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, 0); /* line 1589 */
   MOV(reg_r0_2, 0); /* line 1590 */
} /* line 1590 */
  sim_icache_fetch(1000 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, 0); /* line 1592 */
   MOV(reg_r0_20, 0); /* line 1593 */
} /* line 1593 */
  sim_icache_fetch(1002 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_10); /* line 1595 */
   MOV(reg_r0_15, reg_r0_4); /* line 1596 */
} /* line 1596 */
  sim_icache_fetch(1004 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_16, reg_r0_10); /* line 1598 */
   MOV(reg_r0_17, reg_r0_12); /* line 1599 */
} /* line 1599 */
  sim_icache_fetch(1006 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_13); /* line 1601 */
} /* line 1601 */
l_L57X3: ;/* line 1604 */
LABEL(l_L57X3);
  sim_icache_fetch(1007 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 1605 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 1606 */
} /* line 1606 */
  sim_icache_fetch(1009 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 1608 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 29); /* line 1609 */
} /* line 1609 */
  sim_icache_fetch(1011 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1611 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 1612 */
} /* line 1612 */
  sim_icache_fetch(1013 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 1614 */
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 12600),0,4)); /* line 1615 */
} /* line 1615 */
  sim_icache_fetch(1016 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 1617 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L58X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1618 */
  sim_icache_fetch(1018 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1620 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 1621 */
} /* line 1621 */
  sim_icache_fetch(1020 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1623 */
   MULL(reg_r0_10, reg_r0_4, (unsigned int) -47); /* line 1624 */
} /* line 1624 */
  sim_icache_fetch(1022 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 1626 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 1627 */
} /* line 1627 */
  sim_icache_fetch(1024 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 1629 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 8400),0,4)); /* line 1630 */
} /* line 1630 */
  sim_icache_fetch(1027 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 1632 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 1633 */
} /* line 1633 */
  sim_icache_fetch(1029 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 1635 */
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 1636 */
} /* line 1636 */
  sim_icache_fetch(1031 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1638 */
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 1639 */
} /* line 1639 */
  sim_icache_fetch(1033 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_5, (unsigned int) 215); /* line 1641 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 29); /* line 1642 */
} /* line 1642 */
  sim_icache_fetch(1035 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 1644 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,4)); /* line 1645 */
} /* line 1645 */
  sim_icache_fetch(1038 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_4); /* line 1647 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 1648 */
} /* line 1648 */
  sim_icache_fetch(1040 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 1650 */
   MULL(reg_r0_4, reg_r0_5, (unsigned int) -155); /* line 1651 */
} /* line 1651 */
  sim_icache_fetch(1042 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1653 */
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 1654 */
} /* line 1654 */
  sim_icache_fetch(1044 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 1656 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 1657 */
} /* line 1657 */
  sim_icache_fetch(1046 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 1659 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_9,0,4)); /* line 1660 */
} /* line 1660 */
  sim_icache_fetch(1048 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_12); /* line 1662 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 1663 */
} /* line 1663 */
  sim_icache_fetch(1050 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 1665 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 1666 */
} /* line 1666 */
  sim_icache_fetch(1052 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_2); /* line 1668 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1669 */
} /* line 1669 */
  sim_icache_fetch(1054 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_11); /* line 1671 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L59X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1672 */
  sim_icache_fetch(1056 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_5); /* line 1674 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -16800); /* line 1675 */
} /* line 1675 */
  sim_icache_fetch(1059 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_4); /* line 1677 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L60X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1678 */
  sim_icache_fetch(1061 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_11); /* line 1680 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L61X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1681 */
  sim_icache_fetch(1063 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 1683 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 1685 */
} /* line 1685 */
  sim_icache_fetch(1065 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L57X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L57X3;
} /* line 1687 */
l_L61X3: ;/* line 1690 */
LABEL(l_L61X3);
  sim_icache_fetch(1066 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 1691 */
   MOV(reg_r0_9, reg_r0_22); /* line 1693 */
} /* line 1693 */
  sim_icache_fetch(1068 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L62X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L62X3;
} /* line 1695 */
l_L63X3: ;/* line 1698 */
LABEL(l_L63X3);
  sim_icache_fetch(1069 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1699 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 1700 */
} /* line 1700 */
  sim_icache_fetch(1071 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_5, (unsigned int) 215); /* line 1702 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 1703 */
} /* line 1703 */
  sim_icache_fetch(1073 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 1705 */
   LDWs(reg_r0_12, mem_trace_ld(reg_r0_7,0,4)); /* line 1706 */
} /* line 1706 */
  sim_icache_fetch(1075 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -48); /* line 1708 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_6); /* line 1709 */
} /* line 1709 */
  sim_icache_fetch(1077 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, 0); /* line 1711 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L64X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1712 */
  sim_icache_fetch(1079 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 1714 */
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 1715 */
} /* line 1715 */
  sim_icache_fetch(1082 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_11); /* line 1717 */
   MULL(reg_r0_13, reg_r0_5, (unsigned int) -155); /* line 1718 */
} /* line 1718 */
  sim_icache_fetch(1084 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1720 */
   MULL(reg_r0_11, reg_r0_3, (unsigned int) 28); /* line 1721 */
} /* line 1721 */
  sim_icache_fetch(1086 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_4, reg_r0_12); /* line 1723 */
   MULL(reg_r0_14, reg_r0_6, (unsigned int) -48); /* line 1724 */
} /* line 1724 */
  sim_icache_fetch(1088 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1726 */
   MULL(reg_r0_15, reg_r0_4, (unsigned int) 215); /* line 1727 */
} /* line 1727 */
  sim_icache_fetch(1090 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 1729 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_14); /* line 1730 */
} /* line 1730 */
  sim_icache_fetch(1092 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_14, reg_r0_12); /* line 1732 */
   ADD(reg_r0_15, reg_r0_15, reg_r0_11); /* line 1733 */
} /* line 1733 */
  sim_icache_fetch(1094 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_1, reg_r0_14, (unsigned int) 25); /* line 1735 */
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 1736 */
} /* line 1736 */
  sim_icache_fetch(1096 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_15, reg_r0_4); /* line 1738 */
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_7 + (unsigned int) 4),0,4)); /* line 1739 */
} /* line 1739 */
  sim_icache_fetch(1098 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_12); /* line 1741 */
} /* line 1741 */
  sim_icache_fetch(1099 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_4); /* line 1743 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L65X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1744 */
  sim_icache_fetch(1101 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_13, (unsigned int) 8); /* line 1746 */
   MOV(reg_r0_4, reg_r0_15); /* line 1747 */
} /* line 1747 */
  sim_icache_fetch(1103 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), 0); /* line 1749 */
   ADD(reg_r0_11, reg_r0_5, reg_r0_11); /* line 1750 */
} /* line 1750 */
l_L66X3: ;/* line 1752 */
LABEL(l_L66X3);
  sim_icache_fetch(1105 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1753 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L67X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1754 */
  sim_icache_fetch(1107 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4),0,4), reg_r0_5); /* line 1756 */
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 1757 */
} /* line 1757 */
  sim_icache_fetch(1109 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_11); /* line 1759 */
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_11); /* line 1760 */
} /* line 1760 */
  sim_icache_fetch(1112 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 1762 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1763 */
   ADD_CYCLES(1);
} /* line 1763 */
  sim_icache_fetch(1114 + t_thisfile.offset, 1);
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
} /* line 1765 */
  sim_icache_fetch(1115 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1767 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 8400); /* line 1768 */
} /* line 1768 */
  sim_icache_fetch(1118 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 1770 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 1771 */
} /* line 1771 */
  sim_icache_fetch(1120 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), 0); /* line 1773 */
} /* line 1773 */
l_L69X3: ;/* line 1775 */
LABEL(l_L69X3);
  sim_icache_fetch(1122 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 2100); /* line 1776 */
   GOTO(l_L63X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L63X3;
} /* line 1777 */
l_L68X3: ;/* line 1780 */
LABEL(l_L68X3);
  sim_icache_fetch(1125 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 1781 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1782 */
} /* line 1782 */
  sim_icache_fetch(1127 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 1784 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1785 */
} /* line 1785 */
  sim_icache_fetch(1129 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_3); /* line 1787 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 8400); /* line 1789 */
} /* line 1789 */
  sim_icache_fetch(1133 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L69X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L69X3;
} /* line 1791 */
l_L67X3: ;/* line 1794 */
LABEL(l_L67X3);
  sim_icache_fetch(1134 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_22, reg_r0_22, (unsigned int) 1); /* line 1795 */
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 4); /* line 1797 */
} /* line 1797 */
  sim_icache_fetch(1136 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L70X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L70X3;
} /* line 1799 */
l_L65X3: ;/* line 1802 */
LABEL(l_L65X3);
  sim_icache_fetch(1137 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_13, (unsigned int) 8); /* line 1803 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 1804 */
} /* line 1804 */
  sim_icache_fetch(1139 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_5, reg_r0_11); /* line 1806 */
   MOV(reg_r0_4, reg_r0_15); /* line 1807 */
} /* line 1807 */
  sim_icache_fetch(1141 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_3); /* line 1809 */
   GOTO(l_L66X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L66X3;
} /* line 1810 */
l_L64X3: ;/* line 1813 */
LABEL(l_L64X3);
  sim_icache_fetch(1143 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_22, reg_r0_22, (unsigned int) 1); /* line 1814 */
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 4); /* line 1815 */
} /* line 1815 */
l_L70X3: ;/* line 1817 */
LABEL(l_L70X3);
  sim_icache_fetch(1145 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_18, (unsigned int) 1); /* line 1818 */
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 1819 */
} /* line 1819 */
  sim_icache_fetch(1147 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, reg_r0_16); /* line 1821 */
   MOV(reg_r0_13, reg_r0_19); /* line 1823 */
} /* line 1823 */
  sim_icache_fetch(1149 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L55X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L55X3;
} /* line 1825 */
l_L60X3: ;/* line 1828 */
LABEL(l_L60X3);
  sim_icache_fetch(1150 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 1829 */
   MOV(reg_r0_9, reg_r0_22); /* line 1831 */
} /* line 1831 */
  sim_icache_fetch(1152 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L62X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L62X3;
} /* line 1833 */
l_L59X3: ;/* line 1836 */
LABEL(l_L59X3);
  sim_icache_fetch(1153 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 1837 */
   MOV(reg_r0_9, reg_r0_22); /* line 1839 */
} /* line 1839 */
  sim_icache_fetch(1155 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L62X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L62X3;
} /* line 1841 */
l_L58X3: ;/* line 1844 */
LABEL(l_L58X3);
  sim_icache_fetch(1156 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_18); /* line 1845 */
   MOV(reg_r0_9, reg_r0_22); /* line 1846 */
} /* line 1846 */
l_L62X3: ;/* line 1848 */
LABEL(l_L62X3);
  sim_icache_fetch(1158 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_3); /* line 1849 */
   MOV(reg_r0_7, (unsigned int) by2); /* line 1850 */
} /* line 1850 */
  sim_icache_fetch(1161 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, (unsigned int) by1); /* line 1852 */
   MOV(reg_r0_2, reg_r0_23); /* line 1853 */
} /* line 1853 */
  sim_icache_fetch(1164 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_20); /* line 1855 */
   MOV(reg_r0_5, reg_r0_19); /* line 1856 */
} /* line 1856 */
  sim_icache_fetch(1166 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_21); /* line 1858 */
   MOV(reg_r0_19, reg_r0_18); /* line 1859 */
} /* line 1859 */
  sim_icache_fetch(1168 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_18, reg_r0_15); /* line 1861 */
   GOTO(l_L63X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L63X3;
} /* line 1862 */
l_L56X3: ;/* line 1865 */
LABEL(l_L56X3);
  sim_icache_fetch(1170 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_array);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1867 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 224: goto l_L49X3;
    case 225: goto l_L51X3;
    case 226: goto l_L52X3;
    case 227: goto l_L53X3;
    case 228: goto l_L54X3;
    case 229: goto l_L50X3;
    case 230: goto l_L55X3;
    case 231: goto l_L57X3;
    case 232: goto l_L61X3;
    case 233: goto l_L63X3;
    case 234: goto l_L66X3;
    case 235: goto l_L69X3;
    case 236: goto l_L68X3;
    case 237: goto l_L67X3;
    case 238: goto l_L65X3;
    case 239: goto l_L64X3;
    case 240: goto l_L70X3;
    case 241: goto l_L60X3;
    case 242: goto l_L59X3;
    case 243: goto l_L58X3;
    case 244: goto l_L62X3;
    case 245: goto l_L56X3;
    case 246:
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
  reg_l0_0 = (269 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1171 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 1883 */
} /* line 1883 */
  sim_icache_fetch(1172 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_27, (unsigned int) qy1); /* line 1885 */
   MOV(reg_r0_28, (unsigned int) in); /* line 1886 */
} /* line 1886 */
  sim_icache_fetch(1176 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_4 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_2); /* line 1888 */
   MOV(reg_r0_24, t__i32_0); /* line 1889 */
} /* line 1889 */
  sim_icache_fetch(1178 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_25, (unsigned int) qt); /* line 1891 */
   MOV(reg_r0_26, (unsigned int) qy2); /* line 1892 */
} /* line 1892 */
  sim_icache_fetch(1182 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_24, (unsigned int) -1); /* line 1894 */
   MOV(reg_r0_12, ((unsigned int) qy2 + (unsigned int) -12)); /* line 1895 */
} /* line 1895 */
  sim_icache_fetch(1185 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 1897 */
   MOV(reg_r0_29, reg_r0_3); /* line 1898 */
} /* line 1898 */
l_L71X3: ;/* line 1901 */
LABEL(l_L71X3);
  sim_icache_fetch(1188 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 1902 */
   ADD(reg_r0_9, reg_r0_10, reg_r0_11); /* line 1903 */
} /* line 1903 */
  sim_icache_fetch(1190 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 1905 */
   SH2ADD(reg_r0_8, reg_r0_11, reg_r0_12); /* line 1906 */
} /* line 1906 */
  sim_icache_fetch(1192 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 1908 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L72X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1909 */
  sim_icache_fetch(1194 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 1911 */
   MOV(reg_r0_6, 0); /* line 1912 */
} /* line 1912 */
  sim_icache_fetch(1196 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_22, 0); /* line 1914 */
   MOV(reg_r0_21, 0); /* line 1915 */
} /* line 1915 */
  sim_icache_fetch(1198 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_23, 0); /* line 1917 */
   MOV(reg_r0_7, reg_r0_11); /* line 1918 */
} /* line 1918 */
  sim_icache_fetch(1200 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_4); /* line 1920 */
   MOV(reg_r0_18, reg_r0_10); /* line 1921 */
} /* line 1921 */
  sim_icache_fetch(1202 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, reg_r0_11); /* line 1923 */
   MOV(reg_r0_20, reg_r0_12); /* line 1924 */
} /* line 1924 */
l_L73X3: ;/* line 1927 */
LABEL(l_L73X3);
  sim_icache_fetch(1204 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 1928 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 1929 */
} /* line 1929 */
  sim_icache_fetch(1206 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -48); /* line 1931 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 1932 */
} /* line 1932 */
  sim_icache_fetch(1208 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 1934 */
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1935 */
} /* line 1935 */
  sim_icache_fetch(1210 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1937 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_2); /* line 1938 */
} /* line 1938 */
  sim_icache_fetch(1212 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 1940 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1941 */
  sim_icache_fetch(1214 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 1943 */
   LDBU(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 3),0,1)); /* line 1944 */
} /* line 1944 */
  sim_icache_fetch(1216 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 1946 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1947 */
} /* line 1947 */
  sim_icache_fetch(1218 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 1949 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) 215); /* line 1950 */
} /* line 1950 */
  sim_icache_fetch(1220 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 1952 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1953 */
} /* line 1953 */
  sim_icache_fetch(1222 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1955 */
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_9 + (unsigned int) 2),0,1)); /* line 1956 */
} /* line 1956 */
  sim_icache_fetch(1224 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_5); /* line 1958 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 1959 */
} /* line 1959 */
  sim_icache_fetch(1226 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 1961 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 1962 */
} /* line 1962 */
  sim_icache_fetch(1228 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_13, (unsigned int) -47); /* line 1964 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) -155); /* line 1965 */
} /* line 1965 */
  sim_icache_fetch(1230 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 1967 */
   MULL(reg_r0_15, reg_r0_12, (unsigned int) 215); /* line 1968 */
} /* line 1968 */
  sim_icache_fetch(1232 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1970 */
   LDBUs(reg_r0_16, mem_trace_ld((reg_r0_9 + (unsigned int) 1),0,1)); /* line 1971 */
} /* line 1971 */
  sim_icache_fetch(1234 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1973 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_11); /* line 1974 */
} /* line 1974 */
  sim_icache_fetch(1236 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_15); /* line 1976 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 1977 */
} /* line 1977 */
  sim_icache_fetch(1238 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 1979 */
   MULL(reg_r0_10, reg_r0_12, (unsigned int) -155); /* line 1980 */
} /* line 1980 */
  sim_icache_fetch(1240 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_16, (unsigned int) -47); /* line 1982 */
   MULL(reg_r0_15, reg_r0_14, (unsigned int) 215); /* line 1983 */
} /* line 1983 */
  sim_icache_fetch(1242 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_13, (unsigned int) -48); /* line 1985 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1986 */
} /* line 1986 */
  sim_icache_fetch(1244 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 1988 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 1989 */
} /* line 1989 */
  sim_icache_fetch(1246 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 1991 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_9,0,1)); /* line 1992 */
} /* line 1992 */
  sim_icache_fetch(1248 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_14); /* line 1994 */
   ADD(reg_r0_5, reg_r0_11, reg_r0_13); /* line 1995 */
} /* line 1995 */
  sim_icache_fetch(1250 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_16); /* line 1997 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 1998 */
} /* line 1998 */
  sim_icache_fetch(1252 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 2000 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -4); /* line 2001 */
} /* line 2001 */
  sim_icache_fetch(1254 + t_thisfile.offset, 1);
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
} /* line 2003 */
  sim_icache_fetch(1255 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_12); /* line 2005 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2006 */
  sim_icache_fetch(1257 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_14); /* line 2008 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2009 */
  sim_icache_fetch(1259 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_5); /* line 2011 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 2013 */
} /* line 2013 */
  sim_icache_fetch(1261 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L73X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L73X3;
} /* line 2015 */
l_L74X3: ;/* line 2018 */
LABEL(l_L74X3);
  sim_icache_fetch(1262 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 2, reg_r0_24); /* line 2019 */
   MOV(reg_r0_10, reg_r0_25); /* line 2020 */
} /* line 2020 */
  sim_icache_fetch(1264 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_3); /* line 2022 */
   MOV(reg_r0_8, reg_r0_26); /* line 2023 */
} /* line 2023 */
  sim_icache_fetch(1266 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, reg_r0_27); /* line 2025 */
   MOV(reg_r0_2, reg_r0_28); /* line 2026 */
} /* line 2026 */
  sim_icache_fetch(1268 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_21); /* line 2028 */
   MOV(reg_r0_4, reg_r0_22); /* line 2029 */
} /* line 2029 */
  sim_icache_fetch(1270 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, reg_r0_17); /* line 2031 */
   MOV(reg_r0_6, reg_r0_23); /* line 2032 */
} /* line 2032 */
l_L75X3: ;/* line 2035 */
LABEL(l_L75X3);
  sim_icache_fetch(1272 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 2036 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 215); /* line 2037 */
} /* line 2037 */
  sim_icache_fetch(1274 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 2039 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -155); /* line 2040 */
} /* line 2040 */
  sim_icache_fetch(1276 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2042 */
   LDWs(reg_r0_12, mem_trace_ld(reg_r0_8,0,4)); /* line 2043 */
} /* line 2043 */
  sim_icache_fetch(1278 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -48); /* line 2045 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 8); /* line 2046 */
} /* line 2046 */
  sim_icache_fetch(1280 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_9, (unsigned int) 2); /* line 2048 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 2049 */
} /* line 2049 */
  sim_icache_fetch(1282 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_5); /* line 2051 */
   CMPLT(reg_b0_1, reg_r0_9, (unsigned int) 1); /* line 2052 */
} /* line 2052 */
  sim_icache_fetch(1284 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_13); /* line 2054 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2055 */
  sim_icache_fetch(1286 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_7, reg_r0_12); /* line 2057 */
   LDBUs(reg_r0_5, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 2058 */
} /* line 2058 */
  sim_icache_fetch(1288 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2060 */
   MULL(reg_r0_13, reg_r0_7, (unsigned int) 215); /* line 2061 */
} /* line 2061 */
  sim_icache_fetch(1290 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2063 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2064 */
} /* line 2064 */
  sim_icache_fetch(1292 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -48); /* line 2066 */
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2067 */
} /* line 2067 */
  sim_icache_fetch(1294 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2069 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2070 */
} /* line 2070 */
  sim_icache_fetch(1296 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_13); /* line 2072 */
   LDWs(reg_r0_13, mem_trace_ld((reg_r0_8 + (unsigned int) 4),0,4)); /* line 2073 */
} /* line 2073 */
  sim_icache_fetch(1298 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 2075 */
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 2076 */
} /* line 2076 */
  sim_icache_fetch(1300 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_14); /* line 2078 */
   LDBUs(reg_r0_14, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 2079 */
} /* line 2079 */
  sim_icache_fetch(1302 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_3, reg_r0_13); /* line 2081 */
   MULL(reg_r0_15, reg_r0_3, (unsigned int) 215); /* line 2082 */
} /* line 2082 */
  sim_icache_fetch(1304 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2084 */
   MULL(reg_r0_16, reg_r0_7, (unsigned int) -155); /* line 2085 */
} /* line 2085 */
  sim_icache_fetch(1306 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2087 */
   MULL(reg_r0_17, reg_r0_14, (unsigned int) -48); /* line 2088 */
} /* line 2088 */
  sim_icache_fetch(1308 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2090 */
   SHR(reg_r0_16, reg_r0_16, (unsigned int) 8); /* line 2091 */
} /* line 2091 */
  sim_icache_fetch(1310 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 28); /* line 2093 */
   ADD(reg_r0_17, reg_r0_17, reg_r0_15); /* line 2094 */
} /* line 2094 */
  sim_icache_fetch(1312 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_3); /* line 2096 */
   LDWs(reg_r0_15, mem_trace_ld((reg_r0_8 + (unsigned int) 8),0,4)); /* line 2097 */
} /* line 2097 */
  sim_icache_fetch(1314 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_16); /* line 2099 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 3); /* line 2100 */
} /* line 2100 */
  sim_icache_fetch(1316 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_5, reg_r0_17); /* line 2102 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 12); /* line 2103 */
} /* line 2103 */
  sim_icache_fetch(1318 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_15, reg_r0_4, reg_r0_15); /* line 2105 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 3); /* line 2106 */
} /* line 2106 */
  sim_icache_fetch(1320 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_11,0,4), reg_r0_7); /* line 2108 */
   SHL(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2109 */
} /* line 2109 */
  sim_icache_fetch(1322 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2111 */
   MOV(reg_r0_7, reg_r0_14); /* line 2112 */
} /* line 2112 */
  sim_icache_fetch(1324 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_12); /* line 2114 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2115 */
  sim_icache_fetch(1326 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 4),0,4), reg_r0_3); /* line 2117 */
} /* line 2117 */
  sim_icache_fetch(1327 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4),0,4), reg_r0_13); /* line 2119 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L76X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2120 */
  sim_icache_fetch(1329 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_11 + (unsigned int) 8),0,4), reg_r0_4); /* line 2122 */
   ADD(reg_r0_11, reg_r0_11, (unsigned int) 12); /* line 2123 */
} /* line 2123 */
  sim_icache_fetch(1331 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 8),0,4), reg_r0_15); /* line 2125 */
   ADD(reg_r0_10, reg_r0_10, (unsigned int) 12); /* line 2127 */
} /* line 2127 */
  sim_icache_fetch(1333 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L75X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L75X3;
} /* line 2129 */
l_L76X3: ;/* line 2132 */
LABEL(l_L76X3);
  sim_icache_fetch(1334 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_28, reg_r0_28, (unsigned int) 1050); /* line 2133 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2134 */
} /* line 2134 */
  sim_icache_fetch(1338 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_26, reg_r0_26, reg_r0_2); /* line 2136 */
   ADD(reg_r0_27, reg_r0_27, reg_r0_2); /* line 2137 */
} /* line 2137 */
  sim_icache_fetch(1340 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_25, reg_r0_25, reg_r0_2); /* line 2139 */
   ADD(reg_r0_12, reg_r0_20, reg_r0_2); /* line 2140 */
} /* line 2140 */
  sim_icache_fetch(1342 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_21, (unsigned int) 1); /* line 2142 */
   ADD(reg_r0_10, reg_r0_18, (unsigned int) 1050); /* line 2143 */
} /* line 2143 */
  sim_icache_fetch(1345 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, reg_r0_19); /* line 2145 */
   GOTO(l_L71X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L71X3;
} /* line 2146 */
l_L72X3: ;/* line 2149 */
LABEL(l_L72X3);
  sim_icache_fetch(1347 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_24, 0, reg_r0_24); /* line 2150 */
   MOV(reg_r0_26, (unsigned int) qt); /* line 2151 */
} /* line 2151 */
  sim_icache_fetch(1350 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_24); /* line 2153 */
   MOV(reg_r0_25, (unsigned int) qy1); /* line 2154 */
} /* line 2154 */
  sim_icache_fetch(1353 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_23, (unsigned int) out); /* line 2156 */
   MOV(reg_r0_24, (unsigned int) qy2); /* line 2157 */
} /* line 2157 */
  sim_icache_fetch(1357 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_13, ((unsigned int) qy2 + (unsigned int) -12600)); /* line 2159 */
   MOV(reg_r0_12, ((unsigned int) qt + (unsigned int) -12600)); /* line 2160 */
} /* line 2160 */
  sim_icache_fetch(1361 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_29, (unsigned int) -1); /* line 2162 */
   MOV(reg_r0_22, reg_r0_29); /* line 2163 */
} /* line 2163 */
l_L77X3: ;/* line 2166 */
LABEL(l_L77X3);
  sim_icache_fetch(1363 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 2167 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 4200); /* line 2168 */
} /* line 2168 */
  sim_icache_fetch(1366 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 2170 */
   MOV(reg_r0_6, 0); /* line 2171 */
} /* line 2171 */
  sim_icache_fetch(1368 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 2173 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L78X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2174 */
  sim_icache_fetch(1370 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 2176 */
   ADD(reg_r0_8, reg_r0_13, reg_r0_11); /* line 2177 */
} /* line 2177 */
  sim_icache_fetch(1372 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, 0); /* line 2179 */
   MOV(reg_r0_2, 0); /* line 2180 */
} /* line 2180 */
  sim_icache_fetch(1374 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_21, 0); /* line 2182 */
   MOV(reg_r0_20, 0); /* line 2183 */
} /* line 2183 */
  sim_icache_fetch(1376 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_10); /* line 2185 */
   MOV(reg_r0_15, reg_r0_4); /* line 2186 */
} /* line 2186 */
  sim_icache_fetch(1378 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_16, reg_r0_10); /* line 2188 */
   MOV(reg_r0_17, reg_r0_12); /* line 2189 */
} /* line 2189 */
  sim_icache_fetch(1380 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_13); /* line 2191 */
} /* line 2191 */
l_L79X3: ;/* line 2194 */
LABEL(l_L79X3);
  sim_icache_fetch(1381 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2195 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 2196 */
} /* line 2196 */
  sim_icache_fetch(1383 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 2198 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 29); /* line 2199 */
} /* line 2199 */
  sim_icache_fetch(1385 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2201 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 2202 */
} /* line 2202 */
  sim_icache_fetch(1387 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 2204 */
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 12600),0,4)); /* line 2205 */
} /* line 2205 */
  sim_icache_fetch(1390 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 2207 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L80X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2208 */
  sim_icache_fetch(1392 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2210 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2211 */
} /* line 2211 */
  sim_icache_fetch(1394 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2213 */
   MULL(reg_r0_10, reg_r0_4, (unsigned int) -47); /* line 2214 */
} /* line 2214 */
  sim_icache_fetch(1396 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 2216 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 2217 */
} /* line 2217 */
  sim_icache_fetch(1398 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 2219 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 8400),0,4)); /* line 2220 */
} /* line 2220 */
  sim_icache_fetch(1401 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 2222 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2223 */
} /* line 2223 */
  sim_icache_fetch(1403 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 2225 */
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 2226 */
} /* line 2226 */
  sim_icache_fetch(1405 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2228 */
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 2229 */
} /* line 2229 */
  sim_icache_fetch(1407 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_5, (unsigned int) 215); /* line 2231 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 29); /* line 2232 */
} /* line 2232 */
  sim_icache_fetch(1409 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 2234 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,4)); /* line 2235 */
} /* line 2235 */
  sim_icache_fetch(1412 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_4); /* line 2237 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2238 */
} /* line 2238 */
  sim_icache_fetch(1414 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 2240 */
   MULL(reg_r0_4, reg_r0_5, (unsigned int) -155); /* line 2241 */
} /* line 2241 */
  sim_icache_fetch(1416 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2243 */
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 2244 */
} /* line 2244 */
  sim_icache_fetch(1418 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 2246 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 2247 */
} /* line 2247 */
  sim_icache_fetch(1420 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 2249 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_9,0,4)); /* line 2250 */
} /* line 2250 */
  sim_icache_fetch(1422 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 2252 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 2253 */
} /* line 2253 */
  sim_icache_fetch(1424 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_2); /* line 2255 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 2256 */
} /* line 2256 */
  sim_icache_fetch(1427 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2258 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2259 */
  sim_icache_fetch(1429 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_11); /* line 2261 */
   MOV(reg_r0_6, reg_r0_12); /* line 2262 */
} /* line 2262 */
  sim_icache_fetch(1431 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_5); /* line 2264 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -16800); /* line 2265 */
} /* line 2265 */
  sim_icache_fetch(1435 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_4); /* line 2267 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L82X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2268 */
  sim_icache_fetch(1437 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_11); /* line 2270 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L83X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2271 */
  sim_icache_fetch(1440 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 2273 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16800); /* line 2275 */
} /* line 2275 */
  sim_icache_fetch(1443 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L79X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L79X3;
} /* line 2277 */
l_L83X3: ;/* line 2280 */
LABEL(l_L83X3);
  sim_icache_fetch(1444 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_22); /* line 2281 */
   MOV(reg_r0_9, reg_r0_23); /* line 2283 */
} /* line 2283 */
  sim_icache_fetch(1446 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L84X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L84X3;
} /* line 2285 */
l_L85X3: ;/* line 2288 */
LABEL(l_L85X3);
  sim_icache_fetch(1447 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2289 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2290 */
} /* line 2290 */
  sim_icache_fetch(1449 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_5, (unsigned int) 215); /* line 2292 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 2293 */
} /* line 2293 */
  sim_icache_fetch(1451 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 1); /* line 2295 */
   LDWs(reg_r0_13, mem_trace_ld(reg_r0_7,0,4)); /* line 2296 */
} /* line 2296 */
  sim_icache_fetch(1453 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_3, (unsigned int) -48); /* line 2298 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_6); /* line 2299 */
} /* line 2299 */
  sim_icache_fetch(1455 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, 0); /* line 2301 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L86X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2302 */
  sim_icache_fetch(1457 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 2304 */
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 2305 */
} /* line 2305 */
  sim_icache_fetch(1460 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_12); /* line 2307 */
   MULL(reg_r0_14, reg_r0_5, (unsigned int) -155); /* line 2308 */
} /* line 2308 */
  sim_icache_fetch(1462 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2310 */
   MULL(reg_r0_12, reg_r0_3, (unsigned int) 28); /* line 2311 */
} /* line 2311 */
  sim_icache_fetch(1464 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_4, reg_r0_13); /* line 2313 */
   MULL(reg_r0_15, reg_r0_6, (unsigned int) -48); /* line 2314 */
} /* line 2314 */
  sim_icache_fetch(1466 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2316 */
   MULL(reg_r0_16, reg_r0_4, (unsigned int) 215); /* line 2317 */
} /* line 2317 */
  sim_icache_fetch(1468 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 16); /* line 2319 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_15); /* line 2320 */
} /* line 2320 */
  sim_icache_fetch(1470 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_15, reg_r0_13); /* line 2322 */
   ADD(reg_r0_16, reg_r0_16, reg_r0_12); /* line 2323 */
} /* line 2323 */
  sim_icache_fetch(1472 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_1, reg_r0_15, (unsigned int) 25); /* line 2325 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_16); /* line 2326 */
} /* line 2326 */
  sim_icache_fetch(1474 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_16, reg_r0_4); /* line 2328 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_7 + (unsigned int) 4200),0,4)); /* line 2329 */
} /* line 2329 */
  sim_icache_fetch(1477 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_13); /* line 2331 */
} /* line 2331 */
  sim_icache_fetch(1478 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_10,0,4), reg_r0_4); /* line 2333 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L87X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2334 */
  sim_icache_fetch(1480 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_14, (unsigned int) 8); /* line 2336 */
   MOV(reg_r0_4, reg_r0_16); /* line 2337 */
} /* line 2337 */
  sim_icache_fetch(1482 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), 0); /* line 2339 */
   ADD(reg_r0_12, reg_r0_5, reg_r0_12); /* line 2340 */
} /* line 2340 */
l_L88X3: ;/* line 2342 */
LABEL(l_L88X3);
  sim_icache_fetch(1484 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 2343 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L89X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2344 */
  sim_icache_fetch(1486 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_10 + (unsigned int) 4200),0,4), reg_r0_5); /* line 2346 */
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 16); /* line 2347 */
} /* line 2347 */
  sim_icache_fetch(1489 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_12); /* line 2349 */
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_12); /* line 2350 */
} /* line 2350 */
  sim_icache_fetch(1492 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 2352 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 2353 */
   ADD_CYCLES(1);
} /* line 2353 */
  sim_icache_fetch(1494 + t_thisfile.offset, 1);
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
} /* line 2355 */
  sim_icache_fetch(1495 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 2357 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_11); /* line 2358 */
} /* line 2358 */
  sim_icache_fetch(1497 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 2360 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_11); /* line 2361 */
} /* line 2361 */
  sim_icache_fetch(1499 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), 0); /* line 2363 */
} /* line 2363 */
l_L91X3: ;/* line 2365 */
LABEL(l_L91X3);
  sim_icache_fetch(1501 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 2100); /* line 2366 */
   GOTO(l_L85X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L85X3;
} /* line 2367 */
l_L90X3: ;/* line 2370 */
LABEL(l_L90X3);
  sim_icache_fetch(1504 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 2); /* line 2371 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 2372 */
} /* line 2372 */
  sim_icache_fetch(1506 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_11); /* line 2374 */
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 2375 */
} /* line 2375 */
  sim_icache_fetch(1508 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_9 + (unsigned int) 1050),0,1), reg_r0_3); /* line 2377 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_11); /* line 2379 */
} /* line 2379 */
  sim_icache_fetch(1511 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L91X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L91X3;
} /* line 2381 */
l_L89X3: ;/* line 2384 */
LABEL(l_L89X3);
  sim_icache_fetch(1512 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 4); /* line 2385 */
   ADD(reg_r0_26, reg_r0_26, (unsigned int) 4); /* line 2387 */
} /* line 2387 */
  sim_icache_fetch(1514 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L92X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L92X3;
} /* line 2389 */
l_L87X3: ;/* line 2392 */
LABEL(l_L87X3);
  sim_icache_fetch(1515 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_14, (unsigned int) 8); /* line 2393 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 2394 */
} /* line 2394 */
  sim_icache_fetch(1517 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_5, reg_r0_12); /* line 2396 */
   MOV(reg_r0_4, reg_r0_16); /* line 2397 */
} /* line 2397 */
  sim_icache_fetch(1519 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_9,0,1), reg_r0_3); /* line 2399 */
   GOTO(l_L88X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L88X3;
} /* line 2400 */
l_L86X3: ;/* line 2403 */
LABEL(l_L86X3);
  sim_icache_fetch(1521 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_25, reg_r0_25, (unsigned int) 4); /* line 2404 */
   ADD(reg_r0_26, reg_r0_26, (unsigned int) 4); /* line 2405 */
} /* line 2405 */
l_L92X3: ;/* line 2407 */
LABEL(l_L92X3);
  sim_icache_fetch(1523 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_23, reg_r0_23, (unsigned int) 1); /* line 2408 */
   ADD(reg_r0_24, reg_r0_24, (unsigned int) 4); /* line 2409 */
} /* line 2409 */
  sim_icache_fetch(1525 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 2411 */
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 4); /* line 2412 */
} /* line 2412 */
  sim_icache_fetch(1527 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_20, (unsigned int) 1); /* line 2414 */
   MOV(reg_r0_10, reg_r0_17); /* line 2416 */
} /* line 2416 */
  sim_icache_fetch(1529 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L77X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L77X3;
} /* line 2418 */
l_L82X3: ;/* line 2421 */
LABEL(l_L82X3);
  sim_icache_fetch(1530 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_22); /* line 2422 */
   MOV(reg_r0_9, reg_r0_23); /* line 2424 */
} /* line 2424 */
  sim_icache_fetch(1532 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L84X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L84X3;
} /* line 2426 */
l_L81X3: ;/* line 2429 */
LABEL(l_L81X3);
  sim_icache_fetch(1533 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_22); /* line 2430 */
   MOV(reg_r0_9, reg_r0_23); /* line 2432 */
} /* line 2432 */
  sim_icache_fetch(1535 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L84X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L84X3;
} /* line 2434 */
l_L80X3: ;/* line 2437 */
LABEL(l_L80X3);
  sim_icache_fetch(1536 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_3, (unsigned int) 1, reg_r0_22); /* line 2438 */
   MOV(reg_r0_9, reg_r0_23); /* line 2439 */
} /* line 2439 */
l_L84X3: ;/* line 2441 */
LABEL(l_L84X3);
  sim_icache_fetch(1538 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_3); /* line 2442 */
   MOV(reg_r0_7, reg_r0_24); /* line 2443 */
} /* line 2443 */
  sim_icache_fetch(1540 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, reg_r0_25); /* line 2445 */
   MOV(reg_r0_2, reg_r0_26); /* line 2446 */
} /* line 2446 */
  sim_icache_fetch(1542 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_20); /* line 2448 */
   MOV(reg_r0_5, reg_r0_19); /* line 2449 */
} /* line 2449 */
  sim_icache_fetch(1544 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_21); /* line 2451 */
   MOV(reg_r0_11, (unsigned int) 8400); /* line 2452 */
} /* line 2452 */
  sim_icache_fetch(1547 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_19, reg_r0_17); /* line 2454 */
   MOV(reg_r0_20, reg_r0_15); /* line 2455 */
} /* line 2455 */
  sim_icache_fetch(1549 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_16); /* line 2457 */
   GOTO(l_L85X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L85X3;
} /* line 2458 */
l_L78X3: ;/* line 2461 */
LABEL(l_L78X3);
  sim_icache_fetch(1551 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_fused);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2463 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 247: goto l_L71X3;
    case 248: goto l_L73X3;
    case 249: goto l_L74X3;
    case 250: goto l_L75X3;
    case 251: goto l_L76X3;
    case 252: goto l_L72X3;
    case 253: goto l_L77X3;
    case 254: goto l_L79X3;
    case 255: goto l_L83X3;
    case 256: goto l_L85X3;
    case 257: goto l_L88X3;
    case 258: goto l_L91X3;
    case 259: goto l_L90X3;
    case 260: goto l_L89X3;
    case 261: goto l_L87X3;
    case 262: goto l_L86X3;
    case 263: goto l_L92X3;
    case 264: goto l_L82X3;
    case 265: goto l_L81X3;
    case 266: goto l_L80X3;
    case 267: goto l_L84X3;
    case 268: goto l_L78X3;
    case 269:
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
  reg_l0_0 = (318 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(1552 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 2479 */
} /* line 2479 */
  sim_icache_fetch(1553 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, (unsigned int) qy1); /* line 2481 */
   MOV(reg_r0_12, (unsigned int) in); /* line 2482 */
} /* line 2482 */
  sim_icache_fetch(1557 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_3 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_2); /* line 2484 */
   MOV(reg_r0_19, t__i32_0); /* line 2485 */
} /* line 2485 */
  sim_icache_fetch(1559 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_4); /* line 2487 */
} /* line 2487 */
l_L93X3: ;/* line 2490 */
LABEL(l_L93X3);
  sim_icache_fetch(1560 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2491 */
   SUB(reg_r0_10, (unsigned int) 3, reg_r0_5); /* line 2492 */
} /* line 2492 */
  sim_icache_fetch(1562 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_10); /* line 2494 */
   MOV(reg_r0_9, reg_r0_11); /* line 2495 */
} /* line 2495 */
  sim_icache_fetch(1564 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, 0); /* line 2497 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L94X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2498 */
  sim_icache_fetch(1566 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, 0); /* line 2500 */
   MOV(reg_r0_2, reg_r0_12); /* line 2501 */
} /* line 2501 */
  sim_icache_fetch(1568 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, 0); /* line 2503 */
   MOV(reg_r0_15, reg_r0_3); /* line 2504 */
} /* line 2504 */
  sim_icache_fetch(1570 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_16, reg_r0_5); /* line 2506 */
   MOV(reg_r0_17, reg_r0_11); /* line 2507 */
} /* line 2507 */
  sim_icache_fetch(1572 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_12); /* line 2509 */
} /* line 2509 */
l_L95X3: ;/* line 2512 */
LABEL(l_L95X3);
  sim_icache_fetch(1573 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 2513 */
   MULL(reg_r0_5, reg_r0_4, (unsigned int) 215); /* line 2514 */
} /* line 2514 */
  sim_icache_fetch(1575 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_7, reg_r0_7, (unsigned int) 28); /* line 2516 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -155); /* line 2517 */
} /* line 2517 */
  sim_icache_fetch(1577 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 3); /* line 2519 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2520 */
} /* line 2520 */
  sim_icache_fetch(1579 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_3, (unsigned int) -48); /* line 2522 */
   SHR(reg_r0_6, reg_r0_6, (unsigned int) 8); /* line 2523 */
} /* line 2523 */
  sim_icache_fetch(1581 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_6); /* line 2525 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2526 */
  sim_icache_fetch(1583 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_5); /* line 2528 */
   CMPLT(reg_b0_0, reg_r0_8, (unsigned int) 2); /* line 2529 */
} /* line 2529 */
  sim_icache_fetch(1585 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_7, reg_r0_7, reg_r0_10); /* line 2531 */
   LDBUs(reg_r0_5, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 2532 */
} /* line 2532 */
  sim_icache_fetch(1587 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_7, (unsigned int) 215); /* line 2534 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2535 */
} /* line 2535 */
  sim_icache_fetch(1589 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2537 */
   CMPLT(reg_b0_1, reg_r0_8, (unsigned int) 1); /* line 2538 */
} /* line 2538 */
  sim_icache_fetch(1591 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_5, (unsigned int) -48); /* line 2540 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2541 */
} /* line 2541 */
  sim_icache_fetch(1593 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2543 */
   LDBUs(reg_r0_12, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 2544 */
} /* line 2544 */
  sim_icache_fetch(1595 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 2546 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 2547 */
} /* line 2547 */
  sim_icache_fetch(1597 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2549 */
   MULL(reg_r0_10, reg_r0_7, (unsigned int) -155); /* line 2550 */
} /* line 2550 */
  sim_icache_fetch(1599 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_12, (unsigned int) -48); /* line 2552 */
   MULL(reg_r0_13, reg_r0_3, (unsigned int) 215); /* line 2553 */
} /* line 2553 */
  sim_icache_fetch(1601 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 28); /* line 2555 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2556 */
} /* line 2556 */
  sim_icache_fetch(1603 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2558 */
   CMPLT(reg_b0_2, reg_r0_8, 0); /* line 2559 */
} /* line 2559 */
  sim_icache_fetch(1605 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 2561 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 2562 */
} /* line 2562 */
  sim_icache_fetch(1607 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 2564 */
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 3),0,1)); /* line 2565 */
} /* line 2565 */
  sim_icache_fetch(1609 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_5, (unsigned int) 215); /* line 2567 */
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -155); /* line 2568 */
} /* line 2568 */
  sim_icache_fetch(1611 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_12, (unsigned int) 28); /* line 2570 */
   MOV(reg_r0_6, reg_r0_5); /* line 2571 */
} /* line 2571 */
  sim_icache_fetch(1613 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_10, (unsigned int) -48); /* line 2573 */
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2574 */
} /* line 2574 */
  sim_icache_fetch(1615 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 2576 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 2577 */
} /* line 2577 */
  sim_icache_fetch(1617 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_13); /* line 2579 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_11); /* line 2580 */
} /* line 2580 */
  sim_icache_fetch(1619 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_12, reg_r0_14); /* line 2582 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 4); /* line 2583 */
} /* line 2583 */
  sim_icache_fetch(1621 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_9,0,4), reg_r0_7); /* line 2585 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2586 */
  sim_icache_fetch(1623 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 4),0,4), reg_r0_3); /* line 2588 */
   MOV(reg_r0_7, reg_r0_10); /* line 2589 */
} /* line 2589 */
  sim_icache_fetch(1625 + t_thisfile.offset, 1);
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
} /* line 2591 */
  sim_icache_fetch(1626 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 8),0,4), reg_r0_5); /* line 2593 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L96X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2594 */
  sim_icache_fetch(1628 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_9 + (unsigned int) 12),0,4), reg_r0_4); /* line 2596 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 2598 */
} /* line 2598 */
  sim_icache_fetch(1630 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L95X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L95X3;
} /* line 2600 */
l_L96X3: ;/* line 2603 */
LABEL(l_L96X3);
  sim_icache_fetch(1631 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4200); /* line 2604 */
   ADD(reg_r0_12, reg_r0_18, (unsigned int) 1050); /* line 2605 */
} /* line 2605 */
  sim_icache_fetch(1635 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_15, (unsigned int) 1); /* line 2607 */
   MOV(reg_r0_5, reg_r0_16); /* line 2609 */
} /* line 2609 */
  sim_icache_fetch(1637 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L93X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L93X3;
} /* line 2611 */
l_L94X3: ;/* line 2614 */
LABEL(l_L94X3);
  sim_icache_fetch(1638 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_19); /* line 2615 */
   MOV(reg_r0_12, ((unsigned int) qy2 + (unsigned int) -12)); /* line 2616 */
} /* line 2616 */
  sim_icache_fetch(1641 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_5, (unsigned int) -1); /* line 2618 */
   MOV(reg_r0_4, reg_r0_2); /* line 2619 */
} /* line 2619 */
  sim_icache_fetch(1643 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 2621 */
   MOV(reg_r0_21, reg_r0_19); /* line 2622 */
} /* line 2622 */
  sim_icache_fetch(1646 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_22, reg_r0_5); /* line 2624 */
} /* line 2624 */
l_L97X3: ;/* line 2627 */
LABEL(l_L97X3);
  sim_icache_fetch(1647 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 2628 */
   ADD(reg_r0_9, reg_r0_10, reg_r0_11); /* line 2629 */
} /* line 2629 */
  sim_icache_fetch(1649 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 2631 */
   SH2ADD(reg_r0_8, reg_r0_11, reg_r0_12); /* line 2632 */
} /* line 2632 */
  sim_icache_fetch(1651 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 2634 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L98X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2635 */
  sim_icache_fetch(1653 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 2637 */
   MOV(reg_r0_6, 0); /* line 2638 */
} /* line 2638 */
  sim_icache_fetch(1655 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_11); /* line 2640 */
   MOV(reg_r0_17, reg_r0_4); /* line 2641 */
} /* line 2641 */
  sim_icache_fetch(1657 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_18, reg_r0_10); /* line 2643 */
   MOV(reg_r0_19, reg_r0_11); /* line 2644 */
} /* line 2644 */
  sim_icache_fetch(1659 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_12); /* line 2646 */
} /* line 2646 */
l_L99X3: ;/* line 2649 */
LABEL(l_L99X3);
  sim_icache_fetch(1660 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 2650 */
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2651 */
} /* line 2651 */
  sim_icache_fetch(1662 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) -48); /* line 2653 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 2654 */
} /* line 2654 */
  sim_icache_fetch(1664 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 2656 */
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2657 */
} /* line 2657 */
  sim_icache_fetch(1666 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2659 */
   ADD(reg_r0_4, reg_r0_4, reg_r0_2); /* line 2660 */
} /* line 2660 */
  sim_icache_fetch(1668 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 2662 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2663 */
  sim_icache_fetch(1670 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_6); /* line 2665 */
   LDBU(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 3),0,1)); /* line 2666 */
} /* line 2666 */
  sim_icache_fetch(1672 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2668 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2669 */
} /* line 2669 */
  sim_icache_fetch(1674 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 2671 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) 215); /* line 2672 */
} /* line 2672 */
  sim_icache_fetch(1676 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 2674 */
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2675 */
} /* line 2675 */
  sim_icache_fetch(1678 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2677 */
   LDBUs(reg_r0_13, mem_trace_ld((reg_r0_9 + (unsigned int) 2),0,1)); /* line 2678 */
} /* line 2678 */
  sim_icache_fetch(1680 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_5); /* line 2680 */
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 2681 */
} /* line 2681 */
  sim_icache_fetch(1682 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_3); /* line 2683 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2684 */
} /* line 2684 */
  sim_icache_fetch(1684 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_13, (unsigned int) -47); /* line 2686 */
   MULL(reg_r0_11, reg_r0_4, (unsigned int) -155); /* line 2687 */
} /* line 2687 */
  sim_icache_fetch(1686 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 2689 */
   MULL(reg_r0_15, reg_r0_12, (unsigned int) 215); /* line 2690 */
} /* line 2690 */
  sim_icache_fetch(1688 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2692 */
   LDBUs(reg_r0_16, mem_trace_ld((reg_r0_9 + (unsigned int) 1),0,1)); /* line 2693 */
} /* line 2693 */
  sim_icache_fetch(1690 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2695 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_11); /* line 2696 */
} /* line 2696 */
  sim_icache_fetch(1692 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_15); /* line 2698 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 2699 */
} /* line 2699 */
  sim_icache_fetch(1694 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 2701 */
   MULL(reg_r0_10, reg_r0_12, (unsigned int) -155); /* line 2702 */
} /* line 2702 */
  sim_icache_fetch(1696 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_16, (unsigned int) -47); /* line 2704 */
   MULL(reg_r0_15, reg_r0_14, (unsigned int) 215); /* line 2705 */
} /* line 2705 */
  sim_icache_fetch(1698 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_13, (unsigned int) -48); /* line 2707 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2708 */
} /* line 2708 */
  sim_icache_fetch(1700 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_15, reg_r0_15, (unsigned int) 8); /* line 2710 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 2711 */
} /* line 2711 */
  sim_icache_fetch(1702 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_15); /* line 2713 */
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_9,0,1)); /* line 2714 */
} /* line 2714 */
  sim_icache_fetch(1704 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_11, reg_r0_13); /* line 2716 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 2717 */
} /* line 2717 */
  sim_icache_fetch(1706 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_16); /* line 2719 */
   MOV(reg_r0_2, reg_r0_14); /* line 2720 */
} /* line 2720 */
  sim_icache_fetch(1708 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 2722 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -4); /* line 2723 */
} /* line 2723 */
  sim_icache_fetch(1710 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2725 */
  sim_icache_fetch(1711 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_12); /* line 2727 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2728 */
  sim_icache_fetch(1713 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_14); /* line 2730 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L100X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2731 */
  sim_icache_fetch(1715 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_5); /* line 2733 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16); /* line 2735 */
} /* line 2735 */
  sim_icache_fetch(1717 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L99X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L99X3;
} /* line 2737 */
l_L100X3: ;/* line 2740 */
LABEL(l_L100X3);
  sim_icache_fetch(1718 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_18, (unsigned int) 1050); /* line 2741 */
   ADD(reg_r0_12, reg_r0_20, (unsigned int) 4200); /* line 2742 */
} /* line 2742 */
  sim_icache_fetch(1722 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_17, (unsigned int) 1); /* line 2744 */
   MOV(reg_r0_11, reg_r0_19); /* line 2746 */
} /* line 2746 */
  sim_icache_fetch(1724 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L97X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L97X3;
} /* line 2748 */
l_L98X3: ;/* line 2751 */
LABEL(l_L98X3);
  sim_icache_fetch(1725 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_21); /* line 2752 */
   MOV(reg_r0_11, (unsigned int) qy2); /* line 2753 */
} /* line 2753 */
  sim_icache_fetch(1728 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_2); /* line 2755 */
   MOV(reg_r0_10, (unsigned int) qy1); /* line 2756 */
} /* line 2756 */
  sim_icache_fetch(1731 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, (unsigned int) qt); /* line 2758 */
   MOV(reg_r0_16, reg_r0_21); /* line 2759 */
} /* line 2759 */
  sim_icache_fetch(1734 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_22); /* line 2761 */
} /* line 2761 */
l_L101X3: ;/* line 2764 */
LABEL(l_L101X3);
  sim_icache_fetch(1735 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2765 */
   SUB(reg_r0_8, (unsigned int) 3, reg_r0_7); /* line 2766 */
} /* line 2766 */
  sim_icache_fetch(1737 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_8); /* line 2768 */
   MOV(reg_r0_6, reg_r0_9); /* line 2769 */
} /* line 2769 */
  sim_icache_fetch(1739 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_10); /* line 2771 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L102X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2772 */
  sim_icache_fetch(1741 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_11); /* line 2774 */
   MOV(reg_r0_12, reg_r0_7); /* line 2775 */
} /* line 2775 */
  sim_icache_fetch(1743 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_r0_11 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_11, reg_r0_3); /* line 2777 */
   MOV(reg_r0_15, t__i32_0); /* line 2778 */
} /* line 2778 */
  sim_icache_fetch(1745 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_13, reg_r0_9); /* line 2780 */
   MOV(reg_r0_14, reg_r0_10); /* line 2781 */
} /* line 2781 */
l_L103X3: ;/* line 2784 */
LABEL(l_L103X3);
  sim_icache_fetch(1747 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 2785 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2786 */
} /* line 2786 */
  sim_icache_fetch(1749 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_7, mem_trace_ld(reg_r0_4,0,4)); /* line 2788 */
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2789 */
} /* line 2789 */
  sim_icache_fetch(1751 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 2791 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L104X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2792 */
  sim_icache_fetch(1753 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 2794 */
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 2795 */
} /* line 2795 */
  sim_icache_fetch(1755 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_7); /* line 2797 */
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 2798 */
} /* line 2798 */
  sim_icache_fetch(1757 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2800 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 2801 */
} /* line 2801 */
  sim_icache_fetch(1759 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2803 */
   ADD(reg_r0_8, reg_r0_8, reg_r0_9); /* line 2804 */
} /* line 2804 */
  sim_icache_fetch(1761 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 2806 */
   CMPLT(reg_b0_2, reg_r0_5, 0); /* line 2807 */
} /* line 2807 */
  sim_icache_fetch(1763 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 2809 */
   ADD(reg_r0_7, reg_r0_7, reg_r0_10); /* line 2810 */
} /* line 2810 */
  sim_icache_fetch(1765 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 2812 */
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 2813 */
} /* line 2813 */
  sim_icache_fetch(1767 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 2815 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 2816 */
} /* line 2816 */
  sim_icache_fetch(1769 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 2818 */
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 2819 */
} /* line 2819 */
  sim_icache_fetch(1771 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_6,0,4), reg_r0_3); /* line 2821 */
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2822 */
} /* line 2822 */
  sim_icache_fetch(1773 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_9, reg_r0_10); /* line 2824 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L105X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2825 */
  sim_icache_fetch(1775 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 4),0,4), reg_r0_8); /* line 2827 */
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2828 */
} /* line 2828 */
  sim_icache_fetch(1777 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2830 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L106X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2831 */
  sim_icache_fetch(1779 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 8),0,4), reg_r0_7); /* line 2833 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L107X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2834 */
  sim_icache_fetch(1781 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 12),0,4), reg_r0_9); /* line 2836 */
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 2838 */
} /* line 2838 */
  sim_icache_fetch(1783 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L103X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L103X3;
} /* line 2840 */
l_L107X3: ;/* line 2843 */
LABEL(l_L107X3);
  sim_icache_fetch(1784 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 2844 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2845 */
} /* line 2845 */
  sim_icache_fetch(1787 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_14, reg_r0_2); /* line 2847 */
   ADD(reg_r0_11, reg_r0_15, reg_r0_2); /* line 2849 */
} /* line 2849 */
  sim_icache_fetch(1789 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L108X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L108X3;
} /* line 2851 */
l_L106X3: ;/* line 2854 */
LABEL(l_L106X3);
  sim_icache_fetch(1790 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 2855 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2856 */
} /* line 2856 */
  sim_icache_fetch(1793 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_14, reg_r0_2); /* line 2858 */
   ADD(reg_r0_11, reg_r0_15, reg_r0_2); /* line 2860 */
} /* line 2860 */
  sim_icache_fetch(1795 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L108X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L108X3;
} /* line 2862 */
l_L105X3: ;/* line 2865 */
LABEL(l_L105X3);
  sim_icache_fetch(1796 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 2866 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2867 */
} /* line 2867 */
  sim_icache_fetch(1799 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_14, reg_r0_2); /* line 2869 */
   ADD(reg_r0_11, reg_r0_15, reg_r0_2); /* line 2871 */
} /* line 2871 */
  sim_icache_fetch(1801 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L108X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L108X3;
} /* line 2873 */
l_L104X3: ;/* line 2876 */
LABEL(l_L104X3);
  sim_icache_fetch(1802 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 2877 */
   MOV(reg_r0_2, (unsigned int) 4200); /* line 2878 */
} /* line 2878 */
  sim_icache_fetch(1805 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_14, reg_r0_2); /* line 2880 */
   ADD(reg_r0_11, reg_r0_15, reg_r0_2); /* line 2881 */
} /* line 2881 */
l_L108X3: ;/* line 2883 */
LABEL(l_L108X3);
  sim_icache_fetch(1807 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_13, reg_r0_2); /* line 2884 */
   MOV(reg_r0_7, reg_r0_12); /* line 2886 */
} /* line 2886 */
  sim_icache_fetch(1809 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L101X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L101X3;
} /* line 2888 */
l_L102X3: ;/* line 2891 */
LABEL(l_L102X3);
  sim_icache_fetch(1810 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_7); /* line 2892 */
   MOV(reg_r0_12, (unsigned int) qt); /* line 2893 */
} /* line 2893 */
  sim_icache_fetch(1813 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_2); /* line 2895 */
   MOV(reg_r0_11, (unsigned int) qy1); /* line 2896 */
} /* line 2896 */
  sim_icache_fetch(1816 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_7); /* line 2898 */
   MOV(reg_r0_9, reg_r0_16); /* line 2899 */
} /* line 2899 */
l_L109X3: ;/* line 2902 */
LABEL(l_L109X3);
  sim_icache_fetch(1818 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2903 */
   SUB(reg_r0_10, (unsigned int) 3, reg_r0_9); /* line 2904 */
} /* line 2904 */
  sim_icache_fetch(1820 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_7, reg_r0_10); /* line 2906 */
   MOV(reg_r0_8, reg_r0_11); /* line 2907 */
} /* line 2907 */
  sim_icache_fetch(1822 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_12); /* line 2909 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L110X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2910 */
  sim_icache_fetch(1824 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, 0); /* line 2912 */
   MOV(reg_r0_5, 0); /* line 2913 */
} /* line 2913 */
  sim_icache_fetch(1826 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, 0); /* line 2915 */
   MOV(reg_r0_13, reg_r0_3); /* line 2916 */
} /* line 2916 */
  sim_icache_fetch(1828 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_14, reg_r0_9); /* line 2918 */
   MOV(reg_r0_15, reg_r0_11); /* line 2919 */
} /* line 2919 */
  sim_icache_fetch(1830 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_12); /* line 2921 */
} /* line 2921 */
l_L111X3: ;/* line 2924 */
LABEL(l_L111X3);
  sim_icache_fetch(1831 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2925 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2926 */
} /* line 2926 */
  sim_icache_fetch(1833 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_9, reg_r0_5, (unsigned int) 215); /* line 2928 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 2929 */
} /* line 2929 */
  sim_icache_fetch(1835 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 3); /* line 2931 */
   CMPLT(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2932 */
} /* line 2932 */
  sim_icache_fetch(1837 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_3, (unsigned int) -48); /* line 2934 */
   ADD(reg_r0_9, reg_r0_9, reg_r0_6); /* line 2935 */
} /* line 2935 */
  sim_icache_fetch(1839 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 2937 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L112X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2938 */
  sim_icache_fetch(1842 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_10); /* line 2940 */
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2941 */
} /* line 2941 */
  sim_icache_fetch(1844 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_9); /* line 2943 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2944 */
} /* line 2944 */
  sim_icache_fetch(1846 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2946 */
   MULL(reg_r0_9, reg_r0_11, (unsigned int) -48); /* line 2947 */
} /* line 2947 */
  sim_icache_fetch(1848 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 2949 */
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2950 */
} /* line 2950 */
  sim_icache_fetch(1850 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_9); /* line 2952 */
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 8400),0,4)); /* line 2953 */
} /* line 2953 */
  sim_icache_fetch(1853 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_3); /* line 2955 */
   MULL(reg_r0_3, reg_r0_4, (unsigned int) -155); /* line 2956 */
} /* line 2956 */
  sim_icache_fetch(1855 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 2958 */
   MULL(reg_r0_11, reg_r0_11, (unsigned int) 28); /* line 2959 */
} /* line 2959 */
  sim_icache_fetch(1857 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2961 */
   MULL(reg_r0_10, reg_r0_9, (unsigned int) -48); /* line 2962 */
} /* line 2962 */
  sim_icache_fetch(1859 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_12, reg_r0_5, (unsigned int) 215); /* line 2964 */
   CMPLT(reg_b0_2, reg_r0_7, 0); /* line 2965 */
} /* line 2965 */
  sim_icache_fetch(1861 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_10); /* line 2967 */
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 12600),0,4)); /* line 2968 */
} /* line 2968 */
  sim_icache_fetch(1864 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_12, reg_r0_11); /* line 2970 */
   MULL(reg_r0_10, reg_r0_5, (unsigned int) -155); /* line 2971 */
} /* line 2971 */
  sim_icache_fetch(1866 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_12); /* line 2973 */
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 28); /* line 2974 */
} /* line 2974 */
  sim_icache_fetch(1868 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2976 */
   MULL(reg_r0_11, reg_r0_6, (unsigned int) -48); /* line 2977 */
} /* line 2977 */
  sim_icache_fetch(1870 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 2979 */
   MULL(reg_r0_12, reg_r0_3, (unsigned int) 215); /* line 2980 */
} /* line 2980 */
  sim_icache_fetch(1872 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 2982 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L113X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2983 */
  sim_icache_fetch(1874 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_3); /* line 2985 */
   ADD(reg_r0_12, reg_r0_12, reg_r0_9); /* line 2986 */
} /* line 2986 */
  sim_icache_fetch(1876 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_12); /* line 2988 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16800); /* line 2989 */
} /* line 2989 */
  sim_icache_fetch(1879 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2991 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 2992 */
} /* line 2992 */
  sim_icache_fetch(1881 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_5); /* line 2994 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L114X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2995 */
  sim_icache_fetch(1884 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_3); /* line 2997 */
   MOV(reg_r0_5, reg_r0_10); /* line 2998 */
} /* line 2998 */
  sim_icache_fetch(1887 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L115X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3000 */
  sim_icache_fetch(1888 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_10); /* line 3002 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 16800); /* line 3004 */
} /* line 3004 */
  sim_icache_fetch(1892 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L111X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L111X3;
} /* line 3006 */
l_L115X3: ;/* line 3009 */
LABEL(l_L115X3);
  sim_icache_fetch(1893 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3010 */
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 3011 */
} /* line 3011 */
  sim_icache_fetch(1895 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_14); /* line 3013 */
   GOTO(l_L116X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L116X3;
} /* line 3014 */
l_L114X3: ;/* line 3017 */
LABEL(l_L114X3);
  sim_icache_fetch(1897 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3018 */
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 3019 */
} /* line 3019 */
  sim_icache_fetch(1899 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_14); /* line 3021 */
   GOTO(l_L116X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L116X3;
} /* line 3022 */
l_L113X3: ;/* line 3025 */
LABEL(l_L113X3);
  sim_icache_fetch(1901 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3026 */
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 3027 */
} /* line 3027 */
  sim_icache_fetch(1903 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_9, reg_r0_14); /* line 3029 */
   GOTO(l_L116X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L116X3;
} /* line 3030 */
l_L112X3: ;/* line 3033 */
LABEL(l_L112X3);
  sim_icache_fetch(1905 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3034 */
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 3035 */
} /* line 3035 */
  sim_icache_fetch(1907 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_14); /* line 3037 */
} /* line 3037 */
l_L116X3: ;/* line 3039 */
LABEL(l_L116X3);
  sim_icache_fetch(1908 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_15, (unsigned int) 4); /* line 3040 */
   GOTO(l_L109X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L109X3;
} /* line 3041 */
l_L110X3: ;/* line 3044 */
LABEL(l_L110X3);
  sim_icache_fetch(1910 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_2, 0, reg_r0_17); /* line 3045 */
   MOV(reg_r0_13, ((unsigned int) qy2 + (unsigned int) -12600)); /* line 3046 */
} /* line 3046 */
  sim_icache_fetch(1913 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_2); /* line 3048 */
   MOV(reg_r0_12, ((unsigned int) qt + (unsigned int) -12600)); /* line 3049 */
} /* line 3049 */
  sim_icache_fetch(1916 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_9, (unsigned int) -1); /* line 3051 */
   MOV(reg_r0_19, reg_r0_17); /* line 3052 */
} /* line 3052 */
  sim_icache_fetch(1918 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_r0_9); /* line 3054 */
} /* line 3054 */
l_L117X3: ;/* line 3057 */
LABEL(l_L117X3);
  sim_icache_fetch(1919 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 3058 */
   MULLU(reg_r0_11, reg_r0_10, (unsigned int) 4200); /* line 3059 */
} /* line 3059 */
  sim_icache_fetch(1922 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 3061 */
   MOV(reg_r0_6, 0); /* line 3062 */
} /* line 3062 */
  sim_icache_fetch(1924 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_9, reg_r0_12, reg_r0_11); /* line 3064 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L118X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3065 */
  sim_icache_fetch(1926 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, 0); /* line 3067 */
   ADD(reg_r0_8, reg_r0_13, reg_r0_11); /* line 3068 */
} /* line 3068 */
  sim_icache_fetch(1928 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, 0); /* line 3070 */
   MOV(reg_r0_7, reg_r0_10); /* line 3071 */
} /* line 3071 */
  sim_icache_fetch(1930 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_15, reg_r0_4); /* line 3073 */
   MOV(reg_r0_16, reg_r0_10); /* line 3074 */
} /* line 3074 */
  sim_icache_fetch(1932 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_17, reg_r0_12); /* line 3076 */
   MOV(reg_r0_18, reg_r0_13); /* line 3077 */
} /* line 3077 */
l_L119X3: ;/* line 3080 */
LABEL(l_L119X3);
  sim_icache_fetch(1934 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 3081 */
   MULL(reg_r0_4, reg_r0_3, (unsigned int) -47); /* line 3082 */
} /* line 3082 */
  sim_icache_fetch(1936 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_10, reg_r0_5, (unsigned int) 215); /* line 3084 */
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 29); /* line 3085 */
} /* line 3085 */
  sim_icache_fetch(1938 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGE(reg_b0_0, reg_r0_7, 0); /* line 3087 */
   ADD(reg_r0_2, reg_r0_2, reg_r0_4); /* line 3088 */
} /* line 3088 */
  sim_icache_fetch(1940 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_10, reg_r0_10, reg_r0_6); /* line 3090 */
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_9 + (unsigned int) 12600),0,4)); /* line 3091 */
} /* line 3091 */
  sim_icache_fetch(1943 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 3093 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L120X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3094 */
  sim_icache_fetch(1945 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 3096 */
   CMPGE(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 3097 */
} /* line 3097 */
  sim_icache_fetch(1947 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 3099 */
   MULL(reg_r0_10, reg_r0_4, (unsigned int) -47); /* line 3100 */
} /* line 3100 */
  sim_icache_fetch(1949 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 3102 */
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 3103 */
} /* line 3103 */
  sim_icache_fetch(1951 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 3105 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_9 + (unsigned int) 8400),0,4)); /* line 3106 */
} /* line 3106 */
  sim_icache_fetch(1954 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 3108 */
   CMPGE(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 3109 */
} /* line 3109 */
  sim_icache_fetch(1956 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 3111 */
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 3112 */
} /* line 3112 */
  sim_icache_fetch(1958 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 3114 */
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 3115 */
} /* line 3115 */
  sim_icache_fetch(1960 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_13, reg_r0_5, (unsigned int) 215); /* line 3117 */
   MULL(reg_r0_4, reg_r0_4, (unsigned int) 29); /* line 3118 */
} /* line 3118 */
  sim_icache_fetch(1962 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 3120 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_9 + (unsigned int) 4200),0,4)); /* line 3121 */
} /* line 3121 */
  sim_icache_fetch(1965 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_13, reg_r0_13, reg_r0_4); /* line 3123 */
   CMPGE(reg_b0_2, reg_r0_7, (unsigned int) 3); /* line 3124 */
} /* line 3124 */
  sim_icache_fetch(1967 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 3126 */
   MULL(reg_r0_4, reg_r0_5, (unsigned int) -155); /* line 3127 */
} /* line 3127 */
  sim_icache_fetch(1969 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 3129 */
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 3130 */
} /* line 3130 */
  sim_icache_fetch(1971 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 3132 */
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 3133 */
} /* line 3133 */
  sim_icache_fetch(1973 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_13); /* line 3135 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_9,0,4)); /* line 3136 */
} /* line 3136 */
  sim_icache_fetch(1975 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_2); /* line 3138 */
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 3139 */
} /* line 3139 */
  sim_icache_fetch(1978 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, reg_r0_14); /* line 3141 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L121X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3142 */
  sim_icache_fetch(1980 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_11); /* line 3144 */
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 3145 */
} /* line 3145 */
  sim_icache_fetch(1982 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_12); /* line 3147 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -4); /* line 3148 */
} /* line 3148 */
  sim_icache_fetch(1984 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_5); /* line 3150 */
   ADD(reg_r0_9, reg_r0_9, (unsigned int) -16800); /* line 3151 */
} /* line 3151 */
  sim_icache_fetch(1988 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_4); /* line 3153 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L122X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3154 */
  sim_icache_fetch(1990 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_11); /* line 3156 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L123X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3157 */
  sim_icache_fetch(1993 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 3159 */
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16800); /* line 3161 */
} /* line 3161 */
  sim_icache_fetch(1996 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L119X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L119X3;
} /* line 3163 */
l_L123X3: ;/* line 3166 */
LABEL(l_L123X3);
  sim_icache_fetch(1997 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 3167 */
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 3169 */
} /* line 3169 */
  sim_icache_fetch(1999 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L124X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L124X3;
} /* line 3171 */
l_L122X3: ;/* line 3174 */
LABEL(l_L122X3);
  sim_icache_fetch(2000 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 3175 */
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 3177 */
} /* line 3177 */
  sim_icache_fetch(2002 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L124X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L124X3;
} /* line 3179 */
l_L121X3: ;/* line 3182 */
LABEL(l_L121X3);
  sim_icache_fetch(2003 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 3183 */
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 3185 */
} /* line 3185 */
  sim_icache_fetch(2005 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L124X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L124X3;
} /* line 3187 */
l_L120X3: ;/* line 3190 */
LABEL(l_L120X3);
  sim_icache_fetch(2006 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4); /* line 3191 */
   ADD(reg_r0_13, reg_r0_18, (unsigned int) 4); /* line 3192 */
} /* line 3192 */
l_L124X3: ;/* line 3194 */
LABEL(l_L124X3);
  sim_icache_fetch(2008 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_15, (unsigned int) 1); /* line 3195 */
   MOV(reg_r0_10, reg_r0_16); /* line 3197 */
} /* line 3197 */
  sim_icache_fetch(2010 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L117X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L117X3;
} /* line 3199 */
l_L118X3: ;/* line 3202 */
LABEL(l_L118X3);
  sim_icache_fetch(2011 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_20, 0, reg_r0_20); /* line 3203 */
   MOV(reg_r0_12, (unsigned int) qy2); /* line 3204 */
} /* line 3204 */
  sim_icache_fetch(2014 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_20); /* line 3206 */
   MOV(reg_r0_11, (unsigned int) qy1); /* line 3207 */
} /* line 3207 */
  sim_icache_fetch(2017 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_10, (unsigned int) out); /* line 3209 */
   MOV(reg_r0_8, reg_r0_19); /* line 3210 */
} /* line 3210 */
l_L125X3: ;/* line 3213 */
LABEL(l_L125X3);
  sim_icache_fetch(2020 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 3214 */
   SUB(reg_r0_9, (unsigned int) 3, reg_r0_8); /* line 3215 */
} /* line 3215 */
  sim_icache_fetch(2022 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_9); /* line 3217 */
   MOV(reg_r0_7, reg_r0_10); /* line 3218 */
} /* line 3218 */
  sim_icache_fetch(2024 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_10); /* line 3220 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L126X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3221 */
  sim_icache_fetch(2026 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_11); /* line 3223 */
   MOV(reg_r0_2, reg_r0_12); /* line 3224 */
} /* line 3224 */
  sim_icache_fetch(2028 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_13, reg_r0_3); /* line 3226 */
   MOV(reg_r0_14, reg_r0_8); /* line 3227 */
} /* line 3227 */
  sim_icache_fetch(2030 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_15, reg_r0_10); /* line 3229 */
   MOV(reg_r0_16, reg_r0_11); /* line 3230 */
} /* line 3230 */
  sim_icache_fetch(2032 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_12); /* line 3232 */
} /* line 3232 */
l_L127X3: ;/* line 3235 */
LABEL(l_L127X3);
  sim_icache_fetch(2033 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 3236 */
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 3237 */
} /* line 3237 */
  sim_icache_fetch(2035 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_4,0,4)); /* line 3239 */
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 3240 */
} /* line 3240 */
  sim_icache_fetch(2037 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 3242 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L128X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3243 */
  sim_icache_fetch(2039 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 3245 */
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 3246 */
} /* line 3246 */
  sim_icache_fetch(2041 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_3, reg_r0_8); /* line 3248 */
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 3249 */
} /* line 3249 */
  sim_icache_fetch(2043 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 3251 */
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 3252 */
} /* line 3252 */
  sim_icache_fetch(2045 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 3254 */
   ADD(reg_r0_9, reg_r0_9, reg_r0_10); /* line 3255 */
} /* line 3255 */
  sim_icache_fetch(2047 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_10, reg_r0_3); /* line 3257 */
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 3258 */
} /* line 3258 */
  sim_icache_fetch(2049 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_2, reg_r0_10, (unsigned int) 25); /* line 3260 */
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 3261 */
} /* line 3261 */
  sim_icache_fetch(2051 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_12, reg_r0_9); /* line 3263 */
   ADD(reg_r0_11, reg_r0_11, reg_r0_8); /* line 3264 */
} /* line 3264 */
  sim_icache_fetch(2053 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_3, reg_r0_12, (unsigned int) 25); /* line 3266 */
   SHL(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 3267 */
} /* line 3267 */
  sim_icache_fetch(2055 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 16); /* line 3269 */
   CMPLT(reg_b0_4, reg_r0_5, 0); /* line 3270 */
} /* line 3270 */
  sim_icache_fetch(2057 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_8, reg_r0_11); /* line 3272 */
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 3273 */
} /* line 3273 */
  sim_icache_fetch(2059 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_5, reg_r0_8, (unsigned int) 25); /* line 3275 */
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 3276 */
} /* line 3276 */
  sim_icache_fetch(2061 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_6,0,1), reg_r0_3); /* line 3278 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L129X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3279 */
  sim_icache_fetch(2063 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_6,0,1), 0); /* line 3281 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3282 */
l_L131X3: ;/* line 3284 */
LABEL(l_L131X3);
  sim_icache_fetch(2065 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), reg_r0_9); /* line 3285 */
   ADD(reg_r0_10, reg_r0_10, reg_r0_12); /* line 3286 */
} /* line 3286 */
  sim_icache_fetch(2067 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHL(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 3288 */
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L132X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3289 */
  sim_icache_fetch(2069 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), 0); /* line 3291 */
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 3292 */
} /* line 3292 */
l_L133X3: ;/* line 3294 */
LABEL(l_L133X3);
  sim_icache_fetch(2071 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ZXTB(reg_r0_3, reg_r0_10); /* line 3295 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L134X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3296 */
  sim_icache_fetch(2073 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), reg_r0_11); /* line 3298 */
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 25); /* line 3299 */
} /* line 3299 */
  sim_icache_fetch(2075 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_5) {    BRANCHF(reg_b0_5);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L135X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3301 */
  sim_icache_fetch(2076 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), 0); /* line 3303 */
   if (!reg_b0_4) {    BRANCHF(reg_b0_4);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3304 */
l_L137X3: ;/* line 3306 */
LABEL(l_L137X3);
  sim_icache_fetch(2078 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), reg_r0_10); /* line 3307 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L138X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3308 */
  sim_icache_fetch(2080 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 3310 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 3311 */
} /* line 3311 */
  sim_icache_fetch(2082 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 3313 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 3314 */
} /* line 3314 */
  sim_icache_fetch(2084 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), 0); /* line 3316 */
} /* line 3316 */
l_L139X3: ;/* line 3318 */
LABEL(l_L139X3);
  sim_icache_fetch(2085 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 4); /* line 3319 */
   GOTO(l_L127X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L127X3;
} /* line 3320 */
l_L138X3: ;/* line 3323 */
LABEL(l_L138X3);
  sim_icache_fetch(2087 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 3324 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 3325 */
} /* line 3325 */
  sim_icache_fetch(2089 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 3327 */
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 3328 */
} /* line 3328 */
  sim_icache_fetch(2091 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 3),0,1), reg_r0_3); /* line 3330 */
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 3332 */
} /* line 3332 */
  sim_icache_fetch(2093 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L139X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L139X3;
} /* line 3334 */
l_L136X3: ;/* line 3337 */
LABEL(l_L136X3);
  sim_icache_fetch(2094 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3338 */
   ADD(reg_r0_11, reg_r0_16, (unsigned int) 4200); /* line 3339 */
} /* line 3339 */
  sim_icache_fetch(2097 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4200); /* line 3341 */
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1050); /* line 3343 */
} /* line 3343 */
  sim_icache_fetch(2101 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L140X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L140X3;
} /* line 3345 */
l_L135X3: ;/* line 3348 */
LABEL(l_L135X3);
  sim_icache_fetch(2102 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 3349 */
} /* line 3349 */
  sim_icache_fetch(2103 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 2),0,1), reg_r0_3); /* line 3351 */
   if (!reg_b0_4) {    BRANCHF(reg_b0_4);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L136X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3353 */
  sim_icache_fetch(2105 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L137X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L137X3;
} /* line 3355 */
l_L134X3: ;/* line 3358 */
LABEL(l_L134X3);
  sim_icache_fetch(2106 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3359 */
   ADD(reg_r0_11, reg_r0_16, (unsigned int) 4200); /* line 3360 */
} /* line 3360 */
  sim_icache_fetch(2109 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4200); /* line 3362 */
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1050); /* line 3364 */
} /* line 3364 */
  sim_icache_fetch(2113 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L140X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L140X3;
} /* line 3366 */
l_L132X3: ;/* line 3369 */
LABEL(l_L132X3);
  sim_icache_fetch(2114 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 3370 */
   MOV(reg_r0_3, (unsigned int) 255); /* line 3371 */
} /* line 3371 */
  sim_icache_fetch(2116 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 1),0,1), reg_r0_3); /* line 3373 */
   GOTO(l_L133X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L133X3;
} /* line 3374 */
l_L130X3: ;/* line 3377 */
LABEL(l_L130X3);
  sim_icache_fetch(2118 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3378 */
   ADD(reg_r0_11, reg_r0_16, (unsigned int) 4200); /* line 3379 */
} /* line 3379 */
  sim_icache_fetch(2121 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4200); /* line 3381 */
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1050); /* line 3383 */
} /* line 3383 */
  sim_icache_fetch(2125 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L140X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L140X3;
} /* line 3385 */
l_L129X3: ;/* line 3388 */
LABEL(l_L129X3);
  sim_icache_fetch(2126 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 3389 */
} /* line 3389 */
  sim_icache_fetch(2127 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STB(mem_trace_st(reg_r0_7,0,1), reg_r0_3); /* line 3391 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L130X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 3393 */
  sim_icache_fetch(2129 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L131X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L131X3;
} /* line 3395 */
l_L128X3: ;/* line 3398 */
LABEL(l_L128X3);
  sim_icache_fetch(2130 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_11, reg_r0_16, (unsigned int) 4200); /* line 3399 */
   ADD(reg_r0_12, reg_r0_17, (unsigned int) 4200); /* line 3400 */
} /* line 3400 */
  sim_icache_fetch(2134 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 3402 */
   ADD(reg_r0_10, reg_r0_15, (unsigned int) 1050); /* line 3403 */
} /* line 3403 */
l_L140X3: ;/* line 3405 */
LABEL(l_L140X3);
  sim_icache_fetch(2137 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_8, reg_r0_14); /* line 3406 */
   GOTO(l_L125X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L125X3;
} /* line 3407 */
l_L126X3: ;/* line 3410 */
LABEL(l_L126X3);
  sim_icache_fetch(2139 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_slow);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 3412 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 270: goto l_L93X3;
    case 271: goto l_L95X3;
    case 272: goto l_L96X3;
    case 273: goto l_L94X3;
    case 274: goto l_L97X3;
    case 275: goto l_L99X3;
    case 276: goto l_L100X3;
    case 277: goto l_L98X3;
    case 278: goto l_L101X3;
    case 279: goto l_L103X3;
    case 280: goto l_L107X3;
    case 281: goto l_L106X3;
    case 282: goto l_L105X3;
    case 283: goto l_L104X3;
    case 284: goto l_L108X3;
    case 285: goto l_L102X3;
    case 286: goto l_L109X3;
    case 287: goto l_L111X3;
    case 288: goto l_L115X3;
    case 289: goto l_L114X3;
    case 290: goto l_L113X3;
    case 291: goto l_L112X3;
    case 292: goto l_L116X3;
    case 293: goto l_L110X3;
    case 294: goto l_L117X3;
    case 295: goto l_L119X3;
    case 296: goto l_L123X3;
    case 297: goto l_L122X3;
    case 298: goto l_L121X3;
    case 299: goto l_L120X3;
    case 300: goto l_L124X3;
    case 301: goto l_L118X3;
    case 302: goto l_L125X3;
    case 303: goto l_L127X3;
    case 304: goto l_L131X3;
    case 305: goto l_L133X3;
    case 306: goto l_L137X3;
    case 307: goto l_L139X3;
    case 308: goto l_L138X3;
    case 309: goto l_L136X3;
    case 310: goto l_L135X3;
    case 311: goto l_L134X3;
    case 312: goto l_L132X3;
    case 313: goto l_L130X3;
    case 314: goto l_L129X3;
    case 315: goto l_L128X3;
    case 316: goto l_L140X3;
    case 317: goto l_L126X3;
    case 318:
      reg_l0_0 = t_client_rpc;
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"deriche.s", 2144, 0, 0, 0, 2};


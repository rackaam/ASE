/* "" */
/* "Copyright (C) 1990-2010 Hewlett-Packard Company" */
/* "VEX C compiler version 3.43 (20110131 release)" */
/* "" */
/* "-dir /opt/vex-3.43 -I../include/ -ms -mas_g -mas_t -O2 -fmm=./risc.mm -DVEX -o edge_detect" */

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
extern unsigned int reg_l0_0;
extern unsigned int reg_r0_0;
extern unsigned int reg_r0_1;
extern unsigned int reg_r0_2;
extern unsigned int reg_r0_3;
extern unsigned int reg_r0_4;
extern unsigned int reg_r0_5;
extern unsigned int reg_r0_6;
extern unsigned int reg_r0_7;
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
  reg_l0_0 = (199 << 5);
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
   RETURN(deriche_fused);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 856 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 199:
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
  reg_l0_0 = (200 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(457 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 871 */
  sim_icache_fetch(458 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_slow);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + 0; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 874 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 200:
      reg_l0_0 = t_client_rpc;
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"deriche.s", 464, 0, 0, 0, 2};


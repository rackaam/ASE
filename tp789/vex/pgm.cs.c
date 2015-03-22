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


/*********************************
            ENTRY SYMBOLS
*********************************/

extern unsigned int load_pgm( unsigned int, unsigned int, unsigned int, unsigned int );
extern unsigned int save_pgm( unsigned int, unsigned int, unsigned int, unsigned int );
extern  __assert(  );
extern  exit(  );
extern  strcmp(  );
extern  __swbuf(  );
extern  __srget(  );
extern  fopen(  );
extern  sscanf(  );
extern  printf(  );
extern  fscanf(  );
extern  fprintf(  );
extern  fflush(  );
extern  fclose(  );

/*********************************
            DATA SYMBOLS
*********************************/

static unsigned int _X1STRINGPACKETX7[4]; 
static unsigned int _X1STRINGPACKETX14[4]; 
static unsigned int _X1STRINGPACKETX16[4]; 
static unsigned int _X1STRINGPACKETX17[6]; 
static unsigned int _X1STRINGPACKETX18[4]; 
static unsigned int _X1STRINGPACKETX20[4]; 
static unsigned int _X1STRINGPACKETX1[1]; 
static unsigned int _X1STRINGPACKETX2[1]; 
static unsigned int _X1STRINGPACKETX3[3]; 
static unsigned int _X1STRINGPACKETX4[1]; 
static unsigned int _X1STRINGPACKETX5[1]; 
static unsigned int _X1STRINGPACKETX6[1]; 
static unsigned int _X1STRINGPACKETX8[1]; 
static unsigned int _X1STRINGPACKETX9[3]; 
static unsigned int _X1STRINGPACKETX10[1]; 
static unsigned int _X1STRINGPACKETX11[3]; 
static unsigned int _X1STRINGPACKETX12[1]; 
static unsigned int _X1STRINGPACKETX13[3]; 
static unsigned int _X1STRINGPACKETX15[3]; 
static unsigned int _X1STRINGPACKETX19[3]; 
static unsigned int _X1STRINGPACKETX21[5]; 
static unsigned int _X1STRINGPACKETX23[8]; 
static unsigned int _X1STRINGPACKETX24[4]; 
static unsigned int _X1STRINGPACKETX25[4]; 
static unsigned int _X1STRINGPACKETX27[4]; 
static unsigned int _X1STRINGPACKETX28[6]; 
static unsigned int _X1STRINGPACKETX29[4]; 
static unsigned int _X1STRINGPACKETX31[4]; 
static unsigned int _X1STRINGPACKETX34[10]; 
static unsigned int _X1STRINGPACKETX22[1]; 
static unsigned int _X1STRINGPACKETX26[3]; 
static unsigned int _X1STRINGPACKETX30[3]; 
static unsigned int _X1STRINGPACKETX32[5]; 
static unsigned int _X1STRINGPACKETX33[11]; 
unsigned int verbose[1]; 
extern unsigned int _impure_ptr[];
static unsigned int _X1STRINGPACKETX7[4] = { 
	0x636F6D6D,
	0x656E7420,
	0x3A202573,
	0x0A000000
}; 

static unsigned int _X1STRINGPACKETX14[4] = { 
	0x2E2E2F73,
	0x72632F2F,
	0x70676D2E,
	0x63000000
}; 

static unsigned int _X1STRINGPACKETX16[4] = { 
	0x2E2E2F73,
	0x72632F2F,
	0x70676D2E,
	0x63000000
}; 

static unsigned int _X1STRINGPACKETX17[6] = { 
	0x2A686569,
	0x67687420,
	0x3C3D204D,
	0x41585F48,
	0x45494748,
	0x54000000
}; 

static unsigned int _X1STRINGPACKETX18[4] = { 
	0x2E2E2F73,
	0x72632F2F,
	0x70676D2E,
	0x63000000
}; 

static unsigned int _X1STRINGPACKETX20[4] = { 
	0x2E2E2F73,
	0x72632F2F,
	0x70676D2E,
	0x63000000
}; 

static unsigned int _X1STRINGPACKETX1[1] = { 
	0x72000000
}; 

static unsigned int _X1STRINGPACKETX2[1] = { 
	0x25730000
}; 

static unsigned int _X1STRINGPACKETX3[3] = { 
	0x68656164,
	0x65722025,
	0x730A0000
}; 

static unsigned int _X1STRINGPACKETX4[1] = { 
	0x50350000
}; 

static unsigned int _X1STRINGPACKETX5[1] = { 
	0x25730000
}; 

static unsigned int _X1STRINGPACKETX6[1] = { 
	0x25730000
}; 

static unsigned int _X1STRINGPACKETX8[1] = { 
	0x25750000
}; 

static unsigned int _X1STRINGPACKETX9[3] = { 
	0x77696474,
	0x683D2025,
	0x750A0000
}; 

static unsigned int _X1STRINGPACKETX10[1] = { 
	0x25750000
}; 

static unsigned int _X1STRINGPACKETX11[3] = { 
	0x68656967,
	0x68743D20,
	0x25750A00
}; 

static unsigned int _X1STRINGPACKETX12[1] = { 
	0x25750000
}; 

static unsigned int _X1STRINGPACKETX13[3] = { 
	0x64657074,
	0x683D2025,
	0x750A0000
}; 

static unsigned int _X1STRINGPACKETX15[3] = { 
	0x2A686569,
	0x67687420,
	0x3E203000
}; 

static unsigned int _X1STRINGPACKETX19[3] = { 
	0x2A776964,
	0x7468203E,
	0x20300000
}; 

static unsigned int _X1STRINGPACKETX21[5] = { 
	0x2A776964,
	0x7468203C,
	0x3D204D41,
	0x585F5749,
	0x44544800
}; 

static unsigned int _X1STRINGPACKETX23[8] = { 
	0x53617669,
	0x6E672069,
	0x6D616765,
	0x20257320,
	0x28773D25,
	0x75207820,
	0x683D2575,
	0x290A0000
}; 

static unsigned int _X1STRINGPACKETX24[4] = { 
	0x50350A25,
	0x75202575,
	0x0A203235,
	0x350A0000
}; 

static unsigned int _X1STRINGPACKETX25[4] = { 
	0x2E2E2F73,
	0x72632F2F,
	0x70676D2E,
	0x63000000
}; 

static unsigned int _X1STRINGPACKETX27[4] = { 
	0x2E2E2F73,
	0x72632F2F,
	0x70676D2E,
	0x63000000
}; 

static unsigned int _X1STRINGPACKETX28[6] = { 
	0x68656967,
	0x6874203C,
	0x3D204D41,
	0x585F4845,
	0x49474854,
	0x00000000
}; 

static unsigned int _X1STRINGPACKETX29[4] = { 
	0x2E2E2F73,
	0x72632F2F,
	0x70676D2E,
	0x63000000
}; 

static unsigned int _X1STRINGPACKETX31[4] = { 
	0x2E2E2F73,
	0x72632F2F,
	0x70676D2E,
	0x63000000
}; 

static unsigned int _X1STRINGPACKETX34[10] = { 
	0x436F756C,
	0x64206E6F,
	0x74206F70,
	0x656E2066,
	0x696C6520,
	0x25732069,
	0x6E207265,
	0x6164206D,
	0x6F64650A,
	0x00000000
}; 

static unsigned int _X1STRINGPACKETX22[1] = { 
	0x77000000
}; 

static unsigned int _X1STRINGPACKETX26[3] = { 
	0x68656967,
	0x6874203E,
	0x20300000
}; 

static unsigned int _X1STRINGPACKETX30[3] = { 
	0x77696474,
	0x68203E20,
	0x30000000
}; 

static unsigned int _X1STRINGPACKETX32[5] = { 
	0x77696474,
	0x68203C3D,
	0x204D4158,
	0x5F574944,
	0x54480000
}; 

static unsigned int _X1STRINGPACKETX33[11] = { 
	0x4572726F,
	0x72206475,
	0x72696E67,
	0x20696D61,
	0x67652077,
	0x72697465,
	0x20286174,
	0x20683D25,
	0x642C773D,
	0x2564290A,
	0x00000000
}; 

unsigned int verbose[1] = { 
	0x00000001
}; 


/*********************************
            TEXT
*********************************/
extern unsigned int sim_create_stack(unsigned int, unsigned int);
extern void sim_check_stack(unsigned int, unsigned int);
extern void sim_bad_label(int);
extern unsigned int reg_b0_0;
extern unsigned int reg_b0_1;
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
extern unsigned int reg_r0_57;
extern unsigned int reg_r0_58;
extern unsigned int reg_r0_59;
extern unsigned int reg_r0_60;
extern unsigned int reg_r0_61;
extern unsigned int reg_r0_62;
extern unsigned int reg_r0_63;


extern unsigned int load_pgm( unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   ENTRY(load_pgm);
  sim_check_stack(reg_r0_1, -192); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_r0_5 =  arg2; 
  reg_r0_6 =  arg3; 
  reg_l0_0 = (174 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(0 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_1, reg_r0_1, (unsigned int) -192); /* line 22 */
} /* line 22 */
  sim_icache_fetch(1 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 148),0,4), reg_l0_0); /* line 24 */
} /* line 24 */
  sim_icache_fetch(2 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 180),0,4), reg_r0_4); /* line 26 */
} /* line 26 */
  sim_icache_fetch(3 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 184),0,4), reg_r0_5); /* line 28 */
} /* line 28 */
  sim_icache_fetch(4 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 188),0,4), reg_r0_6); /* line 30 */
} /* line 30 */
  sim_icache_fetch(5 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 152),0,4), reg_r0_63); /* line 32 */
} /* line 32 */
  sim_icache_fetch(6 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 156),0,4), reg_r0_62); /* line 34 */
} /* line 34 */
  sim_icache_fetch(7 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 160),0,4), reg_r0_61); /* line 36 */
} /* line 36 */
  sim_icache_fetch(8 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 164),0,4), reg_r0_60); /* line 38 */
} /* line 38 */
  sim_icache_fetch(9 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 168),0,4), reg_r0_59); /* line 40 */
} /* line 40 */
  sim_icache_fetch(10 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 172),0,4), reg_r0_58); /* line 42 */
} /* line 42 */
  sim_icache_fetch(11 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 176),0,4), reg_r0_57); /* line 44 */
} /* line 44 */
  sim_icache_fetch(12 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_1, (unsigned int) 16); /* line 46 */
} /* line 46 */
  sim_icache_fetch(13 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX1); /* line 48 */
} /* line 48 */
		 /* line 49 */
  sim_icache_fetch(15 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fopen);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fopen;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 51 */
l_lr_1: ;/* line 51 */
LABEL(l_lr_1);
  sim_icache_fetch(17 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_3, 0); /* line 53 */
} /* line 53 */
  sim_icache_fetch(18 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_62, reg_r0_1, (unsigned int) 144); /* line 55 */
} /* line 55 */
  sim_icache_fetch(19 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, 0); /* line 57 */
} /* line 57 */
  sim_icache_fetch(20 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, reg_r0_3); /* line 59 */
} /* line 59 */
  sim_icache_fetch(21 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 180),0,4)); /* line 61 */
} /* line 61 */
  sim_icache_fetch(22 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 184),0,4)); /* line 63 */
} /* line 63 */
  sim_icache_fetch(23 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 188),0,4)); /* line 65 */
} /* line 65 */
  sim_icache_fetch(24 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 144),0,4), 0); /* line 67 */
} /* line 67 */
  sim_icache_fetch(25 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L0X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 69 */
l_L1X3: ;/* line 72 */
LABEL(l_L1X3);
  sim_icache_fetch(26 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_57, (unsigned int) 5); /* line 73 */
} /* line 73 */
  sim_icache_fetch(27 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPEQ(reg_b0_1, reg_r0_57, 0); /* line 75 */
} /* line 75 */
  sim_icache_fetch(28 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 77 */
  sim_icache_fetch(29 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L3X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 79 */
  sim_icache_fetch(30 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX2); /* line 81 */
} /* line 81 */
  sim_icache_fetch(32 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 83 */
} /* line 83 */
  sim_icache_fetch(33 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_58); /* line 85 */
} /* line 85 */
		 /* line 86 */
  sim_icache_fetch(34 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fscanf);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fscanf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 88 */
l_lr_4: ;/* line 88 */
LABEL(l_lr_4);
  sim_icache_fetch(36 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((unsigned int) verbose,0,4)); /* line 90 */
} /* line 90 */
  sim_icache_fetch(38 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 92 */
} /* line 92 */
  sim_icache_fetch(40 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_58); /* line 94 */
} /* line 94 */
  sim_icache_fetch(41 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_2, 0); /* line 96 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 97 */
   ADD_CYCLES(1);
} /* line 97 */
  sim_icache_fetch(43 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L4X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 99 */
		 /* line 100 */
  sim_icache_fetch(44 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 102 */
l_lr_6: ;/* line 102 */
LABEL(l_lr_6);
l_L4X3: ;/* line 104 */
LABEL(l_L4X3);
  sim_icache_fetch(46 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 105 */
} /* line 105 */
  sim_icache_fetch(48 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_58); /* line 107 */
} /* line 107 */
		 /* line 108 */
  sim_icache_fetch(49 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(strcmp);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) strcmp;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 110 */
l_lr_9: ;/* line 110 */
LABEL(l_lr_9);
  sim_icache_fetch(51 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 112 */
} /* line 112 */
  sim_icache_fetch(52 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX5); /* line 114 */
} /* line 114 */
  sim_icache_fetch(54 + t_thisfile.offset, 1);
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
} /* line 116 */
  sim_icache_fetch(55 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, (unsigned int) 1); /* line 118 */
} /* line 118 */
  sim_icache_fetch(56 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 120 */
} /* line 120 */
  sim_icache_fetch(57 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_58); /* line 122 */
} /* line 122 */
		 /* line 123 */
  sim_icache_fetch(58 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fscanf);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fscanf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 125 */
l_lr_11: ;/* line 125 */
LABEL(l_lr_11);
  sim_icache_fetch(60 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 127 */
l_L5X3: ;/* line 130 */
LABEL(l_L5X3);
  sim_icache_fetch(61 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) -1); /* line 131 */
} /* line 131 */
		 /* line 132 */
  sim_icache_fetch(62 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(exit);
   reg_l0_0 = (174 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) exit;
    (*t_call)(reg_r0_3);
   }
} /* line 135 */
l_lr_14: ;/* line 135 */
LABEL(l_lr_14);
  sim_icache_fetch(64 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 137 */
l_L3X3: ;/* line 140 */
LABEL(l_L3X3);
  sim_icache_fetch(65 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPEQ(reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 141 */
} /* line 141 */
  sim_icache_fetch(66 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBs(reg_r0_6, mem_trace_ld(reg_r0_58,0,1)); /* line 143 */
} /* line 143 */
  sim_icache_fetch(67 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 145 */
  sim_icache_fetch(68 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX6); /* line 147 */
} /* line 147 */
  sim_icache_fetch(70 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPEQ(reg_b0_0, reg_r0_6, (unsigned int) 35); /* line 149 */
} /* line 149 */
  sim_icache_fetch(71 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 151 */
} /* line 151 */
  sim_icache_fetch(72 + t_thisfile.offset, 1);
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
} /* line 153 */
  sim_icache_fetch(73 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_58); /* line 155 */
} /* line 155 */
		 /* line 156 */
  sim_icache_fetch(74 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fscanf);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fscanf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 158 */
l_lr_17: ;/* line 158 */
LABEL(l_lr_17);
  sim_icache_fetch(76 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((unsigned int) verbose,0,4)); /* line 160 */
} /* line 160 */
  sim_icache_fetch(78 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX7); /* line 162 */
} /* line 162 */
  sim_icache_fetch(80 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_58); /* line 164 */
} /* line 164 */
  sim_icache_fetch(81 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_5, 0); /* line 166 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 167 */
   ADD_CYCLES(1);
} /* line 167 */
  sim_icache_fetch(83 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L8X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 169 */
		 /* line 170 */
  sim_icache_fetch(84 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 172 */
l_lr_19: ;/* line 172 */
LABEL(l_lr_19);
l_L8X3: ;/* line 174 */
LABEL(l_L8X3);
  sim_icache_fetch(86 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 174 */
l_L9X3: ;/* line 177 */
LABEL(l_L9X3);
  sim_icache_fetch(87 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_59 + (unsigned int) 4),0,4)); /* line 178 */
} /* line 178 */
  sim_icache_fetch(88 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 180 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 181 */
   ADD_CYCLES(1);
} /* line 181 */
  sim_icache_fetch(90 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 183 */
} /* line 183 */
  sim_icache_fetch(91 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 185 */
} /* line 185 */
  sim_icache_fetch(92 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_59 + (unsigned int) 4),0,4), reg_r0_2); /* line 187 */
} /* line 187 */
  sim_icache_fetch(93 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L10X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 189 */
		 /* line 190 */
  sim_icache_fetch(94 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__srget);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) __srget;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 192 */
l_lr_23: ;/* line 192 */
LABEL(l_lr_23);
  sim_icache_fetch(96 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 194 */
l_L11X3: ;/* line 196 */
LABEL(l_L11X3);
  sim_icache_fetch(97 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_3, (unsigned int) 10); /* line 197 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 198 */
   ADD_CYCLES(1);
} /* line 198 */
  sim_icache_fetch(99 + t_thisfile.offset, 1);
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
} /* line 201 */
  sim_icache_fetch(100 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L9X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L9X3;
} /* line 203 */
l_L7X3: ;/* line 206 */
LABEL(l_L7X3);
  sim_icache_fetch(101 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, (unsigned int) 2); /* line 208 */
} /* line 208 */
  sim_icache_fetch(102 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 210 */
l_L10X3: ;/* line 213 */
LABEL(l_L10X3);
  sim_icache_fetch(103 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld(reg_r0_59,0,4)); /* line 214 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 215 */
   ADD_CYCLES(2);
} /* line 215 */
  sim_icache_fetch(105 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 217 */
} /* line 217 */
  sim_icache_fetch(106 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_59,0,4), reg_r0_4); /* line 219 */
} /* line 219 */
  sim_icache_fetch(107 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 221 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 222 */
   ADD_CYCLES(1);
} /* line 222 */
  sim_icache_fetch(109 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L11X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L11X3;
} /* line 224 */
l_L6X3: ;/* line 227 */
LABEL(l_L6X3);
  sim_icache_fetch(110 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPEQ(reg_b0_0, reg_r0_57, (unsigned int) 2); /* line 228 */
} /* line 228 */
  sim_icache_fetch(111 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX8); /* line 230 */
} /* line 230 */
  sim_icache_fetch(113 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L12X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 232 */
  sim_icache_fetch(114 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_58); /* line 234 */
} /* line 234 */
  sim_icache_fetch(115 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_60); /* line 236 */
} /* line 236 */
		 /* line 237 */
  sim_icache_fetch(116 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(sscanf);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) sscanf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 239 */
l_lr_29: ;/* line 239 */
LABEL(l_lr_29);
  sim_icache_fetch(118 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((unsigned int) verbose,0,4)); /* line 241 */
} /* line 241 */
  sim_icache_fetch(120 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_60,0,4)); /* line 243 */
} /* line 243 */
  sim_icache_fetch(121 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 245 */
} /* line 245 */
  sim_icache_fetch(123 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_5, 0); /* line 247 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 248 */
   ADD_CYCLES(1);
} /* line 248 */
  sim_icache_fetch(125 + t_thisfile.offset, 1);
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
} /* line 250 */
		 /* line 251 */
  sim_icache_fetch(126 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 253 */
l_lr_31: ;/* line 253 */
LABEL(l_lr_31);
l_L13X3: ;/* line 255 */
LABEL(l_L13X3);
  sim_icache_fetch(128 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, (unsigned int) 3); /* line 257 */
} /* line 257 */
  sim_icache_fetch(129 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 259 */
l_L12X3: ;/* line 262 */
LABEL(l_L12X3);
  sim_icache_fetch(130 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPEQ(reg_b0_0, reg_r0_57, (unsigned int) 3); /* line 263 */
} /* line 263 */
  sim_icache_fetch(131 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX10); /* line 265 */
} /* line 265 */
  sim_icache_fetch(133 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L14X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 267 */
  sim_icache_fetch(134 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 269 */
} /* line 269 */
  sim_icache_fetch(135 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_61); /* line 271 */
} /* line 271 */
		 /* line 272 */
  sim_icache_fetch(136 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fscanf);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fscanf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 274 */
l_lr_35: ;/* line 274 */
LABEL(l_lr_35);
  sim_icache_fetch(138 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((unsigned int) verbose,0,4)); /* line 276 */
} /* line 276 */
  sim_icache_fetch(140 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_61,0,4)); /* line 278 */
} /* line 278 */
  sim_icache_fetch(141 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX11); /* line 280 */
} /* line 280 */
  sim_icache_fetch(143 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_5, 0); /* line 282 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 283 */
   ADD_CYCLES(1);
} /* line 283 */
  sim_icache_fetch(145 + t_thisfile.offset, 1);
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
} /* line 285 */
		 /* line 286 */
  sim_icache_fetch(146 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 288 */
l_lr_37: ;/* line 288 */
LABEL(l_lr_37);
l_L15X3: ;/* line 290 */
LABEL(l_L15X3);
  sim_icache_fetch(148 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, (unsigned int) 4); /* line 292 */
} /* line 292 */
  sim_icache_fetch(149 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 294 */
l_L14X3: ;/* line 297 */
LABEL(l_L14X3);
  sim_icache_fetch(150 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPEQ(reg_b0_0, reg_r0_57, (unsigned int) 4); /* line 298 */
} /* line 298 */
  sim_icache_fetch(151 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX12); /* line 300 */
} /* line 300 */
  sim_icache_fetch(153 + t_thisfile.offset, 1);
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
} /* line 302 */
  sim_icache_fetch(154 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 304 */
} /* line 304 */
  sim_icache_fetch(155 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_62); /* line 306 */
} /* line 306 */
		 /* line 307 */
  sim_icache_fetch(156 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fscanf);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fscanf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 309 */
l_lr_41: ;/* line 309 */
LABEL(l_lr_41);
  sim_icache_fetch(158 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((unsigned int) verbose,0,4)); /* line 311 */
} /* line 311 */
  sim_icache_fetch(160 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 144),0,4)); /* line 313 */
} /* line 313 */
  sim_icache_fetch(161 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX13); /* line 315 */
} /* line 315 */
  sim_icache_fetch(163 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_5, 0); /* line 317 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 318 */
   ADD_CYCLES(1);
} /* line 318 */
  sim_icache_fetch(165 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L16X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 320 */
		 /* line 321 */
  sim_icache_fetch(166 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 323 */
l_lr_43: ;/* line 323 */
LABEL(l_lr_43);
l_L16X3: ;/* line 325 */
LABEL(l_L16X3);
  sim_icache_fetch(168 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, (unsigned int) 5); /* line 327 */
} /* line 327 */
  sim_icache_fetch(169 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 329 */
l_L2X3: ;/* line 332 */
LABEL(l_L2X3);
  sim_icache_fetch(170 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld(reg_r0_61,0,4)); /* line 333 */
} /* line 333 */
  sim_icache_fetch(171 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld(reg_r0_61,0,4)); /* line 335 */
} /* line 335 */
  sim_icache_fetch(172 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_60,0,4)); /* line 337 */
} /* line 337 */
  sim_icache_fetch(173 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, 0); /* line 339 */
} /* line 339 */
  sim_icache_fetch(174 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLE(reg_b0_1, reg_r0_7, (unsigned int) 1050); /* line 341 */
} /* line 341 */
  sim_icache_fetch(176 + t_thisfile.offset, 1);
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
} /* line 343 */
l_L18X3: ;/* line 345 */
LABEL(l_L18X3);
  sim_icache_fetch(177 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 346 */
l_L20X3: ;/* line 348 */
LABEL(l_L20X3);
  sim_icache_fetch(178 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_8, 0); /* line 349 */
} /* line 349 */
  sim_icache_fetch(179 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_60,0,4)); /* line 351 */
} /* line 351 */
  sim_icache_fetch(180 + t_thisfile.offset, 1);
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
} /* line 353 */
l_L22X3: ;/* line 355 */
LABEL(l_L22X3);
  sim_icache_fetch(181 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_63); /* line 356 */
} /* line 356 */
  sim_icache_fetch(182 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLE(reg_b0_0, reg_r0_3, (unsigned int) 1500); /* line 358 */
} /* line 358 */
  sim_icache_fetch(184 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 360 */
} /* line 360 */
  sim_icache_fetch(185 + t_thisfile.offset, 1);
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
} /* line 362 */
l_L24X3: ;/* line 364 */
LABEL(l_L24X3);
  sim_icache_fetch(186 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_61); /* line 365 */
} /* line 365 */
  sim_icache_fetch(187 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, reg_r0_60); /* line 367 */
} /* line 367 */
l_L25X3: ;/* line 370 */
LABEL(l_L25X3);
  sim_icache_fetch(188 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 371 */
} /* line 371 */
  sim_icache_fetch(189 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, reg_r0_5); /* line 373 */
} /* line 373 */
  sim_icache_fetch(190 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, 0); /* line 375 */
} /* line 375 */
  sim_icache_fetch(191 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_4, reg_r0_3); /* line 377 */
} /* line 377 */
  sim_icache_fetch(192 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, reg_r0_2); /* line 379 */
} /* line 379 */
  sim_icache_fetch(193 + t_thisfile.offset, 1);
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
} /* line 381 */
  sim_icache_fetch(194 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_62, reg_r0_4); /* line 383 */
} /* line 383 */
  sim_icache_fetch(195 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, reg_r0_5); /* line 385 */
} /* line 385 */
l_L27X3: ;/* line 388 */
LABEL(l_L27X3);
  sim_icache_fetch(196 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld(reg_r0_57,0,4)); /* line 389 */
} /* line 389 */
  sim_icache_fetch(197 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_59 + (unsigned int) 4),0,4)); /* line 391 */
} /* line 391 */
  sim_icache_fetch(198 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 393 */
} /* line 393 */
  sim_icache_fetch(199 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, reg_r0_2); /* line 395 */
} /* line 395 */
  sim_icache_fetch(200 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) -1); /* line 397 */
} /* line 397 */
  sim_icache_fetch(201 + t_thisfile.offset, 1);
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
} /* line 399 */
  sim_icache_fetch(202 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 401 */
} /* line 401 */
  sim_icache_fetch(203 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_59 + (unsigned int) 4),0,4), reg_r0_4); /* line 403 */
} /* line 403 */
  sim_icache_fetch(204 + t_thisfile.offset, 1);
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
} /* line 405 */
		 /* line 406 */
  sim_icache_fetch(205 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__srget);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) __srget;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 408 */
l_lr_53: ;/* line 408 */
LABEL(l_lr_53);
  sim_icache_fetch(207 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 410 */
l_L30X3: ;/* line 412 */
LABEL(l_L30X3);
  sim_icache_fetch(208 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 413 */
} /* line 413 */
  sim_icache_fetch(209 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_60,0,1), reg_r0_3); /* line 415 */
} /* line 415 */
  sim_icache_fetch(210 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1050); /* line 418 */
} /* line 418 */
  sim_icache_fetch(212 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L27X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L27X3;
} /* line 420 */
l_L29X3: ;/* line 423 */
LABEL(l_L29X3);
  sim_icache_fetch(213 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld(reg_r0_59,0,4)); /* line 424 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 425 */
   ADD_CYCLES(2);
} /* line 425 */
  sim_icache_fetch(215 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 427 */
} /* line 427 */
  sim_icache_fetch(216 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_59,0,4), reg_r0_4); /* line 429 */
} /* line 429 */
  sim_icache_fetch(217 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 431 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 432 */
   ADD_CYCLES(1);
} /* line 432 */
  sim_icache_fetch(219 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L30X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L30X3;
} /* line 434 */
l_L28X3: ;/* line 437 */
LABEL(l_L28X3);
  sim_icache_fetch(220 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_63, (unsigned int) 1); /* line 438 */
} /* line 438 */
  sim_icache_fetch(221 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_62, (unsigned int) 1); /* line 440 */
} /* line 440 */
  sim_icache_fetch(222 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_61); /* line 443 */
} /* line 443 */
  sim_icache_fetch(223 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L25X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L25X3;
} /* line 445 */
l_L26X3: ;/* line 448 */
LABEL(l_L26X3);
  sim_icache_fetch(224 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 449 */
} /* line 449 */
		 /* line 450 */
  sim_icache_fetch(225 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fclose);
   reg_l0_0 = (174 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) fclose;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 452 */
l_lr_59: ;/* line 452 */
LABEL(l_lr_59);
  sim_icache_fetch(227 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 148),0,4)); /* line 454 */
} /* line 454 */
  sim_icache_fetch(228 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 456 */
} /* line 456 */
  sim_icache_fetch(229 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 152),0,4)); /* line 458 */
} /* line 458 */
  sim_icache_fetch(230 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 156),0,4)); /* line 460 */
} /* line 460 */
  sim_icache_fetch(231 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 160),0,4)); /* line 462 */
} /* line 462 */
  sim_icache_fetch(232 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 164),0,4)); /* line 464 */
} /* line 464 */
  sim_icache_fetch(233 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 168),0,4)); /* line 466 */
} /* line 466 */
  sim_icache_fetch(234 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 172),0,4)); /* line 468 */
} /* line 468 */
  sim_icache_fetch(235 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 176),0,4)); /* line 470 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 471 */
   ADD_CYCLES(1);
} /* line 471 */
  sim_icache_fetch(237 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(load_pgm);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 192; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 474 */
l_L23X3: ;/* line 477 */
LABEL(l_L23X3);
  sim_icache_fetch(238 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX21); /* line 478 */
} /* line 478 */
  sim_icache_fetch(240 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 82); /* line 480 */
} /* line 480 */
  sim_icache_fetch(241 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX20); /* line 482 */
} /* line 482 */
		 /* line 483 */
  sim_icache_fetch(243 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (174 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 485 */
l_lr_62: ;/* line 485 */
LABEL(l_lr_62);
  sim_icache_fetch(245 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_63); /* line 487 */
} /* line 487 */
  sim_icache_fetch(246 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 490 */
} /* line 490 */
  sim_icache_fetch(247 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L24X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L24X3;
} /* line 492 */
l_L21X3: ;/* line 495 */
LABEL(l_L21X3);
  sim_icache_fetch(248 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX19); /* line 496 */
} /* line 496 */
  sim_icache_fetch(250 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 81); /* line 498 */
} /* line 498 */
  sim_icache_fetch(251 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX18); /* line 500 */
} /* line 500 */
		 /* line 501 */
  sim_icache_fetch(253 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (174 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 503 */
l_lr_65: ;/* line 503 */
LABEL(l_lr_65);
  sim_icache_fetch(255 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_60,0,4)); /* line 505 */
} /* line 505 */
  sim_icache_fetch(256 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L22X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L22X3;
} /* line 507 */
l_L19X3: ;/* line 510 */
LABEL(l_L19X3);
  sim_icache_fetch(257 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX17); /* line 511 */
} /* line 511 */
  sim_icache_fetch(259 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 80); /* line 513 */
} /* line 513 */
  sim_icache_fetch(260 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX16); /* line 515 */
} /* line 515 */
		 /* line 516 */
  sim_icache_fetch(262 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (174 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 518 */
l_lr_68: ;/* line 518 */
LABEL(l_lr_68);
  sim_icache_fetch(264 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_8, mem_trace_ld(reg_r0_60,0,4)); /* line 520 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 521 */
   ADD_CYCLES(1);
} /* line 521 */
  sim_icache_fetch(266 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L20X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L20X3;
} /* line 523 */
l_L17X3: ;/* line 526 */
LABEL(l_L17X3);
  sim_icache_fetch(267 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX15); /* line 527 */
} /* line 527 */
  sim_icache_fetch(269 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 79); /* line 529 */
} /* line 529 */
  sim_icache_fetch(270 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX14); /* line 531 */
} /* line 531 */
		 /* line 532 */
  sim_icache_fetch(272 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (174 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 534 */
l_lr_71: ;/* line 534 */
LABEL(l_lr_71);
  sim_icache_fetch(274 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_7, mem_trace_ld(reg_r0_61,0,4)); /* line 536 */
} /* line 536 */
  sim_icache_fetch(275 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_60,0,4)); /* line 538 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 539 */
   ADD_CYCLES(1);
} /* line 539 */
  sim_icache_fetch(277 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLE(reg_b0_1, reg_r0_7, (unsigned int) 1050); /* line 541 */
} /* line 541 */
  sim_icache_fetch(279 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L18X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L18X3;
} /* line 543 */
l_L0X3: ;/* line 546 */
LABEL(l_L0X3);
  sim_icache_fetch(280 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 148),0,4)); /* line 547 */
} /* line 547 */
  sim_icache_fetch(281 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) -1); /* line 549 */
} /* line 549 */
  sim_icache_fetch(282 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 152),0,4)); /* line 551 */
} /* line 551 */
  sim_icache_fetch(283 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 156),0,4)); /* line 553 */
} /* line 553 */
  sim_icache_fetch(284 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 160),0,4)); /* line 555 */
} /* line 555 */
  sim_icache_fetch(285 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 164),0,4)); /* line 557 */
} /* line 557 */
  sim_icache_fetch(286 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 168),0,4)); /* line 559 */
} /* line 559 */
  sim_icache_fetch(287 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 172),0,4)); /* line 561 */
} /* line 561 */
  sim_icache_fetch(288 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 176),0,4)); /* line 563 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 564 */
   ADD_CYCLES(1);
} /* line 564 */
  sim_icache_fetch(290 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(load_pgm);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 192; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 567 */
  reg_l0_0 = t_client_rpc;
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 102: goto l_lr_1;
    case 103: goto l_L1X3;
    case 105: goto l_lr_4;
    case 107: goto l_lr_6;
    case 108: goto l_L4X3;
    case 110: goto l_lr_9;
    case 112: goto l_lr_11;
    case 113: goto l_L5X3;
    case 115: goto l_lr_14;
    case 116: goto l_L3X3;
    case 118: goto l_lr_17;
    case 120: goto l_lr_19;
    case 121: goto l_L8X3;
    case 122: goto l_L9X3;
    case 124: goto l_lr_23;
    case 125: goto l_L11X3;
    case 126: goto l_L7X3;
    case 127: goto l_L10X3;
    case 128: goto l_L6X3;
    case 130: goto l_lr_29;
    case 132: goto l_lr_31;
    case 133: goto l_L13X3;
    case 134: goto l_L12X3;
    case 136: goto l_lr_35;
    case 138: goto l_lr_37;
    case 139: goto l_L15X3;
    case 140: goto l_L14X3;
    case 142: goto l_lr_41;
    case 144: goto l_lr_43;
    case 145: goto l_L16X3;
    case 146: goto l_L2X3;
    case 147: goto l_L18X3;
    case 148: goto l_L20X3;
    case 149: goto l_L22X3;
    case 150: goto l_L24X3;
    case 151: goto l_L25X3;
    case 152: goto l_L27X3;
    case 154: goto l_lr_53;
    case 155: goto l_L30X3;
    case 156: goto l_L29X3;
    case 157: goto l_L28X3;
    case 158: goto l_L26X3;
    case 160: goto l_lr_59;
    case 161: goto l_L23X3;
    case 163: goto l_lr_62;
    case 164: goto l_L21X3;
    case 166: goto l_lr_65;
    case 167: goto l_L19X3;
    case 169: goto l_lr_68;
    case 170: goto l_L17X3;
    case 172: goto l_lr_71;
    case 173: goto l_L0X3;
    case 174:
      reg_l0_0 = t_client_rpc;
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}

extern unsigned int save_pgm( unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3 )
{
  unsigned int t_client_rpc;
  int t_labelnum;
  unsigned int t_bitbucket;
  static int sim_gprof_idx = 0;
   ENTRY(save_pgm);
  sim_check_stack(reg_r0_1, -96); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_r0_5 =  arg2; 
  reg_r0_6 =  arg3; 
  reg_l0_0 = (226 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(291 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_1, reg_r0_1, (unsigned int) -96); /* line 831 */
} /* line 831 */
  sim_icache_fetch(292 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 833 */
} /* line 833 */
  sim_icache_fetch(293 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 52),0,4), reg_r0_6); /* line 835 */
} /* line 835 */
  sim_icache_fetch(294 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_63); /* line 837 */
} /* line 837 */
  sim_icache_fetch(295 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_62); /* line 839 */
} /* line 839 */
  sim_icache_fetch(296 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_61); /* line 841 */
} /* line 841 */
  sim_icache_fetch(297 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_60); /* line 843 */
} /* line 843 */
  sim_icache_fetch(298 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_59); /* line 845 */
} /* line 845 */
  sim_icache_fetch(299 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_58); /* line 847 */
} /* line 847 */
  sim_icache_fetch(300 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 48),0,4), reg_r0_57); /* line 849 */
} /* line 849 */
  sim_icache_fetch(301 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 56),0,4), reg_r0_5); /* line 851 */
} /* line 851 */
  sim_icache_fetch(302 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_4); /* line 853 */
} /* line 853 */
  sim_icache_fetch(303 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 64),0,4), reg_r0_3); /* line 855 */
} /* line 855 */
  sim_icache_fetch(304 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX22); /* line 857 */
} /* line 857 */
		 /* line 858 */
  sim_icache_fetch(306 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fopen);
   reg_l0_0 = (226 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fopen;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 860 */
l_lr_75: ;/* line 860 */
LABEL(l_lr_75);
  sim_icache_fetch(308 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 68),0,4), reg_r0_3); /* line 862 */
} /* line 862 */
  sim_icache_fetch(309 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 864 */
} /* line 864 */
  sim_icache_fetch(310 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 866 */
} /* line 866 */
  sim_icache_fetch(311 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 64),0,4)); /* line 868 */
} /* line 868 */
  sim_icache_fetch(312 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX23); /* line 870 */
} /* line 870 */
		 /* line 871 */
  sim_icache_fetch(314 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (226 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 873 */
l_lr_77: ;/* line 873 */
LABEL(l_lr_77);
  sim_icache_fetch(316 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 875 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 876 */
   ADD_CYCLES(2);
} /* line 876 */
  sim_icache_fetch(319 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_5 + (unsigned int) 8),0,4)); /* line 878 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 879 */
   ADD_CYCLES(1);
} /* line 879 */
		 /* line 880 */
  sim_icache_fetch(321 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fflush);
   reg_l0_0 = (226 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) fflush;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 882 */
l_lr_79: ;/* line 882 */
LABEL(l_lr_79);
  sim_icache_fetch(323 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 884 */
} /* line 884 */
  sim_icache_fetch(324 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 886 */
} /* line 886 */
  sim_icache_fetch(325 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 888 */
} /* line 888 */
  sim_icache_fetch(326 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_3, 0); /* line 890 */
} /* line 890 */
  sim_icache_fetch(327 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX24); /* line 892 */
} /* line 892 */
  sim_icache_fetch(329 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L31X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 894 */
		 /* line 895 */
  sim_icache_fetch(330 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fprintf);
   reg_l0_0 = (226 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fprintf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 897 */
l_lr_81: ;/* line 897 */
LABEL(l_lr_81);
  sim_icache_fetch(332 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 899 */
} /* line 899 */
  sim_icache_fetch(333 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 901 */
} /* line 901 */
  sim_icache_fetch(334 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, 0); /* line 903 */
} /* line 903 */
  sim_icache_fetch(335 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_5, 0); /* line 905 */
} /* line 905 */
  sim_icache_fetch(336 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLE(reg_b0_1, reg_r0_5, (unsigned int) 1050); /* line 907 */
} /* line 907 */
  sim_icache_fetch(338 + t_thisfile.offset, 1);
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
} /* line 909 */
l_L33X3: ;/* line 911 */
LABEL(l_L33X3);
  sim_icache_fetch(339 + t_thisfile.offset, 1);
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
} /* line 912 */
l_L35X3: ;/* line 914 */
LABEL(l_L35X3);
  sim_icache_fetch(340 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, 0); /* line 915 */
} /* line 915 */
  sim_icache_fetch(341 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLE(reg_b0_1, reg_r0_3, (unsigned int) 1500); /* line 917 */
} /* line 917 */
  sim_icache_fetch(343 + t_thisfile.offset, 1);
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
} /* line 919 */
l_L37X3: ;/* line 921 */
LABEL(l_L37X3);
  sim_icache_fetch(344 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L38X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 922 */
l_L39X3: ;/* line 924 */
LABEL(l_L39X3);
  sim_icache_fetch(345 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_5, 0, reg_r0_5); /* line 925 */
} /* line 925 */
  sim_icache_fetch(346 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_5); /* line 927 */
} /* line 927 */
  sim_icache_fetch(347 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 929 */
} /* line 929 */
  sim_icache_fetch(348 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 931 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 932 */
   ADD_CYCLES(1);
} /* line 932 */
  sim_icache_fetch(350 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_6); /* line 934 */
} /* line 934 */
l_L40X3: ;/* line 937 */
LABEL(l_L40X3);
  sim_icache_fetch(351 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 938 */
} /* line 938 */
  sim_icache_fetch(352 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_4); /* line 940 */
} /* line 940 */
  sim_icache_fetch(353 + t_thisfile.offset, 1);
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
} /* line 942 */
  sim_icache_fetch(354 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_5, 0, reg_r0_3); /* line 944 */
} /* line 944 */
  sim_icache_fetch(355 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, reg_r0_5); /* line 946 */
} /* line 946 */
  sim_icache_fetch(356 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, reg_r0_4); /* line 948 */
} /* line 948 */
  sim_icache_fetch(357 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, 0); /* line 950 */
} /* line 950 */
  sim_icache_fetch(358 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_62, reg_r0_2); /* line 952 */
} /* line 952 */
  sim_icache_fetch(359 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, reg_r0_3); /* line 954 */
} /* line 954 */
l_L42X3: ;/* line 957 */
LABEL(l_L42X3);
  sim_icache_fetch(360 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_2, mem_trace_ld((reg_r0_57 + (unsigned int) 8),0,4)); /* line 958 */
} /* line 958 */
  sim_icache_fetch(361 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 960 */
} /* line 960 */
  sim_icache_fetch(362 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_57 + (unsigned int) 24),0,4)); /* line 962 */
} /* line 962 */
  sim_icache_fetch(363 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 964 */
} /* line 964 */
  sim_icache_fetch(364 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L43X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 966 */
  sim_icache_fetch(365 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 968 */
} /* line 968 */
  sim_icache_fetch(366 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_2, reg_r0_7); /* line 970 */
} /* line 970 */
  sim_icache_fetch(367 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_57,0,4)); /* line 972 */
} /* line 972 */
  sim_icache_fetch(368 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX33); /* line 974 */
} /* line 974 */
  sim_icache_fetch(370 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_60); /* line 976 */
} /* line 976 */
  sim_icache_fetch(371 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_61); /* line 978 */
} /* line 978 */
  sim_icache_fetch(372 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_57 + (unsigned int) 8),0,4), reg_r0_2); /* line 980 */
} /* line 980 */
  sim_icache_fetch(373 + t_thisfile.offset, 1);
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
} /* line 982 */
  sim_icache_fetch(374 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L45X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 984 */
  sim_icache_fetch(375 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_2, mem_trace_ld(reg_r0_59,0,1)); /* line 986 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 987 */
   ADD_CYCLES(2);
} /* line 987 */
  sim_icache_fetch(377 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_8,0,1), reg_r0_2); /* line 989 */
} /* line 989 */
  sim_icache_fetch(378 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld(reg_r0_57,0,4)); /* line 991 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 992 */
   ADD_CYCLES(2);
} /* line 992 */
  sim_icache_fetch(380 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_7, mem_trace_ld(reg_r0_2,0,1)); /* line 994 */
} /* line 994 */
  sim_icache_fetch(381 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 996 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 997 */
   ADD_CYCLES(1);
} /* line 997 */
  sim_icache_fetch(383 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_7, (unsigned int) 10); /* line 999 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1000 */
   ADD_CYCLES(1);
} /* line 1000 */
  sim_icache_fetch(385 + t_thisfile.offset, 1);
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
} /* line 1002 */
  sim_icache_fetch(386 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_57,0,4), reg_r0_8); /* line 1004 */
} /* line 1004 */
  sim_icache_fetch(387 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_2, mem_trace_ld(reg_r0_2,0,1)); /* line 1006 */
} /* line 1006 */
  sim_icache_fetch(388 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 1008 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1009 */
   ADD_CYCLES(1);
} /* line 1009 */
l_L47X3: ;/* line 1012 */
LABEL(l_L47X3);
  sim_icache_fetch(391 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 1012 */
l_L48X3: ;/* line 1015 */
LABEL(l_L48X3);
  sim_icache_fetch(392 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 1015 */
l_L49X3: ;/* line 1017 */
LABEL(l_L49X3);
  sim_icache_fetch(393 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 1018 */
} /* line 1018 */
  sim_icache_fetch(394 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) 12),0,4)); /* line 1020 */
} /* line 1020 */
  sim_icache_fetch(395 + t_thisfile.offset, 1);
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
} /* line 1022 */
		 /* line 1023 */
  sim_icache_fetch(396 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fprintf);
   reg_l0_0 = (226 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fprintf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 1025 */
l_lr_92: ;/* line 1025 */
LABEL(l_lr_92);
  sim_icache_fetch(398 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_57); /* line 1027 */
} /* line 1027 */
		 /* line 1028 */
  sim_icache_fetch(399 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fclose);
   reg_l0_0 = (226 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) fclose;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1030 */
l_lr_94: ;/* line 1030 */
LABEL(l_lr_94);
  sim_icache_fetch(401 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) -1); /* line 1032 */
} /* line 1032 */
		 /* line 1033 */
  sim_icache_fetch(402 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(exit);
   reg_l0_0 = (226 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) exit;
    (*t_call)(reg_r0_3);
   }
} /* line 1035 */
l_lr_96: ;/* line 1035 */
LABEL(l_lr_96);
l_L51X3: ;/* line 1037 */
LABEL(l_L51X3);
  sim_icache_fetch(404 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 1); /* line 1038 */
} /* line 1038 */
  sim_icache_fetch(405 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_59, reg_r0_59, (unsigned int) 1050); /* line 1040 */
} /* line 1040 */
  sim_icache_fetch(407 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 1043 */
} /* line 1043 */
  sim_icache_fetch(408 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L42X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L42X3;
} /* line 1045 */
l_L50X3: ;/* line 1048 */
LABEL(l_L50X3);
  sim_icache_fetch(409 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L51X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L51X3;
} /* line 1049 */
l_L46X3: ;/* line 1052 */
LABEL(l_L46X3);
  sim_icache_fetch(410 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_57); /* line 1053 */
} /* line 1053 */
  sim_icache_fetch(411 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 10); /* line 1055 */
} /* line 1055 */
		 /* line 1056 */
  sim_icache_fetch(412 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__swbuf);
   reg_l0_0 = (226 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __swbuf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 1058 */
l_lr_101: ;/* line 1058 */
LABEL(l_lr_101);
  sim_icache_fetch(414 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_3); /* line 1060 */
} /* line 1060 */
  sim_icache_fetch(415 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX33); /* line 1062 */
} /* line 1062 */
  sim_icache_fetch(417 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_60); /* line 1064 */
} /* line 1064 */
  sim_icache_fetch(418 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_61); /* line 1066 */
} /* line 1066 */
  sim_icache_fetch(419 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 1068 */
} /* line 1068 */
  sim_icache_fetch(421 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L47X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L47X3;
} /* line 1070 */
l_L45X3: ;/* line 1073 */
LABEL(l_L45X3);
  sim_icache_fetch(422 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_3, mem_trace_ld(reg_r0_59,0,1)); /* line 1074 */
} /* line 1074 */
  sim_icache_fetch(423 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_57); /* line 1076 */
} /* line 1076 */
		 /* line 1077 */
  sim_icache_fetch(424 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__swbuf);
   reg_l0_0 = (226 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __swbuf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 1079 */
l_lr_104: ;/* line 1079 */
LABEL(l_lr_104);
  sim_icache_fetch(426 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 1081 */
} /* line 1081 */
  sim_icache_fetch(428 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_3); /* line 1083 */
} /* line 1083 */
  sim_icache_fetch(429 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX33); /* line 1085 */
} /* line 1085 */
  sim_icache_fetch(431 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_60); /* line 1087 */
} /* line 1087 */
  sim_icache_fetch(432 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_61); /* line 1090 */
} /* line 1090 */
  sim_icache_fetch(433 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L48X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L48X3;
} /* line 1092 */
l_L44X3: ;/* line 1095 */
LABEL(l_L44X3);
  sim_icache_fetch(434 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_3, mem_trace_ld(reg_r0_59,0,1)); /* line 1096 */
} /* line 1096 */
  sim_icache_fetch(435 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_8, mem_trace_ld(reg_r0_57,0,4)); /* line 1098 */
} /* line 1098 */
  sim_icache_fetch(436 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX33); /* line 1100 */
} /* line 1100 */
  sim_icache_fetch(438 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_60); /* line 1102 */
} /* line 1102 */
  sim_icache_fetch(439 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_61); /* line 1104 */
} /* line 1104 */
  sim_icache_fetch(440 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_8,0,1), reg_r0_3); /* line 1106 */
} /* line 1106 */
  sim_icache_fetch(441 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld(reg_r0_57,0,4)); /* line 1108 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 1109 */
   ADD_CYCLES(2);
} /* line 1109 */
  sim_icache_fetch(443 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_3, (unsigned int) 1); /* line 1111 */
} /* line 1111 */
  sim_icache_fetch(444 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_57,0,4), reg_r0_8); /* line 1113 */
} /* line 1113 */
  sim_icache_fetch(445 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_2, mem_trace_ld(reg_r0_3,0,1)); /* line 1115 */
} /* line 1115 */
  sim_icache_fetch(446 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 1117 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1118 */
   ADD_CYCLES(1);
} /* line 1118 */
  sim_icache_fetch(449 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L49X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L49X3;
} /* line 1120 */
l_L43X3: ;/* line 1123 */
LABEL(l_L43X3);
  sim_icache_fetch(450 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 1124 */
} /* line 1124 */
  sim_icache_fetch(451 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1126 */
} /* line 1126 */
  sim_icache_fetch(452 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_62, (unsigned int) 1); /* line 1128 */
} /* line 1128 */
  sim_icache_fetch(453 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_63); /* line 1130 */
} /* line 1130 */
  sim_icache_fetch(454 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 1); /* line 1133 */
} /* line 1133 */
  sim_icache_fetch(455 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L40X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L40X3;
} /* line 1135 */
l_L41X3: ;/* line 1138 */
LABEL(l_L41X3);
  sim_icache_fetch(456 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_57); /* line 1139 */
} /* line 1139 */
		 /* line 1140 */
  sim_icache_fetch(457 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fclose);
   reg_l0_0 = (226 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) fclose;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1142 */
l_lr_109: ;/* line 1142 */
LABEL(l_lr_109);
  sim_icache_fetch(459 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1144 */
} /* line 1144 */
  sim_icache_fetch(460 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 1146 */
} /* line 1146 */
  sim_icache_fetch(461 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1148 */
} /* line 1148 */
  sim_icache_fetch(462 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1150 */
} /* line 1150 */
  sim_icache_fetch(463 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1152 */
} /* line 1152 */
  sim_icache_fetch(464 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1154 */
} /* line 1154 */
  sim_icache_fetch(465 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 1156 */
} /* line 1156 */
  sim_icache_fetch(466 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 1158 */
} /* line 1158 */
  sim_icache_fetch(467 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 1160 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1161 */
   ADD_CYCLES(1);
} /* line 1161 */
  sim_icache_fetch(469 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(save_pgm);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 96; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1164 */
l_L38X3: ;/* line 1167 */
LABEL(l_L38X3);
  sim_icache_fetch(470 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 1168 */
} /* line 1168 */
  sim_icache_fetch(471 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 56),0,4), reg_r0_5); /* line 1170 */
} /* line 1170 */
  sim_icache_fetch(472 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX32); /* line 1172 */
} /* line 1172 */
  sim_icache_fetch(474 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 106); /* line 1174 */
} /* line 1174 */
  sim_icache_fetch(475 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX31); /* line 1176 */
} /* line 1176 */
		 /* line 1177 */
  sim_icache_fetch(477 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (226 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1179 */
l_lr_112: ;/* line 1179 */
LABEL(l_lr_112);
  sim_icache_fetch(479 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, 0); /* line 1181 */
} /* line 1181 */
  sim_icache_fetch(480 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 1183 */
} /* line 1183 */
  sim_icache_fetch(481 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 1185 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1186 */
   ADD_CYCLES(1);
} /* line 1186 */
  sim_icache_fetch(483 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L39X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L39X3;
} /* line 1188 */
l_L36X3: ;/* line 1191 */
LABEL(l_L36X3);
  sim_icache_fetch(484 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 1192 */
} /* line 1192 */
  sim_icache_fetch(485 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX30); /* line 1194 */
} /* line 1194 */
  sim_icache_fetch(487 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 105); /* line 1196 */
} /* line 1196 */
  sim_icache_fetch(488 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX29); /* line 1198 */
} /* line 1198 */
		 /* line 1199 */
  sim_icache_fetch(490 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (226 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1201 */
l_lr_115: ;/* line 1201 */
LABEL(l_lr_115);
  sim_icache_fetch(492 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 1203 */
} /* line 1203 */
  sim_icache_fetch(493 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, 0); /* line 1205 */
} /* line 1205 */
  sim_icache_fetch(494 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 1207 */
} /* line 1207 */
  sim_icache_fetch(495 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLE(reg_b0_1, reg_r0_3, (unsigned int) 1500); /* line 1209 */
} /* line 1209 */
  sim_icache_fetch(497 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L37X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L37X3;
} /* line 1211 */
l_L34X3: ;/* line 1214 */
LABEL(l_L34X3);
  sim_icache_fetch(498 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 1215 */
} /* line 1215 */
  sim_icache_fetch(499 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX28); /* line 1217 */
} /* line 1217 */
  sim_icache_fetch(501 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 104); /* line 1219 */
} /* line 1219 */
  sim_icache_fetch(502 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX27); /* line 1221 */
} /* line 1221 */
		 /* line 1222 */
  sim_icache_fetch(504 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (226 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1224 */
l_lr_118: ;/* line 1224 */
LABEL(l_lr_118);
  sim_icache_fetch(506 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, 0); /* line 1226 */
} /* line 1226 */
  sim_icache_fetch(507 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 1228 */
} /* line 1228 */
  sim_icache_fetch(508 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 1230 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1231 */
   ADD_CYCLES(1);
} /* line 1231 */
  sim_icache_fetch(510 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L35X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L35X3;
} /* line 1233 */
l_L32X3: ;/* line 1236 */
LABEL(l_L32X3);
  sim_icache_fetch(511 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 1237 */
} /* line 1237 */
  sim_icache_fetch(512 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX26); /* line 1239 */
} /* line 1239 */
  sim_icache_fetch(514 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 103); /* line 1241 */
} /* line 1241 */
  sim_icache_fetch(515 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX25); /* line 1243 */
} /* line 1243 */
		 /* line 1244 */
  sim_icache_fetch(517 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (226 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1246 */
l_lr_121: ;/* line 1246 */
LABEL(l_lr_121);
  sim_icache_fetch(519 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 1248 */
} /* line 1248 */
  sim_icache_fetch(520 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, 0); /* line 1250 */
} /* line 1250 */
  sim_icache_fetch(521 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 1252 */
} /* line 1252 */
  sim_icache_fetch(522 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLE(reg_b0_1, reg_r0_5, (unsigned int) 1050); /* line 1254 */
} /* line 1254 */
  sim_icache_fetch(524 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L33X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L33X3;
} /* line 1256 */
l_L31X3: ;/* line 1259 */
LABEL(l_L31X3);
  sim_icache_fetch(525 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 1260 */
} /* line 1260 */
  sim_icache_fetch(527 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 64),0,4)); /* line 1262 */
} /* line 1262 */
  sim_icache_fetch(528 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX34); /* line 1264 */
} /* line 1264 */
  sim_icache_fetch(530 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 1266 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1267 */
   ADD_CYCLES(1);
} /* line 1267 */
		 /* line 1268 */
  sim_icache_fetch(532 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fprintf);
   reg_l0_0 = (226 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fprintf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1270 */
l_lr_124: ;/* line 1270 */
LABEL(l_lr_124);
  sim_icache_fetch(534 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1272 */
} /* line 1272 */
  sim_icache_fetch(535 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) -1); /* line 1274 */
} /* line 1274 */
  sim_icache_fetch(536 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1276 */
} /* line 1276 */
  sim_icache_fetch(537 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1278 */
} /* line 1278 */
  sim_icache_fetch(538 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1280 */
} /* line 1280 */
  sim_icache_fetch(539 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1282 */
} /* line 1282 */
  sim_icache_fetch(540 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 1284 */
} /* line 1284 */
  sim_icache_fetch(541 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 1286 */
} /* line 1286 */
  sim_icache_fetch(542 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 1288 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1289 */
   ADD_CYCLES(1);
} /* line 1289 */
  sim_icache_fetch(544 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(save_pgm);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 96; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1292 */
  reg_l0_0 = t_client_rpc;
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 176: goto l_lr_75;
    case 178: goto l_lr_77;
    case 180: goto l_lr_79;
    case 182: goto l_lr_81;
    case 183: goto l_L33X3;
    case 184: goto l_L35X3;
    case 185: goto l_L37X3;
    case 186: goto l_L39X3;
    case 187: goto l_L40X3;
    case 188: goto l_L42X3;
    case 189: goto l_L47X3;
    case 190: goto l_L48X3;
    case 191: goto l_L49X3;
    case 193: goto l_lr_92;
    case 195: goto l_lr_94;
    case 197: goto l_lr_96;
    case 198: goto l_L51X3;
    case 199: goto l_L50X3;
    case 200: goto l_L46X3;
    case 202: goto l_lr_101;
    case 203: goto l_L45X3;
    case 205: goto l_lr_104;
    case 206: goto l_L44X3;
    case 207: goto l_L43X3;
    case 208: goto l_L41X3;
    case 210: goto l_lr_109;
    case 211: goto l_L38X3;
    case 213: goto l_lr_112;
    case 214: goto l_L36X3;
    case 216: goto l_lr_115;
    case 217: goto l_L34X3;
    case 219: goto l_lr_118;
    case 220: goto l_L32X3;
    case 222: goto l_lr_121;
    case 223: goto l_L31X3;
    case 225: goto l_lr_124;
    case 226:
      reg_l0_0 = t_client_rpc;
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"pgm.s", 560, 0, 0, 0, 2};


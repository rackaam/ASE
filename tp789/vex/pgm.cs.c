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
  reg_l0_0 = (173 << 5);
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
  sim_icache_fetch(3 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 184),0,4), reg_r0_5); /* line 28 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX1); /* line 29 */
} /* line 29 */
  sim_icache_fetch(6 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 188),0,4), reg_r0_6); /* line 31 */
} /* line 31 */
  sim_icache_fetch(7 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 152),0,4), reg_r0_63); /* line 33 */
} /* line 33 */
  sim_icache_fetch(8 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 156),0,4), reg_r0_62); /* line 35 */
} /* line 35 */
  sim_icache_fetch(9 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 160),0,4), reg_r0_61); /* line 37 */
} /* line 37 */
  sim_icache_fetch(10 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 164),0,4), reg_r0_60); /* line 39 */
} /* line 39 */
  sim_icache_fetch(11 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 168),0,4), reg_r0_59); /* line 41 */
} /* line 41 */
  sim_icache_fetch(12 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 172),0,4), reg_r0_58); /* line 43 */
} /* line 43 */
  sim_icache_fetch(13 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_58, reg_r0_1, (unsigned int) 16); /* line 45 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 176),0,4), reg_r0_57); /* line 46 */
} /* line 46 */
		 /* line 47 */
  sim_icache_fetch(15 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fopen);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fopen;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 49 */
l_lr_1: ;/* line 49 */
LABEL(l_lr_1);
  sim_icache_fetch(17 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPNE(reg_b0_0, reg_r0_3, 0); /* line 51 */
   ADD(reg_r0_62, reg_r0_1, (unsigned int) 144); /* line 52 */
} /* line 52 */
  sim_icache_fetch(19 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, 0); /* line 54 */
   MOV(reg_r0_59, reg_r0_3); /* line 55 */
} /* line 55 */
  sim_icache_fetch(21 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 180),0,4)); /* line 57 */
} /* line 57 */
  sim_icache_fetch(22 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 184),0,4)); /* line 59 */
} /* line 59 */
  sim_icache_fetch(23 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 188),0,4)); /* line 61 */
} /* line 61 */
  sim_icache_fetch(24 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 144),0,4), 0); /* line 63 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L0X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 64 */
  sim_icache_fetch(26 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 65 */
l_L1X3: ;/* line 68 */
LABEL(l_L1X3);
  sim_icache_fetch(27 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_57, (unsigned int) 5); /* line 69 */
   CMPEQ(reg_b0_1, reg_r0_57, 0); /* line 70 */
} /* line 70 */
  sim_icache_fetch(29 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX2); /* line 72 */
   MOV(reg_r0_3, reg_r0_59); /* line 73 */
} /* line 73 */
  sim_icache_fetch(32 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_58); /* line 75 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L2X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 76 */
  sim_icache_fetch(34 + t_thisfile.offset, 1);
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
} /* line 78 */
		 /* line 79 */
  sim_icache_fetch(35 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fscanf);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fscanf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 81 */
l_lr_4: ;/* line 81 */
LABEL(l_lr_4);
  sim_icache_fetch(37 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_2, mem_trace_ld((unsigned int) verbose,0,4)); /* line 83 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 84 */
} /* line 84 */
  sim_icache_fetch(41 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_58); /* line 86 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 87 */
   ADD_CYCLES(1);
} /* line 87 */
  sim_icache_fetch(43 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_2, 0); /* line 89 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 90 */
   ADD_CYCLES(1);
} /* line 90 */
  sim_icache_fetch(45 + t_thisfile.offset, 1);
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
} /* line 92 */
		 /* line 93 */
  sim_icache_fetch(46 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 95 */
l_lr_6: ;/* line 95 */
LABEL(l_lr_6);
l_L4X3: ;/* line 97 */
LABEL(l_L4X3);
  sim_icache_fetch(48 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 98 */
   MOV(reg_r0_4, reg_r0_58); /* line 99 */
} /* line 99 */
		 /* line 100 */
  sim_icache_fetch(51 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(strcmp);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) strcmp;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 102 */
l_lr_9: ;/* line 102 */
LABEL(l_lr_9);
  sim_icache_fetch(53 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 104 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX5); /* line 105 */
} /* line 105 */
  sim_icache_fetch(56 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_58); /* line 107 */
} /* line 107 */
  sim_icache_fetch(57 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 109 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 110 */
		 /* line 111 */
  sim_icache_fetch(59 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, (unsigned int) 1); /* line 113 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fscanf);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fscanf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 114 */
l_lr_11: ;/* line 114 */
LABEL(l_lr_11);
  sim_icache_fetch(62 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 116 */
l_L5X3: ;/* line 119 */
LABEL(l_L5X3);
		 /* line 119 */
  sim_icache_fetch(63 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) -1); /* line 123 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(exit);
   reg_l0_0 = (173 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) exit;
    (*t_call)(reg_r0_3);
   }
} /* line 123 */
l_lr_14: ;/* line 123 */
LABEL(l_lr_14);
  sim_icache_fetch(66 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 125 */
l_L3X3: ;/* line 128 */
LABEL(l_L3X3);
  sim_icache_fetch(67 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPEQ(reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 129 */
   LDBs(reg_r0_6, mem_trace_ld(reg_r0_58,0,1)); /* line 130 */
} /* line 130 */
  sim_icache_fetch(69 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX6); /* line 132 */
   MOV(reg_r0_3, reg_r0_59); /* line 133 */
} /* line 133 */
  sim_icache_fetch(72 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_58); /* line 135 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L6X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 136 */
  sim_icache_fetch(74 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPEQ(reg_b0_0, reg_r0_6, (unsigned int) 35); /* line 138 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 139 */
   ADD_CYCLES(1);
} /* line 139 */
  sim_icache_fetch(76 + t_thisfile.offset, 1);
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
} /* line 141 */
		 /* line 142 */
  sim_icache_fetch(77 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fscanf);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fscanf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 144 */
l_lr_17: ;/* line 144 */
LABEL(l_lr_17);
  sim_icache_fetch(79 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_5, mem_trace_ld((unsigned int) verbose,0,4)); /* line 146 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX7); /* line 147 */
} /* line 147 */
  sim_icache_fetch(83 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_58); /* line 149 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 150 */
   ADD_CYCLES(1);
} /* line 150 */
  sim_icache_fetch(85 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_5, 0); /* line 152 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 153 */
   ADD_CYCLES(1);
} /* line 153 */
  sim_icache_fetch(87 + t_thisfile.offset, 1);
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
} /* line 155 */
		 /* line 156 */
  sim_icache_fetch(88 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 158 */
l_lr_19: ;/* line 158 */
LABEL(l_lr_19);
l_L8X3: ;/* line 160 */
LABEL(l_L8X3);
  sim_icache_fetch(90 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 160 */
l_L9X3: ;/* line 163 */
LABEL(l_L9X3);
  sim_icache_fetch(91 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_59 + (unsigned int) 4),0,4)); /* line 164 */
   MOV(reg_r0_3, reg_r0_59); /* line 165 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 166 */
   ADD_CYCLES(2);
} /* line 166 */
  sim_icache_fetch(94 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 168 */
} /* line 168 */
  sim_icache_fetch(95 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_59 + (unsigned int) 4),0,4), reg_r0_2); /* line 170 */
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 171 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 172 */
   ADD_CYCLES(1);
} /* line 172 */
  sim_icache_fetch(98 + t_thisfile.offset, 1);
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
} /* line 174 */
		 /* line 175 */
  sim_icache_fetch(99 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__srget);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) __srget;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 177 */
l_lr_23: ;/* line 177 */
LABEL(l_lr_23);
  sim_icache_fetch(101 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 179 */
l_L11X3: ;/* line 181 */
LABEL(l_L11X3);
  sim_icache_fetch(102 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_3, (unsigned int) 10); /* line 182 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 183 */
   ADD_CYCLES(1);
} /* line 183 */
  sim_icache_fetch(104 + t_thisfile.offset, 1);
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
} /* line 186 */
  sim_icache_fetch(105 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L9X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L9X3;
} /* line 188 */
l_L7X3: ;/* line 191 */
LABEL(l_L7X3);
  sim_icache_fetch(106 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, (unsigned int) 2); /* line 192 */
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 193 */
l_L10X3: ;/* line 196 */
LABEL(l_L10X3);
  sim_icache_fetch(108 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld(reg_r0_59,0,4)); /* line 197 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 198 */
   ADD_CYCLES(2);
} /* line 198 */
  sim_icache_fetch(110 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 200 */
} /* line 200 */
  sim_icache_fetch(111 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_59,0,4), reg_r0_4); /* line 202 */
} /* line 202 */
  sim_icache_fetch(112 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 204 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 205 */
   ADD_CYCLES(1);
} /* line 205 */
  sim_icache_fetch(114 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L11X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L11X3;
} /* line 207 */
l_L6X3: ;/* line 210 */
LABEL(l_L6X3);
  sim_icache_fetch(115 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPEQ(reg_b0_0, reg_r0_57, (unsigned int) 2); /* line 211 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX8); /* line 212 */
} /* line 212 */
  sim_icache_fetch(118 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_58); /* line 214 */
   MOV(reg_r0_5, reg_r0_60); /* line 215 */
} /* line 215 */
  sim_icache_fetch(120 + t_thisfile.offset, 1);
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
} /* line 217 */
		 /* line 218 */
  sim_icache_fetch(121 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(sscanf);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) sscanf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 220 */
l_lr_29: ;/* line 220 */
LABEL(l_lr_29);
  sim_icache_fetch(123 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_5, mem_trace_ld((unsigned int) verbose,0,4)); /* line 222 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 223 */
} /* line 223 */
  sim_icache_fetch(127 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_60,0,4)); /* line 225 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 226 */
   ADD_CYCLES(1);
} /* line 226 */
  sim_icache_fetch(129 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_5, 0); /* line 228 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 229 */
   ADD_CYCLES(1);
} /* line 229 */
  sim_icache_fetch(131 + t_thisfile.offset, 1);
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
} /* line 231 */
		 /* line 232 */
  sim_icache_fetch(132 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 234 */
l_lr_31: ;/* line 234 */
LABEL(l_lr_31);
l_L13X3: ;/* line 236 */
LABEL(l_L13X3);
  sim_icache_fetch(134 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, (unsigned int) 3); /* line 237 */
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 238 */
l_L12X3: ;/* line 241 */
LABEL(l_L12X3);
  sim_icache_fetch(136 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPEQ(reg_b0_0, reg_r0_57, (unsigned int) 3); /* line 242 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX10); /* line 243 */
} /* line 243 */
  sim_icache_fetch(139 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 245 */
   MOV(reg_r0_5, reg_r0_61); /* line 246 */
} /* line 246 */
  sim_icache_fetch(141 + t_thisfile.offset, 1);
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
} /* line 248 */
		 /* line 249 */
  sim_icache_fetch(142 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fscanf);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fscanf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 251 */
l_lr_35: ;/* line 251 */
LABEL(l_lr_35);
  sim_icache_fetch(144 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_5, mem_trace_ld((unsigned int) verbose,0,4)); /* line 253 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX11); /* line 254 */
} /* line 254 */
  sim_icache_fetch(148 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_61,0,4)); /* line 256 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 257 */
   ADD_CYCLES(1);
} /* line 257 */
  sim_icache_fetch(150 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_5, 0); /* line 259 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 260 */
   ADD_CYCLES(1);
} /* line 260 */
  sim_icache_fetch(152 + t_thisfile.offset, 1);
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
} /* line 262 */
		 /* line 263 */
  sim_icache_fetch(153 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 265 */
l_lr_37: ;/* line 265 */
LABEL(l_lr_37);
l_L15X3: ;/* line 267 */
LABEL(l_L15X3);
  sim_icache_fetch(155 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, (unsigned int) 4); /* line 268 */
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 269 */
l_L14X3: ;/* line 272 */
LABEL(l_L14X3);
  sim_icache_fetch(157 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPEQ(reg_b0_0, reg_r0_57, (unsigned int) 4); /* line 273 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX12); /* line 274 */
} /* line 274 */
  sim_icache_fetch(160 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 276 */
   MOV(reg_r0_5, reg_r0_62); /* line 277 */
} /* line 277 */
  sim_icache_fetch(162 + t_thisfile.offset, 1);
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
} /* line 279 */
		 /* line 280 */
  sim_icache_fetch(163 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fscanf);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fscanf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 282 */
l_lr_41: ;/* line 282 */
LABEL(l_lr_41);
  sim_icache_fetch(165 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_5, mem_trace_ld((unsigned int) verbose,0,4)); /* line 284 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX13); /* line 285 */
} /* line 285 */
  sim_icache_fetch(169 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 144),0,4)); /* line 287 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 288 */
   ADD_CYCLES(1);
} /* line 288 */
  sim_icache_fetch(171 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_5, 0); /* line 290 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 291 */
   ADD_CYCLES(1);
} /* line 291 */
  sim_icache_fetch(173 + t_thisfile.offset, 1);
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
} /* line 293 */
		 /* line 294 */
  sim_icache_fetch(174 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 296 */
l_lr_43: ;/* line 296 */
LABEL(l_lr_43);
l_L16X3: ;/* line 298 */
LABEL(l_L16X3);
  sim_icache_fetch(176 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, (unsigned int) 5); /* line 299 */
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 300 */
l_L2X3: ;/* line 303 */
LABEL(l_L2X3);
  sim_icache_fetch(178 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_3, mem_trace_ld(reg_r0_61,0,4)); /* line 304 */
   MOV(reg_r0_5, reg_r0_63); /* line 305 */
} /* line 305 */
  sim_icache_fetch(180 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_7, mem_trace_ld(reg_r0_61,0,4)); /* line 307 */
   MOV(reg_r0_4, 0); /* line 308 */
} /* line 308 */
  sim_icache_fetch(182 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_60,0,4)); /* line 310 */
   MOV(reg_r0_2, reg_r0_61); /* line 311 */
} /* line 311 */
  sim_icache_fetch(184 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_0, reg_r0_3, 0); /* line 313 */
   LDWs(reg_r0_9, mem_trace_ld(reg_r0_60,0,4)); /* line 314 */
} /* line 314 */
  sim_icache_fetch(186 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLE(reg_b0_1, reg_r0_7, (unsigned int) 1050); /* line 316 */
   MOV(reg_r0_57, reg_r0_60); /* line 317 */
} /* line 317 */
  sim_icache_fetch(189 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_0, reg_r0_8, 0); /* line 319 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 320 */
l_L18X3: ;/* line 322 */
LABEL(l_L18X3);
  sim_icache_fetch(191 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLE(reg_b0_1, reg_r0_9, (unsigned int) 1500); /* line 323 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 324 */
l_L20X3: ;/* line 326 */
LABEL(l_L20X3);
  sim_icache_fetch(194 + t_thisfile.offset, 1);
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
} /* line 327 */
l_L22X3: ;/* line 329 */
LABEL(l_L22X3);
  sim_icache_fetch(195 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L23X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 330 */
l_L24X3: ;/* line 333 */
LABEL(l_L24X3);
  sim_icache_fetch(196 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 334 */
   MOV(reg_r0_60, reg_r0_5); /* line 335 */
} /* line 335 */
  sim_icache_fetch(198 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_58, 0); /* line 337 */
   MOV(reg_r0_61, reg_r0_2); /* line 338 */
} /* line 338 */
  sim_icache_fetch(200 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_62, reg_r0_4); /* line 340 */
   MOV(reg_r0_63, reg_r0_5); /* line 341 */
} /* line 341 */
  sim_icache_fetch(202 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_4, reg_r0_3); /* line 343 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 344 */
   ADD_CYCLES(1);
} /* line 344 */
  sim_icache_fetch(204 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L25X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 346 */
l_L26X3: ;/* line 349 */
LABEL(l_L26X3);
  sim_icache_fetch(205 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_2, mem_trace_ld(reg_r0_57,0,4)); /* line 350 */
   MOV(reg_r0_3, reg_r0_59); /* line 351 */
} /* line 351 */
  sim_icache_fetch(207 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_59 + (unsigned int) 4),0,4)); /* line 353 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 354 */
   ADD_CYCLES(1);
} /* line 354 */
  sim_icache_fetch(209 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, reg_r0_2); /* line 356 */
} /* line 356 */
  sim_icache_fetch(210 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) -1); /* line 358 */
} /* line 358 */
  sim_icache_fetch(211 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 360 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L27X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 361 */
  sim_icache_fetch(213 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_59 + (unsigned int) 4),0,4), reg_r0_4); /* line 363 */
} /* line 363 */
  sim_icache_fetch(214 + t_thisfile.offset, 1);
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
} /* line 365 */
		 /* line 366 */
  sim_icache_fetch(215 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__srget);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) __srget;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 368 */
l_lr_52: ;/* line 368 */
LABEL(l_lr_52);
  sim_icache_fetch(217 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 371 */
} /* line 371 */
l_L29X3: ;/* line 373 */
LABEL(l_L29X3);
  sim_icache_fetch(218 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_60,0,1), reg_r0_3); /* line 374 */
} /* line 374 */
  sim_icache_fetch(219 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1050); /* line 376 */
   GOTO(l_L26X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L26X3;
} /* line 377 */
l_L28X3: ;/* line 380 */
LABEL(l_L28X3);
  sim_icache_fetch(222 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_2, mem_trace_ld(reg_r0_59,0,4)); /* line 381 */
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 382 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 383 */
   ADD_CYCLES(2);
} /* line 383 */
  sim_icache_fetch(225 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 385 */
} /* line 385 */
  sim_icache_fetch(226 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_59,0,4), reg_r0_4); /* line 387 */
} /* line 387 */
  sim_icache_fetch(227 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 389 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 390 */
   ADD_CYCLES(1);
} /* line 390 */
  sim_icache_fetch(229 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L29X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L29X3;
} /* line 392 */
l_L27X3: ;/* line 395 */
LABEL(l_L27X3);
  sim_icache_fetch(230 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_63, (unsigned int) 1); /* line 396 */
   ADD(reg_r0_4, reg_r0_62, (unsigned int) 1); /* line 397 */
} /* line 397 */
  sim_icache_fetch(232 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_61); /* line 399 */
   GOTO(l_L24X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L24X3;
} /* line 400 */
l_L25X3: ;/* line 403 */
LABEL(l_L25X3);
		 /* line 403 */
  sim_icache_fetch(234 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 406 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fclose);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) fclose;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 406 */
l_lr_58: ;/* line 406 */
LABEL(l_lr_58);
  sim_icache_fetch(237 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 408 */
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 148),0,4)); /* line 409 */
} /* line 409 */
  sim_icache_fetch(239 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 152),0,4)); /* line 411 */
} /* line 411 */
  sim_icache_fetch(240 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 156),0,4)); /* line 413 */
} /* line 413 */
  sim_icache_fetch(241 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 160),0,4)); /* line 415 */
} /* line 415 */
  sim_icache_fetch(242 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 164),0,4)); /* line 417 */
} /* line 417 */
  sim_icache_fetch(243 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 168),0,4)); /* line 419 */
} /* line 419 */
  sim_icache_fetch(244 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 172),0,4)); /* line 421 */
} /* line 421 */
  sim_icache_fetch(245 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 176),0,4)); /* line 423 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 424 */
   ADD_CYCLES(1);
} /* line 424 */
  sim_icache_fetch(247 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(load_pgm);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 192; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 427 */
l_L23X3: ;/* line 430 */
LABEL(l_L23X3);
  sim_icache_fetch(248 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 184),0,4), reg_r0_2); /* line 431 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX21); /* line 432 */
} /* line 432 */
  sim_icache_fetch(251 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 82); /* line 434 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX20); /* line 435 */
} /* line 435 */
		 /* line 436 */
  sim_icache_fetch(254 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (173 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 438 */
l_lr_61: ;/* line 438 */
LABEL(l_lr_61);
  sim_icache_fetch(256 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_63); /* line 440 */
   MOV(reg_r0_4, 0); /* line 441 */
} /* line 441 */
  sim_icache_fetch(258 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 184),0,4)); /* line 443 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 444 */
   ADD_CYCLES(1);
} /* line 444 */
  sim_icache_fetch(260 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L24X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L24X3;
} /* line 446 */
l_L21X3: ;/* line 449 */
LABEL(l_L21X3);
  sim_icache_fetch(261 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 184),0,4), reg_r0_2); /* line 450 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX19); /* line 451 */
} /* line 451 */
  sim_icache_fetch(264 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 81); /* line 453 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX18); /* line 454 */
} /* line 454 */
		 /* line 455 */
  sim_icache_fetch(267 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (173 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 457 */
l_lr_64: ;/* line 457 */
LABEL(l_lr_64);
  sim_icache_fetch(269 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_9, mem_trace_ld(reg_r0_57,0,4)); /* line 459 */
   MOV(reg_r0_5, reg_r0_63); /* line 460 */
} /* line 460 */
  sim_icache_fetch(271 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, 0); /* line 462 */
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 184),0,4)); /* line 463 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 464 */
   ADD_CYCLES(1);
} /* line 464 */
  sim_icache_fetch(274 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLE(reg_b0_1, reg_r0_9, (unsigned int) 1500); /* line 466 */
} /* line 466 */
  sim_icache_fetch(276 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L22X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L22X3;
} /* line 468 */
l_L19X3: ;/* line 471 */
LABEL(l_L19X3);
  sim_icache_fetch(277 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 184),0,4), reg_r0_2); /* line 472 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX17); /* line 473 */
} /* line 473 */
  sim_icache_fetch(280 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 80); /* line 475 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX16); /* line 476 */
} /* line 476 */
		 /* line 477 */
  sim_icache_fetch(283 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (173 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 479 */
l_lr_67: ;/* line 479 */
LABEL(l_lr_67);
  sim_icache_fetch(285 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_8, mem_trace_ld(reg_r0_57,0,4)); /* line 481 */
   MOV(reg_r0_5, reg_r0_63); /* line 482 */
} /* line 482 */
  sim_icache_fetch(287 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_9, mem_trace_ld(reg_r0_57,0,4)); /* line 484 */
   MOV(reg_r0_4, 0); /* line 485 */
} /* line 485 */
  sim_icache_fetch(289 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 184),0,4)); /* line 487 */
} /* line 487 */
  sim_icache_fetch(290 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_8, 0); /* line 489 */
} /* line 489 */
  sim_icache_fetch(291 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLE(reg_b0_1, reg_r0_9, (unsigned int) 1500); /* line 491 */
   GOTO(l_L20X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L20X3;
} /* line 492 */
l_L17X3: ;/* line 495 */
LABEL(l_L17X3);
  sim_icache_fetch(294 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 184),0,4), reg_r0_2); /* line 496 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX15); /* line 497 */
} /* line 497 */
  sim_icache_fetch(297 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 79); /* line 499 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX14); /* line 500 */
} /* line 500 */
		 /* line 501 */
  sim_icache_fetch(300 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (173 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 503 */
l_lr_70: ;/* line 503 */
LABEL(l_lr_70);
  sim_icache_fetch(302 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_63); /* line 505 */
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 184),0,4)); /* line 506 */
} /* line 506 */
  sim_icache_fetch(304 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_57,0,4)); /* line 508 */
   MOV(reg_r0_4, 0); /* line 509 */
} /* line 509 */
  sim_icache_fetch(306 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld(reg_r0_57,0,4)); /* line 511 */
} /* line 511 */
  sim_icache_fetch(307 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_7, mem_trace_ld(reg_r0_2,0,4)); /* line 513 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 514 */
   ADD_CYCLES(2);
} /* line 514 */
  sim_icache_fetch(309 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLE(reg_b0_1, reg_r0_7, (unsigned int) 1050); /* line 516 */
} /* line 516 */
  sim_icache_fetch(311 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_0, reg_r0_8, 0); /* line 518 */
   GOTO(l_L18X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L18X3;
} /* line 519 */
l_L0X3: ;/* line 522 */
LABEL(l_L0X3);
  sim_icache_fetch(313 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) -1); /* line 523 */
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 148),0,4)); /* line 524 */
} /* line 524 */
  sim_icache_fetch(315 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 152),0,4)); /* line 526 */
} /* line 526 */
  sim_icache_fetch(316 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 156),0,4)); /* line 528 */
} /* line 528 */
  sim_icache_fetch(317 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 160),0,4)); /* line 530 */
} /* line 530 */
  sim_icache_fetch(318 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 164),0,4)); /* line 532 */
} /* line 532 */
  sim_icache_fetch(319 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 168),0,4)); /* line 534 */
} /* line 534 */
  sim_icache_fetch(320 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 172),0,4)); /* line 536 */
} /* line 536 */
  sim_icache_fetch(321 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 176),0,4)); /* line 538 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 539 */
   ADD_CYCLES(1);
} /* line 539 */
  sim_icache_fetch(323 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(load_pgm);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 192; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 542 */
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
    case 151: goto l_L26X3;
    case 153: goto l_lr_52;
    case 154: goto l_L29X3;
    case 155: goto l_L28X3;
    case 156: goto l_L27X3;
    case 157: goto l_L25X3;
    case 159: goto l_lr_58;
    case 160: goto l_L23X3;
    case 162: goto l_lr_61;
    case 163: goto l_L21X3;
    case 165: goto l_lr_64;
    case 166: goto l_L19X3;
    case 168: goto l_lr_67;
    case 169: goto l_L17X3;
    case 171: goto l_lr_70;
    case 172: goto l_L0X3;
    case 173:
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
  reg_l0_0 = (224 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(324 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_1, reg_r0_1, (unsigned int) -96); /* line 806 */
} /* line 806 */
  sim_icache_fetch(325 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 808 */
} /* line 808 */
  sim_icache_fetch(326 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 52),0,4), reg_r0_6); /* line 810 */
} /* line 810 */
  sim_icache_fetch(327 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_63); /* line 812 */
} /* line 812 */
  sim_icache_fetch(328 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_62); /* line 814 */
} /* line 814 */
  sim_icache_fetch(329 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_61); /* line 816 */
} /* line 816 */
  sim_icache_fetch(330 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_60); /* line 818 */
} /* line 818 */
  sim_icache_fetch(331 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_59); /* line 820 */
} /* line 820 */
  sim_icache_fetch(332 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_58); /* line 822 */
} /* line 822 */
  sim_icache_fetch(333 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 48),0,4), reg_r0_57); /* line 824 */
} /* line 824 */
  sim_icache_fetch(334 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 56),0,4), reg_r0_5); /* line 826 */
} /* line 826 */
  sim_icache_fetch(335 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_4); /* line 828 */
} /* line 828 */
  sim_icache_fetch(336 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX22); /* line 830 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 64),0,4), reg_r0_3); /* line 831 */
} /* line 831 */
		 /* line 832 */
  sim_icache_fetch(339 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fopen);
   reg_l0_0 = (224 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fopen;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 834 */
l_lr_74: ;/* line 834 */
LABEL(l_lr_74);
  sim_icache_fetch(341 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 68),0,4), reg_r0_3); /* line 836 */
} /* line 836 */
  sim_icache_fetch(342 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX23); /* line 838 */
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 839 */
} /* line 839 */
  sim_icache_fetch(345 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 841 */
} /* line 841 */
  sim_icache_fetch(346 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 64),0,4)); /* line 843 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 844 */
   ADD_CYCLES(1);
} /* line 844 */
		 /* line 845 */
  sim_icache_fetch(348 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (224 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 847 */
l_lr_76: ;/* line 847 */
LABEL(l_lr_76);
  sim_icache_fetch(350 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 849 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 850 */
   ADD_CYCLES(2);
} /* line 850 */
  sim_icache_fetch(353 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 852 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 853 */
   ADD_CYCLES(1);
} /* line 853 */
		 /* line 854 */
  sim_icache_fetch(355 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fflush);
   reg_l0_0 = (224 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) fflush;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 856 */
l_lr_78: ;/* line 856 */
LABEL(l_lr_78);
  sim_icache_fetch(357 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX24); /* line 858 */
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 859 */
} /* line 859 */
  sim_icache_fetch(360 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 861 */
} /* line 861 */
  sim_icache_fetch(361 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 863 */
} /* line 863 */
  sim_icache_fetch(362 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_3, 0); /* line 865 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 866 */
   ADD_CYCLES(1);
} /* line 866 */
  sim_icache_fetch(364 + t_thisfile.offset, 1);
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
} /* line 868 */
		 /* line 869 */
  sim_icache_fetch(365 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fprintf);
   reg_l0_0 = (224 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fprintf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 871 */
l_lr_80: ;/* line 871 */
LABEL(l_lr_80);
  sim_icache_fetch(367 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, 0); /* line 873 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 874 */
} /* line 874 */
  sim_icache_fetch(369 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 876 */
} /* line 876 */
  sim_icache_fetch(370 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 878 */
} /* line 878 */
  sim_icache_fetch(371 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_0, reg_r0_4, 0); /* line 880 */
   CMPLE(reg_b0_1, reg_r0_4, (unsigned int) 1050); /* line 881 */
} /* line 881 */
  sim_icache_fetch(374 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_2, reg_r0_3, 0); /* line 883 */
   CMPLE(reg_b0_3, reg_r0_3, (unsigned int) 1500); /* line 884 */
} /* line 884 */
  sim_icache_fetch(377 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   SUB(reg_r0_4, 0, reg_r0_4); /* line 886 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L31X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 887 */
l_L32X3: ;/* line 889 */
LABEL(l_L32X3);
  sim_icache_fetch(379 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_4); /* line 890 */
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L33X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 891 */
l_L34X3: ;/* line 893 */
LABEL(l_L34X3);
  sim_icache_fetch(381 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_6); /* line 894 */
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L35X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 895 */
l_L36X3: ;/* line 897 */
LABEL(l_L36X3);
  sim_icache_fetch(383 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 898 */
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L37X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 899 */
l_L38X3: ;/* line 901 */
LABEL(l_L38X3);
  sim_icache_fetch(385 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 901 */
  sim_icache_fetch(386 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 902 */
l_L39X3: ;/* line 905 */
LABEL(l_L39X3);
  sim_icache_fetch(387 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 906 */
   SUB(reg_r0_4, 0, reg_r0_3); /* line 907 */
} /* line 907 */
  sim_icache_fetch(389 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_58, reg_r0_4); /* line 909 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 910 */
} /* line 910 */
  sim_icache_fetch(391 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_59, reg_r0_5); /* line 912 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L40X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 913 */
  sim_icache_fetch(393 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_61, 0); /* line 915 */
   MOV(reg_r0_62, reg_r0_2); /* line 916 */
} /* line 916 */
  sim_icache_fetch(395 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, reg_r0_3); /* line 918 */
} /* line 918 */
l_L41X3: ;/* line 921 */
LABEL(l_L41X3);
  sim_icache_fetch(396 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 922 */
   LDWs(reg_r0_2, mem_trace_ld((reg_r0_57 + (unsigned int) 8),0,4)); /* line 923 */
} /* line 923 */
  sim_icache_fetch(398 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_57 + (unsigned int) 24),0,4)); /* line 925 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX33); /* line 926 */
} /* line 926 */
  sim_icache_fetch(401 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_57,0,4)); /* line 928 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L42X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 929 */
  sim_icache_fetch(403 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 931 */
   MOV(reg_r0_5, reg_r0_60); /* line 932 */
} /* line 932 */
  sim_icache_fetch(405 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 934 */
   CMPGE(reg_b0_1, reg_r0_2, reg_r0_7); /* line 935 */
} /* line 935 */
  sim_icache_fetch(407 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_57 + (unsigned int) 8),0,4), reg_r0_2); /* line 937 */
   MOV(reg_r0_6, reg_r0_61); /* line 938 */
} /* line 938 */
  sim_icache_fetch(409 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBUs(reg_r0_2, mem_trace_ld(reg_r0_59,0,1)); /* line 940 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L43X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 941 */
  sim_icache_fetch(411 + t_thisfile.offset, 1);
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
} /* line 943 */
  sim_icache_fetch(412 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 944 */
  sim_icache_fetch(413 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_8,0,1), reg_r0_2); /* line 946 */
} /* line 946 */
  sim_icache_fetch(414 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld(reg_r0_57,0,4)); /* line 948 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 949 */
   ADD_CYCLES(2);
} /* line 949 */
  sim_icache_fetch(416 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBU(reg_r0_7, mem_trace_ld(reg_r0_2,0,1)); /* line 951 */
   ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 952 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 953 */
   ADD_CYCLES(2);
} /* line 953 */
  sim_icache_fetch(419 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_7, (unsigned int) 10); /* line 955 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 956 */
   ADD_CYCLES(1);
} /* line 956 */
  sim_icache_fetch(421 + t_thisfile.offset, 1);
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
} /* line 958 */
  sim_icache_fetch(422 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_57,0,4), reg_r0_8); /* line 960 */
} /* line 960 */
  sim_icache_fetch(423 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_2, mem_trace_ld(reg_r0_2,0,1)); /* line 962 */
} /* line 962 */
  sim_icache_fetch(424 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 964 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 965 */
   ADD_CYCLES(1);
} /* line 965 */
l_L46X3: ;/* line 968 */
LABEL(l_L46X3);
  sim_icache_fetch(427 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 968 */
l_L47X3: ;/* line 971 */
LABEL(l_L47X3);
  sim_icache_fetch(428 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) 12),0,4)); /* line 972 */
} /* line 972 */
l_L48X3: ;/* line 974 */
LABEL(l_L48X3);
  sim_icache_fetch(429 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 975 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 976 */
   ADD_CYCLES(1);
} /* line 976 */
  sim_icache_fetch(431 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 978 */
		 /* line 979 */
  sim_icache_fetch(432 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fprintf);
   reg_l0_0 = (224 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fprintf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 981 */
l_lr_91: ;/* line 981 */
LABEL(l_lr_91);
		 /* line 982 */
  sim_icache_fetch(434 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_57); /* line 985 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fclose);
   reg_l0_0 = (224 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) fclose;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 985 */
l_lr_93: ;/* line 985 */
LABEL(l_lr_93);
		 /* line 986 */
  sim_icache_fetch(437 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) -1); /* line 989 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(exit);
   reg_l0_0 = (224 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) exit;
    (*t_call)(reg_r0_3);
   }
} /* line 989 */
l_lr_95: ;/* line 989 */
LABEL(l_lr_95);
l_L49X3: ;/* line 991 */
LABEL(l_L49X3);
  sim_icache_fetch(440 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_59, reg_r0_59, (unsigned int) 1050); /* line 992 */
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 1); /* line 993 */
} /* line 993 */
  sim_icache_fetch(443 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 995 */
   GOTO(l_L41X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L41X3;
} /* line 996 */
l_L45X3: ;/* line 999 */
LABEL(l_L45X3);
  sim_icache_fetch(445 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, reg_r0_57); /* line 1000 */
   MOV(reg_r0_3, (unsigned int) 10); /* line 1001 */
} /* line 1001 */
		 /* line 1002 */
  sim_icache_fetch(447 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__swbuf);
   reg_l0_0 = (224 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __swbuf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 1004 */
l_lr_99: ;/* line 1004 */
LABEL(l_lr_99);
  sim_icache_fetch(449 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_3); /* line 1006 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX33); /* line 1007 */
} /* line 1007 */
  sim_icache_fetch(452 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_60); /* line 1009 */
   MOV(reg_r0_6, reg_r0_61); /* line 1010 */
} /* line 1010 */
  sim_icache_fetch(454 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 1012 */
} /* line 1012 */
  sim_icache_fetch(456 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L46X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L46X3;
} /* line 1014 */
l_L44X3: ;/* line 1017 */
LABEL(l_L44X3);
  sim_icache_fetch(457 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBU(reg_r0_3, mem_trace_ld(reg_r0_59,0,1)); /* line 1018 */
   MOV(reg_r0_4, reg_r0_57); /* line 1019 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1020 */
   ADD_CYCLES(1);
} /* line 1020 */
		 /* line 1021 */
  sim_icache_fetch(460 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__swbuf);
   reg_l0_0 = (224 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __swbuf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 1023 */
l_lr_102: ;/* line 1023 */
LABEL(l_lr_102);
  sim_icache_fetch(462 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_3); /* line 1025 */
   LDWs(reg_r0_7, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 1026 */
} /* line 1026 */
  sim_icache_fetch(465 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX33); /* line 1028 */
   MOV(reg_r0_5, reg_r0_60); /* line 1029 */
} /* line 1029 */
  sim_icache_fetch(468 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_61); /* line 1031 */
   GOTO(l_L47X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L47X3;
} /* line 1032 */
l_L43X3: ;/* line 1035 */
LABEL(l_L43X3);
  sim_icache_fetch(470 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBU(reg_r0_3, mem_trace_ld(reg_r0_59,0,1)); /* line 1036 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX33); /* line 1037 */
} /* line 1037 */
  sim_icache_fetch(473 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_8, mem_trace_ld(reg_r0_57,0,4)); /* line 1039 */
   MOV(reg_r0_5, reg_r0_60); /* line 1040 */
} /* line 1040 */
  sim_icache_fetch(475 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_61); /* line 1042 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1043 */
   ADD_CYCLES(1);
} /* line 1043 */
  sim_icache_fetch(477 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_8,0,1), reg_r0_3); /* line 1045 */
} /* line 1045 */
  sim_icache_fetch(478 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld(reg_r0_57,0,4)); /* line 1047 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 1048 */
   ADD_CYCLES(2);
} /* line 1048 */
  sim_icache_fetch(480 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_3, (unsigned int) 1); /* line 1050 */
} /* line 1050 */
  sim_icache_fetch(481 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_57,0,4), reg_r0_8); /* line 1052 */
} /* line 1052 */
  sim_icache_fetch(482 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_2, mem_trace_ld(reg_r0_3,0,1)); /* line 1054 */
} /* line 1054 */
  sim_icache_fetch(483 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 1056 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 1057 */
   ADD_CYCLES(2);
} /* line 1057 */
  sim_icache_fetch(486 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) 12),0,4)); /* line 1059 */
   GOTO(l_L48X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L48X3;
} /* line 1060 */
l_L42X3: ;/* line 1063 */
LABEL(l_L42X3);
  sim_icache_fetch(488 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 1064 */
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1065 */
} /* line 1065 */
  sim_icache_fetch(490 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_2, reg_r0_62, (unsigned int) 1); /* line 1067 */
   MOV(reg_r0_3, reg_r0_63); /* line 1068 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1069 */
   ADD_CYCLES(1);
} /* line 1069 */
  sim_icache_fetch(493 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 1071 */
   GOTO(l_L39X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L39X3;
} /* line 1072 */
l_L40X3: ;/* line 1075 */
LABEL(l_L40X3);
		 /* line 1075 */
  sim_icache_fetch(495 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_57); /* line 1078 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fclose);
   reg_l0_0 = (224 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) fclose;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1078 */
l_lr_107: ;/* line 1078 */
LABEL(l_lr_107);
  sim_icache_fetch(498 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 1080 */
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1081 */
} /* line 1081 */
  sim_icache_fetch(500 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1083 */
} /* line 1083 */
  sim_icache_fetch(501 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1085 */
} /* line 1085 */
  sim_icache_fetch(502 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1087 */
} /* line 1087 */
  sim_icache_fetch(503 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1089 */
} /* line 1089 */
  sim_icache_fetch(504 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 1091 */
} /* line 1091 */
  sim_icache_fetch(505 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 1093 */
} /* line 1093 */
  sim_icache_fetch(506 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 1095 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1096 */
   ADD_CYCLES(1);
} /* line 1096 */
  sim_icache_fetch(508 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(save_pgm);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 96; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1099 */
l_L37X3: ;/* line 1102 */
LABEL(l_L37X3);
  sim_icache_fetch(509 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 1103 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX32); /* line 1104 */
} /* line 1104 */
  sim_icache_fetch(512 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 106); /* line 1106 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX31); /* line 1107 */
} /* line 1107 */
		 /* line 1108 */
  sim_icache_fetch(515 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 68),0,4), reg_r0_57); /* line 1111 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (224 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1111 */
l_lr_110: ;/* line 1111 */
LABEL(l_lr_110);
  sim_icache_fetch(518 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, 0); /* line 1113 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 1114 */
} /* line 1114 */
  sim_icache_fetch(520 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 1116 */
} /* line 1116 */
  sim_icache_fetch(521 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 1118 */
} /* line 1118 */
  sim_icache_fetch(522 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_4); /* line 1120 */
} /* line 1120 */
  sim_icache_fetch(523 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_2, reg_r0_4); /* line 1122 */
   MOV(reg_r0_5, reg_r0_6); /* line 1123 */
} /* line 1123 */
  sim_icache_fetch(525 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 1125 */
   GOTO(l_L38X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L38X3;
} /* line 1126 */
l_L35X3: ;/* line 1129 */
LABEL(l_L35X3);
  sim_icache_fetch(527 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 1130 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX30); /* line 1131 */
} /* line 1131 */
  sim_icache_fetch(530 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 105); /* line 1133 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX29); /* line 1134 */
} /* line 1134 */
		 /* line 1135 */
  sim_icache_fetch(533 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (224 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1137 */
l_lr_113: ;/* line 1137 */
LABEL(l_lr_113);
  sim_icache_fetch(535 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, 0); /* line 1139 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 1140 */
} /* line 1140 */
  sim_icache_fetch(537 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 1142 */
} /* line 1142 */
  sim_icache_fetch(538 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 1144 */
} /* line 1144 */
  sim_icache_fetch(539 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_4); /* line 1146 */
} /* line 1146 */
  sim_icache_fetch(540 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLE(reg_b0_3, reg_r0_3, (unsigned int) 1500); /* line 1148 */
   MOV(reg_r0_2, reg_r0_4); /* line 1149 */
} /* line 1149 */
  sim_icache_fetch(543 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_6); /* line 1151 */
   GOTO(l_L36X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L36X3;
} /* line 1152 */
l_L33X3: ;/* line 1155 */
LABEL(l_L33X3);
  sim_icache_fetch(545 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 1156 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX28); /* line 1157 */
} /* line 1157 */
  sim_icache_fetch(548 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 104); /* line 1159 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX27); /* line 1160 */
} /* line 1160 */
		 /* line 1161 */
  sim_icache_fetch(551 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (224 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1163 */
l_lr_116: ;/* line 1163 */
LABEL(l_lr_116);
  sim_icache_fetch(553 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, 0); /* line 1165 */
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 1166 */
} /* line 1166 */
  sim_icache_fetch(555 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 1168 */
} /* line 1168 */
  sim_icache_fetch(556 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 1170 */
} /* line 1170 */
  sim_icache_fetch(557 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_5); /* line 1172 */
} /* line 1172 */
  sim_icache_fetch(558 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_2, reg_r0_3, 0); /* line 1174 */
   MOV(reg_r0_2, reg_r0_4); /* line 1175 */
} /* line 1175 */
  sim_icache_fetch(560 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLE(reg_b0_3, reg_r0_3, (unsigned int) 1500); /* line 1177 */
} /* line 1177 */
  sim_icache_fetch(562 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L34X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L34X3;
} /* line 1179 */
l_L31X3: ;/* line 1182 */
LABEL(l_L31X3);
  sim_icache_fetch(563 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 1183 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX26); /* line 1184 */
} /* line 1184 */
  sim_icache_fetch(566 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) 103); /* line 1186 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX25); /* line 1187 */
} /* line 1187 */
		 /* line 1188 */
  sim_icache_fetch(569 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (224 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1190 */
l_lr_119: ;/* line 1190 */
LABEL(l_lr_119);
  sim_icache_fetch(571 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, 0); /* line 1192 */
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 1193 */
} /* line 1193 */
  sim_icache_fetch(573 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 1195 */
} /* line 1195 */
  sim_icache_fetch(574 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 1197 */
} /* line 1197 */
  sim_icache_fetch(575 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLE(reg_b0_1, reg_r0_5, (unsigned int) 1050); /* line 1199 */
   SUB(reg_r0_4, 0, reg_r0_5); /* line 1200 */
} /* line 1200 */
  sim_icache_fetch(578 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_2, reg_r0_3, 0); /* line 1202 */
   CMPLE(reg_b0_3, reg_r0_3, (unsigned int) 1500); /* line 1203 */
} /* line 1203 */
  sim_icache_fetch(581 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L32X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L32X3;
} /* line 1205 */
l_L30X3: ;/* line 1208 */
LABEL(l_L30X3);
  sim_icache_fetch(582 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_2, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 1209 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX34); /* line 1210 */
} /* line 1210 */
  sim_icache_fetch(586 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 64),0,4)); /* line 1212 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1213 */
   ADD_CYCLES(1);
} /* line 1213 */
  sim_icache_fetch(588 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 1215 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1216 */
   ADD_CYCLES(1);
} /* line 1216 */
		 /* line 1217 */
  sim_icache_fetch(590 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fprintf);
   reg_l0_0 = (224 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fprintf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1219 */
l_lr_122: ;/* line 1219 */
LABEL(l_lr_122);
  sim_icache_fetch(592 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) -1); /* line 1221 */
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1222 */
} /* line 1222 */
  sim_icache_fetch(594 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1224 */
} /* line 1224 */
  sim_icache_fetch(595 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1226 */
} /* line 1226 */
  sim_icache_fetch(596 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1228 */
} /* line 1228 */
  sim_icache_fetch(597 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1230 */
} /* line 1230 */
  sim_icache_fetch(598 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 1232 */
} /* line 1232 */
  sim_icache_fetch(599 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 1234 */
} /* line 1234 */
  sim_icache_fetch(600 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 1236 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1237 */
   ADD_CYCLES(1);
} /* line 1237 */
  sim_icache_fetch(602 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(save_pgm);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 96; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1240 */
  reg_l0_0 = t_client_rpc;
  return reg_r0_3;

labelfinder:
  switch (t_labelnum >> 5) {
    case 175: goto l_lr_74;
    case 177: goto l_lr_76;
    case 179: goto l_lr_78;
    case 181: goto l_lr_80;
    case 182: goto l_L32X3;
    case 183: goto l_L34X3;
    case 184: goto l_L36X3;
    case 185: goto l_L38X3;
    case 186: goto l_L39X3;
    case 187: goto l_L41X3;
    case 188: goto l_L46X3;
    case 189: goto l_L47X3;
    case 190: goto l_L48X3;
    case 192: goto l_lr_91;
    case 194: goto l_lr_93;
    case 196: goto l_lr_95;
    case 197: goto l_L49X3;
    case 198: goto l_L45X3;
    case 200: goto l_lr_99;
    case 201: goto l_L44X3;
    case 203: goto l_lr_102;
    case 204: goto l_L43X3;
    case 205: goto l_L42X3;
    case 206: goto l_L40X3;
    case 208: goto l_lr_107;
    case 209: goto l_L37X3;
    case 211: goto l_lr_110;
    case 212: goto l_L35X3;
    case 214: goto l_lr_113;
    case 215: goto l_L33X3;
    case 217: goto l_lr_116;
    case 218: goto l_L31X3;
    case 220: goto l_lr_119;
    case 221: goto l_L30X3;
    case 223: goto l_lr_122;
    case 224:
      reg_l0_0 = t_client_rpc;
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"pgm.s", 608, 0, 0, 0, 2};


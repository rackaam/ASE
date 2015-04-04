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
		 /* line 44 */
  sim_icache_fetch(13 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_58, reg_r0_1, (unsigned int) 16); /* line 46 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 176),0,4), reg_r0_57); /* line 48 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fopen);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fopen;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 48 */
l_lr_1: ;/* line 48 */
LABEL(l_lr_1);
  sim_icache_fetch(17 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPNE(reg_b0_0, reg_r0_3, 0); /* line 50 */
   ADD(reg_r0_62, reg_r0_1, (unsigned int) 144); /* line 51 */
   MOV(reg_r0_57, 0); /* line 52 */
   MOV(reg_r0_59, reg_r0_3); /* line 53 */
} /* line 53 */
  sim_icache_fetch(21 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 180),0,4)); /* line 55 */
} /* line 55 */
  sim_icache_fetch(22 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 184),0,4)); /* line 57 */
} /* line 57 */
  sim_icache_fetch(23 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 188),0,4)); /* line 59 */
} /* line 59 */
  sim_icache_fetch(24 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 144),0,4), 0); /* line 61 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L0X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 62 */
  sim_icache_fetch(26 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 63 */
l_L1X3: ;/* line 66 */
LABEL(l_L1X3);
  sim_icache_fetch(27 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPLT(reg_b0_0, reg_r0_57, (unsigned int) 5); /* line 67 */
   CMPEQ(reg_b0_1, reg_r0_57, 0); /* line 68 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX2); /* line 69 */
} /* line 69 */
  sim_icache_fetch(31 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 71 */
   MOV(reg_r0_5, reg_r0_58); /* line 72 */
} /* line 72 */
  sim_icache_fetch(33 + t_thisfile.offset, 1);
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
} /* line 74 */
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
} /* line 76 */
		 /* line 77 */
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
} /* line 79 */
l_lr_4: ;/* line 79 */
LABEL(l_lr_4);
  sim_icache_fetch(37 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_2, mem_trace_ld((unsigned int) verbose,0,4)); /* line 81 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 82 */
} /* line 82 */
  sim_icache_fetch(41 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_58); /* line 84 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 85 */
   ADD_CYCLES(1);
} /* line 85 */
  sim_icache_fetch(43 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_2, 0); /* line 87 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 88 */
   ADD_CYCLES(1);
} /* line 88 */
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
} /* line 90 */
		 /* line 91 */
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
} /* line 93 */
l_lr_6: ;/* line 93 */
LABEL(l_lr_6);
l_L4X3: ;/* line 95 */
LABEL(l_L4X3);
		 /* line 95 */
  sim_icache_fetch(48 + t_thisfile.offset, 5);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 98 */
   MOV(reg_r0_4, reg_r0_58); /* line 99 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(strcmp);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) strcmp;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 99 */
l_lr_9: ;/* line 99 */
LABEL(l_lr_9);
  sim_icache_fetch(53 + t_thisfile.offset, 5);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPEQ(reg_b0_0, reg_r0_3, 0); /* line 101 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX5); /* line 102 */
   MOV(reg_r0_5, reg_r0_58); /* line 103 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 104 */
   ADD_CYCLES(1);
} /* line 104 */
  sim_icache_fetch(58 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 106 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L5X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 107 */
		 /* line 108 */
  sim_icache_fetch(60 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, (unsigned int) 1); /* line 110 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fscanf);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fscanf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 111 */
l_lr_11: ;/* line 111 */
LABEL(l_lr_11);
  sim_icache_fetch(63 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 113 */
l_L5X3: ;/* line 116 */
LABEL(l_L5X3);
		 /* line 116 */
  sim_icache_fetch(64 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) -1); /* line 120 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(exit);
   reg_l0_0 = (173 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) exit;
    (*t_call)(reg_r0_3);
   }
} /* line 120 */
l_lr_14: ;/* line 120 */
LABEL(l_lr_14);
  sim_icache_fetch(67 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 122 */
l_L3X3: ;/* line 125 */
LABEL(l_L3X3);
  sim_icache_fetch(68 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPEQ(reg_b0_0, reg_r0_57, (unsigned int) 1); /* line 126 */
   LDBs(reg_r0_6, mem_trace_ld(reg_r0_58,0,1)); /* line 127 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX6); /* line 128 */
} /* line 128 */
  sim_icache_fetch(72 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 130 */
   MOV(reg_r0_5, reg_r0_58); /* line 131 */
} /* line 131 */
  sim_icache_fetch(74 + t_thisfile.offset, 1);
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
} /* line 133 */
  sim_icache_fetch(75 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPEQ(reg_b0_0, reg_r0_6, (unsigned int) 35); /* line 135 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 136 */
   ADD_CYCLES(1);
} /* line 136 */
  sim_icache_fetch(77 + t_thisfile.offset, 1);
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
} /* line 138 */
		 /* line 139 */
  sim_icache_fetch(78 + t_thisfile.offset, 2);
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
} /* line 141 */
l_lr_17: ;/* line 141 */
LABEL(l_lr_17);
  sim_icache_fetch(80 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_5, mem_trace_ld((unsigned int) verbose,0,4)); /* line 143 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX7); /* line 144 */
} /* line 144 */
  sim_icache_fetch(84 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_58); /* line 146 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 147 */
   ADD_CYCLES(1);
} /* line 147 */
  sim_icache_fetch(86 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_5, 0); /* line 149 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 150 */
   ADD_CYCLES(1);
} /* line 150 */
  sim_icache_fetch(88 + t_thisfile.offset, 1);
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
} /* line 152 */
		 /* line 153 */
  sim_icache_fetch(89 + t_thisfile.offset, 2);
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
} /* line 155 */
l_lr_19: ;/* line 155 */
LABEL(l_lr_19);
l_L8X3: ;/* line 157 */
LABEL(l_L8X3);
  sim_icache_fetch(91 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 157 */
l_L9X3: ;/* line 160 */
LABEL(l_L9X3);
  sim_icache_fetch(92 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_59 + (unsigned int) 4),0,4)); /* line 161 */
   MOV(reg_r0_3, reg_r0_59); /* line 162 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 163 */
   ADD_CYCLES(2);
} /* line 163 */
  sim_icache_fetch(95 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 165 */
} /* line 165 */
  sim_icache_fetch(96 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_59 + (unsigned int) 4),0,4), reg_r0_2); /* line 167 */
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 168 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 169 */
   ADD_CYCLES(1);
} /* line 169 */
  sim_icache_fetch(99 + t_thisfile.offset, 1);
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
} /* line 171 */
		 /* line 172 */
  sim_icache_fetch(100 + t_thisfile.offset, 2);
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
} /* line 174 */
l_lr_23: ;/* line 174 */
LABEL(l_lr_23);
  sim_icache_fetch(102 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 176 */
l_L11X3: ;/* line 178 */
LABEL(l_L11X3);
  sim_icache_fetch(103 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_3, (unsigned int) 10); /* line 179 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 180 */
   ADD_CYCLES(1);
} /* line 180 */
  sim_icache_fetch(105 + t_thisfile.offset, 1);
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
} /* line 183 */
  sim_icache_fetch(106 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L9X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L9X3;
} /* line 185 */
l_L7X3: ;/* line 188 */
LABEL(l_L7X3);
  sim_icache_fetch(107 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, (unsigned int) 2); /* line 189 */
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 190 */
l_L10X3: ;/* line 193 */
LABEL(l_L10X3);
  sim_icache_fetch(109 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld(reg_r0_59,0,4)); /* line 194 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 195 */
   ADD_CYCLES(2);
} /* line 195 */
  sim_icache_fetch(111 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 197 */
} /* line 197 */
  sim_icache_fetch(112 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_59,0,4), reg_r0_4); /* line 199 */
} /* line 199 */
  sim_icache_fetch(113 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 201 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 202 */
   ADD_CYCLES(1);
} /* line 202 */
  sim_icache_fetch(115 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L11X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L11X3;
} /* line 204 */
l_L6X3: ;/* line 207 */
LABEL(l_L6X3);
  sim_icache_fetch(116 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPEQ(reg_b0_0, reg_r0_57, (unsigned int) 2); /* line 208 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX8); /* line 209 */
   MOV(reg_r0_3, reg_r0_58); /* line 210 */
} /* line 210 */
  sim_icache_fetch(120 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_60); /* line 212 */
} /* line 212 */
  sim_icache_fetch(121 + t_thisfile.offset, 1);
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
} /* line 214 */
		 /* line 215 */
  sim_icache_fetch(122 + t_thisfile.offset, 2);
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
} /* line 217 */
l_lr_29: ;/* line 217 */
LABEL(l_lr_29);
  sim_icache_fetch(124 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_5, mem_trace_ld((unsigned int) verbose,0,4)); /* line 219 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 220 */
} /* line 220 */
  sim_icache_fetch(128 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_60,0,4)); /* line 222 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 223 */
   ADD_CYCLES(1);
} /* line 223 */
  sim_icache_fetch(130 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_5, 0); /* line 225 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 226 */
   ADD_CYCLES(1);
} /* line 226 */
  sim_icache_fetch(132 + t_thisfile.offset, 1);
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
} /* line 228 */
		 /* line 229 */
  sim_icache_fetch(133 + t_thisfile.offset, 2);
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
} /* line 231 */
l_lr_31: ;/* line 231 */
LABEL(l_lr_31);
l_L13X3: ;/* line 233 */
LABEL(l_L13X3);
  sim_icache_fetch(135 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, (unsigned int) 3); /* line 234 */
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 235 */
l_L12X3: ;/* line 238 */
LABEL(l_L12X3);
  sim_icache_fetch(137 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPEQ(reg_b0_0, reg_r0_57, (unsigned int) 3); /* line 239 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX10); /* line 240 */
   MOV(reg_r0_3, reg_r0_59); /* line 241 */
} /* line 241 */
  sim_icache_fetch(141 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_61); /* line 243 */
} /* line 243 */
  sim_icache_fetch(142 + t_thisfile.offset, 1);
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
} /* line 245 */
		 /* line 246 */
  sim_icache_fetch(143 + t_thisfile.offset, 2);
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
} /* line 248 */
l_lr_35: ;/* line 248 */
LABEL(l_lr_35);
  sim_icache_fetch(145 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_5, mem_trace_ld((unsigned int) verbose,0,4)); /* line 250 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX11); /* line 251 */
} /* line 251 */
  sim_icache_fetch(149 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_61,0,4)); /* line 253 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 254 */
   ADD_CYCLES(1);
} /* line 254 */
  sim_icache_fetch(151 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_5, 0); /* line 256 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 257 */
   ADD_CYCLES(1);
} /* line 257 */
  sim_icache_fetch(153 + t_thisfile.offset, 1);
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
} /* line 259 */
		 /* line 260 */
  sim_icache_fetch(154 + t_thisfile.offset, 2);
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
} /* line 262 */
l_lr_37: ;/* line 262 */
LABEL(l_lr_37);
l_L15X3: ;/* line 264 */
LABEL(l_L15X3);
  sim_icache_fetch(156 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, (unsigned int) 4); /* line 265 */
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 266 */
l_L14X3: ;/* line 269 */
LABEL(l_L14X3);
  sim_icache_fetch(158 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPEQ(reg_b0_0, reg_r0_57, (unsigned int) 4); /* line 270 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX12); /* line 271 */
   MOV(reg_r0_3, reg_r0_59); /* line 272 */
} /* line 272 */
  sim_icache_fetch(162 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_62); /* line 274 */
} /* line 274 */
  sim_icache_fetch(163 + t_thisfile.offset, 1);
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
} /* line 276 */
		 /* line 277 */
  sim_icache_fetch(164 + t_thisfile.offset, 2);
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
} /* line 279 */
l_lr_41: ;/* line 279 */
LABEL(l_lr_41);
  sim_icache_fetch(166 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_5, mem_trace_ld((unsigned int) verbose,0,4)); /* line 281 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX13); /* line 282 */
} /* line 282 */
  sim_icache_fetch(170 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 144),0,4)); /* line 284 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 285 */
   ADD_CYCLES(1);
} /* line 285 */
  sim_icache_fetch(172 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_5, 0); /* line 287 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 288 */
   ADD_CYCLES(1);
} /* line 288 */
  sim_icache_fetch(174 + t_thisfile.offset, 1);
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
} /* line 290 */
		 /* line 291 */
  sim_icache_fetch(175 + t_thisfile.offset, 2);
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
} /* line 293 */
l_lr_43: ;/* line 293 */
LABEL(l_lr_43);
l_L16X3: ;/* line 295 */
LABEL(l_L16X3);
  sim_icache_fetch(177 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_57, (unsigned int) 5); /* line 296 */
   GOTO(l_L1X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L1X3;
} /* line 297 */
l_L2X3: ;/* line 300 */
LABEL(l_L2X3);
  sim_icache_fetch(179 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   LDW(reg_r0_3, mem_trace_ld(reg_r0_61,0,4)); /* line 301 */
   MOV(reg_r0_5, reg_r0_63); /* line 302 */
   MOV(reg_r0_4, 0); /* line 303 */
   MOV(reg_r0_2, reg_r0_61); /* line 304 */
} /* line 304 */
  sim_icache_fetch(183 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_7, mem_trace_ld(reg_r0_61,0,4)); /* line 306 */
   MOV(reg_r0_57, reg_r0_60); /* line 307 */
} /* line 307 */
  sim_icache_fetch(185 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_60,0,4)); /* line 309 */
} /* line 309 */
  sim_icache_fetch(186 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_0, reg_r0_3, 0); /* line 311 */
   LDWs(reg_r0_9, mem_trace_ld(reg_r0_60,0,4)); /* line 312 */
} /* line 312 */
  sim_icache_fetch(188 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLE(reg_b0_1, reg_r0_7, (unsigned int) 1050); /* line 314 */
} /* line 314 */
  sim_icache_fetch(190 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_0, reg_r0_8, 0); /* line 316 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L17X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 317 */
l_L18X3: ;/* line 319 */
LABEL(l_L18X3);
  sim_icache_fetch(192 + t_thisfile.offset, 3);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_1 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLE(reg_b0_1, reg_r0_9, (unsigned int) 1500); /* line 320 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L19X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 321 */
l_L20X3: ;/* line 323 */
LABEL(l_L20X3);
  sim_icache_fetch(195 + t_thisfile.offset, 1);
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
} /* line 324 */
l_L22X3: ;/* line 326 */
LABEL(l_L22X3);
  sim_icache_fetch(196 + t_thisfile.offset, 1);
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
} /* line 327 */
l_L24X3: ;/* line 330 */
LABEL(l_L24X3);
  sim_icache_fetch(197 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   LDW(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 331 */
   MOV(reg_r0_60, reg_r0_5); /* line 332 */
   MOV(reg_r0_58, 0); /* line 333 */
   MOV(reg_r0_61, reg_r0_2); /* line 334 */
} /* line 334 */
  sim_icache_fetch(201 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_62, reg_r0_4); /* line 336 */
   MOV(reg_r0_63, reg_r0_5); /* line 337 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 338 */
   ADD_CYCLES(1);
} /* line 338 */
  sim_icache_fetch(204 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_4, reg_r0_3); /* line 340 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 341 */
   ADD_CYCLES(1);
} /* line 341 */
  sim_icache_fetch(206 + t_thisfile.offset, 1);
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
} /* line 343 */
l_L26X3: ;/* line 346 */
LABEL(l_L26X3);
  sim_icache_fetch(207 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_2, mem_trace_ld(reg_r0_57,0,4)); /* line 347 */
   MOV(reg_r0_3, reg_r0_59); /* line 348 */
} /* line 348 */
  sim_icache_fetch(209 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld((reg_r0_59 + (unsigned int) 4),0,4)); /* line 350 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 351 */
   ADD_CYCLES(1);
} /* line 351 */
  sim_icache_fetch(211 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, reg_r0_2); /* line 353 */
} /* line 353 */
  sim_icache_fetch(212 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) -1); /* line 355 */
} /* line 355 */
  sim_icache_fetch(213 + t_thisfile.offset, 2);
{
  unsigned int t__i32_0;
  t__i32_0 = reg_b0_0 ;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLT(reg_b0_0, reg_r0_4, 0); /* line 357 */
   if (!t__i32_0) {    BRANCHF(t__i32_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L27X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 358 */
  sim_icache_fetch(215 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_59 + (unsigned int) 4),0,4), reg_r0_4); /* line 360 */
} /* line 360 */
  sim_icache_fetch(216 + t_thisfile.offset, 1);
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
} /* line 362 */
		 /* line 363 */
  sim_icache_fetch(217 + t_thisfile.offset, 2);
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
} /* line 365 */
l_lr_52: ;/* line 365 */
LABEL(l_lr_52);
  sim_icache_fetch(219 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 368 */
} /* line 368 */
l_L29X3: ;/* line 370 */
LABEL(l_L29X3);
  sim_icache_fetch(220 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_60,0,1), reg_r0_3); /* line 371 */
} /* line 371 */
  sim_icache_fetch(221 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1050); /* line 373 */
   GOTO(l_L26X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L26X3;
} /* line 374 */
l_L28X3: ;/* line 377 */
LABEL(l_L28X3);
  sim_icache_fetch(224 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_2, mem_trace_ld(reg_r0_59,0,4)); /* line 378 */
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 379 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 380 */
   ADD_CYCLES(2);
} /* line 380 */
  sim_icache_fetch(227 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_2, (unsigned int) 1); /* line 382 */
} /* line 382 */
  sim_icache_fetch(228 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_59,0,4), reg_r0_4); /* line 384 */
} /* line 384 */
  sim_icache_fetch(229 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 386 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 387 */
   ADD_CYCLES(1);
} /* line 387 */
  sim_icache_fetch(231 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L29X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L29X3;
} /* line 389 */
l_L27X3: ;/* line 392 */
LABEL(l_L27X3);
  sim_icache_fetch(232 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_5, reg_r0_63, (unsigned int) 1); /* line 393 */
   ADD(reg_r0_4, reg_r0_62, (unsigned int) 1); /* line 394 */
   MOV(reg_r0_2, reg_r0_61); /* line 395 */
   GOTO(l_L24X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L24X3;
} /* line 396 */
l_L25X3: ;/* line 399 */
LABEL(l_L25X3);
		 /* line 399 */
  sim_icache_fetch(236 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_59); /* line 402 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fclose);
   reg_l0_0 = (173 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) fclose;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 402 */
l_lr_58: ;/* line 402 */
LABEL(l_lr_58);
  sim_icache_fetch(239 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 404 */
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 148),0,4)); /* line 405 */
} /* line 405 */
  sim_icache_fetch(241 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 152),0,4)); /* line 407 */
} /* line 407 */
  sim_icache_fetch(242 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 156),0,4)); /* line 409 */
} /* line 409 */
  sim_icache_fetch(243 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 160),0,4)); /* line 411 */
} /* line 411 */
  sim_icache_fetch(244 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 164),0,4)); /* line 413 */
} /* line 413 */
  sim_icache_fetch(245 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 168),0,4)); /* line 415 */
} /* line 415 */
  sim_icache_fetch(246 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 172),0,4)); /* line 417 */
} /* line 417 */
  sim_icache_fetch(247 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 176),0,4)); /* line 419 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 420 */
   ADD_CYCLES(1);
} /* line 420 */
  sim_icache_fetch(249 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(load_pgm);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 192; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 423 */
l_L23X3: ;/* line 426 */
LABEL(l_L23X3);
  sim_icache_fetch(250 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 184),0,4), reg_r0_2); /* line 427 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX21); /* line 428 */
   MOV(reg_r0_4, (unsigned int) 82); /* line 429 */
} /* line 429 */
		 /* line 430 */
  sim_icache_fetch(254 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX20); /* line 433 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (173 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 433 */
l_lr_61: ;/* line 433 */
LABEL(l_lr_61);
  sim_icache_fetch(258 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_5, reg_r0_63); /* line 435 */
   MOV(reg_r0_4, 0); /* line 436 */
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 184),0,4)); /* line 437 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 438 */
   ADD_CYCLES(1);
} /* line 438 */
  sim_icache_fetch(262 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L24X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L24X3;
} /* line 440 */
l_L21X3: ;/* line 443 */
LABEL(l_L21X3);
  sim_icache_fetch(263 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 184),0,4), reg_r0_2); /* line 444 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX19); /* line 445 */
   MOV(reg_r0_4, (unsigned int) 81); /* line 446 */
} /* line 446 */
		 /* line 447 */
  sim_icache_fetch(267 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX18); /* line 450 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (173 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 450 */
l_lr_64: ;/* line 450 */
LABEL(l_lr_64);
  sim_icache_fetch(271 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   LDW(reg_r0_9, mem_trace_ld(reg_r0_57,0,4)); /* line 452 */
   MOV(reg_r0_5, reg_r0_63); /* line 453 */
   MOV(reg_r0_4, 0); /* line 454 */
} /* line 454 */
  sim_icache_fetch(274 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 184),0,4)); /* line 456 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 457 */
   ADD_CYCLES(1);
} /* line 457 */
  sim_icache_fetch(276 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLE(reg_b0_1, reg_r0_9, (unsigned int) 1500); /* line 459 */
} /* line 459 */
  sim_icache_fetch(278 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L22X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L22X3;
} /* line 461 */
l_L19X3: ;/* line 464 */
LABEL(l_L19X3);
  sim_icache_fetch(279 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 184),0,4), reg_r0_2); /* line 465 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX17); /* line 466 */
   MOV(reg_r0_4, (unsigned int) 80); /* line 467 */
} /* line 467 */
		 /* line 468 */
  sim_icache_fetch(283 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX16); /* line 471 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (173 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 471 */
l_lr_67: ;/* line 471 */
LABEL(l_lr_67);
  sim_icache_fetch(287 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   LDW(reg_r0_8, mem_trace_ld(reg_r0_57,0,4)); /* line 473 */
   MOV(reg_r0_5, reg_r0_63); /* line 474 */
   MOV(reg_r0_4, 0); /* line 475 */
} /* line 475 */
  sim_icache_fetch(290 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld(reg_r0_57,0,4)); /* line 477 */
} /* line 477 */
  sim_icache_fetch(291 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 184),0,4)); /* line 479 */
} /* line 479 */
  sim_icache_fetch(292 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_8, 0); /* line 481 */
} /* line 481 */
  sim_icache_fetch(293 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLE(reg_b0_1, reg_r0_9, (unsigned int) 1500); /* line 483 */
   GOTO(l_L20X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L20X3;
} /* line 484 */
l_L17X3: ;/* line 487 */
LABEL(l_L17X3);
  sim_icache_fetch(296 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 184),0,4), reg_r0_2); /* line 488 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX15); /* line 489 */
   MOV(reg_r0_4, (unsigned int) 79); /* line 490 */
} /* line 490 */
		 /* line 491 */
  sim_icache_fetch(300 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX14); /* line 494 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (173 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 494 */
l_lr_70: ;/* line 494 */
LABEL(l_lr_70);
  sim_icache_fetch(304 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_5, reg_r0_63); /* line 496 */
   MOV(reg_r0_4, 0); /* line 497 */
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 184),0,4)); /* line 498 */
} /* line 498 */
  sim_icache_fetch(307 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_57,0,4)); /* line 500 */
} /* line 500 */
  sim_icache_fetch(308 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld(reg_r0_57,0,4)); /* line 502 */
} /* line 502 */
  sim_icache_fetch(309 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_7, mem_trace_ld(reg_r0_2,0,4)); /* line 504 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 505 */
   ADD_CYCLES(2);
} /* line 505 */
  sim_icache_fetch(311 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLE(reg_b0_1, reg_r0_7, (unsigned int) 1050); /* line 507 */
} /* line 507 */
  sim_icache_fetch(313 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPGT(reg_b0_0, reg_r0_8, 0); /* line 509 */
   GOTO(l_L18X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L18X3;
} /* line 510 */
l_L0X3: ;/* line 513 */
LABEL(l_L0X3);
  sim_icache_fetch(315 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) -1); /* line 514 */
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 148),0,4)); /* line 515 */
} /* line 515 */
  sim_icache_fetch(317 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 152),0,4)); /* line 517 */
} /* line 517 */
  sim_icache_fetch(318 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 156),0,4)); /* line 519 */
} /* line 519 */
  sim_icache_fetch(319 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 160),0,4)); /* line 521 */
} /* line 521 */
  sim_icache_fetch(320 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 164),0,4)); /* line 523 */
} /* line 523 */
  sim_icache_fetch(321 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 168),0,4)); /* line 525 */
} /* line 525 */
  sim_icache_fetch(322 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 172),0,4)); /* line 527 */
} /* line 527 */
  sim_icache_fetch(323 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 176),0,4)); /* line 529 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 530 */
   ADD_CYCLES(1);
} /* line 530 */
  sim_icache_fetch(325 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(load_pgm);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 192; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 533 */
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
  reg_l0_0 = (223 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(326 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_1, reg_r0_1, (unsigned int) -96); /* line 797 */
} /* line 797 */
  sim_icache_fetch(327 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 799 */
} /* line 799 */
  sim_icache_fetch(328 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 52),0,4), reg_r0_6); /* line 801 */
} /* line 801 */
  sim_icache_fetch(329 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_63); /* line 803 */
} /* line 803 */
  sim_icache_fetch(330 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_62); /* line 805 */
} /* line 805 */
  sim_icache_fetch(331 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_61); /* line 807 */
} /* line 807 */
  sim_icache_fetch(332 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_60); /* line 809 */
} /* line 809 */
  sim_icache_fetch(333 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_59); /* line 811 */
} /* line 811 */
  sim_icache_fetch(334 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 44),0,4), reg_r0_58); /* line 813 */
} /* line 813 */
  sim_icache_fetch(335 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 48),0,4), reg_r0_57); /* line 815 */
} /* line 815 */
  sim_icache_fetch(336 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 56),0,4), reg_r0_5); /* line 817 */
} /* line 817 */
  sim_icache_fetch(337 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_4); /* line 819 */
} /* line 819 */
		 /* line 820 */
  sim_icache_fetch(338 + t_thisfile.offset, 5);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX22); /* line 823 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 64),0,4), reg_r0_3); /* line 824 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fopen);
   reg_l0_0 = (223 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fopen;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 824 */
l_lr_74: ;/* line 824 */
LABEL(l_lr_74);
  sim_icache_fetch(343 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 68),0,4), reg_r0_3); /* line 826 */
} /* line 826 */
  sim_icache_fetch(344 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX23); /* line 828 */
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 829 */
} /* line 829 */
  sim_icache_fetch(347 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 831 */
} /* line 831 */
  sim_icache_fetch(348 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 64),0,4)); /* line 833 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 834 */
   ADD_CYCLES(1);
} /* line 834 */
		 /* line 835 */
  sim_icache_fetch(350 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (223 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 837 */
l_lr_76: ;/* line 837 */
LABEL(l_lr_76);
  sim_icache_fetch(352 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 839 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 840 */
   ADD_CYCLES(2);
} /* line 840 */
  sim_icache_fetch(355 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 842 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 843 */
   ADD_CYCLES(1);
} /* line 843 */
		 /* line 844 */
  sim_icache_fetch(357 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fflush);
   reg_l0_0 = (223 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) fflush;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 846 */
l_lr_78: ;/* line 846 */
LABEL(l_lr_78);
  sim_icache_fetch(359 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX24); /* line 848 */
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 849 */
} /* line 849 */
  sim_icache_fetch(362 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 851 */
} /* line 851 */
  sim_icache_fetch(363 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 853 */
} /* line 853 */
  sim_icache_fetch(364 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_3, 0); /* line 855 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 856 */
   ADD_CYCLES(1);
} /* line 856 */
  sim_icache_fetch(366 + t_thisfile.offset, 1);
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
} /* line 858 */
		 /* line 859 */
  sim_icache_fetch(367 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fprintf);
   reg_l0_0 = (223 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fprintf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 861 */
l_lr_80: ;/* line 861 */
LABEL(l_lr_80);
  sim_icache_fetch(369 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, 0); /* line 863 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 864 */
} /* line 864 */
  sim_icache_fetch(371 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 866 */
} /* line 866 */
  sim_icache_fetch(372 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 868 */
} /* line 868 */
  sim_icache_fetch(373 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPGT(reg_b0_0, reg_r0_4, 0); /* line 870 */
   CMPLE(reg_b0_1, reg_r0_4, (unsigned int) 1050); /* line 871 */
   SUB(reg_r0_7, 0, reg_r0_4); /* line 872 */
} /* line 872 */
  sim_icache_fetch(377 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPGT(reg_b0_2, reg_r0_3, 0); /* line 874 */
   CMPLE(reg_b0_3, reg_r0_3, (unsigned int) 1500); /* line 875 */
   MOV(reg_r0_2, reg_r0_7); /* line 876 */
} /* line 876 */
  sim_icache_fetch(381 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_5, reg_r0_6); /* line 878 */
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 879 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L31X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 880 */
l_L32X3: ;/* line 882 */
LABEL(l_L32X3);
  sim_icache_fetch(384 + t_thisfile.offset, 1);
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
} /* line 883 */
l_L34X3: ;/* line 885 */
LABEL(l_L34X3);
  sim_icache_fetch(385 + t_thisfile.offset, 1);
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
} /* line 886 */
l_L36X3: ;/* line 888 */
LABEL(l_L36X3);
  sim_icache_fetch(386 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L37X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 889 */
l_L38X3: ;/* line 892 */
LABEL(l_L38X3);
  sim_icache_fetch(387 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 893 */
   SUB(reg_r0_4, 0, reg_r0_3); /* line 894 */
   MOV(reg_r0_59, reg_r0_5); /* line 895 */
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_5); /* line 896 */
} /* line 896 */
  sim_icache_fetch(391 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   MOV(reg_r0_61, 0); /* line 898 */
   MOV(reg_r0_58, reg_r0_4); /* line 899 */
   MOV(reg_r0_62, reg_r0_2); /* line 900 */
   MOV(reg_r0_63, reg_r0_3); /* line 901 */
} /* line 901 */
  sim_icache_fetch(395 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L39X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 903 */
l_L40X3: ;/* line 906 */
LABEL(l_L40X3);
  sim_icache_fetch(396 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 907 */
   LDWs(reg_r0_2, mem_trace_ld((reg_r0_57 + (unsigned int) 8),0,4)); /* line 908 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX33); /* line 909 */
} /* line 909 */
  sim_icache_fetch(400 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_57 + (unsigned int) 24),0,4)); /* line 911 */
   MOV(reg_r0_5, reg_r0_60); /* line 912 */
   MOV(reg_r0_6, reg_r0_61); /* line 913 */
} /* line 913 */
  sim_icache_fetch(403 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_57,0,4)); /* line 915 */
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L41X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 916 */
  sim_icache_fetch(405 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) -1); /* line 918 */
} /* line 918 */
  sim_icache_fetch(406 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_57 + (unsigned int) 8),0,4), reg_r0_2); /* line 920 */
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 921 */
   CMPGE(reg_b0_1, reg_r0_2, reg_r0_7); /* line 922 */
} /* line 922 */
  sim_icache_fetch(409 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_9, mem_trace_ld(reg_r0_59,0,1)); /* line 924 */
} /* line 924 */
  sim_icache_fetch(410 + t_thisfile.offset, 1);
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
} /* line 926 */
  sim_icache_fetch(411 + t_thisfile.offset, 1);
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
} /* line 928 */
  sim_icache_fetch(412 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_8,0,1), reg_r0_9); /* line 930 */
} /* line 930 */
  sim_icache_fetch(413 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld(reg_r0_57,0,4)); /* line 932 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 933 */
   ADD_CYCLES(2);
} /* line 933 */
  sim_icache_fetch(415 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBU(reg_r0_7, mem_trace_ld(reg_r0_2,0,1)); /* line 935 */
   ADD(reg_r0_8, reg_r0_2, (unsigned int) 1); /* line 936 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 937 */
   ADD_CYCLES(2);
} /* line 937 */
  sim_icache_fetch(418 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPNE(reg_b0_0, reg_r0_7, (unsigned int) 10); /* line 939 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 940 */
   ADD_CYCLES(1);
} /* line 940 */
  sim_icache_fetch(420 + t_thisfile.offset, 1);
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
} /* line 942 */
  sim_icache_fetch(421 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_57,0,4), reg_r0_8); /* line 944 */
} /* line 944 */
  sim_icache_fetch(422 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_2, mem_trace_ld(reg_r0_2,0,1)); /* line 946 */
} /* line 946 */
  sim_icache_fetch(423 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 948 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 949 */
   ADD_CYCLES(1);
} /* line 949 */
l_L45X3: ;/* line 952 */
LABEL(l_L45X3);
  sim_icache_fetch(426 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 952 */
l_L46X3: ;/* line 955 */
LABEL(l_L46X3);
  sim_icache_fetch(427 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) 12),0,4)); /* line 956 */
} /* line 956 */
l_L47X3: ;/* line 958 */
LABEL(l_L47X3);
  sim_icache_fetch(428 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 959 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 960 */
   ADD_CYCLES(1);
} /* line 960 */
  sim_icache_fetch(430 + t_thisfile.offset, 1);
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
} /* line 962 */
		 /* line 963 */
  sim_icache_fetch(431 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fprintf);
   reg_l0_0 = (223 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fprintf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 965 */
l_lr_90: ;/* line 965 */
LABEL(l_lr_90);
		 /* line 966 */
  sim_icache_fetch(433 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_57); /* line 969 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fclose);
   reg_l0_0 = (223 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) fclose;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 969 */
l_lr_92: ;/* line 969 */
LABEL(l_lr_92);
		 /* line 970 */
  sim_icache_fetch(436 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) -1); /* line 973 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(exit);
   reg_l0_0 = (223 << 5);
   {
    typedef void t_FT (unsigned int);
    t_FT *t_call = (t_FT*) exit;
    (*t_call)(reg_r0_3);
   }
} /* line 973 */
l_lr_94: ;/* line 973 */
LABEL(l_lr_94);
l_L48X3: ;/* line 975 */
LABEL(l_L48X3);
  sim_icache_fetch(439 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 976 */
   ADD(reg_r0_59, reg_r0_59, (unsigned int) 1050); /* line 977 */
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 1); /* line 979 */
} /* line 979 */
  sim_icache_fetch(443 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L40X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L40X3;
} /* line 981 */
l_L44X3: ;/* line 984 */
LABEL(l_L44X3);
		 /* line 984 */
  sim_icache_fetch(444 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_4, reg_r0_57); /* line 987 */
   MOV(reg_r0_3, (unsigned int) 10); /* line 988 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__swbuf);
   reg_l0_0 = (223 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __swbuf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 988 */
l_lr_98: ;/* line 988 */
LABEL(l_lr_98);
  sim_icache_fetch(448 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_2, reg_r0_3); /* line 990 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX33); /* line 991 */
   MOV(reg_r0_5, reg_r0_60); /* line 992 */
} /* line 992 */
  sim_icache_fetch(452 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_6, reg_r0_61); /* line 994 */
   LDWs(reg_r0_7, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 995 */
} /* line 995 */
  sim_icache_fetch(455 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L45X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L45X3;
} /* line 997 */
l_L43X3: ;/* line 1000 */
LABEL(l_L43X3);
  sim_icache_fetch(456 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDBU(reg_r0_3, mem_trace_ld(reg_r0_59,0,1)); /* line 1001 */
   MOV(reg_r0_4, reg_r0_57); /* line 1002 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1003 */
   ADD_CYCLES(1);
} /* line 1003 */
		 /* line 1004 */
  sim_icache_fetch(459 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__swbuf);
   reg_l0_0 = (223 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __swbuf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 1006 */
l_lr_101: ;/* line 1006 */
LABEL(l_lr_101);
  sim_icache_fetch(461 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_2, reg_r0_3); /* line 1008 */
   LDWs(reg_r0_7, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 1009 */
   MOV(reg_r0_5, reg_r0_60); /* line 1010 */
} /* line 1010 */
  sim_icache_fetch(465 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX33); /* line 1012 */
   MOV(reg_r0_6, reg_r0_61); /* line 1013 */
} /* line 1013 */
  sim_icache_fetch(468 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L46X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L46X3;
} /* line 1015 */
l_L42X3: ;/* line 1018 */
LABEL(l_L42X3);
  sim_icache_fetch(469 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   LDBU(reg_r0_3, mem_trace_ld(reg_r0_59,0,1)); /* line 1019 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX33); /* line 1020 */
   MOV(reg_r0_5, reg_r0_60); /* line 1021 */
} /* line 1021 */
  sim_icache_fetch(473 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_8, mem_trace_ld(reg_r0_57,0,4)); /* line 1023 */
   MOV(reg_r0_6, reg_r0_61); /* line 1024 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 1025 */
   ADD_CYCLES(2);
} /* line 1025 */
  sim_icache_fetch(476 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_8,0,1), reg_r0_3); /* line 1027 */
} /* line 1027 */
  sim_icache_fetch(477 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld(reg_r0_57,0,4)); /* line 1029 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 1030 */
   ADD_CYCLES(2);
} /* line 1030 */
  sim_icache_fetch(479 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_3, (unsigned int) 1); /* line 1032 */
} /* line 1032 */
  sim_icache_fetch(480 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_57,0,4), reg_r0_8); /* line 1034 */
} /* line 1034 */
  sim_icache_fetch(481 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_2, mem_trace_ld(reg_r0_3,0,1)); /* line 1036 */
} /* line 1036 */
  sim_icache_fetch(482 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 1038 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 1039 */
   ADD_CYCLES(2);
} /* line 1039 */
  sim_icache_fetch(485 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDWs(reg_r0_3, mem_trace_ld((reg_r0_7 + (unsigned int) 12),0,4)); /* line 1041 */
   GOTO(l_L47X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L47X3;
} /* line 1042 */
l_L41X3: ;/* line 1045 */
LABEL(l_L41X3);
  sim_icache_fetch(487 + t_thisfile.offset, 5);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(4);
   ADD(reg_r0_2, reg_r0_62, (unsigned int) 1); /* line 1046 */
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 1047 */
   MOV(reg_r0_3, reg_r0_63); /* line 1048 */
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 1049 */
   INC_NOP_CNT((unsigned int) 2);
   XNOP((unsigned int) 2); /* line 1050 */
   ADD_CYCLES(2);
} /* line 1050 */
  sim_icache_fetch(492 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 1); /* line 1052 */
   GOTO(l_L38X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L38X3;
} /* line 1053 */
l_L39X3: ;/* line 1056 */
LABEL(l_L39X3);
		 /* line 1056 */
  sim_icache_fetch(494 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, reg_r0_57); /* line 1059 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fclose);
   reg_l0_0 = (223 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) fclose;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1059 */
l_lr_106: ;/* line 1059 */
LABEL(l_lr_106);
  sim_icache_fetch(497 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, 0); /* line 1061 */
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1062 */
} /* line 1062 */
  sim_icache_fetch(499 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1064 */
} /* line 1064 */
  sim_icache_fetch(500 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1066 */
} /* line 1066 */
  sim_icache_fetch(501 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1068 */
} /* line 1068 */
  sim_icache_fetch(502 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1070 */
} /* line 1070 */
  sim_icache_fetch(503 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 1072 */
} /* line 1072 */
  sim_icache_fetch(504 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 1074 */
} /* line 1074 */
  sim_icache_fetch(505 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 1076 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1077 */
   ADD_CYCLES(1);
} /* line 1077 */
  sim_icache_fetch(507 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(save_pgm);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 96; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1080 */
l_L37X3: ;/* line 1083 */
LABEL(l_L37X3);
  sim_icache_fetch(508 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 1084 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX32); /* line 1085 */
   MOV(reg_r0_4, (unsigned int) 106); /* line 1086 */
} /* line 1086 */
		 /* line 1087 */
  sim_icache_fetch(512 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX31); /* line 1090 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (223 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1090 */
l_lr_109: ;/* line 1090 */
LABEL(l_lr_109);
  sim_icache_fetch(516 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, 0); /* line 1092 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 1093 */
} /* line 1093 */
  sim_icache_fetch(518 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 1095 */
} /* line 1095 */
  sim_icache_fetch(519 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 1097 */
} /* line 1097 */
  sim_icache_fetch(520 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_7, 0, reg_r0_4); /* line 1099 */
} /* line 1099 */
  sim_icache_fetch(521 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_2, reg_r0_7); /* line 1101 */
   MOV(reg_r0_5, reg_r0_6); /* line 1102 */
   GOTO(l_L38X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L38X3;
} /* line 1103 */
l_L35X3: ;/* line 1106 */
LABEL(l_L35X3);
  sim_icache_fetch(524 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 1107 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX30); /* line 1108 */
   MOV(reg_r0_4, (unsigned int) 105); /* line 1109 */
} /* line 1109 */
		 /* line 1110 */
  sim_icache_fetch(528 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX29); /* line 1113 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (223 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1113 */
l_lr_112: ;/* line 1113 */
LABEL(l_lr_112);
  sim_icache_fetch(532 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, 0); /* line 1115 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 1116 */
} /* line 1116 */
  sim_icache_fetch(534 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 1118 */
} /* line 1118 */
  sim_icache_fetch(535 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 1120 */
} /* line 1120 */
  sim_icache_fetch(536 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_7, 0, reg_r0_4); /* line 1122 */
} /* line 1122 */
  sim_icache_fetch(537 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLE(reg_b0_3, reg_r0_3, (unsigned int) 1500); /* line 1124 */
   MOV(reg_r0_2, reg_r0_7); /* line 1125 */
} /* line 1125 */
  sim_icache_fetch(540 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_6); /* line 1127 */
   GOTO(l_L36X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L36X3;
} /* line 1128 */
l_L33X3: ;/* line 1131 */
LABEL(l_L33X3);
  sim_icache_fetch(542 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 1132 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX28); /* line 1133 */
   MOV(reg_r0_4, (unsigned int) 104); /* line 1134 */
} /* line 1134 */
		 /* line 1135 */
  sim_icache_fetch(546 + t_thisfile.offset, 5);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 68),0,4), reg_r0_57); /* line 1138 */
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX27); /* line 1139 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (223 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1139 */
l_lr_115: ;/* line 1139 */
LABEL(l_lr_115);
  sim_icache_fetch(551 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, 0); /* line 1141 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 1142 */
} /* line 1142 */
  sim_icache_fetch(553 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 1144 */
} /* line 1144 */
  sim_icache_fetch(554 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 1146 */
} /* line 1146 */
  sim_icache_fetch(555 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_7, 0, reg_r0_4); /* line 1148 */
} /* line 1148 */
  sim_icache_fetch(556 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPGT(reg_b0_2, reg_r0_3, 0); /* line 1150 */
   CMPLE(reg_b0_3, reg_r0_3, (unsigned int) 1500); /* line 1151 */
   MOV(reg_r0_2, reg_r0_7); /* line 1152 */
} /* line 1152 */
  sim_icache_fetch(560 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_5, reg_r0_6); /* line 1154 */
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 1155 */
} /* line 1155 */
  sim_icache_fetch(562 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L34X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L34X3;
} /* line 1157 */
l_L31X3: ;/* line 1160 */
LABEL(l_L31X3);
  sim_icache_fetch(563 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 1161 */
   MOV(reg_r0_5, (unsigned int) _X1STRINGPACKETX26); /* line 1162 */
   MOV(reg_r0_4, (unsigned int) 103); /* line 1163 */
} /* line 1163 */
  sim_icache_fetch(567 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX25); /* line 1165 */
} /* line 1165 */
		 /* line 1166 */
  sim_icache_fetch(569 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 68),0,4), reg_r0_57); /* line 1169 */
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(__assert);
   reg_l0_0 = (223 << 5);
   {
    typedef void t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) __assert;
    (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1169 */
l_lr_118: ;/* line 1169 */
LABEL(l_lr_118);
  sim_icache_fetch(572 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_60, 0); /* line 1171 */
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 56),0,4)); /* line 1172 */
} /* line 1172 */
  sim_icache_fetch(574 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 1174 */
} /* line 1174 */
  sim_icache_fetch(575 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 52),0,4)); /* line 1176 */
} /* line 1176 */
  sim_icache_fetch(576 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   CMPLE(reg_b0_1, reg_r0_4, (unsigned int) 1050); /* line 1178 */
   SUB(reg_r0_7, 0, reg_r0_4); /* line 1179 */
} /* line 1179 */
  sim_icache_fetch(579 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   CMPGT(reg_b0_2, reg_r0_3, 0); /* line 1181 */
   CMPLE(reg_b0_3, reg_r0_3, (unsigned int) 1500); /* line 1182 */
   MOV(reg_r0_2, reg_r0_7); /* line 1183 */
} /* line 1183 */
  sim_icache_fetch(583 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(3);
   MOV(reg_r0_5, reg_r0_6); /* line 1185 */
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 1186 */
   GOTO(l_L32X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L32X3;
} /* line 1187 */
l_L30X3: ;/* line 1190 */
LABEL(l_L30X3);
  sim_icache_fetch(586 + t_thisfile.offset, 4);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   LDW(reg_r0_2, mem_trace_ld((unsigned int) _impure_ptr,0,4)); /* line 1191 */
   MOV(reg_r0_4, (unsigned int) _X1STRINGPACKETX34); /* line 1192 */
} /* line 1192 */
  sim_icache_fetch(590 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 64),0,4)); /* line 1194 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1195 */
   ADD_CYCLES(1);
} /* line 1195 */
  sim_icache_fetch(592 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 1197 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1198 */
   ADD_CYCLES(1);
} /* line 1198 */
		 /* line 1199 */
  sim_icache_fetch(594 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(fprintf);
   reg_l0_0 = (223 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) fprintf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5);
   }
} /* line 1201 */
l_lr_121: ;/* line 1201 */
LABEL(l_lr_121);
  sim_icache_fetch(596 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(2);
   MOV(reg_r0_3, (unsigned int) -1); /* line 1203 */
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1204 */
} /* line 1204 */
  sim_icache_fetch(598 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 1206 */
} /* line 1206 */
  sim_icache_fetch(599 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1208 */
} /* line 1208 */
  sim_icache_fetch(600 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1210 */
} /* line 1210 */
  sim_icache_fetch(601 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 1212 */
} /* line 1212 */
  sim_icache_fetch(602 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 1214 */
} /* line 1214 */
  sim_icache_fetch(603 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 44),0,4)); /* line 1216 */
} /* line 1216 */
  sim_icache_fetch(604 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 48),0,4)); /* line 1218 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1219 */
   ADD_CYCLES(1);
} /* line 1219 */
  sim_icache_fetch(606 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(save_pgm);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 96; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1222 */
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
    case 186: goto l_L40X3;
    case 187: goto l_L45X3;
    case 188: goto l_L46X3;
    case 189: goto l_L47X3;
    case 191: goto l_lr_90;
    case 193: goto l_lr_92;
    case 195: goto l_lr_94;
    case 196: goto l_L48X3;
    case 197: goto l_L44X3;
    case 199: goto l_lr_98;
    case 200: goto l_L43X3;
    case 202: goto l_lr_101;
    case 203: goto l_L42X3;
    case 204: goto l_L41X3;
    case 205: goto l_L39X3;
    case 207: goto l_lr_106;
    case 208: goto l_L37X3;
    case 210: goto l_lr_109;
    case 211: goto l_L35X3;
    case 213: goto l_lr_112;
    case 214: goto l_L33X3;
    case 216: goto l_lr_115;
    case 217: goto l_L31X3;
    case 219: goto l_lr_118;
    case 220: goto l_L30X3;
    case 222: goto l_lr_121;
    case 223:
      reg_l0_0 = t_client_rpc;
      return reg_r0_3;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"pgm.s", 608, 0, 0, 0, 2};


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
unsigned int ft[1575000];
unsigned int fy2[1575000];
unsigned int fy1[1575000];
unsigned int t[1575000];
unsigned int y2[1575000];
unsigned int y1[1575000];

/*********************************
            ENTRY SYMBOLS
*********************************/

typedef struct {
	unsigned int alias0;
	unsigned int alias1;
} sim_result_0_t;
extern  deriche_float( unsigned int, unsigned int );
extern  deriche_fused( unsigned int, unsigned int );
extern  deriche_slow( unsigned int, unsigned int );
extern  _r_ilfloat(  );
extern  _r_ufloat(  );
extern  _d_r(  );
extern  _r_ufix(  );
extern  _r_mul(  );
extern  _r_add(  );
extern  printf(  );

/*********************************
            DATA SYMBOLS
*********************************/

static unsigned int _X1STRINGPACKETX1[4]; 
static unsigned int _X1STRINGPACKETX2[2]; 
static unsigned int _X1STRINGPACKETX4[4]; 
static unsigned int _X1STRINGPACKETX5[2]; 
static unsigned int _X1STRINGPACKETX7[4]; 
static unsigned int _X1STRINGPACKETX8[2]; 
static unsigned int _X1STRINGPACKETX10[4]; 
static unsigned int _X1STRINGPACKETX11[2]; 
static unsigned int _X1STRINGPACKETX13[4]; 
static unsigned int _X1STRINGPACKETX14[2]; 
static unsigned int _X1STRINGPACKETX16[4]; 
static unsigned int _X1STRINGPACKETX3[1]; 
static unsigned int _X1STRINGPACKETX6[1]; 
static unsigned int _X1STRINGPACKETX9[1]; 
static unsigned int _X1STRINGPACKETX12[1]; 
static unsigned int _X1STRINGPACKETX15[1]; 
static unsigned int _X1STRINGPACKETX17[1]; 
static unsigned int _X1STRINGPACKETX18[1]; 
static unsigned int _X1STRINGPACKETX19[4]; 
static unsigned int _X1STRINGPACKETX20[3]; 
static unsigned int _X1STRINGPACKETX21[1]; 
static unsigned int _X1STRINGPACKETX22[1]; 
static unsigned int _X1STRINGPACKETX23[3]; 
static unsigned int _X1STRINGPACKETX24[1]; 
static unsigned int _X1STRINGPACKETX25[1]; 
static unsigned int _X1STRINGPACKETX26[3]; 
static unsigned int _X1STRINGPACKETX27[1]; 
static unsigned int _X1STRINGPACKETX28[1]; 
static unsigned int _X1STRINGPACKETX29[3]; 
static unsigned int _X1STRINGPACKETX30[1]; 
static unsigned int _X1STRINGPACKETX31[1]; 
static unsigned int _X1STRINGPACKETX32[3]; 
static unsigned int _X1STRINGPACKETX33[1]; 
static unsigned int _X1STRINGPACKETX34[1]; 
static unsigned int _X1STRINGPACKETX35[3]; 
static unsigned int _X1STRINGPACKETX36[1]; 
static unsigned int _X1STRINGPACKETX37[1]; 
extern unsigned int out[];
extern unsigned int in[];
static unsigned int _X1STRINGPACKETX1[4] = { 
	0x0A0A4C31,
	0x20793120,
	0x666C6F61,
	0x743A0A00
}; 

static unsigned int _X1STRINGPACKETX2[2] = { 
	0x252E3066,
	0x20000000
}; 

static unsigned int _X1STRINGPACKETX4[4] = { 
	0x4C322079,
	0x3220666C,
	0x6F61743A,
	0x0A000000
}; 

static unsigned int _X1STRINGPACKETX5[2] = { 
	0x252E3066,
	0x20000000
}; 

static unsigned int _X1STRINGPACKETX7[4] = { 
	0x4C332074,
	0x20666C6F,
	0x61743A0A,
	0x00000000
}; 

static unsigned int _X1STRINGPACKETX8[2] = { 
	0x252E3066,
	0x20000000
}; 

static unsigned int _X1STRINGPACKETX10[4] = { 
	0x4C342079,
	0x3120666C,
	0x6F61743A,
	0x0A000000
}; 

static unsigned int _X1STRINGPACKETX11[2] = { 
	0x252E3066,
	0x20000000
}; 

static unsigned int _X1STRINGPACKETX13[4] = { 
	0x4C352079,
	0x3220666C,
	0x6F61743A,
	0x0A000000
}; 

static unsigned int _X1STRINGPACKETX14[2] = { 
	0x252E3066,
	0x20000000
}; 

static unsigned int _X1STRINGPACKETX16[4] = { 
	0x4C36206F,
	0x75742066,
	0x6C6F6174,
	0x3A0A0000
}; 

static unsigned int _X1STRINGPACKETX3[1] = { 
	0x0A0A0000
}; 

static unsigned int _X1STRINGPACKETX6[1] = { 
	0x0A0A0000
}; 

static unsigned int _X1STRINGPACKETX9[1] = { 
	0x0A0A0000
}; 

static unsigned int _X1STRINGPACKETX12[1] = { 
	0x0A0A0000
}; 

static unsigned int _X1STRINGPACKETX15[1] = { 
	0x0A0A0000
}; 

static unsigned int _X1STRINGPACKETX17[1] = { 
	0x25642000
}; 

static unsigned int _X1STRINGPACKETX18[1] = { 
	0x0A0A0000
}; 

static unsigned int _X1STRINGPACKETX19[4] = { 
	0x0A666978,
	0x65642066,
	0x6173740A,
	0x00000000
}; 

static unsigned int _X1STRINGPACKETX20[3] = { 
	0x0A0A464C,
	0x31206679,
	0x313A0A00
}; 

static unsigned int _X1STRINGPACKETX21[1] = { 
	0x25642000
}; 

static unsigned int _X1STRINGPACKETX22[1] = { 
	0x0A0A0000
}; 

static unsigned int _X1STRINGPACKETX23[3] = { 
	0x464C3220,
	0x6679323A,
	0x0A000000
}; 

static unsigned int _X1STRINGPACKETX24[1] = { 
	0x25642000
}; 

static unsigned int _X1STRINGPACKETX25[1] = { 
	0x0A0A0000
}; 

static unsigned int _X1STRINGPACKETX26[3] = { 
	0x464C3320,
	0x66743A0A,
	0x00000000
}; 

static unsigned int _X1STRINGPACKETX27[1] = { 
	0x25642000
}; 

static unsigned int _X1STRINGPACKETX28[1] = { 
	0x0A0A0000
}; 

static unsigned int _X1STRINGPACKETX29[3] = { 
	0x464C3420,
	0x6679313A,
	0x0A000000
}; 

static unsigned int _X1STRINGPACKETX30[1] = { 
	0x25642000
}; 

static unsigned int _X1STRINGPACKETX31[1] = { 
	0x0A0A0000
}; 

static unsigned int _X1STRINGPACKETX32[3] = { 
	0x464C3520,
	0x6679323A,
	0x0A000000
}; 

static unsigned int _X1STRINGPACKETX33[1] = { 
	0x25642000
}; 

static unsigned int _X1STRINGPACKETX34[1] = { 
	0x0A0A0000
}; 

static unsigned int _X1STRINGPACKETX35[3] = { 
	0x464C3620,
	0x6F75743A,
	0x0A000000
}; 

static unsigned int _X1STRINGPACKETX36[1] = { 
	0x25642000
}; 

static unsigned int _X1STRINGPACKETX37[1] = { 
	0x0a0a0000
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
  reg_l0_0 = (256 << 5);
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
   reg_l0_0 = (256 << 5);
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
   reg_l0_0 = (256 << 5);
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
   reg_l0_0 = (256 << 5);
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
   reg_l0_0 = (256 << 5);
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
   reg_l0_0 = (256 << 5);
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
   reg_l0_0 = (256 << 5);
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
   reg_l0_0 = (256 << 5);
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
   reg_l0_0 = (256 << 5);
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
   reg_l0_0 = (256 << 5);
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
  sim_icache_fetch(96 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX1); /* line 189 */
} /* line 189 */
		 /* line 190 */
  sim_icache_fetch(98 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 192 */
l_lr_23: ;/* line 192 */
LABEL(l_lr_23);
  sim_icache_fetch(100 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, ((unsigned int) y1 + (unsigned int) 58820)); /* line 194 */
} /* line 194 */
  sim_icache_fetch(102 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) -11); /* line 196 */
} /* line 196 */
  sim_icache_fetch(103 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 198 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 199 */
   ADD_CYCLES(1);
} /* line 199 */
  sim_icache_fetch(105 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 200 */
l_L4X3: ;/* line 203 */
LABEL(l_L4X3);
  sim_icache_fetch(106 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_57,0,4)); /* line 204 */
} /* line 204 */
  sim_icache_fetch(107 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 206 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 207 */
   ADD_CYCLES(1);
} /* line 207 */
  sim_icache_fetch(109 + t_thisfile.offset, 1);
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
} /* line 209 */
		 /* line 210 */
  sim_icache_fetch(110 + t_thisfile.offset, 2);
{
  sim_result_0_t t_sim_result_0_t;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_d_r);
   reg_l0_0 = (256 << 5);
   {
    typedef sim_result_0_t t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _d_r;
    t_sim_result_0_t =     (*t_call)(reg_r0_3);
    reg_r0_3 = t_sim_result_0_t.alias0;
    reg_r0_4 = t_sim_result_0_t.alias1;
   }
} /* line 212 */
l_lr_26: ;/* line 212 */
LABEL(l_lr_26);
  sim_icache_fetch(112 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_3); /* line 214 */
} /* line 214 */
  sim_icache_fetch(113 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX2); /* line 216 */
} /* line 216 */
  sim_icache_fetch(115 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_4); /* line 218 */
} /* line 218 */
  sim_icache_fetch(116 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 220 */
} /* line 220 */
		 /* line 221 */
  sim_icache_fetch(117 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 223 */
l_lr_28: ;/* line 223 */
LABEL(l_lr_28);
  sim_icache_fetch(119 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 4200); /* line 225 */
} /* line 225 */
  sim_icache_fetch(121 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 228 */
} /* line 228 */
  sim_icache_fetch(122 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L4X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L4X3;
} /* line 230 */
l_L5X3: ;/* line 233 */
LABEL(l_L5X3);
  sim_icache_fetch(123 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 96),0,4), reg_r0_59); /* line 234 */
} /* line 234 */
  sim_icache_fetch(124 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX3); /* line 236 */
} /* line 236 */
		 /* line 237 */
  sim_icache_fetch(126 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 239 */
l_lr_31: ;/* line 239 */
LABEL(l_lr_31);
  sim_icache_fetch(128 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 241 */
} /* line 241 */
  sim_icache_fetch(129 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, (unsigned int) y2); /* line 243 */
} /* line 243 */
  sim_icache_fetch(131 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_59, (unsigned int) -1); /* line 245 */
} /* line 245 */
  sim_icache_fetch(132 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_3, 0, reg_r0_3); /* line 247 */
} /* line 247 */
  sim_icache_fetch(133 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_3); /* line 249 */
} /* line 249 */
  sim_icache_fetch(134 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) in); /* line 251 */
} /* line 251 */
l_L6X3: ;/* line 254 */
LABEL(l_L6X3);
  sim_icache_fetch(136 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 108),0,4), reg_r0_2); /* line 255 */
} /* line 255 */
  sim_icache_fetch(137 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 112),0,4), reg_r0_4); /* line 257 */
} /* line 257 */
  sim_icache_fetch(138 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 116),0,4), reg_r0_5); /* line 259 */
} /* line 259 */
  sim_icache_fetch(139 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 120),0,4), reg_r0_6); /* line 261 */
} /* line 261 */
  sim_icache_fetch(140 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 263 */
} /* line 263 */
  sim_icache_fetch(141 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_62, reg_r0_4, reg_r0_5); /* line 265 */
} /* line 265 */
  sim_icache_fetch(142 + t_thisfile.offset, 1);
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
} /* line 267 */
  sim_icache_fetch(143 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_63, reg_r0_5, reg_r0_6); /* line 269 */
} /* line 269 */
  sim_icache_fetch(144 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, 0); /* line 271 */
} /* line 271 */
  sim_icache_fetch(145 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, 0); /* line 273 */
} /* line 273 */
  sim_icache_fetch(146 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, 0); /* line 275 */
} /* line 275 */
  sim_icache_fetch(147 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, 0); /* line 277 */
} /* line 277 */
  sim_icache_fetch(148 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, reg_r0_5); /* line 279 */
} /* line 279 */
l_L8X3: ;/* line 282 */
LABEL(l_L8X3);
  sim_icache_fetch(149 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_57, 0); /* line 283 */
} /* line 283 */
  sim_icache_fetch(150 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 285 */
} /* line 285 */
  sim_icache_fetch(152 + t_thisfile.offset, 1);
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
} /* line 287 */
  sim_icache_fetch(153 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_58); /* line 289 */
} /* line 289 */
		 /* line 290 */
  sim_icache_fetch(154 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 292 */
l_lr_35: ;/* line 292 */
LABEL(l_lr_35);
  sim_icache_fetch(156 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_3); /* line 294 */
} /* line 294 */
  sim_icache_fetch(157 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, reg_r0_59); /* line 296 */
} /* line 296 */
  sim_icache_fetch(158 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 298 */
} /* line 298 */
  sim_icache_fetch(160 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 300 */
} /* line 300 */
		 /* line 301 */
  sim_icache_fetch(161 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 303 */
l_lr_37: ;/* line 303 */
LABEL(l_lr_37);
  sim_icache_fetch(163 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_3); /* line 305 */
} /* line 305 */
  sim_icache_fetch(164 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1103022629); /* line 307 */
} /* line 307 */
  sim_icache_fetch(166 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_60); /* line 309 */
} /* line 309 */
		 /* line 310 */
  sim_icache_fetch(167 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 312 */
l_lr_39: ;/* line 312 */
LABEL(l_lr_39);
  sim_icache_fetch(169 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_3); /* line 314 */
} /* line 314 */
  sim_icache_fetch(170 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, reg_r0_61); /* line 316 */
} /* line 316 */
  sim_icache_fetch(171 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1103358174); /* line 318 */
} /* line 318 */
  sim_icache_fetch(173 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_61); /* line 320 */
} /* line 320 */
		 /* line 321 */
  sim_icache_fetch(174 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 323 */
l_lr_41: ;/* line 323 */
LABEL(l_lr_41);
  sim_icache_fetch(176 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_3); /* line 325 */
} /* line 325 */
  sim_icache_fetch(177 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 327 */
} /* line 327 */
  sim_icache_fetch(178 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 329 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 330 */
   ADD_CYCLES(1);
} /* line 330 */
		 /* line 331 */
  sim_icache_fetch(180 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 333 */
l_lr_43: ;/* line 333 */
LABEL(l_lr_43);
  sim_icache_fetch(182 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 335 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 336 */
   ADD_CYCLES(1);
} /* line 336 */
		 /* line 337 */
  sim_icache_fetch(184 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 339 */
l_lr_45: ;/* line 339 */
LABEL(l_lr_45);
  sim_icache_fetch(186 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 341 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 342 */
   ADD_CYCLES(1);
} /* line 342 */
		 /* line 343 */
  sim_icache_fetch(188 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 345 */
l_lr_47: ;/* line 345 */
LABEL(l_lr_47);
  sim_icache_fetch(190 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_3); /* line 347 */
} /* line 347 */
  sim_icache_fetch(191 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBU(reg_r0_2, mem_trace_ld(reg_r0_62,0,1)); /* line 349 */
} /* line 349 */
  sim_icache_fetch(192 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_63,0,4), reg_r0_3); /* line 351 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 352 */
   ADD_CYCLES(1);
} /* line 352 */
  sim_icache_fetch(194 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_2); /* line 354 */
} /* line 354 */
		 /* line 355 */
  sim_icache_fetch(195 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_ufloat);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _r_ufloat;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 357 */
l_lr_49: ;/* line 357 */
LABEL(l_lr_49);
  sim_icache_fetch(197 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) -1); /* line 359 */
} /* line 359 */
  sim_icache_fetch(198 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_63, reg_r0_63, (unsigned int) -4); /* line 361 */
} /* line 361 */
  sim_icache_fetch(199 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_62, reg_r0_62, (unsigned int) -1); /* line 363 */
} /* line 363 */
  sim_icache_fetch(200 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 365 */
} /* line 365 */
  sim_icache_fetch(201 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, reg_r0_3); /* line 367 */
} /* line 367 */
  sim_icache_fetch(202 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L8X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L8X3;
} /* line 369 */
l_L9X3: ;/* line 372 */
LABEL(l_L9X3);
  sim_icache_fetch(203 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_6, mem_trace_ld((reg_r0_1 + (unsigned int) 120),0,4)); /* line 373 */
} /* line 373 */
  sim_icache_fetch(204 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 112),0,4)); /* line 375 */
} /* line 375 */
  sim_icache_fetch(205 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 108),0,4)); /* line 377 */
} /* line 377 */
  sim_icache_fetch(206 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 4200); /* line 379 */
} /* line 379 */
  sim_icache_fetch(208 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 1050); /* line 381 */
} /* line 381 */
  sim_icache_fetch(210 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 383 */
} /* line 383 */
  sim_icache_fetch(211 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 116),0,4)); /* line 385 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 386 */
   ADD_CYCLES(1);
} /* line 386 */
  sim_icache_fetch(213 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L6X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L6X3;
} /* line 388 */
l_L7X3: ;/* line 391 */
LABEL(l_L7X3);
  sim_icache_fetch(214 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX4); /* line 392 */
} /* line 392 */
		 /* line 393 */
  sim_icache_fetch(216 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 395 */
l_lr_53: ;/* line 395 */
LABEL(l_lr_53);
  sim_icache_fetch(218 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, ((unsigned int) y2 + (unsigned int) 58820)); /* line 397 */
} /* line 397 */
  sim_icache_fetch(220 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) -11); /* line 399 */
} /* line 399 */
l_L10X3: ;/* line 402 */
LABEL(l_L10X3);
  sim_icache_fetch(221 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_57,0,4)); /* line 403 */
} /* line 403 */
  sim_icache_fetch(222 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 405 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 406 */
   ADD_CYCLES(1);
} /* line 406 */
  sim_icache_fetch(224 + t_thisfile.offset, 1);
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
} /* line 408 */
		 /* line 409 */
  sim_icache_fetch(225 + t_thisfile.offset, 2);
{
  sim_result_0_t t_sim_result_0_t;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_d_r);
   reg_l0_0 = (256 << 5);
   {
    typedef sim_result_0_t t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _d_r;
    t_sim_result_0_t =     (*t_call)(reg_r0_3);
    reg_r0_3 = t_sim_result_0_t.alias0;
    reg_r0_4 = t_sim_result_0_t.alias1;
   }
} /* line 411 */
l_lr_56: ;/* line 411 */
LABEL(l_lr_56);
  sim_icache_fetch(227 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_3); /* line 413 */
} /* line 413 */
  sim_icache_fetch(228 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX5); /* line 415 */
} /* line 415 */
  sim_icache_fetch(230 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_4); /* line 417 */
} /* line 417 */
  sim_icache_fetch(231 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 419 */
} /* line 419 */
		 /* line 420 */
  sim_icache_fetch(232 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 422 */
l_lr_58: ;/* line 422 */
LABEL(l_lr_58);
  sim_icache_fetch(234 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 4200); /* line 424 */
} /* line 424 */
  sim_icache_fetch(236 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 427 */
} /* line 427 */
  sim_icache_fetch(237 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L10X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L10X3;
} /* line 429 */
l_L11X3: ;/* line 432 */
LABEL(l_L11X3);
  sim_icache_fetch(238 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX6); /* line 433 */
} /* line 433 */
		 /* line 434 */
  sim_icache_fetch(240 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 436 */
l_lr_61: ;/* line 436 */
LABEL(l_lr_61);
  sim_icache_fetch(242 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 438 */
} /* line 438 */
  sim_icache_fetch(243 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, (unsigned int) t); /* line 440 */
} /* line 440 */
  sim_icache_fetch(245 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, (unsigned int) y1); /* line 442 */
} /* line 442 */
  sim_icache_fetch(247 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_4); /* line 444 */
} /* line 444 */
  sim_icache_fetch(248 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_4); /* line 446 */
} /* line 446 */
  sim_icache_fetch(249 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) y2); /* line 448 */
} /* line 448 */
  sim_icache_fetch(251 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 450 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 451 */
   ADD_CYCLES(1);
} /* line 451 */
  sim_icache_fetch(253 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 452 */
l_L12X3: ;/* line 455 */
LABEL(l_L12X3);
  sim_icache_fetch(254 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 456 */
} /* line 456 */
  sim_icache_fetch(255 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_3); /* line 458 */
} /* line 458 */
  sim_icache_fetch(256 + t_thisfile.offset, 1);
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
} /* line 460 */
  sim_icache_fetch(257 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, reg_r0_4); /* line 462 */
} /* line 462 */
  sim_icache_fetch(258 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, 0); /* line 464 */
} /* line 464 */
  sim_icache_fetch(259 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_62, reg_r0_2); /* line 466 */
} /* line 466 */
  sim_icache_fetch(260 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, reg_r0_3); /* line 468 */
} /* line 468 */
l_L14X3: ;/* line 471 */
LABEL(l_L14X3);
  sim_icache_fetch(261 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_58); /* line 472 */
} /* line 472 */
  sim_icache_fetch(262 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 474 */
} /* line 474 */
  sim_icache_fetch(263 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_59); /* line 476 */
} /* line 476 */
  sim_icache_fetch(264 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_2,0,4)); /* line 478 */
} /* line 478 */
  sim_icache_fetch(265 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_60, 0); /* line 480 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 481 */
   ADD_CYCLES(1);
} /* line 481 */
  sim_icache_fetch(267 + t_thisfile.offset, 1);
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
} /* line 483 */
		 /* line 484 */
  sim_icache_fetch(268 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 486 */
l_lr_65: ;/* line 486 */
LABEL(l_lr_65);
  sim_icache_fetch(270 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1065353216); /* line 488 */
} /* line 488 */
		 /* line 489 */
  sim_icache_fetch(272 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 491 */
l_lr_67: ;/* line 491 */
LABEL(l_lr_67);
  sim_icache_fetch(274 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_61); /* line 493 */
} /* line 493 */
  sim_icache_fetch(275 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 495 */
} /* line 495 */
  sim_icache_fetch(276 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 497 */
} /* line 497 */
  sim_icache_fetch(277 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_2,0,4), reg_r0_3); /* line 500 */
} /* line 500 */
  sim_icache_fetch(278 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L14X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L14X3;
} /* line 502 */
l_L15X3: ;/* line 505 */
LABEL(l_L15X3);
  sim_icache_fetch(279 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 4200); /* line 506 */
} /* line 506 */
  sim_icache_fetch(281 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_61, reg_r0_61, reg_r0_4); /* line 508 */
} /* line 508 */
  sim_icache_fetch(282 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_59, reg_r0_59, reg_r0_4); /* line 510 */
} /* line 510 */
  sim_icache_fetch(283 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, reg_r0_4); /* line 512 */
} /* line 512 */
  sim_icache_fetch(284 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_62, (unsigned int) 1); /* line 514 */
} /* line 514 */
  sim_icache_fetch(285 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_63); /* line 517 */
} /* line 517 */
  sim_icache_fetch(286 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L12X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L12X3;
} /* line 519 */
l_L13X3: ;/* line 522 */
LABEL(l_L13X3);
  sim_icache_fetch(287 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 96),0,4), reg_r0_3); /* line 523 */
} /* line 523 */
  sim_icache_fetch(288 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX7); /* line 525 */
} /* line 525 */
		 /* line 526 */
  sim_icache_fetch(290 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 528 */
l_lr_71: ;/* line 528 */
LABEL(l_lr_71);
  sim_icache_fetch(292 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, ((unsigned int) t + (unsigned int) 58820)); /* line 530 */
} /* line 530 */
  sim_icache_fetch(294 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) -11); /* line 532 */
} /* line 532 */
  sim_icache_fetch(295 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 534 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 535 */
   ADD_CYCLES(1);
} /* line 535 */
  sim_icache_fetch(297 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 536 */
l_L16X3: ;/* line 539 */
LABEL(l_L16X3);
  sim_icache_fetch(298 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_57,0,4)); /* line 540 */
} /* line 540 */
  sim_icache_fetch(299 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 542 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 543 */
   ADD_CYCLES(1);
} /* line 543 */
  sim_icache_fetch(301 + t_thisfile.offset, 1);
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
} /* line 545 */
		 /* line 546 */
  sim_icache_fetch(302 + t_thisfile.offset, 2);
{
  sim_result_0_t t_sim_result_0_t;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_d_r);
   reg_l0_0 = (256 << 5);
   {
    typedef sim_result_0_t t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _d_r;
    t_sim_result_0_t =     (*t_call)(reg_r0_3);
    reg_r0_3 = t_sim_result_0_t.alias0;
    reg_r0_4 = t_sim_result_0_t.alias1;
   }
} /* line 548 */
l_lr_74: ;/* line 548 */
LABEL(l_lr_74);
  sim_icache_fetch(304 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_3); /* line 550 */
} /* line 550 */
  sim_icache_fetch(305 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX8); /* line 552 */
} /* line 552 */
  sim_icache_fetch(307 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_4); /* line 554 */
} /* line 554 */
  sim_icache_fetch(308 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 556 */
} /* line 556 */
		 /* line 557 */
  sim_icache_fetch(309 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 559 */
l_lr_76: ;/* line 559 */
LABEL(l_lr_76);
  sim_icache_fetch(311 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 4200); /* line 561 */
} /* line 561 */
  sim_icache_fetch(313 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 564 */
} /* line 564 */
  sim_icache_fetch(314 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L16X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L16X3;
} /* line 566 */
l_L17X3: ;/* line 569 */
LABEL(l_L17X3);
  sim_icache_fetch(315 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 96),0,4), reg_r0_59); /* line 570 */
} /* line 570 */
  sim_icache_fetch(316 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX9); /* line 572 */
} /* line 572 */
		 /* line 573 */
  sim_icache_fetch(318 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 575 */
l_lr_79: ;/* line 575 */
LABEL(l_lr_79);
  sim_icache_fetch(320 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_59, 0, reg_r0_59); /* line 577 */
} /* line 577 */
  sim_icache_fetch(321 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_59); /* line 579 */
} /* line 579 */
  sim_icache_fetch(322 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, (unsigned int) y1); /* line 581 */
} /* line 581 */
  sim_icache_fetch(324 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_62, (unsigned int) t); /* line 583 */
} /* line 583 */
  sim_icache_fetch(326 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 585 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 586 */
   ADD_CYCLES(1);
} /* line 586 */
  sim_icache_fetch(328 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 587 */
l_L18X3: ;/* line 590 */
LABEL(l_L18X3);
  sim_icache_fetch(329 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 124),0,4), reg_r0_2); /* line 591 */
} /* line 591 */
  sim_icache_fetch(330 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 128),0,4), reg_r0_4); /* line 593 */
} /* line 593 */
  sim_icache_fetch(331 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 595 */
} /* line 595 */
  sim_icache_fetch(332 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_4); /* line 597 */
} /* line 597 */
  sim_icache_fetch(333 + t_thisfile.offset, 1);
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
} /* line 599 */
  sim_icache_fetch(334 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, reg_r0_4); /* line 601 */
} /* line 601 */
  sim_icache_fetch(335 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, 0); /* line 603 */
} /* line 603 */
  sim_icache_fetch(336 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, 0); /* line 605 */
} /* line 605 */
  sim_icache_fetch(337 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, 0); /* line 607 */
} /* line 607 */
  sim_icache_fetch(338 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, 0); /* line 609 */
} /* line 609 */
l_L20X3: ;/* line 612 */
LABEL(l_L20X3);
  sim_icache_fetch(339 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_57, 0); /* line 613 */
} /* line 613 */
  sim_icache_fetch(340 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 615 */
} /* line 615 */
  sim_icache_fetch(342 + t_thisfile.offset, 1);
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
} /* line 617 */
  sim_icache_fetch(343 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_58); /* line 619 */
} /* line 619 */
		 /* line 620 */
  sim_icache_fetch(344 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 622 */
l_lr_83: ;/* line 622 */
LABEL(l_lr_83);
  sim_icache_fetch(346 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 60),0,4), reg_r0_3); /* line 624 */
} /* line 624 */
  sim_icache_fetch(347 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, reg_r0_59); /* line 626 */
} /* line 626 */
  sim_icache_fetch(348 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 628 */
} /* line 628 */
  sim_icache_fetch(350 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 630 */
} /* line 630 */
		 /* line 631 */
  sim_icache_fetch(351 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 633 */
l_lr_85: ;/* line 633 */
LABEL(l_lr_85);
  sim_icache_fetch(353 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 64),0,4), reg_r0_3); /* line 635 */
} /* line 635 */
  sim_icache_fetch(354 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1038202178); /* line 637 */
} /* line 637 */
  sim_icache_fetch(356 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_60); /* line 639 */
} /* line 639 */
		 /* line 640 */
  sim_icache_fetch(357 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 642 */
l_lr_87: ;/* line 642 */
LABEL(l_lr_87);
  sim_icache_fetch(359 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 68),0,4), reg_r0_3); /* line 644 */
} /* line 644 */
  sim_icache_fetch(360 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH3ADD(reg_r0_2, reg_r0_61, reg_r0_62); /* line 646 */
} /* line 646 */
  sim_icache_fetch(361 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld(reg_r0_2,0,4)); /* line 648 */
} /* line 648 */
  sim_icache_fetch(362 + t_thisfile.offset, 3);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1103022629); /* line 650 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 651 */
   ADD_CYCLES(1);
} /* line 651 */
  sim_icache_fetch(365 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_60); /* line 653 */
} /* line 653 */
		 /* line 654 */
  sim_icache_fetch(366 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 656 */
l_lr_89: ;/* line 656 */
LABEL(l_lr_89);
  sim_icache_fetch(368 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 72),0,4), reg_r0_3); /* line 658 */
} /* line 658 */
  sim_icache_fetch(369 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 60),0,4)); /* line 660 */
} /* line 660 */
  sim_icache_fetch(370 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 64),0,4)); /* line 662 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 663 */
   ADD_CYCLES(1);
} /* line 663 */
		 /* line 664 */
  sim_icache_fetch(372 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 666 */
l_lr_91: ;/* line 666 */
LABEL(l_lr_91);
  sim_icache_fetch(374 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 68),0,4)); /* line 668 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 669 */
   ADD_CYCLES(1);
} /* line 669 */
		 /* line 670 */
  sim_icache_fetch(376 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 672 */
l_lr_93: ;/* line 672 */
LABEL(l_lr_93);
  sim_icache_fetch(378 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 72),0,4)); /* line 674 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 675 */
   ADD_CYCLES(1);
} /* line 675 */
		 /* line 676 */
  sim_icache_fetch(380 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 678 */
l_lr_95: ;/* line 678 */
LABEL(l_lr_95);
  sim_icache_fetch(382 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH3ADD(reg_r0_2, reg_r0_61, reg_r0_63); /* line 680 */
} /* line 680 */
  sim_icache_fetch(383 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 525); /* line 682 */
} /* line 682 */
  sim_icache_fetch(385 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 684 */
} /* line 684 */
  sim_icache_fetch(386 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, reg_r0_3); /* line 686 */
} /* line 686 */
  sim_icache_fetch(387 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_2,0,4), reg_r0_3); /* line 689 */
} /* line 689 */
  sim_icache_fetch(388 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L20X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L20X3;
} /* line 691 */
l_L21X3: ;/* line 694 */
LABEL(l_L21X3);
  sim_icache_fetch(389 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_63, reg_r0_63, (unsigned int) 4); /* line 695 */
} /* line 695 */
  sim_icache_fetch(390 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_62, reg_r0_62, (unsigned int) 4); /* line 697 */
} /* line 697 */
  sim_icache_fetch(391 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 124),0,4)); /* line 699 */
} /* line 699 */
  sim_icache_fetch(392 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 701 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 702 */
   ADD_CYCLES(1);
} /* line 702 */
  sim_icache_fetch(394 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 705 */
} /* line 705 */
  sim_icache_fetch(395 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L18X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L18X3;
} /* line 707 */
l_L19X3: ;/* line 710 */
LABEL(l_L19X3);
  sim_icache_fetch(396 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX10); /* line 711 */
} /* line 711 */
		 /* line 712 */
  sim_icache_fetch(398 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 714 */
l_lr_99: ;/* line 714 */
LABEL(l_lr_99);
  sim_icache_fetch(400 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, ((unsigned int) y1 + (unsigned int) 58820)); /* line 716 */
} /* line 716 */
  sim_icache_fetch(402 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) -11); /* line 718 */
} /* line 718 */
  sim_icache_fetch(403 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 720 */
} /* line 720 */
  sim_icache_fetch(404 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 722 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 723 */
   ADD_CYCLES(1);
} /* line 723 */
  sim_icache_fetch(406 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 724 */
l_L22X3: ;/* line 727 */
LABEL(l_L22X3);
  sim_icache_fetch(407 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_57,0,4)); /* line 728 */
} /* line 728 */
  sim_icache_fetch(408 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 730 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 731 */
   ADD_CYCLES(1);
} /* line 731 */
  sim_icache_fetch(410 + t_thisfile.offset, 1);
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
} /* line 733 */
		 /* line 734 */
  sim_icache_fetch(411 + t_thisfile.offset, 2);
{
  sim_result_0_t t_sim_result_0_t;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_d_r);
   reg_l0_0 = (256 << 5);
   {
    typedef sim_result_0_t t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _d_r;
    t_sim_result_0_t =     (*t_call)(reg_r0_3);
    reg_r0_3 = t_sim_result_0_t.alias0;
    reg_r0_4 = t_sim_result_0_t.alias1;
   }
} /* line 736 */
l_lr_102: ;/* line 736 */
LABEL(l_lr_102);
  sim_icache_fetch(413 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_3); /* line 738 */
} /* line 738 */
  sim_icache_fetch(414 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX11); /* line 740 */
} /* line 740 */
  sim_icache_fetch(416 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_4); /* line 742 */
} /* line 742 */
  sim_icache_fetch(417 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 744 */
} /* line 744 */
		 /* line 745 */
  sim_icache_fetch(418 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 747 */
l_lr_104: ;/* line 747 */
LABEL(l_lr_104);
  sim_icache_fetch(420 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 4200); /* line 749 */
} /* line 749 */
  sim_icache_fetch(422 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 752 */
} /* line 752 */
  sim_icache_fetch(423 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L22X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L22X3;
} /* line 754 */
l_L23X3: ;/* line 757 */
LABEL(l_L23X3);
  sim_icache_fetch(424 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX12); /* line 758 */
} /* line 758 */
  sim_icache_fetch(426 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 96),0,4), reg_r0_59); /* line 760 */
} /* line 760 */
  sim_icache_fetch(427 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 128),0,4), reg_r0_60); /* line 762 */
} /* line 762 */
		 /* line 763 */
  sim_icache_fetch(428 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 765 */
l_lr_107: ;/* line 765 */
LABEL(l_lr_107);
  sim_icache_fetch(430 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_59, 0, reg_r0_59); /* line 767 */
} /* line 767 */
  sim_icache_fetch(431 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_59); /* line 769 */
} /* line 769 */
  sim_icache_fetch(432 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) t); /* line 771 */
} /* line 771 */
  sim_icache_fetch(434 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 76),0,4), reg_r0_3); /* line 773 */
} /* line 773 */
  sim_icache_fetch(435 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, (unsigned int) y2); /* line 775 */
} /* line 775 */
  sim_icache_fetch(437 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_60, (unsigned int) -1); /* line 777 */
} /* line 777 */
l_L24X3: ;/* line 780 */
LABEL(l_L24X3);
  sim_icache_fetch(438 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 132),0,4), reg_r0_2); /* line 781 */
} /* line 781 */
  sim_icache_fetch(439 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 136),0,4), reg_r0_5); /* line 783 */
} /* line 783 */
  sim_icache_fetch(440 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 785 */
} /* line 785 */
  sim_icache_fetch(441 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULLU(reg_r0_62, reg_r0_5, (unsigned int) 525); /* line 787 */
} /* line 787 */
  sim_icache_fetch(443 + t_thisfile.offset, 1);
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
} /* line 789 */
  sim_icache_fetch(444 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, 0); /* line 791 */
} /* line 791 */
  sim_icache_fetch(445 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, 0); /* line 793 */
} /* line 793 */
  sim_icache_fetch(446 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, 0); /* line 795 */
} /* line 795 */
  sim_icache_fetch(447 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, 0); /* line 797 */
} /* line 797 */
  sim_icache_fetch(448 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, reg_r0_5); /* line 799 */
} /* line 799 */
l_L26X3: ;/* line 802 */
LABEL(l_L26X3);
  sim_icache_fetch(449 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_57, 0); /* line 803 */
} /* line 803 */
  sim_icache_fetch(450 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1088731746); /* line 805 */
} /* line 805 */
  sim_icache_fetch(452 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L27X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 807 */
  sim_icache_fetch(453 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_58); /* line 809 */
} /* line 809 */
		 /* line 810 */
  sim_icache_fetch(454 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 812 */
l_lr_111: ;/* line 812 */
LABEL(l_lr_111);
  sim_icache_fetch(456 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 80),0,4), reg_r0_3); /* line 814 */
} /* line 814 */
  sim_icache_fetch(457 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, reg_r0_59); /* line 816 */
} /* line 816 */
  sim_icache_fetch(458 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1062683894); /* line 818 */
} /* line 818 */
  sim_icache_fetch(460 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_59); /* line 820 */
} /* line 820 */
		 /* line 821 */
  sim_icache_fetch(461 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 823 */
l_lr_113: ;/* line 823 */
LABEL(l_lr_113);
  sim_icache_fetch(463 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 84),0,4), reg_r0_3); /* line 825 */
} /* line 825 */
  sim_icache_fetch(464 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1038770187); /* line 827 */
} /* line 827 */
  sim_icache_fetch(466 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_60); /* line 829 */
} /* line 829 */
		 /* line 830 */
  sim_icache_fetch(467 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 832 */
l_lr_115: ;/* line 832 */
LABEL(l_lr_115);
  sim_icache_fetch(469 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 88),0,4), reg_r0_3); /* line 834 */
} /* line 834 */
  sim_icache_fetch(470 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, reg_r0_61); /* line 836 */
} /* line 836 */
  sim_icache_fetch(471 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) -1103358174); /* line 838 */
} /* line 838 */
  sim_icache_fetch(473 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_61); /* line 840 */
} /* line 840 */
		 /* line 841 */
  sim_icache_fetch(474 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 843 */
l_lr_117: ;/* line 843 */
LABEL(l_lr_117);
  sim_icache_fetch(476 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 92),0,4), reg_r0_3); /* line 845 */
} /* line 845 */
  sim_icache_fetch(477 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 80),0,4)); /* line 847 */
} /* line 847 */
  sim_icache_fetch(478 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 84),0,4)); /* line 849 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 850 */
   ADD_CYCLES(1);
} /* line 850 */
		 /* line 851 */
  sim_icache_fetch(480 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 853 */
l_lr_119: ;/* line 853 */
LABEL(l_lr_119);
  sim_icache_fetch(482 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 88),0,4)); /* line 855 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 856 */
   ADD_CYCLES(1);
} /* line 856 */
		 /* line 857 */
  sim_icache_fetch(484 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 859 */
l_lr_121: ;/* line 859 */
LABEL(l_lr_121);
  sim_icache_fetch(486 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 92),0,4)); /* line 861 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 862 */
   ADD_CYCLES(1);
} /* line 862 */
		 /* line 863 */
  sim_icache_fetch(488 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 865 */
l_lr_123: ;/* line 865 */
LABEL(l_lr_123);
  sim_icache_fetch(490 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH3ADD(reg_r0_4, reg_r0_62, reg_r0_63); /* line 867 */
} /* line 867 */
  sim_icache_fetch(491 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 76),0,4)); /* line 869 */
} /* line 869 */
  sim_icache_fetch(492 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) -1); /* line 871 */
} /* line 871 */
  sim_icache_fetch(493 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, reg_r0_3); /* line 873 */
} /* line 873 */
  sim_icache_fetch(494 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH3ADD(reg_r0_5, reg_r0_62, reg_r0_2); /* line 875 */
} /* line 875 */
  sim_icache_fetch(495 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld(reg_r0_5,0,4)); /* line 877 */
} /* line 877 */
  sim_icache_fetch(496 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_62, reg_r0_62, (unsigned int) -525); /* line 879 */
} /* line 879 */
  sim_icache_fetch(498 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_4,0,4), reg_r0_3); /* line 882 */
} /* line 882 */
  sim_icache_fetch(499 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L26X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L26X3;
} /* line 884 */
l_L27X3: ;/* line 887 */
LABEL(l_L27X3);
  sim_icache_fetch(500 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 76),0,4)); /* line 888 */
} /* line 888 */
  sim_icache_fetch(501 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_63, reg_r0_63, (unsigned int) 4); /* line 890 */
} /* line 890 */
  sim_icache_fetch(502 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 132),0,4)); /* line 892 */
} /* line 892 */
  sim_icache_fetch(503 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, (unsigned int) 4); /* line 894 */
} /* line 894 */
  sim_icache_fetch(504 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 76),0,4), reg_r0_3); /* line 896 */
} /* line 896 */
  sim_icache_fetch(505 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 1); /* line 898 */
} /* line 898 */
  sim_icache_fetch(506 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_5, mem_trace_ld((reg_r0_1 + (unsigned int) 136),0,4)); /* line 900 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 901 */
   ADD_CYCLES(1);
} /* line 901 */
  sim_icache_fetch(508 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L24X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L24X3;
} /* line 903 */
l_L25X3: ;/* line 906 */
LABEL(l_L25X3);
  sim_icache_fetch(509 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX13); /* line 907 */
} /* line 907 */
		 /* line 908 */
  sim_icache_fetch(511 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 910 */
l_lr_127: ;/* line 910 */
LABEL(l_lr_127);
  sim_icache_fetch(513 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, ((unsigned int) y2 + (unsigned int) 58820)); /* line 912 */
} /* line 912 */
  sim_icache_fetch(515 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) -11); /* line 914 */
} /* line 914 */
l_L28X3: ;/* line 917 */
LABEL(l_L28X3);
  sim_icache_fetch(516 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_57,0,4)); /* line 918 */
} /* line 918 */
  sim_icache_fetch(517 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 920 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 921 */
   ADD_CYCLES(1);
} /* line 921 */
  sim_icache_fetch(519 + t_thisfile.offset, 1);
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
} /* line 923 */
		 /* line 924 */
  sim_icache_fetch(520 + t_thisfile.offset, 2);
{
  sim_result_0_t t_sim_result_0_t;
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_d_r);
   reg_l0_0 = (256 << 5);
   {
    typedef sim_result_0_t t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _d_r;
    t_sim_result_0_t =     (*t_call)(reg_r0_3);
    reg_r0_3 = t_sim_result_0_t.alias0;
    reg_r0_4 = t_sim_result_0_t.alias1;
   }
} /* line 926 */
l_lr_130: ;/* line 926 */
LABEL(l_lr_130);
  sim_icache_fetch(522 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_3); /* line 928 */
} /* line 928 */
  sim_icache_fetch(523 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX14); /* line 930 */
} /* line 930 */
  sim_icache_fetch(525 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_4); /* line 932 */
} /* line 932 */
  sim_icache_fetch(526 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 934 */
} /* line 934 */
		 /* line 935 */
  sim_icache_fetch(527 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int, unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4, reg_r0_5, reg_r0_6);
   }
} /* line 937 */
l_lr_132: ;/* line 937 */
LABEL(l_lr_132);
  sim_icache_fetch(529 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 4200); /* line 939 */
} /* line 939 */
  sim_icache_fetch(531 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 942 */
} /* line 942 */
  sim_icache_fetch(532 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L28X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L28X3;
} /* line 944 */
l_L29X3: ;/* line 947 */
LABEL(l_L29X3);
  sim_icache_fetch(533 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX15); /* line 948 */
} /* line 948 */
		 /* line 949 */
  sim_icache_fetch(535 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 951 */
l_lr_135: ;/* line 951 */
LABEL(l_lr_135);
  sim_icache_fetch(537 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_4, mem_trace_ld((reg_r0_1 + (unsigned int) 128),0,4)); /* line 953 */
} /* line 953 */
  sim_icache_fetch(538 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_61, (unsigned int) out); /* line 955 */
} /* line 955 */
  sim_icache_fetch(540 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_59, (unsigned int) y1); /* line 957 */
} /* line 957 */
  sim_icache_fetch(542 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_4); /* line 959 */
} /* line 959 */
  sim_icache_fetch(543 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_4); /* line 961 */
} /* line 961 */
  sim_icache_fetch(544 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) y2); /* line 963 */
} /* line 963 */
  sim_icache_fetch(546 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 96),0,4)); /* line 965 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 966 */
   ADD_CYCLES(1);
} /* line 966 */
  sim_icache_fetch(548 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 967 */
l_L30X3: ;/* line 970 */
LABEL(l_L30X3);
  sim_icache_fetch(549 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_2, 0); /* line 971 */
} /* line 971 */
  sim_icache_fetch(550 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_4, 0, reg_r0_3); /* line 973 */
} /* line 973 */
  sim_icache_fetch(551 + t_thisfile.offset, 1);
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
} /* line 975 */
  sim_icache_fetch(552 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_60, reg_r0_4); /* line 977 */
} /* line 977 */
  sim_icache_fetch(553 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, 0); /* line 979 */
} /* line 979 */
  sim_icache_fetch(554 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_62, reg_r0_2); /* line 981 */
} /* line 981 */
  sim_icache_fetch(555 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_63, reg_r0_3); /* line 983 */
} /* line 983 */
l_L32X3: ;/* line 986 */
LABEL(l_L32X3);
  sim_icache_fetch(556 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_2, reg_r0_57, reg_r0_58); /* line 987 */
} /* line 987 */
  sim_icache_fetch(557 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 989 */
} /* line 989 */
  sim_icache_fetch(558 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_5, reg_r0_57, reg_r0_59); /* line 991 */
} /* line 991 */
  sim_icache_fetch(559 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_4, mem_trace_ld(reg_r0_5,0,4)); /* line 993 */
} /* line 993 */
  sim_icache_fetch(560 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_60, 0); /* line 995 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 996 */
   ADD_CYCLES(1);
} /* line 996 */
  sim_icache_fetch(562 + t_thisfile.offset, 1);
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
} /* line 998 */
		 /* line 999 */
  sim_icache_fetch(563 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_add);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_add;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 1001 */
l_lr_139: ;/* line 1001 */
LABEL(l_lr_139);
  sim_icache_fetch(565 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, (unsigned int) 1065353216); /* line 1003 */
} /* line 1003 */
		 /* line 1004 */
  sim_icache_fetch(567 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_mul);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) _r_mul;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 1006 */
l_lr_141: ;/* line 1006 */
LABEL(l_lr_141);
		 /* line 1007 */
  sim_icache_fetch(569 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(_r_ufix);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) _r_ufix;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1009 */
l_lr_143: ;/* line 1009 */
LABEL(l_lr_143);
  sim_icache_fetch(571 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_57, reg_r0_61); /* line 1011 */
} /* line 1011 */
  sim_icache_fetch(572 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_4, reg_r0_3); /* line 1013 */
} /* line 1013 */
  sim_icache_fetch(573 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_4, (unsigned int) 25); /* line 1015 */
} /* line 1015 */
  sim_icache_fetch(574 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_57, reg_r0_61); /* line 1017 */
} /* line 1017 */
  sim_icache_fetch(575 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 1019 */
} /* line 1019 */
  sim_icache_fetch(576 + t_thisfile.offset, 1);
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
} /* line 1021 */
  sim_icache_fetch(577 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 1023 */
} /* line 1023 */
  sim_icache_fetch(578 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 1025 */
} /* line 1025 */
  sim_icache_fetch(579 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_5,0,1), 0); /* line 1028 */
} /* line 1028 */
  sim_icache_fetch(580 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L32X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L32X3;
} /* line 1030 */
l_L34X3: ;/* line 1033 */
LABEL(l_L34X3);
  sim_icache_fetch(581 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_57, reg_r0_61); /* line 1034 */
} /* line 1034 */
  sim_icache_fetch(582 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 1036 */
} /* line 1036 */
  sim_icache_fetch(583 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_60, reg_r0_60, (unsigned int) 1); /* line 1038 */
} /* line 1038 */
  sim_icache_fetch(584 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1); /* line 1040 */
} /* line 1040 */
  sim_icache_fetch(585 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_2,0,1), reg_r0_3); /* line 1043 */
} /* line 1043 */
  sim_icache_fetch(586 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L32X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L32X3;
} /* line 1045 */
l_L33X3: ;/* line 1048 */
LABEL(l_L33X3);
  sim_icache_fetch(587 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_61, reg_r0_61, (unsigned int) 1050); /* line 1049 */
} /* line 1049 */
  sim_icache_fetch(589 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_59, reg_r0_59, (unsigned int) 4200); /* line 1051 */
} /* line 1051 */
  sim_icache_fetch(591 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 4200); /* line 1053 */
} /* line 1053 */
  sim_icache_fetch(593 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_62, (unsigned int) 1); /* line 1055 */
} /* line 1055 */
  sim_icache_fetch(594 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_63); /* line 1058 */
} /* line 1058 */
  sim_icache_fetch(595 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L30X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L30X3;
} /* line 1060 */
l_L31X3: ;/* line 1063 */
LABEL(l_L31X3);
  sim_icache_fetch(596 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX16); /* line 1064 */
} /* line 1064 */
		 /* line 1065 */
  sim_icache_fetch(598 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1067 */
l_lr_148: ;/* line 1067 */
LABEL(l_lr_148);
  sim_icache_fetch(600 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, ((unsigned int) out + (unsigned int) 14705)); /* line 1069 */
} /* line 1069 */
  sim_icache_fetch(602 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) -11); /* line 1071 */
} /* line 1071 */
l_L35X3: ;/* line 1074 */
LABEL(l_L35X3);
  sim_icache_fetch(603 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_4, mem_trace_ld(reg_r0_57,0,1)); /* line 1075 */
} /* line 1075 */
  sim_icache_fetch(604 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 1077 */
} /* line 1077 */
  sim_icache_fetch(605 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX17); /* line 1079 */
} /* line 1079 */
  sim_icache_fetch(607 + t_thisfile.offset, 1);
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
} /* line 1081 */
		 /* line 1082 */
  sim_icache_fetch(608 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 1084 */
l_lr_151: ;/* line 1084 */
LABEL(l_lr_151);
  sim_icache_fetch(610 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1050); /* line 1086 */
} /* line 1086 */
  sim_icache_fetch(612 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 1089 */
} /* line 1089 */
  sim_icache_fetch(613 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L35X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L35X3;
} /* line 1091 */
l_L36X3: ;/* line 1094 */
LABEL(l_L36X3);
  sim_icache_fetch(614 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX18); /* line 1095 */
} /* line 1095 */
		 /* line 1096 */
  sim_icache_fetch(616 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (256 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1098 */
l_lr_154: ;/* line 1098 */
LABEL(l_lr_154);
  sim_icache_fetch(618 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1100 */
} /* line 1100 */
  sim_icache_fetch(619 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_63, mem_trace_ld((reg_r0_1 + (unsigned int) 164),0,4)); /* line 1102 */
} /* line 1102 */
  sim_icache_fetch(620 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_62, mem_trace_ld((reg_r0_1 + (unsigned int) 160),0,4)); /* line 1104 */
} /* line 1104 */
  sim_icache_fetch(621 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_61, mem_trace_ld((reg_r0_1 + (unsigned int) 156),0,4)); /* line 1106 */
} /* line 1106 */
  sim_icache_fetch(622 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 152),0,4)); /* line 1108 */
} /* line 1108 */
  sim_icache_fetch(623 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 148),0,4)); /* line 1110 */
} /* line 1110 */
  sim_icache_fetch(624 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 144),0,4)); /* line 1112 */
} /* line 1112 */
  sim_icache_fetch(625 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 140),0,4)); /* line 1114 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1115 */
   ADD_CYCLES(1);
} /* line 1115 */
  sim_icache_fetch(627 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_float);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 192; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1118 */
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
    case 124: goto l_lr_23;
    case 125: goto l_L4X3;
    case 127: goto l_lr_26;
    case 129: goto l_lr_28;
    case 130: goto l_L5X3;
    case 132: goto l_lr_31;
    case 133: goto l_L6X3;
    case 134: goto l_L8X3;
    case 136: goto l_lr_35;
    case 138: goto l_lr_37;
    case 140: goto l_lr_39;
    case 142: goto l_lr_41;
    case 144: goto l_lr_43;
    case 146: goto l_lr_45;
    case 148: goto l_lr_47;
    case 150: goto l_lr_49;
    case 151: goto l_L9X3;
    case 152: goto l_L7X3;
    case 154: goto l_lr_53;
    case 155: goto l_L10X3;
    case 157: goto l_lr_56;
    case 159: goto l_lr_58;
    case 160: goto l_L11X3;
    case 162: goto l_lr_61;
    case 163: goto l_L12X3;
    case 164: goto l_L14X3;
    case 166: goto l_lr_65;
    case 168: goto l_lr_67;
    case 169: goto l_L15X3;
    case 170: goto l_L13X3;
    case 172: goto l_lr_71;
    case 173: goto l_L16X3;
    case 175: goto l_lr_74;
    case 177: goto l_lr_76;
    case 178: goto l_L17X3;
    case 180: goto l_lr_79;
    case 181: goto l_L18X3;
    case 182: goto l_L20X3;
    case 184: goto l_lr_83;
    case 186: goto l_lr_85;
    case 188: goto l_lr_87;
    case 190: goto l_lr_89;
    case 192: goto l_lr_91;
    case 194: goto l_lr_93;
    case 196: goto l_lr_95;
    case 197: goto l_L21X3;
    case 198: goto l_L19X3;
    case 200: goto l_lr_99;
    case 201: goto l_L22X3;
    case 203: goto l_lr_102;
    case 205: goto l_lr_104;
    case 206: goto l_L23X3;
    case 208: goto l_lr_107;
    case 209: goto l_L24X3;
    case 210: goto l_L26X3;
    case 212: goto l_lr_111;
    case 214: goto l_lr_113;
    case 216: goto l_lr_115;
    case 218: goto l_lr_117;
    case 220: goto l_lr_119;
    case 222: goto l_lr_121;
    case 224: goto l_lr_123;
    case 225: goto l_L27X3;
    case 226: goto l_L25X3;
    case 228: goto l_lr_127;
    case 229: goto l_L28X3;
    case 231: goto l_lr_130;
    case 233: goto l_lr_132;
    case 234: goto l_L29X3;
    case 236: goto l_lr_135;
    case 237: goto l_L30X3;
    case 238: goto l_L32X3;
    case 240: goto l_lr_139;
    case 242: goto l_lr_141;
    case 244: goto l_lr_143;
    case 245: goto l_L34X3;
    case 246: goto l_L33X3;
    case 247: goto l_L31X3;
    case 249: goto l_lr_148;
    case 250: goto l_L35X3;
    case 252: goto l_lr_151;
    case 253: goto l_L36X3;
    case 255: goto l_lr_154;
    case 256:
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
  sim_check_stack(reg_r0_1, -32); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (259 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(628 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_1, reg_r0_1, (unsigned int) -32); /* line 1307 */
} /* line 1307 */
  sim_icache_fetch(629 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1309 */
} /* line 1309 */
  sim_icache_fetch(630 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX19); /* line 1311 */
} /* line 1311 */
		 /* line 1312 */
  sim_icache_fetch(632 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (259 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1314 */
l_lr_157: ;/* line 1314 */
LABEL(l_lr_157);
  sim_icache_fetch(634 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 1316 */
   INC_NOP_CNT((unsigned int) 3);
   XNOP((unsigned int) 3); /* line 1317 */
   ADD_CYCLES(3);
} /* line 1317 */
  sim_icache_fetch(636 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_fused);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 32; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 1320 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 258: goto l_lr_157;
    case 259:
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
  sim_check_stack(reg_r0_1, -64); 

  t_client_rpc = reg_l0_0; 
  reg_r0_3 =  arg0; 
  reg_r0_4 =  arg1; 
  reg_l0_0 = (344 << 5);
  if (!t_thisfile.init) sim_init_fileinfo(&t_thisfile);

		/*  CODE */

  sim_icache_fetch(637 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_1, reg_r0_1, (unsigned int) -64); /* line 1352 */
} /* line 1352 */
  sim_icache_fetch(638 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_l0_0); /* line 1354 */
} /* line 1354 */
  sim_icache_fetch(639 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_3); /* line 1356 */
} /* line 1356 */
  sim_icache_fetch(640 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, (unsigned int) in); /* line 1358 */
} /* line 1358 */
  sim_icache_fetch(642 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_3); /* line 1360 */
} /* line 1360 */
  sim_icache_fetch(643 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_2); /* line 1362 */
} /* line 1362 */
  sim_icache_fetch(644 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) fy1); /* line 1364 */
} /* line 1364 */
  sim_icache_fetch(646 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_4); /* line 1366 */
} /* line 1366 */
  sim_icache_fetch(647 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_20, reg_l0_0); /* line 1368 */
} /* line 1368 */
l_L37X3: ;/* line 1371 */
LABEL(l_L37X3);
  sim_icache_fetch(648 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 1372 */
} /* line 1372 */
  sim_icache_fetch(649 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_12, (unsigned int) 3, reg_r0_9); /* line 1374 */
} /* line 1374 */
  sim_icache_fetch(650 + t_thisfile.offset, 1);
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
} /* line 1376 */
  sim_icache_fetch(651 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_12); /* line 1378 */
} /* line 1378 */
  sim_icache_fetch(652 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_10); /* line 1380 */
} /* line 1380 */
  sim_icache_fetch(653 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 1382 */
} /* line 1382 */
  sim_icache_fetch(654 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 1384 */
} /* line 1384 */
  sim_icache_fetch(655 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_11); /* line 1386 */
} /* line 1386 */
  sim_icache_fetch(656 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, 0); /* line 1388 */
} /* line 1388 */
  sim_icache_fetch(657 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_3); /* line 1390 */
} /* line 1390 */
  sim_icache_fetch(658 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_9); /* line 1392 */
} /* line 1392 */
  sim_icache_fetch(659 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_10); /* line 1394 */
} /* line 1394 */
  sim_icache_fetch(660 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_11); /* line 1396 */
} /* line 1396 */
l_L39X3: ;/* line 1399 */
LABEL(l_L39X3);
  sim_icache_fetch(661 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_2,0,1)); /* line 1400 */
} /* line 1400 */
  sim_icache_fetch(662 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_4, (unsigned int) 215); /* line 1402 */
} /* line 1402 */
  sim_icache_fetch(663 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 1404 */
} /* line 1404 */
  sim_icache_fetch(664 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_3, (unsigned int) -48); /* line 1406 */
} /* line 1406 */
  sim_icache_fetch(665 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1408 */
} /* line 1408 */
  sim_icache_fetch(666 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_9); /* line 1410 */
} /* line 1410 */
  sim_icache_fetch(667 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 1412 */
} /* line 1412 */
  sim_icache_fetch(668 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 1414 */
} /* line 1414 */
  sim_icache_fetch(669 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 3); /* line 1416 */
} /* line 1416 */
  sim_icache_fetch(670 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_5); /* line 1418 */
} /* line 1418 */
  sim_icache_fetch(671 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, reg_r0_10); /* line 1420 */
} /* line 1420 */
  sim_icache_fetch(672 + t_thisfile.offset, 1);
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
} /* line 1422 */
  sim_icache_fetch(673 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 2); /* line 1424 */
} /* line 1424 */
  sim_icache_fetch(674 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 1),0,1)); /* line 1426 */
} /* line 1426 */
  sim_icache_fetch(675 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_6, (unsigned int) 215); /* line 1428 */
} /* line 1428 */
  sim_icache_fetch(676 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1430 */
} /* line 1430 */
  sim_icache_fetch(677 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_9, (unsigned int) -48); /* line 1432 */
} /* line 1432 */
  sim_icache_fetch(678 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1434 */
} /* line 1434 */
  sim_icache_fetch(679 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_10); /* line 1436 */
} /* line 1436 */
  sim_icache_fetch(680 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1438 */
} /* line 1438 */
  sim_icache_fetch(681 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 1440 */
} /* line 1440 */
  sim_icache_fetch(682 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_7, (unsigned int) 1); /* line 1442 */
} /* line 1442 */
  sim_icache_fetch(683 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_4); /* line 1444 */
} /* line 1444 */
  sim_icache_fetch(684 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_11); /* line 1446 */
} /* line 1446 */
  sim_icache_fetch(685 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 2),0,1)); /* line 1448 */
} /* line 1448 */
  sim_icache_fetch(686 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_3, (unsigned int) 215); /* line 1450 */
} /* line 1450 */
  sim_icache_fetch(687 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_6, (unsigned int) -155); /* line 1452 */
} /* line 1452 */
  sim_icache_fetch(688 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_10, (unsigned int) -48); /* line 1454 */
} /* line 1454 */
  sim_icache_fetch(689 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 1456 */
} /* line 1456 */
  sim_icache_fetch(690 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, reg_r0_11); /* line 1458 */
} /* line 1458 */
  sim_icache_fetch(691 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1460 */
} /* line 1460 */
  sim_icache_fetch(692 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 28); /* line 1462 */
} /* line 1462 */
  sim_icache_fetch(693 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_7, 0); /* line 1464 */
} /* line 1464 */
  sim_icache_fetch(694 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_12); /* line 1466 */
} /* line 1466 */
  sim_icache_fetch(695 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_13); /* line 1468 */
} /* line 1468 */
  sim_icache_fetch(696 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_11, mem_trace_ld((reg_r0_2 + (unsigned int) 3),0,1)); /* line 1470 */
} /* line 1470 */
  sim_icache_fetch(697 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_9, (unsigned int) 215); /* line 1472 */
} /* line 1472 */
  sim_icache_fetch(698 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_3, (unsigned int) -155); /* line 1474 */
} /* line 1474 */
  sim_icache_fetch(699 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) -48); /* line 1476 */
} /* line 1476 */
  sim_icache_fetch(700 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1478 */
} /* line 1478 */
  sim_icache_fetch(701 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_12); /* line 1480 */
} /* line 1480 */
  sim_icache_fetch(702 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1482 */
} /* line 1482 */
  sim_icache_fetch(703 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 28); /* line 1484 */
} /* line 1484 */
  sim_icache_fetch(704 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_9); /* line 1486 */
} /* line 1486 */
  sim_icache_fetch(705 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_13); /* line 1488 */
} /* line 1488 */
  sim_icache_fetch(706 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_10, reg_r0_14); /* line 1490 */
} /* line 1490 */
  sim_icache_fetch(707 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 4); /* line 1492 */
} /* line 1492 */
  sim_icache_fetch(708 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 1494 */
} /* line 1494 */
  sim_icache_fetch(709 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_6); /* line 1496 */
} /* line 1496 */
  sim_icache_fetch(710 + t_thisfile.offset, 1);
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
} /* line 1498 */
  sim_icache_fetch(711 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_11); /* line 1500 */
} /* line 1500 */
  sim_icache_fetch(712 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4),0,4), reg_r0_3); /* line 1502 */
} /* line 1502 */
  sim_icache_fetch(713 + t_thisfile.offset, 1);
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
} /* line 1504 */
  sim_icache_fetch(714 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8),0,4), reg_r0_9); /* line 1506 */
} /* line 1506 */
  sim_icache_fetch(715 + t_thisfile.offset, 1);
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
} /* line 1508 */
  sim_icache_fetch(716 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12),0,4), reg_r0_4); /* line 1510 */
} /* line 1510 */
  sim_icache_fetch(717 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 1513 */
} /* line 1513 */
  sim_icache_fetch(718 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L39X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L39X3;
} /* line 1515 */
l_L40X3: ;/* line 1518 */
LABEL(l_L40X3);
  sim_icache_fetch(719 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_18, (unsigned int) 1050); /* line 1519 */
} /* line 1519 */
  sim_icache_fetch(721 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_17, (unsigned int) 4200); /* line 1521 */
} /* line 1521 */
  sim_icache_fetch(723 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_15, (unsigned int) 1); /* line 1523 */
} /* line 1523 */
  sim_icache_fetch(724 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_16); /* line 1526 */
} /* line 1526 */
  sim_icache_fetch(725 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L37X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L37X3;
} /* line 1528 */
l_L38X3: ;/* line 1531 */
LABEL(l_L38X3);
  sim_icache_fetch(726 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 16),0,4), reg_r0_20); /* line 1532 */
} /* line 1532 */
  sim_icache_fetch(727 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 20),0,4), reg_r0_57); /* line 1534 */
} /* line 1534 */
  sim_icache_fetch(728 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 24),0,4), reg_r0_58); /* line 1536 */
} /* line 1536 */
  sim_icache_fetch(729 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_19); /* line 1538 */
} /* line 1538 */
  sim_icache_fetch(730 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_9); /* line 1540 */
} /* line 1540 */
  sim_icache_fetch(731 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX20); /* line 1542 */
} /* line 1542 */
		 /* line 1543 */
  sim_icache_fetch(733 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1545 */
l_lr_164: ;/* line 1545 */
LABEL(l_lr_164);
  sim_icache_fetch(735 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, ((unsigned int) fy1 + (unsigned int) 58820)); /* line 1547 */
} /* line 1547 */
  sim_icache_fetch(737 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) -11); /* line 1549 */
} /* line 1549 */
l_L41X3: ;/* line 1552 */
LABEL(l_L41X3);
  sim_icache_fetch(738 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_2, mem_trace_ld(reg_r0_57,0,4)); /* line 1553 */
} /* line 1553 */
  sim_icache_fetch(739 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 1555 */
} /* line 1555 */
  sim_icache_fetch(740 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX21); /* line 1557 */
} /* line 1557 */
  sim_icache_fetch(742 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_2, (unsigned int) 8); /* line 1559 */
} /* line 1559 */
  sim_icache_fetch(743 + t_thisfile.offset, 1);
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
} /* line 1561 */
		 /* line 1562 */
  sim_icache_fetch(744 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 1564 */
l_lr_167: ;/* line 1564 */
LABEL(l_lr_167);
  sim_icache_fetch(746 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 4200); /* line 1566 */
} /* line 1566 */
  sim_icache_fetch(748 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 1569 */
} /* line 1569 */
  sim_icache_fetch(749 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L41X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L41X3;
} /* line 1571 */
l_L42X3: ;/* line 1574 */
LABEL(l_L42X3);
  sim_icache_fetch(750 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX22); /* line 1575 */
} /* line 1575 */
		 /* line 1576 */
  sim_icache_fetch(752 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1578 */
l_lr_170: ;/* line 1578 */
LABEL(l_lr_170);
  sim_icache_fetch(754 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1580 */
} /* line 1580 */
  sim_icache_fetch(755 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, ((unsigned int) fy2 + (unsigned int) -12)); /* line 1582 */
} /* line 1582 */
  sim_icache_fetch(757 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_3, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1584 */
} /* line 1584 */
  sim_icache_fetch(758 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_2); /* line 1586 */
} /* line 1586 */
  sim_icache_fetch(759 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_2); /* line 1588 */
} /* line 1588 */
  sim_icache_fetch(760 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_3, (unsigned int) -1); /* line 1590 */
} /* line 1590 */
  sim_icache_fetch(761 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, ((unsigned int) in + (unsigned int) -3)); /* line 1592 */
} /* line 1592 */
l_L43X3: ;/* line 1595 */
LABEL(l_L43X3);
  sim_icache_fetch(763 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_9, 0); /* line 1596 */
} /* line 1596 */
  sim_icache_fetch(764 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_10, reg_r0_11); /* line 1598 */
} /* line 1598 */
  sim_icache_fetch(765 + t_thisfile.offset, 1);
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
} /* line 1600 */
  sim_icache_fetch(766 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SH2ADD(reg_r0_7, reg_r0_11, reg_r0_12); /* line 1602 */
} /* line 1602 */
  sim_icache_fetch(767 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 1604 */
} /* line 1604 */
  sim_icache_fetch(768 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 1606 */
} /* line 1606 */
  sim_icache_fetch(769 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 1608 */
} /* line 1608 */
  sim_icache_fetch(770 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 1610 */
} /* line 1610 */
  sim_icache_fetch(771 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_11); /* line 1612 */
} /* line 1612 */
  sim_icache_fetch(772 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_9); /* line 1614 */
} /* line 1614 */
  sim_icache_fetch(773 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_10); /* line 1616 */
} /* line 1616 */
  sim_icache_fetch(774 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_11); /* line 1618 */
} /* line 1618 */
  sim_icache_fetch(775 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_19, reg_r0_12); /* line 1620 */
} /* line 1620 */
l_L45X3: ;/* line 1623 */
LABEL(l_L45X3);
  sim_icache_fetch(776 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 1624 */
} /* line 1624 */
  sim_icache_fetch(777 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_3, (unsigned int) -47); /* line 1626 */
} /* line 1626 */
  sim_icache_fetch(778 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 1628 */
} /* line 1628 */
  sim_icache_fetch(779 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_2); /* line 1630 */
} /* line 1630 */
  sim_icache_fetch(780 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 1632 */
} /* line 1632 */
  sim_icache_fetch(781 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -48); /* line 1634 */
} /* line 1634 */
  sim_icache_fetch(782 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1636 */
} /* line 1636 */
  sim_icache_fetch(783 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 1638 */
} /* line 1638 */
  sim_icache_fetch(784 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_5); /* line 1640 */
} /* line 1640 */
  sim_icache_fetch(785 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, 0); /* line 1642 */
} /* line 1642 */
  sim_icache_fetch(786 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 3),0,1)); /* line 1644 */
} /* line 1644 */
  sim_icache_fetch(787 + t_thisfile.offset, 1);
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
} /* line 1646 */
  sim_icache_fetch(788 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 1); /* line 1648 */
} /* line 1648 */
  sim_icache_fetch(789 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 1650 */
} /* line 1650 */
  sim_icache_fetch(790 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_10, (unsigned int) -47); /* line 1652 */
} /* line 1652 */
  sim_icache_fetch(791 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 1654 */
} /* line 1654 */
  sim_icache_fetch(792 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_4); /* line 1656 */
} /* line 1656 */
  sim_icache_fetch(793 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_9, (unsigned int) 215); /* line 1658 */
} /* line 1658 */
  sim_icache_fetch(794 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) -48); /* line 1660 */
} /* line 1660 */
  sim_icache_fetch(795 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_12, reg_r0_12, (unsigned int) 8); /* line 1662 */
} /* line 1662 */
  sim_icache_fetch(796 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_12); /* line 1664 */
} /* line 1664 */
  sim_icache_fetch(797 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 1666 */
} /* line 1666 */
  sim_icache_fetch(798 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_12, mem_trace_ld((reg_r0_8 + (unsigned int) 2),0,1)); /* line 1668 */
} /* line 1668 */
  sim_icache_fetch(799 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_6, (unsigned int) 2); /* line 1670 */
} /* line 1670 */
  sim_icache_fetch(800 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_9, (unsigned int) -155); /* line 1672 */
} /* line 1672 */
  sim_icache_fetch(801 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_12, (unsigned int) -47); /* line 1674 */
} /* line 1674 */
  sim_icache_fetch(802 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1676 */
} /* line 1676 */
  sim_icache_fetch(803 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_13); /* line 1678 */
} /* line 1678 */
  sim_icache_fetch(804 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_11, (unsigned int) 215); /* line 1680 */
} /* line 1680 */
  sim_icache_fetch(805 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) -48); /* line 1682 */
} /* line 1682 */
  sim_icache_fetch(806 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1684 */
} /* line 1684 */
  sim_icache_fetch(807 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_13); /* line 1686 */
} /* line 1686 */
  sim_icache_fetch(808 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 1688 */
} /* line 1688 */
  sim_icache_fetch(809 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 1),0,1)); /* line 1690 */
} /* line 1690 */
  sim_icache_fetch(810 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_2, reg_r0_6, (unsigned int) 3); /* line 1692 */
} /* line 1692 */
  sim_icache_fetch(811 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_11, (unsigned int) -155); /* line 1694 */
} /* line 1694 */
  sim_icache_fetch(812 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_15, reg_r0_10, (unsigned int) -47); /* line 1696 */
} /* line 1696 */
  sim_icache_fetch(813 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1698 */
} /* line 1698 */
  sim_icache_fetch(814 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_15, reg_r0_15, reg_r0_13); /* line 1700 */
} /* line 1700 */
  sim_icache_fetch(815 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_14, (unsigned int) 215); /* line 1702 */
} /* line 1702 */
  sim_icache_fetch(816 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_12, (unsigned int) -48); /* line 1704 */
} /* line 1704 */
  sim_icache_fetch(817 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_13, reg_r0_13, (unsigned int) 8); /* line 1706 */
} /* line 1706 */
  sim_icache_fetch(818 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_12, reg_r0_13); /* line 1708 */
} /* line 1708 */
  sim_icache_fetch(819 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_15, reg_r0_12); /* line 1710 */
} /* line 1710 */
  sim_icache_fetch(820 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_3, mem_trace_ld(reg_r0_8,0,1)); /* line 1712 */
} /* line 1712 */
  sim_icache_fetch(821 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_14); /* line 1714 */
} /* line 1714 */
  sim_icache_fetch(822 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_10); /* line 1716 */
} /* line 1716 */
  sim_icache_fetch(823 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) -4); /* line 1718 */
} /* line 1718 */
  sim_icache_fetch(824 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -4); /* line 1720 */
} /* line 1720 */
  sim_icache_fetch(825 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 12),0,4), reg_r0_9); /* line 1722 */
} /* line 1722 */
  sim_icache_fetch(826 + t_thisfile.offset, 1);
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
} /* line 1724 */
  sim_icache_fetch(827 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 8),0,4), reg_r0_11); /* line 1726 */
} /* line 1726 */
  sim_icache_fetch(828 + t_thisfile.offset, 1);
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
} /* line 1728 */
  sim_icache_fetch(829 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 4),0,4), reg_r0_14); /* line 1730 */
} /* line 1730 */
  sim_icache_fetch(830 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L49X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1732 */
  sim_icache_fetch(831 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_7,0,4), reg_r0_4); /* line 1734 */
} /* line 1734 */
  sim_icache_fetch(832 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -16); /* line 1737 */
} /* line 1737 */
  sim_icache_fetch(833 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L45X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L45X3;
} /* line 1739 */
l_L49X3: ;/* line 1742 */
LABEL(l_L49X3);
  sim_icache_fetch(834 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 4200); /* line 1744 */
} /* line 1744 */
  sim_icache_fetch(836 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L50X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L50X3;
} /* line 1746 */
l_L48X3: ;/* line 1749 */
LABEL(l_L48X3);
  sim_icache_fetch(837 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 4200); /* line 1751 */
} /* line 1751 */
  sim_icache_fetch(839 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L50X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L50X3;
} /* line 1753 */
l_L47X3: ;/* line 1756 */
LABEL(l_L47X3);
  sim_icache_fetch(840 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 4200); /* line 1758 */
} /* line 1758 */
  sim_icache_fetch(842 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L50X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L50X3;
} /* line 1760 */
l_L46X3: ;/* line 1763 */
LABEL(l_L46X3);
  sim_icache_fetch(843 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_19, (unsigned int) 4200); /* line 1764 */
} /* line 1764 */
l_L50X3: ;/* line 1766 */
LABEL(l_L50X3);
  sim_icache_fetch(845 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_17, (unsigned int) 1050); /* line 1767 */
} /* line 1767 */
  sim_icache_fetch(847 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_16, (unsigned int) 1); /* line 1769 */
} /* line 1769 */
  sim_icache_fetch(848 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, reg_r0_18); /* line 1772 */
} /* line 1772 */
  sim_icache_fetch(849 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L43X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L43X3;
} /* line 1774 */
l_L44X3: ;/* line 1777 */
LABEL(l_L44X3);
  sim_icache_fetch(850 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX23); /* line 1778 */
} /* line 1778 */
		 /* line 1779 */
  sim_icache_fetch(852 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1781 */
l_lr_180: ;/* line 1781 */
LABEL(l_lr_180);
  sim_icache_fetch(854 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, ((unsigned int) fy2 + (unsigned int) 58820)); /* line 1783 */
} /* line 1783 */
  sim_icache_fetch(856 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) -11); /* line 1785 */
} /* line 1785 */
l_L51X3: ;/* line 1788 */
LABEL(l_L51X3);
  sim_icache_fetch(857 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_2, mem_trace_ld(reg_r0_57,0,4)); /* line 1789 */
} /* line 1789 */
  sim_icache_fetch(858 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 1791 */
} /* line 1791 */
  sim_icache_fetch(859 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX24); /* line 1793 */
} /* line 1793 */
  sim_icache_fetch(861 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_2, (unsigned int) 8); /* line 1795 */
} /* line 1795 */
  sim_icache_fetch(862 + t_thisfile.offset, 1);
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
} /* line 1797 */
		 /* line 1798 */
  sim_icache_fetch(863 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 1800 */
l_lr_183: ;/* line 1800 */
LABEL(l_lr_183);
  sim_icache_fetch(865 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 4200); /* line 1802 */
} /* line 1802 */
  sim_icache_fetch(867 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 1805 */
} /* line 1805 */
  sim_icache_fetch(868 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L51X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L51X3;
} /* line 1807 */
l_L52X3: ;/* line 1810 */
LABEL(l_L52X3);
  sim_icache_fetch(869 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX25); /* line 1811 */
} /* line 1811 */
		 /* line 1812 */
  sim_icache_fetch(871 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1814 */
l_lr_186: ;/* line 1814 */
LABEL(l_lr_186);
  sim_icache_fetch(873 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_2, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 1816 */
} /* line 1816 */
  sim_icache_fetch(874 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) fy2); /* line 1818 */
} /* line 1818 */
  sim_icache_fetch(876 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, (unsigned int) fy1); /* line 1820 */
} /* line 1820 */
  sim_icache_fetch(878 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_2); /* line 1822 */
} /* line 1822 */
  sim_icache_fetch(879 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_2); /* line 1824 */
} /* line 1824 */
  sim_icache_fetch(880 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, (unsigned int) ft); /* line 1826 */
} /* line 1826 */
  sim_icache_fetch(882 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1828 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 1829 */
   ADD_CYCLES(1);
} /* line 1829 */
  sim_icache_fetch(884 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 1830 */
l_L53X3: ;/* line 1833 */
LABEL(l_L53X3);
  sim_icache_fetch(885 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 1834 */
} /* line 1834 */
  sim_icache_fetch(886 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_11, (unsigned int) 3, reg_r0_9); /* line 1836 */
} /* line 1836 */
  sim_icache_fetch(887 + t_thisfile.offset, 1);
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
} /* line 1838 */
  sim_icache_fetch(888 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_11); /* line 1840 */
} /* line 1840 */
  sim_icache_fetch(889 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_7); /* line 1842 */
} /* line 1842 */
  sim_icache_fetch(890 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_8); /* line 1844 */
} /* line 1844 */
  sim_icache_fetch(891 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_10); /* line 1846 */
} /* line 1846 */
  sim_icache_fetch(892 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, reg_r0_3); /* line 1848 */
} /* line 1848 */
  sim_icache_fetch(893 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_9); /* line 1850 */
} /* line 1850 */
  sim_icache_fetch(894 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_7); /* line 1852 */
} /* line 1852 */
  sim_icache_fetch(895 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_8); /* line 1854 */
} /* line 1854 */
  sim_icache_fetch(896 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_10); /* line 1856 */
} /* line 1856 */
l_L55X3: ;/* line 1859 */
LABEL(l_L55X3);
  sim_icache_fetch(897 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 1860 */
} /* line 1860 */
  sim_icache_fetch(898 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld(reg_r0_4,0,4)); /* line 1862 */
} /* line 1862 */
  sim_icache_fetch(899 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 1864 */
} /* line 1864 */
  sim_icache_fetch(900 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 1866 */
} /* line 1866 */
  sim_icache_fetch(901 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_7); /* line 1868 */
} /* line 1868 */
  sim_icache_fetch(902 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 1870 */
} /* line 1870 */
  sim_icache_fetch(903 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 1872 */
} /* line 1872 */
  sim_icache_fetch(904 + t_thisfile.offset, 1);
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
} /* line 1874 */
  sim_icache_fetch(905 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_7, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 1876 */
} /* line 1876 */
  sim_icache_fetch(906 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 1878 */
} /* line 1878 */
  sim_icache_fetch(907 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 1); /* line 1880 */
} /* line 1880 */
  sim_icache_fetch(908 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 1882 */
} /* line 1882 */
  sim_icache_fetch(909 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, reg_r0_8); /* line 1884 */
} /* line 1884 */
  sim_icache_fetch(910 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 1886 */
} /* line 1886 */
  sim_icache_fetch(911 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_7, reg_r0_7, (unsigned int) 8); /* line 1888 */
} /* line 1888 */
  sim_icache_fetch(912 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 1890 */
} /* line 1890 */
  sim_icache_fetch(913 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_5, 0); /* line 1892 */
} /* line 1892 */
  sim_icache_fetch(914 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 1894 */
} /* line 1894 */
  sim_icache_fetch(915 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_8); /* line 1896 */
} /* line 1896 */
  sim_icache_fetch(916 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1898 */
} /* line 1898 */
  sim_icache_fetch(917 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 1900 */
} /* line 1900 */
  sim_icache_fetch(918 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 1902 */
} /* line 1902 */
  sim_icache_fetch(919 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 1904 */
} /* line 1904 */
  sim_icache_fetch(920 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 1906 */
} /* line 1906 */
  sim_icache_fetch(921 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_8); /* line 1908 */
} /* line 1908 */
  sim_icache_fetch(922 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1910 */
} /* line 1910 */
  sim_icache_fetch(923 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 1912 */
} /* line 1912 */
  sim_icache_fetch(924 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 1914 */
} /* line 1914 */
  sim_icache_fetch(925 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_6,0,4), reg_r0_3); /* line 1916 */
} /* line 1916 */
  sim_icache_fetch(926 + t_thisfile.offset, 1);
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
} /* line 1918 */
  sim_icache_fetch(927 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 4),0,4), reg_r0_7); /* line 1920 */
} /* line 1920 */
  sim_icache_fetch(928 + t_thisfile.offset, 1);
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
} /* line 1922 */
  sim_icache_fetch(929 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 8),0,4), reg_r0_9); /* line 1924 */
} /* line 1924 */
  sim_icache_fetch(930 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L56X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1926 */
  sim_icache_fetch(931 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_6 + (unsigned int) 12),0,4), reg_r0_10); /* line 1928 */
} /* line 1928 */
  sim_icache_fetch(932 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 16); /* line 1931 */
} /* line 1931 */
  sim_icache_fetch(933 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L55X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L55X3;
} /* line 1933 */
l_L56X3: ;/* line 1936 */
LABEL(l_L56X3);
  sim_icache_fetch(934 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, (unsigned int) 4200); /* line 1937 */
} /* line 1937 */
  sim_icache_fetch(936 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_15, reg_r0_2); /* line 1939 */
} /* line 1939 */
  sim_icache_fetch(937 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_14, reg_r0_2); /* line 1941 */
} /* line 1941 */
  sim_icache_fetch(938 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_13, reg_r0_2); /* line 1943 */
} /* line 1943 */
  sim_icache_fetch(939 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_11, (unsigned int) 1); /* line 1945 */
} /* line 1945 */
  sim_icache_fetch(940 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_12); /* line 1948 */
} /* line 1948 */
  sim_icache_fetch(941 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L53X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L53X3;
} /* line 1950 */
l_L54X3: ;/* line 1953 */
LABEL(l_L54X3);
  sim_icache_fetch(942 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 32),0,4), reg_r0_9); /* line 1954 */
} /* line 1954 */
  sim_icache_fetch(943 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX26); /* line 1956 */
} /* line 1956 */
		 /* line 1957 */
  sim_icache_fetch(945 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1959 */
l_lr_192: ;/* line 1959 */
LABEL(l_lr_192);
  sim_icache_fetch(947 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, ((unsigned int) ft + (unsigned int) 58820)); /* line 1961 */
} /* line 1961 */
  sim_icache_fetch(949 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) -11); /* line 1963 */
} /* line 1963 */
l_L57X3: ;/* line 1966 */
LABEL(l_L57X3);
  sim_icache_fetch(950 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_2, mem_trace_ld(reg_r0_57,0,4)); /* line 1967 */
} /* line 1967 */
  sim_icache_fetch(951 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 1969 */
} /* line 1969 */
  sim_icache_fetch(952 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX27); /* line 1971 */
} /* line 1971 */
  sim_icache_fetch(954 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_2, (unsigned int) 8); /* line 1973 */
} /* line 1973 */
  sim_icache_fetch(955 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L58X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 1975 */
		 /* line 1976 */
  sim_icache_fetch(956 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 1978 */
l_lr_195: ;/* line 1978 */
LABEL(l_lr_195);
  sim_icache_fetch(958 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 4200); /* line 1980 */
} /* line 1980 */
  sim_icache_fetch(960 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 1983 */
} /* line 1983 */
  sim_icache_fetch(961 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L57X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L57X3;
} /* line 1985 */
l_L58X3: ;/* line 1988 */
LABEL(l_L58X3);
  sim_icache_fetch(962 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX28); /* line 1989 */
} /* line 1989 */
		 /* line 1990 */
  sim_icache_fetch(964 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 1992 */
l_lr_198: ;/* line 1992 */
LABEL(l_lr_198);
  sim_icache_fetch(966 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_9, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 1994 */
} /* line 1994 */
  sim_icache_fetch(967 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, (unsigned int) ft); /* line 1996 */
} /* line 1996 */
  sim_icache_fetch(969 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, (unsigned int) fy1); /* line 1998 */
} /* line 1998 */
  sim_icache_fetch(971 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_9, 0, reg_r0_9); /* line 2000 */
} /* line 2000 */
  sim_icache_fetch(972 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_9); /* line 2002 */
} /* line 2002 */
  sim_icache_fetch(973 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_10, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 2004 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 2005 */
   ADD_CYCLES(1);
} /* line 2005 */
  sim_icache_fetch(975 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 2006 */
l_L59X3: ;/* line 2009 */
LABEL(l_L59X3);
  sim_icache_fetch(976 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2010 */
} /* line 2010 */
  sim_icache_fetch(977 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_13, (unsigned int) 3, reg_r0_10); /* line 2012 */
} /* line 2012 */
  sim_icache_fetch(978 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L60X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2014 */
  sim_icache_fetch(979 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_13); /* line 2016 */
} /* line 2016 */
  sim_icache_fetch(980 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, reg_r0_11); /* line 2018 */
} /* line 2018 */
  sim_icache_fetch(981 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_12); /* line 2020 */
} /* line 2020 */
  sim_icache_fetch(982 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, 0); /* line 2022 */
} /* line 2022 */
  sim_icache_fetch(983 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 2024 */
} /* line 2024 */
  sim_icache_fetch(984 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 2026 */
} /* line 2026 */
  sim_icache_fetch(985 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_3); /* line 2028 */
} /* line 2028 */
  sim_icache_fetch(986 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_10); /* line 2030 */
} /* line 2030 */
  sim_icache_fetch(987 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_11); /* line 2032 */
} /* line 2032 */
  sim_icache_fetch(988 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_12); /* line 2034 */
} /* line 2034 */
l_L61X3: ;/* line 2037 */
LABEL(l_L61X3);
  sim_icache_fetch(989 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2038 */
} /* line 2038 */
  sim_icache_fetch(990 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2040 */
} /* line 2040 */
  sim_icache_fetch(991 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_5, (unsigned int) 215); /* line 2042 */
} /* line 2042 */
  sim_icache_fetch(992 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_3, (unsigned int) -48); /* line 2044 */
} /* line 2044 */
  sim_icache_fetch(993 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_6, reg_r0_6, (unsigned int) 28); /* line 2046 */
} /* line 2046 */
  sim_icache_fetch(994 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_10); /* line 2048 */
} /* line 2048 */
  sim_icache_fetch(995 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_6); /* line 2050 */
} /* line 2050 */
  sim_icache_fetch(996 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_9); /* line 2052 */
} /* line 2052 */
  sim_icache_fetch(997 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2054 */
} /* line 2054 */
  sim_icache_fetch(998 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 3); /* line 2056 */
} /* line 2056 */
  sim_icache_fetch(999 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_7, (unsigned int) 2); /* line 2058 */
} /* line 2058 */
  sim_icache_fetch(1000 + t_thisfile.offset, 1);
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
} /* line 2060 */
  sim_icache_fetch(1001 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 4200),0,4)); /* line 2062 */
} /* line 2062 */
  sim_icache_fetch(1003 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) -155); /* line 2064 */
} /* line 2064 */
  sim_icache_fetch(1004 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 2066 */
} /* line 2066 */
  sim_icache_fetch(1005 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_9, (unsigned int) -48); /* line 2068 */
} /* line 2068 */
  sim_icache_fetch(1006 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2070 */
} /* line 2070 */
  sim_icache_fetch(1007 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_11); /* line 2072 */
} /* line 2072 */
  sim_icache_fetch(1008 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_3); /* line 2074 */
} /* line 2074 */
  sim_icache_fetch(1009 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, reg_r0_10); /* line 2076 */
} /* line 2076 */
  sim_icache_fetch(1010 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_5, reg_r0_5, (unsigned int) 8); /* line 2078 */
} /* line 2078 */
  sim_icache_fetch(1011 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_7, (unsigned int) 1); /* line 2080 */
} /* line 2080 */
  sim_icache_fetch(1012 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld((reg_r0_2 + (unsigned int) 8400),0,4)); /* line 2082 */
} /* line 2082 */
  sim_icache_fetch(1014 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) -155); /* line 2084 */
} /* line 2084 */
  sim_icache_fetch(1015 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_5, (unsigned int) 215); /* line 2086 */
} /* line 2086 */
  sim_icache_fetch(1016 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_3, (unsigned int) -48); /* line 2088 */
} /* line 2088 */
  sim_icache_fetch(1017 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 28); /* line 2090 */
} /* line 2090 */
  sim_icache_fetch(1018 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_12); /* line 2092 */
} /* line 2092 */
  sim_icache_fetch(1019 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_9); /* line 2094 */
} /* line 2094 */
  sim_icache_fetch(1020 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 2096 */
} /* line 2096 */
  sim_icache_fetch(1021 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2098 */
} /* line 2098 */
  sim_icache_fetch(1022 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_7, 0); /* line 2100 */
} /* line 2100 */
  sim_icache_fetch(1023 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_6, mem_trace_ld((reg_r0_2 + (unsigned int) 12600),0,4)); /* line 2102 */
} /* line 2102 */
  sim_icache_fetch(1025 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_5, (unsigned int) -155); /* line 2104 */
} /* line 2104 */
  sim_icache_fetch(1026 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_10, (unsigned int) 215); /* line 2106 */
} /* line 2106 */
  sim_icache_fetch(1027 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_6, (unsigned int) -48); /* line 2108 */
} /* line 2108 */
  sim_icache_fetch(1028 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 28); /* line 2110 */
} /* line 2110 */
  sim_icache_fetch(1029 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_12); /* line 2112 */
} /* line 2112 */
  sim_icache_fetch(1030 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 2114 */
} /* line 2114 */
  sim_icache_fetch(1031 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_11); /* line 2116 */
} /* line 2116 */
  sim_icache_fetch(1032 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2118 */
} /* line 2118 */
  sim_icache_fetch(1033 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_8,0,4), reg_r0_4); /* line 2120 */
} /* line 2120 */
  sim_icache_fetch(1034 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_1) {    BRANCHF(reg_b0_1);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2122 */
  sim_icache_fetch(1035 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_10); /* line 2124 */
} /* line 2124 */
  sim_icache_fetch(1036 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16800); /* line 2126 */
} /* line 2126 */
  sim_icache_fetch(1038 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 2128 */
} /* line 2128 */
  sim_icache_fetch(1039 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 4200),0,4), reg_r0_5); /* line 2130 */
} /* line 2130 */
  sim_icache_fetch(1041 + t_thisfile.offset, 1);
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
} /* line 2132 */
  sim_icache_fetch(1042 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_9); /* line 2134 */
} /* line 2134 */
  sim_icache_fetch(1043 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 8400),0,4), reg_r0_10); /* line 2136 */
} /* line 2136 */
  sim_icache_fetch(1045 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_2) {    BRANCHF(reg_b0_2);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L62X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2138 */
  sim_icache_fetch(1046 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_8 + (unsigned int) 12600),0,4), reg_r0_9); /* line 2140 */
} /* line 2140 */
  sim_icache_fetch(1048 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) 16800); /* line 2143 */
} /* line 2143 */
  sim_icache_fetch(1050 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L61X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L61X3;
} /* line 2145 */
l_L62X3: ;/* line 2148 */
LABEL(l_L62X3);
  sim_icache_fetch(1051 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_16, (unsigned int) 4); /* line 2149 */
} /* line 2149 */
  sim_icache_fetch(1052 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_15, (unsigned int) 4); /* line 2151 */
} /* line 2151 */
  sim_icache_fetch(1053 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 2153 */
} /* line 2153 */
  sim_icache_fetch(1054 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, reg_r0_14); /* line 2156 */
} /* line 2156 */
  sim_icache_fetch(1055 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L59X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L59X3;
} /* line 2158 */
l_L60X3: ;/* line 2161 */
LABEL(l_L60X3);
  sim_icache_fetch(1056 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 36),0,4), reg_r0_59); /* line 2162 */
} /* line 2162 */
  sim_icache_fetch(1057 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 40),0,4), reg_r0_60); /* line 2164 */
} /* line 2164 */
  sim_icache_fetch(1058 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_1 + (unsigned int) 28),0,4), reg_r0_10); /* line 2166 */
} /* line 2166 */
  sim_icache_fetch(1059 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX29); /* line 2168 */
} /* line 2168 */
		 /* line 2169 */
  sim_icache_fetch(1061 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 2171 */
l_lr_204: ;/* line 2171 */
LABEL(l_lr_204);
  sim_icache_fetch(1063 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, ((unsigned int) fy1 + (unsigned int) 58820)); /* line 2173 */
} /* line 2173 */
  sim_icache_fetch(1065 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) -11); /* line 2175 */
} /* line 2175 */
  sim_icache_fetch(1066 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 28),0,4)); /* line 2177 */
} /* line 2177 */
  sim_icache_fetch(1067 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 32),0,4)); /* line 2179 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 2180 */
   ADD_CYCLES(1);
} /* line 2180 */
  sim_icache_fetch(1069 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 2181 */
l_L63X3: ;/* line 2184 */
LABEL(l_L63X3);
  sim_icache_fetch(1070 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_2, mem_trace_ld(reg_r0_57,0,4)); /* line 2185 */
} /* line 2185 */
  sim_icache_fetch(1071 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 2187 */
} /* line 2187 */
  sim_icache_fetch(1072 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX30); /* line 2189 */
} /* line 2189 */
  sim_icache_fetch(1074 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_2, (unsigned int) 8); /* line 2191 */
} /* line 2191 */
  sim_icache_fetch(1075 + t_thisfile.offset, 1);
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
} /* line 2193 */
		 /* line 2194 */
  sim_icache_fetch(1076 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 2196 */
l_lr_207: ;/* line 2196 */
LABEL(l_lr_207);
  sim_icache_fetch(1078 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 4200); /* line 2198 */
} /* line 2198 */
  sim_icache_fetch(1080 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 2201 */
} /* line 2201 */
  sim_icache_fetch(1081 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L63X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L63X3;
} /* line 2203 */
l_L64X3: ;/* line 2206 */
LABEL(l_L64X3);
  sim_icache_fetch(1082 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX31); /* line 2207 */
} /* line 2207 */
		 /* line 2208 */
  sim_icache_fetch(1084 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 2210 */
l_lr_210: ;/* line 2210 */
LABEL(l_lr_210);
  sim_icache_fetch(1086 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_2, 0, reg_r0_59); /* line 2212 */
} /* line 2212 */
  sim_icache_fetch(1087 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, reg_r0_2); /* line 2214 */
} /* line 2214 */
  sim_icache_fetch(1088 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, ((unsigned int) fy2 + (unsigned int) -12600)); /* line 2216 */
} /* line 2216 */
  sim_icache_fetch(1090 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, ((unsigned int) ft + (unsigned int) -12600)); /* line 2218 */
} /* line 2218 */
  sim_icache_fetch(1092 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_12, reg_r0_60, (unsigned int) -1); /* line 2220 */
} /* line 2220 */
l_L65X3: ;/* line 2223 */
LABEL(l_L65X3);
  sim_icache_fetch(1093 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_11, 0); /* line 2224 */
} /* line 2224 */
  sim_icache_fetch(1094 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULLU(reg_r0_15, reg_r0_12, (unsigned int) 4200); /* line 2226 */
} /* line 2226 */
  sim_icache_fetch(1096 + t_thisfile.offset, 1);
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
} /* line 2228 */
  sim_icache_fetch(1097 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_13, reg_r0_15); /* line 2230 */
} /* line 2230 */
  sim_icache_fetch(1098 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_14, reg_r0_15); /* line 2232 */
} /* line 2232 */
  sim_icache_fetch(1099 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, 0); /* line 2234 */
} /* line 2234 */
  sim_icache_fetch(1100 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, 0); /* line 2236 */
} /* line 2236 */
  sim_icache_fetch(1101 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, 0); /* line 2238 */
} /* line 2238 */
  sim_icache_fetch(1102 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, 0); /* line 2240 */
} /* line 2240 */
  sim_icache_fetch(1103 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_12); /* line 2242 */
} /* line 2242 */
  sim_icache_fetch(1104 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_11); /* line 2244 */
} /* line 2244 */
  sim_icache_fetch(1105 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_12); /* line 2246 */
} /* line 2246 */
  sim_icache_fetch(1106 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_13); /* line 2248 */
} /* line 2248 */
  sim_icache_fetch(1107 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_18, reg_r0_14); /* line 2250 */
} /* line 2250 */
l_L67X3: ;/* line 2253 */
LABEL(l_L67X3);
  sim_icache_fetch(1108 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_2, reg_r0_2, (unsigned int) -155); /* line 2254 */
} /* line 2254 */
  sim_icache_fetch(1109 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_3, (unsigned int) -47); /* line 2256 */
} /* line 2256 */
  sim_icache_fetch(1110 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_4, (unsigned int) 215); /* line 2258 */
} /* line 2258 */
  sim_icache_fetch(1111 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_9); /* line 2260 */
} /* line 2260 */
  sim_icache_fetch(1112 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_5, reg_r0_5, (unsigned int) 29); /* line 2262 */
} /* line 2262 */
  sim_icache_fetch(1113 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, 0); /* line 2264 */
} /* line 2264 */
  sim_icache_fetch(1114 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_5); /* line 2266 */
} /* line 2266 */
  sim_icache_fetch(1115 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, reg_r0_10); /* line 2268 */
} /* line 2268 */
  sim_icache_fetch(1116 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_2, reg_r0_2, (unsigned int) 8); /* line 2270 */
} /* line 2270 */
  sim_icache_fetch(1117 + t_thisfile.offset, 1);
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
} /* line 2272 */
  sim_icache_fetch(1118 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_9, mem_trace_ld((reg_r0_8 + (unsigned int) 12600),0,4)); /* line 2274 */
} /* line 2274 */
  sim_icache_fetch(1120 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_0, reg_r0_6, (unsigned int) 1); /* line 2276 */
} /* line 2276 */
  sim_icache_fetch(1121 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_4, reg_r0_4, (unsigned int) -155); /* line 2278 */
} /* line 2278 */
  sim_icache_fetch(1122 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_9, (unsigned int) -47); /* line 2280 */
} /* line 2280 */
  sim_icache_fetch(1123 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) 215); /* line 2282 */
} /* line 2282 */
  sim_icache_fetch(1124 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_10); /* line 2284 */
} /* line 2284 */
  sim_icache_fetch(1125 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_3, reg_r0_3, (unsigned int) 29); /* line 2286 */
} /* line 2286 */
  sim_icache_fetch(1126 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_8 + (unsigned int) 8400),0,4)); /* line 2288 */
} /* line 2288 */
  sim_icache_fetch(1128 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_3); /* line 2290 */
} /* line 2290 */
  sim_icache_fetch(1129 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, reg_r0_11); /* line 2292 */
} /* line 2292 */
  sim_icache_fetch(1130 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_4, (unsigned int) 8); /* line 2294 */
} /* line 2294 */
  sim_icache_fetch(1131 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_1, reg_r0_6, (unsigned int) 2); /* line 2296 */
} /* line 2296 */
  sim_icache_fetch(1132 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_11, reg_r0_2, (unsigned int) -155); /* line 2298 */
} /* line 2298 */
  sim_icache_fetch(1133 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_12, reg_r0_10, (unsigned int) -47); /* line 2300 */
} /* line 2300 */
  sim_icache_fetch(1134 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_4, (unsigned int) 215); /* line 2302 */
} /* line 2302 */
  sim_icache_fetch(1135 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_12); /* line 2304 */
} /* line 2304 */
  sim_icache_fetch(1136 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_9, (unsigned int) 29); /* line 2306 */
} /* line 2306 */
  sim_icache_fetch(1137 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_8 + (unsigned int) 4200),0,4)); /* line 2308 */
} /* line 2308 */
  sim_icache_fetch(1139 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_13, reg_r0_9); /* line 2310 */
} /* line 2310 */
  sim_icache_fetch(1140 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_11, reg_r0_13); /* line 2312 */
} /* line 2312 */
  sim_icache_fetch(1141 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_11, reg_r0_11, (unsigned int) 8); /* line 2314 */
} /* line 2314 */
  sim_icache_fetch(1142 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGE(reg_b0_2, reg_r0_6, (unsigned int) 3); /* line 2316 */
} /* line 2316 */
  sim_icache_fetch(1143 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_9, reg_r0_4, (unsigned int) -155); /* line 2318 */
} /* line 2318 */
  sim_icache_fetch(1144 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_13, reg_r0_12, (unsigned int) -47); /* line 2320 */
} /* line 2320 */
  sim_icache_fetch(1145 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_14, reg_r0_11, (unsigned int) 215); /* line 2322 */
} /* line 2322 */
  sim_icache_fetch(1146 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_13); /* line 2324 */
} /* line 2324 */
  sim_icache_fetch(1147 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MULL(reg_r0_10, reg_r0_10, (unsigned int) 29); /* line 2326 */
} /* line 2326 */
  sim_icache_fetch(1148 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_8,0,4)); /* line 2328 */
} /* line 2328 */
  sim_icache_fetch(1149 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_14, reg_r0_10); /* line 2330 */
} /* line 2330 */
  sim_icache_fetch(1150 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_14); /* line 2332 */
} /* line 2332 */
  sim_icache_fetch(1151 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2334 */
} /* line 2334 */
  sim_icache_fetch(1152 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_12); /* line 2336 */
} /* line 2336 */
  sim_icache_fetch(1153 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 12600),0,4), reg_r0_2); /* line 2338 */
} /* line 2338 */
  sim_icache_fetch(1155 + t_thisfile.offset, 1);
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
} /* line 2340 */
  sim_icache_fetch(1156 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_11); /* line 2342 */
} /* line 2342 */
  sim_icache_fetch(1157 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) -4); /* line 2344 */
} /* line 2344 */
  sim_icache_fetch(1158 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, (unsigned int) -16800); /* line 2346 */
} /* line 2346 */
  sim_icache_fetch(1160 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 8400),0,4), reg_r0_4); /* line 2348 */
} /* line 2348 */
  sim_icache_fetch(1162 + t_thisfile.offset, 1);
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
} /* line 2350 */
  sim_icache_fetch(1163 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_9); /* line 2352 */
} /* line 2352 */
  sim_icache_fetch(1164 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st((reg_r0_7 + (unsigned int) 4200),0,4), reg_r0_11); /* line 2354 */
} /* line 2354 */
  sim_icache_fetch(1166 + t_thisfile.offset, 1);
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
} /* line 2356 */
  sim_icache_fetch(1167 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STW(mem_trace_st(reg_r0_7,0,4), reg_r0_9); /* line 2358 */
} /* line 2358 */
  sim_icache_fetch(1168 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) -16800); /* line 2361 */
} /* line 2361 */
  sim_icache_fetch(1170 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L67X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L67X3;
} /* line 2363 */
l_L68X3: ;/* line 2366 */
LABEL(l_L68X3);
  sim_icache_fetch(1171 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_14, reg_r0_18, (unsigned int) 4); /* line 2367 */
} /* line 2367 */
  sim_icache_fetch(1172 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_13, reg_r0_17, (unsigned int) 4); /* line 2369 */
} /* line 2369 */
  sim_icache_fetch(1173 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_15, (unsigned int) 1); /* line 2371 */
} /* line 2371 */
  sim_icache_fetch(1174 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_12, reg_r0_16); /* line 2374 */
} /* line 2374 */
  sim_icache_fetch(1175 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L65X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L65X3;
} /* line 2376 */
l_L66X3: ;/* line 2379 */
LABEL(l_L66X3);
  sim_icache_fetch(1176 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX32); /* line 2380 */
} /* line 2380 */
		 /* line 2381 */
  sim_icache_fetch(1178 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 2383 */
l_lr_216: ;/* line 2383 */
LABEL(l_lr_216);
  sim_icache_fetch(1180 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, ((unsigned int) fy2 + (unsigned int) 58820)); /* line 2385 */
} /* line 2385 */
  sim_icache_fetch(1182 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) -11); /* line 2387 */
} /* line 2387 */
l_L69X3: ;/* line 2390 */
LABEL(l_L69X3);
  sim_icache_fetch(1183 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_2, mem_trace_ld(reg_r0_57,0,4)); /* line 2391 */
} /* line 2391 */
  sim_icache_fetch(1184 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 2393 */
} /* line 2393 */
  sim_icache_fetch(1185 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX33); /* line 2395 */
} /* line 2395 */
  sim_icache_fetch(1187 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_4, reg_r0_2, (unsigned int) 8); /* line 2397 */
} /* line 2397 */
  sim_icache_fetch(1188 + t_thisfile.offset, 1);
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
} /* line 2399 */
		 /* line 2400 */
  sim_icache_fetch(1189 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 2402 */
l_lr_219: ;/* line 2402 */
LABEL(l_lr_219);
  sim_icache_fetch(1191 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 4200); /* line 2404 */
} /* line 2404 */
  sim_icache_fetch(1193 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 2407 */
} /* line 2407 */
  sim_icache_fetch(1194 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L69X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L69X3;
} /* line 2409 */
l_L70X3: ;/* line 2412 */
LABEL(l_L70X3);
  sim_icache_fetch(1195 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX34); /* line 2413 */
} /* line 2413 */
		 /* line 2414 */
  sim_icache_fetch(1197 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 2416 */
l_lr_222: ;/* line 2416 */
LABEL(l_lr_222);
  sim_icache_fetch(1199 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_60, 0, reg_r0_60); /* line 2418 */
} /* line 2418 */
  sim_icache_fetch(1200 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, reg_r0_60); /* line 2420 */
} /* line 2420 */
  sim_icache_fetch(1201 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_11, (unsigned int) fy2); /* line 2422 */
} /* line 2422 */
  sim_icache_fetch(1203 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_10, (unsigned int) fy1); /* line 2424 */
} /* line 2424 */
  sim_icache_fetch(1205 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_8, (unsigned int) out); /* line 2426 */
} /* line 2426 */
  sim_icache_fetch(1207 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_59); /* line 2428 */
} /* line 2428 */
l_L71X3: ;/* line 2431 */
LABEL(l_L71X3);
  sim_icache_fetch(1208 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_3, 0); /* line 2432 */
} /* line 2432 */
  sim_icache_fetch(1209 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SUB(reg_r0_12, (unsigned int) 3, reg_r0_9); /* line 2434 */
} /* line 2434 */
  sim_icache_fetch(1210 + t_thisfile.offset, 1);
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
} /* line 2436 */
  sim_icache_fetch(1211 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_5, reg_r0_12); /* line 2438 */
} /* line 2438 */
  sim_icache_fetch(1212 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_7, reg_r0_8); /* line 2440 */
} /* line 2440 */
  sim_icache_fetch(1213 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_6, reg_r0_8); /* line 2442 */
} /* line 2442 */
  sim_icache_fetch(1214 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_4, reg_r0_10); /* line 2444 */
} /* line 2444 */
  sim_icache_fetch(1215 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_2, reg_r0_11); /* line 2446 */
} /* line 2446 */
  sim_icache_fetch(1216 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_13, reg_r0_3); /* line 2448 */
} /* line 2448 */
  sim_icache_fetch(1217 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_14, reg_r0_9); /* line 2450 */
} /* line 2450 */
  sim_icache_fetch(1218 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_15, reg_r0_8); /* line 2452 */
} /* line 2452 */
  sim_icache_fetch(1219 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_16, reg_r0_10); /* line 2454 */
} /* line 2454 */
  sim_icache_fetch(1220 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_17, reg_r0_11); /* line 2456 */
} /* line 2456 */
l_L73X3: ;/* line 2459 */
LABEL(l_L73X3);
  sim_icache_fetch(1221 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_3, mem_trace_ld(reg_r0_2,0,4)); /* line 2460 */
} /* line 2460 */
  sim_icache_fetch(1222 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld(reg_r0_4,0,4)); /* line 2462 */
} /* line 2462 */
  sim_icache_fetch(1223 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_5, (unsigned int) 3); /* line 2464 */
} /* line 2464 */
  sim_icache_fetch(1224 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_1, reg_r0_5, (unsigned int) 2); /* line 2466 */
} /* line 2466 */
  sim_icache_fetch(1225 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_3, reg_r0_8); /* line 2468 */
} /* line 2468 */
  sim_icache_fetch(1226 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_3, reg_r0_3, (unsigned int) 8); /* line 2470 */
} /* line 2470 */
  sim_icache_fetch(1227 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_3, reg_r0_3, (unsigned int) 16); /* line 2472 */
} /* line 2472 */
  sim_icache_fetch(1228 + t_thisfile.offset, 1);
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
} /* line 2474 */
  sim_icache_fetch(1229 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_8, reg_r0_3); /* line 2476 */
} /* line 2476 */
  sim_icache_fetch(1230 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_8, (unsigned int) 125); /* line 2478 */
} /* line 2478 */
  sim_icache_fetch(1231 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_9, mem_trace_ld((reg_r0_2 + (unsigned int) 4),0,4)); /* line 2480 */
} /* line 2480 */
  sim_icache_fetch(1232 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_4 + (unsigned int) 4),0,4)); /* line 2482 */
} /* line 2482 */
  sim_icache_fetch(1233 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_2, reg_r0_5, (unsigned int) 1); /* line 2484 */
} /* line 2484 */
  sim_icache_fetch(1234 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_10, mem_trace_ld((reg_r0_2 + (unsigned int) 8),0,4)); /* line 2486 */
} /* line 2486 */
  sim_icache_fetch(1235 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_9, reg_r0_9, reg_r0_8); /* line 2488 */
} /* line 2488 */
  sim_icache_fetch(1236 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_9, reg_r0_9, (unsigned int) 8); /* line 2490 */
} /* line 2490 */
  sim_icache_fetch(1237 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_9, reg_r0_9, (unsigned int) 16); /* line 2492 */
} /* line 2492 */
  sim_icache_fetch(1238 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_8, reg_r0_9); /* line 2494 */
} /* line 2494 */
  sim_icache_fetch(1239 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_3, reg_r0_8, (unsigned int) 125); /* line 2496 */
} /* line 2496 */
  sim_icache_fetch(1240 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_11, mem_trace_ld((reg_r0_4 + (unsigned int) 8),0,4)); /* line 2498 */
} /* line 2498 */
  sim_icache_fetch(1241 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_4, reg_r0_5, 0); /* line 2500 */
} /* line 2500 */
  sim_icache_fetch(1242 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_8, mem_trace_ld((reg_r0_2 + (unsigned int) 12),0,4)); /* line 2502 */
} /* line 2502 */
  sim_icache_fetch(1243 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_10, reg_r0_11); /* line 2504 */
} /* line 2504 */
  sim_icache_fetch(1244 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_10, reg_r0_10, (unsigned int) 8); /* line 2506 */
} /* line 2506 */
  sim_icache_fetch(1245 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_10, reg_r0_10, (unsigned int) 16); /* line 2508 */
} /* line 2508 */
  sim_icache_fetch(1246 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_11, reg_r0_10); /* line 2510 */
} /* line 2510 */
  sim_icache_fetch(1247 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_5, reg_r0_11, (unsigned int) 125); /* line 2512 */
} /* line 2512 */
  sim_icache_fetch(1248 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDWs(reg_r0_12, mem_trace_ld((reg_r0_4 + (unsigned int) 12),0,4)); /* line 2514 */
} /* line 2514 */
  sim_icache_fetch(1249 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_6,0,1), reg_r0_3); /* line 2516 */
} /* line 2516 */
  sim_icache_fetch(1250 + t_thisfile.offset, 1);
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
} /* line 2518 */
  sim_icache_fetch(1251 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, reg_r0_12); /* line 2520 */
} /* line 2520 */
  sim_icache_fetch(1252 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 2522 */
} /* line 2522 */
  sim_icache_fetch(1253 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 2524 */
} /* line 2524 */
  sim_icache_fetch(1254 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_3, reg_r0_8); /* line 2526 */
} /* line 2526 */
  sim_icache_fetch(1255 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_3, (unsigned int) 125); /* line 2528 */
} /* line 2528 */
  sim_icache_fetch(1256 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_6,0,1), 0); /* line 2530 */
} /* line 2530 */
l_L76X3: ;/* line 2532 */
LABEL(l_L76X3);
  sim_icache_fetch(1257 + t_thisfile.offset, 1);
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
} /* line 2533 */
  sim_icache_fetch(1258 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), reg_r0_9); /* line 2535 */
} /* line 2535 */
  sim_icache_fetch(1259 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_3) {    BRANCHF(reg_b0_3);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L77X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2537 */
  sim_icache_fetch(1260 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 1),0,1), 0); /* line 2539 */
} /* line 2539 */
l_L78X3: ;/* line 2541 */
LABEL(l_L78X3);
  sim_icache_fetch(1261 + t_thisfile.offset, 1);
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
} /* line 2542 */
  sim_icache_fetch(1262 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), reg_r0_10); /* line 2544 */
} /* line 2544 */
  sim_icache_fetch(1263 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_5) {    BRANCHF(reg_b0_5);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L79X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2546 */
  sim_icache_fetch(1264 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 2),0,1), 0); /* line 2548 */
} /* line 2548 */
l_L80X3: ;/* line 2550 */
LABEL(l_L80X3);
  sim_icache_fetch(1265 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_4) {    BRANCHF(reg_b0_4);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L74X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2551 */
  sim_icache_fetch(1266 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), reg_r0_8); /* line 2553 */
} /* line 2553 */
  sim_icache_fetch(1267 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   if (!reg_b0_0) {    BRANCHF(reg_b0_0);
      INC_BTC_CNT();
      INC_STALL_CNT();
      goto l_L81X3; 
   } else {
      INC_BNT_CNT();
   }
} /* line 2555 */
  sim_icache_fetch(1268 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 2557 */
} /* line 2557 */
  sim_icache_fetch(1269 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 2559 */
} /* line 2559 */
  sim_icache_fetch(1270 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 2561 */
} /* line 2561 */
  sim_icache_fetch(1271 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2563 */
} /* line 2563 */
  sim_icache_fetch(1272 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_6 + (unsigned int) 3),0,1), 0); /* line 2565 */
} /* line 2565 */
l_L82X3: ;/* line 2567 */
LABEL(l_L82X3);
  sim_icache_fetch(1273 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_6, reg_r0_6, (unsigned int) 4); /* line 2569 */
} /* line 2569 */
  sim_icache_fetch(1274 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L73X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L73X3;
} /* line 2571 */
l_L81X3: ;/* line 2574 */
LABEL(l_L81X3);
  sim_icache_fetch(1275 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 2575 */
} /* line 2575 */
  sim_icache_fetch(1276 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_5, reg_r0_5, (unsigned int) 4); /* line 2577 */
} /* line 2577 */
  sim_icache_fetch(1277 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_4, reg_r0_4, (unsigned int) 16); /* line 2579 */
} /* line 2579 */
  sim_icache_fetch(1278 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_2, reg_r0_2, (unsigned int) 16); /* line 2581 */
} /* line 2581 */
  sim_icache_fetch(1279 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 3),0,1), reg_r0_3); /* line 2583 */
} /* line 2583 */
  sim_icache_fetch(1280 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_7, reg_r0_7, (unsigned int) 4); /* line 2586 */
} /* line 2586 */
  sim_icache_fetch(1281 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L82X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L82X3;
} /* line 2588 */
l_L74X3: ;/* line 2591 */
LABEL(l_L74X3);
  sim_icache_fetch(1282 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_11, reg_r0_17, (unsigned int) 4200); /* line 2592 */
} /* line 2592 */
  sim_icache_fetch(1284 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_10, reg_r0_16, (unsigned int) 4200); /* line 2594 */
} /* line 2594 */
  sim_icache_fetch(1286 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_15, (unsigned int) 1050); /* line 2596 */
} /* line 2596 */
  sim_icache_fetch(1288 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_3, reg_r0_13, (unsigned int) 1); /* line 2598 */
} /* line 2598 */
  sim_icache_fetch(1289 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_9, reg_r0_14); /* line 2601 */
} /* line 2601 */
  sim_icache_fetch(1290 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L71X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L71X3;
} /* line 2603 */
l_L79X3: ;/* line 2606 */
LABEL(l_L79X3);
  sim_icache_fetch(1291 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 2607 */
} /* line 2607 */
  sim_icache_fetch(1292 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 2),0,1), reg_r0_3); /* line 2610 */
} /* line 2610 */
  sim_icache_fetch(1293 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L80X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L80X3;
} /* line 2612 */
l_L77X3: ;/* line 2615 */
LABEL(l_L77X3);
  sim_icache_fetch(1294 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 2616 */
} /* line 2616 */
  sim_icache_fetch(1295 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st((reg_r0_7 + (unsigned int) 1),0,1), reg_r0_3); /* line 2619 */
} /* line 2619 */
  sim_icache_fetch(1296 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L78X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L78X3;
} /* line 2621 */
l_L75X3: ;/* line 2624 */
LABEL(l_L75X3);
  sim_icache_fetch(1297 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) 255); /* line 2625 */
} /* line 2625 */
  sim_icache_fetch(1298 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_8, reg_r0_8, reg_r0_12); /* line 2627 */
} /* line 2627 */
  sim_icache_fetch(1299 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHL(reg_r0_8, reg_r0_8, (unsigned int) 8); /* line 2629 */
} /* line 2629 */
  sim_icache_fetch(1300 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   SHR(reg_r0_8, reg_r0_8, (unsigned int) 16); /* line 2631 */
} /* line 2631 */
  sim_icache_fetch(1301 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ZXTB(reg_r0_11, reg_r0_8); /* line 2633 */
} /* line 2633 */
  sim_icache_fetch(1302 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPGT(reg_b0_0, reg_r0_11, (unsigned int) 125); /* line 2635 */
} /* line 2635 */
  sim_icache_fetch(1303 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   STB(mem_trace_st(reg_r0_7,0,1), reg_r0_3); /* line 2638 */
} /* line 2638 */
  sim_icache_fetch(1304 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L76X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L76X3;
} /* line 2640 */
l_L72X3: ;/* line 2643 */
LABEL(l_L72X3);
  sim_icache_fetch(1305 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX35); /* line 2644 */
} /* line 2644 */
		 /* line 2645 */
  sim_icache_fetch(1307 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 2647 */
l_lr_236: ;/* line 2647 */
LABEL(l_lr_236);
  sim_icache_fetch(1309 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_57, ((unsigned int) out + (unsigned int) 14705)); /* line 2649 */
} /* line 2649 */
  sim_icache_fetch(1311 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_58, (unsigned int) -11); /* line 2651 */
} /* line 2651 */
  sim_icache_fetch(1312 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_59, mem_trace_ld((reg_r0_1 + (unsigned int) 36),0,4)); /* line 2653 */
} /* line 2653 */
  sim_icache_fetch(1313 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_60, mem_trace_ld((reg_r0_1 + (unsigned int) 40),0,4)); /* line 2655 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 2656 */
   ADD_CYCLES(1);
} /* line 2656 */
  sim_icache_fetch(1315 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(0);
} /* line 2657 */
l_L83X3: ;/* line 2660 */
LABEL(l_L83X3);
  sim_icache_fetch(1316 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDBUs(reg_r0_4, mem_trace_ld(reg_r0_57,0,1)); /* line 2661 */
} /* line 2661 */
  sim_icache_fetch(1317 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   CMPLT(reg_b0_0, reg_r0_58, 0); /* line 2663 */
} /* line 2663 */
  sim_icache_fetch(1318 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX36); /* line 2665 */
} /* line 2665 */
  sim_icache_fetch(1320 + t_thisfile.offset, 1);
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
} /* line 2667 */
		 /* line 2668 */
  sim_icache_fetch(1321 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int, unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3, reg_r0_4);
   }
} /* line 2670 */
l_lr_239: ;/* line 2670 */
LABEL(l_lr_239);
  sim_icache_fetch(1323 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_57, reg_r0_57, (unsigned int) 1050); /* line 2672 */
} /* line 2672 */
  sim_icache_fetch(1325 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   ADD(reg_r0_58, reg_r0_58, (unsigned int) 1); /* line 2675 */
} /* line 2675 */
  sim_icache_fetch(1326 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   GOTO(l_L83X3);   INC_BTU_CNT();
   INC_STALL_CNT();
   goto l_L83X3;
} /* line 2677 */
l_L84X3: ;/* line 2680 */
LABEL(l_L84X3);
  sim_icache_fetch(1327 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   MOV(reg_r0_3, (unsigned int) _X1STRINGPACKETX37); /* line 2681 */
} /* line 2681 */
		 /* line 2682 */
  sim_icache_fetch(1329 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   INC_BTU_CNT();
   INC_STALL_CNT();
   CALL(printf);
   reg_l0_0 = (344 << 5);
   {
    typedef unsigned int t_FT (unsigned int);
    t_FT *t_call = (t_FT*) printf;
    reg_r0_3 =     (*t_call)(reg_r0_3);
   }
} /* line 2684 */
l_lr_242: ;/* line 2684 */
LABEL(l_lr_242);
  sim_icache_fetch(1331 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_l0_0, mem_trace_ld((reg_r0_1 + (unsigned int) 16),0,4)); /* line 2686 */
   INC_NOP_CNT((unsigned int) 3);
   XNOP((unsigned int) 3); /* line 2687 */
   ADD_CYCLES(3);
} /* line 2687 */
  sim_icache_fetch(1333 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_57, mem_trace_ld((reg_r0_1 + (unsigned int) 20),0,4)); /* line 2689 */
} /* line 2689 */
  sim_icache_fetch(1334 + t_thisfile.offset, 2);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   LDW(reg_r0_58, mem_trace_ld((reg_r0_1 + (unsigned int) 24),0,4)); /* line 2691 */
   INC_NOP_CNT((unsigned int) 1);
   XNOP((unsigned int) 1); /* line 2692 */
   ADD_CYCLES(1);
} /* line 2692 */
  sim_icache_fetch(1336 + t_thisfile.offset, 1);
{
   ADD_CYCLES(1);
   INC_BUNDLE_CNT(1);
   RETURN(deriche_slow);   INC_BTU_CNT();
   INC_STALL_CNT();
   reg_r0_1 = reg_r0_1 + (unsigned int) 64; /* pop frame */
   t_labelnum = reg_l0_0;
   goto labelfinder;
} /* line 2695 */
  reg_l0_0 = t_client_rpc;
  return;

labelfinder:
  switch (t_labelnum >> 5) {
    case 260: goto l_L37X3;
    case 261: goto l_L39X3;
    case 262: goto l_L40X3;
    case 263: goto l_L38X3;
    case 265: goto l_lr_164;
    case 266: goto l_L41X3;
    case 268: goto l_lr_167;
    case 269: goto l_L42X3;
    case 271: goto l_lr_170;
    case 272: goto l_L43X3;
    case 273: goto l_L45X3;
    case 274: goto l_L49X3;
    case 275: goto l_L48X3;
    case 276: goto l_L47X3;
    case 277: goto l_L46X3;
    case 278: goto l_L50X3;
    case 279: goto l_L44X3;
    case 281: goto l_lr_180;
    case 282: goto l_L51X3;
    case 284: goto l_lr_183;
    case 285: goto l_L52X3;
    case 287: goto l_lr_186;
    case 288: goto l_L53X3;
    case 289: goto l_L55X3;
    case 290: goto l_L56X3;
    case 291: goto l_L54X3;
    case 293: goto l_lr_192;
    case 294: goto l_L57X3;
    case 296: goto l_lr_195;
    case 297: goto l_L58X3;
    case 299: goto l_lr_198;
    case 300: goto l_L59X3;
    case 301: goto l_L61X3;
    case 302: goto l_L62X3;
    case 303: goto l_L60X3;
    case 305: goto l_lr_204;
    case 306: goto l_L63X3;
    case 308: goto l_lr_207;
    case 309: goto l_L64X3;
    case 311: goto l_lr_210;
    case 312: goto l_L65X3;
    case 313: goto l_L67X3;
    case 314: goto l_L68X3;
    case 315: goto l_L66X3;
    case 317: goto l_lr_216;
    case 318: goto l_L69X3;
    case 320: goto l_lr_219;
    case 321: goto l_L70X3;
    case 323: goto l_lr_222;
    case 324: goto l_L71X3;
    case 325: goto l_L73X3;
    case 326: goto l_L76X3;
    case 327: goto l_L78X3;
    case 328: goto l_L80X3;
    case 329: goto l_L82X3;
    case 330: goto l_L81X3;
    case 331: goto l_L74X3;
    case 332: goto l_L79X3;
    case 333: goto l_L77X3;
    case 334: goto l_L75X3;
    case 335: goto l_L72X3;
    case 337: goto l_lr_236;
    case 338: goto l_L83X3;
    case 340: goto l_lr_239;
    case 341: goto l_L84X3;
    case 343: goto l_lr_242;
    case 344:
      reg_l0_0 = t_client_rpc;
      return;
    default:
      sim_bad_label(t_labelnum);
    }
}


static sim_fileinfo_t t_thisfile = {"deriche.s", 1344, 0, 0, 0, 2};


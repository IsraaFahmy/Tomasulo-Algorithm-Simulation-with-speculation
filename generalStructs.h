#pragma once

#define LW_RS       2
#define LW_cycles   3 
#define SW_RS       2
#define SW_cycles   3 
#define JMP_RS      2
#define JMP_cycles  1 
#define BEQ_RS      2
#define BEQ_cycles  1
#define ADD_RS      3
#define ADD_cycles  2  
#define NANd_RS     2
#define NANd_cycles 1
#define MULT_RS     2
#define MULT_cycles 10

#include <iostream>
#include <string>
using namespace std;

enum state {issue, excute, write, commit}; 
enum operation {load, store, add, sub, mult, /*div,*/ nand, addi};

struct inst {
	state instState;
	operation instType;
	string rs1, rs2, rd;
	long signed int imm; 
};

struct reservation_station_table {
	string FU_name;
	bool busy;
	operation op;
	string Vj, Vk;
	int Qj, Qk, dest, A; 
};

struct reg_table {
	int regs[8]; 
	int ROB_ID[8]; 
};

struct ROB {
	int ROB_ID;
	operation Type;
	int dest, value;
	bool Ready; 
};

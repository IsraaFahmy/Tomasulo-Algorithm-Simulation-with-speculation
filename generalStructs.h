#pragma once
#include <iostream>
#include <string>
using namespace std;

enum state {issue, excute, write, commit}; 
enum operation {load, store, add, sub, mult, div, nand, addi};

struct inst {
	state instState;
	operation instType;
	string rs1, rs2, rd;
	long signed int imm; 
};

struct FU_parameters {
	//1 -> the number of available reservation stations
	//2 -> the number of cycles needed 
	int LW[2] = { 2,3 };
	int SW[2] = { 2,3 };
	int JMP[2] = { 2,1 };
	int JALR[2] = { 2,1 };
	int RET[2] = { 2,1 };
	int BEQ[2] = { 2,1 };
	int ADD[2] = { 3,2 };
	int SUB[2] = { 3,2 };
	int ADDI[2] = { 3,2 };
	int NANd[2] = { 2,1 };
	int MULT[2] = { 2,10 };
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

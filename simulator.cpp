#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <vector>
#include <fstream>
#include"GeneralStructs.h"
#include "CircularQueue.h"
using namespace std;

int regs[8] = { 0 };   //array of registers 
int pc = 0x0;  //location 0x00000000 in the main memory
int clk = 1,
//loading instructions from file
void File_Instructions(vector<string> inst_str, int Number_of_instructions)
{
	string filename;
	bool found = false;
	while (!found) //the loop is repeated till the file opens
	{
		cout << "Enter the name of the instruction file " << endl;
		cin >> filename;
		ifstream file(filename);

		if (file.is_open())
		{
			int i = 0;
			while ((i < Number_of_instructions) && (file))
			{
				getline(file, inst_str[i]);
				i++;
			}
			found = true;
		}
		else
		{
			cout << "File Not Found!" << endl;
			found = false;
		}
	}

}

//Manually enter instructions
void Manual_Instructions(vector<string> inst_str, int Number_of_instructions)
{
	cout << "Enter the instructions";
	string in;
	for (short int i = 0; (i < Number_of_instructions); i++)
	{
		cout << "i:" << (i + 1);
		cin >> in;
		inst_str[i] = in;
	}
}
int main() {
	int Memory[64 * 1024] = { 0 }; //64 * 1024 bytes * 2 bytes = 128KB, but word addressable so 64 * 1024 is used (char or int??)
	int Mem_Location;
	int Mem_Val;
	int inst_count; // to be read from the user
	int User_choice;
	//updating the memory 
	while (Mem_Location >= 0)//terminate using any number less than 0 
	{
		cout << "Enter memory location to update";
		cin >> Mem_Location;
		cout << "Enter new value:";
		cin >> Mem_Val;
		if (Mem_Location >= 0)
			Memory[Mem_Location] = Mem_Val;
	}
	
	
	cout << " Please choose (0) to read from a file or (1) to enter the instructions manually" << endl;
	cin >> User_choice;
	vector<string> instruction_line(inst_count);
	if (User_choice == 1) {
		cout << "Enter number of instrutions: ";
		cin >> inst_count;
		Manual_Instructions(instruction_line, inst_count);
	}
	else File_Instructions(instruction_line, inst_count);



	system("pause");
	exit(0);
}

void RS_TB_initialize(RS_Table RS_TB[15])
{
	
	//For load
	int j = 0;
	for (int i= 0; i < LW[0]; i++)
	{
		RS_TB[i].FU_name = "LOAD" + to_string(j++);
		RS_TB[i].Busy = 0; 
		RS_TB[i].op = load;
		RS_TB[i].dest = 0;
		RS_TB[i].A = 0;
	}
	//For Store
	j = 0;
	for (int i=0; i < SW[0] ; i++)
	{
		RS_TB[i].FU_name = "STORE" + to_string(j++);
		RS_TB[i].Busy = 0;
		RS_TB[i].op = store;
		RS_TB[i].dest = 0;
		RS_TB[i].A = 0;
	}
	//For Jump
	j = 0;
	for (int i=0 ; i < JMP[0]; i++)
	{
		RS_TB[i].FU_name = "JUMP" + to_string(j++);
		RS_TB[i].Busy = 0;
		RS_TB[i].op = add;
		RS_TB[i].dest = 0;
		RS_TB[i].A = 0;
	}
	//For Branch
	j = 0;
	for (int i=0; i < BEQ[0]; i++)
	{
		RS_TB[i].FU_name = "BRANCH" + to_string(j++);
		RS_TB[i].Busy = 0;
		RS_TB[i].op = add;
		RS_TB[i].dest = 0;
		RS_TB[i].A = 0;
	}
	//For Arith
	j = 0;
	for (int i=0; i < ; i++)
	{
		res_tb[i].Name = "ADD" + to_string(j + 1);
		res_tb[i].Busy = 0; //Initially Mark as Free
		res_tb[i].Address = 0;
		res_tb[i].OpCycle = 0;
		res_tb[i].temp_result = 0;
		res_tb[i].Initial_Cycle = 0;
		j++;
	}
	//For NAND
	j = 0;
	NCounter = i;
	for (i; i < (NCounter + NAND_RS); i++)
	{
		res_tb[i].Name = "NAND" + to_string(j + 1);
		res_tb[i].Busy = 0; //Initially Mark as Free
		res_tb[i].Address = 0;
		res_tb[i].OpCycle = 0;
		res_tb[i].temp_result = 0;
		res_tb[i].Initial_Cycle = 0;
		j++;
	}
	//For Multiply
	j = 0;
	NCounter = i;
	for (i; i < (NCounter + MULT_RS); i++)
	{
		res_tb[i].Name = "MULT" + to_string(j + 1);
		res_tb[i].Busy = 0; //Initially Mark as Free
		res_tb[i].Address = 0;
		res_tb[i].OpCycle = 0;
		res_tb[i].temp_result = 0;
		res_tb[i].Initial_Cycle = 0;
		j++;
	}
}

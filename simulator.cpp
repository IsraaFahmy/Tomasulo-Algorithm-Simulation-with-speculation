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
int pc = 0x0;          //location 0x00000000 in the main memory
int clk = 1;
int Memory[64 * 1024] = { 0 }; //64 * 1024 bytes * 2 bytes = 128KB, but word addressable so 64 * 1024 is used 
void RS_TB_initialize(reservation_station_table RS_TB[15]);
void File_Instructions(vector <string> inst_str);
void Manual_Instructions(vector <string> inst_str, int inst_count);

int main() 
{

	int Mem_Location=0;
	int Mem_Val;
	int inst_count; 
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

	
	vector <string> instruction_lines;

	if (User_choice == 1) 
	{
		cout << "Enter number of instrutions: ";
		cin >> inst_count;
		Manual_Instructions(instruction_lines, inst_count);
	}
	else File_Instructions(instruction_lines);



	system("pause");
	exit(0);
}

void RS_TB_initialize(reservation_station_table RS_TB[15])
{

	//For load
	int j = 0;
	for (int i = 0; i < LW_RS; i++)
	{
		RS_TB[i].FU_name = "LOAD" + to_string(j++);
		RS_TB[i].busy = 0;
		RS_TB[i].op = load;
		RS_TB[i].dest = 0;
		RS_TB[i].A = 0;
	}
	//For Store
	j = 0;
	for (int i = 0; i < SW_RS; i++)
	{
		RS_TB[i].FU_name = "STORE" + to_string(j++);
		RS_TB[i].busy = 0;
		RS_TB[i].op = store;
		RS_TB[i].dest = 0;
		RS_TB[i].A = 0;
	}
	//For Jump
	j = 0;
	for (int i = 0; i < JMP_RS; i++)
	{
		RS_TB[i].FU_name = "JUMP" + to_string(j++);
		RS_TB[i].busy = 0;
		RS_TB[i].op = add;
		RS_TB[i].dest = 0;
		RS_TB[i].A = 0;
	}
	//For Branch
	j = 0;
	for (int i = 0; i < BEQ_RS; i++)
	{
		RS_TB[i].FU_name = "BRANCH" + to_string(j++);
		RS_TB[i].busy = 0;
		RS_TB[i].op = add;
		RS_TB[i].dest = 0;
		RS_TB[i].A = 0;
	}
}

// loading instructions from file
void File_Instructions(vector <string> inst_str)
{
	string filename;

	cout << "Enter the name of the instruction file " << endl;
	cin >> filename;

	ifstream file(filename);

	if (file.is_open())
	{
		int i = 0;
		while (!file.eof())
		{
			getline(file, inst_str[i]);
			i++;
		}
	}
	else
		cout << "File Not Found!" << endl;

}

//Manually enter instructions
void Manual_Instructions(vector <string> inst_str, int inst_count)
{
	cout << "Enter the instructions";
	for (int i = 0; i < inst_count; i++)
	{
		cout << "i" << (i + 1) << ": ";
		getline(cin, inst_str[i]);
	}
}
//convert source registers into their integer value 
int reg_To_Num(string & str) {
	int reg;
	if (str == "R0")
		return 0;
	else if (str == "R1")
		return 1;
	else if (str == "R2")
		return 2;
	else if (str == "R3")
		return 3;
	else if (str == "R4")
		return 4;
	else if (str == "R5")
		return 5;
	else if (str == "R6")
		return 6;
	else if (str == "R7")
		return 7;
}


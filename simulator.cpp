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

int regs[32] = { 0 };   //array of registers 
unsigned int pc = 0x0;  //location 0x00000000 in the main memory
bool flag = false;
char memory[8 * 1024] = { 0 };	// only 8KB of memory located at address 0

int main(int argc, char *argv[]) {




	system("pause");
	exit(0);
}

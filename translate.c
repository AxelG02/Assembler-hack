#include "translate.h"
#include <stdio.h>
#include <string.h>

// map of destinations with corresponding integer value
keymap DEST[8] = {
	"", 0, "M", 8, "D", 16, "MD", 24, "A", 32, "AM", 40, "AD", 48, "AMD", 56
};

// map of jumps with corresponding integer value
keymap JUMP[8] = {
	"", 0, "JGT", 1, "JEQ", 2, "JGE", 3, "JLT", 4, "JNE", 5, "JLE", 6, "JMP", 7
};

// map of operations with corresponding integer value
keymap OPERATION[28] = {
	"0", 2688, "1", 4032, "-1", 3712, "D", 768, "A", 3072, "!D", 832, "!A", 3136, "-D", 960, "-A", 3264, "D+1", 1984, "A+1", 3520, "D-1", 896, "A-1", 3200, "D+A", 128, "D-A", 1216, "A-D", 448, "D&A", 0, "D|A", 1344,
	"M", 7168, "!M", 7232, "-M", 7360,  "M+1", 7616, "M-1", 7296, "D+M", 4224, "D-M", 5312, "M-D", 4544, "D&M", 4096, "D|M", 5440
};

// search "str" in the keymap "map" and returns the "str" in its integer form corresponding to its binary value
int map_search(keymap* map, int size, char* str) {
	for (int i=0; i<size; i++) {
		if (strcmp(map[i].hack, str) == 0) {
			return  map[i].bin;
		}
	}	
	return -1;
}

// switch between the three different keymaps given the instruction type (jump, dest, operation)
int translate(char *str, char instrtype){
	int translated = 0;
	switch (instrtype){
	case 'J':
		translated =  map_search(JUMP, 8, str);
		break;
	case 'D':
		translated = map_search(DEST, 8, str);
		break;
	case 'O':
		translated = map_search(OPERATION, 28, str);
		break;
	}
	return translated;
}
#ifndef TRANSLATION
#define TRANSLATION

typedef struct{
	char *hack;
	int bin;
} keymap;

// search "str" in the keymap "map" and returns the "str" in its integer form corresponding to its binary value
int map_search(keymap* map, int size, char* str);

// switch between the three different keymaps given the instruction type (jump, dest, operation)
int translate(char *str, char instrtype);

#endif
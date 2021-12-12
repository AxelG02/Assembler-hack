// returns an integer from a number inside a string
int string_to_int(char str[]);

// transform an integer in binary and returns it inside string
char* int_to_bin(char* ret, int val);

// changes the extentionfrom .asm to .hack in order to create the output file.
char* asm_to_hack(char* foutN, char* fname, char* ext);

// void function that remove all the comments from the string
void remove_comments(char* str);

// void function that take a string pointer and cleans the spaces tabs and newlines
void clean_string(char* str);

// returns the index of the "c" in "str"
int char_search(char *str, char c);
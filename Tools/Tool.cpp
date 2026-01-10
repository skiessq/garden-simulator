#include "Tool.h"

int Tool::lastID = 0;

Tool::Tool(char s) : symbol(s) {
    id = ++lastID;
}
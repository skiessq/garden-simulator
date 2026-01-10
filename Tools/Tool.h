#ifndef TOOL_H
#define TOOL_H

class Soil;

class Tool {
    static int lastID;
    int id;
    char symbol;
public:
    Tool(char s);
    virtual ~Tool() {}

    int getID() const { return id; }
    static int getLastId() {return lastID; }
    char getSymbol() const { return symbol; }
    virtual bool use(Soil* soil) = 0;

    virtual Tool* clone() const = 0;
};

#endif
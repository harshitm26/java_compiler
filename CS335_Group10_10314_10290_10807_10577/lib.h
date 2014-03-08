#include <unordered_map>
#include <string>
#include <vector>
#include <map>
#include "./tokenize.h"
#define OKAY true
#define ERROR false
using namespace std;

typedef unordered_map<string, struct element*> symmap;
struct scope{
	string lexeme;
	struct scope* parent;
	element* elem;
	symmap symtbl;
	
};
typedef enum _kind{
	KVARIABLE,					//0
	KOBJECT,					//1
	KLITERAL,						//2
	KPRIMITIVE,//type				//3
	KCLASS,//type					//4
	KPRIMFUNCTION,//type			//5
	KREFFUNCTION,//type				//6
	KCONSTRUCTOR,//type				//7
	KBLOCK,							//8
	KUNKNOWN,//to be known			//9
	KILLEGAL,//error				//10
	KALL								//11
}kindof;
typedef enum _accessmod{
	APUBLIC,
	APRIVATE,
	APROTECTED,
	ANONE
}accessmod;
typedef enum _primdtype{
	TBYTE,
	TCHAR,
	TSHORT,
	TINT,
	TLONG,
	TFLOAT,
	TDOUBLE,
	TSTRING,
	TBOOLEAN,
	TVOID,
	TUNKNOWN,//to be known
	TWILDCARD, //for switch's default label
	TILLEGAL//error
}primdtype;
typedef enum _addrmode{
	DIRECT,
	REFERENCE
}addrmode;
struct element{
	string name;
	kindof kind;
	primdtype pdtype;
	struct element* rdtype;
	vector<int> dimensions;
	int loc;
	accessmod mod;
	scope* desc;
	struct element* superclass;
	struct listofelements* arguments;
	string label;
	addrmode amode;
};
struct namenode{
	string name;
	struct namenode* next;
};
struct listofelements{
	element* elem;
	struct listofelements* next;
};
struct listofdeclarators{
	element* elem;
	element* equals;
	struct listofdeclarators* next;
};
typedef vector<string> vectorstring;	

struct spvec {
	vector<int> *pvec;
};

struct splab{
	int sp1;
	int sp2;
	int sp3;
	string label;
};

element* makePrimNode(string name, kindof kind, primdtype pdtype, vector<int> dimensions, int location, accessmod mod, scope* desc);

element* makeRefNode(string name, kindof kind, element* rdtype, vector<int> dimensions, int location, accessmod mod, scope* desc, element* superclass, listofelements* args);


element* findtype(scope* pscope, namenode* node, kindof kind = KALL);
element* findtypeinthisorsuper(element* pelement, namenode* node, bool respectprivacy);
scope* createScope(string lexeme, scope* parent,element* elem);
void revertscope();
accessmod getModifier(char* str);
bool iscoercible(element* coerced, element* target);
bool iscoerciblelist(listofelements* list, element* target);
bool iscoercibledlist(listofdeclarators* list, element* target);
element* copyelement(element* elem);
element* coerce (element* coerced, element* target);
bool coercelist(listofelements * list, element * target);
bool coercedlist(listofdeclarators * list, element * target);
element* copyandcoerce(element* coerced, element* target);
bool issuperclass(element* sup, element* sub);
element* currentelement();
element* makeIllegalNode();
bool iscoerciblelisttolist(listofelements* coerced, listofelements* target);
element* getelement(scope* scp);
void makeblockscope();

void printscopehierarchy();

void here(int a);
void ehere(int a=0);
void printsymtbl(symmap& tbl);
bool alreadypresent(string& str);
bool alreadypresent(char* str);
void printrec(scope* scp,int count);
void print();
char* newlabel();
int sizeofelement(element* e);
void fetchint0(element* e);
int sizeoftype(element* e);
int getoffset(element* object, namenode* node, bool respectprivacy);
element* findobjectinthisorsuper(element* pelement, namenode* node, bool respectprivacy);

element* findobject(scope* pscope, namenode* node, kindof kind);

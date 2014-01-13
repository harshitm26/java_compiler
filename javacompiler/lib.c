#include "./lib.h"
#define LDEBUG 1
extern int error_count;
extern scope* current;
extern scope* godscope;
extern element* godelement;
extern int line_number;
int nblocks = 0;
element* makePrimNode(string name, kindof kind, primdtype pdtype, vector<int> dimensions, void* location, accessmod mod, scope* desc){
	element* newelem = new element();
	newelem->name = string(name);
	newelem->kind = kind;
	newelem->pdtype = pdtype;
	newelem->dimensions = dimensions;
	newelem->loc = location;
	newelem->mod =mod;
	newelem->desc = desc;
	newelem->superclass = NULL;
	return newelem;
}

element* makeRefNode(string name, kindof kind, element* rdtype, vector<int> dimensions, void* location, accessmod mod, scope* desc, element* superclass, listofelements* args){
	element* newelem = new element();
	newelem->name = string(name);
	newelem->kind = kind;
	newelem->rdtype = rdtype;
	newelem->dimensions = dimensions;
	newelem->loc = location;
	newelem->mod =mod;
	newelem->desc = desc;
	newelem->superclass = superclass;
	return newelem;
}

element* findtype(scope* pscope, namenode* node, kindof kind){
	//printf("findtype(): finding %s in scope %s\n", node->name.c_str(), pscope->lexeme.c_str());
	//printsymtbl(pscope->symtbl);
	
	//if(pscope == NULL) return NULL;
	element* e = findtypeinthisorsuper(pscope->elem, node, false);
	if(e!=NULL) return e;
	
	scope* s = pscope->parent;
	unordered_map<string, element*>::iterator it;
	while(s != NULL){
		//printf("findtype(): finding %s in scope %s\n", node->name.c_str(), s->lexeme.c_str());
		//printsymtbl(s->symtbl);
		e = findtypeinthisorsuper(s->elem, node, true);
		if(e!=NULL && (kind == KALL || e->kind == kind)) return e;
		s = s->parent;
	}
	printf("error at line #%d: %s does not exist or is not accessible in this scope\n", line_number, node->name.c_str());
	here(35);
	return makeIllegalNode();
}


element* findtypeinthisorsuper(element* pelement, namenode* node, bool respectprivacy){
	if(node==NULL){
		return pelement;
	}
	element* e = pelement;
	unordered_map<string, element*>::iterator it;
	
	while(e!=NULL){
		
		if(e->desc != NULL){
			it = e->desc->symtbl.find(node->name);
			//printf("findtypeinthisorsuper(): finding %s in %s\n", node->name.c_str(), e->name.c_str());
			//printsymtbl(e->desc->symtbl);
			if(it != e->desc->symtbl.end()){
				if(it->second->mod == APRIVATE && respectprivacy== true){
					printf("error at line #%d: class/member %s not accessible", line_number, node->name.c_str());
					
					here(36);
					return NULL;
				}else{
					return findtypeinthisorsuper(it->second, node->next, respectprivacy);
				}
			}
		}
		e = e->superclass;
	}
	return NULL;
}

scope* createScope(string lexeme, scope* parent, element* elem){
	//printf("%d: createScope()\n", line_number);
	scope* newscope = new scope();
	newscope->lexeme = string(lexeme);
	newscope->parent = parent;
	newscope->elem = elem;
	//~ newscope->symtbl = symmap();
	return newscope;
}
void revertscope(){
	current = current->parent;
}

bool iscoercible(element* coerced, element* target){
	//printf("iscoercible() coerced(%s, %d, %d) target(%s, %d, %d)\n", coerced->name.c_str(), coerced->kind, coerced->pdtype, target->name.c_str(), target->kind, target->pdtype);
	if(coerced == NULL){
		if(LDEBUG) printf("%d iscoercible()=false arg 1 is NULL\n", line_number);
		here(38);
		return false;
	}else if(target == NULL){
		if(LDEBUG) printf("%d iscoercible()=false arg 2 is NULL\n", line_number);
		here(39);
		return false;
	}
	if(LDEBUG){
		//printf("%d iscoercible() kind:(%d, %d) pdtype(%d, %d) rdtype(%ud, %ud)\n", line_number, coerced->kind, target->kind, coerced->pdtype, target->pdtype, coerced->rdtype, target->rdtype);
	}
	if(target->kind != KPRIMITIVE
		&& target->kind != KCLASS
		&& target->kind!= KVARIABLE
		&& target->kind!=KOBJECT
		&& target->kind!=KLITERAL){//check if target is a type
		here(40);
		return false;
	}
	
	switch(coerced->kind){
		case(KVARIABLE):	if(target->kind!=KVARIABLE 
							&& target->kind != KPRIMITIVE
							&& target->kind!=KLITERAL){
								here(41); return false;
							}
							break;
		case(KOBJECT):	if(target->kind!=KCLASS && target->kind!=KOBJECT){
								here(42); return false;
							}
						break;
		case(KLITERAL):	if(target->kind!=KVARIABLE
							&& target->kind != KPRIMITIVE){
								here(43); return false; 
							}
						break;
		case(KUNKNOWN): //printf("COERCIBLE\n"); 
						return true; break;
		default: return false;
	}
	if(coerced->kind == KVARIABLE || coerced->kind==KLITERAL){
		if(coerced->pdtype == TBOOLEAN){
			switch(target->pdtype){
				case(TSTRING):
				case(TBOOLEAN): break;
				default: here(44); return false;
			}
		}else if(coerced->pdtype == TBYTE){
			switch(target->pdtype){
				case(TBYTE):
				case(TCHAR):
				case(TSTRING):
				case(TINT):
				case(TLONG):
				case(TFLOAT):
				case(TDOUBLE): break;
				default: here(45); return false;
			}
		}else if(coerced->pdtype == TCHAR){
			switch(target->pdtype){
				case(TCHAR):
				case(TSTRING):
				case(TINT):
				case(TLONG):
				case(TFLOAT):
				case(TDOUBLE): break;
				default: here(46); return false;
			}
		}else if(coerced->pdtype == TINT){
			switch(target->pdtype){
				case(TSTRING):
				case(TINT):
				case(TLONG):
				case(TFLOAT):
				case(TDOUBLE): break;
				default: here(47); return false;
			}
		}else if(coerced->pdtype == TLONG){
			switch(target->pdtype){
				case(TSTRING):
				case(TLONG):
				case(TFLOAT):
				case(TDOUBLE): break;
				default: here(48); return false;
			}
		}else if(coerced->pdtype == TFLOAT){
			switch(target->pdtype){
				case(TSTRING):
				case(TFLOAT):
				case(TDOUBLE): break;
				default: here(49); return false;
			}
		}else if(coerced->pdtype == TDOUBLE){
			switch(target->pdtype){
				case(TSTRING):
				case(TDOUBLE): break;
				default: here(50); return false;
			}
		}
	}else{ //coerced is object
		if(coerced->rdtype != target && !issuperclass(target, coerced) && coerced->rdtype!=NULL){
			here(51);
			return false;
		}
	}
		
	if(coerced->dimensions != target->dimensions){
		here(52);
		return false;
	}
	//printf("COERCIBLE\n");
	return true;
}
			
bool iscoerciblelist(listofelements* list, element* target){
	if(target->kind != KPRIMITIVE && target->kind!= KCLASS){
		here(53);
		return false;
	}
	listofelements* node = list;
	while(node!=NULL){
		if(!iscoercible(node->elem, target)){
			here(54);
			return false;
		}
		node = node->next;
	}
	return true;
}

element* copyelement(element* elem){
	element* newelem = new element();
	newelem->name = string(elem->name);
	newelem->kind = elem->kind;
	if(elem->kind == KPRIMITIVE || elem->kind == KPRIMFUNCTION){
		newelem->pdtype = elem->pdtype;
	}else if(elem->kind == KCLASS || elem->kind == KREFFUNCTION){
		newelem->rdtype = elem->rdtype;		
	}
	newelem->dimensions = vector<int>(elem->dimensions);
	newelem->loc = NULL;//will be set in code generation phase
	newelem->mod = elem->mod;
	newelem->desc = elem->desc;
	newelem->superclass = elem->superclass;
	newelem->arguments = elem->arguments;
	return newelem;
}
	
element* coerce (element* coerced, element* target){
	if(target->kind == KPRIMITIVE || target->kind==KLITERAL || target->kind==KVARIABLE){
		if(coerced->kind==KUNKNOWN) coerced->kind=KVARIABLE;
		coerced->pdtype = target->pdtype;
	}else if(target->kind == KCLASS || target->kind==KOBJECT){
		if(coerced->kind == KUNKNOWN) coerced->kind = KOBJECT;
		coerced->rdtype = target->rdtype;
	}else{
		here(55);
		//~ ehere(55);
		return NULL;
	}
	//~ if(coerced->kind == KUNKNOWN) coerced->kind=target->kind;	
	coerced->dimensions = vector<int>(target->dimensions);
	return coerced;
}

bool coercelist(listofelements * list, element * target){
	listofelements* node =list;
	while(node!=NULL){
		if(NULL==coerce(node->elem, target)){
			here(56);
			return ERROR;
		}
		node = node->next;
	}
	return OKAY;
}

element* copyandcoerce(element* coerced, element* target){
	element* copy = copyelement(coerced);
	return coerce(copy, target);
}

bool issuperclass(element* sup, element* sub){
	element* c = sub->superclass;
	while(c !=NULL){
		if(c==sup) return true;
		c = c->superclass;
	}
	here(57);
	return false;
}

element* currentelement(){
	return getelement(current);
}
	
element* getelement(scope* scp){
	return scp->elem;
	//~ if(LDEBUG) printf("getelement() lexme=%s\n", scp->lexeme.c_str());
	//~ if(scp == godscope){
		//~ if(LDEBUG) printf("getelement() returned godelement\n");
		//~ return godelement;
	//~ }
	//~ scope* parentscope = current->parent;
	//~ symmap::iterator it = parentscope->symtbl.find(lexeme);
	//~ if(it!=parentscope->symtbl.end()) return it->second;
	//~ scope* parentparentscope = parentscope->parent;
	//~ element* parentelement = getelement(parentparentscope, parentscope->lexeme);
	//~ element* sup = parentelement->superclass;
	//~ while(sup != NULL){
		//~ it = sup->desc->symtbl.find(lexeme);
		//~ if(it != sup->desc->symtbl.end()) return it->second;
		//~ sup = sup ->superclass;
	//~ }
	//~ return NULL;//never reached
}	

	
element* makeIllegalNode(){
	printf("Line #%d: incompatible types\n", line_number);
	element* ill = new element();
	ill->kind = KILLEGAL;
	ill->pdtype=TUNKNOWN;
	ill->rdtype=NULL;
	ill->loc=NULL;
	ill->superclass=NULL;
	ill->arguments=NULL;
	ill->desc=NULL;
	here(58);
	return ill;
}

bool iscoerciblelisttolist(listofelements* coerced, listofelements* target){
	
	listofelements *cnode = coerced, *tnode = target;
	while(cnode!=NULL && tnode!=NULL){
		if(!iscoercible(cnode->elem, tnode->elem)){
			here(60);
			return false;
		}
		tnode = tnode->next;
		cnode= cnode->next;
	}
	if(cnode==NULL && tnode==NULL) return true;
	here(61);
	return false;
}

void makeblockscope(){
	//~ printf("%d: makeblockscope()\n", line_number);
	//~ printscopehierarchy();
	char str[16];
	nblocks ++;
	sprintf(str, "block%d", nblocks);
	scope* newscope = new scope();
	newscope->parent = current;
	newscope->lexeme = string(str);
	newscope->elem = makePrimNode(string(str), KBLOCK, TUNKNOWN, vector<int>(), NULL, ANONE, newscope);

	current->symtbl.insert({string(str), newscope->elem});
	current = newscope;
}

void printscopehierarchy(){
	scope* scp= current;
	printf("SCOPE HIERARCHY\n");
	while(scp->parent!=NULL){
		printf("kind: %d name: %s\n", scp->elem->kind, scp->lexeme.c_str());
		printf("\t|\n");
		printf("\t|\n");
		printf("\tv\n");
		scp = scp->parent;
	}
	printf("kind: %d name: %s\n", scp->elem->kind, scp->lexeme.c_str());
}

void here(int a){
	//~ printf("[[[%d]]]\n",a);
}

void ehere(int a){
	error_count++;
	printf("ERROR: at lin number [%d].....................................\n", line_number);
}

void printsymtbl(symmap& tbl){
	printf("symtbl.size()=%d\n", tbl.size());
	symmap::iterator it = tbl.begin();
	for(; it != tbl.end(); it++){
		printf("(name:%s, kind: %d, type: %d %s)\n", it->first.c_str(), it->second->kind, it->second->pdtype, it->second->rdtype==NULL?string().c_str():it->second->rdtype->name.c_str());
		if(it->second->kind == KBLOCK) printsymtbl(it->second->desc->symtbl);
	}
}

bool alreadypresent(char* str){
	
	symmap::iterator it = current->symtbl.find(string(str));
	if(it==current->symtbl.end()) return false;
	here(393);
	return true;
}
bool alreadypresent(string& str){
	symmap::iterator it = current->symtbl.find(string(str));
	if(it==current->symtbl.end()) return false;
	here(399);
	return true;
	
}
void printrec(scope *scp,int count=0){
	if(scp==NULL)	return;
	symmap::iterator it=scp->symtbl.begin();
	for (;it!=scp->symtbl.end();it++){
		if(it->first.c_str()!=NULL)
		{
			int i;
			if(it->second->kind!=KBLOCK){	
				for(i=0;i<count;i++) printf("\t");
				printf("%s:............\n",it->first.c_str());
			}	
			
			printrec(it->second->desc,count+1);
			if(it->second->kind!=KVARIABLE && it->second->kind!=KBLOCK){
				for(i=0;i<count;i++) printf("\t");
				printf("%s:.................over\n",it->first.c_str());
			}	
		}
		//~ printf(".........................................................\n");
	}	
}

void print(){
	printrec(godscope);
}

void printrec(scope* scp,int count);
void print();


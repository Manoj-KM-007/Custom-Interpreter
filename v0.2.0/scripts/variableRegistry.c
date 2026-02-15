#include <variableRegistry.h>
#include <memoryHandler.h>
#include <error.h>
#include <string.h>
#include <value.h>

Variable* arr[100];
Variable* local_var[100];
bool inFunction = false;

void clear_local(){
    for(int i = 0; i < 100; i++){
        local_var[i] = NULL;
    }
}
void initVariableRegistry() {
    for(int i = 0; i < 100; i++){
        arr[i] = NULL;
    }
    for(int i = 0; i < 100; i++){
        local_var[i] = NULL;
    }
}

Variable* createVariable(char* varName,DataType type,MemNode* obj){
    MemNode* node = createMemNode(sizeof(Variable));
    Variable* v = node->ptr;
    MemNode* strObj = createMemNode(strlen(varName)+1);
    v->varName = strObj->ptr;
    strcpy(v->varName,varName);
    v->data =  obj->ptr;
    v->isConstant = false;
    v->type = type;
    v->next = NULL;
    return v;
}

unsigned int hash(char* varName){
    int temp = 0;
    int n = strlen(varName);
    for(int i =0;i < n;i++){
        temp += (int) varName[i];
    }
    unsigned int key = (temp * 33) % 100;
    return key;
}

void setVariable(Variable* v){
    Variable** current;
    unsigned int index = hash(v->varName);
    if(!local_var[index]){
        local_var[index] = v;
        return;
    }
    current = &local_var[index];
    while(*current){ 
        char* varName = (*current)->varName;
        if(strcmp(varName,v->varName) == 0){
            if((*current)->isConstant){
                char err[256];
                snprintf(err,sizeof(err),"'%s' cannot be Modified (const)",varName);
                error(err,0,RUN_TIME_ERROR);
            }
            v->next = (*current)->next;
            *current = v;
            return;
        }
        current = &((*current)->next);
    }
    (*current)->data= v->data;
    (*current)->isConstant = v->isConstant;
    (*current)->type = v->type;
    return;
    if(!arr[index]){
        arr[index] = v;
        return;
    }
    current = &arr[index];
    while(*current){ 
        char* varName = (*current)->varName;
        if(strcmp(varName,v->varName) == 0){
            if((*current)->isConstant){
                char err[256];
                snprintf(err,sizeof(err),"'%s' cannot be Modified (const)",varName);
                error(err,0,RUN_TIME_ERROR);
            }
            v->next = (*current)->next;
            *current = v;
            return;
         }
        current = &((*current)->next);
    }
    (*current)->data= v->data;
    (*current)->isConstant = v->isConstant;
    (*current)->type = v->type;
}

Variable* getVariable(char* varName){
    unsigned int index = hash(varName);
    Variable* current;
    current = local_var[index];
    while(current != NULL){
        if(strcmp(current->varName,varName) == 0){
            return current;
        }
        current = current->next;
    }

    current = arr[index];
    if(current == NULL){
        char err[256];
        snprintf(err,sizeof(err),"'%s'  Accesing an Undefined Variable, Check Variable Names and Previous Declaration",varName);
        error(err,0,RUN_TIME_ERROR);
    }
    while(current != NULL){
        if(strcmp(current->varName,varName) == 0){
            return current;
        }
        current = current->next;
    }
    char err[256];
    snprintf(err,sizeof(err),"'%s'  Accesing an Undefined Variable, Check Variable Names and Previous Declaration",varName);
    error(err,0,RUN_TIME_ERROR);
    return NULL;
}

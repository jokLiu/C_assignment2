
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "evalexp.h"



struct env {
    char var[8];
    int value;
    struct env *next;
};


int getConstantFromEnvironment(char *var, struct env *env);
struct env *removeFirstEnvironment(struct env *env);
struct env *addEnvironment(struct env *env, char *var, int value);
int evalexpList(enum op tag, struct explist *list, struct env *env);
int evalexpenv(struct exp *e, struct env *env);

int getConstantFromEnvironment(char *var, struct env *env)
{
    struct env *temp = env;
    while(temp){
        if (strcmp(var,temp->var) == 0)
            return temp->value;
        temp = temp->next;
    }
    //should never happen
    return 0;
}

struct env *removeFirstEnvironment(struct env *env)
{
    struct env *temp = NULL;
    if(env)
    {
        temp = env->next;
        free(env);
    }
    return temp;
}

struct env *addEnvironment(struct env *env, char *var, int value)
{
    struct env *newEnv = malloc(sizeof(struct env));
    newEnv->value = value;
    strncpy(newEnv->var, var, 8);
    newEnv->next= env;
    return newEnv;
}


int evalexpList(enum op tag, struct explist *list, struct env *env)
{
    if(list)
    {
        if(tag == isplus)
            return evalexpenv(list->head, env)+evalexpList(tag, list->tail, env);
        else return evalexpenv(list->head, env)*evalexpList(tag, list->tail, env);
    }
    if(tag == isplus)
         return 0;
    else return 1;
}


int evalexpenv(struct exp *e, struct env *env)
{

    if(!e) return 0;
    switch(e->tag)
    {
        case isconstant:
            return e->constant;
            break;
        case isopapp:
            if(e->op == isplus) return evalexpList(isplus, e->exps, env);
            else return evalexpList(ismult, e->exps, env);
            break;
        case islet:
            env = addEnvironment(env,e->bvar,evalexpenv(e->bexp, env));
            int result = evalexpenv(e->body, env);
            env = removeFirstEnvironment(env);
            return result;
            break;
        case isvar:
            return getConstantFromEnvironment(e->var, env);
            break;
        default:
            break;
    }
    return 0;
}

int evalexp(struct exp *e)
{
    struct env *env = malloc(sizeof(struct env));
    env = NULL;
    return evalexpenv(e, env);
}

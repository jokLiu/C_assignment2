// main function for evaluation expression exercise

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "evalexp.h"

// tree construction functions

struct exp *mkvar(char *cp)
{
  struct exp *ep = malloc(sizeof(struct exp));
  ep->tag = isvar;
  strncpy(ep->var, cp, 8);
  return ep;
}

struct exp *mkconstant(int n)
{
  struct exp *ep = malloc(sizeof(struct exp));
  ep->tag = isconstant;
  ep->constant = n;
  return ep;
}

struct exp *mkopapp(enum op op, struct explist *el)
{
  struct exp *ep = malloc(sizeof(struct exp));
  ep->tag = isopapp;
  ep->op =  op;
  ep->exps =  el;
  return ep;
}

struct exp *mklet(char *cp, struct exp *e1, struct exp *e2)
{
  struct exp *ep = malloc(sizeof(struct exp));
  ep->tag = islet;
  strncpy(ep->bvar, cp, 8);
  ep->bexp = e1;
  ep->body = e2;
  return ep;
}

struct explist *cons(struct exp *e, struct explist *l)
{
  struct explist *l2 = malloc(sizeof(struct explist));
  l2->head = e;
  l2->tail = l;
  return l2;
}

// main for testing

int main(int argc, const char *argv[])
{
//  struct exp *e1 ,*e2;
//  struct explist *l;
//
//  l = NULL;
//  l = cons(mkconstant(5), l);
//  l = cons(mkconstant(3), l);
//  l = cons(mkconstant(2), l);
//  e1 = mkopapp(isplus, l);
//
//  l = NULL;
//  l = cons(mkvar("x"), l);
//  l = cons(mkvar("x"), l);
//  l = cons(mkvar("x"), l);
//  e2 = mkopapp(ismult, l);
//
//  e1 = mklet("x", e1, e2);
//
//  printf("%d\n", evalexp(e1)); // should print  1000

    //2

//    struct exp *e1 ,*e2, *e3;
//    struct explist *l;
//
//    l = NULL;
//    l = cons(mkconstant(5), l);
//    l = cons(mkconstant(3), l);
//    l = cons(mkconstant(2), l);
//    e1 = mkopapp(isplus, l);
//
//    l = NULL;
//    l = cons(mkvar("x"), l);
//    l = cons(mkvar("x"), l);
//    e3 = mkopapp(isplus, l);
//    l = NULL;
//    l = cons(e3, l);
//    l = cons(mkvar("x"), l);
//    l = cons(mkvar("x"), l);
//    e2 = mkopapp(ismult, l);
//
//    e1 = mklet("x", e1, e2);
//
//    printf("%d\n", evalexp(e1)); // should print  2000

//    struct exp *e1 ,*e2, *e3;
//    struct explist *l;
//
//    l = NULL;
//    l = cons(mkvar("y"), l);
//    e2 = mklet("x",mkconstant(10) , mkvar("x"));
//    l = cons(e2, l);
//    l = cons(mkvar("y"), l);
//    e3 = mkopapp(isplus, l);
//    e1 = mklet("y",mkconstant(2) , e3);
//
//    printf("%d\n", evalexp(e1)); // should print  14

//    struct exp *e1 ,*e2;
//    struct explist *l, *l2;
//
//    l = NULL;
//    l = cons(mkconstant(4), l);
//    l = cons(mkconstant(2), l);
//    l = cons(mkconstant(1), l);
//    e1 = mkopapp(ismult, l);
//
//    l = NULL;
//    l = cons(mkconstant(3), l);
//    l = cons(mkconstant(3), l);
//
//    l2 = NULL;
//    l2 = cons(mkconstant(2), l2);
//    l2 = cons(mkconstant(1), l2);
//    l2 = cons(mkconstant(3), l2);
//    e2 = mkopapp(ismult, l2);
//
//    l = cons(e2, l);
//    l = cons(mkconstant(1), l);
//    e2 = mkopapp(isplus, l);
//
//    l2 = NULL;
//    l2 = cons(e1, l2);
//    l2 = cons(e2, l2);
//    l2 = cons(mkconstant(2), l2);
//    l2 = cons(mkconstant(2), l2);
//    l2 = cons(mkconstant(5), l2);
//    e2 = mkopapp(isplus, l2);
//
//    printf("%d\n", evalexp(e2)); //should print 30

//
//    struct exp *e1, *e2,*e3;
//    struct explist *l;
//
//    l = NULL;
//    l = cons(mkvar("x"), l);
//    l = cons(mkvar("y"), l);
//    e3 = mkopapp(isplus, l);
//
//    e1 = mklet("x", mkconstant(2), mkvar("x"));
//    e2 = mklet("y", mkvar("x"),e3);
//    e3 = mklet("x",e1,e2);
//
//    printf("%d\n", evalexp(e3)); // should print  4

    int n = 10;
    int *p1 = &n;
    int *p2 = p1;
    *p2 = *p1 + 1;
    printf("%d\n", n);

    return 0;
}



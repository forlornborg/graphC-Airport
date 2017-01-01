#ifndef __graph_h__
#define __graph_h__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Graph struct */
typedef struct __vertexType vertex;
struct __vertexType{
    char *label; //APC
};

typedef vertex airport;

typedef struct __arcType arc;
struct __arcType{
    char *label; //Flight
    vertex *head;
    vertex *tail;
    int startTime;
    int endTime;
    int cost;
};

typedef arc flight;


/* end Graph struct */

/* LL struct */
typedef struct __nodeTypeVertex Vnode;
struct __nodeTypeVertex{
    vertex* e; //element of Node
    Vnode *next;
};
typedef struct __nodeTypeArc Anode;
struct __nodeTypeArc{
    arc* e;
    Anode *next;
};

typedef struct __linkedListTypeVertex Vll;
struct __linkedListTypeVertex{
    Vnode *head;
    Vnode *tail;
};

typedef struct __linkedListTypeArc All;
struct __linkedListTypeArc{
    Anode *head;
    Anode *tail;
};
/*end LL struct */

typedef struct __graphType graph;
struct __graphType{
    Vll *V;
    All *A;
};

Vnode *VnodeConstructor(vertex *);
Vll *VllConstructor();
Vnode *VllFind(Vll *, vertex *);
vertex *vertexConstructor(char *);
void VllPrint(Vll *);
void VllAppend(Vll *, Vnode *);
All *AllConstructor();
Anode *AnodeConstructor(arc *);
arc *arcConstructor(vertex *, vertex *, int, int, int);
void AllPrint(All *);
void AllAppend(All *, Anode *);
Anode *AllFind(All *, arc *);

graph *graphConstructor();
void addVertex (graph *, char *);
void addArc(graph *, char *, char *,int, int, int);

#endif
#ifndef __struct_h__
#define __struct_h__

//structure of graph
/*
graph D will be a LL of V and a LL of A

a vertex can be labeled (APC)
an arc can be labeled (Flight)

*/


/* LL struct */
typedef struct __nodeTypeVertex Vnode;
struct __nodeTypeVertex{
    vertex* e; //element of Node
    Vnode *next;
};
typedef struct __nodeTypeArc Anode;
struct __nodeTypeArc{
    arc* a;
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

Vnode *nodeConstructor(Vll *, vertex *);
Vll *llConstructor();
Vnode *llFind(Vll *, vertex *);



#endif
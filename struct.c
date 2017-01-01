/*
problems: how can e hold both vertexes and arcs
    for now I will create two linked lists
*/
#include "graph.h"
/*VLL Code */

void VllPrint(Vll *list){
    //done
    Vnode *temp = list->head;
    while(temp != NULL){
        printf("%s\n", temp->e->label);
        temp = temp->next;
    }
    return;
}

void VllAppend(Vll *list, Vnode* nodeToAdd){
    //done
    /*Add to end of ll
    for adding to V and A*/
    if(list->head == NULL){
        list->head = nodeToAdd;
        list->tail = nodeToAdd;
        return;
    }else{
        list->tail->next = nodeToAdd;
        list->tail = list->tail->next;
    }
}

void VllRemove(){
/*
 //not necessary
*/
}

void VnodeDestroy(Vnode *nodeToDestroy){
    //not done
    //free(nodeToDestroy->e);
    free(nodeToDestroy);
    return;
}

void VllDestroy(Vll *list){
    //not done
    return;
}

Vnode *VllFind(Vll *list, vertex *e){
    /*
    make index named temp
    while temp doesn't point to the end
        if temp contains the e, return it
    else
        move temp forwards
    return NULL if nothing is found
    */
    Vnode *temp = list->head;
    while(temp != NULL){
        if(strcmp(temp->e->label, e->label) == 0){
            return temp;
        }else{
            temp = temp->next;
        }
    }
    VnodeDestroy(temp);
    return NULL; //return NULL if not in list
}

Vnode *VnodeConstructor(vertex *e){
    Vnode *N = (Vnode *)malloc(sizeof(Vnode));
    N->e = e;
    N->next = NULL;
    return N;
}

Vll *VllConstructor(){
    Vll *L = (Vll *)malloc(sizeof(Vll));
    L->head = NULL;
    L->tail = NULL;
    return L;
}
/*end VLL code*/

/*VLL Code */

int Acomparator(Anode n, Anode m){
    /*for appending in order*/
}

void AllPrint(All *list){
    //done
    Anode *temp = list->head;
    while(temp != NULL){
        printf("head: %s\n", temp->e->head->label);
        printf("tail: %s\n", temp->e->tail->label);
        temp = temp->next;
    }
    return;
}

void AllAppend(All *list, Anode* nodeToAdd){
    //done
    /*Add to end of ll
    for adding to V and A*/
    if(list->head == NULL){
        list->head = nodeToAdd;
        list->tail = nodeToAdd;
        return;
    }else{
        list->tail->next = nodeToAdd;
        list->tail = list->tail->next;
    }
}

void AllRemove(){
/*
 //not necessary
*/
}

void AnodeDestroy(Anode *nodeToDestroy){
    //not done
    //free(nodeToDestroy->e);
    free(nodeToDestroy);
    return;
}

void AllDestroy(All *list){
    //not done
    return;
}

Anode *AllFind(All *list, arc *e){
    /*
    make index named temp
    while temp doesn't point to the end
        if temp contains the e, return it
    else
        move temp forwards
    return NULL if nothing is found
    */
    Anode *temp = list->head;
    while(temp != NULL){
        if(temp->e->head->label == e->head->label && temp->e->tail->label == e->tail->label){
            return temp;
        }else{
            temp = temp->next;
        }
    }
    AnodeDestroy(temp);
    return NULL; //return NULL if not in list
}

Anode *AnodeConstructor(arc *e){
    Anode *N = (Anode *)malloc(sizeof(Anode));
    N->e = e;
    N->next = NULL;
    return N;
}

All *AllConstructor(){
    All *L = (All *)malloc(sizeof(All));
    L->head = NULL;
    L->tail = NULL;
    return L;
}
/*end ALL code*/

/*graph code*/
graph *graphConstructor(){
    graph *G = (graph *)malloc(sizeof(graph));
    G->V = VllConstructor();
    G->A = AllConstructor();
    return G;
}
arc *arcConstructor(vertex *head, vertex* tail, int startTime, int endTime, int cost){
    arc *A = (arc *)malloc(sizeof(arc));
    A->head = head;
    A->tail = tail;
    A->startTime = startTime;
    A->endTime = endTime;
    A->cost = cost;
    return A;
}
vertex *vertexConstructor(char *label){
    vertex *Vt = (vertex *)malloc(sizeof(vertex));
    Vt->label = label;
    return Vt;
}

void graphDestroy(graph *g){
    VllDestroy(g->V);
    //AllDestroy(g->A);
    free(g);
}

void addVertex(graph *g, char *label){
    vertex *vertexTemp = vertexConstructor(label);
    Vnode *VnodeTemp = VnodeConstructor(vertexTemp);
    Vnode *isPrevious = VllFind(g->V, vertexTemp);
    if(isPrevious != NULL){
        return;
    }else{
        VllAppend(g->V, VnodeTemp);
    }
    return;
}

void addArc(graph *g, char *head, char *tail, int startTime, int endTime, int cost){
    vertex *v1 = vertexConstructor(head);
    vertex *v2 = vertexConstructor(tail);
    Vnode *v1Node = VnodeConstructor(v1);
    Vnode *v2Node = VnodeConstructor(v2);
    if(!VllFind(g->V,v1)){
        VllAppend(g->V,v1Node);
    }
    if(!VllFind(g->V,v2)){
        VllAppend(g->V,v2Node);
    }
    arc *arcTemp = arcConstructor(v1, v2, startTime, endTime, cost);
    Anode *AnodeTemp = AnodeConstructor(arcTemp);
    Anode *isPrevious = AllFind(g->A, arcTemp);
    if(isPrevious != NULL){
    }else{
        AllAppend(g->A, AnodeTemp);
    }
    return;
}

int getEdgeFrom(graph *g, char *head){;
    int didPrint;
    Anode *temp = g->A->head;
    while(temp != NULL){
        if(strcmp(temp->e->head->label, head) == 0){
            didPrint = 1;
            printf("-- Flights to %s start:%d end:%d cost:%d\n", temp->e->tail->label, temp->e->startTime, temp->e->endTime, temp->e->cost);
        }
        temp = temp->next;
    }
    AnodeDestroy(temp);
    return didPrint; //return NULL if not in list
}

void printFromEdges(graph *g, char *label){
    vertex *vertexTemp = vertexConstructor(label);
    if(!VllFind(g->V, vertexTemp)){
        printf("Airport %s Not Found\n",label);
        return;
    }
    printf("Flights From %s\n",label);
    if(!getEdgeFrom(g, label)){
        printf("-- No Flights\n ");
    }
    printf(" ");
}

void printAllFromEdges(graph *g){
    if(g->V->head == NULL){
        printf("Network Is Empty\n");
    }
    Vnode *Vtemp = g->V->head;
    while(Vtemp != NULL){
        printFromEdges(g, Vtemp->e->label);
        Vtemp = Vtemp->next;
    }
}


/*end graph code*/
 #include "graph.h"
 #define MAXSTRING 3

 int main(){
     graph *graphMaster = graphConstructor();
     char command[81];
     while(scanf("%s", command) > 0){
         if(strcmp(command, "Flight") == 0){
             char *to = malloc(sizeof(char) * MAXSTRING);
             char *from = malloc(sizeof(char) * MAXSTRING);
             int startTime = 555;
             int endTime = 555;
             int cost = 444;
             scanf("%s %s %d %d %d", to, from, &startTime, &endTime, &cost);
             addArc(graphMaster, to, from, startTime, endTime, cost);
         }if(strcmp(command, "List") == 0){
             char *APC = malloc(sizeof(char) * MAXSTRING);
             scanf("%s",APC);
             if(strcmp(APC,"*") == 0){
                 printAllFromEdges(graphMaster);
             }else{
                printFromEdges(graphMaster, APC);
             }
         }
     }
      return 0;
}
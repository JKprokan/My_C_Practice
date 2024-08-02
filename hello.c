#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int t,x1,y1,x2,y2,r1,r2,i;
    int res = 0; 
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
        double dis = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
        int sum = r1+r2;
        int dif = abs(r1-r2);
        if (dis == 0 && r1 == r2){
            res = -1;
        }
        else if (dis == sum || dis == dif){
            res = 1;
        }   
        else if (dis < sum && dif < dis){
            res = 2;
        }
        else res = 0;
        printf("%d\n",res);
    }
    return 0;
}


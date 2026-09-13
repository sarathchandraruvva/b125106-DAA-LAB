#include<stdio.h>
#include<stdlib.h>
#define INFO 99999
int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a<b)?a:b;
}
int eggdrop(int eggs,int floors){
    int **dp;
    int e,f,x;
    dp = (int**)malloc((eggs+1)*sizeof(int*));
    for(e=0;e<=eggs;e++){
        dp[e]=(int*)malloc((floors+1)*sizeof(int));
    }
    for(e=1;e<=eggs;e++){
        dp[e][0]=0;
        if(floors>=1){
            dp[e][1]=1;
        }
    }
    for(f=0;f<=floors;f++){
        dp[1][f]=f;
    }
    for(e=2;e<=eggs;e++){
        for(f=2;f<=floors;f++){
            dp[e][f]=INFO;
            for(x=1;x<=f;x++){
                int eggbreaks;
                int egg_notbreaks;
                int worstcase;
                int attempts;
                eggbreaks = dp[e-1][x-1];
                egg_notbreaks = dp[e][f-x];
                worstcase = max(eggbreaks,egg_notbreaks);
                attempts = 1 + worstcase;
                dp[e][f]=min(dp[e][f],attempts);
            }
        }
    }
    int answer = dp[eggs][floors];
    for(e=0;e<=eggs;e++){
        free(dp[e]);
    }
    free (dp);
    return answer;
}
int main(){
    int eggs,floors,result;
    printf("Enter the number of eggs : \n");
    scanf("%d",&eggs);
    printf("Enter the number of floors : \n");
    scanf("%d",&floors);
    if(eggs==0||floors==0){
        printf("Invalid input\n");
        return 1;
    }
    result = eggdrop(eggs,floors);
    printf("Minimum number of droppings required = %d\n",result);
    return 0;
}
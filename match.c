#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "score.c"
#include "result.c"

int a,b,score;

int bat(int target){
    score=0;
    printf("\n \t Start Batting.. \n");
    while(1){
        printf("Enter number:");
        scanf("%d",&a);

        if(a>10){
            printf("Hit wicket for %d runs.\n",score);
            insert(score);
            if(target!=-1){
                if(target==score){
                    printf("\t Match drawn. \n");
                    push('D');
                }else{
                    printf("\t Computer won by %d runs. \n",target-score);
                    push('L');
                }
            }
            return score;
        }

        b=rand()%11;

        if(a==b){
            printf("Well played innings of %d runs.\n",score);
            insert(score);
            if(target!=-1){
                if(target==score){
                    printf("\t Match drawn. \n");
                    push('D');
                }else{
                    printf("\t Computer won by %d runs. \n",target-score);
                    push('L');
                }
            }
            return score;
        }else if(a==0 && b!=0){
            score+=b;
            printf("%d runs \t You: %d runs. \n",b,score);
        }else{
            score+=a;
            printf("%d runs \t You: %d runs. \n",a,score);
        }

        if(target>-1){
            if(score>target){
                printf("\t\t You won the match.\n");
                insert(score);
                push('W');
                return score;
            }else{
                printf("You need %d more runs to win\n",target-score+1);
            }
        }
    }
}

int bowl(int target){
    score=0;
    printf("\n \t Start Bowling.. \n");
    while(1){
        printf("Enter number:");
        scanf("%d",&a);
        if(a>10){
            b=rand()%11;
            score+=b;
            if(target!=-1 && score>target){
                printf("Computer won the match.\n");
                push('L');
                return score;
            }
            printf("%d runs \t Computer: %d runs. \n",b,score);
            printf("The bowler overstepped the line and it is NO-Ball.\n");
            printf("Free-hit delivery Coming Up.\n");
            b=rand()%11;
            score+=b;
            printf("%d runs \t Computer: %d runs. \n",b,score);
        }

        b=rand()%11;

        if(a==b){
            printf("Bowled him for %d runs.\n",score);
            if(target!=-1){
                if(target==score){
                    printf("\t Match drawn. \n");
                    push('D');
                }else{
                    printf("\t You won by %d runs. \n",target-score);
                    push('W');

                }
            }
            return score;
        }else if(b==0 && a!=0){
            score+=a;
            printf("%d runs \t Computer: %d \n",a,score);
        }else{
            score+=b;
            printf("%d runs \t Computer: %d \n",b,score);
        }

         if(target>-1){
            if(score>target){
                printf("\t\t Computer won the match.\n");
                push('L');
                return score;
            }else{
                printf("Computer need %d more runs to win\n",target-score+1);
            }
        }
    }
}

int toss(){
    printf("\n It\'s Toss time..\n");
    printf("Make your call(1.Head 2.Tail): ");
    scanf("%d",&a);
    b=rand()%2+1;
    if(a==b){
        printf("\nYou won the toss. Make your decision (1.Bat 2.Bowl) : ");
        scanf("%d",&a);
        if(a==1){
            return 1;
        }else{
            return 0;
        }
    }else{
        b=rand()%2+1;
        if(b==1){
            printf("\n Computer have won the toss and elected to bowl first");
            return 1;
        }else{
            printf("\n Computer have won the toss and elected to bat first");
            return 0;
        }
    }
}

void match(){
    printf("\n\n\t\t Welcome to Hand - Cricket Game \n\n");
    int cs,ps;
    if(toss()){
        ps=bat(-1);
        cs=bowl(ps);
    }else{
        cs=bowl(-1);
        ps=bat(cs);
    }
    printf("\n\t\t  Thank you for playing \n");
}


void main(){
    header h;
    stack s;
    create();
    createstack();
    int ch;
    do{
        match();
        printf("Do you want to play again(1.Yes 2.No): ");
        scanf("%d",&ch);
    }while(ch==1);
    scorehistory();
    form();
    printf("High Score: %d",highscore());
}

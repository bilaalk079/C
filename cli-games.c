#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
     int option = 0;
     printf("Select an option, 1 - No. guessing game, 2 - rps: ");
     scanf("%d", &option);

     srand(time(NULL));


     if(option == 1){
          printf("********NUMBER GUESSING GAME*********\n");

          int min = 1;
          int max = 10;
          int user_input = 0;
          int number_of_tries = 1;
          int answer = rand() % (max - min + 1) + min;
          
          while(1){
               printf("Guess a Number between 1- 10: ");
               scanf("%d",  &user_input);

               if(user_input != answer){
                    printf(user_input > answer ? "Too high\n" : user_input < answer ? "Too low\n" : "\0");
                    number_of_tries++;
               }
               else{
                    printf("You got it right....after %d trials.\n",  number_of_tries);
                    printf(number_of_tries <= 3 ? "Excellent Performance\n" : number_of_tries <= 6 && number_of_tries > 3  ? "Average Performance\n" :  "Poor Performance\n");
                    break;
               }
          }
     }else if(option == 2){
          printf("ROCK, PAPER, SCISSORS\n");

          int rps_index = (rand() % 3) + 1;
          int user_option = 0;

        const char* rps_option = rps_index == 1 ? "ROCK" :  rps_index == 2 ? "PAPER" : "SCISSORS";
          const char* user_opt;

          while(1){
               printf("Select an option, 1 - ROCK, 2 -PAPER, 3 - SCISSORS: ");
               scanf("%d", &user_option) ;

               if(user_option > 3 || user_option < 1){
                    printf("Invalid Option\n");
               }
               else{
                    user_opt = user_option == 1 ?  "ROCK" :  user_option == 2 ? "PAPER" : "SCISSORS";
                    break;
               }
          }
          if(user_option == rps_index){
               printf("Draw\n");
          }
          else if((user_option == 3 && rps_index == 2) || (user_option == 1 && rps_index == 3) || (user_option == 2 && rps_index == 1)){
               printf("You Won\n");
          }
          else{
               printf("You Lost\n");
          }

          printf("Computer chose %s\nYou chose %s\n", rps_option, user_opt);
     }
     else{ 
          printf("Invalid Option");
     }
     return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

void move_motors(float speed){
     if(speed < 10){
          printf("Bot would soon stop, current speed is %.2f RPM\n", speed);
     }
     else{
          printf("Bot moving at %.2f RPM\n", speed);
     }
};

int check_sensors(){
     int sensor_value;
     bool isRunning = true;
     printf("Input your sensor value: ");
     scanf("%d", &sensor_value);
     while(isRunning){
          if(sensor_value != 0 && sensor_value != 1){
               printf("Invalid sensor Value\n");
               printf("Input your sensor value: ");
                scanf("%d", &sensor_value);
          }
          else{
               break;
          }
     }
     return sensor_value;
};
void search_routine(){
     float speed_initial = 100;
     float speed_decay = 0.8;
     for(int i = 0; i < 60; i++){
          int value = check_sensors();
          if(value == 1){
               printf("Line Found\n");
               break;
          }
          float current_speed;

          current_speed = speed_initial * speed_decay;
          speed_initial = current_speed;
          if(current_speed > 10){
               printf("Still Searching....");
          }
          move_motors(current_speed);
          if(current_speed < 0.1){
               printf("Bot Has stopped searching in order to save battery\n");
               break;
          }
     }
}
int main(){
     search_routine();
     return 0;
}
#include <stdio.h>
#include <wiringPi.h>
#include <time.h>
int main(){
wiringPiSetup();
FILE *fpoint;
time_t timestamp;
time(&timestamp);
int sensor  = 0;
int led  = 2;
pinMode(led, OUTPUT);
pinMode(sensor, INPUT);//pull down
pullUpDnControl(sensor, PUD_DOWN);

for(;;){
if(digitalRead(sensor) == 1){
time(&timestamp);
fpoint = fopen("log.txt", "a");
fprintf(fpoint, "Intruder detected at..");
fprintf(fpoint, "%s\n", ctime(&timestamp));
printf("INTRUDER ALERT!\n");
delay(5000);
fclose(fpoint);
}
}
return(0);
}

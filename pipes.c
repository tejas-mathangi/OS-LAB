#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    int pid;
    int fd[2];
    char wrt_msg[] = "Hi from parent!";
    char rd_msg[50];

    if(pipe(fd)==-1){
        perror("pipe failed");
        exit(1);
    }
    
    pid = fork();

    if(pid > 0){
        close(fd[0]);
        printf("Message sent from parent\n");
        write(fd[1],wrt_msg,sizeof(wrt_msg));
        close(fd[1]);
    }else{
        close(fd[1]);
        read(fd[0],rd_msg,sizeof(rd_msg));
        printf("Child recieved message! --> %s",rd_msg);
        close(fd[0]);
    }
    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i;

    for(i = 0; i < 3; i++) {
        pid_t pid = fork();

        if(pid == 0) {
            printf("Child %d: PID = %d\n", i, getpid());
            return 0;
        }
    }

    for(i = 0; i < 3; i++) {
        wait(NULL);
    }

    printf("All done\n");

    return 0;
}

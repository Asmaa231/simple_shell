#include "shell.h"

/**
 *  main *execv Command Example
 * 
 * Return: Always 0 
*/
int main(void){
    char *argv[] = {"bin/ls", "/user/", NULL};
    printf("Before execv\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execv\n");
    return (0);
}
/**
 * _myexit - this function will be used in order to exit the shell
 * @intel:The structure which will be holding the expected arguments for a Constant function prototype
 * Return: exits with a given statement shows the status of the shell
*/
int _myexit(info_t *intel){
    int exitcheckers:
    if (intel-> argv [1]) /* This is just to find out if there is an exit argument*/
    {
        exitcheckers = erratoi(intel->argv[1]);
        if (exitcheckers == -1)
        {
            intel->status = 2; /* This is just to indicate the exit statemnet if there is an illegal statement*/
            print_error(intel, "Illegal Number:");
            _eputs(intel->argv[1]);
            _eputchar("\n");
            return (1);
        }
        intel->err num = erratoi(intel->argv[1]);
        return (-2) /* Indicates that the shell should exit with a given exit statement*/
    }
    intel->err num = -1 /* Unspecified error*/
    return (-2);
}
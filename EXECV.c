#include "shell.h"

/**
*  main *execv Command Example
*
* Return: Always 0
*/
int main(void)
{
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
 * @intel:The structure holds expected arguments for a Constant function
 * Return: exits with a given statement shows the status of the shell
*/
int _myexit(info_t *intel)
{
int exit_status:
if (intel->argv[1]) /* This is to find out if there is an exit argument*/
{
exit_status = atoi(intel->argv[1]);
if (exit_status == 0)
{
intel->status = -2; /*indicates the exit statemnet if it's illegal statement*/
/*Assuming print_error and _eputs are defined and handle error printing
_eputs are defined and handle error printing*/
print_error(intel, "Illegal Number:");
_eputs(intel->argv[1]);
_eputchar("\n");
return (1);/*Indicates an error condition*/
}
intel->errnum = exit_status;
return (exit_status); /* Return the exit status*/
}
intel->errnum = -1 /* Unspecified error*/
return (-1); /*Indicates an error condition*/
}
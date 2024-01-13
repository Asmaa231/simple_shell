#include "shell.h"
/**
 * getenv - It's a Function used to fetch an evironment variable
 * @info: The structure holds expected arguments , maintain a Constant Func
 * @sin: The Environment variable name
 * Return: It is going to be the Variable Value 
*/
char *getenv(info_t *info, const char *sin)
{
list_t *node = info->env;
char *g;
while (node)
{
g = starts_with(node->str, sin);
if (g && *g)
return (g);
node = node -> next;
}
return (NULL);
}
/**
 * _setenv - It is being used to give the ability in order to be able to modify the Enviroment Variable such as Change or add.
 * @info: The structure that will be holding an expected arguments to maintain a Constant Func Prototype
 * @jo: The String Variable of the enironment.
 * @res: The Value of the environment string variable
 * Return: Always 0
*/
int _setenv(info_t *info, char *jo, char *res )
{
char *bur = NULL;
list_t *node;
char *t; 
if (!jo || !res) {
return (0);
}
bur = malloc(_strlen(jo) +_strlen(res) +2);
if (!bur) {
return (1);
}
_strcpy(bur, jo);
_strcat(bur,"=");
_strcat(bur, res);
node = info->env;
while (node){
t = starts_with(node->str, jo);
if (t && *t == '='){
free(node->str); // Free the existing string before assigning the new one
node->str = bur;
info->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(info->env), bur, 0);
free(bur);
info->env_changed = 1;
return (0);      
}
/**
 * _unsetenv- This Function is used to delete a Variable from the Eniroment.
 *@info: The structure that will be holding an expected arguments to maintain a Constant Func Prototype
 *return:   on success or -1 on error cases 
*/
int _unsetenv(info_t *info, char *jo)
{
list_t *node = info->env;
size_t n = 0;
char *r;
while (node)
{
r = starts_with(node->str, jo);
if (r &&*r == '=')
{
info->env_changed = delete_node_at_index(&(info->env), n);
n =0;
node = info->env;
continue;
}
node = node->next;
n++;
}
return (info->env_changed);
}
/**
 * _mysetenv - This Function is being used in order to create or initialize a new Environemt Variable
 * @tango: The structure which will be holding the expected arguments
 * Return:  0 indicates that the environment variable name was successfully set to the value 
*/
int _mysetenv(info_t *tango){
if (tango->argc != 3){
_eputs("The Number of Arguments is not accurate");
return (1); //Return 1 for Failure
}
if (_setenv(tango, tango->argv[1], tango->argv[2], 1) !=0){
return (1); //Return 1 for Failure
}
return (0); //Return 0 for Success
}
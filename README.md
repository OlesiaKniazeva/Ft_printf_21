# Ft_printf
`Ft_printf`, a function that mimics the real printf function.  
Program name
`libftprintf.a`

## Description
Task was to recode printf function.

It manages the following conversions: `cspdiuxX%`

• `%c` print a single character.  
• `%s` print a string of characters.  
• `%p` The void * pointer argument is printed in hexadecimal.  
• `%d` print a decimal (base 10) number.  
• `%i` print an integer in base 10.  
• `%u` print an unsigned decimal (base 10) number.  
• `%x` print a number in hexadecimal (base 16), with lowercase.  
• `%X` print a number in hexadecimal (base 16), with uppercase.  
• `%%` print a percent sign.  

Also it manages any combination of the following flags: `-0.` and minimum field width with all conversions.

File `main.c` contains some examples that shows how my ft_printf works.

To compile:
1. git clone `git@github.com:Ollietani/Push_swap_21.git`
2. run `make`

Example:

```c
int main()
{
	printf("%d\n",	printf("|%12.*s|", -20, "hello"));
	printf("%d\n",	ft_printf("|%12.*s|", -20, "hello"));
		printf("-------\n");
	printf("%d\n",	printf ("|%*s|", 10, "libfta"));
	printf("%d\n",	ft_printf ("|%*s|", 10, "libfta"));
		printf("-------\n");
	char *c = "cat";
	printf("%d\n",  printf ("|%p|", c));
	printf("%d\n",  ft_printf ("|%p|", c));
		printf("-------\n");
	printf("%d\n",  printf ("|%8.5d|", 8375));
	printf("%d\n",  ft_printf ("|%8.5d|", 8375));
		printf("-------\n");
   	printf("%d\n",  printf ("|%13.12u|", 345));
	printf("%d\n",  ft_printf ("|%13.12u|", 345));
		printf("-------\n");
	printf("%d\n",  printf ("|%.2x|", 345999));
	printf("%d\n",  ft_printf ("|%.2x|", 345999));
	   	printf("-------\n");
	printf("%d\n",  printf ("|%56.7x|", 12345));
	printf("%d\n",  ft_printf ("|%56.7x|", 12345));	   
		printf("-------\n");
	printf("%d\n",  printf ("|%-12X|", 345));
	printf("%d\n",  ft_printf ("|%-12X|", 345));
		printf("-------\n");
	printf("%d\n",  printf ("|%05.6d|", 345));
	printf("%d\n",  ft_printf ("|%05.6d|", 345));

		printf("%d\n",  printf ("|%05%%.6d|", 345));
		printf("%d\n",  ft_printf ("|%05%%.6d|", 345));

}
```
Output:
```
./a.out 
|       hello|14
|       hello|14
-------
|    libfta|12
|    libfta|12
-------
|0x1059b2f57|13
|0x1059b2f57|13
-------
|   08375|10
|   08375|10
-------
| 000000000345|15
| 000000000345|15
-------
|5478f|7
|5478f|7
-------
|                                                 0003039|58
|                                                 0003039|58
-------
|159         |14
|159         |14
-------
|000345|8
|000345|8
|0000%000345|13
|0000%000345|13
```

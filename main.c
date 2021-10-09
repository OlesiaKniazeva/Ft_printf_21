#include "includes/ft_printf.h"

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
}
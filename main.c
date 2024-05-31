/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:56:42 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/05/28 19:31:44 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int MAXLINE = 1024;
char prompt[] = "lnsh> "; //command line prompt

int	main(int argc, char **argv)
{
	char cmdline[MAXLINE]; //buffer for fgets

	while(1)
	{
		printf("%s", prompt);
		if ((fgets(cmdline, MAXLINE, stdin) == NULL) && ferror(stdin))
			error("fgets error");

		if (feof(stdin))
		{
			printf("\n");
			exit(0);
		}

		//remove trailing newline
		cmdline[strlen(cmdline)=1] = '\0';

		//evaluate command line
		eval(cmdline);
	}
}

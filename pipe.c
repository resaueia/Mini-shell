/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:14:09 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/05/31 17:24:05 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* pipe dup fork and exec eggs
 runs as: ./a.out date wc
 runs the shell equivalent of date | wc */

int main(int argc, char *argv)
{
	int pipefd[2], status, done = 0;
	pid_t cpid;

	pipe(pipefd);

	cpid = fork();
	if (cpid == 0) // left child (for left cmd of pipe)
	{
		close(pipefd[0]); // Close unused read end
		dup2(pipefd[1], STDOUT_FILENO); // Make output go to pipe
		execlp(argv[1], argv[1], (char *) NULL;
	}
	cpid = fork();
	if (cpid == 0) // right child (for right cmd of pipe)
	{
		close(pipefd[1]); // Close unused write end
		dup2(pipefd[0], STDIN_FILENO); // Get input from pipe
		execlp(argv[2], argv[2], (char *) NULL;
	}
	close(pipefd[0]); // close pipes so EOF(end of file) can work
	close(pipefd[1]); /* This is a subtle yet important step. The second
					   child will not receive a EOF to trigger it to terminate
					   while at least one other process (the parent) has the
					   write end open */

	// Parent reaps children exits
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:00:46 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/05/29 20:01:02 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

int main() {
    char *input; // Ponteiro para armazenar a entrada do usuário

    // Lê uma linha de entrada do terminal
    input = readline("Digite algo: ");

    // Verifica se a entrada não é nula
    if (input != NULL) {
        // Imprime a linha de entrada
        printf("Você digitou: %s\n", input);

        // Libera a memória alocada para a linha de entrada
        free(input);
    }

    return 0;
}


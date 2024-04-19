/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:51:23 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:48:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "token.h"

void	print_command(t_cmds *cmds)
{
	int			i;
	t_redirs	*rd;

	ft_printf("[\n");
	while (cmds != NULL)
	{
		ft_printf("\t[\n");
		ft_printf("\tpipe type = %d\n", cmds->t);
		ft_printf("\targs = {");
		i = 0;
		while (cmds->args != NULL && cmds->args[i] != NULL)
		{
			ft_printf("%s", cmds->args[i++]);
			if (cmds->args[i] != NULL)
				ft_printf(", ");
		}
		ft_printf("}\n");
		rd = cmds->rd_arr;
		while (rd != NULL)
		{
			ft_printf("\trd type     : %d\n", rd->t);
			ft_printf("\trd filename : %s\n", rd->file_name);
			rd = rd->next;
		}
		ft_printf("\t]\n");
		cmds = cmds->next;
	}
	ft_printf("]\n");
}

t_cmds	*parse_command(char *arg, char **envp)
{
	t_token	*tokens;
	t_cmds	*cmds;

	tokens = lexer(arg);
	if (tokens == NULL)
		return (NULL);
	if (!syntax_analyzer(tokens))
		return (free_tokens(&tokens), NULL);
	if (!expander(tokens, envp))
		return (free_tokens(&tokens), NULL);
	print_token_list(tokens);
	cmds = parser(tokens);
	if (cmds == NULL)
		return (free_tokens(&tokens), NULL);
	print_command(cmds);
	free_tokens(&tokens);
	return (cmds);
}

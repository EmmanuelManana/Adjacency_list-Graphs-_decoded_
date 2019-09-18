/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:53:57 by emanana           #+#    #+#             */
/*   Updated: 2019/09/01 20:46:38 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct 		t_struct
{
	int				vn;
	struct t_struct *next;
} 					t_node;	

typedef struct		t_struct2
{
	t_node          *head;
}					t_list;

void 				addVertex(int a, int b, t_list **adjacent_list)
{
	t_node *temp;
	t_node *first;
	t_node *last;
		
	if (adjacent_list[a]->head == NULL)
	{
		
		first = (t_node*)malloc(sizeof(t_node) * 1);
		first->vn = a;
		first->next = NULL;
		adjacent_list[a]->head = first;
	}
	
	last = (t_node*)malloc(sizeof(t_node) * 1);
	last->vn = b;
	last->next = NULL;

	temp = adjacent_list[a]->head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}	
	temp->next = last;
}

int					main(void)
{
	t_list  *adjacent_list[5] = {0};
	int		vertexNumber;
	int		i;

	vertexNumber = 5;
	i = 0;
	while (i < vertexNumber)
	{
		adjacent_list[i] = (t_list*)malloc(sizeof(t_list) * 1);
		i++;
	}
	/*manually adding: the vertex and edges  G = (v, E); */

	/* adding edges to the first vertex*/
	addVertex(0, 1, adjacent_list);
	addVertex(0, 3, adjacent_list);

	/* adding edges to the second vertex*/
	addVertex(1, 2, adjacent_list);
	addVertex(1, 3, adjacent_list);

	/* adding edges to the third vertex*/
	 addVertex(2, 0, adjacent_list);
	 addVertex(2, 1, adjacent_list);
	 addVertex(2, 4, adjacent_list);

	 /* adding edge to the fourth vertex */
	  addVertex(3, 0, adjacent_list);
	  addVertex(3, 3, adjacent_list);
	  
	  /*adding the edges to the 5th vertex*/ 
	   addVertex(4, 0, adjacent_list);


	/*print the hash/graph */
	int j;

	j = 0;
	while (j < vertexNumber)
	{
		t_node *p = adjacent_list[j]->head;
		printf("adjacency list for vertex %d\n", j);
		while (p)
		{
			printf("%d-", p->vn);
			p = p->next;
		}
		printf("\n");
		j++;
	}
	return (0);
}

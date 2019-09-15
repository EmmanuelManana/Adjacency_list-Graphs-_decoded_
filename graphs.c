#include <unistd.h>
#include <stdio.h>


typedef struct 		s_struct
{
	int				v;/*vert*/
	struct s_struct	*next;
}					t_node;/* anode is a vertex in a graph of vertices(more than vertex)*/

typedef struct 		s_graph
{
	int				numVertices/*the number of vertices(plural for vertex)in a graph*/
	t_node 			**adjLists;/*an array of linked list defines a graph structure*/
}					t_graph;

/* dont be intimidated by t_node** or **adjList
* this simply means you store a pointer to struct t_node*, 
* this is because the vertices of the graph youre creating are unknown to you
* and thus we cannot create an array of linked list at run time*/


/*create and return a new singular node*/
t_node				*new_node(int v) /* v isn the vertx number*/
{
	t_node *newNode;

	/*use ft_memalloc is cleaner*/
	newNode = (t_node*)malloc(sizeof(t_node) * 1);
	newNode->v;
	newNode->next = NULL;
	return (newNode);
}



/* create and array of linked list, a graph*/
t_graph		*createGraph(int vertices)
{
	/*create an array of linked list, size if undefined*/
	t_graph *graph;
	graph = (t_graph*)malloc(sizeof(t_graph) * 1);
	graph->numVertices = vertices;
	/*depending on the vertices to add, allocate this much memory for each vertex available*/
	graph->adjLists = (t_node**)malloc(sizeof(t_node*) * vertices);

	int i;

	i = 0;
	/*point each element(each separate vertex) of the linked list array to NULL*/
	/*this is before you can add edges*/
	while (i < vertices)
	{
		/*point all vertices to NULL(before adding edges)*/
		graph->adjLists[i] = NULL;
		i++;
	} 
	/*return a graph with vertices pointed to NULL
	* heres how it will look like if you had only 3 vertices
			[0]->NULL;
	 		 |
			[1]->NULL;
	 		 |
			[2]->NULL;
	*/
	return (graph);
}

/*add and edges to the graph*/ 
void		add_edges(t_graph *graph, int src, int dst)/* [0]->[src]->[dst]->NULL;*/
{	
	t_node *temp = new_node(dest);
	temp->next = graph->adjLists[src];
	/* you can call ft_lstadd here , Or ->*/
	graph->adjLists[dst] = temp;

	temp = new_node(src);
	/*you can also call ft_lstadd here, Or ->*/
	temp->next = graph->adjLists[dest];
	graph->adjLists[dest] = temp;	
}

/*print graph*/
void printGraph(t_graph *graph)
{
    int i = 0;
    while  (i < graph->numVertices)
    {
        t_node *temp = graph->adjLists[i];
        printf("\n Adjacency list of vertex %d\n ", i);
        while (temp)
        {
            printf("%d -> ", temp->v);
            temp = temp->next;
        }
        printf("\n");
        i++;
    }
}
int 	main(void)
{
	t_graph *graph = createGraph(3); /* create graph with 3 nodes/vertices*/
	/*add edges yo the graph*/
	add_edges(0, 2);
	add_edges(2, 1);
	add_edges(0, 2);
	add_edges(1, 0);

	printGraph(graph);
	return (0);
}

typedef struct node {
    int data;
    struct node *link;
} Node;

typedef struct descriptor {
    int size;
    Node *start;
} Descriptor;

void show_menu();
void start_linked_list(Descriptor *p);
Node *new_node(int data);
void link_node(Node *p, int size); // links all the nodes
void show_linked_list(Descriptor *p);
int restart(Descriptor *p);  // removes all the nodes
int insert(Descriptor *p, Node *new, int pos); // isert a new node in the position provided

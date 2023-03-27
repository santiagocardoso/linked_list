#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    Descriptor *desc = (Descriptor *) malloc(sizeof(Descriptor));

    int option = -1;
    while(option != 0) {
        show_menu();
        scanf("%d", &option);
        switch (option) {
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                start_linked_list(desc);
                break;
            case 2:
                show_linked_list(desc);
                break;
            case 3:
                printf("Nodes: %d\n", desc->size);
                break;
            case 4:
                if (restart(desc)) {
                    printf("List restarted!\n");
                    desc->size = 0;
                }
                else
                    printf("Operation failed!\n");
                break;
            case 5:
                if (insert(desc, new_node(333), 3))
                    printf("Node inserted!\n");
                else
                    printf("Operatioin failed!\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    }

    return 0;
}

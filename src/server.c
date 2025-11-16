#include "racing.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Pocket Racing Server starting...\n");
    
    Racer racer;
    racer_init(&racer, 1, "Player1");
    
    printf("Racer initialized: %s (ID: %d)\n", racer.name, racer.id);
    printf("Initial position: %d\n", racer_get_position(&racer));
    
    racer_update(&racer);
    printf("After update, position: %d\n", racer_get_position(&racer));
    
    printf("Server ready.\n");
    
    return 0;
}

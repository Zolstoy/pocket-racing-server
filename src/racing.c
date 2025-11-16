#include "racing.h"
#include <string.h>

void racer_init(Racer *racer, int id, const char *name) {
    racer->id = id;
    strncpy(racer->name, name, sizeof(racer->name) - 1);
    racer->name[sizeof(racer->name) - 1] = '\0';
    racer->position = 0;
    racer->speed = 100;
}

void racer_update(Racer *racer) {
    racer->position += racer->speed;
}

int racer_get_position(const Racer *racer) {
    return racer->position;
}

#ifndef RACING_H
#define RACING_H

typedef struct {
    int id;
    char name[64];
    int position;
    int speed;
} Racer;

void racer_init(Racer *racer, int id, const char *name);
void racer_update(Racer *racer);
int racer_get_position(const Racer *racer);

#endif /* RACING_H */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdbool.h>
#include <../sdl/include/SDL_mutex.h>
#include <../sdl/include/SDL_thread.h>

//#include "config.h"
#include "cbuf.h"
#include "control_msg.h"
#include "net.h"
#include "receiver.h"

struct control_msg_queue CBUF(struct control_msg, 64);

struct controller {
    socket_t control_socket;
    SDL_Thread *thread;
    SDL_mutex *mutex;
    SDL_cond *msg_cond;
    bool stopped;
    struct control_msg_queue queue;
    struct receiver receiver;
};

bool
controller_init(struct controller *controller, socket_t control_socket);

void
controller_destroy(struct controller *controller);

bool
controller_start(struct controller *controller);

void
controller_stop(struct controller *controller);

void
controller_join(struct controller *controller);

bool
controller_push_msg(struct controller *controller,
                    const struct control_msg *msg);

#endif

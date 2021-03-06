#include <assert.h>
#include <unistd.h>
#include <zmq.h>

int main(void) {
  void *context = zmq_ctx_new();
  void *responder = zmq_socket(context, ZMQ_REP);
  int rc = zmq_bind(responder, "tcp://*:5555");
  assert(rc == 0);
  while (1) {
    char buffer[10];
    zmq_recv(responder, buffer, 10, 0);
    puts("Received Hello");
    sleep(1);
    zmq_send(responder, "World", 5, 0);
  }
  return 0;
}
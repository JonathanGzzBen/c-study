#include <stdio.h>
#include <zmq.h>
int main(void) {
  puts("Connecting to hello world server...");
  void *context = zmq_ctx_new();
  void *requester = zmq_socket(context, ZMQ_REQ);
  zmq_connect(requester, "tcp://localhost:5555");

  for(int request_nbr = 0; request_nbr != 10; request_nbr++){
    char buffer[10];
    printf("Sending Hello %d...\n", request_nbr);
    zmq_send(requester, "Hello", 5, 0);
    zmq_recv(requester, buffer, 10, 0);
    printf("Recieved World %d\n", request_nbr);
  }
  zmq_close(requester);
  zmq_close(context);
}
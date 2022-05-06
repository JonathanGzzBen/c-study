#include <zmq.hpp>

#define within(num) (int) ((float) num * random() / (RAND_MAX + 1.0))

int main() {
  // Prepare context and publisher
  zmq::context_t context(1);
  zmq::socket_t publisher(context, zmq::socket_type::pub);
  publisher.bind("tcp://*:5556");
  publisher.bind("ipc://weather.ipc");

  // Initialize random number generator
  srandom((unsigned)time(nullptr));
  while(true) {
    int zipcode = within(100000);
    int temperature = within(215) - 80;
    int relhumidity = within(50) + 10;

    // Send message to all subscribers
    zmq::message_t message(20);
    snprintf((char*) message.data(), 20, "%05d %d %d", zipcode, temperature, relhumidity);
    publisher.send(message, zmq::send_flags::none);
  }
  return 0;
}
#include <stdint.h>

struct recoilfuse_state {
  uint64_t output[2];
  uint64_t a;
  uint64_t b;
  uint64_t c;
};

void recoilfuse(struct recoilfuse_state *s) {
  s->a = ((s->a << 29) | (s->a >> 35)) ^ s->b;
  s->b += 11111111111111111;
  s->output[0] = s->a + s->c;
  s->c = ((s->c << 47) | (s->c >> 17)) + s->a;
  s->output[1] = ((s->a + s->b) ^ s->a) + s->c;
}

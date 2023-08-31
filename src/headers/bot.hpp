#include <vector>

#include "car.hpp"
#include "engine.hpp"

class Bot : public Car {
 private:
  std::vector<Checkpoint> checkpoints;

 public:
  Bot();
  ~Bot();

  void pushCheckpoint(std::vector<Checkpoint> checkpoints);
  void pushCheckpoint(Checkpoint checkpoint);

  void update(Engine *pEngine);
};

#include <iostream>
#include <functional>

using namespace std;

void forLoop(int& counter, int startValue, function<bool()> condition, function<void()> onIteration, function<void()> onIterationEnd) {
  counter = startValue;
loopStart:
  if (condition()) {
    onIteration();
    onIterationEnd();

    goto loopStart;
  }
}

void whileLoop(function<bool()> condition, function<void(void)> onIteration) {
loopStart:
  if (condition()) {
    onIteration();
    goto loopStart;
  }
}

void doWhileLoop(function<bool()> condition, function<void(void)> onIteration) {
loopStart:
  onIteration();

  if (condition()) {
    goto loopStart;
  }
}

int main() {
  int i = 1;

  forLoop(i, 1, [&]()->bool { return i < 10; }, [&]() { cout << i << " "; }, [&]() { i++; });
  cout << i << "\n";

  i = 1;
  whileLoop([&]() -> bool { return i < 10; }, [&]() { cout << i++ << " "; });
  cout << i << "\n";

  i = 1;
  doWhileLoop([&]() -> bool { return i < 10; }, [&]() { cout << i++ << " "; });
  cout << i << "\n";

  return 0;
}




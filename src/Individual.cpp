#include "Individual.h"
#include <chrono>
#include <random>
Individual::Individual(int num_genes, double low_val, double hi_val)
    : genes(num_genes), fit(0.0) {
  init_genes(low_val, hi_val);
}

Individual::Individual(int num_genes) : genes(num_genes), fit(0.0) {}

void Individual::init_genes(double low_val, double hi_val) {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_real_distribution<double> distribution(low_val, hi_val);

  for (auto &g : genes) {
    g = distribution(generator);
  }
}

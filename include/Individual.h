#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>

// Class representing an individual
class Individual {
public:
  std::vector<double> genes;
  double fit;
  // Constructor that initializes random genes
  Individual(int num_genes, double low_val, double hi_val);
  // Constructor with default genes
  Individual(int num_genes);

private:
  // Function that initializes random genes in range (low, hi)
  void init_genes(double low_val, double hi_val);
};
#endif

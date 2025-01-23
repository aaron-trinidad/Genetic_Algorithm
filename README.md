# Genetic algorithm

### Overview

The algorithm presented here is a simple implementation of GA in C++.
Individuals and populations are represented as classes, and constructors are
employed to generate new populations.

Each individual's genes represent the values of parameters in a function.
Initially, these genes are assigned random values within a specified
range (0.0 to 1.0 in this case).

The goal is to maximize the result of a simple function: the sum of the squares
of each variable.
To achieve this, individuals are evaluated and ranked based on their
function results.
Individuals with the highest ranks are selected as parents for the next
generation, creating a new population.
To introduce diversity, the genes of the offspring can undergo mutation.

Executing the main program yields an optimal solution to the given problem.

CMake was used to manage the compilation process for all files.

**Important: The function used to evaluate individual ranks/fits can be adapted
to suit various problem domains. With slight modifications to the evaluate
function, this code was used to control the parameters (voltages) of an
adaptive optics instrument, which was used to compress the pulses of a
femtosecond laser.**

---

### Features

- **Population Initialization:** Random generation of individuals with
customizable properties.
- **Selection:** Fitness-based selection to choose the best individuals for
crossover.
- **Crossover:** Generation of new individuals through recombination of parents.
- **Mutation:** Random alterations to maintain diversity and avoid local optima.
- **Generational Evolution:** Iterative improvement over multiple generations.

---

### Project Structure

```yml
Genetic_Algorithm/
+-- build/              # Directory for compiled binaries.
+-- include/            # Header files.
¦   +-- Individual.h    # Definition of the Individual class.
¦   +-- Population.h    # Definition of the Population class.
+-- src/                # Source files.
¦   +-- Individual.cpp  # Implementation of the Individual class.
¦   +-- Population.cpp  # Implementation of the Population class.
¦   +-- main.cpp        # Main entry point for the algorithm.
+-- CMakeLists.txt      # Build configuration.
+-- README.md           # Project documentation.
```  

---

### Requirements  

- **C++ Standard:** C++11 or higher.  
- **Build System:** CMake.  
- **Environment:** Developed using Neovim on WSL (Windows Subsystem for Linux).

---

### Build Instructions  

1. Clone the repository:  

   ```bash
   git clone https://github.com/aaron-trinidad/Genetic_Algorithm.git
   cd Genetic_Algorithm
   ```  

2. Create a build directory:  

   ```bash
   mkdir build && cd build
   ```  

3. Run CMake to configure the project:  

   ```bash
   cmake ..
   ```  

4. Build the project:  

   ```bash
   make
   ```  

5. Run the program:  

   ```bash
   ./gen_alg
   ```  

---

### Usage  

Modify the parameters in the `main.cpp` file to customize:  

- Population size.  
- Number of generations.  
- Mutation and crossover rates.  

---

### Future Improvements

- Changing the mutation value range. When a gene mutates it does so within the
full range of allowed values. Changing this so that it only mutates within a
given small percentage could bring about convergence improvements.  
- Implement additional selection strategies (e.g., tournament selection).  
- Extend the algorithm to support multi-objective optimization.  
- Optimize performance for larger populations.  

---

### Author  

Developed by Aaron Trinidad, a physicist and C++ enthusiast exploring
optimization algorithms for his work in an NonLinear Optics Lab.  

---

### License  

This project is licensed under the MIT License.

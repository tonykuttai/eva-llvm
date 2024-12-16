/**
 * Eva LLVM Executable
 */

#include "EvaLLVM.hpp"

int main(int argc, char *argv[]) {

  std::string program = R"(
    46
  )";

  /**
   * Compiler Instance
   */
  EvaLLVM vm;

  /**
   * Generate LLVM IR
   */
  vm.exec(program);

  return 0;
}

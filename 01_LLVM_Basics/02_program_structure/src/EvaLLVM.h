/**
 *  Eva to LLVM IR Compiler
 */
#pragma once

#define __STDC_LIMIT_MACROS
#define __STDC_CONSTANT_MACROS

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include <cstdint>
#include <string>
#include <system_error>

class EvaLLVM {
public:
  EvaLLVM() { moduleInit(); }

  /**
   *  Executes the prgogram
   */
  void exec(const std::string &program) {
    // 1. Parse the program
    // auto ast = parser->parser(program);

    // 2. Compile to LLVM IR
    // compile(ast);

    // print the generated code
    module->print(llvm::outs(), nullptr);

    // 3. Save module IR to file
    saveModuleToFile("./out.ll");
  }

private:
  // Initialize the module
  void moduleInit() {
    // open a new context and module
    ctx = std::make_unique<llvm::LLVMContext>();
    module = std::make_unique<llvm::Module>("EvaLLVM", *ctx);

    // create a new builder for the module
    builder = std::make_unique<llvm::IRBuilder<>>(*ctx);
  }

  void saveModuleToFile(const std::string &fileName) {
    std::error_code errorCode;
    llvm::raw_fd_ostream outLL(fileName, errorCode);
    module->print(outLL, nullptr);
  }

  // Global Context
  std::unique_ptr<llvm::LLVMContext> ctx;

  // Module
  std::unique_ptr<llvm::Module> module;

  // IR Builder
  std::unique_ptr<llvm::IRBuilder<>> builder;
};

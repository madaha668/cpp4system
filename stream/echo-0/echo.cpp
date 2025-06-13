#include <iostream>
#include <exception>
#include <gsl/gsl>

void handle_version()
{
  std::cout
    << "echo (example) 1.0\n"
    << "Copyright (C) ???\n"
    << "\n"
    << "Written by Rian Quinn.\n";
  ::exit(EXIT_SUCCESS);
}

void handle_help()
{
  std::cout
    << "Usage: echo [SHORT-OPTION]... [STRING]...\n"
    << " or: echo LONG-OPTION\n"
    << "Echo the STRING(s) to standard output.\n"
    << "\n"
    << " -n do not output the trailing newline\n"
    << " --help display this help and exit\n"
    << " --version output version information and exit\n";

  ::exit(EXIT_SUCCESS);
}


int safe_main(int argc, char** argv)
{
  using namespace gsl;

  auto endl = true;
  auto args = make_span(argv, argc);

  for (int i = 0, num = 0; i < argc; i ++) {
    cstring_span<> span_arg = ensure_z(args.at(i));
    if (span_arg == "-n") {
      endl = false;
      continue;
    }
    if (span_arg == "--help") {
      handle_help();
    }
    if (span_arg == "--version") {
      handle_version();
    }
    if (num ++ > 0) {
      std::cout << " ";
    }
    std::cout << span_arg.data();
  }

  if (endl)
    std::cout << '\n';

  return EXIT_SUCCESS;
}


int main(int argc, char** argv)
{
  try {
    return safe_main(argc, argv);
  } catch (const std::exception& e) {
    std::cerr << "standard exception caught: \n" << " - what(): " << e.what() << '\n';
  } catch (...) {
    std::cerr << "unknown exception caught!!!\n";
  }
  return EXIT_FAILURE;
}

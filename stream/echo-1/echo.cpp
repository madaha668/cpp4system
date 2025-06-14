#include <fstream>
#include <iostream>
#include <exception>
#include <gsl/gsl>

using namespace gsl;

void redirect_output(
  const std::ifstream& is,
  const std::ofstream& os,
  std::function<void()> f) 
{
  auto cinrdbuf   = std::cin.rdbuf();
  auto coutrdbuf  = std::cout.rdbuf(); 

  std::cin.rdbuf(is.rdbuf());
  std::cout.rdbuf(os.rdbuf());

  f();

  std::cin.rdbuf(cinrdbuf);
  std::cout.rdbuf(coutrdbuf);
}

void redirect_output2(
  const std::ifstream& is,
  const std::ofstream& os,
  std::function<void()> f) 
{
  auto cinrdbuf   = std::cin.rdbuf();
  auto coutrdbuf  = std::cout.rdbuf(); 

  std::cin.rdbuf(is.rdbuf());
  std::cout.rdbuf(os.rdbuf());

  f();

  std::cin.rdbuf(cinrdbuf);
  std::cout.rdbuf(coutrdbuf);
}

auto open_streams(cstring_span<> port)
{
  std::ifstream is(port.data());
  std::ofstream os(port.data());

  if (!is || !os) {
    std::clog << "ERROR: unable to open serial IO port:" << port.data() << '\n';
    ::exit(EXIT_FAILURE);
  }

  return std::make_pair(std::move(is), std::move(os));
}

auto open_streams2(auto ports)
{
  std::ifstream is(port.at(0).data());
  std::ofstream os(port.at(0).data());

  if (!is || !os) {
    std::clog << "ERROR: unable to open serial IO port:" << port.data() << '\n';
    ::exit(EXIT_FAILURE);
  }

  return std::make_pair(std::move(is), std::move(os));
}

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

  if (argc != 2) {
    std::clog << "ERROR: only suport 1 parameter!" << '\n';
    ::exit(EXIT_FAILURE);
  }

  auto [is, os] = open_streams(args);

  redirect_output(is, os, [] {
    std::string buf;
    std::cin >> buf;
    std::cout << buf << std::flush;
  });

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

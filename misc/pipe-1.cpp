#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

#include <string>
#include <iostream>
#include <string_view>


class my_pipe {
  std::array<int, 2> m_handles;
public:  
  my_pipe() {
    if (pipe(m_handles.data()) < 0) {
      std::cerr << "pipe() failed" << std::endl;
      exit(1);
    }
  }
  ~my_pipe() {
    close(m_handles.at(0));
    close(m_handles.at(1));
  }
  std::string read();
  void write(const std::string& str);
};

std::string 
my_pipe::read() {
  std::array<char, 256> buf; 
  std::size_t bytes = ::read(m_handles.at(0), buf.data(), buf.size());
  if (bytes > 0) {
    return {buf.data(), bytes};
  }
  return {};
}

void
my_pipe::write(const std::string& str) {
  ::write(m_handles.at(1), str.data(), str.size());
}

int main() 
{
  my_pipe p;

  if (fork() != 0) {
    std::cout << "from parent" << std::endl;
    p.write("done");
    wait(nullptr);
    std::cout << "waited child done - parent" << std::endl;
  } else {
    std::cout << "from child: " << p.read() << std::endl;
  }
}

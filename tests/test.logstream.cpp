#include <logstream.h>

int main()
{
    J::dbg() << "Testing DebugLogStream";
    J::dbg(J::Severity::INFO) << "This is an informational debug message";
    J::dbg(J::Severity::WARNING) << "This is a warning debug message";
    J::dbg(J::Severity::ERROR) << "This is an error debug message";
    J::dbg(J::Severity::FATAL) << "This is a fatal debug message";
    return 0;
}

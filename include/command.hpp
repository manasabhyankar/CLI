using namespace std;
#include <string>

class Command
{
private:
    pair<string, void (*)()> command_tuple;
public:
    Command(string command_literal);
    ~Command();
};
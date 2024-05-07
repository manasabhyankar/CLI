using namespace std;
#include <string>
#include <vector>
class Command
{
private:
    pair<string, void (*)()> command_tuple;
public:
    Command(string command_literal);
    ~Command();
};

typedef struct CommandList{
    vector<string> command_list = {
        "help",
        "ls",
        "pwd",
    };
} CommandList;
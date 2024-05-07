#include "../include/command.hpp"

Command::Command(string command_literal){
    command_tuple.first = command_literal;
}

Command::~Command(){

}
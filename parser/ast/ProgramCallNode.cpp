//
// Created by marcin on 09.06.18.
//

#include <iostream>
#include "ProgramCallNode.h"
#include "NameNode.h"

ProgramCallNode::ProgramCallNode(std::shared_ptr <Node> progname, std::vector <std::shared_ptr<Node>> args):progname(progname), args(args) {

}

ProgramCallNode::~ProgramCallNode() {

}

std::string ProgramCallNode::toString() {
    std::string result = "<ProgramCallNode " + progname->toString();
    result += " ARGS: ";
    for(auto arg : args){
        result += arg->toString();
    }
    return result + ">";
}

std::string ProgramCallNode::execute(Memory *memory) {
    std::string progname_s = std::static_pointer_cast<NameNode>(progname)->getToken().getTokenData();
    if(progname_s=="pwd"){
        return memory->getPwd();
    }
    else if(progname_s=="cd"){
        if(args.size()==1){
            std::string arg1 = args[0]->execute(memory);
            memory->cd(arg1);
        }
        else if(args.size()==0){
            memory->cd("");
        }
        else{
            throw std::runtime_error("Incorrect cd arguments");
        }
        return "";
    }
    else if(progname_s=="ls"){
        return memory->ls();
    }
    else{
        return "CHUJ";
    }
}


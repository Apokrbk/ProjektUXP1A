//
// Created by marcin on 09.06.18.
//

#include "SubstitutionNode.h"
#include "../Parser.h"

SubstitutionNode::SubstitutionNode(std::shared_ptr<Node> programCallNode): programCallNode(programCallNode) {

}

SubstitutionNode::~SubstitutionNode() {

}

std::string SubstitutionNode::toString() {
    return "<SubstitutionNode "+programCallNode->toString()+">";
}

std::string SubstitutionNode::execute(Memory *memory) {
    int READ = 0;
    int fds1[2];

    pipe(fds1);

    if (fork()==0) {
        close(fds1[READ]);

        dup2(fds1[1],1 );
        programCallNode->execute(memory);
        exit(0);
    }
    char readBuffer[2048];
    read(fds1[READ], readBuffer, 2048);
    std::string result = std::string(readBuffer);


    auto lexer = Lexer(result);
    auto parser = Parser(lexer);
    auto ast = parser.parseStatement();
    if (ast != nullptr)
        return ast->execute(memory);
    else
        return "";
}

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
    auto lexer = Lexer(programCallNode->execute(memory));
    auto parser = Parser(lexer);
    auto ast = parser.parseStatement();
    return ast->execute(memory);
}
